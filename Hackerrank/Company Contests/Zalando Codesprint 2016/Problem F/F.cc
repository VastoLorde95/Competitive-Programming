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

const long double PI = 3.1415926535897932384626433832795;

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

int ans = 0;

void go(int id, int cur, vector<int> v, int x, int y, int z){
	ans = max(ans, cur);
	if(id == 8){
		return;
	}
	
	int del, old;
	int nx, ny, nz;
	for(int j = 0; j < 8; j++){
		if(v[j] == -1) continue;
		if(v[j] == 0){
			v[j] = -1;
			go(id+1, cur, v, x, y, z);
			v[j] = 0;
			continue;
		}
		
		del = v[j];
		
		if((j&1) > 0) del = min(del, x);
		if((j&2) > 0) del = min(del, y);
		if((j&4) > 0) del = min(del, z);
		
		old = v[j];
		v[j] = -1;
	
		nx = x, ny = y, nz = z;
		if((j&1) > 0) nx -= del;
		if((j&2) > 0) ny -= del;
		if((j&4) > 0) nz -= del;
		
		go(id+1, cur+del, v, nx, ny, nz);
		v[j] = old;
	}
}

int cnt[8];
int main(){
	int a, b, c;
	int m;
	sd3(a,b,c);
	sd(m);
	while(m--){
		string s;
		cin >> s;
		int msk = 0;
		for(int i = 0; i < s.length(); i++){
			if(s[i] == 'A') msk |= 1;
			if(s[i] == 'B') msk |= 2;
			if(s[i] == 'C') msk |= 4;
		}
		cnt[msk]++;
	}
	
	vector<int> v;
	for(int j = 0; j < 8; j++){
		v.pb(cnt[j]);
	}
	
	go(0, 0, v, a, b, c);
	
	tr(ans);
	
	return 0;
}
