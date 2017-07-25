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


void print(int x){
	cout << x << ' ';
}

set<int> s;

int main(){ _
	int n, k;
	int a, b, c, d;	
	
	cin >> n >> k;
	cin >> a >> b >> c >> d;
	
	if(n == 4 or k <= n){
		cout << -1 << endl;
		return 0;
	}
	
	for(int i = 1; i <= n; i++) s.insert(i);
	
	s.erase(a);
	s.erase(b);
	s.erase(c);
	s.erase(d);
	
	if(n == 5){
		int e = *s.begin();
		print(a);
		print(c);
		print(e);
		print(d);
		print(b);
		
		cout << '\n';
		
		print(c);
		print(a);
		print(e);
		print(b);
		print(d);
		
		cout << '\n';
		
		return 0;
	}
	
	int x = *s.begin(); s.erase(x);
	int y = *s.begin(); s.erase(y);
	
	print(a);
	print(c);
	print(x);
	foreach(it, s) print(*it);
	print(y);
	print(d);
	print(b);
	
	cout << '\n';
	
	print(c);
	print(a);
	print(x);
	foreach(it, s) print(*it);
	print(y);
	print(b);
	print(d);
		
	cout << '\n';
	
	return 0;
}
