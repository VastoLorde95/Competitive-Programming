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

#define no cout<<"NO"<<endl;
#define yes cout<<"YES"<<endl;

int main(){ _
	int n;
	cin >> n;
	
	int lo = 1e9, hi = 1;
	
	vector<int> v;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		v.pb(x);
		
		lo = min(lo, x);
		hi = max(hi, x);
	}

	int len = hi - lo + 1;
	if(2 * len - 2 > n){
		no;
		return 0;
	}
	
	map<int, int> f;
	for(int x : v){
		x -= lo;
		x++;
		f[x]++;
	}
	
	hi -= lo;
	hi++;
	lo = 1;
	
	for(int i = 1; i <= hi; i++){
		f[i]--;
		if(f[i] < 0){
			no;
			return 0;
		}
	}
	for(int i = 2; i < hi; i++){
		f[i]--;
		if(f[i] < 0){
			no;
			return 0;
		}
	}
	
	for(int i = hi; i > 1; i--){
		while(f[i] > 0){
			tr(i);
			if(f[i-1] == 0){
				no;
				return 0;
			}
			tr(i);
		
			int tmp = i-1;
			while(tmp >= 1 and f[tmp] >= 2){
				tmp--;
			}
			
			if(f[tmp] == 0) tmp++;
			
			for(int j = i-1; j > tmp; j--){
				f[j]--;
			}
			for(int j = tmp; j <= i; j++){
				f[j]--;
			}
		}
	}
	
	for(int i = 1; i <= hi; i++){
		if(f[i]){
			no;
			return 0;
		}
	}
	
	yes;
	
	return 0;
}
