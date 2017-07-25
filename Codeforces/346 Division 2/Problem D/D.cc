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

#define N 'N'
#define S 'S'
#define E 'E'
#define W 'W'

int n;

char w, u1, u2;

vector<pii> pts;

char getdir(const pii &p1, const pii &p2){
	if(p1.fi == p2.fi){
		if(p2.se > p1.se) return 'N';
		else return 'S';
	}
	else{
		if(p2.fi > p1.fi) return 'E';
		else return 'W';
	}
}

int main(){
	sd(n);
	n++;
	
	int x, y;
	for(int i = 0; i < n; i++){
		sd2(x,y);
		pts.pb(mp(x,y));
	}
	pts.pb(pts[1]);
	
	int ans = 0;
	w = 'E';
	for(int i = 1; i < n; i++){
		u1 = getdir(pts[i-1], pts[i]);
		u2 = getdir(pts[i], pts[i+1]);
		
		if(u1 == N){
			if(u2 == W){
				if(w == E){
					ans++;
					w = N;
				}
				else{
					w = S;
				}
			}
			else{
				if(w == E){
					w = S;
				}
				else{
					ans++;
					w = N;
				}
			}
		}
		else if(u1 == S){
			if(u2 == W){
				if(w == E){
					ans++;
					w = S;
				}
				else{
					w = N;
				}
			}
			else{
				if(w == E){
					w = N;
				}
				else{
					ans++;
					w = S;
				}
			}
		}
		else if(u1 == W){
			if(u2 == N){
				if(w == S){
					ans++;
					w = W;
				}
				else{
					w = E;
				}
			}
			else{
				if(w == S){
					w = E;
				}
				else{
					ans++;
					w = W;
				}
			}
		}
		else if(u1 == E){
			if(u2 == N){
				if(w == S){
					ans++;
					w = E;
				}
				else{
					w = W;
				}
			}
			else{
				if(w == S){
					w = W;
				}
				else{
					ans++;
					w = E;
				}
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
