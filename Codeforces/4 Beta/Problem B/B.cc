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

int d, s, t[30][2], s1, s2, res[30], s3;

int main(){
	sd2(d, s);
	for(int i = 0; i < d; i++){
		sd2(t[i][0], t[i][1]);
		s1 += t[i][0]; s2 += t[i][1];
	}
	
	if(s1 > s or s2 < s){
		cout<<"NO\n";
		return 0;
	}
	
	for(int i = 0; i < d; i++){
		s3 += t[i][0];
	}
	
	
	int i = 0;
	while(s3 != s){
		if(t[i][0] < t[i][1]){
			s3++;
			t[i][0]++;
		}
		else{
			res[i] = t[i][0];
			i++;
		}
	}
	while(i < d){
		res[i] = t[i][0];
		i++;
	}
	cout<<"YES\n";
	for(int i = 0; i < d; i++){
		cout<<res[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}
