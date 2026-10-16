#include<stdio.h>
#include<stdint.h>

int main()
{
    int num, numSize, bit, i, count = 0;
    printf("Enter the number\n");
    scanf("%d",&num);
    numSize = (sizeof(num) * 8) - 1;

    for(i =0; i<=numSize;i++)
    {
        bit = (num >> i) & 0x01;
        if(bit == 1)
        {
            count++;
        }
    }
    printf("No of set bits in the number is = %d\n", count);
    return 0;
}