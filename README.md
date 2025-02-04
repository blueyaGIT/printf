<p align="center">
  <img src="https://github.com/blueyaGIT/blueyaGIT/blob/master/42_badges/ft_printfe.png?raw=true" alt="printf"/>
</p>

<p align="center">
  Score: <i>102/100</i><br>
  Finished: <i>20.10.2024</i><br>
</p>

###

`ft_printf` is a custom implementation of the standard `printf` function in C. It allows formatted output with various format specifiers and handles multiple data types. This project is part of the 42 School curriculum.

## Usage

To use `ft_printf`, clone the repository in the root of your project using one of the following commands:

#### SSH
```bash
git clone git@github.com:blueyaGIT/ft_printf.git
```
#### HTTPS
```bash
git clone https://github.com:blueyaGIT/ft_printf.git
```
#### GitHub CLI
```bash
gh repo clone blueyaGIT/ft_printf
```
This will create a directory called `ft_printf/`. Enter it with the command:

```bash
cd ft_printf
```

### Compiling

`ft_printf` is provided in `.c` and `.h` files, which you can include in your project. To compile a test program, you can use:

```bash
gcc -Wall -Wextra -Werror ft_printf.c ft_printf_utils.c main.c -o printf
```

## Example Usage

```c
#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int value = 42;
    ft_printf("Hello, World! Value: %d\n", value);
    return (0);
}
```

## Files

- `ft_printf.c` - Contains the `ft_printf()` function implementation.
- `ft_printf.h` - Header file with function prototypes and necessary includes.
- `ft_*.c` - Utility functions used by `ft_printf()`.

## Function Description

### `int ft_printf(const char *format, ...);`
Formats and prints data to the standard output based on format specifiers.

- Returns the number of characters printed (excluding `\0`).
- Supports format specifiers such as `%c`, `%s`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%p`.

## Notes

- Ensure proper handling of variable arguments to avoid undefined behavior.
- The function is designed to mimic standard `printf` but does not support all its features.
- Memory allocation is not required unless additional dynamic operations are introduced.

For more details, refer to the project documentation or the `42` subject PDF.

## 🚀 Next Project

<a href="https://github.com/blueyaGIT/get_next_line"><img src="https://readme-typing-svg.demolab.com?font=Fira+Code&pause=1000&color=BF94E4&width=435&lines=get_next_line"></a>

## ⏳ Previous Project

<a href="https://github.com/blueyaGIT/libft"><img src="https://readme-typing-svg.demolab.com?font=Fira+Code&pause=1000&color=BF94E4&width=435&lines=libft"></a>