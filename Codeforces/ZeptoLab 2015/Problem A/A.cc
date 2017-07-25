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

int n;
string s;

int main(){
	cin>>n;
	cin>>s;
	for(int j = 1; j < n; j++){
		for(int i = 0; i < n; i++){
			if(i < n and i+j < n and i+j+j < n and i+j+j+j < n and i+j+j+j+j < n)
				if(s[i] == '*' and s[i+j] == '*' and s[i+j+j] == '*' and s[i+j+j+j] == '*' and s[i+j+j+j+j] == '*'){
					cout<< "yes" << endl;
					return 0;
				}
		}
	}
	
	cout << "no" << endl;
	return 0;
}
