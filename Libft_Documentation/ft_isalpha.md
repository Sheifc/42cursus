# ft_isalpha function

NAME: isalpha – alphabetic character test
LIBRARY: Standard C Library (libc, -lc)
SYNOPSIS
     #include <ctype.h>
     int isalpha(int c);

DESCRIPTION: The isalpha() function tests for any character for which isupper(3) or islower(3) is true.

# Implementation: 

The `ft_isalpha` function implementation follows the standard behavior expected from the `isalpha` function in C. Here's an explanation of the implementation:

```c
#include "libft.h"

int ft_isalpha(int c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    else
        return (0);
}

/*
int	main(void)
{
	printf("%i", ft_isalpha('P'));
	printf("%i", isalpha('P'));
	return (0);
} */
```

This function checks if the input character `c` is an alphabetic character (a letter) and returns `1` if it is, indicating that the character is alphabetic. Otherwise, it returns `0`, indicating that the character is not alphabetic.

Here's a breakdown of the implementation:

- `#include "libft.h"`: You've included the `libft.h` header file, which is a good practice when using functions in your library.

- `int ft_isalpha(int c)`: This is the function signature for `ft_isalpha`. It takes one parameter, `c`, which is an integer representing a character.

- `if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))`: This is the conditional statement that checks if `c` is within the range of lowercase (`'a'` to `'z'`) or uppercase (`'A'` to `'Z'`) alphabetic characters. If `c` falls within either of these ranges, the condition evaluates to true.

- `return (1);`: If the condition is true, meaning `c` is an alphabetic character, the function returns `1` to indicate that it's an alphabetic character.

- `return (0);`: If the condition is false, meaning `c` is not an alphabetic character, the function returns `0` to indicate that it's not an alphabetic character.

The `ft_isalpha` function is implemented and can be used to determine if a given character is an alphabetic character.

# Why uses int instead of char: 

Using `int` instead of `char` as the parameter type for functions like `ft_isalpha` is a common practice in the C standard library and in many C libraries for a couple of reasons:

1. **Extended Character Set**: In the C standard, `EOF` (End of File) is represented as an `int` with a value that cannot be confused with a valid character. Using `int` allows you to handle the extended character set, including all valid character values and `EOF`, without ambiguity.

2. **Compatibility with Other Functions**: Many standard library functions (e.g., `getchar`, `fgetc`, etc.) return values of type `int`, which makes it convenient to pass their results directly to functions like `ft_isalpha`. If `ft_isalpha` accepted a `char`, it might not be able to distinguish between a valid character and `EOF` returned by those functions.

3. **Consistency**: Consistency with other standard library functions and conventions is essential for code readability and interoperability. By using `int` for character functions, libraries ensure that they align with established conventions.

While you could technically use `char` for functions like `ft_isalpha`, it's generally more practical and compatible to use `int`, especially when dealing with character functions that need to handle both valid character values and special values like `EOF`.