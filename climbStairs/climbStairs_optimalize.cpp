#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int climbStairs(int n){
	int ways[n];
	for(int j=0;j<n;j++){
		ways[j]=-1;
	}
	ways[0]=1;
	ways[1]=2;
	for(int i=2;i<n;i++)
		ways[i]=ways[i-1]+ways[i-2];
	return ways[n-1];
	
}

int main(int argc, char *argv[]){
	int n;
	if(argc < 2 || (n = atoi(argv[1]))<0)
	{
		cout << "unvalid parameter !" << endl;
		exit(1);
	}
	n = atoi(argv[1]);
	int result;
	result=climbStairs(n);
	cout << result << endl;

	return 0;
}

