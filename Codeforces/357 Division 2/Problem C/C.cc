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

const long double PI = 3.1415926535897932384626433832795;

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

const int N = 1000100;

struct line{
	string s;
	int x;
} ans[N];

int n;

map<int, int> m;

int main(){ _
	cin >> n;
	
	string s;
	int x;
	
	int cur =  0;
	
	for(int i = 0; i < n; i++){
		cin >> s;
		if(s[0] == 'i'){
			cin >> x;
			m[x]++;
			ans[cur].s = s;
			ans[cur].x = x;
			cur++;
		}
		else if(s[0] == 'g'){
			cin >> x;
			
			if(!m.count(x)){
				m[x] = 1;
				ans[cur].s = "insert";
				ans[cur].x = x;
				cur++;
			}
			
			while(true){
				int y = m.begin()->fi;
				if(y == x) break;
				
				m[y]--;
				if(m[y] == 0) m.erase(y);
				ans[cur++].s = "removeMin";
			}
			
			ans[cur].s = s;
			ans[cur].x = x;
			cur++;
		}
		else{
			if(m.empty()){
				ans[cur].s = "insert";
				ans[cur].x = 1;
				m[x] = 1;
				cur++;
			}
			int y = m.begin()->fi;
			m[y]--;
			if(m[y] == 0) m.erase(y);
			ans[cur++].s = s;
		}
	}
	
	tr(cur);
	for(int i = 0; i < cur; i++){
		cout << ans[i].s;
		if(ans[i].s[0] != 'r'){
			cout << ' ' << ans[i].x << '\n';
		}
		else cout << '\n';
	}
	
	return 0;
}
