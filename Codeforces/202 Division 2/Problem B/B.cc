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

int v, mn = 1000000000, ind;
string res;
int d[10];

int main(){
	sd(v);
	for(int i = 1; i <= 9; i++){
		sd(d[i]);
		if(d[i] <= mn){
			mn = d[i];
			ind = i;
		}
	}
	
	for(int i = 1; i <= v/mn; i++){
		res += (char)(ind+48);
	}
	
	v %= mn;
	
	for(int i = 0; i < res.length(); i++){
		for(int j = 9; j > ind; j--){
			if( v-d[j]+d[res[i]-48] >= 0){
				v = v-d[j]+d[res[i]-48];
				res[i] = (char)(j+48);
				break;
			}
		}
	}
	
	if(res.length() == 0) cout<<-1<<endl;
	else cout<< res << endl;
	
	return 0;
}
