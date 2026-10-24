#include<stdio.h>
#include<stdint.h>

#define SET_BIT(data, pos)             (data |= 1 << pos)
#define CLEAR_BIT(data, pos)           (data &= ~ (1 << pos))
#define READ_BIT(data, pos)             ((data >> i)&0x01)

int main()
{
    uint32_t num, value, res;
    uint8_t size;
    int i;
    printf("Enter the number\n");
    scanf("%d", &num);
    size = sizeof(num) * 8;

    for(i=size-1;i>=0;i--)
    {
        printf("%d", READ_BIT(num, i));
    }
    
    for(i=size-1;i>=0;i--)
    {
        value = (READ_BIT(num, i));
        if(value == 1)
        {
            CLEAR_BIT(res, i);
        }
        else
        {
            SET_BIT(res, i);
        }
    }
    
    printf("\n");
    for(i=size-1;i>=0;i--)
    {
        printf("%d", READ_BIT(res, i));
    }

    return 0;
}