#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int climbStairs(int n){
	if(n<=0)
		return 0;
	if(n==1)
		return 1;
	if(n==2)
		return 2;
	else
		return climbStairs(n-1)+climbStairs(n-2);
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

