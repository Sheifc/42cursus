# Inter

The function `inter` takes two strings `s1` and `s2` and prints the characters that are common to both strings, but each common character is printed only once. 

1. **Initialize an Array `tab` of Size 256**:
   - The array `tab` is used to keep track of characters. Since there are 256 possible characters in the ASCII table, the array size is 256.
   - It is initialized to 0 for all elements.

2. **First Loop: Mark Characters in `s2`**:
   - The first loop iterates through the characters in `s2`.
   - For each character in `s2`, it sets the corresponding position in the `tab` array to 1. This marks that the character is present in `s2`.

3. **Second Loop: Check Characters in `s1`**:
   - The second loop iterates through the characters in `s1`.
   - For each character in `s1`, it checks if the corresponding position in the `tab` array is 1, which indicates that the character is present in `s2` and has not yet been printed.
   - If the character is found, it is printed and the corresponding position in the `tab` array is set to 2 to ensure that it is not printed again.

The function thus prints each character that is common to both `s1` and `s2` exactly once.


```c
void inter(char *s1, char *s2)
{
	int i = 0;
	int tab[256] = {0};

	// Mark characters in s2
	while (s2[i])
		tab[(int)s2[i++]] = 1; // Assign 1 to the elements of s2
	i = 0;

	// Check characters in s1
	while (s1[i])
	{
		if (tab[(int)s1[i]] == 1) // If elements of s1 are 1, it means they are in s2
		{
			write(1, &s1[i], 1); // Print the character
			tab[(int)s1[i]] = 2; // Set the value to 2 to prevent reprinting
		}
		i++;
	}
}
```

### Explanation of Key Parts:

- **Array Initialization**:
  - `int tab[256] = {0};` initializes an array of size 256 to 0. This array is used to track the occurrence of characters.

- **First Loop (`s2`)**:
  - `while (s2[i]) tab[(int)s2[i++]] = 1;`
  - This loop runs through each character in `s2`, and for each character, it sets the corresponding index in `tab` to 1. This marks that the character exists in `s2`.

- **Second Loop (`s1`)**:
  - `while (s1[i])`
  - This loop runs through each character in `s1`.
  - `if (tab[(int)s1[i]] == 1)` checks if the character is marked as 1 in `tab`, meaning it exists in `s2` and has not been printed yet.
  - `write(1, &s1[i], 1);` prints the character.
  - `tab[(int)s1[i]] = 2;` sets the index in `tab` to 2 to prevent the character from being printed again.

The function effectively finds and prints characters that are present in both `s1` and `s2`, ensuring each common character is printed only once.

ref: https://www.youtube.com/watch?app=desktop&v=NTyBvR8lJU8
