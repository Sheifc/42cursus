<div align="justify">

# My-first-library-in-C-libft

As part of the common course at the 42 programming campus, I developed my first library in C where I am implementing my own version of 43 C functions.

There is a pdf uploaded where it can be found the subject of the project in Spanish. Subject translated to English: 

# Subject

## **Libft Your First Library**

### **Summary**: This project involves programming a library in C.

Your library will have a bunch of general-purpose functions that your programs will rely on. 

## **Chapter I Introduction**

Programming in C can be tedious when one doesn't have access to the most commonly used functions. This project will allow you to understand how these functions work, how to implement them, and learn to use them. You'll create your own library, which will be very useful as you'll use it in subsequent C projects.

Make sure to continually enrich your libft throughout your cursus. However, when using your library, ensure that all the functions used by your library comply with those permitted in each project. 

## **Chapter II General Instructions**

• Your project must be written in C.  
• Your project should adhere to the Norm. If you have additional files or functions, they are included in the Norm verification, and you'll score 0 if there's any standard error in any of them.  
• Your functions should not terminate unexpectedly (segfault, bus error, double free, etc.) nor exhibit undefined behavior. If this happens, your project will be deemed non-functional, and you will receive a 0 during evaluation.  
• All memory allocated on the heap must be properly freed when necessary. Memory leaks are not permitted.  
• If required by the assignment, you must deliver a Makefile that compiles your source files to the required output with flags -Wall, -Werror, and -Wextra, and of course, your Makefile must not relink.  
• Your Makefile must contain at least the rules $(NAME), all, clean, fclean, and re.  
• To submit the bonuses of your project, you must include a bonus rule in your Makefile, where you will add all headers, libraries, or functions that are forbidden in the main part of the project. The mandatory part and the bonuses are evaluated separately.  
• If your project allows the use of libft, you must copy its source and associated Makefiles into a libft directory with its corresponding Makefile. The Makefile of your project must first compile the library using its Makefile and then compile the project.  
• We recommend creating test programs for your project, although this work will not be submitted or evaluated. It will give you the opportunity to verify that your program works correctly during your evaluation and that of your peers. And yes, you are allowed to use these tests during your evaluation or that of your peers.  
• Submit your work in your assigned Git repository. Only the work from your Git repository will be evaluated. If Deepthought evaluates your work, it will do so after your peers. If an error is found during Deepthought's evaluation, the evaluation will have ended.  

## **Chapter III Mandatory Part**

| Title | Description |
| :----------- | :---------- |
| Program Name | libft.a |
| Files to Submit | Makefile, libft.h, ft_*.c |
| Makefile | NAME, all, clean, fclean, re | 
| Authorized Functions | Details below |
| Use of libft allowed | you don't have it yet | 
| Description | Write your own library: a set of functions that will be a very useful tool throughout the cursus. | 

## **III.1. Technical Considerations**

• Declaring global variables is prohibited.
• If you need to split a complex function into several, make sure to use the word static for it. This way, the functions will stay in the appropriate file.
• Put all your files in the root of your repository.
• Delivering unused files is prohibited.
• All .c files must be compiled with flags -Wall -Werror -Wextra.
• You must use the ar command to generate the library. The use of libtool is prohibited.
• Your libft.a must be created at the root of the repository. 

## **III.2. Part 1 - libc Functions**

To start, you must remake some of the libc functions. Your functions will have the same prototypes and will implement the same behaviors as the original functions. They must be as described in the man. The only difference will be the nomenclature. They will start with the prefix "ft_". For example, strlen will become ft_strlen.

Some functions have the word "restrict" in their prototypes.
This word is part of the c99 standard. Therefore, it is
prohibited to include it in your own prototypes, as well as to compile your
code with the -std=c99 flag. 

You must write your own functions implementing the following original functions. 
They do not require authorized functions:

• isalpha • isdigit • isalnum • isascii • isprint • strlen • memset • bzero
• memcpy • memmove • strlcpy • strlcat
• toupper • tolower • strchr • strrchr • strncmp • memchr • memcmp • strnstr • atoi 

To implement these other two functions, you will have to use malloc():

• calloc • strdup 

## **III.3. Part 2 - Additional Functions**

In this second part, you must develop a set of functions that either are not from the libc library or are but in a different form. Some of the following functions can be done more
easily if you use functions from part 1. 
  
| Title | Description |
| :----------- | :---------- |
| Function Name | ft_substr |
| Prototype | char *ft_substr(char const *s, unsigned int start, size_t len); |
| Files to Submit | - |
| Parameters | s: The string from which to create the substring. start: The index of the character in 's' from which to start the substring. len: The maximum length of the substring. |
| Return Value | The resulting substring. NULL if memory reservation fails. | 
| Authorized Functions | malloc | 
| Description | Allocates (with malloc(3)) and returns a substring of the string 's'. The substring starts from the index 'start' and has a maximum length 'len'. | 

| Title | Description |
| :----------- | :---------- |
| Function Name | ft_strjoin | 
| Prototype | char *ft_strjoin(char const *s1, char const *s2); |
| Files to Submit | - |
| Parameters | s1: The first string. s2: The string to add to 's1'. | 
| Return Value | The new string. NULL if memory reservation fails. | 
| Authorized Functions | malloc |
| Description | Allocates (with malloc(3)) and returns a new string, formed by the concatenation of 's1' and's2'. |

| Title | Description |
| :----------- | :---------- |
| Function Name | ft_strtrim | 
| Prototype | char *ft_strtrim(char const *s1, char const *set); |
| Files to Submit | - |
| Parameters | s1: The string to be trimmed. set: The characters to remove from the string. | 
| Return Value | The trimmed string. NULL if memory reservation fails. |
| Authorized Functions | malloc |
| Description | Removes all characters in the string 'set' from the beginning and end of 's1', until a character not belonging to 'set' is found. The resulting string is returned with a malloc(3) reservation. | 

| Title | Description |
| :----------- | :---------- |
| Function Name | ft_split |
| Prototype | char **ft_split(char const *s, char c); |
| Files to Submit | - |
| Parameters | s: The string to split. c: The delimiter character. |
| Return Value | The array of new strings resulting from the separation. NULL if memory reservation fails. |
| Authorized Functions | malloc, free |
| Description | Allocates (using malloc(3)) an array of strings resulting from splitting the string 's' into substrings using the character 'c' as a delimiter. The array must end with a NULL pointer. | 

| Title | Description |
| :----------- | :---------- |
| Function Name | ft_itoa |
| Prototype | char *ft_itoa(int n);
| Files to Submit | - | 
| Parameters | n: the integer to convert. | 
| Return Value | The string representing the number. NULL if memory reservation fails. |
| Authorized Functions | malloc |
| Description | Using malloc(3), generates a string that represents the integer value received as an argument. Negative numbers must be managed. |

| Title | Description |
| :----------- | :---------- |
| Function Name | ft_strmapi |
| Prototype | char *ft_strmapi(char const *s, char (*f)(unsigned int, char)); |
| Files to Submit | - |
| Parameters | s: The string to iterate over. f: The function to apply to each character. |
| Return Value | The string created after correctly using 'f' on each character. NULL if memory reservation fails. |
| Authorized Functions | malloc |
| Description | Applies the function 'f' to each character of the string 's', giving as parameters the index of each character within 's' and the character itself. Generates a new string with the result of successive use of 'f'. |

| Title | Description |
| :----------- | :---------- |
| Function Name | ft_striteri |
| Prototype | void ft_striteri(char *s, void (f)(unsigned int, char)); |
| Files to Submit | - |
| Parameters | s: The string to iterate over. f: The function to apply to each character. |
| Return Value | Nothing |
| Authorized Functions | None |
| Description | Applies the function 'f' to each character of the string 's', giving as parameters the index of each character within 's' and the address of the character, which may be modified if necessary. |

| Title | Description |
| :----------- | :---------- |
| Function Name | ft_putchar_fd |
| Prototype | void ft_putchar_fd(char c, int fd); |
| Files to Submit | - |
| Parameters | c: The character to send. fd: The file descriptor to write on. |
| Return Value | Nothing |
| Authorized Functions | write |
| Description | Sends the character 'c' to the specified file descriptor. | 

| Title | Description |
| :----------- | :---------- |
| Function Name | ft_putstr_fd |
| Prototype | void ft_putstr_fd(char *s, int fd); |
| Files to Submit | - |
| Parameters | s: The string to send. fd: The file descriptor to write on. |
| Return Value | Nothing |
| Authorized Functions | write |
| Description | Sends the string 's' to the specified file descriptor. |

| Title | Description |
| :----------- | :---------- |
| Function Name | ft_putendl_fd |
| Prototype | void ft_putendl_fd(char *s, int fd); |
| Files to Submit | - |
| Parameters | s: The string to send. fd: The file descriptor to write on. | 
| Return Value | None. |
| Authorized Functions | write |
| Description | Sends the string 's' to the given file descriptor, followed by a newline. 

| Title | Description |
| :----------- | :---------- |
| Function Name | ft_putnbr_fd |
| Prototype | void ft_putnbr_fd(int n, int fd); |
| Files to Submit | - |
| Parameters | n: The number to send. fd: The file descriptor to write on. Return Value None. |
| Authorized Functions | write. |
| Description | Sends the number 'n' to the given file descriptor. |
</div>
