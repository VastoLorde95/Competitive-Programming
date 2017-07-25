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

const int N = 1001;
int sieve[N], primes[N], pcnt;

void getSieve(){
	for(int i = 2; i < N; i++){
		if(sieve[i] == 0){
			sieve[i] = i; primes[pcnt++] = i;
		}
		for(int j = 0; j < pcnt and primes[j] <= sieve[i] and i*primes[j] < N; j++) sieve[i*primes[j]] = primes[j];
	}
	return;
}

const int M = 1001;

int a[M];
int taken[M];

bool comp(const vector<int> &u, const vector<int> &v){
	return u.size() < v.size();
}

void solve(){
	int n;
	sd(n);
	for(int i = 0; i < n; i++){
		sd(a[i]);
	}
	
	memset(taken, 0, sizeof taken);
	
	vector<vector<int> > v;
	for(int i = 0; i < n; i++){
		set<int> s;
		int num = a[i];
		while(num > 1){
			s.insert(sieve[num]);
			num /= sieve[num];
		}
		vector<int> t;
		foreach(it, s) t.pb(*it);
		v.pb(t);
	}
	
	sort(v.begin(), v.end(), comp);
	
	int ans = 0;
	for(int i = 0; i < v.size(); i++){
		bool ok = true;
		foreach(it, v[i]){
			if(taken[*it]) ok = false;
		}
		if(ok){
			foreach(it, v[i]) taken[*it] = 1;
			ans++;
		}
	}
	
	tr(ans);
	
}

int main(){
	getSieve();
	int t; sd(t);
	while(t--) solve();
	return 0;
}
