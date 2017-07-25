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

void solve(){
	string s;
	cin >> s;
	
	int n = s.length();
	
	int a = 0, b = 0;
	for(char c : s) if(c == 'A') a++; else b++;
	
	if(a == 2){
		cout << "A" << endl;
		return;
	}
	else if(b == 2){
		cout << "B" << endl;
		return;
	}
	if(n == 2){
		cout << -1 << endl;
		return;
	}
	
	int pos = -1;
	if(s[0] == s[1] and s[1] != s[2]){
		pos = 0;
	}
	else if(s[n-1] == s[n-2] and s[n-2] != s[n-3]){
		pos = n-2;
	}
	
	for(int i = 1; i < n-2; i++){
		if(s[i] == s[i+1] and s[i-1] != s[i] and s[i+2] != s[i]){
			pos = i;
			break;
		}
	}

	if(pos == -1) cout << pos << endl;
	else{
		for(int i = 0; i < n; i++){
			if(pos == i) continue;
			cout << s[i];
		}
		cout << endl;
	}
	
}

int main(){
	int t;
	cin >> t;
	while(t--) solve();	
	return 0;
}
