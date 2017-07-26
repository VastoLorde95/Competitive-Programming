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

int p[30];

void solve(){
	int n;
	sd(n);
	
	int cnt = 0;
	for(int i = 0; i < n; i++){
		sd(p[i]);
		cnt += p[i];
	}
	
	set<pii> s;
	for(int i = 0; i < n; i++){
		s.insert(mp(-p[i], i));
	}
	
	while(cnt){
		pii tp = *s.begin();
		s.erase(tp);
		
		string r;
		r += (char)('A' + tp.se);
		cnt--;
		tp.fi++;
				
		if(!s.empty() and -s.begin()->fi >= (cnt/2)+1){
			pii tp2 = *s.begin();
			s.erase(tp2);
			cnt--;
			tp2.fi++;
			
			r += (char) ('A' + tp2.se);
			if(tp2.fi)
				s.insert(tp2);
		}
		if(tp.fi)
			s.insert(tp);
			
		printf("%s ", r.c_str());
	}
	puts("");
}


int main(){
    int t; sd(t);
    for(int T = 1; T <= t; T++){
        printf("Case #%d: ", T);
       	solve();
    }
	return 0;
}
