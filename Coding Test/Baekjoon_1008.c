#include <stdio.h>

// ����Ʈ 
// 8byte �ڷ����� ����ϸ� 10-9 �ڸ������� ��Ȯ�ϰ� ǥ������
// 4byte �ڷ��� ��� ��, 10-8 �ڸ������� ���� ��� �̻�����
// 4byte -> 32bit, 1bit �� ��ȣ, 8bit �� ����(�Ҽ���), 23bit�� ����
// �� ����� IEEE���� ǥ������ ������ ��� (IEEE 754 Standard for Floating-Point Arithmetic)


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