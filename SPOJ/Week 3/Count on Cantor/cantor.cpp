#include<iostream>
using namespace std;
int main(){
	int t;
	long long number, i, total, a, b;
	cin>>t;
	while(t--){
		cin>>number;
		i = 1;
		total = 0;
		while(total < number){
			total += i;
			i++;
		}
		i--;
		total -= i;
		if(i%2 == 0){
			a = number-total;
			b = i - a + 1;
		}
		else{
			b = number-total;
			a = i - b + 1;
		}
		cout<<"TERM "<<number<<" IS "<<a<<"/"<<b<<endl;
	}
	return 0;
}
