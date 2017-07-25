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

ll p[15];

ll get(ll x, ll y){
	int len = 0;
	ll tx = x;
	while(tx){
		tx /= 10;
		len++;
	}
	
	return x / p[len-y];
	
}

ll f(ll x){
	if(x <= 100) return 0;
	
	int len = 0;
	
	ll tx = x;
	while(tx){
		tx /= 10;
		len++;
	}

	tx = x;
	vector<int> dig;
	while(tx){
		dig.pb(tx%10);
		tx /= 10;
	}
	
	ll ret = 0;
	
	for(int d = 3; d <= len; d++){
		if(d == len){
			for(int i = 1; i <= 9; i++){
				for(int j = 0; j < i; j++){
					for(int k = j+1; k <= 9; k++){
						int num1 = 100*i + 10*j + k;
						int num2 = 100*dig[d-1] + 10*dig[d-2] + dig[d-3];
						
						if(num1 > num2) continue;
						else if(num1 == num2){
							ret += (x % p[len-3]) + 1;
						}
						else{
							ret += p[len-3];
						}
						
					}
				}
			}
		}
		else{
			for(int i = 1; i <= 9; i++){
				for(int j = 0; j < i; j++){
					for(int k = j+1; k <= 9; k++){
						int num1 = 100*i + 10*j + k;
						int num2 = 100*dig[d-1] + 10*dig[d-2] + dig[d-3];
						
						if(num1 > num2){
							ret += get(x, len-d) * p[d-3];
						}
						else if(num1 == num2){
							ret += (get(x, len-d)) * p[d-3];
							ret += ((x % p[d-3]) + 1);
						}
						else{
							ret += (get(x, len-d) + 1) * p[d-3];
						}
						
					}
				}
			}
		}
	}
	
	for(int d = 3; d <= len; d++){
		if(d == len){
			for(int i = 1; i < 9; i++){
				for(int j = i+1; j <= 9; j++){
					for(int k = 0; k < j; k++){
						int num1 = 100*i + 10*j + k;
						int num2 = 100*dig[d-1] + 10*dig[d-2] + dig[d-3];
						
						if(num1 > num2) continue;
						else if(num1 == num2){
							ret += (x % p[len-3]) + 1;
						}
						else{
							ret += p[len-3];
						}
					}
				}
			}
		}
		else{
			for(int i = 0; i < 9; i++){
				for(int j = i+1; j <= 9; j++){
					for(int k = 0; k < j; k++){
						int num1 = 100*i + 10*j + k;
						int num2 = 100*dig[d-1] + 10*dig[d-2] + dig[d-3];
						
						if(num1 > num2){
							ret += max((get(x, len-d) - (i==0)), 0ll) * p[d-3];
						}
						else if(num1 == num2){
							ret += max((get(x, len-d) - (i==0)), 0ll) * (p[d-3]);
							ret += ((x % p[d-3]) + 1);
						}
						else{
							ret += (get(x, len-d) + (i != 0)) * p[d-3];
						}
					}
				}
			}
		}
	}
	
	return ret;
}

int main(){
	p[0] = 1;
	for(int i = 1; i < 15; i++){
		p[i] = p[i-1] * 10;
	}
	
	ll a;
	ll b;
	cin >> a >> b;
	
	ll res = f(b) - f(a-1); 
	
	cout << res << endl;
	
	return 0;
}
