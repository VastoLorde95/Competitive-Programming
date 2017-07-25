	#include <bits/stdc++.h>

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
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define func __FUNCTION__
#define line __LINE__

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.fi<<", "<<p.se<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
int l = v.size(); for(int i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;
typedef pair<int,int> pii;

const int N = 100100;

int l;
string num;
vector<int> n;

int dp[N][2][2];
pii v[N][2][2];

int go(int x, int y, int s, int t){
	if(dp[x][s][t] != -1) return dp[x][s][t];
	
	if(x+1 == y){
		for(int i = 0; i < 10; i++){
			for(int j = 0; j < 10; j++){
				int d1 = i+j+s, d2 = i+j+t;
				if(d1%10 != n[x] or d1/10 != s or d2%10 != n[y] or d2/10 != s) continue;
				if(x == 0 and i == 0) continue;
				
				v[x][s][t] = mp(i,j);
				return dp[x][s][t] = 1;
			}
		}
		return dp[x][s][t] = 0;
	}
	
	if(x == y){
		for(int i = 0; i < 10; i++){
			int d = i+i+t;
			if(d%10 != n[x] or d/10 != s) continue;
			if(x == 0 and i == 0) continue;
			
			v[x][s][t] = mp(i,i);
			return dp[x][s][t] = 1;
		}
		return dp[x][s][t] = 0;
	}
	
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			int d1 = i+j, d2 = i+j+t;
			
			if(d2%10 != n[y]) continue;
			if(x == 0 and i == 0) continue;
			
			int ns = 0, nt = 0;
			if(d1%10 == n[x] and d1/10 == s) ns = 0;
			else if((d1+1)%10 == n[x] and (d1+1)/10 == s) ns = 1;
			else continue;
			
			nt = d2/10;
			
			if(go(x+1,y-1,ns,nt)){
				v[x][s][t] = mp(i,j);
				return dp[x][s][t] = 1;
			}
		}
	}
	return dp[x][s][t] = 0;
}

char tochar(int x){
	return (char)('0'+x);
}

char ans[N];

void build(int x, int y, int s, int t){
	if(x > y) return;
	
	int d1 = v[x][s][t].fi;
	int d2 = v[x][s][t].se;
	ans[x] = tochar(d1);
	ans[y] = tochar(d2);
	
	int ns = ((d1+d2+1)%10 == n[x]);
	int nt = ((d1+d2+t)/10);
	
	build(x+1,y-1,ns,nt);
	
}

int main(){ _
	cin >> num;

	l = num.length();
	
	for(int i = 0; i <= l; i++){
		for(int s = 0; s < 2; s++){
			for(int k = 0; k < 2; k++){
				dp[i][s][k] = -1;
			}
		}
	}
	
	for(int i = 0; i < l; i++){
		n.pb(num[i]-'0');
	}
	
	if(go(0,l-1,0,0)){
		build(0,l-1,0,0);
		for(int i = 0; i < l; i++){
			cout << ans[i];
		}
		cout << endl;
		
		return 0;
	}
	
	if(n[0] == 1 and go(1,l-1,1,0)){
		build(1,l-1,1,0);
		for(int i = 1; i < l; i++){
			cout << ans[i];
		}
		cout << endl;
		return 0;
	}
	
	cout << 0 << endl;
	
	return 0;
}
