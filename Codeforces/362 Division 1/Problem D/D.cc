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

const int N = 210, M = 26;
const ll INF = 1ll << 60;

bitset<N> suff[N];

struct Matrix{
	int n;
	vector<vector<ll> > m;
	Matrix(int nn = 0, bool id = false){
		n = nn;
		m.resize(n);
		for(int i = 0; i < n; i++) m[i].resize(n, -INF);
		
		if(id) for(int i = 0; i < n; i++) m[i][i] = 0;
	}
	
	vector<ll>& operator[](int i){return m[i];}
	
	int size(){return n;}
};

Matrix operator*(Matrix &A, Matrix &B){
	int n = A.size();
	Matrix C(n);
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; k < n; k++)
				C[i][j] = max(C[i][j], A[i][k] + B[k][j]);
	return C;
}

Matrix fast(Matrix A, ll b){
	Matrix ret(N, true);
	while(b){
		if((b&1)) ret = ret * A;
		A = A * A;
		b >>= 1;
	}
	return ret;
}

int a[N];

struct AhoCorasick{
	vector<vector<int> > tree;
	vector<int> f;
	int ncnt;
	queue<int> q;
	
	AhoCorasick(vector<vector<int> > &w){
		f.resize(N, -1);
		tree.resize(N); for(int i = 0; i < N; i++) tree[i].resize(M, -1);
		ncnt = 1;
		for(int j = 0; j < w.size(); j++){
			vector<int> &v = w[j];
			int cur = 0;
			for(int i = 0; i < v.size(); i++){
				if(tree[cur][v[i]] == -1) tree[cur][v[i]] = ncnt++;
				cur = tree[cur][v[i]];
			}
			suff[cur][j] = 1;
		}

		for(int i = 0; i < M; i++){
			if(tree[0][i] == -1)
				tree[0][i] = 0;
			else{
				f[tree[0][i]] = 0;
				q.push(tree[0][i]);
			}
		}

		while(!q.empty()){
			int cur = q.front(); q.pop();
			suff[cur] |= suff[f[cur]];
			
			for(int i = 0; i < M; i++){
				if(tree[cur][i] == -1)
					tree[cur][i] = tree[f[cur]][i];
				else{
					f[tree[cur][i]] = tree[f[cur]][i];
					q.push(tree[cur][i]);
				}
			}
		}
	}
	
	Matrix buildMatrix(){
		Matrix ret(N, true);
		vector<ll> wt(N);
		
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				if(suff[i][j]) wt[i] += a[j];
		
		for(int i = 0; i < ncnt; i++){
			for(int j = 0; j < M; j++){
				int k = tree[i][j];
				assert(k >= 0 and k < N);
				ret[i][k] = max(ret[i][k], wt[k]);
			}
		}
		
		return ret;
	}
};

int n; ll l;

int main(){ _
	cin >> n >> l;
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
		
	vector<vector<int> > w;
	for(int i = 0; i < n; i++){
		vector<int> v;
		string s; cin >> s;
		for(char &c : s) v.pb(c-'a');
		w.pb(v);
	}

	Matrix m = AhoCorasick(w).buildMatrix();
	
	m = fast(m, l);
	
	ll ans = 0;
	for(int i = 0; i < N; i++) ans = max(ans, m[0][i]);
	
	cout << ans << endl;
	
	return 0;
}
