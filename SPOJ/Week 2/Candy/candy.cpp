#include<iostream>
using namespace std;
int main(){
	int n, k, i;
	long long int sum, avg, swaps;
	int arr[10000];
	cin>>n;
	while(n != -1){
		i = 0;
		sum = 0;
		swaps = 0;
		k = n;
		while(k--){
			cin>>arr[i];
			sum += arr[i];
			i++;
		}
		if(sum % n == 0){
			avg = sum / n;
			i = 0;
			while(i<n){
				if(arr[i] < avg){
					swaps += avg - arr[i];
				}
				i++;
			}
			cout<<swaps<<endl;
		}
		else{
			cout<<-1<<endl;
		}
		cin>>n;
	}
	return 0;
}
