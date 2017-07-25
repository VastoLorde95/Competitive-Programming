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

const int N = 200100;

int n;
int t[N];

vector<int> ind;

set<pii> s;

bool good(int i){
	if(i == 1){
		if(t[i] >= t[i+1]) return false;
	}
	else if(i == n){
		if(i%2 == 1 and t[i] >= t[i-1]) return false;
		if(i%2 == 0 and t[i] <= t[i-1]) return false;
	}
	else{
		if(i%2 == 1){
			if(t[i] >= t[i-1] or t[i] >= t[i+1]) return false;
		}
		else{
			if(t[i] <= t[i-1] or t[i] <= t[i+1]) return false;
		}
	}
	return true;
}

int main(){
	sd(n);
	for(int i = 1; i <= n; i++){
		sd(t[i]);
	}	
	
	for(int i = 1; i <= n; i++){
		if(i == 1){
			if(t[i] >= t[i+1]) ind.pb(i);
		}
		else if(i == n){
			if(i%2 == 1 and t[i] >= t[i-1]) ind.pb(i);
			if(i%2 == 0 and t[i] <= t[i-1]) ind.pb(i);
		}
		else{
			if(i%2 == 1){
				if(t[i] >= t[i-1] or t[i] >= t[i+1]) ind.pb(i);
			}
			else{
				if(t[i] <= t[i-1] or t[i] <= t[i+1]) ind.pb(i);
			}
		}
	}
	
	if(ind.size() > 6){
		puts("0");
		return 0;
	}
	
	int cnt = 0;
	for(int i = 0; i < ind.size(); i++){
		int x = ind[i];
		for(int j = 1; j <= n; j++){
			int y = j;
			if(s.count(mp(x,y)) or s.count(mp(y,x))) continue;
			
			swap(t[x], t[y]);
			
			if(!good(y) or !good(x)){
				swap(t[x], t[y]);
				continue;
			}
			
			bool res = true;
			for(int k = 0; k < ind.size(); k++){
				if(!good(ind[k])){
					res = false;
					break;
				}
			}
			
			if(res){
				s.insert(mp(x,y));
				s.insert(mp(y,x));
				cnt++;
			}
			
			swap(t[x], t[y]);
			
		}
	}
	
	printf("%d\n", cnt);
	
	return 0;
}
