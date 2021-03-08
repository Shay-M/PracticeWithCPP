//VS - 17
//c
#include<stdio.h>
#include<stdlib.h>
#include"Interval.h"
#include"quick_sort.h"

void GreedyColoring();

void getIntervals(Interval *tempInterval, int k);//scanf
void printIntervals(Interval *tempInterval, int k);
int degIntervals(Interval *tempInterval, int k);
int chromaticNum(Interval *tempInterval, int k);
void getColor(Interval *tempInterval, int k);

void printMaxMinDeg(Interval *tempInterval, int k, int *max, int *min);
void printColoring(Interval *tempInterval, int k);

void resatColorArr(int*, int k);
int seeEdges(Interval *tempInterval, int i, int j);

void main() {
	GreedyColoring();
}

void GreedyColoring()
{
	int k, max = 0, min = 0, count = 0;
	printf_s("Please input k:\n");
	scanf_s("%d", &k);
	if (k == 0) exit(1);//empty

	Interval * tempInterval = (Interval*)malloc(k * sizeof(Interval));
	if (!tempInterval) exit(-1);//faild memory

	getIntervals(tempInterval, k);
	Quick_Sort(tempInterval, 0, k - 1);
	printIntervals(tempInterval, k);

	count = degIntervals(tempInterval, k);
	printf_s(" \nG Edges = %d", count);
	printMaxMinDeg(tempInterval, k, &max, &min);
	getColor(tempInterval, k);
	printf_s(" \nChromatic Mumber of G = %d", chromaticNum(tempInterval, k));
	printf_s(" \nG' Edges : %d", (k - 1)*k / 2 - count);
	printf_s(" \nMax G' deg: %d", k - min - 1);
	printf_s(" \nMin G' deg: %d\n", k - max - 1);
	printColoring(tempInterval, k);

	printf_s("\n");
	free(tempInterval);
}

void getIntervals(Interval * tempInterval, int k)
{
	int i;
	printf_s("You will now be asked to insert a family of %d intervals: \n", k);
	for (i = 0; i < k; i++)
	{
		printf_s("%dth Interval: ", i + 1);
		scanf_s("%d%d", &tempInterval[i].a, &tempInterval[i].b);
		//if () exit(1);
		tempInterval[i].deg = 0;
		tempInterval[i].color = 0;
	}

}

void printIntervals(Interval * tempInterval, int k)
{
	int i;
	printf_s(" \nThe Interval family is: \n");
	for (i = 0; i < k; i++)
	{
		printf_s("[%d %d]", tempInterval[i].a, tempInterval[i].b);
		if (i != k - 1) printf_s(",");
	}
}

int degIntervals(Interval * tempInterval, int k)
{
	int i, j, count = 0;
	for (i = 0; i < k; i++)
	{
		for (j = i; j < k; j++)
		{
			if (i != j)
			{
				if (seeEdges(tempInterval, i, j))
				{
					tempInterval[i].deg++;
					tempInterval[j].deg++;
					count++;
				}
			}
		}
	}
	return count;
}

void getColor(Interval * tempInterval, int k)
{
	int i, j;
	int * colorArry = (int*)malloc(k * sizeof(int));
	if (!colorArry) exit(-1);//faild memory

	for (i = 0; i < k; i++)
	{
		resatColorArr(colorArry, k);//put zero too arr

		for (j = 0; j < k; j++)
		{
			if (seeEdges(tempInterval, i, j)) {
				colorArry[tempInterval[j].color]++;
			}
		}

		for (j = 0; colorArry[j] != 0; j++)
		{
			tempInterval[i].color = j + 1;
		}

	}
	free(colorArry);
}

int chromaticNum(Interval * tempInterval, int k)
{
	int i, maxC = 1;
	for (i = 0; i < k; i++)
	{
		if (tempInterval[i].color > maxC)
		{
			maxC = tempInterval[i].color;
		}
	}
	return maxC;
}

void printMaxMinDeg(Interval * tempInterval, int k, int * max, int * min)
{
	int i;
	*max = tempInterval[0].deg;
	*min = tempInterval[0].deg;

	for (i = 1; i < k; i++)
	{
		if (tempInterval[i].deg > *max)
			*max = tempInterval[i].deg;
		
		if (tempInterval[i].deg < *min)
			*min = tempInterval[i].deg;
	}
	printf_s(" \nMax deg of G = %d", *max);
	printf_s(" \nMin deg of G = %d", *min);
}

void printColoring(Interval * tempInterval, int k)
{
	int first = 1, i, j;
	int maxC = chromaticNum(tempInterval, k);
	printf_s("Optinal Coloring: ");
	for (j = 0; j < maxC; j++)
	{
		printf_s("{");
		for (i = 0; i < k; i++)
		{
			if (tempInterval[i].color - 1 == j)
			{
				if (!first) printf_s(",");
				first = 0;
				printf_s("[%d %d]", tempInterval[i].a, tempInterval[i].b);
			}
		}
		first = 1;
		printf_s("} = %d", j + 1);
		if (j != maxC-1) printf_s(", ");
	}
}

void resatColorArr(int * arr, int k)
{
	int i;
	for (i = 0; i < k; i++)
		arr[i] = 0;
}

int seeEdges(Interval * tempInterval, int i, int j)
{
	if ((tempInterval[i].b >= tempInterval[j].a) 
		&& (tempInterval[i].a <= tempInterval[j].b))
		return 1;
	
	return 0;
}
