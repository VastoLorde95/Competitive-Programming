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

const int N = 1<<17;

int n, ans;
string a, b;
vector<pair<int, int> > matches;

struct node{
	vector<int> a, b;
	node* edge[26];
	int len;
	node(int l){
		len = l;
		for(int i = 0; i < 26; i++) edge[i] = NULL;
	}
};

node *ROOT;

void insert(string &s, int type, int indx){
	int l = s.length();
	node *cur = ROOT;
	for(int i = 0; i < l; i++){
		if(cur->edge[s[i]-'a'] == NULL)
			cur->edge[s[i]-'a'] = new node(i+1);
		cur = cur->edge[s[i]-'a'];
	}
	
	if(type == 1) cur->a.pb(indx); else cur->b.pb(indx);
}

void match(node *cur){
	for(int i = 0; i < 26; i++){
		if(cur->edge[i] != NULL){
			node *nxt = cur->edge[i];			
			match(nxt);
			cur->a.insert(cur->a.end(), nxt->a.begin(), nxt->a.end());
			cur->b.insert(cur->b.end(), nxt->b.begin(), nxt->b.end());
		}
	}
	
	while(cur->a.size() > 0 and cur->b.size() > 0){
		matches.pb(mp(cur->a.back(), cur->b.back()));
		ans += cur->len;
		cur->a.pop_back();
		cur->b.pop_back();
	}
	return;
	
}

int main(){	_
	cin >> n;
	
	ROOT = new node(0);
	
	for(int i = 0; i < n; i++){
		cin >> a;
		insert(a, 1, i);
	}
	for(int i = 0; i < n; i++){
		cin >> b;
		insert(b, 2, i);
	}
	
	match(ROOT);
	
	cout << ans << "\n";
	
	foreach(it, matches){
		cout << it->fi+1 << " " << it->se+1 << "\n";
	}
	
	return 0;
}
