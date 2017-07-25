#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

using namespace std;

typedef unsigned long long ll;
typedef long double ld;
typedef pair<int,int> pii;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

const ld PI = 3.1415926535897932384626433832795;

const int B = 333;
const int N = 100100;

ll n;
ll BLOCK;

ll a[N];

ll l[N], r[N];
ll freq[B][N];	// freq[i][j] = number of segments in block i that contain point j

ll sum1[B][B];
ll sum2[B];

ll qsum1[B];

#define bs(x) (BLOCK*((x)-1)+1)
#define be(x) (min((BLOCK*(x)),n))

void preprocess(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> l[i] >> r[i];
	
	BLOCK = sqrt(n) + 1;
	
	for(int i = 1; i <= BLOCK; i++){
		int start = bs(i);
		int end = min(be(i), n);
		
		for(int j = start, k = 1; j <= end; j++, k++){
			sum1[i][k] = sum1[i][k-1] + a[j];
		}
		
		sum2[i] = sum2[i-1] + sum1[i][end-start+1];
	}
	
	for(int i = 1; i <= BLOCK; i++){
		int start = bs(i);
		int end = min(be(i), n);
		
		for(int j = start; j <= end; j++){
			freq[i][l[j]]++;
			freq[i][r[j]+1]--;
		}
		
		for(int j = 1; j <= n; j++){
			freq[i][j] += freq[i][j-1];
			qsum1[i] += a[j] * freq[i][j];
		}
	}
}

void update(int x, ll y){
	int curb = (x + BLOCK - 1) / BLOCK;
	int endb = (n + BLOCK - 1) / BLOCK;
	
	ll del = y - a[x];
	a[x] = y;
	
	for(int i = curb; i <= endb; i++){
		sum2[i] += del;
	}
	
	int k = x - bs(curb) + 1;
	int lim = be(curb);
	for(int i = x; i <= lim; i++, k++){
		sum1[curb][k] += del;
	}
	
	for(int i = 1; i <= endb; i++){
		qsum1[i] += del * freq[i][x];
	}
}

ll get(int x){
	int b = (x + BLOCK - 1) / BLOCK;
	return sum2[b-1] + sum1[b][x - bs(b) + 1];
}

ll query(int x, int y){
	ll ans = 0;
	if(y - x + 1 <= BLOCK){
		for(int i = x; i <= y; i++){
			ans += get(r[i]) - get(l[i]-1);
		}
		return ans;
	}
	
	int xblock = (x + BLOCK-1) / BLOCK;
	int yblock = (y + BLOCK-1) / BLOCK;
	
	for(int i = xblock+1; i < yblock; i++){
		ans += qsum1[i];
	}
	
	int xbe = be(xblock);
	int ybb = bs(yblock);
	
	for(int i = x; i <= xbe; i++){
		ans += get(r[i]) - get(l[i]-1);
	}
	
	for(int i = ybb; i <= y; i++){
		ans += get(r[i]) - get(l[i]-1);
	}
	
	return ans;
}

int main(){ _
	preprocess();
	
	int q;
	cin >> q;
	while(q--){
		int t, x, y;
		cin >> t >> x >> y;
		if(t == 1){
			update(x, y);
		}
		else{
			ll ans = query(x, y);
			cout << ans << '\n';
		}
	}
	
	return 0;
}
