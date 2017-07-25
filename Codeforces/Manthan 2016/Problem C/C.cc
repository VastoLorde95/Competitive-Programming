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

const int N = 100100;
const int M = 10100;

int n;
string t;
int m;
string w[N];
string wl[N];

int dp[M];

struct tri{
	struct node{
		node *e[26];
		int id;

		node(){
			for(int i = 0; i < 26; i++) e[i] = NULL;
			id = -1;
		}
	};
	
	node *ROOT;
	
	tri(){
		ROOT = new node();
	}

	~tri(){
		queue<node *> q;
		node *cur = ROOT;
		q.push(cur);
		while(!q.empty()){
			cur = q.front(); q.pop();
			for(int i = 0; i < 26; i++) if(cur->e[i] != NULL) q.push(cur->e[i]);
			delete cur;
		}
	}
	
	void insert(string &s, int id){
		int l = s.length();
		node *cur = ROOT, *next = NULL;
		
		for(int i = 0; i < l; i++){
			if(cur->e[s[i]-'a'] == NULL) cur->e[s[i]-'a'] = new node();
			cur = cur->e[s[i]-'a'];
		}
		
		cur->id = id;
		
		return;
	}
	
	int match(int i){
		int l = i+1;
		node *cur = ROOT, *next = NULL;
		
		for(; i >= 0; i--){
			if(cur->e[t[i]-'a'] == NULL) return -1;
			cur = cur->e[t[i]-'a'];
			if(cur->id != -1){
				if(i == 0) return cur->id;
				if(dp[i-1] != -1) return cur->id;
			}
		}
		
		return -1;
	}
	
};

vector<int> res;

int main(){ _
	cin >> n;
	cin >> t;
	cin >> m;
	
	tri *tree = new tri();
	
	for(int i = 0; i < m; i++){
		cin >> w[i];
		int l = w[i].length();
		wl[i] = w[i];
		for(int j = 0; j < l; j++){
			if(w[i][j] < 'a') w[i][j] += 32;
		}
		
		tree->insert(w[i], i);
	}
	
	for(int i = 0; i < n; i++){
		dp[i] = tree->match(i);
	}
	
	int e = n-1;
	while(e >= 0){
		res.pb(dp[e]);
		e = e - (int) w[dp[e]].size();
	}
	
	reverse(res.begin(), res.end());
	for(int i = 0; i < res.size(); i++){
		cout << wl[res[i]] << " ";
	}
	cout << '\n';
	
	return 0;
}
