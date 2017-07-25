#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<queue>
#include<stack>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n;
long long a[200001], v[200001][2], c[200001][2];

long long cnt(int i, int s, int color){
	if(i == 1) return -1;
	if(c[i][s] == color) return v[i][s] = -1;
	if(v[i][s] != 0) return v[i][s];
	
	c[i][s] = color;
	
	long long ret = 0;
	
	if(s == 0){
		if(i + a[i] > n) return v[i][s] = a[i];
		
		ret = cnt(i+a[i], 1-s, color);
		
		if(ret == -1) return v[i][s] = -1;
		else return v[i][s] = ret + a[i];
	}
	else{
		if(i - a[i] <= 0) return v[i][s] = a[i];
		
		ret = cnt(i-a[i], 1-s, color);
		
		if(ret == -1) return v[i][s] = -1;
		else return v[i][s] = ret + a[i];
	} 
	
}

int main(){ _
	cin >> n;
	for(int i = 2; i <= n; i++){
		cin >> a[i];
	}
	
	for(int i = 2; i <= n; i++){
		if(v[i][1] == 0)
			cnt(i,1,i);
	}
	
	for(int i = 2; i <= n; i++){
		if(v[i][1] == -1) cout << -1 << "\n";
		else cout << v[i][1] + i-1 << "\n";
	}
	
	return 0;
}
