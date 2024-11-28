#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void x64distance(int n, double* x1, double* x2, double* y1, double* y2, double* z);

void Cdistance(int n, double * x1, double* x2, double* y1, double* y2, double* z) {
	for (int i = 0; i < n; i++)
		z[i] = sqrt(pow(x2[i] - x1[i], 2) + pow(y2[i] - y1[i], 2));
}

int main(int argc, char* argv[]) {
	int n = 134217728;
	double* x1, * x2, * y1, * y2, * z;

	x1 = (double*)malloc(n * sizeof(double));
	x2 = (double*)malloc(n * sizeof(double));
	y1 = (double*)malloc(n * sizeof(double));
	y2 = (double*)malloc(n * sizeof(double));
	z = (double*)malloc(n * sizeof(double));

// Initialize clock variable
	clock_t start, end;
	double time_taken;

// Initialize Array with Random Numbers
	for (int i = 0; i < n; i++) {
		x1[i] = 1.0 + i * 0.41;  
		x2[i] = 3.0 + i * 0.25;
		y1[i] = 4.0 + i * 0.33;
		y2[i] = 2.2 + i * 0.23;
	}

//----------------C PROGRAM VERSION----------
	start = clock();
	Cdistance(n, x1, x2, y1, y2, z);
	end = clock();
	time_taken = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;
	printf("Time it takes to execute using C is %lf ms\n", time_taken);

//----------------C PROGRAM SANITY CHECK---------
	for (int i = 0; i < (n < 10 ? n : 10); i++)
		printf("%.9f\n", z[i]);

//----------------x86-64 PROGRAM VERSION----------
	start = clock();
	x64distance(n, x1, x2, y1, y2, z);
	end = clock();
	time_taken = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;
	printf("Time it takes to execute using x86-64 is %lf ms\n", time_taken);

//----------------C PROGRAM SANITY CHECK---------
	for (int i = 0; i < (n < 10 ? n : 10); i++)
		printf("%.9f\n", z[i]);

	return 0;
}
