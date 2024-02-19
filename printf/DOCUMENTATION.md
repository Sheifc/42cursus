# ft_printf: a simplified version of the printf function in C

It includes implementations for various format specifiers such as %c, %s, %p, %d, %i, %u, %x, and %X. ft_printf function takes a format string and a variable number of arguments, then processes the string and the arguments according to the format specifiers. It uses the va_list to process a variable number of arguments.

# ft_printf_utils.c

ft_putchar_pf: Writes a single character to the standard output.
ft_putstr_pf: Writes a string to the standard output.
ft_putptr_pf: Writes a pointer value to the standard output.
ft_putnbrbase_pf: Writes an integer in a specified base to the standard output.
ft_putnbrbase_ptr_pf: Writes an unsigned long integer in a specified base to the standard output.
ft_print_format: Determines which helper function to call based on the format specifier.
ft_printf: Main function that processes the format string and calls ft_print_format.

```c
// ft_putchar_pf(int c): Writes a single character c to the standard output (file descriptor 1) using write and returns the number of characters written, which is 1.
int	ft_putchar_pf(int c)
{
	return (write(1, &c, 1));
}

// ft_putstr_pf(char *str): Writes a string str to the standard output and returns the number of characters written. If str is NULL, it prints (null).
int	ft_putstr_pf(char *str)
{
	int	i; //Declares an integer i to keep track of the number of characters written.

	i = 0; //Initialises i to zero.
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (*str)
		i += write(1, str++, 1);
	return (i);
}

// ft_putptr_pf(unsigned long ptr): Writes the pointer address ptr to the standard output in hexadecimal format, prefixed with "0x". Returns the number of characters written.
int	ft_putptr_pf(unsigned long ptr)
{
	int		i;

	i = 0;
	i += ft_putstr_pf("0x"); //Writes the prefix "0x" to indicate a hexadecimal number, these number of characters written (2) are added to i.
	if (ptr == 0)
		i += ft_putchar_pf('0'); //Checks if ptr is zero. If it is, writes '0' to the standard output.
	else
		i += ft_putnbrbase_ptr_pf(ptr, 16, "0123456789abcdef"); // If ptr is not zero, the function ft_putnbrbase_ptr_pf is called to convert ptr to a hexadecimal string and write it to the standard output.
	return (i);
}

// ft_putnbrbase_ptr_pf(unsigned long n, int base, const char *base_digits): Writes the unsigned long number n to the standard output using base_digits for conversion. Returns the number of characters written.
int	ft_putnbrbase_ptr_pf(unsigned long n, int base, const char *base_digits)
{
	int	i;

	if (n < (unsigned long) base) //If n is smaller than the base, then the function simply writes the corresponding digit character (from base_digits) to the standard output.
		return (ft_putchar_pf(base_digits[n]));
	else //If n is greater than or equal to base, the function calls itself twice:
		//First for n / base to get the higher-order digits.
		//Then for n % base to the current digit.
	{
		i = ft_putnbrbase_ptr_pf(n / base, base, base_digits); 
		return (i + ft_putnbrbase_ptr_pf(n % base, base, base_digits));
	}
}

//n is type of unsigned long, in the context of the ft_putnbrbase_ptr_pf and ft_putptr_pf functions, n is used to hold the numerical value of a pointer, not to act as a pointer itself.

// ft_putnbrbase_ptr_pf itself doesn't directly print the numbers to the standard output. Instead, it returns the number of characters that should be printed, and the actual printing is done in the ft_putchar_pf function which is called within ft_putnbrbase_ptr_pf.

// Example:
/*Suppose you want to print the value 22 in hexadecimal (base 16).

In hexadecimal, 22 is represented as 16. Here's how ft_putnbrbase_ptr_pf would handle this:

First call to ft_putnbrbase_ptr_pf(22, 16, "0123456789abcdef")

22 >= 16, so it goes to the else block.
It makes a recursive call with 22 / 16 which is 1.
Second call to ft_putnbrbase_ptr_pf(1, 16, "0123456789abcdef")

1 < 16, so it goes to the if block.
ft_putchar_pf(base_digits[1]) is called, which prints 1.
Returns 1 (one character printed).
Back to the first call

It continues with the line return (i + ft_putnbrbase_ptr_pf(22 % 16, 16, "0123456789abcdef"));.
Makes a new recursive call with 22 % 16 which is 6.
Third call to ft_putnbrbase_ptr_pf(6, 16, "0123456789abcdef")

6 < 16, so it goes to the if block.
ft_putchar_pf(base_digits[6]) is called, which prints 6.
Returns 1 (one character printed).
Back to the first call again

Now it finally returns 1 (from second call) + 1 (from third call) = 2.
So, the output would be 16 and the function would return 2 to indicate that 2 characters were printed. The higher-order digit (1) is printed first, followed by the lower-order digit (6).*/

// ft_putnbrbase_pf(long n, int base, const char *base_digits): Writes the number n to the standard output using base_digits for conversion. Returns the number of characters written. It can handle negative numbers.
int	ft_putnbrbase_pf(long n, int base, const char *base_digits)
{
	int	i;

	if (n < 0)
	{
		write(1, "-", 1);
		// recursive with a positive value in this case
		return (ft_putnbrbase_pf(-n, base, base_digits) + 1); //+1 to count the "-"
	}
	if (n < base)
		return (ft_putchar_pf(base_digits[n])); // print the base_digits in the position n
	else
	{
		i = ft_putnbrbase_pf(n / base, base, base_digits);
		return (i + ft_putnbrbase_pf(n % base, base, base_digits));
	}
}

```

# ft_print.c: uses variable arguments (va_list) to support various types of data to be printed in a formatted way

```c
// ft_print_format(char format, va_list ap): Writes the next argument from va_list to the standard output according to the format specifier. Returns the number of characters written.
int	print_format(char format, va_list ap) //returns the amount of bytes written too
{
	int			i;

	i = 0;
	if (format == 'c')
		i += ft_putchar_pf(va_arg(ap, int)); //type promotion: automatic data type promotion that happens implicity
									  //from a lower-ranking to a higher(which is not the same than bigger) ranking data type
	else if (format == 's')
		i += ft_putstr_pf(va_arg(ap, char *));
	else if (format == 'p')
		i += ft_putptr_pf(va_arg(ap, unsigned long)); //the pointer is not going thr type promotion
	else if (format == 'd' || format == 'i')
		i += ft_putnbrbase_pf((long)va_arg(ap, int), 10, "0123456789");
	else if (format == 'u')
		i += ft_putnbrbase_pf((long)va_arg(ap, unsigned int), 10, "0123456789");
	else if (format == 'x')
		i += ft_putnbrbase_pf((long)va_arg(ap, unsigned int), 16, "0123456789abcdef");
	else if (format == 'X')
		i += ft_putnbrbase_pf((long)va_arg(ap, unsigned int), 16, "0123456789ABCDEF");
	else
		i += write(1, &format, 1); //write is used to write data to a file descriptor. Here, 1 is the file descriptor for standard output (stdout).
		//&format: Address of the format variable (which is a char in this context).
		//1: Number of bytes to write.
	return (i);
}

// ft_printf(char const *format, ...): Processes a format string and a variable number of arguments, writing to the standard output according to format specifiers. Returns the total number of characters written.
int	ft_printf(char const *format, ...)
{
	va_list	ap; //arg pointer to the serie of arguments va (vector/variable arguments)
	int		i;

	va_start(ap, format); //its going to move the pointer ap to the first argument
	if (write(1, "", 0) == -1)
		return (-1);
	i = 0;
	while (*format)
	{
		if (*format == '%') // 1.here the pointer is in the position %
			i += print_format(*(++format), ap); // first print format and then dereference it
			// 2. the pointer moves to next position that will be for example letter s (%s)
			// 3. Then dereference it to get the value of s
			// print_format is going to retrieve the amount of formats that are written
			// that is saved into the counter i

			// "Dereferencing" is the act of accessing the value that a pointer is pointing to
		else
			i += write(1, format, 1);
		++format;
	}
	va_end(ap); //cleans va_start, va_arg, va_list, its like free, liberate the memory allocated
	return (i);

	//va_arg(ap, int)// va_arg allows me to fetch the argument (pointer, data type I want to retrieve)
}

int	main(void)
{
	int	count; 

	count = ft_printf("Hello %s\n", "Sheila");
	ft_printf("The chars written are %d\n", count);
	count = ft_printf("%x\n", 42);
	ft_printf("The chars written are %d\n", count);
	// printf("%x %d", -42, -42) // we obtain the binary for the first and -42 for the second, so printf for hexadecimal, is taking unsigned int 
	count = ft_printf("Hello %s\n", "John");

	printf("%d chars\n", count);//, fflush(stdout);
	count = ft_printf("Char-> %c\n", 'a');
	printf("%d chars\n", count);//, fflush(stdout);
	count = ft_printf("Nbr-> %d\n", -42);
	printf("%d chars\n", count);//, fflush(stdout);
	count = ft_printf("Hex-> %x\n", -1);
	printf("%d chars\n", count);//, fflush(stdout);
}

// reference:https://www.youtube.com/watch?v=byRw36Y3Hjs&t=474s

/*In a call of a variatic function the default argument promotions are performed on the optional arguments values. This means the object of type char or short int(wether signed or not) are promoted to either int or unsigned int and type float are promoted to type double.

So, if the caller passes a char as an optional argument, it is promoted to an int, the function can access it with va_arg(ap,int).

This happens when we don't have a prototype like it happens in a variatic function.
A char is a 1 byte integer
A short 2 bytes
An int 4 bytes
A long 8 bytes element
A Float 4 bytes
A double 8 bytes

The va_arg macro performs some type promotion internally, based on the type specified as a parameter to the macro.

The reason for this promotion is that smaller integer typers may not be properly aligned on the stack or in CPU registers which can cause performance issues or even crashes on some platforms. 
By promoting these types to int, which is typically properly aligned, the va_arg macro
ensures that the arguments are handled correctly and safely*/
