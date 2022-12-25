#include <stdio.h>
#include <memory.h>


// 포인트
// 탐색 및 스택을 사용할 수 있나?



typedef signed long int int32_t;

void FindCanGoRegion(int32_t s32NumOfRow, int32_t s32NumOfColumn,
	int32_t s32RowIdx, int32_t s32ColumnIdx, int32_t(*pars32Ground)[50]);



int main()
{
	int32_t s32TestCase = 0;
	int32_t ars32NumOfRow[10] = { 0 }, ars32NumOfColumn[10] = { 0 };
	int32_t ars32NumOfPlant[10] = { 0 };
	int32_t ars32NumOfXpos[2500][10] = { 0 }, ars32NumOfYpos[2500][10] = { 0 };
	int32_t ars32Ground[50][50] = { 0 };
	int32_t s32NumOfBugs = 0;

	scanf_s("%d", &s32TestCase);

	for (int32_t s32i = 0; s32i != s32TestCase; ++s32i)
	{
		scanf_s("%d", &ars32NumOfColumn[s32i]);
		scanf_s("%d", &ars32NumOfRow[s32i]);
		scanf_s("%d", &ars32NumOfPlant[s32i]);

		for (int32_t s32j = 0; s32j != ars32NumOfPlant[s32i]; ++s32j)
		{
			scanf_s("%d", &ars32NumOfYpos[s32j][s32i]);
			scanf_s("%d", &ars32NumOfXpos[s32j][s32i]);
		}
	}

	for (int32_t s32TestCaseIdx = 0; s32TestCaseIdx != s32TestCase; ++s32TestCaseIdx)
	{
		s32NumOfBugs = 0;
		memset(ars32Ground, 0, sizeof(int32_t) * 50 * 50);

		for (int32_t s32j = 0; s32j != ars32NumOfPlant[s32TestCaseIdx]; ++s32j)
		{
			ars32Ground[ars32NumOfXpos[s32j][s32TestCaseIdx]][ars32NumOfYpos[s32j][s32TestCaseIdx]] = 1;
		}

		for (int32_t s32RowIdx = 0; s32RowIdx != ars32NumOfRow[s32TestCaseIdx]; ++s32RowIdx)
		{
			for (int32_t s32ColumnIdx = 0; s32ColumnIdx != ars32NumOfColumn[s32TestCaseIdx]; ++s32ColumnIdx)
			{
				if (ars32Ground[s32RowIdx][s32ColumnIdx] == 1)
				{
					++s32NumOfBugs;
					FindCanGoRegion(ars32NumOfRow[s32TestCaseIdx], ars32NumOfColumn[s32TestCaseIdx],
						s32RowIdx, s32ColumnIdx, ars32Ground);
				}
				else
				{
					// Do Nothing
				}
			}
		}

		printf("%d \n", s32NumOfBugs);
	}

	return 0;
}

void FindCanGoRegion(int32_t s32NumOfRow, int32_t s32NumOfColumn, 
	int32_t s32RowIdx, int32_t s32ColumnIdx, int32_t(*pars32Ground)[50])
{
	int32_t ars32CandidateXpos[2500] = { 0 };
	int32_t ars32CandidateYpos[2500] = { 0 };
	int32_t s32NumOfCandidates = 0;
	int32_t s32Initialize = 0;

	pars32Ground[s32RowIdx][s32ColumnIdx] = 2;

	while (s32Initialize == 0 || s32NumOfCandidates != 0)
	{
		s32Initialize = 1;

		if (((s32RowIdx + 1) < s32NumOfRow)
			&& (pars32Ground[s32RowIdx + 1][s32ColumnIdx] == 1))
		{
			pars32Ground[s32RowIdx + 1][s32ColumnIdx] = 2;

			ars32CandidateXpos[s32NumOfCandidates] = s32RowIdx + 1;
			ars32CandidateYpos[s32NumOfCandidates] = s32ColumnIdx;
			++s32NumOfCandidates;
		}
		else
		{
			// Do Nothing
		}

		if (((s32RowIdx - 1) > (-1))
			&& (pars32Ground[s32RowIdx - 1][s32ColumnIdx] == 1))
		{
			pars32Ground[s32RowIdx - 1][s32ColumnIdx] = 2;

			ars32CandidateXpos[s32NumOfCandidates] = s32RowIdx - 1;
			ars32CandidateYpos[s32NumOfCandidates] = s32ColumnIdx;
			++s32NumOfCandidates;
		}
		else
		{
			// Do Nothing
		}

		if (((s32ColumnIdx + 1) < s32NumOfColumn)
			&& (pars32Ground[s32RowIdx][s32ColumnIdx + 1] == 1))
		{
			pars32Ground[s32RowIdx][s32ColumnIdx + 1] = 2;

			ars32CandidateXpos[s32NumOfCandidates] = s32RowIdx;
			ars32CandidateYpos[s32NumOfCandidates] = s32ColumnIdx + 1;
			++s32NumOfCandidates;
		}
		else
		{
			// Do Nothing
		}

		if (((s32ColumnIdx - 1) > (-1))
			&& (pars32Ground[s32RowIdx][s32ColumnIdx - 1] == 1))
		{
			pars32Ground[s32RowIdx][s32ColumnIdx - 1] = 2;

			ars32CandidateXpos[s32NumOfCandidates] = s32RowIdx;
			ars32CandidateYpos[s32NumOfCandidates] = s32ColumnIdx - 1;
			++s32NumOfCandidates;
		}
		else
		{
			// Do Nothing
		}

		if (s32NumOfCandidates > 0)
		{
			s32RowIdx = ars32CandidateXpos[s32NumOfCandidates - 1];
			s32ColumnIdx = ars32CandidateYpos[s32NumOfCandidates - 1];

			ars32CandidateXpos[s32NumOfCandidates - 1] = 0;
			ars32CandidateYpos[s32NumOfCandidates - 1] = 0;
			--s32NumOfCandidates;

			s32Initialize = 0;
		}
		else
		{
			break;
		}
	}
}