
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