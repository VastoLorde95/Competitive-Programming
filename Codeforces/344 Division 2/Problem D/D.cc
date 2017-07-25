#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(__typeof((v).begin()) it=(v).begin(); it != (v).end(); ++it)
#define meta __FUNCTION__,__LINE__

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;
typedef pair<int,int> pii;

const int N = 200100;

int f[N];

void build_f(vector<pair<ll, char> > &s){
	f[0] = 0;
	f[1] = 0;
	int l = s.size();
	for(int i = 2; i <= l; i++){
		int j = f[i-1];
		while(true){
			if(s[j].se == s[i-1].se and ((j == 0 and s[j].fi <= s[i-1].fi) or (j != 0 and s[j].fi == s[i-1].fi))){
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

long long answer = 0;

bool match(vector<pair<ll, char> > &s, vector<pair<ll, char> > &t){	// pattern, string
	int l1 = s.size(), l2 = t.size();
	for(int i = 0, j = 0; j < l2;){
		if(t[j].se == s[i].se and (((i == 0 or i == l1-1) and s[i].fi <= t[j].fi) \
		 or ((i != 0 and i != l1-1) and s[i].fi == t[j].fi))) {	// try to expand the prefix ending at index i with character t[j]
			j++, i++;
			if(i == l1){
				i = f[i];		// uncomment if you want to find other occurences
				answer++;
			}
		}
		else if(i > 0) i = f[i];	// try the next/prefix suffix to match
		else j++;	// no match found, try from the empty string again
	}
	return false;
}

int n, m;
vector<string> t, s;
vector<pair<ll,char> > x, y;

void get(string &str, int &num, char &c){
	num = 0;
	for(int i = 0; i < str.length(); i++){
		if(str[i] == '-') break;
		num *= 10;
		num += (str[i] - '0');
	}
	c = str[str.length() - 1];
}

void parse(vector<string> &v, vector<pair<ll,char> > &res){
	char prev = '0';
	for(int i = 0; i < v.size(); i++){
		int L; char c;
		get(v[i], L, c);
		if(c == prev){
			res.back().fi += L;
		}
		else{
			res.pb(mp(L,c));
			prev = c;
		}
	}
}

int main(){ _
	cin >> n >> m;
	t.resize(n);
	s.resize(m);
	
	for(int i = 0; i < n; i++){
		cin >> t[i];
	}
	for(int i = 0; i < m; i++){
		cin >> s[i];
	}
	
	parse(t, x);
	parse(s, y);
	
	if(y.size() > 1){
		build_f(y);
		match(y,x);
	}
	else if(y.size() == 1){
		pair<int, char> p = y[0];
		for(int i = 0; i < x.size(); i++){
			if(p.se == x[i].se and p.fi <= x[i].fi){
				answer += x[i].fi - p.fi + 1;
			}
		}
	}
	
	cout << answer << endl;
	
	return 0;
}
