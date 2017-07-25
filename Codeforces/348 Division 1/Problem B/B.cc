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

const int N = 1001000;

int n;

void add(int &x, int y){
	x += y;
	if(x < 0) x += n;
	else if(x >= n) x -= n;
}

int ans[N];

int main(){
	int q, d1 = 0, d2 = 0, t, x;
	int par1 = 0, par2 = 1;
	
	sd2(n,q);
	
	int last1 = 0, last2 = 0;
	for(int i = 0; i < q; i++){
		sd(t);
		if(t == 1){
			sd(x);
			add(last1, x);			
			add(last2, x);
		}
		else{
			add(d1, last1);
			add(d2, last2);
		
			if(abs(last1)%2 == 1) par1 ^= 1;
			
			if(par1 == 0) {
				par1 = 1; add(d1, -1);
			} else {
				par1 = 0; add(d1, 1);
			}
			
			if(abs(last2)%2 == 1) par2 ^= 1;
			
			if(par2 == 0) {
				par2 = 1; add(d2, -1);
			} else {
				par2 = 0; add(d2, 1);
			}
			
			last1 = last2 = 0;
		}
	}
	add(d1, last1);
	add(d2, last2);
	
	for(int i = 0; i < n; i++){
		int f = i;
		if(i%2 == 0) add(f, d2);
		else add(f, d1);
		ans[f] = i;
	}
	
	for(int i = 0; i < n; i++) printf("%d ", ans[i]+1);
	puts("");
	
	
	return 0;
}

