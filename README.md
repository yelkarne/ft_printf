*This project has been created as part of the 42 curriculum by beakduma.*

# ft_printf

## Description

`ft_printf` is a C library (`libftprintf.a`) that recreates the behavior of the
standard `printf()` function from `libc`, without reproducing its internal
buffer management: every character is written directly with `write(2)`.

The goal of the project is to learn how **variadic functions** work in C
(`va_start`, `va_arg`, `va_end`) and to build a format-string parser that is
easy to read and easy to extend.

Prototype:

```c
int	ft_printf(const char *format, ...);
```

The return value is the number of characters printed, like the original
`printf()`.

### Supported conversions

| Conversion  | Description                                          |
|-------------|------------------------------------------------------|
| `%c`        | Single character                                     |
| `%s`        | String (`(null)` is printed for a `NULL` pointer)    |
| `%p`        | Pointer address in hexadecimal (`(nil)` for `NULL`)  |
| `%d` / `%i` | Signed decimal integer                               |
| `%u`        | Unsigned decimal integer                             |
| `%x`        | Unsigned hexadecimal, lowercase                      |
| `%X`        | Unsigned hexadecimal, uppercase                      |
| `%%`        | Literal percent sign                                 |

## Instructions

### Compilation

```bash
make          # builds libftprintf.a at the root of the repository
make clean    # removes object files
make fclean   # removes object files and libftprintf.a
make re       # fclean + all
```

The library is compiled with `cc -Wall -Wextra -Werror` and archived with `ar`.

### Usage

```c
#include "ft_printf.h"

int	main(void)
{
	int	len;

	len = ft_printf("Hello %s, %d in hex is %x (%p)\n", "World", 42, 42, &len);
	ft_printf("%d characters printed\n", len);
	return (0);
}
```

Compile and link your program against the library:

```bash
cc main.c -L. -lftprintf -o my_program
./my_program
```

### Project structure

| File                 | Content                                                  |
|----------------------|----------------------------------------------------------|
| `ft_printf.h`        | Prototypes and the `t_conv` structure                    |
| `ft_printf.c`        | `ft_printf()`, the conversion table and the dispatcher   |
| `ft_handlers_text.c` | Handlers for `%c`, `%s`, `%%`                            |
| `ft_handlers_num.c`  | Handlers for `%d`, `%i`, `%u`, `%x`, `%X`, `%p`          |
| `ft_utils.c`         | Low-level output: `ft_putchar`, `ft_putstr`, `ft_putnbr`, `ft_putnbr_base` |

## Algorithm and data structure

### Parsing the format string

`ft_printf` walks the format string once, from left to right, with a pointer:

1. An ordinary character is written immediately with `ft_putchar`.
2. When a `%` is found, the pointer moves to the next character, which is the
   conversion specifier, and it is passed to `dispatch()`.
3. If the string ends right after a `%`, the function stops and returns `-1`.

Each character of the format is visited exactly once, so parsing is linear in
the length of the format string, and no memory is allocated.

### Dispatch table (`t_conv`)

Instead of a long `if / else if` chain, the conversions are stored in a static
constant table of `t_conv` structures:

```c
typedef struct s_conv
{
	char	specifier;
	void	(*handler)(va_list *ap, int *counter);
}	t_conv;
```

Each entry associates a specifier character with a function pointer to its
handler (`'d'` and `'i'` share the same handler). `dispatch()` scans the table
until it finds the matching specifier and calls the handler. The table ends
with a `{0, NULL}` sentinel; if no entry matches, `%` and the unknown
character are printed as they are.

**Why this choice:**

- **Extensibility** — adding a conversion only means writing one handler and
  adding one line to the table; the parser itself does not change.
- **Readability and Norm compliance** — every handler is a short function with
  a single responsibility, which keeps functions under 25 lines.
- **Cost** — the table has only 9 entries, so a linear search is effectively
  constant time and simpler than any other lookup structure.

### Passing `va_list` and the counter

- Handlers receive a **pointer** to the `va_list` (`va_list *ap`). This way,
  every `va_arg` call inside a handler advances the same list used by
  `ft_printf`, and the next conversion reads the next argument.
- The number of printed characters is tracked through an `int *counter`.
  Only `ft_putchar` writes to the output, and it increments the counter on
  every write, so the final count is always exact without each function
  having to return and sum its own length.

### Number conversion

`ft_putnbr_base` prints an `unsigned long` in any base recursively: it first
prints `number / base`, then the digit `number % base`, so the digits come out
in the correct order without a temporary buffer.

- `%u`, `%x`, `%X` use it with bases 10 and 16 and the matching digit set.
- `%p` casts the pointer to `unsigned long` (64 bits) and prints `0x` followed
  by the lowercase hexadecimal value.
- `%d` / `%i` store the `int` in a `long` before negating it, so `INT_MIN`
  (`-2147483648`) is printed correctly without overflow.

## Resources

- `man 3 printf` — reference behavior of the original function
- `man 3 stdarg` — `va_start`, `va_arg`, `va_copy`, `va_end`
- [cppreference — Variadic functions](https://en.cppreference.com/w/c/variadic)
- [cppreference — printf](https://en.cppreference.com/w/c/io/fprintf)
- The 42 Norm (norminette) documentation

### AI usage

An AI assistant (Claude) was used for:

- writing the `Makefile` and this `README.md`.

The `ft_printf` implementation itself (parser, dispatch table, handlers and
utility functions) was designed and written by me.
