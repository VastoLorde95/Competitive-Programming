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

const int M = 10100;

int n, m;

vector<pair<int, string> > reg[M];

int main(){ _
	cin >> n >> m;
	
	string name; int region, score;
	for(int i = 1; i <= n; i++){
		cin >> name >> region >> score;
		reg[region].pb(mp(score, name));
	}
	
	for(int i = 1; i <= m; i++){
		sort(reg[i].begin(), reg[i].end(), greater<pair<int, string> >());
		
		if(reg[i].size() == 2){
			cout << reg[i][0].se << " " << reg[i][1].se << endl;
			continue;
		}
		
		if((reg[i][0].fi == reg[i][1].fi and reg[i][1].fi != reg[i][2].fi) or (reg[i][0].fi != reg[i][1].fi  and reg[i][1].fi != reg[i][2].fi)){
			cout << reg[i][0].se << " " << reg[i][1].se << endl;
		}
		else cout << "?" << endl;
	}
	
	return 0;
}
