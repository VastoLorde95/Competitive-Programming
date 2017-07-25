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
	double s, x1, x2;
	cin >> s >> x1 >> x2;
	
	double t1, t2;
	cin >> t1 >> t2;
	
	double p, d;
	cin >> p >> d;
	
	if(x1 > x2){
		x1 = s - x1;
		x2 = s - x2;
		p = s - p;
		d = -d;
	}

	double ans = (x2 - x1) * t2;
	double off = 0;
	
	if(t1 >= t2){	// if train is slower
		cout << ans << endl;
		return 0;
	}
	
	if(d < 0){
		off = p * t1;
		p = 0;
		d = 1;
		
		x1 += off / t2;
		if(x1 >= x2){
			cout << ans << endl;
			return 0;
		}
	}
	else if(p > x1){
		off = (s - p + s) * t1;
		p = 0;
		d = 1;
		
		x1 += off / t2;
		if(x1 >= x2){
			cout << ans << endl;
			return 0;
		}
	}
	
	double T = (x1 - p) * t2 * t1 / (t2 - t1);
	
	if(x1 + T / t2 >= x2){
		cout << ans << endl;
		return 0;
	}
	
	
	off += T;
	x1 += T / t2;
	
	off += (x2 - x1) * t1;
	
	cout << min(ans, off) << endl;
	
	return 0;
}
