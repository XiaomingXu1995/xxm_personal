#include <iostream>
#include <cstdlib>

#include <sys/time.h>
using namespace std;

double get_sec(){
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (double)tv.tv_sec + (double)tv.tv_usec / 1000000;
}

int main(){
	
	long iterator = 1 << 24;
	long arrLength = 1 << 30;
	long arr0Length = 1 << 29;

	double t0 = get_sec();
	for(long i = 0; i < iterator; i++){
		long indexTest = rand()%arrLength;
		long indexTest1 = rand()%arr0Length;
	}

	double t1 = get_sec();
	cerr << "the time of rand() is: " << t1 - t0 << endl;

	double * arr = (double *)malloc(arrLength * sizeof(double));
	double * arr0 = (double *)malloc(arr0Length * sizeof(double));
	double * arr1 = (double *)malloc(arr0Length * sizeof(double));

	for(long i = 0; i < arrLength; i++){
		arr[i] = i * 1.0;
	}

	for(long i = 0; i < arr0Length; i++){
		arr0[i] = i * 1.0;
		arr1[i] = i * 2.0;
	}

	double t2 = get_sec();
	cerr << "the time of initialize array is: " << t2 - t1 << endl;

	double result0 = 0.;
	double result1 = 0.;

	for(long i = 0; i < iterator; i++){
		long index0 = rand()%arrLength;
		long index1 = rand()%arrLength;
		result0 += arr[index0];
		result0 -= arr[index1];//make sure not overflow

//		long index0 = i % arrLength;
//		long index1 = (i*2) % arrLength;
//		result0 += arr[index0];
//		result0 -= arr[index1];//make sure not overflow
	}

	double t3 = get_sec();
	cerr << "the time of IO arr  is: " << t3 - t2 << endl;

	for(long i = 0; i < iterator; i++){
		long index2 = rand()%arr0Length;
		long index3 = rand()%arr0Length;
		result1 += arr0[index2];
		result1 -= arr1[index3];

//		long index2 = i % arr0Length;
//		long index3 = i % arr0Length;
//		result1 += arr0[index2];
//		result1 -= arr1[index3];
	}

	double t4 = get_sec();
	cerr << "the time of IO arr0 and arr1 is: " << t4 - t3 << endl;

	cerr << "ther result0 is: " << result0 << endl;
	cerr << "ther result1 is: " << result1 << endl;

	return 0;


}










































































