#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	const double PI  =3.141592653589793238463;
	long long n;
	cin>>n;
	while( n!= 0){
		long double x =((n*n) / (2 * PI));
		printf("%.2Lf\n", x);
		cin>>n;
	}
	return 0;
}
