#include <stdbool.h>

bool digitCount(char* pnum);

int main()
{
	char string[] = "030";
	bool RetVal;

	RetVal = digitCount(string);

	return 0;
}

bool digitCount(char* pnum)
{
	bool bRetVal = true;
	const int ASCIINumberInit = 48;
	int i = 0;
	int NumOfChar = 0;
	int arrHashTable[10] = { 0 };

	while (pnum[NumOfChar] != '\0')
	{
		arrHashTable[pnum[NumOfChar] - ASCIINumberInit] += 1;
		++NumOfChar;
	}

	for (i = 0; i != NumOfChar; ++i)
	{
		if (arrHashTable[i] != (pnum[i] - ASCIINumberInit))
		{
			bRetVal = false;
			break;
		}
		else
		{
			// Do Nothing
		}
	}

	return bRetVal;
}