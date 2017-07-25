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

const int N = 501;
const int B = 300300;
const int base = 130000;
const int INF = 1e9;

int n;
vector<int> h, v;

int ans1 = INF;
int ans2 = INF;
int a;

void go1(int i, int tot, int l, int r){
	if(i == h.size()){
		if(tot == 0){
			ans1 = 0;
		}
		else if(tot > 0){
			if(r >= tot) ans1 = min(ans1, tot);
		}
		else{
			tot = -tot;
			if(l >= tot) ans1 = min(ans1, tot);
		}
		return;
	}
	
	go1(i+1, tot+h[i], l, r + h[i]-1);
	go1(i+1, tot-h[i], l + h[i]-1, r);
}

void go2(int i, int tot, int l, int r){
	if(i == v.size()){
		if(tot == -a){
			ans2 = 0;
		}
		else if(tot > -a){
			if(r >= tot) ans2 = min(ans2, abs(tot+a));
		}
		else{
			if(l >= tot) ans2 = min(ans2, abs(tot+a));
		}
		return;
	}
	
	go2(i+1, tot+v[i], l, r + v[i]-1);
	go2(i+1, tot-v[i], l + v[i]-1, r);
}



void solve(){
	sd(n);
	
	sd(a);
	char c;
	
	h.clear();
	v.clear();
	
	int x;	
	for(int i = 0; i < n; i++){
		scanf(" %c %d", &c, &x);
		if(i&1) v.pb(x);	
		else h.pb(x);
	}

	if(n <= 2){
		puts("NO");
		return;
	}
	
	ans1 = INF;
	ans2 = INF;
	
	go1(0, 0, 0, 0);	
	go2(0, 0, 0, 0);
	
	cout << ans1 + ans2 << endl;
	
	
}

int main(){
	int t;
	sd(t);
	while(t--) solve();
	return 0;
}
