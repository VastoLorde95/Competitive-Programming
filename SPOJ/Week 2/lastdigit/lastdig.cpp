#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int t,a, remainder;
	unsigned long long b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		a = a%10;
		if( b ==0)
			cout<<1<<endl;
		else if(a == 1 || a == 5 || a == 6 || a == 0 ){
			cout<<a<<endl;
		}
		else if(a == 2 || a == 3 || a == 7 || a == 8){
			remainder = b % 4;
			if (remainder == 0)
				remainder += 4;
			cout<<((int) pow(a,remainder))%10<<endl;
		}
		else if(a == 4 || a == 9){
			remainder = b%2;
			if (remainder == 0)
				remainder += 2;
			cout<<((int) pow(a,remainder))%10<<endl;
		}
	}
	return 0;
}
