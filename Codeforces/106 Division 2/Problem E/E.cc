#include <bits/stdc++.h>

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

#define meta __FUNCTION__<<' '<<__LINE__<<' '
#define tr(x) cout<<meta<<#x<<' '<<x<<'\n';
#define tr2(x,y) cout<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<'\n';
#define tr3(x,y,z) cout<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr4(w,x,y,z) cout<<meta<<#w<<' '<<w<<' '<<#x<<' ' <<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr5(v,w,x,y,z) cout<<meta<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr6(u,v,w,x,y,z) cout<<meta<<#u<<' '<<u<<' '<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';

using namespace std;

void build(string &s, int f[]){
	f[0] = f[1] = 0;
	for(int i = 2; i <= s.length(); i++){
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

void match(string &s, string &t, int f[], int m[]){
	memset(m, 0, sizeof m);
	for(int i = 0, j = 0; j < t.length();){
		if(t[j] == s[i]){	// try to expand the prefix ending at index i with character t[j]
			i++;
			
			if(j == 0) m[j] = i;
			else m[j] = max(m[j-1], i);
			
			if(i == s.length()){
				i = f[i];
			}
			
			j++;
		}
		else if(i > 0) i = f[i];	// try the next/prefix suffix to match
		else{
			if(j == 0) m[j] = i;
			else m[j] = max(m[j-1], i);
			j++;	// no match found, try from the empty string again
		}
	}
	return;
}

const int N = 100100, M = 101;

string s, rs, t;
int n, m, f1[N], f2[N], m1[N], m2[N];
int ans;

int main(){	_
	cin >> s >> m;
	n = s.length();
	 	
	rs = s;
	reverse(rs.begin(), rs.end());
	
	for(int i = 0; i < m; i++){
		cin >> t;
		
		if(t.length() == 1) continue;
		
		build(t, f1);
		match(t, s, f1, m1);

		reverse(t.begin(), t.end());

		build(t, f2);
		match(t, rs, f2, m2);
		
		for(int j = 0; j+1 < n; j++){
			if(m1[j] + m2[n-j-2] >= t.length()){
				ans++;
				break;
			}
		}
	}
	
	
	cout << ans << '\n';
	
	
	return 0;
}
