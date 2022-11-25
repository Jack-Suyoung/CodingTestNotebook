#include <stdio.h>
#include <memory.h>

// Æ÷ÀÎÆ® 

typedef unsigned long long int uint64_t;

uint64_t GetConnectCase(uint64_t u64WestSite, uint64_t u64EastSite);

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

		gu64ConnectCase += GetConnectCase(aru64WestSite[u64i], aru64EastSite[u64i]);

		printf("%lld \n", gu64ConnectCase);

		memset(garu64ConnectCase, 0, sizeof(uint64_t) * 30 * 30);
	}

	return 0;
}

uint64_t GetConnectCase(uint64_t u64WestSite, uint64_t u64EastSite)
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
					GetConnectCase(u64WestSite - 1, u64EastSite - 1 - u64i);

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