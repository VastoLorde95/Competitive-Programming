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

void solve(){
	int n, p;
	cin >> n >> p;
	
	map<int, int> f;
	
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		x %= p;
		f[x]++;
	}
	
	int ans = f[0];
	if(p == 2){
		ans += (f[1]+1)/2;
	}
	else if(p == 3){
		int mn = min(f[1], f[2]);
		ans += mn;
		f[1] -= mn;
		f[2] -= mn;
		
		ans += (f[1] + 2) / 3;
		ans += (f[2] + 2) / 3;
	}
	else{
		int mn = min(f[1], f[3]);
		ans += mn;
		
		f[1] -= mn;
		f[3] -= mn;
		
		int b = max(f[1], f[3]);
		int a = f[2];
		
		int mx = 0;
		for(int i = 0; i <= min(a, b/2); i++){
			int f = a - i;
			int g = b - 2 * i;
			
			int val = 0;
			if(f % 2 == 0){
				int tmp = i;
				tmp += f/2;
				tmp += (g+3)/4;
				val = max(val, tmp);
			}
			else{
				int tmp = i;
				tmp += (f+1)/2;
				
				if(g >= 2){
					g -= 2;
					tmp += (g + 3) / 4;
				}
				
				val = max(val, tmp);
			}

			int tmp = i;
			tmp += (g + 3) / 4;
			
			int rem = (g * 3) % 4;
			if(rem  == 0){
				tmp += (f + 1) / 2;
			}
			
			val = max(val, tmp);
			
			mx = max(mx, val);
		}
		
		ans += mx;
	}
	
	cout << ans << endl;
	
}

int main(){ _
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}

