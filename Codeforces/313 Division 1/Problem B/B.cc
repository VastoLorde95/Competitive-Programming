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

char s1[200200], s2[200200];

bool good(int x1, int y1, int x2, int y2){
	int l = y1-x1;
	if(l%2 == 1){
		for(int i = x1, j = x2; i < y1 and j < y2; i++, j++) if(s1[i] != s2[j]) return false;
		return true;
	}		
	
	int mid1 = (x1+y1)/2;
	int mid2 = (x2+y2)/2;
	
	if(good(x1,mid1,x2,mid2) and good(mid1,y1,mid2,y2)) return true;
	if(good(x1,mid1,mid2,y2) and good(mid1,y1,x2,mid2)) return true;
	return false;
}

int main(){
	scanf("%s %s", s1, s2);
	int l = strlen(s1);
	if(l%2 == 1){
		for(int i = 0; i < l; i++){
			if(s1[i] != s2[i]){
				puts("NO");
				return 0;
			}
		}
		puts("YES");
		return 0;
	}
	
	if(good(0,l,0,l)) puts("YES"); else puts("NO");
	
	return 0;
}
