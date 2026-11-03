#include<stdio.h>
#include<stdint.h>

#define SET_BIT(register, pos)                  (register |= (1 << pos))
#define CLEAR_BIT(register, pos)                (register &=~ (1 << pos))
#define TOGGLE_BIT(register, pos)               (register ^= (1 << pos))
#define READ_BIT(register, pos, result)         (result = (register >> pos) & 0x01)

volatile uint32_t reg;

int main()
{
    uint8_t result;
    reg = 0x40001000;

    SET_BIT(reg, 0);
    printf("%x\n", reg);

    READ_BIT(reg, 30, result);
    printf("%d\n", result);

    CLEAR_BIT(reg, 0);
    SET_BIT(reg, 2);
    printf("%x\n", reg);

    return 0;
}
