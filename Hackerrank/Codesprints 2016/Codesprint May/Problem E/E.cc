#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(__typeof((v).begin()) it=(v).begin(); it != (v).end(); ++it)
#define rofeach(it, v) for(__typeof((v).rbegin()) it=(v).rbegin(); it != (v).rend(); ++it)
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

const int M = 22;
const int N = 1 << M;

string l, r;
int n;

int len[M];

void fix(){
	int diff = r.length() - l.length();
	string tmp = l;
	l = "";
	while(diff--) l += '0';
	l += tmp;
}

map<int, vector<int> > cnt;
map<int, vector<int> > cnt2;

vector<int> u, v;

void add(vector<int> &v1, vector<int> v2){
	while(v1.size() < v2.size()) v1.pb(0);
	while(v2.size() < v1.size()) v2.pb(0);
	
	for(int i = 0; i < v1.size(); i++){
		v1[i] += v2[i];
		if(v1[i] >= 10){
			v1[i] -= 10;
			if(i+1 == v1.size()){
				v1.pb(1);
				v2.pb(0);
			}
			else
				v1[i+1]++;
		}
	}
	
	
}

void increase(int id, int l, int r){
	vector<int> s;
	vector<int> t;
	
	bool ok = false;
	for(int i = l; i <= r; i++){
		if(u[i] != 0) ok = true;
	}
	
	if(!ok) return;
	
	for(int i = l; i <= r; i++){
		t.pb(u[i]);
		s.pb(0);
	}
	
	s.pb(1);
	t.pb(0);
	
	vector<int> res;
	res.resize(s.size());
	
	for(int i = 0; i < t.size(); i++){
		res[i] = s[i] - t[i];
		if(res[i] < 0){
			res[i] += 10;
			s[i+1]--;
		}
	}
	
	add(cnt[id], res);
}

void decrease(int id, int l, int r){
	vector<int> t;
	
	bool ok = false;
	for(int i = l; i <= r; i++){
		if(v[i] != 0) ok = true;
	}
	
	if(!ok) return;
	
	for(int i = l; i <= r; i++){
		t.pb(v[i]);
	}
	
	add(cnt2[id], t);
}

bool allnines(int id, vector<int> &v){
	if(id == 0){
		if(v[0] == 9) return true;
		return false;
	}
	
	int cnt = 0;
	for(int i = 0; i < v.size(); i++){
		cnt += (v[i] == 9);
	}
	
	return cnt == id;
}

void clean(vector<int> &v){
	while(!v.empty() and v.back() == 0) v.pop_back();
}

int main(){ _
	cin >> l >> r;
	
	if(l == r){
		cout << 1 << endl;
		cout << 0 << ' ' << 1 << endl;
		return 0;
	}
	
	len[0] = 0;
	for(int i = 1; i < M; i++) len[i] = (1 << (i-1));
	
	fix();
	
	n = l.length();
	
	int lim = 0;
	while(lim < n and l[lim] == r[lim]) lim++;
	lim = n - lim - 1;
	
	reverse(l.begin(), l.end());
	reverse(r.begin(), r.end());
	
	for(int i = 0; i < n; i++){
		u.pb(l[i] - '0');
		v.pb(r[i] - '0');
	}
	
	for(int i = 0; i < M; i++){
		int x = len[i];
		int y = len[i+1]-1;
				
		if(y < lim){
			increase(i, x, y);
			int j = y+1;
			while(++u[j] == 10) u[j++] -= 10;
			decrease(i, x, y);
		}
		else{
			y = lim;
			vector<int> s;
			vector<int> t;
			
			for(int j = x; j <= y; j++){
				s.pb(u[j]);
				t.pb(v[j]);
			}
			
			vector<int> res(y-x+1, 0);
			for(int j = 0; j < s.size(); j++){
				res[j] = t[j] - s[j];
				if(res[j] < 0){
					res[j] += 10;
					t[j+1]--;
				}
			}
			
			add(cnt[i], res);
			break;
		}
	}
	
	foreach(it, cnt2){
		add(cnt[it->fi], it->se);
	}
	
	
	vector<int> er;
	rofeach(it, cnt){
		clean(it->se);
		if(allnines(it->fi, it->se)){
			vector<int> one = {1};
			add(cnt[it->fi + 1], one);
			er.pb(it->fi);
		}
	}
	
	foreach(it, er) cnt.erase(*it);
	
	er.clear();
	
//	rofeach(it, cnt2){
//		clean(it->se);
//		if(allnines(it->fi, it->se)){
//			vector<int> one = {1};
//			add(cnt2[it->fi + 1], one);
//			er.pb(it->fi);
//		}
//		else if(it->se.empty()){
//			er.pb(it->fi);
//		}
//	}
//	
//	foreach(it, er) cnt2.erase(*it);
	
	cout << cnt.size() << endl;
	
	foreach(it, cnt){
		cout << it->fi << ' ';
		
		vector<int> v = it->se;
		reverse(v.begin(), v.end());
		foreach(itt, v) cout << *itt; cout << endl;
	}
	
//	for(map<int,vector<int> >::reverse_iterator it = cnt2.rbegin(); it != cnt2.rend(); it++){
//		cout << it->fi << ' ';
//		
//		vector<int> v = it->se;
//		reverse(v.begin(), v.end());
//		foreach(itt, v) cout << *itt; cout << endl;
//	}
	
		
	
	return 0;
}
