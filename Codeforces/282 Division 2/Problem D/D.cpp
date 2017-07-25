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

int n, m, MOD = 1000000007, a[100001], q1[100001], q2[100001], fail[100001], found[100001];
string s, t;
//fail is the failure function of the KMP algorithm

void kmp(){
	int i, j, k;
	
	//Build the failure function
	j = fail[0] = -1;
	for(i = 1; i <= m; i++){
		while(j >= 0 and t[j] != t[i-1]) j = fail[j];
		
		fail[i] = j+1;
		j++;
	}

	//preform kmp to match the string	
	i = 0, j = 0, k = 0;
	for(; i < n; i++){
		while(k >= 0 and t[k] != s[i]) k = fail[k];
		
		if(++k >= m){//found
			k = fail[k];
			found[i] = 1;
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin>>s;
	cin>>t;
	n = s.length(), m  = t.length();
	//cout<<s<<endl;
	//cout<<t<<endl;
	kmp();
	int i;
	for(i = 0; i < m-1; i++){
		a[i] = q1[i] = q2[i] = 0;
	}
	if(m == 1 and s[0] == t[0]){
		a[0] = q1[0] = q2[1] = 1;
	}
	for(; i <= n; i++){
		if(found[i-1] == 0){
			a[i] = a[i-1];
		}
		else{
			a[i] = (q2[i-m] + i - m + 1)%MOD;
		}
		q1[i] = (a[i] + q1[i-1])%MOD;
		q2[i] = (q2[i-1] + q1[i])%MOD;
	}
	cout<<q1[n]<<endl;
	return 0;
}	
