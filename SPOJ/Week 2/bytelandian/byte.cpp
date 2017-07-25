#include<iostream>
#include<map>
using namespace std;
map<long long, long long> a;
long long answer(long long n){
	long long val;
	if(n == 0)
		return 0;
	if(a.find(n) == a.end()){
		val = answer(n/2) + answer(n/3) + answer(n/4);
		if(val > n){
			a[n] = val;
		}
		else{
			a[n] = n;
		}
	}
	return a[n];
}
int main(){
	long long number;
	int t = 10;
	a[1] = 1;
	a[2] = 2;
	a[3] = 3;
	a[4] = 4;
	a[5] = 5;
	a[6] = 6;
	a[7] = 7;
	a[8] = 8;
	a[9] = 9;
	a[10] = 10;
	a[11] = 11;
	a[12] = 13;
	
	while(t--){
		cin>>number;
		cout<<answer(number)<<endl;
	}
	return 0;
}

