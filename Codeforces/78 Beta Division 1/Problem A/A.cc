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

set<string> rep;
char in[10], tmp[10];

// TDLRFB

int tr[6][6]={
	0,1,2,3,4,5, // T is top
	1,0,2,3,5,4, // D is top
	2,3,1,0,4,5, // L is top
	3,2,0,1,4,5, // R is top
	4,5,2,3,1,0, // F is top
	5,4,2,3,0,1  // B is top
};

void rotate(){
	char t;
	t = tmp[2];
	tmp[2] = tmp[4];
	tmp[4] = tmp[3];
	tmp[3] = tmp[5];
	tmp[5] = t;
}

void makeRotations(string s){
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 6; j++){
			tmp[j] = s[tr[i][j]];
		}
		
		string ts;
		
		for(int j = 0; j < 4; j++){
			ts = tmp;
			rep.insert(ts);
			rotate();
		}
	}
	return;
}

int main(){
	
	
	string s;
	scanf("%s",in);
	sort(in,in+6);
	
	s = in;
	int cnt = 1;
	
	makeRotations(s);
	
	while(next_permutation(in,in+6)){
		s = in;
		if(rep.find(s) == rep.end()){
			cnt++;
			makeRotations(s);
		}
	}
	
	printf("%d\n", cnt);
	
	return 0;
}
