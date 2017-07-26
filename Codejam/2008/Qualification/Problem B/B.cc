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

int stringToMinutes(string s){
	return ((s[0]-'0')*10 + (s[1]-'0'))*60 + ((s[3]-'0')*10 + (s[4]-'0'));
}

void solve(int cn){
	int t;
	sd(t);
	int na, nb;
	sd2(na, nb);
	
	int ans1 = 0, ans2 = 0;
	int cnt1 = 0, cnt2 = 0;
	
	string depart, arrive;
	
	vector<pair<int, pii> > e;
	
	for(int i = 0; i < na; i++){
		cin >> depart >> arrive;
		
		int t1 = stringToMinutes(depart);
		int t2 = stringToMinutes(arrive);
	
		e.pb(mp(t1,mp(1,0)));
		e.pb(mp(t2+t,mp(0,1)));
	}
	
	for(int i = 0; i < nb; i++){
		cin >> depart >> arrive;
		
		int t1 = stringToMinutes(depart);
		int t2 = stringToMinutes(arrive);
	
		e.pb(mp(t1,mp(1, 1)));
		e.pb(mp(t2+t,mp(0,0)));
	}
	
	sort(e.begin(), e.end());
	
	foreach(it, e){
		int st = it->se.se;
		int type = it->se.fi;
		
		if(st == 0){
			if(type == 0){
				cnt1++;
			}
			else{
				if(cnt1 == 0) ans1++;
				else cnt1--;
			}
		}
		else{
			if(type == 0){
				cnt2++;
			}
			else{
				if(cnt2 == 0) ans2++;
				else cnt2--;
			}
		}
	}
	
	printf("Case #%d: %d %d\n", cn, ans1, ans2);
	
}

int main(){
	int n;
	sd(n);
	for(int i = 1; i <= n; i++){
		solve(i);
	}	
	return 0;
}
