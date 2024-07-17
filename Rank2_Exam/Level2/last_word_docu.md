# Last word

This function processes a command-line argument and prints the last word in the string passed as the argument, ignoring any trailing spaces or tabs. 

1. **Check Argument Count**:
   - The function checks if exactly one argument is passed (`argc == 2`). If not, it does nothing and simply prints a newline.

2. **Initialize Variables**:
   - `s` is a pointer to the string passed as the argument.
   - `i`, `start`, and `end` are integer variables used to traverse and mark positions in the string.

3. **Find the Length of the String**:
   - The first `while` loop (`while(s[i]) i++;`) moves `i` to the end of the string.

4. **Ignore Trailing Spaces and Tabs**:
   - The second `while` loop (`while(s[i] == 32 || s[i] == 9) i--;`) moves `i` backward to skip any trailing spaces (ASCII 32) or tabs (ASCII 9).

5. **Mark the End of the Last Word**:
   - `end = i + 1;` sets `end` to the position just after the last non-space/tab character.

6. **Find the Start of the Last Word**:
   - The third `while` loop (`while(i >= 0 && s[i] != 32 && s[i] != 9) i--;`) moves `i` backward to find the beginning of the last word (i.e., it stops when it encounters a space or tab or the beginning of the string).

7. **Mark the Start of the Last Word**:
   - `start = i + 1;` sets `start` to the position just after the last space/tab before the last word.

8. **Print the Last Word**:
   - The fourth `while` loop (`while(start < end) write(1, &s[start++], 1);`) prints the characters from `start` to `end`.

9. **Print Newline**:
   - `write(1, "\n", 1);` prints a newline character.

```c
#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        char *s = argv[1];
        int i = 0;
        int start = 0;
        int end = 0;

        // Find the length of the string
        while (s[i])
            i++;
        i--;
        
        // Ignore trailing spaces and tabs
        while (s[i] == 32 || s[i] == 9)
            i--;
        end = i + 1;

        // Find the start of the last word
        while (i >= 0 && s[i] != 32 && s[i] != 9)
            i--;
        start = i + 1;

        // Print the last word
        while (start < end)
            write(1, &s[start++], 1);
    }
    write(1, "\n", 1);
    return (0);
}
```

### Explanation of Key Parts:

- **Checking Argument Count**:
  - `if (argc == 2)` ensures the program only runs if there is exactly one argument provided.

- **Finding the Length of the String**:
  - The loop `while(s[i]) i++;` moves `i` to the end of the string (null terminator).

- **Ignoring Trailing Spaces/Tabs**:
  - The loop `while(s[i] == 32 || s[i] == 9) i--;` skips any trailing spaces or tabs by decrementing `i`.

- **Marking End and Start of the Last Word**:
  - `end = i + 1;` sets the end position just after the last character of the last word.
  - `while(i >= 0 && s[i] != 32 && s[i] != 9) i--;` moves `i` to just before the last word.
  - `start = i + 1;` sets the start position to the first character of the last word.

- **Printing the Last Word**:
  - The loop `while(start < end) write(1, &s[start++], 1);` prints each character from `start` to `end`.

- **Printing Newline**:
  - `write(1, "\n", 1);` ensures the output ends with a newline.
