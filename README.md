*This project has been created as part of the 42 curriculum by migusant.*

# ft_printf

A reimplementation of the standard C `printf()` function, handling **variadic arguments** and multiple format specifiers using low-level `write()` system calls. This project demonstrates format string parsing, variadic function handling, recursive number conversion, and building a reusable static library in C.

## Description

The ft_printf project recreates the behavior of `printf()` from the C standard library. It parses a format string, processes `%` conversion specifiers by extracting the corresponding argument from a variadic argument list, and writes the formatted output character by character to stdout. The function returns the total number of characters printed, or `-1` on error (including `NULL` format string and closed stdout). It is compiled as a **static library** (`libftprintf.a`) for use in other 42 projects.

### Key Features

- **9 format specifiers:** `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`
- **Variadic argument handling** using `<stdarg.h>` (`va_list`, `va_start`, `va_arg`, `va_end`)
- **Recursive number conversion** for decimal, unsigned, and hexadecimal output
- **Pointer printing** with `0x` prefix and lowercase hexadecimal representation
- **NULL safety:** prints `(null)` for NULL strings and `(nil)` for NULL pointers
- **INT_MIN handling** via hardcoded string for `-2147483648` (avoids negation overflow)
- **Uppercase/lowercase hex** using compile-time lookup strings (`HEX_U` / `HEX_L`)
- **Error detection** returning `-1` for NULL format strings and `write()` failures (closed stdout)
- **Invalid specifier passthrough** printing `%` followed by the unknown character
- **Static library output** (`libftprintf.a`) via `ar rcs` for linking into other projects

### Project Structure

```
├── ft_printf.h          # Header with prototypes and hex lookup macros
├── ft_printf.c          # Main ft_printf function and format specifier dispatcher
├── ft_printf_utils.c    # Output functions: putchar, putstr, putnbr, puthex, putptr
├── .main.c              # Comprehensive test program comparing ft_printf vs printf
├── Makefile             # Build system producing libftprintf.a static library
└── en.subject.pdf
```

## Instructions

### Compilation

```bash
make        # Compile the static library libftprintf.a
make clean  # Remove object files
make fclean # Remove object files and library
make re     # Recompile from scratch
```

This produces the `libftprintf.a` static library.

### Linking

To use ft_printf in another project:

```bash
# Compile your program with the library
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o program

# Or link the .a file directly
cc -Wall -Wextra -Werror main.c libftprintf.a -o program
```

### Usage

```c
#include "ft_printf.h"

int count;

// Character and string
count = ft_printf("Char: %c, String: %s\n", 'A', "hello");

// Signed and unsigned integers
ft_printf("Signed: %d or %i, Unsigned: %u\n", -42, -42, 4294967295);

// Hexadecimal (lower and upper)
ft_printf("Hex: %x, HEX: %X\n", 255, 255);  // ff, FF

// Pointer address
int n = 42;
ft_printf("Pointer: %p\n", &n);  // 0x7ffd...

// Literal percent
ft_printf("100%%\n");

// NULL handling
ft_printf("Null string: %s\n", NULL);   // (null)
ft_printf("Null pointer: %p\n", NULL);  // (nil)
```

### Supported Format Specifiers

| Specifier | Description | Example Output |
|-----------|-------------|----------------|
| `%c` | Single character | `A` |
| `%s` | String (prints `(null)` for NULL) | `hello` |
| `%p` | Pointer address with `0x` prefix (prints `(nil)` for NULL) | `0x7ffd5e8a3c` |
| `%d` | Signed decimal integer | `-42` |
| `%i` | Signed decimal integer (same as `%d`) | `42` |
| `%u` | Unsigned decimal integer | `4294967295` |
| `%x` | Unsigned hexadecimal (lowercase) | `ff` |
| `%X` | Unsigned hexadecimal (uppercase) | `FF` |
| `%%` | Literal percent sign | `%` |

## Technical Implementation

### Format String Parsing

The `ft_printf()` function iterates through the format string character by character:
- Regular characters are output directly via `ft_putchar()`
- When `%` is encountered, the next character is passed to `ft_format()` which dispatches to the appropriate conversion function
- Each conversion function returns the number of characters written, which is accumulated into the total return value
- Unknown specifiers (e.g., `%v`) print `%` followed by the character verbatim

### Number Conversion

**`ft_putnbr(unsigned int n, int is_signed)`** - Unified signed/unsigned decimal output:
- Uses a single function with an `is_signed` flag to handle both `%d`/`%i` and `%u`
- For signed negative values, prints `-` and negates (special-cases `INT_MIN` = `-2147483648` to avoid undefined behavior from negating it)
- Recursively divides by 10, printing digits from most significant to least significant

**`ft_puthex(unsigned long n, char format)`** - Hexadecimal conversion:
- Recursively divides by 16, using lookup strings `HEX_U` ("0123456789ABCDEF") or `HEX_L` ("0123456789abcdef") based on the format character
- Takes `unsigned long` to support both `%x`/`%X` (unsigned int) and pointer values

**`ft_putptr(unsigned long ptr)`** - Pointer output:
- Returns `(nil)` for NULL pointers
- Prints `0x` prefix followed by lowercase hex conversion via `ft_puthex()`

### Error Handling

- **NULL format string:** Returns `-1` immediately
- **Closed stdout:** Detected by testing `write(1, "", 0) == -1` before any output
- **NULL string argument:** `ft_putstr()` recursively calls itself with `"(null)"`
- **NULL pointer argument:** `ft_putptr()` outputs `"(nil)"`

### Return Value

Returns the total number of characters successfully printed, matching the behavior of the standard `printf()`. Each helper function returns its own character count, which is summed by the main loop.

## Resources

### Variadic Functions

- `man stdarg(3)` - Variable argument lists
- `man va_start(3)` / `man va_arg(3)` / `man va_end(3)` - Variadic macros
- [C Variadic Functions Tutorial](https://en.cppreference.com/w/c/variadic) - va_list usage and type promotion rules

### System Calls

- `man write(2)` - Low-level output to file descriptors
- `man printf(3)` - Standard printf reference for behavior comparison

### Static Libraries

- `man ar(1)` - Create and manage static library archives
- [Static Libraries in C](https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_C_libraries.html) - Building and linking `.a` files

### AI Usage

AI tools (GitHub Copilot, ChatGPT) were used as a **thinking partner and debugging assistant** to discuss problems and approaches, but all final code, architecture decisions, and bug fixes were produced by the student after understanding the underlying concepts.

**Documentation & Understanding:**
- Explaining variadic function mechanics and type promotion rules (char/short promoted to int)
- Clarifying `printf()` behavior for edge cases (NULL strings, NULL pointers, invalid specifiers)
- Understanding the difference between signed and unsigned integer representation for hex/unsigned output
- Refining and structuring README.md documentation to accurately represent technical implementations

**Code Review:**
- Verifying correct handling of `INT_MIN` negation edge case
- Reviewing return value accumulation across recursive calls
- Identifying the need for `write()` failure detection on closed stdout

**Learning Resources:**
- Providing reference for `printf` format specifier behavior across different libc implementations
- Clarifying pointer printing conventions (`0x` prefix, `(nil)` for NULL)
- Explaining static library creation with `ar rcs` and linking with `-L` / `-l` flags

**Testing Assistance & Debugging:**
- Helping design comprehensive test cases comparing ft_printf vs printf output and return values
- Debugging edge cases with negative hex values, UINT_MAX, and pointer arithmetic
- Testing behavior with closed stdout file descriptor

## License

This project is part of the 42 Common Core curriculum. See [LICENSE](LICENSE) for details.
