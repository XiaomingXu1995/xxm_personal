#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <random>

using namespace std;
using std::default_random_engine;
using std::uniform_int_distribution;

void printArr(int * arr, int n){
	for(int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int parttion(int *arr,int l,int r){
	int x=arr[r];
	int i=l-1;
	for(int j = l; j < r; j++){
		if(arr[j] <= x)
		{
			i = i + 1;
			int temp;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	arr[r] = arr[i+1];
	arr[i+1] = x;

	return i+1;

}

void quickSort(int *arr, int l, int r){
	if(l<r){
		int mid = parttion(arr, l, r);
//		printf("%d \n",mid);
//		printArr(arr,r);
		quickSort(arr, l, mid-1);
		quickSort(arr, mid+1, r);
	}
}


int main(){
	int *arrdemo;
	arrdemo =(int *) malloc(100*sizeof(int));

	default_random_engine e;
	uniform_int_distribution<unsigned> u(1,100);
	for(int i = 0; i < 100; i++)
		arrdemo[i]=u(e);

	
	printArr(arrdemo,100);

	quickSort(arrdemo,0,99);
	printArr(arrdemo,100);

	return 0;

}
