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

const int N = 5010;
const int M = 1010;

int n, m;

int mx[M];
int mn[M];

unordered_map<string, int> sid;

vector<int> var;
string con[N];
vector<string> op[N];

int bitval[N];

vector<string> split(string &s){
	vector<string> ret;
	
	string tmp;
	for(char c : s){
		if(c == ' '){
			ret.pb(tmp);
			tmp = "";
		}
		else{
			tmp += c;
		}
	}
	
	
	if(tmp.length())
		ret.pb(tmp);
	return ret;
}

inline int get(int &a, int &b, string &op){
	if(op[0] == 'X') return a ^ b;
	if(op[0] == 'A') return a & b;
	if(op[0] == 'O') return a | b;
}

int main(){ _
	cin >> n >> m;
	
	sid.reserve(8196);
	sid.max_load_factor(0.25);
	
	sid["?"] = 0;
	
	string line;
	getline(cin, line);
	for(int i = 1; i <= n; i++){
		getline(cin, line);
		vector<string> v = split(line);
		
		vector<string> vv;
		for(int i = 2; i < v.size(); i++){
			vv.pb(v[i]);
		}
		
		sid[v[0]] = i;
		
		var.pb(i);
		if(vv.size() == 1){
			con[i] = vv[0];
		}
		else{
			op[i] = vv;
		}
	}
	
	for(int i = 0; i < m; i++){
		int cnt1 = 0, cnt2 = 0;
		
		memset(bitval, 0, sizeof bitval);
		bitval[0] = 0;
		
		for(int j = 1; j <= n; j++){
			if(con[j].length() != 0){
				bitval[j] = con[j][i] - '0';
			}
			else{
				string o = op[j][1];
				int a = sid[op[j][0]];
				int b = sid[op[j][2]];
			
				bitval[j] = get(bitval[a], bitval[b], o);
			}
			cnt1 += bitval[j];
		}

		memset(bitval, 0, sizeof bitval);
		bitval[0] = 1;
		
		for(int j = 1; j <= n; j++){
			if(con[j].length() != 0){
				bitval[j] = con[j][i] - '0';
			}
			else{
				string o = op[j][1];
				int a = sid[op[j][0]];
				int b = sid[op[j][2]];
			
				bitval[j] = get(bitval[a], bitval[b], o);
			}
			cnt2 += bitval[j];
		}
		
		if(cnt1 < cnt2){
			mn[i] = 0;
			mx[i] = 1;
		}
		else if(cnt2 < cnt1){
			mn[i] = 1;
			mx[i] = 0;
		}
		else{
			mn[i] = mx[i] = 0;
		}
	}
	
	for(int i = 0; i < m; i++) cout << mn[i];
	cout << endl;
	
	for(int i = 0; i < m; i++) cout << mx[i];
	cout << endl;
	
	return 0;
}
