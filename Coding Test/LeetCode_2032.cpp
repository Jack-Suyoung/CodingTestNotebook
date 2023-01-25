#include <vector>

using namespace std;

class Solution {
public:
    int arrHashMap1[100] = { 0 };
    int arrHashMap2[100] = { 0 };
    int arrHashMap3[100] = { 0 };

    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> res;
        memset(arrHashMap1, 0, sizeof(int) * 100);
        memset(arrHashMap2, 0, sizeof(int) * 100);
        memset(arrHashMap3, 0, sizeof(int) * 100);

        for (int i = 0; i != nums1.size(); ++i)
        {
            arrHashMap1[nums1[i]] = 1;
        }

        for (int i = 0; i != nums2.size(); ++i)
        {
            arrHashMap2[nums2[i]] = 1;
        }

        for (int i = 0; i != nums3.size(); ++i)
        {
            arrHashMap3[nums3[i]] = 1;
        }


        for (int i = 0; i != 100; ++i)
        {
            if ((arrHashMap1[i] + arrHashMap2[i] + arrHashMap3[i]) > 1)
            {
                res.push_back(i);
            }
            else
            {
                // Do Nothing
            }
        }

        return res;
    }
};

int main()
{
    vector<int> nums1 = { 1, 1, 3, 2 };
    vector<int> nums2 = { 2, 3};
    vector<int> nums3 = { 3 };

    class Solution solution;
    vector<int> sol = solution.twoOutOfThree(nums1, nums2, nums3);

    return 0;
}