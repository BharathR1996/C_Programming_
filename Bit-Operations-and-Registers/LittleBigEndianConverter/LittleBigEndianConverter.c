#include <stdio.h>
#include <stdint.h>

// Define the two endian formats used in the program.
enum e_Endian_Type {
    LITTLE_ENDIAN,
    BIG_ENDIAN
};

// Labels shown to the user for each endian format.
char *lEndian = "LITTLE ENDIAN";
char *bEndian = "BIG ENDIAN";

int main()
{
    // Pointers and variables used to inspect and convert the raw byte order.
    char *pInt = NULL;
    uint8_t endianType;
    uint32_t data;
    uint32_t temp = 0;

    // Read the user input as a hexadecimal value.
    printf("Enter the data in hex format\n");
    scanf("%x", &data);

    // Print each byte of the integer and its memory address.
    pInt = (char *)&data;
    while (temp < sizeof(uint32_t))
    {
        printf("%x ", *(char *)pInt);
        printf("Address of data %p\n", pInt);
        pInt = pInt + 1;
        temp++;
    }
    temp = 0;
    *pInt = NULL;

    // Ask the user which byte order they want to use for storage.
    printf("Enter the value to be stored in which format:\n"
            "0 -> LITTLE_ENDIAN \n" 
            "1 -> BIG_ENDIAN\n");
    scanf("%hhd", &endianType);

    // Display the original value and the chosen storage format.
    printf("The data entered by the user is: %x and to will be stored in %s format\n", data, (endianType ? (bEndian) : (lEndian)));

    // Convert the value based on the selected endian type.
    switch (endianType)
    {
        int i;
        case LITTLE_ENDIAN:
            // Rearrange bytes from little-endian order to the desired memory layout.
            temp |= ((data & 0x000000FF) << 24);
            temp |= ((data & 0x0000FF00) << 8);
            temp |= ((data & 0x00FF0000) >> 8);
            temp |= ((data & 0xFF000000) >> 24);
            data = temp;
            printf("The data stored in memory is %x\n", data);
            break;

        case BIG_ENDIAN:
            // Keep the bytes in big-endian order as defined by the selected format.
            temp |= (data & 0xFF000000);
            temp |= (data & 0x00FF0000);
            temp |= (data & 0x0000FF00);
            temp |= (data & 0x000000FF);
            data = temp;
            printf("The data stored in memory is %x\n", data);
            break;
    }

    return 0;
}