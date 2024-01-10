# Get Next Line

This project ask you to develop a solution to be able to read the content of a file line by line and as part of the bonus section, to be able to read line by line from different files.

The most important concept to learn from this project is the handling of static variables. 

# static char *estatic = NULL; It's used to declare a static pointer variable named estatic that points to a character type.

static: This keyword specifies that the variable estatic has a static storage duration. It means that the variable is allocated when the program starts and deallocated when the program ends. Static variables retain their value between function calls if they are declared within a function.

char *: This declares that estatic is a pointer to a character. In C, pointers are used to store memory addresses, and char * indicates that this pointer will point to a memory location where a character (or characters, in case of strings) is stored.

estatic: This is the name of the variable.

= NULL;: Here, estatic is initialized to NULL. In pointer terminology, NULL is a special value that indicates that the pointer is not currently pointing to any valid memory location. It's a good practice to initialize pointers to NULL to avoid them pointing to random memory locations (known as "dangling pointers").

So, in essence, this line of code declares a static pointer to a character and initialises it to point to no location (NULL). This could be used, for example, in a function that needs to remember the address of some data between calls, but starts with no valid address to point to.

## References:
https://www.geeksforgeeks.org/static-variables-in-c/
https://stackoverflow.com/questions/14753036/what-maximum-size-of-static-arrays-are-allowed-in-c

# get_next_line.c

## ft_free
```c
char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}
```

The function takes a double pointer char **str as an argument. It is designed to free a dynamically allocated memory block pointed to by a pointer, and then set that pointer to NULL. In this project, this function will be used to free the static variable. After calling ft_free, the static pointer will become NULL and remain so until explicitly changed.

### Purpose of Double Pointer (char **str)

1. Modify Pointer in Caller Function: A function in C cannot directly modify the contents of a variable in a caller function, including pointers. It can only modify what those pointers point to. To modify the pointer itself, such as changing where it points or setting it to NULL, you need a pointer to that pointer. That's why a double pointer is used.

2. Freeing and Nullifying: When you free a pointer using free(), you deallocate the memory it points to. However, the pointer itself still holds the address of the now-deallocated memory, becoming a dangling pointer. To prevent issues like accidental dereferencing or double freeing, it's good practice to set the pointer to NULL after freeing. To do this from within a function, you need to modify the pointer itself, which requires a double pointer.

# read in C

read and write return the number of bytes read or written, or -1 in case of error. 

## Reference: 
https://pasky.wordpress.com/2009/08/04/funciones-openclose-y-readwrite-en-c/

```c
char	*ft_read(int fd, char *estatic)
{
	int		nbytes;
	char	*buffer;

	nbytes = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(&estatic));
	buffer[0] = '\0';
	// it will continue reading until it finds a '\n' in the 10 bytes read pre-defined as a buffer_size
	// with the example provided, it will perform 2 consecutive reads
	// it will find the '\n' at the second read and stop reading
	while (nbytes > 0 && !ft_strchr(buffer, '\n'))
	{
		nbytes = read (fd, buffer, BUFFER_SIZE); //nbytes are the bytes read by read
		if (nbytes > 0)
		{
			buffer[nbytes] = '\0';
			estatic = ft_strjoin_gnl(estatic, buffer);
		}
	}
	// buffer will be freed because it's not needed anymore
	free(buffer);
	// in case read fails (will return -1), so then static variable will be freed
	if (nbytes == -1)
		return (ft_free(&estatic));
	return (estatic);
}

char	*ft_get_line(char *estatic)
{
	char	*line;
	char	*ptr;
	int		len;

	// ptr is a pointer to '\n' which contains the static
	ptr = ft_strchr(estatic, '\n'); // all files even if it's empty will contain a '/n'
	// len is the lenght from the start of the static to the next position of '\n' (that's why the +1)
	// len = ft_strlen(ptr) - ft_strlen(estatic) + 1; // it's not the same
	len = (ptr - estatic) + 1; 
	// ptr-estatic is the distance between the pointers within the same string
	// line will contain te content of static from start till len bytes 
	line = ft_substr(estatic, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_new_estatic(char *estatic)
{
	char	*new_estatic;
	char	*ptr;
	int		len;
	// ptr is a pointer to '\n' which contains the static
	ptr = ft_strchr(estatic, '\n');
	if (!ptr)
	{
		new_estatic = NULL;
		return (ft_free(&estatic));
	}
	else // estatic is a pointer to the start of the content it holds 
		// len is the lenght from the start of the static to the next position of '\n' (that's why the +1) 
		// len = ft_strlen(ptr) - ft_strlen(estatic) + 1; it's not the same
		len = (ptr - estatic) + 1; 
		// ptr-estatic is the distance between the pointers within the same string
	if (!estatic[len])
		return (ft_free(&estatic));
	// len will be the start
	// new_estatic will contain the content from len position (which is 1 byte more than the position of '\n') to the end of the static, so it will contain the extra content read after the line, this will be available for the next call to be able to join it with the rest content until next '\n' in order to print the next line
	new_estatic = ft_substr(estatic, len, ft_strlen(estatic) - len);
	// we obtain with ft_substr the extra content after the '\n'
	// therefore, we free the old static
	ft_free(&estatic);
	if (!new_estatic)
		return (NULL);
	return (new_estatic);
}

char	*get_next_line(int fd)
{
	static char	*estatic = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// if there is a static variable and it's not a '\n' or the static is null, it will proceed reading
	if ((estatic && !ft_strchr(estatic, '\n')) || !estatic)
		estatic = ft_read (fd, estatic);
	// if nothing has been saved after read in static, it will return null
	if (!estatic)
		return (NULL);
	// to obtain the content of the line that will be returned by the function
	line = ft_get_line(estatic);
	if (!line)
		return (ft_free(&estatic));
	// update the content of static with the extra content after getting line 
	// this will be available in static when we call next time the function
	// to be concatenated with join to the new content read and be able to return the next line
	estatic = ft_new_estatic(estatic);
	return (line);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);
	int fd = open(argv[1], O_RDONLY);
	char *line = get_next_line(fd);
	printf("line: %s\n", line);
	system("leaks a.out");
}
```
Auxiliary Functions:
--------------------

ft_strlen will calculate the length of a string

```c
size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

ft_strchr will look for c inside of s

char	*ft_strchr(char *s, int c)
{
	while (*s != (char)c)
	{
		if (!*s)
			return (NULL);
		s++;
	}
	return ((char *)s);
}

ft_strdup will copy the content from s1 into p which has been dynamically allocated

char	*ft_strdup(char *s1)
{
	size_t	len;
	size_t	i;
	char	*p;

	len = ft_strlen(s1) + 1;
	p = (char *)malloc(sizeof(char) * len);
	i = -1;
	if (!p)
		return (0);
	while (s1[++i])
		p[i] = s1[i];
	p[i] = '\0';
	return (p);
}

ft_strjoin_gnl will join the content of s2 to s1

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	// if it doesn't point to a valid s1, it will be converted to a valid empty string 
	// This results in a string that only contains a null character ('\0'), 
	// which effectively converts s1 in a valid string that can handle
	if (!s1)
	{
		s1 = ft_strdup("");
		if (!s1) // if strdup fails, then it will return null
			return (0);
	}
	str = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (ft_free(&s1));
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

The function ft_strdup is utilised in ft_strjoin_gnl to handle a specific case: when s1 is NULL. Let's look at why it's necessary to use ft_strdup in this context:

Handling s1 NULL in ft_strjoin_gnl:

The function ft_strjoin_gnl is designed to concatenate two strings, s1 and s2.
If s1 is NULL at the start of the function, you can't proceed directly with the concatenation, as there's no existing string to which s2 can be appended.
Therefore, you need a way to initialise s1 with an empty string so that it can be concatenated with s2.
Using ft_strdup to Initialise s1:

ft_strdup(""): This line creates a new string that is a copy of an empty string ("").
The ft_strdup function dynamically allocates memory for this new string and copies the content of the empty string to this new memory location.
This provides s1 with an initial value (an empty string) on which the concatenation with s2 can be performed.
Why Not Directly Assign s1 = "":

Assigning s1 = "" would simply make s1 point to an empty string literal, but it wouldn't allocate new memory.

In ft_strjoin_gnl, s1 is freed at the end (free(s1)), and freeing a string literal (like "") isn't valid, as string literals aren't in dynamic memory.

Hence, it's important that s1 be a string in dynamic memory, even if it's empty, so that memory operations (like freeing) are valid.

In summary, ft_strdup is used in ft_strjoin_gnl to initialise s1 with an empty string in dynamic memory when s1 is NULL. This allows the function to proceed correctly with the concatenation and manage memory in a safe and coherent manner.

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	// If the input string s is NULL, the function returns NULL) for safety
	if (!s)
		return (NULL);
	// If the starting index start is greater than the length of s, there's nothing to extract
	if (start > ft_strlen(s))
	{
		// Memory is allocated for a string of size 1 (just the null terminator).
		str = malloc(sizeof(char) * (1));
		if (!str)
			return (NULL);
		str[0] = '\0'; // The new string is initialised to an empty string
		return (str);
	}
	// If the remaining length of s after start is less than len, adjust len to this remaining length
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	// Allocate memory for the new substring, including space for the null terminator
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	// While the end of s hasn't been reached and len characters haven't been copied, copy the characters from s to str
	while (start < ft_strlen(s) && i < len && s[start])
		str[i++] = s[start++];
	// Null-terminate the new string
	str[i] = '\0';
	// The function returns the new substring
	return (str);
}
```