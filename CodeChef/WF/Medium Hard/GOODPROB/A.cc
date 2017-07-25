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

typedef long long ll;
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

const int N = 100100;

const int M = 20;
const int B = 7;

vector<int> sup[1 << B];
vector<int> sub[1 << B];

int n;
int a[N], l[N], r[N];
vector<int> posi[1 << (2*B)];
map<pii, int> maxpos;
ll ans;
stack<int> s;

void pre(){
	for(int mask = 0; mask < 1 << B; mask++)
		for(int i = 0; i < 1 << B; i++){
			if((mask & i) == mask) sup[mask].pb(i);
			if((mask & i) == i) sub[mask].pb(i);
		}
}

void getLR(){
	for(int i = 1; i <= n; i++) posi[a[i]].pb(i);

	l[1] = 0;
	s.push(1);
	for(int i = 2; i <= n; i++){
		while(!s.empty() and a[s.top()] < a[i]) s.pop();
		l[i] = (s.empty())? 0 : s.top();
		s.push(i);
	}
	
	while(!s.empty()) s.pop();
	
	r[n] = n+1;
	s.push(n);
	for(int i = n-1; i ; i--){
		while(!s.empty() and a[s.top()] <= a[i]) s.pop();
		r[i] = (s.empty())? n+1 : s.top();
		s.push(i);
	}
	
	for(int i = 1; i <= n; i++) maxpos[mp(l[i], r[i])] = i;
}

bool isFree[M];
int dp1[M][1 << B][1 << B];
int dp2[M][1 << B][1 << B];

int solve(int l, int r){
	if(l + 1 == r) return M-1;
	
	if(r - l - 1 == 1){
		int memmid = -1;
		for(int i = 0; i < M; i++){
			if(isFree[i] == 0){
				isFree[i] = 1, memmid = i;
				break;
			}
		}
		
		int num = a[l+1];
		int high = num >> B;
		int low = num & ((1 << B) - 1);
		
		for(int s : sub[low]) dp1[memmid][high][s]++;	// super(s) = low
		for(int s : sup[low]) dp2[memmid][high][s]++;	// sub(s) = low
	
		return memmid;	
	}
	
	int pos = maxpos[mp(l,r)];
	int sz1 = pos - l - 1;
	int sz2 = r - pos - 1;
	
	int m1, m2;

	if(sz1 >= sz2) m1 = solve(l, pos), m2 = solve(pos, r);
	else m2 = solve(pos, r), m1 = solve(l, pos);

	ll num = a[pos];
	
	int high = num >> B;
	int low = num & ((1 << B) - 1);
	
	ll cnt = 0;
	int ret;

	for(int s : sup[high]) cnt += dp1[m1][s][low];
	for(int s : sub[high]) cnt += dp2[m1][s][low];

	int rem = lower_bound(posi[num].begin(), posi[num].end(), pos) - upper_bound(posi[num].begin(), posi[num].end(), l);
	cnt -= rem;

	for(int s : sup[high]) cnt += dp1[m2][s][low];
	for(int s : sub[high]) cnt += dp2[m2][s][low];
	
	rem = lower_bound(posi[num].begin(), posi[num].end(), r) - upper_bound(posi[num].begin(), posi[num].end(), pos);
	cnt -= rem;
	
	if(sz1 <= sz2){	// combine left into right
		for(int i = l+1; i < pos; i++){
			int high = a[i] >> B;
			int low = a[i] & ((1 << B) - 1);
			
			for(int s : sup[high]) cnt += dp1[m2][s][low];
			for(int s : sub[high]) cnt += dp2[m2][s][low];
			
			int sub = 0;
			sub += (lower_bound(posi[a[i]].begin(), posi[a[i]].end(), r) - posi[a[i]].begin());
			sub -= (upper_bound(posi[a[i]].begin(), posi[a[i]].end(), pos) - posi[a[i]].begin());
			cnt -= sub;
		}
			
		
		for(int i = l+1; i < pos; i++){
			int high = a[i] >> B;
			int low = a[i] & ((1 << B) - 1);
			
			for(int s : sup[low]) dp2[m2][high][s] += dp2[m1][high][s], dp2[m1][high][s] = 0;
			for(int s : sub[low]) dp1[m2][high][s] += dp1[m1][high][s], dp1[m1][high][s] = 0;
		}
		
		isFree[m1] = 0;
		ret = m2;
	}
	else{	// combine right into left
		for(int i = pos+1; i < r; i++){
			int high = a[i] >> B;
			int low = a[i] & ((1 << B) - 1);
			
			for(int s : sup[high]) cnt += dp1[m1][s][low];
			for(int s : sub[high]) cnt += dp2[m1][s][low];
			
			int sub = 0;
			sub += (lower_bound(posi[a[i]].begin(), posi[a[i]].end(), pos) - posi[a[i]].begin());
			sub -= (upper_bound(posi[a[i]].begin(), posi[a[i]].end(), l) - posi[a[i]].begin());
			cnt -= sub;
		}
		
		for(int i = pos+1; i < r; i++){
			int high = a[i] >> B;
			int low = a[i] & ((1 << B) - 1);
			for(int s : sup[low]) dp2[m1][high][s] += dp2[m2][high][s], dp2[m2][high][s] = 0;
			for(int s : sub[low]) dp1[m1][high][s] += dp1[m2][high][s], dp1[m2][high][s] = 0;
		}
			
		isFree[m2] = 0;
		ret = m1;
	}
	
	for(int s : sub[low]) dp1[ret][high][s]++;
	for(int s : sup[low]) dp2[ret][high][s]++;
	
	ans += cnt * num;
	return ret;
}

int main(){ _
	pre();
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	getLR();
	
	solve(0, n+1);
	
	cout << ans << '\n';
	
	return 0;
}
