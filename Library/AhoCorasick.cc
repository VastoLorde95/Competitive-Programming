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

const int N = 200;
const int M = 26;

struct AhoCorasick{
	vector<vector<int> > tree;
	vector<int> f;	// longest proper suffix that is a prefix of some state in the tree
	int ncnt;
	queue<int> q;
	bitset<N> suff[N];	// all words that are suffixes of state i
	
	AhoCorasick(vector<vector<int> > &w){
		f.resize(N, -1);
		tree.resize(N); for(int i = 0; i < N; i++) tree[i].resize(M, -1);
		ncnt = 1;
		for(int j = 0; j < w.size(); j++){
			vector<int> &v = w[j];
			int cur = 0;
			for(int i = 0; i < v.size(); i++){
				if(tree[cur][v[i]] == -1) tree[cur][v[i]] = ncnt++;
				cur = tree[cur][v[i]];
			}
			suff[cur][j] = 1;
		}

		for(int i = 0; i < M; i++){
			if(tree[0][i] == -1) tree[0][i] = 0;
			else{
				f[tree[0][i]] = 0;
				q.push(tree[0][i]);
			}
		}

		while(!q.empty()){
			int cur = q.front(); q.pop();
			suff[cur] |= suff[f[cur]];
			
			for(int i = 0; i < M; i++){
				if(tree[cur][i] == -1) tree[cur][i] = tree[f[cur]][i];
				else{
					f[tree[cur][i]] = tree[f[cur]][i];
					q.push(tree[cur][i]);
				}
			}
		}
	}
};

int main(){
	
	return 0;
}
