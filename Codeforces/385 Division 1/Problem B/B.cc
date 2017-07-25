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

const int N = 1024;
const int M = 10;

int q[M][N][2];

int ans[N];

int main(){
	int n;
	cin >> n;
	
	for(int i = 0; i < 10; i++){
		if((1<<i) > n) break;
		vector<int> v;
		
		for(int j = 1; j <= n; j++){
			if((j&(1<<i)) > 0){
				v.pb(j);
			}
		}
		
		cout << v.size() << endl;
		foreach(it, v){
			cout << *it << ' ';
		}		
		
		cout << endl;
		fflush(stdout);
		
		for(int j = 1; j <= n; j++){
			cin >> q[i][j][1];
//			cerr << "this     " <<  i << ' ' << j << ' ' <<  q[i][j][0] << endl;
		}
		
		//
		
		v.clear();
		
		for(int j = 1; j <= n; j++){
			if((j&(1<<i)) == 0){
				v.pb(j);
			}
		}
		
		cout << v.size() << endl;
		foreach(it, v){
			cout << *it << ' ';
		}		
		
		cout << endl;
		fflush(stdout);
		
		for(int j = 1; j <= n; j++){
			cin >> q[i][j][0];
		}
	}
	
	for(int i = 1; i <= n; i++){
		ans[i] = 1e9;
		
		for(int j = 0; j < 10 and (1<<j) <= n; j++){
			if((i&(1<<j)) > 0){
//				tr(i,j, q[j][i][0]);
				ans[i] = min(ans[i], q[j][i][0]);
			}
			else ans[i] = min(ans[i], q[j][i][1]);
		}
	}
	
	cout << -1 << endl;
	for(int i = 1; i <= n; i++){
		cout << ans[i] << ' ';
	}	
	cout << endl;
	fflush(stdout);
	
	
	return 0;
}
