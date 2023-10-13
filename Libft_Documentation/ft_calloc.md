# ft_calloc function:

NAME: calloc, free, malloc, realloc, reallocf, valloc, aligned_alloc – memory allocation
SYNOPSIS
     #include <stdlib.h>
     void *calloc(size_t count, size_t size);

DESCRIPTION: The malloc(), calloc(), valloc(), realloc(), and reallocf() functions allocate memory.  The allocated memory is aligned such that it can be used for any data type, including AltiVec- and SSE-related types.  The aligned_alloc() function allocates memory with the requested alignment.  The free() function frees allocations that were created via the preceding allocation functions.

The malloc() function allocates size bytes of memory and returns a pointer to the allocated memory.

The calloc() function contiguously allocates enough space for count objects that are size bytes of memory each and returns a pointer to the allocated memory.  The allocated memory is filled with bytes of value zero.

RETURN VALUES: If successful, calloc(), malloc(), realloc(), reallocf(), valloc(), and aligned_alloc() functions return a pointer to allocated memory.  If there is an error, they return a NULL pointer and set errno to ENOMEM.

# Implementation

The `ft_calloc` function is an implementation of the `calloc` function, which is used to allocate memory for an array of elements and initialize all the bytes in the allocated memory to zero. Here's a step-by-step explanation of how this function works:

1. Function Signature:
   - `void *ft_calloc(size_t count, size_t size)`
   - The function takes two parameters: `count` and `size`, which represent the number of elements in the array and the size (in bytes) of each element, respectively.

2. Memory Allocation:
   - `void *p;`: Declares a pointer `p` of type `void*`. This pointer will be used to store the address of the allocated memory block.

   - `if (!(p = (void *)malloc(count * size)))`: This line uses the `malloc` function to allocate memory for an array of `count` elements, each of size `size` bytes.
     - `malloc(count * size)` allocates a contiguous block of memory with a total size of `count * size` bytes.
     - `if (!(p = (void *)malloc(count * size)))` checks if the memory allocation was successful. If `malloc` returns a `NULL` pointer (indicating failure to allocate memory), the condition is true.

3. Check for Allocation Success:
   - If the memory allocation was successful (i.e., `malloc` did not return `NULL`), the code inside the `if` block is executed.

4. Memory Initialization:
   - `ft_bzero(p, (count * size));`: This line initializes the allocated memory block pointed to by `p` to zero using the `ft_bzero` function (which is not shown in your code but is assumed to set a block of memory to zero). This step ensures that all elements in the allocated memory are set to zero.

5. Return Allocated Memory:
   - `return (p);`: The function returns the pointer `p`, which now points to the beginning of the allocated and initialized memory block.

In summary, the `ft_calloc` function allocates a block of memory for an array, initializes all the bytes in that memory to zero, and returns a pointer to the allocated memory. It is a custom implementation of the standard `calloc` function, which serves the same purpose.

```c
void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = (void *)malloc(count * size);
	if (!p)
		return (NULL);
	ft_bzero(p, (count * size));
	return (p);
}
```