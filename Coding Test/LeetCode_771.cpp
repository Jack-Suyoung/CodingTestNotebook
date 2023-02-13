#include <string>


// Use Hash Table to decrese time complexity to under log(n^2)

using namespace std;

int gstHashTable[60] = { 0 };

class Solution {
public:
	int numJewelsInStones(string jewels, string stones) {
		memset(&gstHashTable, 0, sizeof(int) * 60);
		int RetVal = 0;

		for (int i = 0; i != stones.size(); ++i)
		{
			gstHashTable[stones[i] - 65]++;
		}

		for (int i = 0; i != jewels.size(); ++i)
		{
			RetVal += gstHashTable[jewels[i] - 65];
		}

		return RetVal;
	}
};