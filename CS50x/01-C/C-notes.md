# __C Programming Language:__

## From Scratch to C

Everything from Scratch maps directly to C — functions, conditionals, loops, variables. The difference is syntax: semicolons, curly braces, and data types now matter.

Source code (human-readable) → **compiler** → machine code (binary).

In CS50, the compiler is invoked with `make`:
```
code hello.c     # create file
make hello       # compile → produces executable
./hello          # run
```

---

## Basic structure of a C program

```c
#include <stdio.h>

int main(void)
{
    printf("hello, world\n");
}
```

- `#include <stdio.h>` — imports the standard I/O library (needed for `printf`)
- `int main(void)` — entry point of every C program
- `printf` — prints to the terminal
- `\n` — newline (escape character)
- Every statement ends with `;`

**Common escape characters:**
```
\n   new line
\"   double quote
\'   single quote
\\   backslash
```

---

## Header files and libraries

`#include <stdio.h>` gives access to `printf` and other I/O functions.

CS50 provides its own library `cs50.h` with helper functions:
```c
#include <cs50.h>
```

CS50 input functions:
```
get_int()      get_float()    get_char()
get_string()   get_long()     get_double()
```

---

## Data types

```c
int      // whole numbers (e.g. 3, -7)
long     // larger whole numbers
float    // decimal numbers
double   // more precise decimals
char     // single character (e.g. 'y')
string   // series of characters (CS50 library)
bool     // true or false
```

Each type has memory limits. `int` maxes out at ~2.1 billion. Beyond that → **integer overflow** (value wraps around unpredictably). Use `long` for larger numbers.

---

## Format codes (for printf)

```c
%i    int
%li   long
%f    float
%c    char
%s    string
```

Example:
```c
int age = 17;
printf("I am %i years old\n", age);
```

---

## Variables

```c
int counter = 0;       // declare and assign
counter = counter + 1; // increment
counter += 1;          // shorthand
counter++;             // even shorter
counter--;             // decrement
```

---

## Conditionals

```c
if (x < y)
{
    printf("x is less than y\n");
}
else if (x > y)
{
    printf("x is greater than y\n");
}
else
{
    printf("x is equal to y\n");
}
```

**Comparing chars** — use single quotes, use `==` not `=`:
```c
char c = get_char("Agree? ");
if (c == 'y' || c == 'Y')
{
    printf("Agreed.\n");
}
```

- `==` checks equality
- `=` assigns a value (completely different)
- `||` means OR
- `&&` means AND

---

## Loops

**while loop:**
```c
int i = 0;
while (i < 3)
{
    printf("meow\n");
    i++;
}
```

**for loop** (cleaner for known iterations):
```c
for (int i = 0; i < 3; i++)
{
    printf("meow\n");
}
```
Three parts: `initialise ; condition ; update`

**do-while** (runs at least once — good for input validation):
```c
int n;
do
{
    n = get_int("Enter positive number: ");
}
while (n < 1);
```

**break and continue:**
```c
while (true)
{
    n = get_int("Number: ");
    if (n >= 0)
    {
        break;    // exit loop
    }
    // continue; would skip rest and restart loop
}
```

---

## Functions

**Defining and calling a custom function:**
```c
#include <stdio.h>

void meow(int n);   // prototype (declared before main)

int main(void)
{
    meow(3);
}

void meow(int n)    // definition
{
    for (int i = 0; i < n; i++)
    {
        printf("meow\n");
    }
}
```

- `void` return type = function returns nothing
- Prototype at the top tells the compiler the function exists before it's defined
- Parameters pass values *into* a function

**Function that returns a value:**
```c
int get_positive_int(void)
{
    int n;
    do
    {
        n = get_int("Number: ");
    }
    while (n < 1);
    return n;
}
```

**Scope** — a variable only exists inside the `{}` block it was declared in. If you declare `n` in `main`, the `meow` function gets its own *copy* of `n`, not the original.

---

## Operators

```
+    addition
-    subtraction
*    multiplication
/    division
%    remainder (modulo)
```

**Integer division truncates** — `7 / 2 = 3` in C, not 3.5.

**To get a decimal result, cast to float:**
```c
printf("%f\n", (float) x / y);
```

**Floating point imprecision** — floats can't represent all decimals exactly in binary. `1.0 / 3.0` stored as float will eventually show rounding errors at enough decimal places.

---

## Nested loops (Mario grid)

```c
const int n = 3;
for (int i = 0; i < n; i++)        // rows
{
    for (int j = 0; j < n; j++)    // columns
    {
        printf("#");
    }
    printf("\n");
}
```

`const` makes a variable unchangeable after assignment.

---

## Code quality — three axes

- **Correctness** — does it do what it's supposed to? (`check50`)
- **Design** — is it written efficiently and cleanly? (`design50`)
- **Style** — is it readable and consistently formatted? (`style50`)

---

## Key Linux commands (terminal)

```
ls        list files in current directory
cd        change directory
mkdir     make a new directory
mv        move or rename a file
cp        copy a file
rm        delete a file
```

---

## Key takeaways

- C is compiled — source code must be converted to machine code before running
- Every variable needs a declared type
- `=` assigns, `==` compares — mixing these is a common bug
- Loops: use `for` when iterations are known, `while` when condition-driven, `do-while` for input validation
- Functions keep code clean and reusable — prototype at top, define at bottom
- Integer overflow and floating point imprecision are real — choose types carefully
