# C++ Phone Book Project

## Overview
This is a C++ project with two exercises:
- **ex00**: Simple megaphone program that converts input to uppercase
- **ex01**: PhoneBook application with contact management (ADD, SEARCH, EXIT commands)

## Project Structure
```
.
├── ex00/
│   ├── Makefile
│   └── megaphone.cpp
├── ex01/
│   ├── Makefile
│   ├── main.cpp
│   ├── PhoneBook.class.hpp
│   ├── PhoneBook.class.cpp
│   ├── Contact.class.hpp
│   └── Contact.class.cpp
└── .gitignore
```

## Build System
- Uses GNU Make with C++98 standard
- Compile flags: `-Wall -Wextra -Werror -std=c++98`
- Each exercise has its own Makefile with `make`, `make clean`, `make fclean`, and `make re` targets

## Current Workflow
- **Name**: Build and Run
- **Command**: `cd ex00 && make re && ./megaphone "Hello from Replit!"`
- **Output Type**: Console
- **Status**: Configured and working

## Key Features (ex01)
- Add contacts with: first name, last name, nickname, phone number, darkest secret
- Store up to 8 contacts with overwrite protection
- Search contacts with formatted table display
- Display full contact details when selected

## Recent Fixes
1. Fixed contact data not being saved (passed by reference instead of by value)
2. Corrected loop condition for displaying contacts
3. Fixed substring syntax in getData()
4. Aligned header and data columns with proper setw() formatting
5. Fixed input buffer issue with std::cin.ignore() after reading index

## Notes
- ex01 requires full program interaction (uses std::cin for user input)
- Contact data truncated to 10 characters in display (with dot indicator if longer)
- Program uses C++98 standard as per assignment requirements
