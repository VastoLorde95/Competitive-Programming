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

int main(){
	char s[100005];
	cin >> s;
	int l = strlen(s), flag = 0, a, c = s[l-1] - 48, pos;
	for(int i = l-2; i >= 0; i--){
		a = s[i] - 48;
		if( a%2 == 0){
			flag = 1;
			pos = i;
			break;
		}
	}
	if(flag == 0){
		cout<< -1 <<endl;
	}
	else{
		for(int i = pos - 1; i >= 0; i--){
			a = s[i] - 48;
			if(a%2 == 0 and a < c){
				pos = i;
			}	
		}
		char temp = s[l-1];
		s[l-1] = s[pos];
		s[pos] = temp;
		int i = 0; 
		while(i < l){
			if(s[i] == '0') i++;
			else break;
		}
		while(i < l){
			cout<<s[i];
			i++;
		}
		cout<<endl;
	}
	return 0;
}
