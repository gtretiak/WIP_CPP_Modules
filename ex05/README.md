# exam05 — Level 00: C++ Class Design Under Exam Conditions

> Three timed C++ exercises covering operator overloading, arbitrary-precision arithmetic, and a multi-level inheritance hierarchy with abstract interfaces — all under Orthodox Canonical Form.

---

## Table of Contents

- [Overview](#overview)
- [Exercises](#exercises)
  - [vect2 — 2D Integer Vector](#vect2--2d-integer-vector)
  - [bigint — Arbitrary-Precision Integer](#bigint--arbitrary-precision-integer)
  - [polyset — Polymorphic Set with Dual Backends](#polyset--polymorphic-set-with-dual-backends)
- [Key Concepts & Approaches](#key-concepts--approaches)
- [Technologies](#technologies)
- [Setup & Build](#setup--build)
- [Usage Examples](#usage-examples)
- [Real-World Applicability](#real-world-applicability)

---

## Overview

Level 00 of 42's Exam Rank 05 requires implementing self-contained C++ classes from a specification, building and verifying against a provided `main.cpp`, within a strict time limit. All classes are expected to follow the Orthodox Canonical Form (copy constructor, copy assignment operator, destructor). The three exercises covered here are:

| Exercise | Core challenge |
|----------|---------------|
| `vect2` | Full operator suite for a 2D integer vector |
| `bigint` | Arbitrary-precision non-negative integer using string-based addition |
| `polyset` | Multiple-inheritance hierarchy: Array/Tree backends, searchable interface, Set wrapper |

---

## Exercises

### vect2 — 2D Integer Vector

**Files:** `vect2.hpp`, `vect2.cpp`

A class representing a two-component integer vector with full arithmetic operator support. The design goal is that `vect2` objects behave syntactically identically to scalar numerics.

**What it does:**
- Stores two `int` components (`x_`, `y_`) with private encapsulation
- Supports binary `+`, `-`, `*` between two vectors (component-wise) and between a vector and a scalar (both orders: `v * 2` and `2 * v`)
- Compound assignment: `+=`, `-=`, `*=` with both vector and scalar arguments
- Pre/post increment and decrement (`++v`, `v++`, `--v`, `v--`)
- Unary negation (`-v`)
- Component access via `operator[]` with both mutable and `const` overloads
- Equality/inequality comparison
- `std::ostream` integration: outputs `{x, y}`
- Free-function commutative operators (`2 + v`, `2 * v`) defined outside the class

**Why this approach:** Overloading both member and free-function operators is the idiomatic C++ way to achieve symmetric arithmetic expressions. Returning `*this` from compound assignments enables chaining (`a += b += c`). Separate pre- and post-increment signatures (with the dummy `int` parameter) follow the C++ standard convention.

---

### bigint — Arbitrary-Precision Integer

**Files:** `bigint.hpp`, `bigint.cpp`

A class representing non-negative integers of unbounded size, stored as a decimal digit string internally. Implements addition and comparison, with decimal left/right shift operators for power-of-10 scaling.

**What it does:**
- Stores the number as a `std::string` of decimal digits, normalized to remove leading zeros
- Constructors from `std::string`, `unsigned int`, and copy
- String-based addition via a carry-propagating loop (`summarize()`) — avoids integer overflow entirely
- Pre/post `operator++` for incremental counting
- Full comparison suite: `==`, `!=`, `<`, `<=`, `>`, `>=` — length-first comparison exploits the normalized representation (longer string = larger number)
- Decimal shift operators (`<<`, `>>`) for multiply/divide by powers of 10: left-shift appends zeros, right-shift truncates trailing digits
- `std::ostream` output

**Why this approach:** Storing digits as a string makes addition straightforward with no platform-specific integer size constraints. The length-first comparison optimization is efficient for normalized strings: if `num1.size() != num2.size()`, the longer string is definitively larger without character-by-character comparison. Decimal shifts are O(n) string operations rather than multiplication.

---

### polyset — Polymorphic Set with Dual Backends

**Files:** `SearchableArrayBag.hpp/cpp`, `SearchableTreeBag.hpp/cpp`, `Set.hpp/cpp`

A multi-level inheritance hierarchy built on a provided abstract `Bag` interface and concrete `ArrayBag`/`TreeBag` implementations. The exercise adds a searchable interface layer and a `Set` wrapper that enforces uniqueness.

**Provided (not written):**
- `Bag` — pure abstract base: `insert`, `print`, `clear`
- `ArrayBag` — concrete implementation backed by a dynamic array
- `TreeBag` — concrete implementation backed by a binary search tree
- `SearchableBag` — extends `Bag` with pure virtual `bool has(int)`

**Implemented:**

`SearchableArrayBag` inherits from both `ArrayBag` and `SearchableBag`, resolving the diamond via virtual inheritance from `Bag`. Implements `has(int)` as a linear scan of the underlying array.

`SearchableTreeBag` inherits from both `TreeBag` and `SearchableBag`. Implements `has(int)` as a BST traversal — O(log n) average case.

`Set` wraps any `SearchableBag*` and enforces the set invariant: before every `insert`, it calls `has()` to check for duplicates. This decouples the uniqueness policy from the storage backend — a `Set` backed by `SearchableTreeBag` gets O(log n) lookups, while one backed by `SearchableArrayBag` gives O(n). Both satisfy the same `Set` interface.

All three classes are under full Orthodox Canonical Form.

---

## Key Concepts & Approaches

**Symmetric Operator Overloading**
Member operators handle `v OP scalar` and `v OP v`. Free functions (declared as `operator+(int, const vect2&)`) handle the commutative `scalar OP v` case. Without the free functions, `2 * v` would not compile.

**String-Based Arbitrary Precision**
`bigint` sidesteps all platform integer limits by working in base 10 on strings. The digit-by-digit carry loop is O(max(n, m)) where n and m are digit counts. Normalization (stripping leading zeros) ensures length-based comparison is always correct.

**Virtual Inheritance for the Diamond**
Both `SearchableArrayBag` and `SearchableTreeBag` inherit from two bases that themselves both derive from `Bag`. Without `virtual` inheritance on `Bag`, there would be two separate `Bag` subobjects, causing ambiguous dispatch. Virtual inheritance ensures a single shared `Bag` base.

**Policy via Composition**
`Set` holds a `SearchableBag*` rather than inheriting from it. The storage policy (array vs. tree) is injected at construction time. This is the Composition-over-Inheritance principle in practice: `Set`'s uniqueness logic is independent of how or where data is stored.

**Orthodox Canonical Form**
Every class defines a copy constructor, copy assignment operator, and destructor. For classes owning heap resources (`ArrayBag` with `_data`, `TreeBag` with its node tree), these perform deep copies. For `Set`, which holds a pointer it does not own, the copy semantics are shallow and intentional.

---

## Technologies

| Tool | Purpose |
|------|---------|
| C++ (C++98 standard) | Implementation language |
| clang++ / g++ | Compilation with `-Wall -Wextra -Werror` |
| Makefile | Per-exercise build |
| Valgrind | Memory leak detection |

---

## Setup & Build

**Prerequisites:** `clang++` or `g++`, `make`.

```bash
# Clone the repo
git clone https://github.com/gtretiak/exam05.git
cd exam05/lvl_00

# --- vect2 ---
cd vect2
clang++ -Wall -Wextra -Werror vect2.cpp main.cpp -o vect2
./vect2

# --- bigint ---
cd ../bigint
clang++ -Wall -Wextra -Werror bigint.cpp main.cpp -o bigint
./bigint

# --- polyset ---
cd ../polyset
clang++ -Wall -Wextra -Werror \
    ArrayBag.cpp TreeBag.cpp \
    SearchableArrayBag.cpp SearchableTreeBag.cpp \
    Set.cpp main.cpp -o polyset
./polyset

# Check for memory leaks
valgrind --leak-check=full ./polyset
```

---

## Usage Examples

### vect2

```cpp
vect2 a(3, 3);
vect2 b(8, 9);

std::cout << a + b;          // {11, 12}
std::cout << 2 * a;          // {6, 6}
std::cout << a * 2;          // {6, 6}
std::cout << (a == a);       // 1

vect2 c = a;
c += b;
std::cout << c;              // {11, 12}

std::cout << a++;            // {3, 3}  (post-increment returns old value)
std::cout << a;              // {4, 4}
```

### bigint

```cpp
bigint x("99999999999999999999");   // way beyond int/long long
bigint y(1u);

std::cout << x + y;   // 100000000000000000000
std::cout << (x > y); // 1
std::cout << (x << 3u); // 99999999999999999999000  (multiply by 10^3)
std::cout << (x >> 3u); // 99999999999999999  (divide by 10^3, truncated)
```

### polyset

```cpp
SearchableTreeBag treeBag;
Set s(&treeBag);

s.insert(5);
s.insert(3);
s.insert(5);   // duplicate — silently ignored by Set::insert

s.print();     // prints tree contents: 3, 5

std::cout << s.has(3);  // 1
std::cout << s.has(7);  // 0
```

---

## Real-World Applicability

### 1. Physics and Game Math Libraries
`vect2`'s complete operator suite — including scalar commutativity and compound assignment — is exactly how production 2D math libraries (`glm`, `Box2D`'s `b2Vec2`, Unity's `Vector2`) are designed. The pattern scales directly: replace `int` with `float`, add `dot()` and `normalize()`, and you have the core of any 2D physics or rendering math layer.

### 2. Cryptography and Arbitrary-Precision Arithmetic
`bigint`'s string-based addition and comparison are the conceptual foundation of arbitrary-precision libraries (GMP, OpenSSL's BIGNUM). RSA key generation, elliptic curve arithmetic, and hash-based signatures all require integers far beyond 64 bits. The digit-carry loop and length-first comparison are primitive versions of what these libraries implement in optimized assembly.

### 3. Database Index Structures
`SearchableTreeBag`'s BST lookup (`has()` traversal) is structurally identical to a B-tree or AVL-tree index used in databases. Separating the storage backend from the uniqueness policy (`Set` wrapping `SearchableBag*`) mirrors how database engines decouple index strategy (B-tree, hash, skip-list) from the uniqueness constraint logic imposed at the query-planner level.

### 4. Configurable Collection Backends
The `Set`-wrapping-`SearchableBag*` pattern is the Strategy design pattern in its canonical form. Production systems use this constantly: a cache class wrapping an eviction strategy interface, a logger wrapping a sink interface (stdout, file, network), or a serializer wrapping a format interface (JSON, protobuf, MessagePack) — all inject behavior through a pointer to an abstract interface, exactly as `Set` does.

### 5. Financial Calculation Engines
`bigint` addition without overflow is critical in financial systems where integer arithmetic on cent-denominated amounts must be exact. Systems handling large transaction volumes (clearinghouses, central banks) use arbitrary-precision integers to avoid the rounding errors inherent to `double`. The operator overloading from `vect2` and `bigint` also underpins portfolio-level vector math (position vectors, covariance matrices) where custom numeric types integrate cleanly with mathematical expressions.
