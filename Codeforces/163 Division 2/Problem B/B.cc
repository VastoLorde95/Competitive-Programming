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

int t, n;
string s;

int main(){
	cin>>n>>t;
	cin>>s;
	for(int i = 0; i < t; i++){
		for(int j = 1; j < n; j++){
			if(s[j] == 'G' and s[j-1] == 'B'){
				swap(s[j], s[j-1]);
				j++;
			}	
		}
	}
	
	cout<< s <<endl;
	
	return 0;
}
