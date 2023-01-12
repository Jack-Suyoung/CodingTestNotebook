#include <iostream>
#include <string>
using namespace std;


class Solution {
public:

    //int subtractProductAndSum(int n) { // use Integer operation
    //    int Arr[6] = { 0 };
    //    int DivideNum = 1;
    //    int i = 0;
    //    int Sum = 0;
    //    int Product = 1;

    //    while (n / DivideNum != 0)
    //    {
    //        Arr[i] = n / DivideNum;
    //        DivideNum = DivideNum * 10;
    //        Product = Product * (Arr[i] % 10);
    //        Sum += Arr[i] % 10;
    //        ++i;
    //    }

    //    return Product - Sum;
    //}

    int subtractProductAndSum(int n) { // use Integer operation
        string string = to_string(n);
        int length = string.length();

        int product = 1;
        int sum = 0;
        int unitInteger = 0;

        for (int i = 0; i != length; ++i)
        {
            unitInteger = stoi(string.substr(i, 1));

            product = product * unitInteger;
            sum += unitInteger;
        }

        return product - sum;
    }
};

int main()
{
    Solution solution;

    int RetVal = solution.subtractProductAndSum(234);

    return = 0;
}