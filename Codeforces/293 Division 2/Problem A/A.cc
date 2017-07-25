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
	string s, t;
	int l, i = 0, j;
	char c, d;
	cin>>s;
	cin>>t;
	l = s.length();

	while(i < l and s[i] == t[i]) i++;
	c = s[i];
	c = (char)(c + 1);
	if(c != t[i]){
		s[i] = c;
		cout<<s<<endl;
		return 0;
	}
	else{
		i++; j = i;
		while(j < l and s[j] == 'z') j++;
		
		if(j < l){
			d = s[j];
			d = (char)(d + 1);
			s[j] = d;
			cout<<s<<endl;
			return 0;
		}
		
		s[i-1] = c;
		while(i < l){
			if(s[i] == t[i] and s[i] > 'a'){
				s[i] = 'a';
				cout<< s <<endl;
				return 0;
			}
			else if(s[i] < t[i]){
				cout<< s <<endl;
				return 0;
			}
			else if(s[i] > t[i] and t[i] > 'a'){
				s[i] = 'a';
				cout<< s <<endl;
				return 0;
			}
			else if(s[i] > t[i] and t[i] == 'a'){
				s[i] = 'a';
			}
			i++;
		}
		
		cout<<"No such string"<<endl;
	}	
	
	
	return 0;
}
