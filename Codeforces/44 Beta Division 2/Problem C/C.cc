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
#define _ ios_base::sync_with_stdio();cin.tie(NULL);cout.tie(NULL);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

string w[6];
vector<vector<string> > res;

void check(vector<string> s){
	int l[6];
	for(int i = 0; i < 6; i++) l[i] = s[i].length()-1;
	
	if(s[0][0] != s[3][0] or s[0][l[0]] != s[4][0] or s[1][0] != s[3][l[3]] or s[1][l[1]] != s[5][0] or s[2][0] != s[4][l[4]] or s[2][l[2]] != s[5][l[5]] or l[0]+l[2] != l[1] or l[3]+l[5] != l[4] or s[1][l[0]] != s[4][l[3]]) return;
	
	vector<string> tmp;	string x;
	
	for(int i = 0; i <= l[1]; i++) x += '.';
	for(int i = 0; i <= l[4]; i++) tmp.pb(x);
	
	for(int i = 0; i <= l[0]; i++) tmp[0][i] = s[0][i];
	for(int i = 0; i <= l[1]; i++) tmp[l[3]][i] = s[1][i];
	for(int i = 0; i <= l[2]; i++) tmp[l[4]][l[0]+i] = s[2][i];
	for(int i = 0; i <= l[3]; i++) tmp[i][0] = s[3][i];
	for(int i = 0; i <= l[4]; i++) tmp[i][l[0]] = s[4][i];
	for(int i = 0; i <= l[5]; i++) tmp[l[3]+i][l[1]] = s[5][i];
	res.pb(tmp);
}

int main(){ _
	for(int i = 0; i < 6; i++) cin >> w[i];
	sort(w, w+6);
	
	vector<string> tmp;
	for(int i = 0; i < 6; i++) tmp.pb(w[i]);
	
	check(tmp);
	
	while(next_permutation(w,w+6)){
		for(int i = 0; i < 6; i++) tmp[i] = w[i];
		check(tmp);
	}

	if(res.size() == 0){
		puts("Impossible");
		return 0;
	}
	
	sort(res.begin(), res.end());
	
	for(int i = 0; i < res[0].size(); i++){
		cout << res[0][i] << endl;
	}
	return 0;
}
