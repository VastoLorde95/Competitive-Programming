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
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n, m, a[100][100];

int main(){
	sd2(n,m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			sd(a[i][j]);
		}
	}
	
	if(n%2 == 1){
		cout << n << endl; return 0;
	}
	
	int ans = n, up = n;
	while(up%2 == 0 and up > 0){
		for(int j = 0; j < up/2; j++){
			for(int k = 0; k < m; k++){
				if(a[j][k] != a[up-j-1][k]){
					cout << up << endl;
					return 0;
				}
			}
		}
		up /= 2;
		if(up == 1){
			cout << up << endl; return 0;
		}
	}
	
	cout << up << endl;
	
	return 0;
}
