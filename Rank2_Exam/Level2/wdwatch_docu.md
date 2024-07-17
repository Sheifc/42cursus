# wdwatch

This function checks if the first string `s1` is a subsequence of the second string `s2`. If `s1` is a subsequence of `s2`, it prints `s1`; otherwise, it does nothing and prints a newline.


1. **Check Argument Count**:
   - The function first checks if exactly two arguments are provided (`argc == 3`). If not, it does nothing and simply prints a newline.

2. **Initialize Variables**:
   - `s1` and `s2` are pointers to the first and second strings passed as arguments, respectively.
   - `i` and `j` are integer variables used to traverse `s1` and `s2`.

3. **Traverse the Second String (`s2`)**:
   - The `while` loop (`while(s2[j])`) iterates through each character in `s2`.
   - Inside the loop, if the current character in `s1` matches the current character in `s2` (`if (s1[i] == s2[j])`), the index `i` is incremented to check the next character in `s1`.
   - The index `j` is always incremented to continue checking the next character in `s2`.

4. **Check if `s1` is a Subsequence**:
   - After the loop, if `s1[i] == '\0'`, it means all characters of `s1` were found in `s2` in order, making `s1` a subsequence of `s2`. In this case, `write(1, s1, i);` prints `s1`.

5. **Print Newline**:
   - `write(1, "\n", 1);` prints a newline character to ensure the output ends properly.


```c
#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        char *s1 = argv[1];
        char *s2 = argv[2];
        int i = 0;
        int j = 0;

        while (s2[j])
        {
            if (s1[i] == s2[j])
                i++;
            j++;
        }
        if (s1[i] == '\0')
            write(1, s1, i);
    }
    write(1, "\n", 1);
    return (0);
}
```

### Explanation of Key Parts:

- **Checking Argument Count**:
  - `if (argc == 3)` ensures the program only runs if there are exactly two arguments provided.

- **Initializing Variables**:
  - `char *s1 = argv[1];` and `char *s2 = argv[2];` assign the first and second command-line arguments to `s1` and `s2`, respectively.
  - `int i = 0;` and `int j = 0;` initialize the indices used to traverse `s1` and `s2`.

- **Traversing `s2`**:
  - The loop `while (s2[j])` iterates through each character of `s2` using `j`.
  - Inside the loop, `if (s1[i] == s2[j]) i++;` checks if the current character in `s1` matches the current character in `s2`. If they match, it increments `i` to check the next character in `s1`.
  - `j++` increments the index for `s2` to continue the loop.

- **Checking Subsequence**:
  - `if (s1[i] == '\0')` checks if the end of `s1` is reached, which indicates that `s1` is a subsequence of `s2`. If true, `write(1, s1, i);` prints `s1`.

- **Printing Newline**:
  - `write(1, "\n", 1);` ensures the output ends with a newline, regardless of whether `s1` was printed or not.
