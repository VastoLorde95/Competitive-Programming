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

const int INF = 1e9;

int h[6];
int a[6];
int ans[7];

int res = INF;

string s1, s2, s3, s4;

void add(int x){
	if(x == 0)
		s1 += 'a', s2 += 'b', s3 += 'b', s4 += 'b';
	else if(x == 1)
		s1 += 'b', s2 += 'a', s3 += 'b', s4 += 'b';
	else if(x == 2)
		s1 += 'b', s2 += 'b', s3 += 'a', s4 += 'b';
	else if(x == 3)
		s1 += 'b', s2 += 'b', s3 += 'b', s4 += 'a';
	else if(x == 4)
		s1 += 'b', s2 += 'b', s3 += 'a', s4 += 'a';
	else if(x == 5)
		s1 += 'b', s2 += 'a', s3 += 'b', s4 += 'a';
	else if(x == 6)
		s1 += 'a', s2 += 'b', s3 += 'b', s4 += 'a';
}

void solve(int x){
	for(int i = 0; i < 6; i++) a[i] = h[i];
	
	for(int i = 0; i < 3; i++) a[i] -= x;
	
	a[3] -= a[0] + a[1];
	a[4] -= a[0] + a[2];
	a[5] -= a[1] + a[2];
	
	int *v = new int[6];
	for(int i = 3; i < 6; i++){
		if(a[i] > 0) return;
		if(a[i] % 2) return;
		
		v[8-i] = a[i] / -2;
	}
	
	if((v[0] = a[0] - v[4] - v[5]) < 0) return;
	if((v[1] = a[1] - v[3] - v[5]) < 0) return;
	if((v[2] = a[2] - v[3] - v[4]) < 0) return;

	int sum = x;	
	for(int i = 0; i < 6; i++) sum += v[i];
	
	if(sum < res){
		res = sum;
		ans[0] = x;
		for(int i = 1; i < 7; i++) ans[i] = v[i-1];
	}
}

int main(){
	int mx = 0;
	
	for(int i = 0; i < 6; i++){
		sd(h[i]);
		mx = max(mx, h[i]);
	}
	
	for(int i = 0; i <= mx; i++)
		solve(i);
	
	if(res == INF)
		puts("-1");
	else{
		for(int i = 0; i < 7; i++)
			while(ans[i]--) add(i);
		
		cout << res << endl;
		cout << s1 << endl;
		cout << s2 << endl;
		cout << s3 << endl;
		cout << s4 << endl;
	}
	
	return 0;
}
