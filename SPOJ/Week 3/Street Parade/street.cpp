#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<stack>
using namespace std;
int main(){
	int n;
	cin>>n;
	while(n != 0){
		stack<int> st;
		int array[n];
		int i = 0, j;
		bool ans = true;
		while(i<n){
			cin>>array[i];
			i++;
		}
		i = 0, j = 1;
		while(i < n){
			if(array[i] == j){
				j++;
				i++;
			}
			else if(!st.empty() && st.top() == j){
				j++;
				st.pop();
			}
			else{
				if(!st.empty() && array[i] > st.top()){
					//cout<<array[i]<<" "<<st.top()<<" "<<j<<endl;
					ans = false;
					break;
				}
				else
					st.push(array[i]);
				i++;
			}
		}
		if(ans)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
		cin>>n;
	}
	return 0;
}
