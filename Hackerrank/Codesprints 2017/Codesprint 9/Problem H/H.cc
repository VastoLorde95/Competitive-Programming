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

int b[N];

int main(){ _
	int n, q;
	cin >> n >> q;
	
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}
	
	while(q--){
		int t, l, r, x;
		cin >> t >> l >> r;
		
		if(t == 1){
			cin >> x;
			for(int i = l; i <= r; i++){
				b[i] += x;
			}
		}
		else if(t == 2){
			cin >> x;
			for(int i = l; i <= r; i++){
				if(b[i] >= 0){
					b[i] /= x;
				}
				else{
					b[i] -= (x-1);
					b[i] /= x;
				}
			}
		}
		else if(t == 3){
			int mn = b[l];
			for(int i = l+1; i <= r; i++){
				mn = min(mn, b[i]);
			}
			cout << mn << endl;
		}
		else if(t == 4){
			int sum = b[l];
			for(int i = l+1; i <= r; i++){
				sum += b[i];
			}
			cout << sum << endl;
		}
		
//		for(int i = 0; i < n; i++){
//			cout << b[i] << ' ';
//		}
//		cout << endl;
	}
	
	return 0;
}
