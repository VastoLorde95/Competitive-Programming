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

const int N = 600;

string s[2];
int g[N];

void solve(){
	int n;
	cin >> n;
	
	cin >> s[0];
	cin >> s[1];
	
	bool ok = false;
	for(int i = 0; i < n; i++){
		g[i] = (s[0][i] == '#') + (s[1][i] == '#') * 2;
		ok |= (g[i] > 0);
	}

	if(!ok){
		cout << "no" << endl;
		return;
	}	
	
	int state = -1;
	
	for(int i = 0; i < n; i++){
		if(g[i] == 0){
			if(state != -1){
				state = -2;
			}
		}
		else{
			if(state == -2){
				ok = false;
				break;
			}
			else if(state == -1){
				state = g[i];
			}
			else{
				if(state == 3){
					state = g[i];
				}
				else if(state == 1){
					if(g[i] == 2){
						ok = false;
						break;
					}
					else if(g[i] == 1) continue;
					else state = 2;
				}
				else if(state == 2){
					if(g[i] == 1){
						ok = false;
						break;
					}
					else if(g[i] == 2) continue;
					else state = 1;
				}
			}
		}
	}
	
	cout << (ok ? "yes" : "no") << endl;
	
}

int main(){ _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
