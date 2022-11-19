#include <stdio.h>

typedef unsigned char uint8_t;
typedef unsigned long int uint32_t;

int main()
{
    uint8_t u8RetVal = 0;
    uint32_t u32year = 0;

    while (1)
    {
        scanf_s("%d", &u32year);

        if (u32year % 4 == 0)
        {
            if (u32year % 100 != 0)
            {
                u8RetVal = 1;
            }
            else if (u32year > 399 && u32year % 400 == 0)
            {
                u8RetVal = 1;
            }
            else
            {
                u8RetVal = 0;
            }
        }
        else
        {
            u8RetVal = 0;
        }

        printf("%d \n", u8RetVal);
    }
}