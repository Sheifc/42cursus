# Strategy to print the byte in binary:

1. Start with the most significant bit (the leftmost bit) and move towards the least significant bit (the rightmost bit).
2. To access each bit, you can use a mask and the AND operation.
3. A mask is a byte where all bits are 0, except one which is 1. 
   - For example, for the most significant bit, the mask would be 10000000 in binary or 128 in decimal.

# Step-by-step process:

1. Start with a mask for the most significant bit (e.g., 128 or 10000000 in binary).
2. Apply the AND operation between the byte and the mask. If the result is different from 0, then the bit in that position is 1; otherwise, it is 0.
3. Print '1' or '0' according to the result.
4. Shift the mask one bit to the right (using the right shift >>) and repeat the process for the next bit.
5. Continue this process until you have checked all the bits (8 times in total).

The difference between >> 1 and i >>= 1 is how each operator is used in the context of an expression or assignment in C.

>> 1:

This is the right shift operator. When you use >> 1, you are shifting the bits of a number one position to the right.
For example, if you have a >> 1, it means you take the value of a, shift its bits one position to the right, and then use or evaluate this shifted value.
However, the original value of a does not change after this operation.

```c
void print_bits(unsigned char octet)
{
    int i = 128; // Initialize i with 128, which is 10000000 in binary, and will be used to compare our number

    while (i)
    {
        if ((octet & i) != 0) // AND: 0+0=0    1+0=0    1+1=1
            write(1, "1", 1); // If the result is different from 0, write 1
        else
            write(1, "0", 1); // If the result is 0, write 0
        i = i >> 1; // Shift the mask one bit to the right: i >>= 1;
    }
}

int main()
{
    print_bits(2); // This will print 00000010
    return 0;
}
```
