#include <iostream>


// Use Bitwise operator

class Solution {
public:
    bool isPowerOfTwo(int n) {

        if (n < 0)
        {
            return false;
        }
        else
        {
            return n && !(n & n - 1);
        }

    }
};

int main(void)
{

	Solution solution;
	int n = -16;
	return solution.isPowerOfTwo(n);
	
}