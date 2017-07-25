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

long long sum[100000], total;
map<long long, long long> sums;
int vals[26], l, prev;
string s;

int main(){
	for(int i = 0; i < 26; i++){
		sd(vals[i]);
	}
	cin>>s;
	l = s.length();
	for(int i = 0; i < l; i++){
		sum[i] = (i > 0)? sum[i-1] + vals[s[i]-'a']: vals[s[i]-'a'];
	}
	for(int i = 0; i < 26; i++){
		sums.clear();
		int temp = 0;
		while(temp < l and s[temp] != (char)(i+'a')) temp++;
		if(temp == l) continue;
		sums[sum[temp]] = 1;
		for(int j = temp + 1; j < l; j++){
			if(s[j] == (char)(i+'a')){
				total += sums[sum[j-1]];
				sums[sum[j]]++;
			}
		}
		
	}
	cout<< total <<endl;
	return 0;
}
