#include<iostream>
using namespace std;
int main(){
	int t;
	long long n;
	long long sum;
	long long temp;
	long long i;
	cin>>t;
	while(t--){
		cin>>n;
		i = 0;
		sum = 0;
		while(i<n){
			cin>>temp;
			sum += temp%n;
			i++;
		}
		if(sum%n == 0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
