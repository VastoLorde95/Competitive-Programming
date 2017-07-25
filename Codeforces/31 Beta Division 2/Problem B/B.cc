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

int l, flag, len;

string s;	
string res;

int main(){
	cin>>s;
	
	if(s[0] == '@'){
		cout << "No solution\n" << endl;
		return 0;
	}
	
	l = s.length();
	for(int i = 0; i < l; i++){
		while(i < l and s[i] != '@'){
			res += s[i];
			len++;
			i++;
		}
		
		if(i < l and s[i] == '@'){
			res += s[i];
			len++;
			flag = 1;
		}
		
		if(flag == 0){
			cout << "No solution\n" << endl;
			return 0;
		}
		
		//cout<< res << endl;
		i++;
		
		for(; i < l; i++){
			if(s[i] != '@'){
				res += s[i];
				len++;
			}
			else{
				if(s[i-1] != '@' and s[i-2] != '@'){
					res[len-1] = ',';
					res += s[i-1];
					res += s[i];					
					len += 2;
				}
				else{
					cout << "No solution\n" << endl;
					return 0;
				}
			}
		}	
	}
	
	if(s[len-1] == '@'){
		cout << "No solution\n" << endl;
		return 0;
	}
	
	cout << res << endl;
	
	return 0;
}
