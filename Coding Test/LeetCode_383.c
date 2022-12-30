#include <stdio.h>
#include <stdbool.h>

bool canConstruct(char* ransomNote, char* magazine);

int main()
{
    bool test = true;
    char RansomeNote[] = "ab";
    char Magazine[] = "a";

    test = canConstruct(RansomeNote, Magazine);
    return 0;
}


bool canConstruct(char* ransomNote, char* magazine) {

    int CharNumOfRansomNote = 0;
    int CharNumOfMagazineNote = 0;
    int i = 0, j = 0;
    char CharOfRansomNote;
    int FindChar = 0;
    bool RetVal = true;

    // Get Num of Char ransomNote
    while (ransomNote[CharNumOfRansomNote] != '\0')
    {
        ++CharNumOfRansomNote;
    }

    // Get Num of Char magazine
    while (magazine[CharNumOfMagazineNote] != '\0')
    {
        ++CharNumOfMagazineNote;
    }

    FindChar = 1;

    // Check Ransom Note can made by Magazine Note
    for (i = 0; i < CharNumOfRansomNote; ++i)
    {
        CharOfRansomNote = ransomNote[i];

        if (FindChar == 1)
        {
            FindChar = 0;

            for (j = 0; j < CharNumOfMagazineNote; ++j)
            {
                if (FindChar == 0)
                {
                    if (CharOfRansomNote == magazine[j])
                    {
                        FindChar = 1;
                        magazine[j] = '-';
                    }
                    else
                    {
                        // Do Nothing
                    }
                }
                else
                {
                    // Do Nothing
                }
            }

            if (FindChar == 0)
            {
                RetVal = false;
            }
            else
            {
                // Do Nothing
            }
        }
        else
        {
            RetVal = false;
            break;
        }
    }

    return RetVal;
}