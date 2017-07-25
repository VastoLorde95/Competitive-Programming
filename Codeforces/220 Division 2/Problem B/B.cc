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
#define fi first
#define se second

using namespace std;

string s;
int l;
long long cnt;

int main(){
	cin>>s;
	l = s.length();
	
	if(l <= 2){
	 	cout<< 1 << endl;
	}
	
	else if(l == 3){
		if(s[0]-'0' + s[1]-'0' == 9 and s[1]-'0' + s[2]-'0' == 9){
			cout << 2 << endl;
		}
		
		else if(s[0]-'0' + s[1]-'0' == 9 and  s[2]-'0' == 9){
			cout << 2 << endl;
		}
		
		else if(s[0]-'0' == 9 and s[1]-'0' + s[2]-'0' == 9){
			cout << 2 << endl;
		}
		
		else{
			cout << 1 << endl;
		}
	}
	
	else{
		cnt = 1;
		
		for(int i = 1; i < l; i++){
			long long tmp = 1;
			while(i < l and (s[i]-'0' + s[i-1]-'0') == 9){
				tmp++;
				i++;
			}
			
			if(tmp%2 == 1) cnt *= (tmp+1)/2;
			
		}
		
		cout<< cnt << endl;
	}	
	return 0;
}
