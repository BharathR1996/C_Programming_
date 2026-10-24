#include<stdio.h>
#include<stdint.h>

int main()
{
    uint32_t num;
    uint8_t size, res, numOfOnes;
    printf("Enter the number\n");
    scanf("%d", &num);
    size = sizeof(num) * 8;

    for(int i=1;i<size;i++)
    {
        res = (num >> i) & 0x01;
        if(res == 1)
        {
            numOfOnes++;
        }
        if(numOfOnes > 1)
        {
            printf("Num = %d is not a power of 2\n", num);
            break;
        }
    }
    if(numOfOnes == 1)
    {
        printf("Num = %d is a power of 2\n", num);
    }
    return 0;
}