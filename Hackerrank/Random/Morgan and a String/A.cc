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

#define FI first
#define SE second.first
#define TH second.second

typedef pair<int, pair<int, int> > tri;

const int MAXN = 1<<18;
int p[2][MAXN];
tri L[MAXN];

int getSuffixArray(string &s){
	int indx = 0, l = s.length();
	for(int i = 0; i < l; i++) p[0][i] = s[i] - 'A'; // careful!
	
	for(int step = 0, cnt = 1; (cnt >> 1) < l; step++, cnt <<= 1){
		for(int i = 0; i < l; i++){
			L[i].FI = p[indx][i];
			L[i].SE = (i + cnt < l)? p[indx][i+cnt]: -1;
			L[i].TH = i;
		}
		
		sort(L, L+l);
		indx ^= 1;
		p[indx][L[0].TH] = 0;
		for(int i = 1; i < l; i++){
			if(L[i].FI == L[i-1].FI and L[i].SE == L[i-1].SE)
				p[indx][L[i].TH] = p[indx][L[i-1].TH];
			else
				p[indx][L[i].TH] = i;
		}
	}
	tr(s);
	for(int i = 0; i < l; i++){
		tr2(i,p[indx][i]);
	}
	return indx;
}

int test;
string a, b;

void solve(string &x, string &y){
	x += '[';
	y += '[';
	int l1 = x.length(), l2 = y.length();
	string s = x+y;
	int indx = getSuffixArray(s);
	
	int ptr1 = 0, ptr2 = 0;
	while(ptr1 < l1-1 or ptr2 < l2-1){
		if(ptr1 == l1-1) cout << y[ptr2++];
		else if(ptr2 == l2-1) cout << x[ptr1++];
		else if(p[indx][ptr1] < p[indx][l1+ptr2]) cout << x[ptr1++];
		else cout << y[ptr2++];
	}
	
	cout << "\n";
	return;
}

int main(){ _
	cin >> test;
	while(test--){
		cin >> a >> b;
		solve(a,b);
	}
	return 0;
}
