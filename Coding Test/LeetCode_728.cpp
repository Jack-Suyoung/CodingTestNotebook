// Leet Code 728. Self Dividing Numbers
// Level : Easy
#include <vector>

using namespace std;

class Solution {
public:
    bool IdSelfDividingNumber(int n)
    {
        int k = 10;
        int a = n;
        for (int i = 1; i != 5; ++i)
        {
            int digit = a % k;

            if (digit == 0)
            {
                return false;
            }
            else if (n % digit != 0)
            {
                return false;
            }
            else
            {
                // Do Nothing
            }

            a = a / k;
            if (a == 0)
            {
                return true;
            }

        }

        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int i = left; i < (right + 1); ++i)
        {
            if (IdSelfDividingNumber(i) == true)
            {
                res.push_back(i);
            }
            else
            {
                // DO Nothing
            }
        }

        return res;
    }
};