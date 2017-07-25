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

int ma[N][N];
int a[N][N];
int b[N][N];

int main(){ _
	int n, m;
	cin >> n >> m;
	
	set<string> st;
	
	for(int i = 0; i < n; i++){
		string s; cin >> s;
		st.insert(s);
		for(int j = 0; j < m; j++){
			ma[i][j] = (s[j] == '1');
			a[i][j] = b[j][i] = ma[i][j];
		}
	}
	
	int rnk1 = 0;
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			if(a[j][i] == 1){
				swap(a[j], a[i]);
				rnk1++;
				break;
			}
		}
		
		for(int j = i+1; j < n; j++){
			if(a[j][i] == 0) continue;
			for(int k = i; k < m; k++){
				a[j][k] -= a[i][k];
			}
		}
	}
	
	int rnk2 = 0;
	for(int i = 0; i < m; i++){
		for(int j = i; j < m; j++){
			if(b[j][i] == 1){
				swap(b[j], b[i]);
				rnk2++;
				break;
			}
		}
		
		for(int j = i+1; j < m; j++){
			if(b[j][i] == 0) continue;
			for(int k = i; k < n; k++){
				b[j][k] -= b[i][k];
			}
		}
	}
	
	cout << max(rnk1, rnk2) << endl;
	
	return 0;
}
