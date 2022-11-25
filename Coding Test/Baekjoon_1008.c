#include <stdio.h>

// 포인트 
// 8byte 자료형을 사용하면 10-9 자릿수까지 정확하게 표현가능
// 4byte 자료형 사용 시, 10-8 자릿수부터 연산 결과 이상해짐
// 4byte -> 32bit, 1bit 는 부호, 8bit 는 지수(소숫점), 23bit는 가수
// 이 방식은 IEEE에서 표준으로 제안한 방식 (IEEE 754 Standard for Floating-Point Arithmetic)


typedef long int int64_t;
typedef double float64_t;

typedef int int32_t;
typedef float float32_t;

int main()
{
	int64_t s64_1stVal = 0, s64_2ndVal = 0;
	float64_t f64_1stVal = 0.0f, f64_2ndVal = 0.0f;
	float64_t f64_RetVal = 0.0f;

	while (1)
	{
		scanf_s("%d", &s64_1stVal);
		scanf_s("%d", &s64_2ndVal);

		f64_1stVal = (float64_t)s64_1stVal;
		f64_2ndVal = (float64_t)s64_2ndVal;

		printf_s("%f \n", f64_1stVal);
		printf_s("%f \n", f64_2ndVal);

		f64_RetVal = f64_1stVal / f64_2ndVal;

		printf_s("%.10f \n", f64_RetVal);
	}
}