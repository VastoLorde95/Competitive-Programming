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

int main(){ _
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	int ans1 = 0, len = 0, ans2 = 0;
	bool in = false, word = false;
	
	for(int i = 0; i < n; i++){
		if(s[i] == '('){
			in = true;
			if(word and len > ans1) ans1 = len;
			word = false;
			len = 0;
		}
		else if(s[i] == ')'){
			in = false;	
			if(word) ans2++;
			word = false;
		}
		else if(s[i] == '_'){
			if(word){
				if(in) ans2++;
				else if(!in) ans1 = max(ans1, len);
				len = 0;
				word = false;
			}
		}
		else{
			word = true;
			if(!in) ans1 = max(ans1, ++len);
		}
	}
	
	if(len > ans1) ans1 = len;

	cout << ans1 << ' ' << ans2 << endl;
	
	return 0;
}
