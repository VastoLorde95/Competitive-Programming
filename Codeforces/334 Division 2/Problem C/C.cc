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

const int N = 100100;

int n;
char s[N];

int l1, l2;
int m1, m2;
int c1, c2;
int cnt = 1;

int main(){
	sd(n);
	scanf("%s", s);
	
	if(s[0] == '1') l1 = 1; else l2 = 1;
	for(int i = 1; i < n; i++){
		if(s[i] == s[i-1]){
			if(l1 > 0) l1++;
			else l2++;
		}
		else{
			cnt++;
			if(l1 > 0){
				if(l1 > 1) c1++;
				m1 = max(m1, l1);
				l1 = 0, l2 = 1;
			}
			else{
				if(l2 > 1) c2++;
				m2 = max(m2, l2);
				l1 = 1, l2 = 0;
			}
		}
	}	

	if(l1 > 1) c1++;
	if(l2 > 1) c2++;
	m1 = max(m1, l1);
	m2 = max(m2, l2);
	
	if(m1 > 2 or m2 > 2){
		cnt += 2;
	}
	else if(m1 > 1 and m2 > 1){
		cnt += 2;
	}
	else if(c1 > 1 or c2 > 1){
		cnt += 2;
	}
	else if(c1 == 1 or c2 == 1){
		cnt++;
	}
	
	cout << cnt << endl;
	
	return 0;
}
