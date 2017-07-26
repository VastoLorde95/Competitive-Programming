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

int n, m;
string s;

void stackToString(stack<char> &stck, string &s){
	// empty the stack
	while(!stck.empty()) s += stck.top(), stck.pop();
	for(int i = 0, j = s.length()-1; i < j; i++, j--) swap(s[i], s[j]);
//	tr(s);
}

string solve(){
	string ans;
	stack<char> stck;
		
	int to_remove = m;
	for(int i = 0; i < n; i++){
//		tr(i, s[i]);
		if(!to_remove) stck.push(s[i]);
		else{
			while(!stck.empty() and stck.top() < s[i] and to_remove) stck.pop(), to_remove--;
			stck.push(s[i]);
		}
	}
	
	stackToString(stck, ans);
	return ans;
}

int main(){ _
	cin >> n >> m >> s;
	cout << solve();
	return 0;
}
