#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t != 0){
		int arr[t+1];
		int i = 0;
		bool ambi = true;
		while(i<t+1){
			arr[i] = 0;
			i++;
		}
		i = 1;
		while(i<t+1){
			cin>>arr[i];
			i++;
		}
		i = 1;
		while(i<t+1){
			if(arr[arr[i]] != i){
				ambi = false;
				break;
			}
			i++;
		}
		
		if(ambi)
			cout<<"ambiguous"<<endl;
		else
			cout<<"not ambiguous"<<endl;
		cin>>t;
	}
	return 0;
}
