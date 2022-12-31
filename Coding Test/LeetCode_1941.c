#include <stdio.h>
#include <stdbool.h>

// Solutoin
// using Hash Map

#define NumOfLowerCaseEnglishLetter  26
#define ASCII_INIT_NUM_IDX           97


bool areOccurrencesEqual(char* s) {
    long int NumOfChar = 0;
    int RefNum = 0;
    int arr[NumOfLowerCaseEnglishLetter] = { 0 }; // consists of lowercase English letters
    bool RetVal = true;

    while (s[NumOfChar] != '\0')
    {
        ++arr[s[NumOfChar] - NumOfLowerCaseEnglishLetter];
        ++NumOfChar;
    }


    for (long int i = 0; i != NumOfLowerCaseEnglishLetter; ++i)
    {
        if (RefNum == 0 && arr[i] != 0)
        {
            RefNum = arr[i];
        }
        else if (RefNum != 0 && arr[i] != 0)
        {
            if (RefNum != arr[i])
            {
                RetVal = false;
            }
            else
            {
                // Do Nothing
            }
        }
    }

    return RetVal;
}