# Swap bits

The function `swap_bits` takes an octet (an 8-bit number) and swaps the upper 4 bits with the lower 4 bits. Here is a detailed breakdown of each step in the function:

1. **Take an Octet**: Imagine the octet (a byte) as a series of 8 bits, something like 10110010. The 4 leftmost bits are 1011 and the 4 rightmost bits are 0010.

2. **Right Shift (octet >> 4)**:
   - When you perform `octet >> 4`, you move all bits 4 positions to the right.
   - For example, if you have 10110010 and perform `octet >> 4`, you get 00001011. The 4 rightmost bits (0010) have moved to the left, and the 4 leftmost bits (1011) have "fallen off" the number, with the empty spaces filled with zeros.

3. **Left Shift (octet << 4)**:
   - Similarly, `octet << 4` moves all bits 4 positions to the left.
   - Using the same original octet (10110010), performing `octet << 4` gives you 00100000. The 4 leftmost bits (1011) have moved to the right, with the empty spaces filled with zeros.

4. **Combining Both Results with OR (|)**:
   - Then you use the OR operator (|) to combine the results of the two shifts.
   - Combining 00001011 (result of `octet >> 4`) and 00100000 (result of `octet << 4`) gives you 00101011.
   - OR compares each bit of the two numbers: if at least one of the bits in a position is 1, then the resulting bit in that position is also 1. If both are 0, the result is 0.

5. **Result**:
   - The final result is an octet where the 4 bits originally on the right are now on the left, and vice versa.
   - In our example, the original octet 10110010 transforms into 00101011.
   - Essentially, what the function does is take an octet, cut it in half, and then swap those two halves. The use of shifts ensures that each half is moved to its new position, and OR combines these two halves into the final result.

In this particular context, the `& 0xFF` operation is not strictly necessary but is a good practice in some cases, especially when working with bit manipulation. Here’s why:

1. **Ensuring the Result’s Range**:
   - `0xFF` is 255 in decimal and `11111111` in binary. Performing an AND operation (`&`) with `0xFF` ensures that the result does not exceed the range of an `unsigned char` (which is 0 to 255).
   - Each bit in the final result is compared with the corresponding bit in `0xFF`. Since all bits in `0xFF` are 1, the final result does not change (1 AND 1 = 1, 0 AND 1 = 0).

2. **Cleaning Upper Bits in Larger Data Types**:
   - In some contexts, if you were working with data types that occupy more than 8 bits (such as `int` or `unsigned int` in C), you might use `& 0xFF` to ensure that only the lower 8 bits are considered and all upper bits are discarded (set to 0).
   - However, in the case of `unsigned char`, which is guaranteed by the C standard to be 8 bits, this operation is more about clarity or precaution, in case the code changes in the future or the result of the previous bit operation is unexpected for some reason.

3. **Code Clarity and Maintenance**:
   - Although in this particular case, the result of `(octet >> 4) | (octet << 4)` will never exceed 8 bits, using `& 0xFF` can make the code’s purpose clearer to someone reading it, indicating that the intended result should be within the range of an `unsigned char`.
   - It is also a form of self-protection against future changes in the code that might introduce unexpected results.

In summary, while `& 0xFF` does not change the result in this specific context, it is a useful practice in general for bit manipulation, especially when the data type size is not strictly defined or when emphasizing that only the lower 8 bits are being considered.

```c
#include <stdio.h>
#include <unistd.h>

void print_bit(unsigned char octet)
{
    int i = 128; 

    while (i)
    {
        if ((octet & i) != 0) 
            write(1, "1", 1);
        else
            write(1, "0", 1); 
        i = i >> 1; 
    }
}

unsigned char swap_bits(unsigned char octet)
{
    return ((octet >> 4) | (octet << 4)) & 0xFF;
}

int main(void)
{
    unsigned char octet = 0b10110010; // Example byte
    unsigned char swapped = swap_bits(octet);
    print_bit(swapped); // Should print the swapped bits
    return 0;
}
```

In this example, the function `swap_bits` swaps the upper 4 bits with the lower 4 bits of the given octet and returns the result. The `print_bit` function then prints the binary representation of the swapped octet.
