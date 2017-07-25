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

string getString(int a, int b, int c, int d){
	string s;
	s += (char)('0' + a);
	s += (char)('0' + b);
	s += ':';
	s += (char)('0' + c);
	s += (char)('0' + d);
	return s;
}

int main(){
	int x; cin >> x;
	string s; cin >> s;
	
	int d1 = s[0] - '0';
	int d2 = s[1] - '0';
	
	int d3 = s[3] - '0';
	int d4 = s[4] - '0';
	
	if(x == 24){
		string res = s;
		int cnt = 100;
		
		for(int i = 0; i < 24; i++){
			for(int j = 0; j < 60; j++){
				int x1 = i / 10, x2 = i % 10;
				int x3 = j / 10, x4 = j % 10;
				
				int c = (d1!=x1) + (d2!=x2) + (d3!=x3) + (d4!=x4);
				
				if(c < cnt){
					cnt = c;
					res = getString(x1,x2,x3,x4);
				}
			}
		}
		cout << res << endl;
		
	}
	else{
		string res = s;
		int cnt = 100;
		
		for(int i = 1; i <= 12; i++){
			for(int j = 0; j < 60; j++){
				int x1 = i / 10, x2 = i % 10;
				int x3 = j / 10, x4 = j % 10;
				
				int c = (d1!=x1) + (d2!=x2) + (d3!=x3) + (d4!=x4);
				
				if(c < cnt){
					cnt = c;
					res = getString(x1,x2,x3,x4);
				}
			}
		}
		
		cout << res << endl;
	}
		
	return 0;
}
