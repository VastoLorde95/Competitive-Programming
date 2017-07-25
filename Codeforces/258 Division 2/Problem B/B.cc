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

int n, cnt, a[100000], s, e;

int main(){
	cin>>n;
	
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	
	for(int i = 0; i+1 < n and a[i] < a[i+1]; i++){
		//cout<<a[i]<<" "<<a[i+1]<<endl;
		s = i+1;
	}
	
	for(int i = s; i+1 < n and a[i] > a[i+1]; i++)
		e = i+1;
	
	//cout<<s<<" "<<e<<endl;
	
	if(e == 0){
		cout<<"yes\n";
		cout<<"1 1\n";
		return 0;
	}	
	
	for(int i = e; i+1 < n; i++){
		if(a[i] > a[i+1]){
			cout<<"no\n";
			return 0;
		}
	}	
	
	
	
	if(s == 0 and e == n-1){
		cout<<"yes\n";
		cout<<s+1<<" "<<e+1<<endl;
	}
	else if(s == 0){
		if(a[s] < a[e+1]){
			cout<<"yes\n";
			cout<<s+1<<" "<<e+1<<endl;
		}
		else{
			cout<<"no\n";
		}
	}
	else if(e == n-1){
		if(a[e] > a[s-1]){
			cout<<"yes\n";
			cout<<s+1<<" "<<e+1<<endl;
		}
		else{
			cout<<"no\n";
		}
	}
	else{
		if(a[e] > a[s-1] and a[s] < a[e+1]){
			cout<<"yes\n";
			cout<<s+1<<" "<<e+1<<endl;
		}	
		else{
			cout<<"no\n";
		}
	}
	
	return 0;
}
