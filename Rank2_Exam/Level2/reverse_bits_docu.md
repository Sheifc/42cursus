# Reverse bits

A byte has 8 bits. Reversing the bits means that the bit in position 0 is swapped with the bit in position 7, the bit in position 1 with the bit in position 6, and so on. In other words, the order of the bits is completely reversed.

**Initialize a Result**: Start with a new byte called `result`, initialized to 0. This byte will store the final result after reversing the bits.

**Iterate over Each Bit**: You will need a loop that goes through each bit of the original byte. This can be done 8 times, once for each bit.

**Extract Each Bit**: Inside the loop, you need to extract the bit at the current position. This is done by performing the AND operation between the original byte and a mask that has a 1 only at the position of the bit you want to extract. For example, if you want to extract the bit at position 0, use the mask 1 (which is 00000001 in binary). If it is position 1, use the mask 2 (00000010), and so on. This is usually done by shifting the 1 to the correct position using the left shift operator (<<).

**Position the Bit in its New Location**: After extracting the bit, you need to place it in its new position in the `result` byte. This is done using the left shift operator (<<). The number of positions you need to shift varies depending on the bit's position. For example, the bit in position 0 (the least significant) is shifted 7 positions to the left, and the bit in position 1 is shifted 6 positions, and so on.

**Combine the Bit with the Result**: Use the OR operator (|) to combine this newly positioned bit with the `result`. This "adds" the bit in its new position.

**Repeat for All Bits**: Repeat this process for each of the 8 bits.

**Final Result**: After processing all the bits, `result` will contain the reversed version of the original byte.

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

unsigned char reverse_bits(unsigned char octet)
{
    unsigned char reverted = 0;
    unsigned char bit;
    int i = 0; 
    while (i < 8)
    {   
        // AND: 0+0=0    1+0=0    1+1=1 // binary: octet = 01000001 1 = 00000001
        bit = (octet >> i) & 1; // Shift all bits of octet i positions to the right
        // 1 in binary: 00000001 is used as a mask to check the last bit
        // shift the bits of octet i positions to the right to check from right to left with the mask
        reverted = reverted | (bit << (7 - i)); // result |= (bit << (7 - i)); 
        // OR: 0+0=0    1+0=1    1+1=1 // 00000000 OR 
        // Shift the bit to its new position and add it to the result
        i++;
    }
    return (reverted);
}

int main(void)
{
    unsigned char reverted = 0;
    unsigned char octet = 65; // 01000001 in binary
    reverted = reverse_bits(octet);
    print_bit(reverted);
    return 0;
}
```

# Explanation and Example:

**`bit = (octet >> i) & 1;`**

Let's use a concrete example to explain the line `bit = (octet >> i) & 1;`. Suppose `octet` is `01000001` in binary (which is 65 in decimal) and let's calculate the value of `bit` for different values of `i`.

1. **When `i = 0`**:
   - `octet` is `01000001`.
   - `octet >> i` is `octet >> 0`, which means we do not shift `octet` at all (shifting 0 positions is the same as not shifting). So, `octet >> 0` is still `01000001`.
   - Now apply `& 1`, which is `01000001 & 00000001`. Only the least significant bit (the rightmost bit) is compared with 1. In this case, that bit is 1.
   - The result is `00000001`, which means `bit` will be `1`.

2. **When `i = 1`**:
   - `octet` is `01000001`.
   - `octet >> i` is `octet >> 1`, which means we shift all the bits of `octet` one position to the right. The result is `00100000`.
   - Now apply `& 1`, which is `00100000 & 00000001`. Again, only the least significant bit is compared with 1. In this case, that bit is 0.
   - The result is `00000000`, which means `bit` will be `0`.

This process repeats for each value of `i` from 0 to 7. The final result is that `bit` will get the value of each bit in `octet`, one by one, starting from the least significant bit (the rightmost) to the most significant bit (the leftmost).

**`result |= (bit << (7 - i));`**

Let's explain the line `result |= (bit << (7 - i));` with a concrete example, continuing with `octet` as `01000001` and using the values of `bit` obtained for `i = 0` and `i = 1`.

Remember that `result` is where we are building our reversed byte, and it starts at `00000000`.

1. **When `i = 0` and `bit = 1`**:
   - The value of `bit` we obtained for `i = 0` was `1`.
   - `bit << (7 - i)` is `1 << (7 - 0)`, which is `1 << 7`. This means we shift the bit `1` seven positions to the left, resulting in `10000000`.
   - Now, we perform `result |= 10000000`. Since `result` is `00000000`, the result of this operation will be `10000000`. Thus, we have correctly placed the least significant bit of `octet` in the most significant position of `result`.

2. **When `i = 1` and `bit = 0`**:
   - The value of `bit` we obtained for `i = 1` was `0`.
   - `bit << (7 - i)` is `0 << (7 - 1)`, which is `0 << 6`. Any number shifted to the left by `0` is still `0`, so the result remains `00000000`.
   - We perform `result |= 00000000`. Since `result` is currently `10000000`, this operation does not change `result`. It remains `10000000`.

This process repeats for each value of `i` from 0 to 7. Each bit extracted from `octet` is shifted to its new position in `result`. If the bit is `1`, it is added to `result` in the corresponding position. If it is `0`, it does not change the current state of `result` at that specific position.

At the end of the loop, `result` will contain the reversed version of `octet`, where the least significant bit of `octet` becomes the most significant bit of `result`, and so on.

**`|=` in C**

The operator `|=` is a compound assignment operator that combines the bitwise OR operator (`|`) with assignment (`=`). Essentially, `x |= y` is a shorthand way of writing `x = x | y`. Here's how this works:

1. **Bitwise OR Operator (`|`)**:
   - This operator performs a bitwise OR operation between two numbers. In a bitwise OR operation, if any of the corresponding bits of the two operands is 1, the resulting bit is 1. If both are 0, the result is 0.
   - For example, `1010 | 0101` would result in `1111`.

2. **Combining OR with Assignment (`|=`)**:
   - The `|=` operator takes the result of the bitwise OR operation and assigns it to the left operand.
   - For example, if you have `x = 1010` and you execute `x |= 0101`, first the OR operation is performed, which in this case results in `1111`, and then this result is assigned back to `x`. Thus, `x` now is `1111`.

In the context of your `reverse_bits` function, `result |= (bit << (7 - i));` means that you are taking the bit you have extracted and shifted to its new position, performing a bitwise OR with the current value of `result`, and then storing the result back in `result`. This effectively "places" the bit in its new position in `result` without altering the other bits that you have already processed in previous iterations of the loop.
