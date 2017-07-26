#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

const ld PI = 3.1415926535897932384626433832795;

string get(char a, int cnta, char b, int cntb, char c, int cntc, int n){
	if(cnta < 0 or cntb < 0 or cntc < 0) return "IMPOSSIBLE";
	
	string res;
	
	if(cnta == 0){
		if(cntc - cntb > 0) return "IMPOSSIBLE";
		
		while(cntb > 0){
			res += c;
			res += b;
			cntc--;
			cntb--;
		}
		
//		assert(cnta == 0 and cntb == 0 and cntc == 0 and res.length() == n);
		return res;
	}

	if(cntc - cnta <= cntb){
		while(cntc > cntb){
			res += a;
			res += c;
			cnta--;
			cntc--; 
		}
		
//		assert(cntc == cntb);
		
		while(cnta > 0){
			res += a;
			res += b;
			res += c;
			cnta--;
			cntb--;
			cntc--;
		}
		
		while(cntc > 0){
			res += b;
			res += c;
			cntb--;
			cntc--;
		}
		
//		assert(cnta == 0 and cntb == 0 and cntc == 0 and res.length() == n);
		return res;
	}
	return "IMPOSSIBLE";
}

string get(char c1, char c2, int m){
	string res;
	while(m--){
		res += c1;
		res += c2;
	}
	
	return res;
}

void update(char c1, char c2, int num, string &res){
	string tmp;
	bool flag = true;
	for(int i = 0; i < res.length(); i++){
		tmp += res[i];
		if(res[i] == c1 and flag){
			while(num--){
				tmp += c2;
				tmp += c1;
			}				
			flag = false;
		}
	}
	
	res = tmp;
}

void solve(){
	int n, r, o, y, g, b, v;
	cin >> n >> r >> o >> y >> g >> b >> v;

	if(r == g and r + g == n){
		cout << get('R', 'G', r) << endl;
		return;
	}
	if(y == v and y + v == n){
		cout << get('Y', 'V', y) << endl;
		return;
	}
	if(b == o and b + o == n){
		cout << get('B', 'O', b) << endl;
		return;
	}

	if(g > 0 and r - g <= 0){
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	if(v > 0 and y - v <= 0){
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	if(o > 0 and b - o <= 0){
		cout << "IMPOSSIBLE" << endl;
		return;
	}

	vector<pair<int, char> > vec;
	vec.pb(mp(r-g, 'R'));
	vec.pb(mp(y-v, 'Y'));
	vec.pb(mp(b-o, 'B'));
	
	sort(vec.begin(), vec.end());
	
	string res = get(vec[0].se , vec[0].fi, vec[1].se, vec[1].fi, vec[2].se, vec[2].fi, n - g-v-o);
	
	if(res == "IMPOSSIBLE"){
		cout << res << endl;
		return;
	}
	
	if(g > 0){
		update('R', 'G', g, res);
	}
	if(v > 0){
		update('Y', 'V', v, res);
	}
	if(o > 0){
		update('B', 'O', o, res);
	}
	
	cout << res << endl;
		
	
}

int main(){ _
	int t;
	cin >> t;
	
	for(int i = 1; i <= t; i++){
		cout << "Case #" << i << ": ";
		solve();
	}
	
	return 0;
}
