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

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

using namespace std;	

int main(){
	int n, m;
	map<string, string> words;
	string a, b;
	sd2(n,m);
	for(int i = 0; i < m; i++){
		cin>>a>>b;
		if(a.length() <= b.length()){
			words[a] = a;
		}
		else{
			words[a] = b;
		}
	}
	
	for(int i = 0; i < n; i++){
		cin>>a;
		cout<<words[a]<<" ";
	}
	cout<<endl;
	return 0;
}
