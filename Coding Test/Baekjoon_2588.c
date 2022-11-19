#include <stdio.h>

typedef unsigned long int uint32_t;

int main()
{
	uint32_t u32FirstVal = 0, u32SecondVal = 0;

	while (1)
	{
		scanf_s("%d", &u32FirstVal);
		scanf_s("%d", &u32SecondVal);

		uint32_t u32a = 0, u32b = 0, u32c = 0;

		u32a = u32SecondVal % 10;
		u32b = (u32SecondVal / 10) % 10;
		u32c = u32SecondVal / 100;


		uint32_t u32d = 0, u32e = 0, u32f = 0;

		u32d = u32FirstVal * u32a;
		u32e = u32FirstVal * u32b;
		u32f = u32FirstVal * u32c;

		printf_s("%d \n", u32d);
		printf_s("%d \n", u32e);
		printf_s("%d \n", u32f);

		uint32_t u32RetVal = 0;

		u32RetVal = (u32f * 100) + (u32e * 10) + u32d;

		printf_s("%d \n", u32RetVal);
	}
}