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

map<char, int> d;
int n, cnt, l;
string s;

int main(){
	cin>>n;
	cin>>s;
	l = s.length();
	d[s[0]] = 1;
	for(int i = 1; i < l; i++){
		if(i&1){
			char c = (char)(s[i]+32);
			if(d.find(c) == d.end()){
				//cout<< s[i] << " " << c << endl;
				cnt++;
			}
			else{
				//cout<< s[i] << " " << c << endl;
				d[c] -= 1;
				if(d[c] == 0){
					d.erase(c);
				}
			}
		}
		else{
			d[s[i]]++;
		}
	}
	
	cout<< cnt << endl;
	return 0;
}
