#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void x64distance(int n, double* x1, double* x2, double* y1, double* y2, double* z);

void Cdistance(int n, double * x1, double* x2, double* y1, double* y2, double* z) {
	for (int i = 0; i < n; i++)
		z[i] = sqrt(pow(x2[i] - x1[i], 2) + pow(y2[i] - y1[i], 2));
}

double measure_time(void (*func)(int, double*, double*, double*, double*, double*), int n, double* x1, double* x2, double* y1, double* y2, double* z, int iterations) {
	clock_t start, end;
	double total_time = 0;
	for (int i = 0; i < iterations; i++) {
		start = clock();
		func(n, x1, x2, y1, y2, z);
		end = clock();
		total_time += ((double)(end - start)) / CLOCKS_PER_SEC;
	}
	return (total_time / iterations) * 1000; 
}

int main(int argc, char* argv[]) {
	int n = 134217728; // 2^20 = 1048576, 2^24 = 16777216, 2^27 = 134217728, 2^30 = 1073741824
	int iterations = 30;
	double *x1, *x2, *y1, *y2, *z;

	x1 = (double*)malloc(n * sizeof(double));
	x2 = (double*)malloc(n * sizeof(double));
	y1 = (double*)malloc(n * sizeof(double));
	y2 = (double*)malloc(n * sizeof(double));
	z = (double*)malloc(n * sizeof(double));

// Initialize clock variable // note: for manual computation
	// clock_t start, end; 
	// double time_taken;

// Initialize Array with Random Numbers
	for (int i = 0; i < n; i++) {
		x1[i] = 1.0 + i * 0.41;  
		x2[i] = 3.0 + i * 0.25;
		y1[i] = 4.0 + i * 0.33;
		y2[i] = 2.2 + i * 0.23;
	}

//----------------C PROGRAM VERSION----------
	/* note: for manual computation
	start = clock();
	Cdistance(n, x1, x2, y1, y2, z);
	end = clock();
	time_taken = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;
	printf("Time it takes to execute using C is %lf ms\n", time_taken);
	*/
	double c_time = measure_time(Cdistance, n, x1, x2, y1, y2, z, iterations);
	printf("Average time it takes to execute %d iterations using C is %.6f ms\n", iterations, c_time);

//----------------C PROGRAM SANITY CHECK---------
	for (int i = 0; i < (n < 10 ? n : 10); i++)
		printf("%.9f\n", z[i]);

//----------------x86-64 PROGRAM VERSION----------
	/* note: for manual computation
	start = clock();
	x64distance(n, x1, x2, y1, y2, z);
	end = clock();
	time_taken = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;
	printf("Time it takes to execute using x86-64 is %lf ms\n", time_taken);
	*/
	double asm_time = measure_time(x64distance, n, x1, x2, y1, y2, z, iterations);
	printf("Average time it takes to execute %d iterations using x86-64 is %.6f ms\n", iterations, asm_time);

//----------------C PROGRAM SANITY CHECK---------
	for (int i = 0; i < (n < 10 ? n : 10); i++)
		printf("%.9f\n", z[i]);

	return 0;
}
