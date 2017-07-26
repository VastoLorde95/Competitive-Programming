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

// z[i] = the length of the longest substring of 's' starting at index 'i' which is at the same time a prefix of the string 's'
int z[1000001];
string s;

void build_z(){					// l, r are the invariant variables => [l,r] is the maximum interval such that s[l,r] is a prefix substring
	int len = s.length(), l = 0, r = 0, k;
	z[0] = len;
	
	for(int i = 1; i < len; i++){
		if(r < i){				// make a new interval l,r and find the substring starting at i which is a prefix substring
			l = r = i; 
			while(r < n and s[r-l] == s[r]) r++;
			z[i] = r-l; r--;
		}
		else{					// try to expand the current interval by observing the value of z[k]
			k = i-l;
			if(z[k] < r-i+1){		// can't be more than z[k] since s[i..R] matches with s[k...z[k]]
				z[i] = z[k];
			}
			else{				// we can expand the current r since z[k] allows us to do so
				l = i;
				while(r < n and s[r-l] == s[r]) r++;
				z[i] = r-l; r--;
			}
		}
	}
	return;	
}

int main(){
	return 0;
}
