#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <stack>

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

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

typedef long long ll;

int l, q;
ll a, b;
char x;
vector<pair<ll, ll> > pos[26];
vector<pair<ll, ll> >::iterator it;
string s;
ll up = 1e18;

ll count(ll r, int c){
	if(r == 0) return 0;
	ll ret = 0;
	
	while(r){
		it = upper_bound(pos[c].begin(), pos[c].end(), mp(r,up*2LL));
		if(it == pos[c].begin()) break;
		it--;
		ret += (r / it->fi) * it->se;
		r %= it->fi;
	}
	
	return ret;
}

int main(){
	cin >> s;
	l = s.length();
	for(int i = 0; i < 26; i++){
		ll cnt = 0, r = 0;
		char c = char(i + 'a');
		
		for(int j = 0; j < l and r <= up; j++){
			if(s[j] >= '0' and s[j] <= '9'){
				ll digit = s[j] - '0';
				cnt *= digit, r *= digit;
			}
			else if(s[j] == c)
				cnt++, r++;
			else 
				r++;
			pos[i].pb(mp(r,cnt));
		}
	}
	
	sd(q);
	while(q--){
		 scanf(" %c %lld %lld", &x, &a, &b);
		 int c = x - 'a';
		 
		 printf("%lld\n", count(b,c) - count(a-1,c));
	}
	
	return 0;
}
