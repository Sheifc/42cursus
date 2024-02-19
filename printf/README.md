# Introduction 

You are going to discover a very famous and versatile C function: printf(). This exercise is a great opportunity to improve your programming skills. It is an exercise of moderate difficulty
You will also discover variadic functions in C. 
The key to overcoming ft_printf is having well-structured and extensible code. 
Once you pass this exercise, you will be able to include ft_printf() in your libft, so you can use it in future C projects. 

# General instructions 

• Your project must be written in C. 
• Your project must be written following the Standard. If you have additional files or functions, these are included in the Standard check and you will get a 0 if there are any standard errors in any of them. 
• Your functions should not terminate unexpectedly (segfault, bus error, double free, etc.) or have undefined behaviors. If this happens, your project will be considered non-functional and you will receive a 0 during the evaluation. 
• All memory allocated in the heap must be released appropriately when necessary. No memory leaks will be allowed. 
• If the statement requires it, you must provide a Makefile that will compile your source files to the required output with the -Wall, -Werror and -Wextra flags and of course your Makefile must not relink. 
• Your Makefile must contain at least the rules $(NAME), all, clean, fclean and re. 
• To deliver the bonuses of your project you must include a bonus rule in your Makefile, in which you will add all the headers, libraries or functions that are prohibited in the main part of the project. The bonuses must be in different files _bonus.{c/h}.  
The mandatory part and the bonuses are evaluated separately. 
• If your project allows the use of libft, you must copy its source and its associated Makefile into a libft directory with its corresponding Makefile. Your project's Makefile must first compile the library using its Makefile, and then compile the project. 
• We recommend creating test programs for your project, although this work will not be delivered or evaluated. It will give you the opportunity to verify that your program is working correctly during your evaluation and that of other colleagues. 
And yes, you are allowed to use these tests during your evaluation or that of other classmates. 
• Deliver your work to your assigned Git repository. Only work from your Git repository will be evaluated. If Deepthought evaluates your work, it will do so after your colleagues.  
If an error is found during the Deepthought evaluation, the evaluation is terminated. 


# Mandatory part 

Program name: libftprintf.a 
Files to deliver: Makefile, *.h, */*.h, *.c, */*.c 
Makefile: NAME, all, clean, fclean, re 
Authorized functions: malloc, free, write, va_start, va_arg, va_copy, va_end 
Using libft is allowed 
Description: Write a library that contains the function ft_printf(), which imitates the original printf() 

You must reprogram the printf() function of the libc. 
The prototype of ft_printf() is:  int ft_printf(char const *, ...); 

Here are the requirements: 
• Do not implement the buffer management of the original printf(). 
• You must implement the following conversions: cspdiuxX % 
• Your function will be compared with the original printf(). 
• You have to use the ar command to create your library. The use of libtool command is prohibited. 
• Your libftprintf.a file should be created in the root of your repository. 

You have to implement the following conversions: 
• %c Prints a single character. 
• %s Prints a string (as defined by default in C). 
• %p The void * pointer given as an argument is printed in hexadecimal format.  
• %d Prints a decimal number (base 10). 
• %i Prints a base 10 integer. 
• %u Prints an unsigned decimal (base 10) number. 
• %x Prints a hexadecimal (base 16) number in lower case. 
• %X Prints a hexadecimal (base 16) number in uppercase. 
• % % to print the percentage symbol. 

# Bonus part 

It is not necessary to do all the bonuses. 
Bonus list: 
• Manages any combination of the following flags: ’-0.’ and the field minimum width under all possible conversions. 
• Manages all the following flags: ’# +’ (yes, one of them is a space). 
If you want to complete the bonus part, think about the implementation of the extra features from the beginning. 
Thus, you will avoid the dangers of a naive approach. 
The bonus part can only be evaluated if the mandatory part is PERFECT. Perfect means that the mandatory part works at
complete, without any errors or unexpected behavior. If you haven't
passed all the requirements of the mandatory part, it will not be evaluated
nothing of the bonus part. 

# Delivery and evaluation 

Deliver your project to your Git repository as usual. Only the content within your Git repository will be evaluated. Be sure to double check your file names to make sure they are correct.
Once you pass this exercise, you will be able to include ft_printf() in your libft, so you can use it in future C projects.
