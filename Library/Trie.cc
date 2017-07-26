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

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

struct Trie{
	struct node{
		node *e[26];

		node(){
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
	
	void insert(string &s){
		int l = s.length();
		node *cur = ROOT, *next = NULL;
		
		for(int i = 0; i < l; i++){
			if(cur->e[s[i]-'a'] == NULL) cur->e[s[i]-'a'] = new node();
			cur = cur->e[s[i]-'a'];
		}
		return;
	}
};

int main(){
	return 0;
}

