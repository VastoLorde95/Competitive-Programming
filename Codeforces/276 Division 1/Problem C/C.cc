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

const int LOGN = 20;
const int N = 1 << LOGN;

char s[N], t[N];
int n, m;

int pos[LOGN][N];

int get(int x, int k, int logn){
	int res = 0;
	if(x >= k){
		res = x - k + 1;
		x = k-1;
	}
	
	for(int i = logn-1; i >= 0; i--){
		if(pos[i][x] != -1 and res + k-1 + (1 << i) - 1 < n){
			res += (1 << i) - 1;
			x = pos[i][x];
			if(res + k < n and x > 0){
				x--;
				res++;
			}
			else
				break;
		}
	}
	
	res += x;

	return res;
}

void update(){
	int k, d;
	sd2(k,d);
		
	int cur = 0;
	for(int i = 0; i < d; i++){
		for(int j = i; j < k; j += d){
			pos[0][j] = cur++;
		}
	}
	
	int logn = 0;
	while((1 << logn) < n) ++logn;
	
	for(int j = 1; j < logn; j++){
		for(int i = 0; i < k; i++){
			pos[j][i] = (pos[j-1][i] <= 0)? -1 : pos[j-1][pos[j-1][i]-1];
		}
	}
	
	for(int i = 0; i < n; i++) t[i] = s[i];
	for(int i = 0; i < n; i++) s[get(i, k, logn)] = t[i];
	printf("%s\n", s);
	
}

int main(){
	scanf("%s", s);
	n = strlen(s);
	
	sd(m);
	while(m--){
		update();
	}
	
	return 0;
}
