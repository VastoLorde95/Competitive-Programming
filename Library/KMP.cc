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

void build_f(string &s, int f[]){
	f[0] = f[1] = 0;
	int l1 = s.length();
	for(int i = 2; i <= l1; i++){
		int j = f[i-1];
		while(true){
			if(s[j] == s[i-1]){
				f[i] = j+1; break;	// match found, next char to match is j+1
			}
			else if(j == 0){
				f[i] = 0; break; // no match found
			}
			j = f[j];	// try next prefix/suffix
		}
	}
	return;	
}

bool match(string &s, string &t, int f[]){	// pattern, string
	int l1 = s.length(), l2 = t.length();
	for(int i = 0, j = 0; j < l2;){
		if(t[j] == s[i]){	// try to expand the prefix ending at index i with character t[j]
			j++, i++;
			if(i == l1){
//				i = f[i];		// uncomment if you want to find other occurences
				return true;	// match found
			}
		}
		else if(i > 0) i = f[i];	// try the next/prefix suffix to match
		else j++;	// no match found, try from the empty string again
	}
	return false;
}

const int N = 100100;

int f[N];
string s, t;

int main(){
	cin >> s >> t;
	return 0;
}
