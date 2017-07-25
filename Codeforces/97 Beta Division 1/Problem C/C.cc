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

int n, z, o, q;
string s;

set<string> res;

int main(){ _
	cin >> s;
	n = s.length();
	
	for(int i = 0; i < n; i++){
		if(s[i] == '0') z++;
		else if(s[i] == '1') o++;
		else q++;
	}
	
	if(n == 2){
		if(q == 0) cout << s << endl;
		else if(q == 2) cout << "00\n01\n10\n11" << endl;
		else{
			if(s[0] == '?'){
				cout << "0" << s[1] << endl;
				cout << "1" << s[1] << endl;
			}
			else{
				cout << s[0] << "0" << endl;
				cout << s[0] << "1" << endl;
			}
		}
		return 0;
	}
	
	int x = (n-1)/2, y = n-2-x;
	
	if(o <= x) res.insert("00");
	if(o+q >= x+2) res.insert("11");
	
	string e = s.substr(n-2,2);
	
	if(o <= x+1 and z <= y+1){
		if(e == "00") res.insert("10");
		else if(e == "01") res.insert("01");
		else if(e == "0?"){
			if(o == x+1) res.insert("10");
			if(z == y+1) res.insert("01");
			if(o < x+1 and z < y+1){
				res.insert("01");
				res.insert("10");
			}
		}
		else if(e == "10") res.insert("10");
		else if(e == "11") res.insert("01");
		else if(e == "1?"){
			if(o == x+1) res.insert("10");
			if(z == y+1) res.insert("01");
			if(o < x+1 and z < y+1){
				res.insert("01");
				res.insert("10");
			}
		}
		else if(e == "?0") res.insert("10");
		else if(e == "?1") res.insert("01");
		else if(e == "??"){
			if(o == x+1) res.insert("10");
			if(z == y+1) res.insert("01");
			if(o < x+1 and z < y+1){
				res.insert("01");
				res.insert("10");
			}
		}
	}	
	
	foreach(it, res) cout << *it << endl;
	
	return 0;
}
