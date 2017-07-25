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

const int N = 4000;

int p[N];
vector<int> pr;

int find(int x){
	map<int, int> f;
	
	int tmp = x;
	for(int &y : pr){
		if(tmp % y != 0) continue;
		
		int cnt = 0;
		
		while(tmp % y == 0){
			cnt++;
			tmp /= y;
		}
		
		f[y] = cnt; 
	}
	if(tmp > 1) f[tmp] = 1;
	
	int lo = 0, hi = 1000*1000*10, mid;
	
	while(lo + 1 < hi){
		mid = (lo + hi) / 2;
		
		bool flag = true;
		
		foreach(it, f){
			int y = it->fi, req = it->se;
			
			ll cur = y;
			int cnt = 0;
			
			while(cur <= mid){
				cnt += mid / cur;
				cur *= y;
			}
			
			if(cnt < req){
				flag = false;
				break;
			}
		}
		
		if(flag) hi = mid;
		else lo = mid;
	}
	
	return hi;
	
}

int main(){ _
	for(int i = 2; i < N; i++){
		if(p[i]) continue;
		for(int j = 2*i; j < N; j += i){
			p[j] = 1;
		}
		
		pr.pb(i);
	}
	
	int a, b;
	cin >> a >> b;
	
	if(a == b){
		cout << 0 << endl;
		return 0;
	}
	
	cout << max(find(b) - find(a), 0) << endl;
	
	return 0;
}
