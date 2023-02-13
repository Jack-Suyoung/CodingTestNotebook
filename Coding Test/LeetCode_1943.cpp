#include <vector>
#include <map>

using namespace std;

int garsHashTable[100000];

class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<int, vector<int>> ColorSet;
        vector<vector<long long>> RetVal;
        memset(&garsHashTable, 0, sizeof(int) * 100000);
        int LastIdx = 0;


        for (int i = 0; i != segments.size(); ++i)
        {
            for (int HashTableIdx = segments[i][0]; HashTableIdx != segments[i][1]; ++HashTableIdx)
            {
                garsHashTable[HashTableIdx] += segments[i][2];
                ColorSet[HashTableIdx].push_back(segments[i][2]);
            }

            if (segments[i][1] > LastIdx)
            {
                LastIdx = segments[i][1];
            }
            else
            {
                // Do Nothing
            }
        }

        int PrevVal = garsHashTable[1];
        int StartIdx = 1;
        for (int i = 2; i != LastIdx; ++i)
        {
            if ((garsHashTable[i] != PrevVal) || (ColorSet[i] != ColorSet[i-1]))
            {
                if (i == (LastIdx - 1))
                {
                    RetVal.push_back({ StartIdx, i, PrevVal });
                    RetVal.push_back({ LastIdx, LastIdx, garsHashTable[i] });
                }
                else
                {
                    RetVal.push_back({ StartIdx, i, PrevVal });

                    PrevVal = garsHashTable[i];
                    StartIdx = i;
                }
            }
            else
            {
                if (i == (LastIdx - 1))
                {
                    RetVal.push_back({ StartIdx, LastIdx, garsHashTable[i] });
                }
                else
                {
                    // Do Nothing
                }
            }
        }

        return RetVal;
    }
};

int main() {
    //vector<vector<int>> Src = { {1, 4, 5}, {4, 7, 7}, {1, 7, 9} };
    vector<vector<int>> Src = { {1, 4, 5}, {1, 4, 7}, {4, 7, 1}, {4, 7, 11} };
    Solution solution;

    vector<vector<long long>> RetVal = solution.splitPainting(Src);


    return 0;
}