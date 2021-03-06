
#include <stdio.h>
#include <stdlib.h>

typedef struct Time
{
	int hour;
	int minute;
	int seconds;
};


Time* inPut(int & n) {

	
	Time * arr = NULL;
	scanf_s("%d", &n);

	if (n > 0)
	{
		arr = (Time*)malloc(sizeof(Time) * n);
	}

	for (int i = 0; i < n; i++)
	{
		printf_s("in: \n");
		scanf_s("%d%d%d", &arr[i].hour, &arr[i].minute, &arr[i].seconds);
	}


	return arr;
}

void funTimeFix(Time & _nowTime) {

	while (_nowTime.seconds >= 60)
	{
		_nowTime.seconds -= 60;
		_nowTime.minute++;
	}

	while (_nowTime.minute >= 60)
	{
		_nowTime.minute -= 60;
		_nowTime.hour++;
	}

}

void main() {
	Time newTime = { 3,128,70 };
	Time * Temp;
	int n;
	funTimeFix(newTime);

	Temp = inPut(n);

	for (int i = 0; i < n; i++)
	{
		printf("hour: %d\n", Temp[i].hour);
		printf("minute: %d\n", Temp[i].minute);
		printf("seconds: %d\n", Temp[i].seconds);
	}

	
}