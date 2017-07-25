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
#define __ freopen("rsa.in","r",stdin);freopen("rsa.out","w",stdout);

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

const int N = 33333;
const int M = 101;

vector<int> p;
int ok[N];
int a[M][M];

void print(int cnt){
	vector<int> a = {1};
	while(cnt--){
		int carry = 0;
		for(int i = 0; i < a.size(); i++){
			a[i] = (a[i] * 2 + carry);
			carry = a[i] / 10;
			a[i] %= 10;
		}
		if(carry) a.pb(carry);
	}
	a[0]--;
	for(int i = a.size()-1; i >= 0; i--){
		printf("%d", a[i]);
	}
	printf("\n");
}

void gauss(int n, int m){
	int top = 0;
	for(int j = 0; j < m; j++){
		int pos = -1;
		for(int i = top; i < n; i++){
			if(a[i][j]){
				pos = i;
				break;
			}
		}
		if(pos == -1) continue;
		
		swap(a[top], a[pos]);
		
		for(int i = top+1; i < n; i++){
			if(!a[i][j]) continue;
			for(int k = 0; k < m; k++){
				a[i][k] ^= a[top][k];
			}
		}
		
		top++;
	}
	
	int cnt = m - top;
	
	print(cnt);	
	
}

int main(){ __
	for(int i = 2; i < N; i++) ok[i] = 1;
	
	for(int i = 2; i < N; i++){
		if(!ok[i]) continue;
		p.pb(i);
		for(int j = i*i; j < N; j += i) ok[j] = 0;
	}
	
	int t, m;
	sd2(t,m);
	
	for(int i = 0; i < m; i++){
		int b; sd(b);
		
		for(int j = 0; j < t; j++){
			while(b % p[j] == 0){
				b /= p[j];
				a[j][i] ^= 1;
			}
		}
	}
	
	gauss(t, m);
	
	return 0;
}
