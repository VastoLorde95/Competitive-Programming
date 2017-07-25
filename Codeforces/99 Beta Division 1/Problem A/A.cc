#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<queue>
#include<stack>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n, k, res, cnt, t[2500][4], flag;
string w[4];
map<char, int> v;

bool match(string a, string b){
	int x = a.length()-1, y = b.length()-1;
	int c1 = 0, c2 = 0;
	
	while(x >= 0 and c1 < k){
		c1 += v[a[x--]];
	}
	x++;
	
	while(y >= 0 and c2 < k){
		c2 += v[b[y--]];
	}
	y++;
	
	if(c1 != k or c2 != k or a.substr(x, a.length()-x+1) != b.substr(y, b.length()-y+1)) return false;
	
	return true;	
}

int c1(){
	if(match(w[0],w[1]) and match(w[2],w[3])) return 1;
	return 0;
}

int c2(){
	if(match(w[0],w[2]) and match(w[1],w[3])) return 1;
	return 0;
}

int c3(){
	if(match(w[0],w[3]) and match(w[1],w[2])) return 1;
	return 0;
}

int main(){
	sd2(n,k);
	
	v['a'] = 1;
	v['e'] = 1;
	v['i'] = 1;
	v['o'] = 1;
	v['u'] = 1;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 4; j++){
			cin >> w[j];
		}
		
		cnt = 0;
		
		t[i][0] = c1();
		t[i][1] = c2();
		t[i][2] = c3();
	}
	
	for(int j = 0; j < 3; j++){
		flag = 1;
		for(int i = 0; i < n; i++){
			if(t[i][j] == 0){
				flag = 0;
				break;
			}
		}
		if(flag){
			res |= (1<<j);
		}
	}
	
	if(res == 0) puts("NO");
	else if(res == 7) puts("aaaa");
	else if(res&1) puts("aabb");
	else if(res&2) puts("abab");
	else puts("abba");
	
	return 0;
}
