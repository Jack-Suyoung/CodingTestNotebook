#include <stdio.h>
#include <memory.h>

// ����Ʈ 
// �ٷ� DP �������� Ǫ�� �ð��ʰ� �̽��� �ذ��� �� ������, �Լ� : GetConnectCaseByDynamicProgramming
// ���� ���� ������� Ǫ�� �ð� �ʰ� �̽��� �ذ��� �� ������, �Լ� : GetConnectCaseByBinomialTheorem
// ���� ���� ��Ŀ� DP�� ���� �迭 ���� ����ϴ� �ð� �ʰ� �̽��� �ذ��� �� �־���

typedef unsigned long long int uint64_t;

uint64_t GetConnectCaseByDynamicProgramming(uint64_t u64WestSite, uint64_t u64EastSite);
uint64_t GetConnectCaseByBinomialTheorem(uint64_t u64WestSite, uint64_t u64EastSite);


uint64_t gu64ConnectCase = 0;
uint64_t garu64ConnectCase[100][100] = { 0 };
int main()
{
	uint64_t u64TestCase = 0;
	uint64_t aru64WestSite[1000] = { 0 };
	uint64_t aru64EastSite[1000] = { 0 };

	scanf_s("%lld", &u64TestCase);

	for (uint64_t u64i = 0; u64i != u64TestCase; ++u64i)
	{
		scanf_s("%lld", &aru64WestSite[u64i]);
		scanf_s("%lld", &aru64EastSite[u64i]);
	}

	for (uint64_t u64i = 0; u64i != u64TestCase; ++u64i)
	{
		gu64ConnectCase = 0;

		//gu64ConnectCase += GetConnectCaseByDynamicProgramming(aru64WestSite[u64i], aru64EastSite[u64i]);
		gu64ConnectCase += GetConnectCaseByBinomialTheorem(aru64WestSite[u64i], aru64EastSite[u64i]);


		printf("%lld \n", gu64ConnectCase);

		memset(garu64ConnectCase, 0, sizeof(uint64_t) * 30 * 30);
	}

	return 0;
}

// Solve by DP
uint64_t GetConnectCaseByDynamicProgramming(uint64_t u64WestSite, uint64_t u64EastSite)
{
	uint64_t u64RetVal = 0;
	uint64_t u64i = 0;

	if (u64WestSite == 1)
	{
		u64RetVal = u64EastSite;
	}
	else if (u64WestSite == u64EastSite)
	{
		u64RetVal = 1;
	}
	else
	{
		for (u64i = 0; u64i < (u64EastSite - u64WestSite + 1); ++u64i)
		{
			if (garu64ConnectCase[u64WestSite - 1][u64EastSite - 1 - u64i] == 0)
			{
				garu64ConnectCase[u64WestSite - 1][u64EastSite - 1 - u64i] = \
					GetConnectCaseByDynamicProgramming(u64WestSite - 1, u64EastSite - 1 - u64i);

				gu64ConnectCase += garu64ConnectCase[u64WestSite - 1][u64EastSite - 1 - u64i];
			}
			else
			{
				gu64ConnectCase += garu64ConnectCase[u64WestSite - 1][u64EastSite - 1 - u64i];
			}
		}
	}

	return u64RetVal;
}

// ���� ����, �Ľ�Į�� �ﰢ�� ���
uint64_t GetConnectCaseByBinomialTheorem(uint64_t u64WestSite, uint64_t u64EastSite)
{
	uint64_t u64RetVal = 0;

	if (u64WestSite == 1)
	{
		u64RetVal = u64EastSite;
	}
	else if (u64WestSite == u64EastSite)
	{
		u64RetVal = 1;
	}
	else
	{
		if (garu64ConnectCase[u64WestSite][u64EastSite - 1] != 0)
		{
			u64RetVal += garu64ConnectCase[u64WestSite][u64EastSite - 1];
		}
		else
		{
			garu64ConnectCase[u64WestSite][u64EastSite - 1] = GetConnectCaseByBinomialThreorem(u64WestSite, u64EastSite - 1);
			u64RetVal += garu64ConnectCase[u64WestSite][u64EastSite - 1];

		}

		if (garu64ConnectCase[u64WestSite - 1][u64EastSite - 1] != 0)
		{
			u64RetVal += garu64ConnectCase[u64WestSite - 1][u64EastSite - 1];
		}
		else
		{
			garu64ConnectCase[u64WestSite - 1][u64EastSite - 1] = GetConnectCaseByBinomialThreorem(u64WestSite - 1, u64EastSite - 1);
			u64RetVal += garu64ConnectCase[u64WestSite - 1][u64EastSite - 1];
		}

	}


	return u64RetVal;
}