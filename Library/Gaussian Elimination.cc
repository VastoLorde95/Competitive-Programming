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

void GaussianElimination(){
	int sz = part.size();
	
	for(int i = 1; i <= sz; i++){
		int id = i;
		for(int j = i; j <= sz; j++){
			if(abs(m[j][i]) > abs(m[id][i])) id = j;
		}
		
		for(int j = 1; j <= sz; j++) swap(m[i][j], m[id][j]);
		
		swap(f[i], f[id]);
		
		for(int j = i+1; j <= sz; j++){
			double r = m[j][i] / m[i][i];
			for(int k = 1; k <= sz; k++){
				m[j][k] -= r * m[i][k];
			}
			f[j] -= r * f[i];
		}
	}
	
	for(int i = sz; i > 0; i--){
		for(int j = i+1; j <= sz; j++){
			f[i] -= m[i][j] * f[j];
		}
		f[i] /= m[i][i];
	}
}

int main(){
	
	return 0;
}
