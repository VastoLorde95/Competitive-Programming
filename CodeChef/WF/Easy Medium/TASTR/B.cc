#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

class SuffixArray{
private:
	int l;
	string s;
	vector<int> sa;
	vector<int> rank;
	vector<int> lcp;

	const int M = 256;
		
	vector<vector<pii> > buck;

public:
	SuffixArray(string &str){
		s = str;
		l = s.length();
		
		rank.resize(l);
		sa.resize(l);
		buck.resize(M);
		
		for(int i = 0; i < l; i++){
			buck[s[i]].pb(mp(i,i));
			rank[i] = s[i];
		}
			
		int trnk = -1;
		for(int i = 0; i < M; i++){
			if(buck[i].empty() or ++trnk == i) continue;
						
			for(pii &x : buck[i]){
				rank[x.fi] = trnk;
				buck[trnk].pb(mp(x.fi, trnk));
			}
			buck[i].clear();
		}
		
		buck.resize(trnk+1);
		vector<vector<pii> > tmp;
				
		for(int w = 1; w < l; w <<= 1){
			tmp.clear();
			tmp.resize(buck.size()+1);
			
			for(int i = 0; i < buck.size(); i++){
				for(int j = 0; j < buck[i].size(); j++){
					pii x = buck[i][j];
					if(x.fi + w >= l) tmp[0].pb(x);
					else tmp[rank[x.fi+w]+1].pb(x);
				}
				buck[i].clear();
			}
			
			for(int i = 0; i < tmp.size(); i++)
				for(pii &x : tmp[i])
					buck[rank[x.fi]].pb(mp(x.fi, i));
			
			int bnum = -1;
			for(int i = 0; i < buck.size(); i++){
				for(int j = 0; j < buck[i].size(); j++){
					int id = buck[i][j].fi, bid = buck[i][j].se;
					
					if(j == 0 or bid != buck[i][j-1].se) ++bnum;
					
					rank[id] = bnum;
				}
				
				buck[i].clear();
			}
			
			buck.resize(bnum+1);
			for(int i = 0; i < l; i++)
				buck[rank[i]].pb(mp(i,rank[i]));
		}
		
		buck.clear();
		
		for(int i = 0; i < l; i++) sa[rank[i]] = i;
		
		lcp.resize(l, 0);
		for(int i = 0, k = 0; i < l; i++, k ? k-- : 0)
		{
		    if(rank[i] == l-1){
		    	k = 0;
		    	continue;
		    }
		    int j = sa[rank[i]+1];
		    while(i + k < l and j + k < l and s[i+k] == s[j+k]) k++;
		    lcp[rank[i]] = k;
		}
	}
	
	~SuffixArray(){
		sa.clear();
		rank.clear();
		lcp.clear();
	}
	
	ll countDistinctSubstrings(){
		ll ans = l - sa[0];
		for(int i = 1; i < l; i++)
			ans += l - sa[i] - lcp[i-1];
		return ans;
	}
	
	ll countDistinctSubstrings(int l1, int l2){
		ll ans = 0;
		if(sa[0] < l1) ans = l1 - sa[0]; else if(sa[0] > l1) ans = l - sa[0];
		
		for(int i = 1; i < l; i++){
			if(sa[i] == l1) continue;
			if(sa[i] < l1)
				ans += max(l1 - sa[i] - lcp[i-1], 0);
			else
				ans += max(l - sa[i] - lcp[i-1], 0);
		}
		return ans;
	}
};

string a;
string b;
string s;

int main(){ _
	cin >> a >> b;
	
	SuffixArray A = SuffixArray(a);
	ll x = A.countDistinctSubstrings();
	
	SuffixArray B = SuffixArray(b);
	ll y = B.countDistinctSubstrings();

	s = a + "$" + b;
	
	SuffixArray S = SuffixArray(s);
	ll z = S.countDistinctSubstrings(a.length(), b.length());
	
	ll k = x + y - z;
	ll ans = x + y - k - k;
	
	cout << ans << endl;	
	
	return 0;
}
