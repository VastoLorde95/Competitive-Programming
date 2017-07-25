#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define meta __FUNCTION__<<' '<<__LINE__<<' '
#define tr(x) cout<<meta<<#x<<' '<<x<<'\n';
#define tr2(x,y) cout<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<'\n';
#define tr3(x,y,z) cout<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr4(w,x,y,z) cout<<meta<<#w<<' '<<w<<' '<<#x<<' ' <<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr5(v,w,x,y,z) cout<<meta<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr6(u,v,w,x,y,z) cout<<meta<<#u<<' '<<u<<' '<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.first<<", "<<p.second<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
int l = v.size(); for(int i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

typedef long long ll;

ll n;

int main(){ _
	cin >> n;
	
	if(n == 0){
		cout << "0 0" << endl;
		return 0;
	}
	
	ll lo = 0, hi = 600000000, mid;
	while(lo+1 < hi){
		mid = (lo+hi)/2;
		if(1+(mid*(mid+1))*3 <= n+1) lo = mid;
		else hi = mid;
	}
	
	
	ll x, y;
	if(lo == 0){
		x = 2, y = 0;
		lo++;
	}
	else{
		n -= (lo*(lo+1)*3);
		lo++;
		x = 2*(lo), y = 0;
	}

	if(n == 0){
		x -= 2;
	}

	for(int i = 0; i < 6 and n > 0; i++){
//		tr5(i,x,y,lo,n);
		if(lo <= n){
			if(i == 0){
				x -= lo;
				y += 2*lo;
			}
			else if(i == 1){
				x -= 2*lo;
			}
			else if(i == 2){
				x -= lo;
				y -= 2*lo;
			}
			else if(i == 3){
				x += lo;
				y -= 2*lo;
			}
			else if(i == 4){
				x += 2*lo;
			}
			else if(i == 5){
				x += lo;
				y += 2*lo;
			}
			n -= lo;
		}
		else{
			lo = n;	
			if(i == 0){
				x -= lo;
				y += 2*lo;
			}
			else if(i == 1){
				x -= 2*lo;
			}
			else if(i == 2){
				x -= lo;
				y -= 2*lo;
			}
			else if(i == 3){
				x += lo;
				y -= 2*lo;
			}
			else if(i == 4){
				x += 2*lo;
			}
			else if(i == 5){
				x += lo;
				y += 2*lo;
			}
			break;
		}
	}
	
	cout << x << " " << y << endl;
	
	return 0;
}
