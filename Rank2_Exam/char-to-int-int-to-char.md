### Character to Integer Conversion (`char` to `int`)

When you convert a character representing a numeric digit to an integer, you subtract the character `'0'` from the digit. This is because of how characters are stored in the ASCII table: the characters `'0'` to `'9'` are sequential, and `'0'` has a lower associated integer value than `'1'`, `'2'`, etc. Therefore, to get the actual integer value of the character, you subtract the ASCII value of `'0'` from the ASCII value of the digit.

For example, if you have the character `'2'`, to convert it to an integer you subtract `'0'`:
```c
char c = '2';
int num = c - '0'; // num will be 2
```

### Integer to Character Conversion (`int` to `char`)

On the other hand, when you convert an integer to its character representation, you do the opposite: you add the character `'0'` to the digit. This is because you are reversing the previous process: you are mapping the integer value to the corresponding character in the ASCII table.

For example, to convert the integer 2 into a character:
```c
int c = 2;
char num = c + '0'; // num will be '2'
```

### In the Context of the `ft_atoi` and `ft_putnbr_fd` Functions

- **`ft_atoi`**: This function converts a string of characters into an integer. Each time it encounters a digit in the string, it multiplies the accumulated number by 10 (to "move it one place to the left") and then adds the integer value of the current digit.
  ```c
  res = res * 10 + (str[i] - '0');
  ```
  Here, `(str[i] - '0')` converts the current character to its integer value.

- **`ft_putnbr_fd`**: This function does the opposite, converting an integer into a sequence of characters. When working with each digit of the number, it converts it to its character representation by adding `'0'`.
  ```c
  char c = n % 10 + '0';
  ```
  Here, `n % 10` gets the least significant digit of `n`, and adding `'0'` converts it into the corresponding character.