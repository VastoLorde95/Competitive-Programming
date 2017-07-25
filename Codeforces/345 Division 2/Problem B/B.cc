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

const int N = 1001;

int n;
int cnt[N];
set<int> s;

int main(){
	sd(n);
	int x;
	for(int i = 0; i < n; i++){
		sd(x);
		cnt[x]++;
		s.insert(x);
	}	
	
	int ans = 0, sum = 0;
	
	n = s.size();
	
	sort(cnt+1, cnt+1001);
	for(int i = 1; i <= 1000; i++){
		if(cnt[i] - sum <= 0) continue;
		ans += (cnt[i] - sum) * (n-1);
		sum += (cnt[i] - sum);
		n--;
	}
	
	printf("%d\n", ans);	
	
	return 0;
}
