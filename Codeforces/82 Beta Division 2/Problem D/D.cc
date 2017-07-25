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
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int nn, m;

int grid[1001][1001], n[1001][1001], s[1001][1001], e[1001][1001], w[1001][1001];
map<char, pair<int, int> > pos;

bool res[26];

string str;

int main(){
	sd2(nn,m);
	
	for(int i = 0; i < nn; i++){
		cin >> str;
		for(int j = 0; j < m; j++){
			if(str[j] == '#'){
				grid[i][j] = -1;
			}
			else{
				grid[i][j] = 1;
				if(str[j] != '.'){
					pos[str[j]] = mp(i,j);
				}
			}
		}
	}
	
	for(int i = 0; i < nn; i++){
		for(int j = 0; j < m; j++){
			if(grid[i][j] == -1){
				n[i][j] = w[i][j] = -1;
			}
			else{
				n[i][j] = n[i-1][j]+1;
				w[i][j] = w[i][j-1]+1;
			}
		}
	}
	
	for(int i = nn-1; i >= 0; i--){
		for(int j = m-1; j >= 0; j--){
			if(grid[i][j] == -1){
				e[i][j] = s[i][j] = -1;
			}
			else{
				e[i][j] = e[i][j+1] + 1;
				s[i][j] = s[i+1][j] + 1;
			}
		}
	}
	
	vector<pair<char, int > > d;
	char c; int x, y, k;
	sd(k);
	
	for(int i = 0; i < k; i++){
		scanf(" %c 	%d", &c, &x);
		d.pb(mp(c,x));
	}
	
	string ans;
	
	foreach(it, pos){
		x = it->se.fi, y = it->se.se, c = it->fi;
		res[c - 'A'] = true;
		for(int i = 0; i < k; i++){
			if(d[i].fi == 'N'){
				if(n[x][y] < d[i].se) res[c-'A'] = false;
				else x -= d[i].se;
			}
			else if(d[i].fi == 'S'){
				if(s[x][y] < d[i].se) res[c-'A'] = false;
				else x += d[i].se;
			}
			else if(d[i].fi == 'E'){
				if(e[x][y] < d[i].se) res[c-'A'] = false;
				else y += d[i].se;
			}
			else if(d[i].fi == 'W'){
				if(w[x][y] < d[i].se) res[c-'A'] = false;
				else y -= d[i].se;
			}
		}
		
		if(res[c-'A']) ans += c;
	}
	
	if(ans.length()) cout << ans << "\n";
	else cout << "no solution\n";
	
	return 0;
}
