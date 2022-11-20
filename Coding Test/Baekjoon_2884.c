#include <stdio.h>

typedef int int32_t;

int main()
{
	int32_t s32Hour = 0, s32Minute = 0;
	const int32_t s32DefaultOffsetMinute = 45;
	const int32_t s32MinutePerHour = 60;
	const int32_t s32HourPerDay = 24;

	int32_t s32AlarmHour = 0, s32AlarmMinute = 0;

	while (1)
	{
		scanf_s("%d", &s32Hour);
		scanf_s("%d", &s32Minute);

		
		if ((s32Minute - s32DefaultOffsetMinute) < 0)
		{
			s32AlarmMinute = s32Minute - s32DefaultOffsetMinute + s32MinutePerHour;

			s32AlarmHour = s32Hour - 1;

			if (s32AlarmHour < 0)
			{
				s32AlarmHour += s32HourPerDay;
			}
			else
			{
				// Do Nothing
			}
		}
		else
		{
			s32AlarmMinute = s32Minute - s32DefaultOffsetMinute;

			s32AlarmHour = s32Hour;
		}

		printf_s("%d %d\n", s32AlarmHour, s32AlarmMinute);
	}
}