#include <stdio.h>

/* 

포인트
- 다차원 행렬 값 입력 받기
- 다차원 행렬 값 덧셈
- 다차원 행렬 값 출력하기

*/

typedef unsigned int uint16_t;
typedef signed char int8_t;

int main()
{
	uint16_t u16i = 0, u16j = 0;
	uint16_t arstArr1[100][100] = { 0 }, arstArr2[100][100] = { 0 };
	uint16_t u16Row = 0, u16Column = 0;
	uint16_t arstArrSum[100][100] = { 0 };

	while (1)
	{
		scanf_s("%d", &u16Row);
		scanf_s("%d", &u16Column);

		for (u16i = 0; u16i != u16Row; ++u16i)
		{
			for (u16j = 0; u16j != u16Column; ++u16j)
			{
				scanf_s("%d", &arstArr1[u16i][u16j]);
			}
		}

		for (u16i = 0; u16i != u16Row; ++u16i)
		{
			for (u16j = 0; u16j != u16Column; ++u16j)
			{
				scanf_s("%d", &arstArr2[u16i][u16j]);
			}
		}



		for (u16i = 0; u16i != u16Row; ++u16i)
		{
			for (u16j = 0; u16j != u16Column; ++u16j)
			{
				arstArrSum[u16i][u16j] = arstArr1[u16i][u16j] + arstArr2[u16i][u16j];
			}
		}



		//for (u16i = 0; u16i != u16Row; ++u16i)
		//{
		//	for (u16j = 0; u16j != u16Column; ++u16j)
		//	{
		//		printf("%d ", arstArr1[u16i][u16j]);
		//	}
		//	printf("\n");
		//}

		//for (u16i = 0; u16i != u16Row; ++u16i)
		//{
		//	for (u16j = 0; u16j != u16Column; ++u16j)
		//	{
		//		printf("%d ", arstArr2[u16i][u16j]);
		//	}
		//	printf("\n");
		//}

		for (u16i = 0; u16i != u16Row; ++u16i)
		{
			for (u16j = 0; u16j != u16Column; ++u16j)
			{
				printf("%d ", arstArrSum[u16i][u16j]);
			}
			printf("\n");
		}
	}

	return 0;
}