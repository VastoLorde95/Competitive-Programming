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

const int N = 100100;

struct PalindromicTree{
	struct node {
		int next[26];
		int len, sufflink, num;
		node(){
			for(int i = 0; i < M; i++) next[i] = 0;
		}
	};

	string s;
	node tree[N]; 
	int num; 			// node 1 - root with len -1, node 2 - root with len 0
	int suff; 			// max suffix palindrome

	PalindromicTree(string &t) {
		s = t;
		num = 2, suff = 2;
		tree[1].len = -1; tree[1].sufflink = 1;
		tree[2].len = 0; tree[2].sufflink = 1;
		
		for(int i = 0; i < s.length(); i++){
			tree[i+3] = node();
		}
	}

	bool addLetter(int pos) {
		int cur = suff, curlen = 0, let = s[pos] - 'a';

		while(true){
			curlen = tree[cur].len;
			if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos])    	
				break;	
			cur = tree[cur].sufflink;
		}		
		if(tree[cur].next[let]){	
			suff = tree[cur].next[let];
			return false;
		}

		suff = ++num;
		tree[num].len = tree[cur].len + 2;
		tree[cur].next[let] = num;

		if(tree[num].len == 1){
			tree[num].sufflink = 2, tree[num].num = 1;
			return true;
		}

		while(true){
			cur = tree[cur].sufflink, curlen = tree[cur].len;
			if(pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos]){
				tree[num].sufflink = tree[cur].next[let];
				break;
			}    	
		}           

		tree[num].num = 1 + tree[tree[num].sufflink].num;

		return true;
	}
};

int main(){
	
	return 0;
}
