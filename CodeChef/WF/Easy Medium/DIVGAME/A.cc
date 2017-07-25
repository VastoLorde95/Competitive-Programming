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

const int N = 10000;

int p[N+1];

int main(){
	
	for(int i = 2; i < N; i++){
		p[i] = 1;
	}

	vector<int> pr;

	for(int i = 2; i < N; i++){
		if(!p[i]) continue;
		for(int j = i*i; j < N; j += i){
			p[j] = 0;	
		}
		pr.pb(i);
	}
	
	int t;
	cin >> t;
	while(t--){
		int x;
		cin >> x;
		if(x == 2 or x == 17){
			cout << "Mike" << endl;
			continue;
		}
		if(x == 16 or x == 34 or x == 289){
			cout << "Tom" << endl;
			continue;
		}
		
		bool flag = false;
		for(int &y : pr){
			if(x != y and x % y == 0){
				flag = true;
			}
		}
		
		if(flag) cout << "Mike" << endl; else cout << "Tom" << endl;
	}
	
	return 0;
}
