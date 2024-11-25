#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void Cdistance(int n, double * x1, double* x2, double* y1, double* y2, double* z) {
	for (int i = 0; i < n; i++) {
		z[i] = sqrt(pow(x2[i] - x1[i], 2) + pow(y2[i] - y1[i], 2));
	}
}

int main(int argc, char* argv[]) {
	int n = 0;
	double* x1, * x2, * y1, * y2, * z;

	printf("Enter the number of points (n): ");
	scanf_s("%d", &n);

	x1 = (double*)malloc(n * sizeof(double));
	x2 = (double*)malloc(n * sizeof(double));
	y1 = (double*)malloc(n * sizeof(double));
	y2 = (double*)malloc(n * sizeof(double));
	z = (double*)malloc(n * sizeof(double));

	//Initialize clock variable
	clock_t start, end;
	double time_taken;

	// Input coordinates
	printf("Enter values for x1:\n");
	for (int i = 0; i < n; i++) {
		scanf_s("%lf", &x1[i]);
	}

	printf("Enter values for x2:\n");
	for (int i = 0; i < n; i++) {
		scanf_s("%lf", &x2[i]);
	}

	printf("Enter values for y1:\n");
	for (int i = 0; i < n; i++) {
		scanf_s("%lf", &y1[i]);
	}

	printf("Enter values for y2:\n");
	for (int i = 0; i < n; i++) {
		scanf_s("%lf", &y2[i]);
	}

//----------------C PROGRAM VERSION----------
	start = clock();
	Cdistance(n, x1, x2, y1, y2, z);
	end = clock();
	time_taken = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;	//time program in c (ms)
	printf("Time it takes to execute using C is %lf ms\n", time_taken);

//----------------C PROGRAM SANITY CHECK -------
	for (int i = 0; i < n; i++)
		printf("%.9f\n", z[i]);


	return 0;
}