#include <stdio.h>
#include <stdint.h>

//  32bit float value
//  [1][8][23] bits according to IEEE
union IEEE_754_float
{
    uint32_t bitfield;
    float value;
} IEEE_754_float;

int main()
{
    union IEEE_754_float test;
    test.bitfield = 0;

    // 1 in sign field
    test.bitfield = 0b10000000000000000000000000000000;
    test.bitfield = 0x80000000;

    // 128 in exponent field (bits 2 to 9)
    // clear the exponent field (bits 2 to 9)
    test.bitfield = test.bitfield & ~0b01111111100000000000000000000000;
    test.bitfield = test.bitfield & ~0x7F800000;
    // shift it in place (skip the mantissa or the first 23 bits)
    test.bitfield = test.bitfield | 128 << 23;

    // 0 in mantissa field (bits 10 to 32)
    // clear the mantissa field (bits 10 to 32)
    test.bitfield = test.bitfield & ~0b00000000011111111111111111111111;
    test.bitfield = test.bitfield & ~0x7FFFFF;
    // shift it in place (mantissa in the last 23 bits, so no shifting required)
    test.bitfield = test.bitfield | 0 << 0;

    printf("As float: %f\n", test.value);
    return 0;
}