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

const long double PI = 3.1415926535897932384626433832795;

const int M = 21;
const int N = 1 << M;

string l, r;
int n;

int len[M];
int comp[N];

void fix(){
	int diff = r.length() - l.length();
	string tmp = l;
	l = "";
	while(diff--) l += '0';
	l += tmp;
}

void compare(){
	if(l[n-1] == r[n-1]) comp[n-1] = 0;
	else if(l[n-1] > r[n-1]) comp[n-1] = 1;
	else comp[n-1] = -1;
	
	for(int i = n-2; i >= 0; i--){
		if(l[i] < r[i]) comp[i] = -1;
		else if(l[i] > r[i]) comp[i] = 1;
		else comp[i] = comp[i+1];
	}
}

string sub(string &s, string &t){
	vector<int> u, v, res;
	int l = s.length();
	
	for(int i = 0; i < l; i++) u.pb(s[i] - '0');
	for(int i = 0; i < l; i++) v.pb(t[i] - '0');
	
	res.resize(l);
	
	for(int i = l-1; i >= 0; i--){
		res[i] = u[i] - v[i];
		if(res[i] < 0){
			res[i] += 10;
			u[i-1]--;
		}
	}
	
	string ret;
	for(int i = 0; i < l; i++) ret += (char) ('0' + res[i]);
	
	return ret;
	
}

string sub(string &s, int i){
	int l = s.length();
	string t;
	for(int i = 0; i < l; i++){
		t += '0';
	}
	t[l-1] = '1';
	return sub(s,t);
}

string add(string &s){
	vector<int> u;
	int l = s.length();
	
	for(int i = 0; i < l; i++){
		u.pb(s[i] - '0');
	}
	
	reverse(u.begin(), u.end());
	
	for(int i = 0; i < l; i++){
		u[i]++;
		if(u[i] == 10){
			u[i] = 0;
			if(i+1 == l)
				u.pb(1);
			else
				u[i+1]++;
		}
		else break;
	}
	
	reverse(u.begin(), u.end());
	
	string res;
	for(int i = 0; i < u.size(); i++){
		res += (char)('0' + u[i]);
	}
	
	return res;
}

bool allnines(string s){
	foreach(it, s){
		if(*it != '9') return false;
	}
	return true;
}

string clean(string s){
	int i = 0;
	if(s.length() == 1) return s;
	string t;
	while(i < s.length() and s[i] == '0') i++;
	while(i < s.length()) t += s[i++];
	return t;
}

vector<pair<int, string> > ans;

int main(){ _
	cin >> l >> r;

	len[0] = 0;
	for(int i = 1; i < M; i++) len[i] = (1 << (i-1));
	
	fix();
	
	assert(l.length() == r.length());
	n = l.length();
	
	compare();
	
	int i = 0;
	while(i < n){
		while(i < n and l[i] == r[i]) i++;
		if(i == n) break;
		
		int dl = n - 1 - i;
				
		int j = 0;
		while(j < M and len[j] <= dl) j++;
		if(j > 0)
			j--;
		
		if(comp[i] == -1){
			string str1 = l.substr(i, n-len[j]-i);
			string str2 = r.substr(i, n-len[j]-i);
			
			ans.pb(mp(j, sub(str2, str1)));
			
			i = n-1-len[j]+1;
		}
		else{
			string str1 = l.substr(i, n-len[j]-i);
			string str2 = r.substr(i, n-len[j]-i);
			str1 = "0" + sub(str1, str2);
			
			string str3(str1.length(), '0');
			str3[0] = '1';
		
			str1 = sub(str3, str1);
			
			ans.pb(mp(j, str1));
			assert(ans.size() > 1);
			
			int k = ans.size();
			ans[k-2].se = sub(ans[k-2].se, 1);
			
			i = n-1-len[j]+1;
		}
	}
	
	foreach(it, ans){
		it->se = clean(it->se);
	}
	
	for(int i = (int) ans.size() - 1; i >= 0; i--){
		if(allnines(ans[i].se)){
			ans[i-1].se = add(ans[i-1].se);
			ans[i].fi = -1;
		}
	}
	
	vector<pair<int, string> > fin;
	foreach(it, ans){
		if(it->fi != -1) fin.pb(*it);
	}
	
	cout << fin.size() << '\n';
	foreach(it, fin){
		cout << it->fi << ' ' << it->se << '\n';
	}
	
	
	
	return 0;
}
