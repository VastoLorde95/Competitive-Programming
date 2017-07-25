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

int t, type, n, b, g, cost1, cost2;
vector<int> boys, girls;
string s;

int main(){
	sd(t);
	while(t--){
		sd(type);
		cin>>s;
		n = s.length();
		
		b = g = 0;
		
		for(int i = 0; i < n; i++){
			if(s[i] == 'B') b++;
			else g++;
		}
		
		if(abs(b-g) > 1){
			cout<< -1 <<endl;
			continue;
		}
		
		if(type == 0){
			//BGBG or GBGB
			int indx = 0;
			
			cost1 = 0;
			cost2 = 0;
			
			for(int i = 0; i < n; i++){
				if(indx == 0 and s[i] == 'G') cost1++;
				else if(indx == 1 and s[i] == 'B') cost1++;
				indx = 1 - indx;
			}
			
			indx = 1;
			
			for(int i = 0; i < n; i++){
				if(indx == 0 and s[i] == 'G') cost2++;
				else if(indx == 1 and s[i] == 'B') cost2++;
				indx = 1 - indx;
			}
			
			if(cost1%2 == 1) cout<< cost2/2 <<endl;
			else if(cost2%2 == 1) cout<< cost1/2 <<endl;
			else cout<< (min(cost1, cost2)/2) <<endl;
		}
		else{
			long long ans = 0, ans2 = 0;
			b = g = 0;
			for(int i = 0; i < n; i++){
				 if(s[i] == 'B'){
				 	ans += abs(i - (2*b));
				 	b++;
				 }
				 else{
				 	ans += abs(i - (2*g + 1));
				 	g++;
				 }
			}
			
			b = g = 0;
			for(int i = 0; i < n; i++){
				 if(s[i] == 'G'){
				 	ans2 += abs(i - (2*g));
				 	g++;
				 }
				 else{
				 	ans2 += abs(i - (2*b + 1));
				 	b++;
				 }
			}
			
			if(ans%2 == 1){
				cout<< ans2/2 << endl;
			}
			else if(ans2%2 == 1){
				cout<< ans/2 <<endl;
			}
			else{		
				cout<< (min(ans, ans2)/2) <<endl;
			}
		}
						
				
	}	
	return 0;
}
