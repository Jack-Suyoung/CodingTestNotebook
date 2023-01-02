#include <stdlib.h> // to use qsort
#include "CodingTestMathExport.h"

// 2D array qsort 이후
// Greedy Algorithms 컨셉으로 풀려고 시도함
// Time Limit Exceed에 걸려서 Submit 실패
// qsort에서 Time Limit이 걸리나? Greedy Algorithms 에서 Limit 이 걸리나?

int minGroups(int** intervals, int intervalsSize, int* intervalsColsize);

int main()
{
	int** array;
	int arrSize = 8;
	int arrColSize = 2;
	int i = 0;
	int NumOfGroup = 0;

	array = malloc(arrSize * sizeof(int*));

	for (i = 0; i < arrSize; i++)
	{
		array[i] = malloc(arrColSize * sizeof(int));
	}

	array[0][0] = 441459;
	array[0][1] = 446342;
	array[1][0] = 801308;
	array[1][1] = 840640;
	array[2][0] = 871890;
	array[2][1] = 963447;
	array[3][0] = 228525;
	array[3][1] = 336985;
	array[4][0] = 807945;
	array[4][1] = 946787;
	array[5][0] = 479815;
	array[5][1] = 507766;
	array[6][0] = 693292;
	array[6][1] = 944029;
	array[7][0] = 751962;
	array[7][1] = 821744;


	NumOfGroup = minGroups(array, arrSize, &arrColSize);

	return 0;
}

int minGroups(int** intervals, int intervalsSize, int* intervalsColsize)
{
	int i = 0;
	int** RefArr;
	int RefArrSize = intervalsSize;
	int** TmpArr;
	int TmpArrSize = intervalsSize;
	int NumOfGroup = 0;
	int StartIndex = 0;
	int EndIndex = 0;


	// Sort
	qsort(intervals, intervalsSize, sizeof(intervals[0]), compare2Darray2Column);


	// Grouping - greedy algorithms
	RefArr = malloc(RefArrSize * sizeof(int*));
	for (i = 0; i < RefArrSize; i++)
	{
		RefArr[i] = malloc((*intervalsColsize) * sizeof(int));
		RefArr[i][0] = intervals[i][0];
		RefArr[i][1] = intervals[i][1];
	}


	TmpArr = malloc(TmpArrSize * sizeof(int*));
	for (i = 0; i < TmpArrSize; i++)
	{
		TmpArr[i] = malloc((*intervalsColsize) * sizeof(int));
	}



	while (TmpArrSize != 0)
	{
		if (TmpArrSize != 0)
		{
			++NumOfGroup;
		}
		else
		{
			break;
		}

		StartIndex = RefArr[0][0];
		EndIndex = RefArr[0][1];
	
		TmpArrSize = 0;

		for (i = 1; i != RefArrSize; ++i)
		{
			if (RefArr[i][0] > EndIndex)
			{
				EndIndex = RefArr[i][1];
			}
			else
			{
				TmpArr[TmpArrSize][0] = RefArr[i][0];
				TmpArr[TmpArrSize][1] = RefArr[i][1];
				++TmpArrSize;
			}
		}

		for (i = 0; i != TmpArrSize; ++i)
		{
			RefArr[i][0] = TmpArr[i][0];
			RefArr[i][1] = TmpArr[i][1];
		}
		RefArrSize = TmpArrSize;
	}

	return NumOfGroup;
}