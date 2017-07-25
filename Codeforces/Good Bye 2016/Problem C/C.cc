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

int main(){
	int n;
	cin >> n;
	
	int c[n], d[n];
	
	bool flag = false;
	
	for(int i = 0; i < n; i++){
		cin >> c[i] >> d[i];
		
		if(d[i] == 2) flag = true;
	}
	
	if(!flag){
		cout << "Infinity" << endl;
		return 0;
	}
	
	ll INF = 1ll << 40;
	ll l, r;
	
	if(d[0] == 1){
		l = 1900, r = INF;
	}
	else{
		l = -INF, r = 1899;
	}
	
	for(int i = 0; i + 1 < n; i++){
		if(d[i+1] == 2){
			l += c[i];
			r += c[i];
			
			if(l >= 1900){
				cout << "Impossible" << endl;
				return 0;
			}
			
			r = min(r, 1899ll);
		}
		else{
			l += c[i];
			r += c[i];
			
			if(r <= 1899){
				cout << "Impossible" << endl;
				return 0;
			}
			
			l = max(l, 1900ll);
		}
	}

	l += c[n-1];
	r += c[n-1];

	cout << r << endl;
	
	return 0;
}
