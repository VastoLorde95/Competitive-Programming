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

const int N = 101;
int ans[N];

int beg[5] = {1, 22, 43, 64, 85};

void solve(){
	int k; sd(k);
	int kk = k;
	
	if(k == 100000){
//		printf("50 %d\n", kk);
		puts("50");
		for(int i = 1; i <= 5; i++){
			int k = 10 * i;
			for(int m = 0; m < 10; m++){
				printf("%d ", k - m);
			}
		}
		puts("");
		return;
	}
	
	fill(ans, ans+N, 0);
	
	vector<int> digits;
	while(k){
		digits.pb(k%10);
		k /= 10;
	}
	
	for(int i = 1; i <= 4; i++){
		int cur = 21*i;
		int st = 10*(i-1);
		for(int j = 0; j < 10; j++){
			ans[st+j+1] = cur-j;
		}
	}
	
	ans[100] = 95;
	ans[99] = 74;
	ans[98] = 53;
	ans[97] = 32;
	ans[96] = 11;
	
	int cur = 95;
	for(int j = 0; j < digits.size(); j++){
		int x = digits[j];
		int y = beg[j];
		
		while(x--){
			ans[cur--] = y++;
		}
	}
	
	vector<int> v;
	for(int i = 1; i < N; i++){
		if(ans[i]) v.pb(ans[i]);
	}
	
	assert(1 <= v.size() and v.size() <= 100);
	
	set<int> s;
	foreach(it, v) s.insert(*it);
		
	map<int, int> mm;
	int cnt = 0;
	foreach(it, s){
		mm[*it] = ++cnt;
	} 
	
	for(int i = 0; i < v.size(); i++){
		v[i] = mm[v[i]];
	}

//	printf("%d %d\n", v.size(), kk);	
	printf("%d\n", v.size());
	for(int i = 0; i < v.size(); i++){
		printf("%d ", v[i]);
	}
	puts("");
}

int main(){
	int t; sd(t);
//	cout << t << endl;
	while(t--) solve();
	return 0;
}
