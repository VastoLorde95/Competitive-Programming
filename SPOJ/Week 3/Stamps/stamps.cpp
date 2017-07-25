#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int t, n, diff, sum, j =1;
	cin>>t;
	while(t--){
		cin>>diff>>n;
		int array[n];
		int i = 0;
		int count = 0;
		sum = 0;
		while(i < n){
			cin>>array[i];
			i++;
		}
		sort(array, array + n);
		i = n-1;
		while(i >= 0 && sum < diff){
			sum += array[i];
			i--;
			count++;
		}
		cout<<"Scenario #"<<j<<":"<<endl;
		if(sum >= diff)
			cout<<count<<endl;
		else
			cout<<"impossible"<<endl;
		j++;
	}
	return 0;
}
