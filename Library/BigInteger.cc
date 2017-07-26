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

const ll BASE = 1e9;

class BigInteger{
public:
	vector<ll> number;
	int sign;
	
	int size(){
		return (int) number.size();
	}
	
	BigInteger(ll num = 0){
		sign = (num > 0)? 1 : ((sign < 0)? -1 : 0);
		
		while(num){
			number.pb(num % BASE);
			num /= BASE;
		}
	}
	
	BigInteger operator+(BigInteger &b){
		BigInteger &a = *this;
		BigInteger res;
		
		bool swapped = false;
		if(a.size() < b.size()){
			swap(a,b);
			swapped = true;
		}
		
		int l = a.size();
		
		ll carry = 0;		
		for(int i = 0; i < l; i++){
			if(b.size() <= i){
				res.number.pb(carry + a.number[i]);
				if(res.number.back() >= BASE){
					carry = res.number[i] / BASE;
					res.number[i] -= BASE;
				}
				else carry = 0;
			}
			else{
				res.number.pb(carry + a.number[i] + b.number[i]);
				carry = res.number[i] / BASE;
				res.number[i] %= BASE;
			}
		}
		if(carry) res.number.pb(carry);
				
		if(swapped) swap(a,b);
		
		return res;
	}
	
	BigInteger operator*(BigInteger &b){
		BigInteger &a = *this;
		BigInteger res = 1;
		
		
		
		return res;
	}
	
	friend ostream &operator<<( ostream &output, BigInteger &n){ 
		for(int i = n.size() - 1; i >= 0; i--) output << n.number[i];
		return output;
	}
	
};

int main(){
	BigInteger i = 1, j = 1ll << 60;
	
	return 0;
}
