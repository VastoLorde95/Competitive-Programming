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

int t, n, k, cnt, r, idx, flag;
string s;

int main(){
	cin>>t;
	while(t--){
		cin>>n>>k;
		cin>>s;
		int i = 0, j = 0;
		cnt = r = 0;
		idx = 1;
		
		while(i < n and s[i] == 'G') i++;
		
		if(i == n){
			if(s[i] == 'G'){
				cout<< 0 <<endl;
				continue;
			}
			else{
				cout<< 1 <<endl;
				continue;
			}
		}
		
		j = min(n-1, i+k-1);
		
		while(i != n-1){
			cout<<i<<" "<<idx<<endl;
			if(idx == 1){// find G
				cnt++;
				while(i <= j and s[i] == 'R'){
					i++;
				}
				
				if(s[i] == 'R'){
					while(i < n and s[i] == 'G') i++;
					
					j = min(n-1, i+k-1);
				}
				
				else{
					j = min(n-1, i+k-1);
					idx = 1-idx;
				}
			}
			
			else{//find R
				cnt++;
				
				while(i <= j and s[i] == 'G'){
					i++;
				}
				
				if(s[i] == 'G'){
					while(i < n and s[i] == 'R') i++;
					
					j = min(n-1, i+k-1);
				}
				
				else{
					j = min(n-1, i+k-1);
					idx = 1 - idx;
				}
			}
			
		}
		
		cout<< cnt << endl;
	}
	return 0;
}
