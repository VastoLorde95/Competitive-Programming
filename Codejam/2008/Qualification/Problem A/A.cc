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

set<string> st;

int solve(){
	int s;
	cin >> s;
	string str;
	
	getline(cin, str);
	st.clear();
	for(int i = 0; i < s; i++){
		getline(cin, str);
		st.insert(str);
	}
	
	int q;
	cin >> q;
	
	int ret = 0;
	set<string> tmp = st;
	
	getline(cin, str);
	while(q--){
		getline(cin, str);
		if(tmp.count(str)) tmp.erase(str);
		if(tmp.empty()){
			ret++;
			tmp = st;
			tmp.erase(str);
		}
	}
	
	return ret;
}

int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cout << "Case #" << i << ": " << solve() << endl;
	}
	return 0;
}
