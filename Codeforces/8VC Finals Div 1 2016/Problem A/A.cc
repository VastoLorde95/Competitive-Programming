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
vector<int> a, b;

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		int x; sd(x);
		if(x) a.pb(x);
	}
	
	a.insert(a.end(), a.begin(), a.end());
	
	for(int i = 0; i < n; i++){
		int x; sd(x);
		if(x) b.pb(x);
	}
	
	int start = 0;
	for(int i = 0; i < n; i++){
		if(a[i] == b[0]) start = i;
	}
		
	if(start == -1){
		puts("NO"); return 0;
	}
	
	n--;
	for(int i = start, j = 0; j < n and i < 2*n; j++, i++){
		if(b[j] != a[i]){
			puts("NO"); return 0;	
		}	
	}
	
	puts("YES");
	
	return 0;
}
