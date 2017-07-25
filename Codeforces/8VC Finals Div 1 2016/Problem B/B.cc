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

ll up = 31;

ll s, x;
ll cnt;

int main(){
	cin >> s >> x;
	int up = 0;
	for(int i = 0; i < 60; i++){
		if((x&(1ll<<i)) > 0) up = i;
	}
	
	for(int i = 0; i <= up; i++){
		if((x&(1ll<<i)) > 0){
			cnt++;
			s -= (1ll<<i);
		}
	}
	
	bool ok = true;
	if(s%2) ok = false;
	for(int i = 0; i <= up; i++){
		if((x&(1ll<<i)) > 0 and (s&(1ll<<(i+1))) > 0) ok = false;
	}
		
	if(ok){
		if(s > 0)
			cout << (1ll<<cnt) << endl;
		else
			cout << (1ll<<cnt) - 2 << endl;
	}
	else{
		cout << 0 << endl;
	}
	return 0;
}
