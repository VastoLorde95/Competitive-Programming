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

const int N = 26;

vector<pii> v;

char getchar(int i){
	return (char) ('a' + i);
}

bool cmp(const pii &p1, const pii &p2){
	return p1.se < p2.se;
}

int main(){ _
	int x, lenn = 0;	
	for(int i = 0; i < N; i++){
		cin >> x;
		v.pb(mp(x, i));
		lenn += x;
	}
	
	sort(v.begin(), v.end());

	string res;

	x = 0;
	while(x < N and v[x].fi == 0) x++;	
	
	sort(v.begin()+x+1, v.end(), cmp);
	
	bool flag = true;
	for(int j = x+1; j < N; j++){
		if(v[x].se > v[j].se) flag = false;
	}
	
	if(v[x].fi <= 2 and flag){
		while(x < N){
			while(v[x].fi--) res += getchar(v[x].se);
			x++;
		}
		
		assert(res.length() == lenn);
		
		cout << res << endl;
		return 0;
	}
	if(v[x].fi == 3 and flag){
		res += getchar(v[x].se);
		res += getchar(v[x].se);
		int y = x;
		v[y].fi = 1;
		x++;
		while(x < N){
			while(v[x].fi--){
				res += getchar(v[x].se);
				while(v[y].fi > 0){
					res += getchar(v[y].se);
					v[y].fi--;		
				}
			}
			x++;
		}
		while(v[y].fi > 0){
			res += getchar(v[y].se);
			v[y].fi--;
		}
		
		assert(res.length() == lenn);
	
		cout << res << endl;
		return 0;
	}
	if(v[x].fi > 3 and flag){
		res += getchar(v[x].se);
		res += getchar(v[x].se);
		v[x].fi -= 2;
		int y = x;
		x++;
		while(x < N){
			while(v[x].fi--){
				res += getchar(v[x].se);
				if(v[y].fi > 0){
					res += getchar(v[y].se);
					v[y].fi--;		
				}
			}
			x++;
		}
		while(v[y].fi > 0){
			res += getchar(v[y].se);
			v[y].fi--;
		}
		
		assert(res.length() == lenn);
	
		cout << res << endl;
		return 0;
	}
	
	res += getchar(v[x].se);
	v[x].fi--;
	
	sort(v.begin() + x, v.end(), cmp);
	while(x < N){
		while(v[x].fi--) res += getchar(v[x].se);
		x++;
	}
	assert(res.length() == lenn);
	
	cout << res << endl;

	return 0;
}
