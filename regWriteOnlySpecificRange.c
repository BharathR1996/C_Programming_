#include<stdio.h>
#include<stdint.h>

/*
 * This program modifies a selected bit range inside a 32-bit register.
 *
 * The user enters:
 *   - the current register value
 *   - the number of bits to change
 *   - the starting bit position
 *   - the desired bit pattern for that range (LSB to MSB)
 *
 * The code checks whether the chosen field stays within the register size,
 * updates only those bits, and prints the modified register value if the
 * operation is successful.
 */

#define SET         1
#define CLEAR       0

/*
 * Status codes returned by register modification operations.
 */
typedef enum returnStatus
{
    NOT_VALID = 0,
    SUCCESS,
    FAILURE,

}Status;

volatile uint32_t reg;
uint32_t REG_SIZE;

/*
 * Updates a specific bit field inside a register.
 * width   : number of bits to modify
 * bitPos  : starting bit position of the field (LSB = 0)
 * RegAddr : pointer to the register being modified
 * pBinModifyValue : bit pattern to write, ordered from bitPos to bitPos + width - 1
 */
Status modifyRegister(uint8_t width,uint8_t bitPos,volatile uint32_t *RegAddr, uint8_t *pBinModifyValue)
{
    uint8_t retStatus = NOT_VALID;
    uint8_t *tempAddr;
    tempAddr = pBinModifyValue;
    uint8_t bitVerify = 0;

    /*
     * Apply each requested bit value to the selected register field.
     * A 1 writes a SET bit and a 0 writes a CLEAR bit.
     */
    for(int i = bitPos;i<bitPos + width;i++)
    {
        if(*pBinModifyValue == SET)
        {
            *RegAddr |= *pBinModifyValue << i;
        }
        else
        {
            *RegAddr &= ~(*pBinModifyValue << i);
        }
        // Enable when debugging: printf("register values %x %x\n", *RegAddr, *pBinModifyValue);
        pBinModifyValue++;
    }
    pBinModifyValue = tempAddr;

    /*
     * Verify whether the updated bits match the requested pattern.
     * The loop checks each bit in the selected range and reports success only
     * when the entire field matches the desired value.
     */
    int j = 0;
    for(int i=bitPos;i<=bitPos + width;i++)
    {   
        bitVerify = (*RegAddr >> i) & 0x01;
        printf("Value bitVerify = %u, Value pBinModifyValue[%d] = %d\n", bitVerify, j, pBinModifyValue[j]);
        if(bitVerify == pBinModifyValue[j])
        {
            j++;
        }
        else
        {
            if(i == (bitPos + width))
            {
                printf("Value is modified\n");
                retStatus = SUCCESS;
            }
            else
            {
                break;
            }
        }
    }
    return retStatus;
}

int main()
{
    uint8_t width, bitPos, loopVar; 
    uint8_t binModifyValue[32];

    uint8_t status;

    REG_SIZE = sizeof(reg) * 8;

    /*
     * Read the initial register value and the targeted bit-field settings
     * from the user before modifying the hardware register.
     */
    printf("Enter the register value\n");
    scanf("%x", &reg);

    printf("Register Value is %x\n", reg);
    
    printf("Enter the width of the register to be modified\n");
    scanf("%hhu",&width);

    printf("Enter the starting bitpos from where the width of the register has to be modified\n");
    scanf("%hhu",&bitPos);

    printf("Enter the value which has to be modified within that width starting from bitPos (LSB towards MSB) in binary\n");
    for(loopVar=0;loopVar <width;loopVar++)
    {
        printf("Enter bit value\n");
        scanf(" %hhu", &binModifyValue[loopVar]);
    }

    /*
     * Prevent writes that would move beyond the configured register size.
     */
    if(width < (REG_SIZE - bitPos))
    {
        status = modifyRegister(width, bitPos, &reg, binModifyValue);
    }
    else
    {
        printf("The entered width of bits cannot be modified as from the bitPos you entered, the width of bits will overflow into another register");
    }

    if(status == SUCCESS)
    {
        printf("Modified register value = %x\n", reg);
    }

    return 0;
}
