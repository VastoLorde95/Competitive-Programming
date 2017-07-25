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

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

string s1, s2, v, res;

int dp[101][101][101];
int go[101][26];
int prev[101][101][101];

int l1, l2, l3;

void process(){
	for(int i = 0; i < l3; i++){
		for(int j = 0; j < 26; j++){
			char c = j + 'A';
			int l = i+1;
			while(l){
				if(c != v[l-1]){
					l--; continue;
				}
				
				bool flag = true;
				
				for(int k = 0; k < l-1; k++){
					if(v[l-2-k] != 	v[i-1-k]){
						flag = false;
						break;
					}
				}
				
				if(flag) break;
				
				l--;
			}
			
			go[i][j] = l;
		}
	}
}

string solve(){
	for(int i = 0; i <= l1; i++){
		for(int j = 0; j <= l2; j++){
			for(int k = 0; k <= l3; k++){
				dp[i][j][k] = -1;
			}
		}	
	}	
	
	dp[0][0][0] = 0;
	
	for(int i = 0; i <= l1; i++){
		for(int j = 0; j <= l2; j++){
			for(int k = 0; k < l3; k++){
				if(dp[i][j][k] == -1) continue;
				
				if(i < l1 and dp[i+1][j][k] < dp[i][j][k]){
					dp[i+1][j][k] = dp[i][j][k];
					prev[i+1][j][k] = -1;
				}
				
				if(j < l2 and dp[i][j+1][k] < dp[i][j][k]){
					dp[i][j+1][k] = dp[i][j][k]; 
					prev[i][j+1][k] = -2;
				}
				
				
				if(i < l1 and j < l2 and s1[i] == s2[j]){
					int l = go[k][s1[i]-'A'];
					if(l < l3 and dp[i+1][j+1][l] < dp[i][j][k] + 1){
						dp[i+1][j+1][l] = dp[i][j][k]+1;
						prev[i+1][j+1][l] = k;
					}
				}
			}
		}
	}
	
	
	int mx = 0, k = 0;
	for(int i = 0; i <= l3; i++){
		if(dp[l1][l2][i] > mx){
			k = i;
			mx = dp[l1][l2][i];
		}
	}
	
	if(mx == 0) return "0";
	
	for(int i = l1, j = l2; i > 0 or j > 0;){
		int val = prev[i][j][k];
		if(val >= 0 or val == -1) i--;
		if(val >= 0 or val == -2) j--;
		if(val >= 0){
			res = s1[i] + res;
			k = val;
		}
	}
	
	return res;
}

int main(){ _

	cin >> s1 >> s2 >> v;
	
	l1 = s1.length();
	l2 = s2.length();
	l3 = v.length();
	
	process();
	
	cout << solve() << endl;
	
	return 0;
}
