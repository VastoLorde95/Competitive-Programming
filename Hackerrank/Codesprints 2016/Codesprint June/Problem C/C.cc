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

vector<int> tovector(string &s){
	int l = s.length();
	vector<int> v;
	for(int i = l-1; i >= 0; i--){
		int num;
		if(s[i] >= '0' and s[i] <= '9'){
			num = s[i] - '0';
		}
		else{
			num = s[i] - 'A' + 10;
		}
		
		int cnt = 0;
		while(num > 0){
			if(num&1) v.pb(1);
			else v.pb(0);
			num >>= 1;
			cnt++;
		}
		while(cnt < 4){
			v.pb(0);
			cnt++;
		}
	}
	return v;
}

void patch(vector<int> &v, int l){
	while(v.size() < l) v.pb(0);
}

void convert(vector<int> &v){
	int l = v.size();
	string res;
	for(int i = l-1; i >= 0; i--){
		int num = 0;
		for(int j = 0; j < 4; j++, i--){
			num <<= 1;
			num += v[i];
		}
		
		if(num < 10){
			res += (char)('0' + num);
		}
		else{
			res += (char)('A' + num - 10);
		}
		i++;
	}
	
	int start = 0;
	while(start < res.length() and res[start] == '0') start++;
	if(start == res.length()) cout << 0;
	else{
		while(start < res.length()){
			cout << res[start++];
		}
	}
	cout << endl;
	
}

void solve(){
	int k; cin >> k;
	string a, b, c;
	cin >> a >> b >> c;
	
	vector<int> x = tovector(a);
	vector<int> y = tovector(b);
	vector<int> z = tovector(c);
	
	int l = max(x.size(), max(y.size(), z.size()));
	
	patch(x, l);
	patch(y, l);
	patch(z, l);
	
	int cnt = 0;
	for(int i = 0; i < l; i++){
		if((x[i]|y[i]) != z[i]){
			if(z[i] == 0){
				if(x[i] == 1) x[i] = 0, cnt++;
				if(y[i] == 1) y[i] = 0, cnt++;
			}
			else{
				y[i] = 1;
				cnt++;
			}
		}
	}
	
	if(cnt > k){
		cout << -1 << '\n';
		return;
	}
	
	k -= cnt;
	for(int i = l-1; i >= 0 and k > 0; i--){
		if(z[i] == 1){
			if(x[i] == 1 and y[i] == 1){
				x[i] = 0;
				k--;	
			}
			else if(x[i] == 1 and y[i] == 0 and k > 1){
				x[i] = 0;
				y[i] = 1;
				k -= 2;
			}
		}
	}

	convert(x);
	convert(y);
}

int main(){ _
	int q; cin >> q;
	while(q--) solve();
	return 0;
}
