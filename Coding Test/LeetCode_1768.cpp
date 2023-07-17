#include <string>
#include <stdlib.h>

using namespace  std;

// unsigned iterator 변수를 사용할때는 -- 처리할때 조심해야 함. 음수를 가질 수 없어서 > 0 조건을 넣으면 안됨
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        unsigned int minLength = 0;
        unsigned int Lengthword1 = word1.length();
        unsigned int Lengthword2 = word2.length();
        string MergedString;
        string SortedMergedString;

        if (Lengthword1 > Lengthword2)
        {
            for (unsigned int i = 0; i < (Lengthword1 - Lengthword2); ++i)
            {
                MergedString.push_back(word1[word1.length() - 1]);

                word1.pop_back();
            }

            minLength = Lengthword2;
        }
        else if (Lengthword1 < Lengthword2)
        {
            for (unsigned int i = 0; i < (Lengthword2 - Lengthword1); ++i)
            {
                MergedString.push_back(word2[word2.length() - 1]);

                word2.pop_back();
            }

            minLength = Lengthword1;
        }
        else
        {
            minLength = Lengthword1;
        }

        for (unsigned int i = 0; i < minLength; ++i)
        {
            MergedString.push_back(word2[word2.length() - 1]);
            MergedString.push_back(word1[word1.length() - 1]);

            word2.pop_back();
            word1.pop_back();
        }

        for (unsigned int i = 0; i < MergedString.length(); ++i)
        {
            SortedMergedString.push_back(MergedString[MergedString.length() - 1 - i]);
        }

        for (unsigned int i = 0; i < SortedMergedString.length(); ++i)
        {
            printf("%c ", SortedMergedString[i]);
        }
        printf("\n ");

        return SortedMergedString;
    }
};

int main()
{
    string arrWord1[3] = { "abc", "ab", "abcd" };
    string arrWord2[3] = { "pqr", "pqrs", "pq" };
    int NumOfTestCase = 3;

    Solution solution;

    for (int i = 0; i != NumOfTestCase; ++i)
    {
        solution.mergeAlternately(arrWord1[i], arrWord2[i]);
    }

	return 0;
}

