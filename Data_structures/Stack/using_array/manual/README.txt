STACK USING ARRAY (MANUAL MODE)
--------------------------------

This program implements a Stack data structure using an array.
All operations are performed manually by the user through menu options.

FEATURES:
---------
1. Push (manual input)
2. Pop
3. Peek
4. Display
5. Check if Empty
6. Check if Full
7. Input validation for:
   - Characters
   - Symbols
   - Floats
   - Mixed input (12ab)
   - Overflow characters
   - Invalid menu entries

EDGE CASES HANDLED:
-------------------
- Stack Overflow
- Stack Underflow
- Manual input with invalid characters
- Very large numbers
- Negative numbers
- Empty stack operations
- Single element push/pop
- Repeated invalid input without crashing

FILES:
------
main.c
functions.c
header.h
Makefile

HOW TO RUN:
-----------
make
./stack_manual

clean:
make clean

