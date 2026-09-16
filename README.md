*This project has been created as part of the 42 curriculum by beakduma.*

# ft_printf

## Description

`ft_printf` is a C library that recreates the behavior of the standard `printf()`
function from `libc`, without relying on its internal buffer management.

The goal of this project is to understand and implement **variadic functions**
in C (`va_start`, `va_arg`, `va_copy`, `va_end`), and to build a well-structured,
extensible parser for format strings.

The function handles the following conversions:

| Conversion | Description                              |
|------------|-------------------------------------------|
| `%c`       | Single character                          |
| `%s`       | String                                    |
| `%p`       | Pointer address (hexadecimal)             |
| `%d` / `%i`| Signed decimal integer                    |
| `%u`       | Unsigned decimal integer                  |
| `%x`       | Hexadecimal, lowercase                    |
| `%X`       | Hexadecimal, uppercase                    |
| `%%`       | Literal percent sign                      |

<!-- If you did the bonus, add the flags you support here, e.g.: -->
<!-- Bonus flags supported: `-`, `0`, `.` (precision), field width, `#`, `+`, space -->

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

<!-- List the documentation / references you actually used, for example: -->
- `man 3 printf`
- `man 3 stdarg` (`va_start`, `va_arg`, `va_copy`, `va_end`)
- 42 subject PDF (`en_subject__ft_printf.pdf`)

### AI usage

<!--
Be honest and specific here, as required by the subject.
Example structure:
- Which parts of the project (if any) you discussed with an AI tool
- What kind of help was requested (e.g. clarifying variadic function syntax,
  debugging a segfault, reviewing Norm compliance of the Makefile)
- Confirm that the core logic/algorithm was designed and written by you
-->

## Technical choices — algorithm & data structure

<!--
Required section. Explain and justify, for example:
- How the format string is parsed (state machine? index-based loop?)
- How each conversion specifier is dispatched (function pointer table? switch/if-else?)
- How flags/width/precision (if bonus done) are parsed and stored
- Why you chose this structure (extensibility, readability, avoiding duplication)
-->
