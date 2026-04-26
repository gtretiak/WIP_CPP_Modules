A progressive series of C++ exercises covering class design, memory ownership, operator overloading, the Orthodox Canonical Form, inheritance hierarchies, abstract interfaces, virtual dispatch, and structured exception handling — all implemented from scratch without STL containers.

This repository contains a structured series of C++ exercises that:
- showcases object‑oriented programming, namespaces, classes, member functions, initialization, static and const semantics, dynamic memory management, references, pointers to members, switch statements, and stream I/O.
- includes such concepts as ad‑hoc and subtype polymorphism, operator overloading, the Orthodox Canonical class form (Rule of Three), inheritance, abstract classes and interfaces, repetition constructs, and exception handling.
- demonstrates deep copying, virtual dispatch, and clean class architecture.

---

## Table of Contents

- [Overview](#overview)
- [Module Breakdown](#module-breakdown)
- [Key Concepts & Approaches](#key-concepts--approaches)
- [Technologies](#technologies)
- [Setup & Build](#setup--build)
- [Usage Examples](#usage-examples)
- [Real-World Applicability](#real-world-applicability)

---

## Overview

This repository contains six progressive C++ modules (cpp00–cpp05) completed as part of the 42 Porto curriculum. Each module introduces a tightly scoped set of language features and builds on the previous one. Working without STL containers and with manual memory management forces a ground-up understanding of how object-oriented abstractions actually work under the hood — which is exactly what makes these transferable to production systems.

**What's covered across all modules:**

- Namespaces, classes, member functions, access specifiers, `static`/`const` semantics (cpp00)
- Heap vs. stack allocation, references vs. pointers, pointers-to-member-functions (cpp01)
- Orthodox Canonical Form (Rule of Three), operator overloading, fixed-point arithmetic (cpp02)
- Single and multiple inheritance, constructor/destructor chaining, the diamond problem (cpp03)
- Pure virtual functions, abstract interfaces, virtual dispatch, deep copy correctness (cpp04)
- Custom exception hierarchies, `try`/`catch`, RAII-adjacent invariant enforcement (cpp05)

---

## Module Breakdown

### cpp00 — Classes, Namespaces, Stream I/O

Introduces the C++ class model. A `PhoneBook` CLI application demonstrates namespace scoping, member functions, `static` class-level state (fixed-size contact storage), `const` correctness, and formatted stream output via `std::cout`. Control flow is handled with a switch-based menu loop.

**Key files:** `PhoneBook.hpp/cpp`, `Contact.hpp/cpp`, `main.cpp`

---

### cpp01 — Memory Ownership, References, Pointers-to-Members

Explores how C++ manages memory. A `Zombie` class is instantiated both on the stack (automatic lifetime) and the heap (`new`/`delete`), demonstrating why the distinction matters. A `Brain`/`Human` design introduces references as safer aliases to pointers. Pointers-to-member-functions enable runtime dispatch without inheritance — a precursor to virtual dispatch.

**Key files:** `Zombie.hpp/cpp`, `Human.hpp/cpp`, `Brain.hpp/cpp`

---

### cpp02 — Orthodox Canonical Form and Operator Overloading

Implements a `Fixed` class representing fixed-point numbers (8 bits fractional part, no `float` shortcuts). All arithmetic, comparison, increment/decrement, and stream operators are overloaded. The Rule of Three is applied rigorously: copy constructor, copy assignment operator, and destructor work together to prevent shallow copy bugs.

**Key files:** `Fixed.hpp/cpp`

---

### cpp03 — Inheritance and Constructor Chaining

Models a class hierarchy (`ClapTrap` → `ScavTrap` → `FragTrap`, plus a `DiamondTrap` using multiple inheritance) to explore constructor and destructor call order. The diamond problem — where two paths through the hierarchy share a common base — is introduced and resolved via virtual inheritance.

**Key files:** `ClapTrap.hpp/cpp`, `ScavTrap.hpp/cpp`, `FragTrap.hpp/cpp`, `DiamondTrap.hpp/cpp`

---

### cpp04 — Abstract Interfaces and Virtual Dispatch

Builds a polymorphic `Animal` hierarchy (`Dog`, `Cat`) using pure virtual functions and abstract base classes. Virtual dispatch resolves the correct overridden method at runtime via vtable lookup — enabling the same pointer type to exhibit different behavior depending on the object it holds. Deep copy correctness with owned `Brain` objects is tested explicitly. Interfaces (`AMateria`, `ICharacter`, `IMateriaSource`) follow the Interface Segregation principle as pure abstract classes.

**Key files:** `Animal.hpp/cpp`, `Dog.hpp/cpp`, `Cat.hpp/cpp`, `Brain.hpp/cpp`, `AMateria.hpp/cpp`, `ICharacter.hpp`, `IMateriaSource.hpp`, `Character.hpp/cpp`, `MateriaSource.hpp/cpp`

---

### cpp05 — Exception Hierarchies and Structured Error Handling

Implements a `Bureaucrat`/`Form` system where objects enforce invariants in their constructors and signal violations via custom exceptions derived from `std::exception`. `try`/`catch` blocks propagate errors to the correct level of abstraction — no return-code checking. This mirrors how exception safety is designed in production C++ libraries.

**Key files:** `Bureaucrat.hpp/cpp`, `AForm.hpp/cpp`, `ShrubberyCreationForm.hpp/cpp`, `RobotomyRequestForm.hpp/cpp`, `PresidentialPardonForm.hpp/cpp`, `Intern.hpp/cpp`

---

## Key Concepts & Approaches

**Orthodox Canonical Form (Rule of Three)**
Any class that owns a resource must define a copy constructor, copy assignment operator, and destructor together. Without all three, copies produce shallow duplicates causing double-free crashes or silent data corruption. This principle is the precursor to C++11's Rule of Five and informs modern RAII patterns.

**Operator Overloading**
Defining `operator+`, `operator[]`, `operator<<`, `operator==`, etc. allows user-defined types to integrate transparently with C++ syntax. The `Fixed` class arithmetic expressions look identical to those on built-in numeric types while the underlying 8-bit fractional representation is entirely custom — this is the same technique used in graphics math libraries and DSP code.

**Virtual Dispatch**
Pure virtual functions (`= 0`) define a contract that derived classes must satisfy. At runtime, a base class pointer calls the correct overridden method via vtable lookup — the foundation of plugin systems, strategy patterns, and any architecture where behavior varies by concrete type without the caller knowing which type it holds.

**Abstract Interfaces as Contracts**
`ICharacter` and `IMateriaSource` are implemented as pure abstract classes with no data members — an idiomatic C++ Interface Segregation pattern. Code that depends only on the interface is decoupled from any concrete implementation, allowing implementations to be swapped without changing call sites.

**Exception Safety**
Throwing in a constructor prevents the object from ever being considered valid, avoiding partially-constructed state. Custom exception hierarchies let callers catch at the granularity they care about (`GradeTooHighException` vs. `GradeTooLowException`) without inspecting return codes or error flags.

---

## Technologies

| Tool | Purpose |
|------|---------|
| C++ (C++98 standard) | Implementation language — strict standard enforced by 42 |
| Makefile | Per-exercise build automation |
| clang++ / g++ | Compilation with `-Wall -Wextra -Werror` |
| GDB | Step-through debugging |
| Valgrind | Memory leak and invalid access detection |

---

## Setup & Build

**Prerequisites:** `clang++` or `g++`, `make`, and optionally `valgrind` (Linux only).

```bash
# Clone the repository
git clone https://github.com/gtretiak/WIP_CPP_Modules.git
cd WIP_CPP_Modules

# Navigate to a specific exercise
cd cpp04/ex02

# Build
make

# Run
./animals

# Check for memory leaks (Linux)
valgrind --leak-check=full --track-origins=yes ./animals

# Clean build artifacts
make fclean && make
```

Each subdirectory (`ex00`, `ex01`, `ex02`…) within a module folder is a self-contained exercise with its own `Makefile`. Standard targets: `make`, `make clean`, `make fclean`, `make re`.

---

## Usage Examples

### Fixed-Point Arithmetic (cpp02)

```cpp
Fixed a(5);       // integer constructor
Fixed b(42.42f);  // float constructor — converts to fixed-point

std::cout << a;           // outputs: 5
std::cout << b;           // outputs: 42.4219
std::cout << (a + b);     // outputs: 47.4219
std::cout << (a > b);     // outputs: 0
std::cout << Fixed::max(a, b);  // outputs: 42.4219
```

### Virtual Dispatch (cpp04)

```cpp
Animal *animals[4];
animals[0] = new Dog();
animals[1] = new Cat();
animals[2] = new Dog();
animals[3] = new Cat();

for (int i = 0; i < 4; i++)
    animals[i]->makeSound();   // Dog::makeSound or Cat::makeSound resolved at runtime

for (int i = 0; i < 4; i++)
    delete animals[i];         // correct destructor called via virtual ~Animal()
```

### Exception Handling (cpp05)

```cpp
try {
    Bureaucrat senior("Alice", 1);
    senior.incrementGrade();          // throws GradeTooHighException
} catch (std::exception &e) {
    std::cout << e.what() << "\n";    // outputs: "Grade is too high"
}
```

### Multiple Inheritance — DiamondTrap (cpp03)

```bash
$ ./diamond
DiamondTrap constructor called
FragTrap constructor called
ScavTrap constructor called
ClapTrap constructor called
[DiamondTrap Jack] attacks [target], causing 30 points of damage!
...
ClapTrap destructor called
ScavTrap destructor called
FragTrap destructor called
DiamondTrap destructor called
```

---

## Real-World Applicability

### 1. Game Engine Entity/Component Systems
The `Animal`/`Dog`/`Cat` polymorphic hierarchy from cpp04 directly maps to game engine entity patterns. A `GameObject` abstract base class with `update()`, `render()`, and `destroy()` pure virtual functions lets engine code process any entity type through a uniform interface — exactly how Unreal Engine's `AActor` and Unity's `MonoBehaviour` hierarchies are structured.

### 2. Financial Instruments Abstraction
The abstract interface pattern (`ICharacter`, `IMateriaSource`) mirrors how trading systems define abstract `Instrument` or `Pricer` interfaces. A `Bond`, `Option`, and `Swap` class each implement the same `price()` and `risk()` interface, allowing a portfolio engine to iterate over mixed instrument types uniformly — the same vtable dispatch demonstrated in cpp04.

### 3. Custom Numeric Types in Embedded / DSP Systems
The `Fixed` class from cpp02 demonstrates how to implement a custom numeric type with full operator integration. In embedded systems and digital signal processing, fixed-point arithmetic avoids the overhead and precision issues of floating-point hardware. The same operator overloading technique is used in production DSP libraries where expressions like `sample * gain + offset` must work on custom fixed-point types.

### 4. Plugin/Strategy Pattern in CLI Tools and Servers
The pointer-to-member and virtual dispatch techniques from cpp01 and cpp04 are the mechanical foundation of the Strategy and Command design patterns. A web server's request router, a CLI tool's command dispatcher, or a rendering pipeline's shader selector — all use the same mechanism: a base class pointer or function pointer is resolved at runtime to the correct concrete behavior without the caller knowing which it is.

### 5. Exception-Safe Resource Management in Production Libraries
The exception hierarchy from cpp05 directly reflects how production C++ libraries (Boost, Qt, LLVM) design error handling. Constructor invariant enforcement + custom exception types allow callers to handle specific error categories (`NetworkException`, `ParseException`) while a single `std::exception&` catch at the top level handles anything unexpected — far safer and more expressive than return codes.

---

## Repository Structure

```
WIP_CPP_Modules/
├── cpp00/        # Namespaces, classes, stream I/O
│   ├── ex00/     # Megaphone (string manipulation)
│   ├── ex01/     # PhoneBook (class design, static members)
│   └── ex02/     # Account (static state, stream logging)
├── cpp01/        # Memory, references, pointers-to-members
├── cpp02/        # Orthodox Canonical Form, operator overloading
├── cpp03/        # Inheritance, constructor chains
├── cpp04/        # Virtual dispatch, abstract interfaces
└── cpp05/        # Exception hierarchies
```
