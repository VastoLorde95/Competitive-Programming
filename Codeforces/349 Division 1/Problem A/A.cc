#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(__typeof((v).begin()) it=(v).begin(); it != (v).end(); ++it)
#define meta __FUNCTION__,__LINE__

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

using namespace std;

const long double PI = 3.1415926535897932384626433832795;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;
typedef pair<int,int> pii;

const int N = 10010;

set<string> r;

int dp[N][2];
string s;
int v[N];

void go(int i){
	if(i == s.length()) return;
	if(v[i]) return;
	v[i] = 1;
	
	for(int j = 0; j < 2; j++){
		if(dp[i][j]){
			r.insert(s.substr(i,j+2));
			go(i+j+2);
		}
	}
	
}

int main(){ _
	cin >> s;
	
	int l = s.length();
	
	if(s.length() <= 5){
		cout << 0 << endl;
		return 0;
	}

	dp[l][0] = dp[l][1] = 1;
	
	for(int i = l-2; i > 4; i--){
		if(dp[i+2][1]){
			dp[i][0] = 1;
		}
		else if(dp[i+2][0]){
			if(i+2 == l){
				dp[i][0] = 1;
			}
			else if(s.substr(i+2,2) != s.substr(i,2)){
				dp[i][0] = 1;
			}
		}
		if(dp[i+3][0]){
			dp[i][1] = 1;
		}
		else if(dp[i+3][1]){
			if(i+3 == l){
				dp[i][1] = 1;
			}
			else if(s.substr(i,3) != s.substr(i+3,3)){
				dp[i][1] = 1;
			}
		}
	}
	
	
	for(int i = 5; i < l; i++){
		if(dp[i][0] and !v[i]){
			go(i);
		}
		if(dp[i][1] and !v[i]){
			go(i);
		}	
	}
	
	tr(r.size());
	foreach(it, r) tr(*it);
	
		
	return 0;
}
