#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<math.h>

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z);

using namespace std;

int n, a[100000], first, cnt, flag;
int main(){
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	for(int i = 1; i < n; i++){
		if(a[i] < a[i-1])
			flag = 1;
	}
	
	if(flag == 0){
		cout<<0<<endl;
		return 0;
	}
	
	first = a[0];
	
	for(int i = n-1; i >= 0; i--){
		if(a[i] <= first){
			first = a[i];
			cnt++;
		}
		else{
			for(;i > 0; i--){
				if(a[i] < a[i-1]){
					cout<<-1<<endl;
					return 0;
				}
			}
			cout<<cnt<<endl;
			return 0;
		}
	}
	
	cout<<cnt<<endl;
	
	
	
	return 0;
}
