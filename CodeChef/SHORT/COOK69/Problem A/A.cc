#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)
#define meta __FUNCTION__,__LINE__

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

using namespace std;

const long double PI = 3.1415926535897932384626433832795;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;
typedef pair<int,int> pii;

void solve(){
	int n;
	cin >> n;
	
	int mx = 0, mr = 0, id = 0;
	
	int l[n], r[n];
	
	for(int i = 1; i <= n; i++)
		cin >> l[i];
	for(int i = 1; i <= n; i++)
		cin >> r[i];
		
	for(int i = 1; i <= n; i++){
		if(l[i]*r[i] > mx){
			mx = l[i]*r[i];
			mr = r[i];
			id = i;
		}
		else if(l[i]*r[i] == mx and r[i] > mr){
			mr = r[i];
			id = i;
		}
	}
	
	cout << id << endl;
	
}

int main(){
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
