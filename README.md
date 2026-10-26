# C Programming Examples

This repository is a collection of small C programs covering basic syntax,
input/output, arithmetic, and bit manipulation. Each program is a standalone
example with its own `main` function; compile and run one source file at a time.

> **Note:** The examples are educational and are not all production-ready.
> A few currently contain format-string mismatches, uninitialized variables,
> or other behavior that is undefined in C. Those cases are called out below;
> their output may differ between builds or machines.

## Table of contents

- [Getting started](#getting-started)
- [GCC and GDB command reference](#gcc-and-gdb-command-reference)
- [Programs](#programs)
  - [Fundamentals and types](#fundamentals-and-types)
    - [MyFirstProgram.c](#myfirstprogramc)
    - [VariableInC.c](#variableincc)
    - [ConstantsInC.c](#constantsincc)
    - [DataTypesInC.C](#datatypesincc)
  - [Input and text output](#input-and-text-output)
    - [InputFromUser.c](#inputfromuserc)
    - [InputFullString.c](#inputfullstringc)
    - [BasicReverseCharacter.c](#basicreversecharacterc)
    - [NameDOBContactinC.c](#namedobcontactincc)
    - [PrintFandCusing#.c](#printfandcusingc)
    - [PrintingTriangle.c](#printingtrianglec)
  - [Arithmetic and calculations](#arithmetic-and-calculations)
    - [SquareAndCube.c](#squareandcubec)
    - [BasicCalculator.c](#basiccalculatorc)
    - [AverageGrades.c](#averagegradesc)
    - [LargestofTwoNumbers.c](#largestoftwonumbersc)
    - [SimpleInterest.c](#simpleinterestc)
    - [PerimeterAndAreaofCircle.c](#perimeterandareaofcirclec)
    - [PerimeterAndAreaofRectangle.c](#perimeterandareaofrectanglec)
    - [SwaPVariables.c](#swapvariablesc)
    - [WorkingWithNumbers.c](#workingwithnumbersc)
  - [Bit operations and registers](#bit-operations-and-registers)
    - [SetBitCount.c](#setbitcountc)
    - [NumberIsPowerOf2.c](#numberispowerof2c)
    - [Macro_SetClearToggleRead.c](#macro_setcleartogglereadc)
    - [ReverseBitsofNumber.c](#reversebitsofnumberc)
    - [SwapBytes.c](#swapbytesc)
    - [regWriteOnlySpecificRange.c](#regwriteonlyspecificrangec)

## Getting started

Install GCC and GDB, then open a terminal in the repository directory. Compile
one source file into an executable and run it:

```sh
gcc -Wall -Wextra -g MyFirstProgram.c -o my_first_program
./my_first_program
```

For `WorkingWithNumbers.c`, link the math library by adding `-lm` after the
source file:

```sh
gcc -Wall -Wextra -g WorkingWithNumbers.c -lm -o working_with_numbers
```

The source file [SquareAndCube.c](.vscode/SquareAndCube.c) is in the `.vscode`
directory. Quote the filename [PrintFandCusing#.c](<PrintFandCusing#.c>) when
using it in a shell command because `#` has special meaning in some shell
contexts:

```sh
gcc -Wall -Wextra -g 'PrintFandCusing#.c' -o print_shapes
```

GCC treats the uppercase `.C` suffix as C++, so explicitly select C when
compiling [DataTypesInC.C](DataTypesInC.C):

```sh
gcc -x c -Wall -Wextra -g DataTypesInC.C -o data_types
```

## GCC and GDB command reference

In the examples below, replace `source.c` with a source filename and
`program` with the executable name you want to create. Use quotes around
filenames containing shell-special characters.

| Tool | Command prototype | Example / purpose |
|---|---|---|
| GCC | `gcc [options] source.c -o program` | `gcc -Wall -Wextra -g BasicCalculator.c -o calculator` compiles with common warnings and debugger information. |
| GCC | `gcc -std=c11 -Wall -Wextra source.c -o program` | Selects the C11 language standard and enables warnings. |
| GCC | `gcc -x c source.C -o program` | Forces GCC to treat a source file with uppercase `.C` suffix as C rather than C++. |
| GCC | `gcc source.c -lm -o program` | Links the math library; `-lm` follows the source/object files. |
| GCC | `./program` | Runs the executable on Linux/macOS. |
| GCC | `program.exe` | Runs an executable from Windows Command Prompt; use `.\program.exe` in PowerShell. |
| GDB | `gdb ./program` | Starts GDB with the compiled executable. |
| GDB | `break main` or `b main` | Sets a breakpoint at the start of `main`. |
| GDB | `run` or `r` | Starts or restarts the program. For input redirection: `run < input.txt`. |
| GDB | `next` or `n` | Executes the next source line without stepping into a function. |
| GDB | `step` or `s` | Executes the next source line, stepping into a function call. |
| GDB | `print expression` or `p expression` | Prints a value, for example `p result`. |
| GDB | `info locals` | Shows local variables in the current stack frame. |
| GDB | `continue` or `c` | Continues execution until the next breakpoint or program exit. |
| GDB | `backtrace` or `bt` | Shows the current call stack. |
| GDB | `quit` or `q` | Exits GDB. |

### Example debugging session

```text
$ gcc -Wall -Wextra -g BasicCalculator.c -o calculator
$ gdb ./calculator
(gdb) break main
(gdb) run
(gdb) next
(gdb) info locals
(gdb) continue
(gdb) quit
```

## Programs

Programs are grouped by topic, with a separate heading and horizontal divider
for each source file. This makes it easier to scan between examples and jump
from the table of contents to a specific program. Flow summaries use arrows
to show the order of operations; programs with decisions show both branches.
Output snippets are sample terminal output for the indicated input, with
prompts included where useful.

### Fundamentals and types

#### MyFirstProgram.c

**Problem:** Print a greeting to the terminal.

**Logic:** Call `printf` twice: once for `Hello World!!!` with a newline and
once for `Hi Bharath here`.

**Flow:** Start → print first greeting → print second greeting → End.

**Sample output:**

```text
Hello World!!!
Hi Bharath here
```

The second line has no trailing newline in the program. This example declares
`void main()`, which is not standard C; `int main(void)` is the portable form.

---

#### VariableInC.c

**Problem:** Demonstrate storing and printing a person's name and age using
variables.

**Logic:** Initialize a string and an integer, then print them with `%s` and
`%d` format specifiers.

**Flow:** Start → initialize name and age → print values → End.

**Sample output:** The final `printf` passes the name string to `%d`, which
expects an integer. That mismatch causes undefined behavior, so there is no
portable, reliable output for the last line. The first three lines are:

```text
There once was a man named John
He was 35 Years old.
He really liked the name John
```

---

#### ConstantsInC.c

**Problem:** Show that ordinary variables can change while `const` variables
are read-only.

**Logic:** Print an integer, change it, print it again, then print two constants
and literal values.

**Flow:** Start → print variable → update and print variable → print constants
and literals → End.

**Sample output:**

```text
5
8
5
8
90
Hello
```

---

#### DataTypesInC.C

**Problem:** Demonstrate integer, floating-point, character, and string
variables and their `printf` format specifiers.

**Logic:** Initialize an `int`, `float`, `char`, and character array; print
each value with `%d`, `%f`, `%c`, and `%s`.

**Flow:** Start → initialize example values → print each using its matching
specifier → End.

**Sample output:**

```text
Hello "This program is very important"
The variable of type integer is storing 25
The variable of type float is storing 5.800000
The variable of type char is storing A
The variable of type phrase is storing My Name is Bharath
My Favourite number is 500
```

### Input and text output

#### InputFromUser.c

**Problem:** Read a grade, a one-word name, an age, and a GPA from standard
input, then display them.

**Logic:** Prompt for each value and read it with `scanf`. `%s` reads only up
to whitespace, so a name containing spaces is truncated.

**Flow:** Start → read grade → read name → read age → read GPA → print values
→ End.

**Sample input:** `A`, `Alex`, `21`, `3.8`.

**Sample output:**

```text
Enter your Grade:
Your Grade is A
Enter your name: Your Name is Alex
Enter your Age:
You are 21 years old
Enter your gpa:
Your gpa is 3.800000
```

---

#### InputFullString.c

**Problem:** Read and print a name containing spaces.

**Logic:** `fgets` reads up to the buffer capacity (including spaces) from
standard input. The newline from pressing Enter is retained in the buffer.

**Flow:** Start → prompt for name → read line with `fgets` → print line → End.

**Sample input:** `Alex Morgan`.

**Sample output:**

```text
Enter the name:
Your Name is Alex Morgan
```

---

#### BasicReverseCharacter.c

**Problem:** Print three fixed characters in reverse order.

**Logic:** Store `X`, `M`, and `L` in separate character variables, then pass
them to `printf` in forward order and reverse order.

**Flow:** Start → initialize characters → print original and reversed order
→ End.

**Sample output:**

```text
The reverse of XML is LMX
```

---

#### NameDOBContactinC.c

**Problem:** Print a sample name, date of birth, and mobile number in aligned
labels.

**Logic:** Use three `printf` calls with fixed text.

**Flow:** Start → print name → print DOB → print mobile number → End.

**Sample output:**

```text
Name    : Alexandra Abramov
DOB     : Jan 19, 1996
Mobile  : 99-9999999999
```

---

#### PrintFandCusing#.c

**Problem:** Print two fixed patterns made from `#` characters.

**Logic:** Each `printf` call emits one line; `\n` moves to the next line.

**Flow:** Start → print first pattern → print blank line → print second pattern
→ End.

**Sample output:**

```text
######
#
#
####
#
#
#

    ######
 ##        ##
#
#
#
#
#
 ##        ##
    ######
```

---

#### PrintingTriangle.c

**Problem:** Print a small right-triangle-like outline using slash, vertical
bar, and underscore characters.

**Logic:** Print four fixed rows of characters.

**Flow:** Start → print four pattern rows → End.

**Sample output:**

```text
   /|
  / |
 /  |
/___|
```

### Arithmetic and calculations

#### SquareAndCube.c

**Source:** [.vscode/SquareAndCube.c](.vscode/SquareAndCube.c)

**Problem:** Read an integer and calculate its square and cube.

**Logic:** Read `input_data`, then calculate `input_data * input_data` and
`input_data * input_data * input_data`.

**Flow:** Start → read integer → calculate square and cube → print results
→ End.

**Sample input:** `5`.

**Sample output:**

```text
Enter the Input value:
The Square of the input value is 25 and cube is 125
```

---

#### BasicCalculator.c

**Problem:** Add two user-provided numbers.

**Logic:** Read two `double` values, add them, and print the result to two
decimal places.

**Flow:** Start → read first number → read second number → add → print result
→ End.

**Sample input:** `12.5`, `3.25`.

**Sample output:**

```text
Enter the first Number:
Enter the second Number:
The result is: 15.75
```

---

#### AverageGrades.c

**Problem:** Calculate the average of three grades.

**Logic:** Read three floating-point grades, add them, and divide the sum by
three.

**Flow:** Start → read three grades → sum grades → divide sum by 3 → print
average → End.

**Sample input:** `80`, `90`, `70`.

**Sample output:**

```text
Enter the Grade 1 value:
Enter the Grade 2 value:
Enter the Grade 3 value:
The average of the Grades are: 80.000000
```

---

#### LargestofTwoNumbers.c

**Problem:** Compare two integers and print which is larger.

**Logic:** If `Num1 > Num2`, print `Num1`; otherwise print `Num2`. When the
values are equal, the current code also reports `Num2` as largest.

**Flow:** Start → read two integers → is `Num1 > Num2`? → yes: print `Num1`;
no: print `Num2` → End.

**Sample input:** `17`, `29`.

**Sample output:**

```text
Enter the Value of Num1:
Enter the Value of Num2:
Num2 = 29 is the largest of the two numbers
```

---

#### SimpleInterest.c

**Problem:** Calculate simple interest from principal, number of periods, and
rate.

**Logic:** Read `P`, `N`, and `R`, then calculate `(P * N * R) / 100`.

**Flow:** Start → read P, N, R → calculate simple interest → print result
→ End.

**Sample input:** `1000 2 5`.

**Sample output:**

```text
Enter the value of P, N and R:
 The Simple Interest is: 100.000000
```

---

#### PerimeterAndAreaofCircle.c

**Problem:** Calculate the circumference (called perimeter in the output) and
area of a circle for an integer radius.

**Logic:** Use `2 * 3.14 * radius` for circumference and
`3.14 * radius * radius` for area.

**Flow:** Start → read radius → calculate circumference and area → print both
→ End.

**Sample input:** `3`.

**Sample output:**

```text
Enter the radius of the circle:
Perimeter of the Circle = 18.840000
Area of the circle = 28.260000
```

---

#### PerimeterAndAreaofRectangle.c

**Problem:** Calculate the perimeter and area of a rectangle.

**Logic:** Use the fixed dimensions `height = 7` and `width = 5`.
Perimeter is `2 * height + 2 * width`; area is `height * width`.

**Flow:** Start → set height and width → calculate perimeter and area → print
both → End.

**Sample output:**

```text
Perimeter of the rectangle = 24 inches
Area of the rectangle = 35 square inches
```

---

#### SwaPVariables.c

**Problem:** Swap two integer values without using a temporary variable.

**Logic:** Read `var_1` and `var_2`; use addition and subtraction assignments
to exchange their values.

**Flow:** Start → read two integers → add values into first → subtract to
recover second and first → print swapped values → End.

**Sample input:** `7 11`.

**Sample output:**

```text
Enter the values of Variable 1 and 2:
The data stored in variable1 is 7 variable2 is 11
 The values entered are swapped
 variable1 =11
 variable2 = 7
```

The addition-based method can overflow for sufficiently large integer inputs.

---

#### WorkingWithNumbers.c

**Problem:** Demonstrate arithmetic conversions and math-library functions
including `pow`, `sqrt`, `ceil`, and `floor`.

**Logic:** Print results from integer and floating-point arithmetic, then call
the math functions. The program should be linked with `-lm`.

**Flow:** Start → print arithmetic examples → call and print math functions
→ End.

**Output note:** This source passes values to `printf` that do not match the
format specifiers (for example, an `int` with `%f` and a `double` with `%d`).
These mismatches cause undefined behavior, so an execution transcript cannot
be treated as a reliable expected output. Use matching argument types and
format specifiers before relying on its results.

### Bit operations and registers

#### SetBitCount.c

**Problem:** Count the set (1-valued) bits in an integer.

**Logic:** Examine each bit position from zero through the top bit of the
integer. Increment a counter whenever `(num >> i) & 1` equals one.

**Flow:** Start → read number → initialize count to zero → inspect each bit
→ increment for each 1 → print count → End.

**Sample input:** `13` (binary `1101`).

**Sample output:**

```text
Enter the number
No of set bits in the number is = 3
```

---

#### NumberIsPowerOf2.c

**Problem:** Attempt to determine whether a number is a power of two by
counting its set bits.

**Logic:** The intended rule is that a positive power of two has exactly one
set bit. The program scans bits and reports a result based on the count.

**Flow:** Start → read number → scan bits and count 1s → count greater than 1:
report not a power; count equals 1: report power → End.

**Output note:** The current `numOfOnes` counter is not initialized, and the
loop starts at bit 1, skipping the least-significant bit. Its `scanf` and
`printf` format specifiers also do not match `uint32_t` portably. Consequently,
its result is not reliable. A correct implementation should initialize the
counter, inspect every bit (or use `n != 0 && (n & (n - 1)) == 0`), and use
format specifiers matching the integer type.

---

#### Macro_SetClearToggleRead.c

**Problem:** Demonstrate setting, reading, and clearing bits in a 32-bit
register value.

**Logic:** Start with `0x40001000`; set bit 0, read bit 30, then clear bit 0
and set bit 2. The macros use bitwise OR, AND, XOR, and shift operations.

**Flow:** Start → initialize register → set bit 0 and print → read bit 30 and
print → clear bit 0 → set bit 2 → print updated register → End.

**Sample output:**

```text
40001001
1
40001004
```

---

#### ReverseBitsofNumber.c

**Problem:** The apparent goal is to print the bits of a number and then print
the bits in reversed order (bitwise complement across the displayed width).

**Logic:** The first loop prints bits from most significant to least
significant. The second loop intends to set or clear corresponding bits in a
result value and then print that value.

**Flow:** Start → read number → print its bits → construct complemented result
→ print result bits → End.

**Output note:** `res` is uninitialized before the bit operations, and the
`READ_BIT` macro ignores its position argument in favor of a separate global
loop variable. This makes the constructed result unreliable; no stable sample
output can be given for the current implementation.

---

#### SwapBytes.c

**Problem:** Display a 16-bit value in binary, exchange its high and low bytes,
and display the result.

**Logic:** Print the bits from most significant to least significant, then
combine the low byte shifted left by eight with the high byte shifted right by
eight.

**Flow:** Start → read 16-bit number → print bits → swap two bytes → print
swapped bits → End.

**Sample input:** `4660` (`0x1234`).

**Sample output:**

```text
Enter the number
0001001000110100
Bytes are swapped!!!
0011010000010010
```

The current `scanf` format uses `%hd` for a `uint16_t`; use a format matched to
the actual type for portable input.

---

#### regWriteOnlySpecificRange.c

**Problem:** Modify a selected range of bits in a 32-bit register using a
user-supplied bit pattern, then verify and print the register.

**Logic:** Read the register value, field width, starting bit, and one bit
value per field position. The `modifyRegister` function applies the values and
checks the resulting bits.

**Flow:** Start → read register and field parameters → does the field fit in
the register? → no: report overflow; yes: modify field → verify → report
result → End.

**Output note:** This example has correctness and safety issues that prevent a
dependable output example: the range check rejects a field that ends exactly
at the register boundary, clearing a bit with input zero does not actually
clear it, and verification iterates one position past the requested field.
The status variable is also uninitialized on the rejected-range path. These
issues should be corrected before relying on the program's output.
