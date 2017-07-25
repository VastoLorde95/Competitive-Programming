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

#define meta __FUNCTION__<<' '<<__LINE__<<' '
#define tr(x) cerr<<meta<<#x<<' '<<x<<'\n';
#define tr2(x,y) cerr<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<'\n';
#define tr3(x,y,z) cerr<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr4(w,x,y,z) cerr<<meta<<#w<<' '<<w<<' '<<#x<<' ' <<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr5(v,w,x,y,z) cerr<<meta<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr6(u,v,w,x,y,z) cerr<<meta<<#u<<' '<<u<<' '<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';

using namespace std;

typedef long long ll;
const int N = 100100;

int n;
ll a[N];

struct trie{
	struct node{
		node *left, *right;
		
		node(){
			left = right = NULL;
		}
	};
	
	node *root;
	trie(){
		root =  new node();
	}
	void insert_node(ll num){
		node *cur = root;
		for(int i = 40; i >= 0; i--){
			if((num&(1ll<<i)) == 0){
				if(cur->left == NULL) cur->left = new node();
				cur = cur->left;
			}
			else{
				if(cur->right == NULL) cur->right = new node();
				cur = cur->right;
			}
		}
	}
	
	ll get_max(ll num){
		node *cur = root;
		for(int i = 40; i >= 0; i--){
			if((num&(1ll<<i)) == 0){
				if(cur->right == NULL){
					cur = cur->left;
				}
				else{
					num ^= (1ll<<i);
					cur = cur->right;
				}
			}
			else{
				if(cur->left == NULL){
					num ^= (1ll<<i);
					cur = cur->right;
				}
				else{
					cur = cur->left;
				}
			}
		}
		return num;
	}
};

int main(){ _
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	ll x = 0, mx = 0;

	trie *t = new trie();
	
	for(int i = 0; i < n; i++){
		x ^= a[i];
		t->insert_node(x);
	}
	
	x = 0, mx = t->get_max(0);
	for(int i = n-1; i >= 0; i--){
		x ^= a[i];
		mx = max(mx, t->get_max(x));
	}
	
	cout << mx << endl;
	
	return 0;
}
