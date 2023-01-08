#include <iostream>
#include <vector>

using namespace std;

int ArrHashMap[1000000001] = { 0 };

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {


       
    }
};

// Brute Force
// Time Compexity : O(N^2)
// Space Complexity : O(1);
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> RetVal;
        for (int i = 0; i != nums.size(); ++i)
        {
            for (int j = i + 1; j != nums.size(); ++j)
            {
                if ((nums[i] + nums[j]) == target)
                {
                    RetVal.push_back(i);
                    RetVal.push_back(j);

                    return RetVal;
                }
            }
        }

        RetVal.push_back(-1);
        RetVal.push_back(-1);

        return RetVal;
    }
};