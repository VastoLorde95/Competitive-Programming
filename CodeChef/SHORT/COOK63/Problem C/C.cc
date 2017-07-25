#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <cassert>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cerr.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define meta __FUNCTION__<<" "<<__LINE__<<" "
#define tr(x) cerr<<meta<<#x<<" "<<x<<endl;
#define tr2(x,y) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define tr3(x,y,z) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr4(w,x,y,z) cerr<<meta<<#w<<" "<<w<<" "<<#x<<" " <<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cerr<<meta<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cerr<<meta<<#u<<" "<<u<<" "<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;

using namespace std;

typedef long long ll;

const int N = 1001000;

int n, t, base = 31;
string s[N];
vector<int> mark1[N];
vector<int> mark2[N];

ll ans, h1, h2, MOD = 1e9 + 7;
ll powers[N];

struct trie{
	struct node{
		int end, below;
		node *e[26];

		node(){
			end = below = 0;
			for(int i = 0; i < 26; i++) e[i] = NULL;
		}
	};
	
	node *ROOT;
	
	trie(){
		ROOT = new node();
	}

	~trie(){
		queue<node *> q;
		node *cur = ROOT;
		q.push(cur);
		while(!q.empty()){
			cur = q.front(); q.pop();
			for(int i = 0; i < 26; i++) if(cur->e[i] != NULL) q.push(cur->e[i]);
			delete cur;
		}
	}
	
	void insert(string &s, int indx){
		int l = s.length();
		node *cur = ROOT, *next = NULL;
		
		for(int i = 0; i < l; i++){
			cur->below += mark1[indx][l-i-1];
			if(cur->e[s[i]-'a'] == NULL){
				next = new node();
				cur->e[s[i]-'a'] = next;
			}
			else{
				next = cur->e[s[i]-'a'];
			}
			cur = next;
		}
		cur->end += 1;
		return;
	}
	
	ll get(string &s, int indx){
		reverse(s.begin(), s.end());
		int l = s.length();
		ll tot = 0;
		node *cur = ROOT;
		for(int i = 0; i < l; i++){
			if(mark2[indx][l-i-1] == 1){
				tot += cur->end; 
			}
			if(cur->e[s[i]-'a'] == NULL) return tot;		
			cur = cur->e[s[i]-'a'];	
		}
		
		tot += (cur->end-mark1[indx][l-1]);
		tot += cur->below;
		return tot;
	}
};


int main(){ _
	cin >> t;
	powers[0] = 1;
	for(int i = 1; i < N; i++) powers[i] = (powers[i-1]*base)%MOD;
	
	while(t--){
		cin >> n;
		ans = 0;	
		
		trie *TREE = new trie();
		
		for(int i = 0; i < n; i++) mark1[i].clear(), mark2[i].clear();
		
		for(int i = 0; i < n; i++){
			cin >> s[i];
			int l = s[i].length(), p1 = l-1, p2 = l-2;
			
			mark1[i].pb(1);
			
			h1 = h2 = 0;
			
			for(int j = l-2; j >= 0; j--){
				if((l-j)%2 == 0){
					h1 = (h1*base)%MOD;				
					h1 = (h1 + (s[i][p1--]-'a'+1))%MOD;
					h2 = (h2 + ((s[i][j]-'a'+1)*powers[-1+(l-j)/2])%MOD)%MOD;
				}
				else{
					h2 = (h2 - (s[i][p2--]-'a'+1) + MOD)%MOD;
					h2 = (h2 + ((s[i][j]-'a'+1)*powers[(l-j)/2])%MOD)%MOD;
					h2 = (h2 * 129032259ll)%MOD;
				}
				mark1[i].pb((h1 == h2));
			}
			
			mark2[i].pb(1);
			
			h1 = h2 = 0, p1 = 0, p2 = 1;
			
			for(int j = 1; j < l; j++){
				if(j%2 == 1){
					h1 = (h1*base)%MOD;				
					h1 = (h1 + (s[i][p1++]-'a'+1))%MOD;
					h2 = (h2 + ((s[i][j]-'a'+1)*powers[-1 + (j+1)/2])%MOD)%MOD;
				}
				else{
					h2 = (h2 + ((s[i][j]-'a'+1)*powers[(j+1)/2])%MOD)%MOD;
					h2 = (h2 - (s[i][p2++]-'a'+1) + MOD)%MOD;
					h2 = (h2 * 129032259ll)%MOD;
				}
				mark2[i].pb((h1 == h2));
			}
		}
		
		for(int i = 0; i < n; i++){
			TREE->insert(s[i],i);
		}
		
		for(int i = 0; i < n; i++){
			ans += TREE->get(s[i], i);
		}
		delete TREE;
		cout << ans << '\n';
	}
	return 0;
}
