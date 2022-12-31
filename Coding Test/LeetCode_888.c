#include <stdio.h>
#include <stdlib.h>


// Solution 1
// Get Total Sum of alice and bob candis number
// Calculate how many candies should be exchanged, to get equal num each other.
// But this method Runtime too much, only Beats 7.14% in Leet Code.

int* fairCandySwap(int* aliceSizes, int aliceSizesSize, int* bobSizes, int bobSizesSize, int* returnSize);


int main()
{
	int alice[] = {1, 1};
	int aliceSize = 2;
	int bob[] = {2, 2};
	int bobSize = 2;
	int returnSize = 0;
	int* pArr = NULL;


	pArr = fairCandySwap(
		alice,
		aliceSize,
		bob,
		bobSize,
		&returnSize);


	return 0;
}

int* fairCandySwap(
	int* aliceSizes,
	int aliceSizesSize,
	int* bobSizes,
	int bobSizesSize,
	int* returnSize)
{
	int i = 0;
	int aliceCandyNum = 0;
	int bobCandyNum = 0;
	int DivideCandyNum = 0;
	int* ExchangeArr = (int*)malloc(sizeof(int) * 2);

	for (i = 0; i != aliceSizesSize; ++i)
	{
		aliceCandyNum += aliceSizes[i];
	}

	for (i = 0; i != bobSizesSize; ++i)
	{
		bobCandyNum += bobSizes[i];
	}

	DivideCandyNum = (aliceCandyNum + bobCandyNum) / 2;

	int aliceNeedCandyNum = DivideCandyNum - aliceCandyNum;

	int FindAnswer = 0;

	if (aliceNeedCandyNum == 0)
	{
		for (int j = 0; j != aliceSizesSize; ++j)
		{
			for (int k = 0; k != bobSizesSize; ++k)
			{
				if (aliceSizes[j] == bobSizes[k])
				{
					ExchangeArr[0] = aliceSizes[j];
					ExchangeArr[1] = bobSizes[k];

					FindAnswer = 1;
					break;
				}
				else
				{
					// Do Nothing
				}
			}

			if (FindAnswer == 1)
			{
				break;
			}
			else
			{
				// Do Nothing
			}
		}
	}
	else
	{
		for (int j = 0; j != aliceSizesSize; ++j)
		{
			for (int k = 0; k != bobSizesSize; ++k)
			{
				if ((aliceSizes[j] + aliceNeedCandyNum) == bobSizes[k])
				{
					ExchangeArr[0] = aliceSizes[j];
					ExchangeArr[1] = bobSizes[k];

					FindAnswer = 1;
					break;
				}
				else
				{
					// Do Nothing
				}
			}

			if (FindAnswer == 1)
			{
				break;
			}
			else
			{
				// Do Nothing
			}
		}
	}

	*returnSize = 2;

	return ExchangeArr;
}