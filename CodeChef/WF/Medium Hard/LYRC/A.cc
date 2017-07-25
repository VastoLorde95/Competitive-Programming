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

const ld PI = 3.1415926535897932384626433832795;

const int W = 500;
const int P = 5000;

const int N = W * P;
const int M = 26 + 26 + 10 + 1;

ll ans[W];

vector<vector<int> > tree(N, vector<int>(M, -1));
vector<int> f;	// longest proper suffix that is a prefix of some state in the tree
int ncnt;
vector<vector<int> > words;
vector<int> freq;
vector<int> in;

queue<int> q;

struct AhoCorasick{
	
	AhoCorasick(vector<vector<int> > &w){
		ncnt = 1;
		for(int j = 0; j < w.size(); j++){
			vector<int> &v = w[j];
			int cur = 0;
			for(int i = 0; i < v.size(); i++){
				if(tree[cur][v[i]] == -1){
					tree[cur][v[i]] = ncnt++;
				}
				cur = tree[cur][v[i]];
			}
			
			while(cur >= words.size()) words.pb(vector<int>());		
			words[cur].pb(j);
		}
	
		f.resize(ncnt);		
		freq.resize(ncnt);
		in.resize(ncnt);

		for(int i = 0; i < M; i++){
			if(tree[0][i] == -1) tree[0][i] = 0;
			else{
				f[tree[0][i]] = 0;
				q.push(tree[0][i]);
			}
		}

		while(!q.empty()){
			int cur = q.front(); q.pop();
			
			in[f[cur]]++;
			
			for(int i = 0; i < M; i++){
				if(tree[cur][i] == -1) tree[cur][i] = tree[f[cur]][i];
				else{
					f[tree[cur][i]] = tree[f[cur]][i];
					q.push(tree[cur][i]);
				}
			}
		}
	}
	
	void process(vector<int> &w){
		int cur = 0;
		
		for(int i : w){
			cur = tree[cur][i];
			freq[cur]++;
		}
	}
	
	void getans(){
		for(int i = 0; i < ncnt; i++){
			if(in[i] == 0) q.push(i);
		}
		
		while(!q.empty()){
			int cur = q.front();
			q.pop();
			
			if(--in[f[cur]] == 0){
				q.push(f[cur]);
			}
			
			freq[f[cur]] += freq[cur];
		}
		
		for(int i = 0; i < ncnt; i++){
			for(int j : words[i]) ans[j] = freq[i];
		}
	}
};

int main(){ _
	int w;
	cin >> w;
	
	map<char, int> mm;
	for(char c = 'a'; c <= 'z'; c++){
		mm[c] = c - 'a';
	}
	for(char c = 'A'; c <= 'Z'; c++){
		mm[c] = c - 'A' + 26;
	}
	for(char c = '0'; c <= '9'; c++){
		mm[c] = c - '0' + 52;
	}
	
	mm['-'] = 62;
	
	vector<vector<int> > words;
	for(int i = 0; i < w; i++){
		string s;
		cin >> s;
		
		vector<int> v;
		for(char c : s){
			v.pb(mm[c]);
		}
		
		words.pb(v);
	}
	
	AhoCorasick *a = new AhoCorasick(words);
	
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		
		vector<int> v;
		for(char ct : s) v.pb(mm[ct]);
		a->process(v);
	}
	
	a->getans();
	
	for(int i = 0; i < w; i++){
		cout << ans[i] << '\n';
	}
	
	return 0;
}
