#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(__typeof((v).begin()) it=(v).begin(); it != (v).end(); ++it)
#define meta __FUNCTION__,__LINE__

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

using namespace std;

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

const int N = 5100;

int n;
int t[N];
int tot[N];
int res[N];
int mx, id;

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		sd(t[i]);
	}
	
	for(int i = 0; i < n; i++){
		memset(tot, 0, sizeof tot);		
		mx = 0, id = 1e9;
		for(int j = i; j < n; j++){
			tot[t[j]]++;
			
			if(tot[t[j]] > mx){
				mx = tot[t[j]];
				id = t[j];
				res[t[j]]++;
			}
			else if(tot[t[j]] == mx and t[j] < id){
				id = t[j];
				res[t[j]]++;
			}
			else{
				res[id]++;
			}
		}
	}	
	
	for(int i = 1; i <= n; i++){
		printf("%d ", res[i]);
	}
	puts("");
	return 0;
}
