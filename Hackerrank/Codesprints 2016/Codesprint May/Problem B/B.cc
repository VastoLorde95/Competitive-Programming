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

const int N = 100100;

string s;
int n, k;
int modified[N];

int main(){ _
	cin >> n >> k;
	cin >> s;
	
	for(int i = 0, j = n-1; i <= j; i++, j--){
		int d1 = s[i] - '0';
		int d2 = s[j] - '0';
		if(d1 < d2){
			s[i] = s[j];
			k--;
			modified[i] = 1;
		}
		else if(d1 > d2){
			s[j] = s[i];
			k--;
			modified[i] = 1;
		}
	}
	
	if(k < 0){
		cout << -1 << endl;
		return 0;
	}
	
	for(int i = 0, j = n-1; i <= j; i++, j--){
		if(i < j){
			if(!modified[i] and k >= 2 and s[i] != '9'){
				s[i] = s[j] = '9';
				k -= 2;
			}
			else if(modified[i] and k >= 1 and s[i] != '9'){
				k--;
				s[i] = s[j] = '9';
			}
		}
		else{
			if(k >= 1 and s[i] != '9'){
				s[i] = '9';
				k--;
			}
		}
	}
	
	cout << s << endl;
	
	return 0;
}
