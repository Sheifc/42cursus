# ft_bzero function: 

NAME: bzero – write zeroes to a byte string.
LIBRARY: Standard C Library (libc, -lc)
SYNOPSIS
     #include <strings.h>
     void bzero(void *s, size_t n);

DESCRIPTION: The bzero() function writes n zeroed bytes to the string s.  If n is zero, bzero() does nothing.

# Implementation:

Your `ft_bzero` function implementation follows the general idea of the `bzero` function, which sets a block of memory to zero. 

```c
#include "libft.h"

void ft_bzero(void *s, size_t n)
{
    char *p;

    p = (char *)s;
    while (n--)
        *p++ = 0;
}
/* int main(void)
{
	char s[5] = "Hola";
	ft_bzero(s, 2);
} */
```

# Reason of using n-- and not --n: 

The loop runs exactly `n` times, which means it zeroes out `n` bytes.

```c
while (n--)
    *p++ = 0;
```
The loop will run `n - 1` times because `--n` will decrement `n` before the loop condition is checked. Therefore, it will zero out only `n - 1` bytes.

```c
while (--n)
    *p++ = 0;
```

So, the second option would not be a correct replacement for the original `ft_bzero`, as it wouldn't set the last byte to zero.

# Step by step: 

1. `#include "libft.h"`: It includes the `libft.h` header file, which is a good practice when using functions and types defined in your own library.

2. `void ft_bzero(void *s, size_t n)`: This is the function signature for your `ft_bzero` function. It takes two parameters:
   - `void *s`: A pointer to the memory block you want to set to zero.
   - `size_t n`: The number of bytes to set to zero, starting from the address pointed to by `s`.

3. `char *p;`: It declares a `char` pointer `p` to be used for traversing the memory block pointed to by `s`.

4. `p = (char *)s;`: It casts the `void` pointer `s` to a `char` pointer `p`. This is necessary because `void` pointers cannot be directly dereferenced, so you cast it to a `char` pointer to make it possible to access individual bytes.

5. `while (n--) *p++ = 0;`: This loop iterates `n` times, where `n` is the number of bytes specified. In each iteration, it sets the byte pointed to by `p` to zero (`0`) and then increments the pointer `p` to move to the next byte. This effectively sets all `n` bytes starting from the address pointed to by `s` to zero.

Overall, the `ft_bzero` function implementation aligns with the behavior of the standard `bzero` function, which sets a block of memory to zero. 

## Using char: 

The `ft_bzero` function, like `ft_memset`, operates on a block of memory, setting bytes to zero. Therefore, it's appropriate and conventional to use `char` to represent the byte value to set to zero in the `ft_bzero` function.

This implementation is consistent with the standard `bzero` function and maintains clarity and compatibility with memory operations. Using `char` as the parameter type makes it evident that you are setting memory bytes to zero, which is the typical use case for the `bzero` function.

For more detailed information, check the file ft_memset.md.