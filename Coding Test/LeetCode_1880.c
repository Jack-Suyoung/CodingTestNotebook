#include <math.h>

int GetNumericValue(char* ArrWord);

bool isSumEqual(char* firstWord, char* secondWord, char* targetWord) {
	bool RetVal = true;

	int fisrtWordNumericValue = GetNumericValue(firstWord);
	int secondWordNumericValue = GetNumericValue(secondWord);
	int targetWordNumericValue = GetNumericValue(targetWord);

	if (targetWordNumericValue == (fisrtWordNumericValue + secondWordNumericValue))
	{
		RetVal = true;
	}
	else
	{
		RetVal = false;
	}

	return RetVal;
}

int GetNumericValue(char* ArrWord)
{
	int ArrIntWord[8] = { 0 };
	int LengthOfWord = 0;
	int Num = 0;
	int Unit = 1;


	while (ArrWord[LengthOfWord] != '\0')
	{
		ArrIntWord[LengthOfWord] = ArrWord[LengthOfWord] - 97;
		++LengthOfWord;
	}

	Num = ArrIntWord[LengthOfWord - 1];

	for (int i = (LengthOfWord - 2); i > -1; --i)
	{

		Num += ArrIntWord[i] * (int)pow(10, Unit);
		++Unit;
	}

	return Num;
}