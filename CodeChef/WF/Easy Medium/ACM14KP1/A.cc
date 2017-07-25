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

struct point{
	double x;
	double y;
};

struct setpoint{
	double x;
	double y;
	int id;
};

bool operator<(const point &a, const point &b){
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

bool operator<(const setpoint &a, const setpoint &b){
	return a.y < b.y;
}

double dis(const point &a, const point &b){
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

set<setpoint> s;

void solve(int T){
	int n;
	cin >> n;
	
	vector<point> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i].x >> v[i].y;
	}
	
	sort(v.begin(), v.end());
	
	double ans = 1e9;
	int prev = 0;
	
	s.clear();
	
	for(int i = 0; i < n; i++){
		setpoint tmp;
		
		while(prev < i and v[i].x - v[prev].x > ans/2){
			tmp.x = v[prev].x, tmp.y = v[prev].y, tmp.id = prev;
			s.erase(tmp);
			prev++;
		}
	
		tmp.x = -1;
		tmp.id = -1;
		tmp.y = v[i].y - ans / 2;
		
		set<setpoint>::iterator it = s.lower_bound(tmp), jt;
		while(it != s.end() and abs(it->y - v[i].y) <= ans/2){
			jt = it;
			jt++;
			while(jt != s.end() and abs(jt->y - v[i].y) <= ans/2){
				point A, B;
				A.x = it->x;
				A.y = it->y;
				
				B.x = jt->x;
				B.y = jt->y;
				
				double d = dis(v[i], A) + dis(v[i], B) + dis(A, B);
				if(d < ans) ans = d;
				jt++;
			}
			it++;
		}
		
		tmp.x = v[i].x;
		tmp.y = v[i].y;
		tmp.id = i;
		s.insert(tmp);
	}
	
	cout << "Case " << T << ": " << fixed << setprecision(11) << ans << endl;
}

int main(){ _
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		solve(i);
	}
	return 0;
}
