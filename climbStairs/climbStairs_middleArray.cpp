#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int climbStairs(int n){
	int ways[n];
	for(int j=0;j<n;j++){
		ways[j]=-1;
	}
	if(n<=0)
		return 0;
	if(n==1)
	{
		ways[n-1]=1;
		return ways[n-1];
	}	
	if(n==2)
	{
		ways[n-1]=2;
		return ways[n-1];
	}
	else{
		if(ways[n-1]==-1)
			ways[n-1] = climbStairs(n-1)+climbStairs(n-2);
		return ways[n-1];
	}
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

