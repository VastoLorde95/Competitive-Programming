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

string s;
int n;

int main(){
	cin>>n;
	while(n--){
		cin>>s;
		if(s.length() <= 10){
			cout<< s <<endl;
		}
		else{
			cout<<s[0]<<s.length()-2<<s[s.length()-1]<<endl;
		}
	}
	return 0;
}
