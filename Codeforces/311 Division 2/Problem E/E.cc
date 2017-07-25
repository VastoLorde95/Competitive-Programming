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

struct node{
	node *child[2];
	int cnt;
	node(){
		cnt = 0; child[0] = child[1] = NULL;
	}
};

char s[5001];
string t, ans;
int k, dp[5000][5000], l;
node *ROOT;

void insert(int x, int y){
	node *cur = ROOT;
	for(int i = y; i < l; i++){
		if(cur->child[s[i]-'a'] == NULL) cur->child[s[i]-'a'] = new node();
		cur = cur->child[s[i]-'a'];
		cur->cnt += dp[x][i];
	}
}

int get(node *cur, int k){
	if(cur == NULL) return 0;
	if(k <= cur->cnt) return -1;
	
	int used = cur->cnt; k -= used;
	for(int i = 0; i < 2; i++){
		int ret = get(cur->child[i], k);
		if(ret == -1){
			ans += char(i + 'a');
			return ret;
		}
		used += ret;
		k -= ret;
	}
	return used;
}

int main(){
	scanf("%s%d",s,&k);
	
	l = strlen(s);
	
	for(int i = 0; i < l; i++){
		for(int j = 0; i-j >= 0 and i+j < l; j += 2){
			if(s[i-j] != s[i+j]) break;
			dp[i-j][i+j]++;
		}
		for(int j = 1; i-j >= 0 and i+j < l; j += 2){
			if(s[i-j] != s[i+j]) break;
			dp[i-j][i+j]++;
		}
		for(int j = 1; i-j+1 >= 0 and i+j < l; j += 2){
			if(s[i-j+1] != s[i+j]) break;
			dp[i-j+1][i+j]++;
		}
		for(int j = 2; i-j+1 >= 0 and i+j < l; j += 2){
			if(s[i-j+1] != s[i+j]) break;
			dp[i-j+1][i+j]++;
		}
		
	}
	
	ROOT = new node();

	for(int i = 0; i < l; i++){
		insert(i,i);
	}
	
	get(ROOT, k);
	reverse(ans.begin(), ans.end());
	printf("%s\n", ans.c_str());
	
	return 0;
}
