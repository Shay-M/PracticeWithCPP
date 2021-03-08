#include"quick_sort.h"

void Quick_Sort(Interval* ArrInterval, int p, int r) {
	int  q;
	if (p < r) {
		q = Partition(ArrInterval, p, r);
		Quick_Sort(ArrInterval, p, q - 1);
		Quick_Sort(ArrInterval, q + 1, r);
	}
}

int Partition(Interval*  ArrInterval, int p, int r) {
	int  x = ArrInterval[r].a;
	int  i = p - 1, j;
	for (j = p; j <= r - 1; j++)
		if (ArrInterval[j].a <= x) {
			i = i + 1;
			swape(ArrInterval + i, ArrInterval + j);
		}
	swape(ArrInterval + i + 1, ArrInterval + r);
	return  i + 1;
}

void swape(Interval * pa, Interval * pb) {
	Interval temp = *pa;
	*pa = *pb;
	*pb = temp;
}