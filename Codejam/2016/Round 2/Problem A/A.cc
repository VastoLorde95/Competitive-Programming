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

const int N = 1 << 15;

int n, r, p, s;

int a[N];

// 1 paper
// 2 rock
// 3 scissor

void dfs(int cur, int id, int lvl){
	if(lvl == n+1){
		assert(id >= (1 << n));
		a[id - (1<<n)] = cur;
		return;
	}
	
	if(cur == 1){
		dfs(1, 2*id, lvl+1);
		dfs(2, (2*id)+1, lvl+1);
	}
	else if(cur == 2){
		dfs(2, 2*id, lvl+1);
		dfs(3, (2*id)+1, lvl+1);
	}
	else if(cur == 3){
		dfs(3, (2*id)+1, lvl+1);
		dfs(1, 2*id, lvl+1);
	}
	
}

int tot[4];

bool check(){
	if(tot[1] == p and tot[2] == r and tot[3] == s) return true;
	return false; 
}

string srt(string s){
	if(s.length() == 1) return s;
	int l = s.length();
	string s1 = srt(s.substr(0, l/2));
	string s2 = srt(s.substr(l/2, l/2));
	
	if(s1 < s2) return s1+s2;
	else return s2+s1;
}

void solve(){
	sd2(n,r);
	sd2(p,s);
	
	memset(a, 0, sizeof a);
	
	for(int j = 1; j <= 3; j++){
		dfs(j, 1, 1);
		
		memset(tot, 0, sizeof tot);
	
		for(int i = 0; i < 1<<n; i++){
			tot[a[i]]++;
		}
	
	
		if(check()){
			string tmp;
			for(int i = 0; i < 1<<n; i++){
				if(a[i] == 1) tmp += 'P';
				else if(a[i] == 2) tmp += 'R';
				else if(a[i] == 3) tmp += 'S';
			}
			
			cout << srt(tmp);
			
			puts("");
			return;
		}
	}
	
	printf("IMPOSSIBLE\n");
}


int main(){
	int t;
	sd(t);
	for(int i = 1; i <= t; i++){
		printf("Case #%d: ", i);
		solve();
	}	
	return 0;
}
