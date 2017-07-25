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

const long double PI = 3.1415926535897932384626433832795;

const int N = 610;

int n, m, k;
int g[N];

void get(set<vector<int> > &f, vector<int> v, int id, int len, int tot){
	if(id == len){
		v.pb(tot);
		sort(v.begin(), v.end());
		f.insert(v);
		return;
	}
	
	int rem = len - id;
	for(int i = 1; i <= tot - rem; i++){
		vector<int> tmp = v;
		tmp.pb(i);
		get(f, tmp, id+1, len, tot - i);
	}
}

void go(int cur){
	if(g[cur] != -1) return;
	set<int> s;
	
	for(int i = 2; i <= min(k,cur); i++){
		set<vector<int> > f;
		vector<int> v;
		get(f, v, 1, i, cur);
		foreach(it, f){
			int x = 0;
			vector<int> tmp = *it;
			foreach(itt, tmp){
				go(*itt);
				x ^= g[*itt];
			}
			s.insert(x);
		}
	}
	
	for(int i = 0; i < N; i++){
		if(!s.count(i)){
			g[cur] = i;
			break;
		}
	}

}

int main(){
//	sd3(n,m,k);
	
	cout << "gg[601] = {0";
	for(int i = 3; i <= 3; i++){
		n = 4, m = 10, k = i;
		fill(g, g+N, -1);
		g[1] = 0;
		go(600);
		tr(meta);
		for(int j = 1; j <= 600; j++){
			cout << ","<< g[j];
//			tr(i, j, g[j]);
		}
		cout << "};" << endl;
	}

	return 0;
}
