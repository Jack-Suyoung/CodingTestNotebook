#include <stdio.h>
#include <stdlib.h>

#include "CodingTestMathExport.h"

// FInde Index at array of value, 
// Binary Search in Iteration Method
int FindValueIndexBinarySearch(int* arr, int NumOfElement, int FindValue)
{
	int LowIdx = 0;
	int HighIdx = NumOfElement - 1;
	int MidIdx = 0;
	int RetVal = -1;

	while (LowIdx <= HighIdx)
	{
		MidIdx = (LowIdx + HighIdx) / 2;

		if (FindValue == arr[MidIdx])
		{
			RetVal = MidIdx;
			break;
		}
		else if (FindValue < arr[MidIdx])
		{
			HighIdx = MidIdx - 1;
		}
		else
		{
			LowIdx = MidIdx + 1;
		}
	}

	return RetVal;
}



int compare2Darray2Column(const void* pa, const void* pb) 
{
    const int* a = *(const int**)pa;
    const int* b = *(const int**)pb;

	if (a[0] == b[0])
	{
		return a[1] - b[1];
	}
	else
	{
		return a[0] - b[0];
	}
}
