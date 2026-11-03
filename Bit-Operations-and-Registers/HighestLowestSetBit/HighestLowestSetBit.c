#include <stdio.h>
#include <stdint.h>

// Zero-based position of the most significant bit in an int32_t.
#define NO_OF_BITS          ((sizeof(int32_t) * 8) - 1)

// Masks used to scan from the most- and least-significant ends.
#define HIGHEST_BIT         0x80000000
#define LOWEST_BIT          0x00000001

// Both scans accept the value and write their scan offset through this
// output pointer.
void highestBitSet(int32_t data, uint8_t *ptr);
void lowestBitSet(int32_t data, uint8_t *ptr);

// This declares an array of two pointers to functions that take (int32_t, uint8_t *)
// and return void. The parentheses group the pointer declarator so the parameter
// list describes the function type being pointed to.
void (*FindHighLowBitSet[2])(int32_t data, uint8_t *ptr) =
{
    highestBitSet, // Index 0 scans from the most-significant bit.
    lowestBitSet   // Index 1 scans from the least-significant bit.
};

int main()
{
    int32_t data;
    uint8_t findLow, findHigh;
    printf("Enter a random value and I will identify the highest and the lowest set bit in that number\n");
    scanf("%d", &data);

    // Calling an array entry invokes its function and writes the scan offset
    // through the output pointer.
    FindHighLowBitSet[0](data, &findHigh);
    FindHighLowBitSet[1](data, &findLow);
    printf("The highest set bit position is %zu\n", (NO_OF_BITS - findHigh));
    printf("The Lowest set bit position is %d\n", findLow);

    return 0;
}

void highestBitSet(int32_t data, uint8_t *ptr)
{
    uint8_t i = 0;

    // Shift the mask right until it reaches the first set bit.
    while(!((data) & (HIGHEST_BIT >> i)))
    {
        i++;
    }
    *ptr = i;
}

void lowestBitSet(int32_t data, uint8_t *ptr)
{
    uint8_t i = 0;

    // Shift the mask left until it reaches the first set bit.
    while(!((data) & (LOWEST_BIT << i)))
    {
        i++;
    }
    *ptr = i;
}