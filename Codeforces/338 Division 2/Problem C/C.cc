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

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.first<<", "<<p.second<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
int l = v.size(); for(int i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

void build_f(string s, int f[]){
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

pair<int,int> match(string &s, string &t, int f[]){
	int l1 = s.length(), l2 = t.length();
	int mx = 0;
	pair<int,int> ret = mp(-1,-1);
	for(int i = 0, j = 0; j < l2;){
		if(t[j] == s[i]){
			j++, i++;
			if(i == l1){
				return mp(j-l1+1, j);
			}
			
			if(i > mx){
				mx = i;
				ret = mp(j-i+1, j);
			}
			
		}
		else if(i > 0) i = f[i];
		else j++;
	}
	return ret;
}

const int N = 2200;

int f[N];
string s, r, t;
vector<pair<int,int> > ans;

int main(){ _
	cin >> s >> t;
	r = s;
	reverse(r.begin(), r.end());
	
	int l = t.length(), k = s.length();
	for(int i = 0; i < l; i++){
		string x = t.substr(i, l-i);
		build_f(x, f);
		
		pair<int,int> p1 = match(x,s,f);
		pair<int,int> p2 = match(x,r,f);
		
		if(p1.fi == -1 and p2.fi == -1){
			puts("-1");
			return 0;
		}
		
//		tr3(p1,p2,k);
		
		if(p1.se - p1.fi > p2.se - p2.fi){
			ans.pb(p1);
			i += p1.se - p1.fi;
		}
		else{
			p2.fi = k - p2.fi + 1, p2.se = k - p2.se + 1;
			ans.pb(p2);
			i += p2.fi - p2.se;
		}
	}
	
	printf("%d\n", (int) ans.size());
	foreach(it, ans){
		printf("%d %d\n", it->fi, it->se);
	}
	
	
	
	
	return 0;
}
