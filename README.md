*This project has been created as part of the 42 curriculum by beakduma.*

# ft_printf

## Description

`ft_printf` is a C library that recreates the behavior of the standard `printf()`
function from `libc`, without relying on its internal buffer management.

The goal of this project is to understand and implement **variadic functions**
in C (`va_start`, `va_arg`, `va_copy`, `va_end`), and to build a well-structured,
extensible parser for format strings.

The function handles the following conversions:

| Conversion | Description                               |
|------------|-------------------------------------------|
| `%c`       | Single character                          |
| `%s`       | String                                    |
| `%p`       | Pointer address (hexadecimal)             |
| `%d` / `%i`| Signed decimal integer                    |
| `%u`       | Unsigned decimal integer                  |
| `%x`       | Hexadecimal, lowercase                    |
| `%X`       | Hexadecimal, uppercase                    |
| `%%`       | Literal percent sign                      |

## Instructions

### Compilation

```bash
make          # builds libftprintf.a (mandatory part)
make bonus    # builds libftprintf.a with bonus flags support
make clean    # removes object files
make fclean   # removes object files and the library
make re       # fclean + all
```

### Usage

Include the header and link against the library:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s, you are %d years old (%p)\n", "World", 42, main);
    return (0);
}
```

Compile your own program with:

```bash
cc your_file.c -L. -lftprintf -I includes -o your_program
```

## Resources

- `man 3 printf`
- `man 3 stdarg` (`va_start`, `va_arg`, `va_copy`, `va_end`)
- 42 subject PDF (`en_subject__ft_printf.pdf`)

### AI usage

An AI assistant was used only to help structure and format this `README.md` file (headings, tables, wording) after the project's own logic and code were designed and written independently. No AI-generated code was used for the implementation of the `ft_printf` functions themselves, in line with the project's AI Instructions.

## Technical choices — algorithm & data structure

- **Format String Parsing:** The format string is iterated character by character using an index-based loop. When a percent sign (`%`) is encountered, the parser inspects the next character to identify the conversion specifier.
- **Modular Dispatching:** Instead of a monolithic block of code, each conversion (`%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`) is delegated to dedicated helper functions. This ensures clean code, readability, and full compliance with the 42 Norm.
- **Variadic Argument Handling:** Standard `<stdarg.h>` macros (`va_start`, `va_arg`, `va_end`) are used to dynamically extract arguments from the `va_list` based on the type implied by the specifier.
- **Return Value Tracking:** Every helper function computes and returns the number of characters it prints. These counts are accumulated throughout the string parsing process so that `ft_printf` accurately mirrors the return value behavior of the original `printf`.
