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

const int N = 400;

int n;
string s;

set<char> res;
int dp[N][N][N];

void go(int a, int b, int c){
	if(dp[a][b][c]) return;
	dp[a][b][c] = 1;

	if(a + b + c == 1){
		if(a == 1) res.insert('R');
		else if(b == 1) res.insert('G');
		else res.insert('B');
		return;
	}
	
	if(a > 0 and b > 0) go(a-1, b-1, c+1);
	if(a > 0 and c > 0) go(a-1, b+1, c-1);
	if(b > 0 and c > 0) go(a+1, b-1, c-1);
	if(a > 1) go(a-1, b, c);
	if(b > 1) go(a, b-1, c);
	if(c > 1) go(a, b, c-1);
}

int main(){
	cin >> n >> s;
	
	int r = 0, g = 0, b = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == 'R') r++; else if(s[i] == 'G') g++; else b++;
	}	
	
	go(r,g,b);
	
	foreach(it, res) cout << *it;
	cout << endl;
	
	return 0;
}
