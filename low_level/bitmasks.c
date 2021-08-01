// Function setBit()
// Sets the bit at position p in the mask m.
// Uses CHAR_BIT, defined in limits.h, for the number of bits in a byte. 
// Return value: The new mask with the bit set, or the original mask
// if p is not a valid bit position.
#include <limits.h>
#include <stdio.h>
unsigned int set_bit( unsigned int mask, unsigned int p )
{
    if ( p >= CHAR_BIT * sizeof(int) ) 
        return mask;
    else 
        return mask | (1 << p);
}

unsigned int invert(unsigned int input)
{
    return input ^ 0xF;
}

unsigned int shift_left(unsigned int input, unsigned int shift_amount)
{
    return input << shift_amount;
}

/* for 8-bit integer */
unsigned int int2binary(unsigned int input)
{
    
}

int main()
{
    int x = 123;
    int new_x = shift_left(x, 2);
    printf("Old x is %d\n", x);
    printf("New x is %d\n", new_x);
}