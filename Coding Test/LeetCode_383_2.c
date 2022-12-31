#include <stdio.h>
#include <stdbool.h>

bool canConstruct(char* ransomNote, char* magazine);

int main()
{
    bool test = true;
    char RansomeNote[] = "abc";
    char Magazine[] = "abb";

    test = canConstruct(RansomeNote, Magazine);
    return 0;
}


bool canConstruct(char* ransomNote, char* magazine) {

    int CharNumOfRansomNote = 0;
    int CharNumOfMagazineNote = 0;
    int ArrHashMap[26] = { 0 };
    int ASCIIInitNum = 97;
    bool RetVal = true;


    // Get Num of Char magazine
    while (magazine[CharNumOfMagazineNote] != '\0')
    {
        ++ArrHashMap[magazine[CharNumOfMagazineNote] - ASCIIInitNum];
        ++CharNumOfMagazineNote;
    }

    // Get Num of Char ransomNote
    while (ransomNote[CharNumOfRansomNote] != '\0')
    {
        --ArrHashMap[ransomNote[CharNumOfRansomNote] - ASCIIInitNum];
        
        if (ArrHashMap[ransomNote[CharNumOfRansomNote] - ASCIIInitNum] < 0)
        {
            RetVal = false;
            break;
        }
        else
        {
            // Do Nothing
        }

        ++CharNumOfRansomNote;
    }

    return RetVal;
}