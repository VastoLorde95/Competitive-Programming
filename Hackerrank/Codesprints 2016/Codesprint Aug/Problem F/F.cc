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

const int N = 301;

int x[N], y[N], z[N];

int solve1(int n, bool flag){
	int k = n / 3;

	int j = 0;		
	for(int i = k; i <= 2*k; i++){
		x[j] = i;
		y[j] = (2 * k) - 2 * (i - k);
		z[j] = n - x[j] - y[j];
		j++;
	}
	
	for(int i = 0; i < k; i++){
		x[j] = k - i - 1;
		y[j] = 2 * i + 1;
		z[j] = n - x[j] - y[j];
		j++;
	}
	
	if(flag){	
		printf("%d\n", j);
	
		for(int i = 0; i < j; i++){
			printf("%d %d %d\n", x[i], y[i], z[i]);
		}
	}
	
	return j;
}

void solve2(int n){
	int j = solve1(n-2, false);
	
	for(int i = 0; i < j; i++){
		y[i]++; z[i]++;
	}
	
	x[j] = n, y[j] = 0, z[j] = 0;
	j++;
	
	printf("%d\n", j);
	
	for(int i = 0; i < j; i++){
		printf("%d %d %d\n", x[i], y[i], z[i]);
	}
}

int main(){
	int n;
	sd(n);
	
	if(n%3 < 2) solve1(n, true); else solve2(n);
	
	return 0;
}
