#include <stdio.h>
#include <memory.h>

// 포인트 
// 바로 DP 형식으로 푸니 시간초과 이슈를 해결할 수 없었음, 함수 : GetConnectCaseByDynamicProgramming
// 이항 정리 방식으로 푸니 시간 초과 이슈를 해결할 수 없었음, 함수 : GetConnectCaseByBinomialTheorem
// 이항 정리 방식에 DP를 더해 배열 값을 사용하니 시간 초과 이슈를 해결할 수 있었음

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

// 이항 정리, 파스칼의 삼각형 방식
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