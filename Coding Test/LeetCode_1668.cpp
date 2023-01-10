#include <stdio.h>

int maxRepeating(char* sequence, char* word);

int main()
{
    char sequence[] = "aaabaaaabaaabaaaabaaaabaaaabaaaaba";
    char word[] = "aaaba";

    int maxRepeate = maxRepeating(sequence, word);

    return 0;
}

int maxRepeating(char* sequence, char* word) {
    int MaxRepeat = 0;
    int maxRepeating = 0;
    int lengthOfsequence = 0;
    while (sequence[lengthOfsequence] != '\0')
    {
        ++lengthOfsequence;
    }


    int lengthOfword = 0;
    while (word[lengthOfword] != '\0')
    {
        ++lengthOfword;
    }

    int Substring = 0;
    for (int i = 0; i < (lengthOfsequence - lengthOfword) + 1; ++i)
    {
        Substring = 1;
        for (int j = 0; j != lengthOfword; ++j)
        {
            if (sequence[i + j] == word[j])
            {
                // Do Nothing
            }
            else
            {
                Substring = 0;
                break;
            }
        }

        if (Substring == 1)
        {
            i += (lengthOfword - 1);
            ++maxRepeating;
        }
        else
        {
            if (maxRepeating > MaxRepeat)
            {
                MaxRepeat = maxRepeating;
                maxRepeating = 0;
           }
            else
            {
                // Do Nothing
            }
        }

        
    }

    if (maxRepeating > MaxRepeat)
    {
        MaxRepeat = maxRepeating;
        maxRepeating = 0;
    }
    else
    {
        // Do Nothing
    }

    return MaxRepeat;
}