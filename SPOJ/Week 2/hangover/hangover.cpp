#include<iostream>
using namespace std;
int main(){
	float total;
	float sum;
	float i;
	cin>>total;
	while(total != 0.0){
		i = 2;
		sum = 0.0;
		while(sum <= total){
			sum += 1 / i;
			i += 1;
		}
		cout<<(int) (i-2)<<" card(s)"<<endl;
		cin>>total;
	}
	return 0;
}
