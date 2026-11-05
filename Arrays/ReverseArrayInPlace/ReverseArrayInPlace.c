#include <stdio.h>
#include <stdint.h>

void ReverseArrayInPlace(int *data, uint8_t elements);

int main()
{
    int data[10] = {1,2,3,4,5,6,7,8,9,10};
    int noOfElements = sizeof(data) / sizeof(int);
    ReverseArrayInPlace(&data[0], noOfElements);
    
    for(int i =0; i<noOfElements;i++)
    {
        printf("%d ", data[i]);
    }
    return 0;
}

void ReverseArrayInPlace(int *data, uint8_t elements)
{
    if (elements < 2)
    {
        return;
    }

    int i, swap;
    int *end = NULL;
    /*
     * elements is a count, so subtract one to point at the last valid element.
     * Using data + elements would point past the array and corrupt the stack.
     */
    end = data + (elements - 1);
    for(i=0;i<elements/2;i++)
    {
        swap = *data;
        *data = *end;
        *end = swap;
        
        data++;
        end--;
        if(data == end)
        {
            break;
        }
    }
}