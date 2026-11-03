#include<stdio.h>
#include<stdint.h>

#define READ_BIT(data, pos)             ((data >> i)&0x01)

int main()
{
    uint16_t num, size, res;
    int i;
    printf("Enter the number\n");
    scanf("%hd", &num);
    size = sizeof(num) * 8;
    
    for(i=size-1;i>=0;i--)
    {
        printf("%d", READ_BIT(num, i));
    }
    printf("\n");
    num = (((num >> 8) & 0xFF) | ((num << 8) & 0xFF00));

    printf("Bytes are swapped!!!\n");

    for(i=size-1;i>=0;i--)
    {
        printf("%d", READ_BIT(num, i));
    }

    return 0;
}