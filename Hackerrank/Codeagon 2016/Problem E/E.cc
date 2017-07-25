#include <bits/stdc++.h>

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

#define func __FUNCTION__
#define line __LINE__

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.fi<<", "<<p.se<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
long long l = v.size(); for(long long i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

const long long base = 1000000000;
const long long base_digits = 9; 
struct bigint {
  vector<long long> a;
  long long sign;
  /*<arpa>*/
  long long size(){
    if(a.empty())return 0;
    long long ans=(a.size()-1)*base_digits;
    long long ca=a.back();
    while(ca)
      ans++,ca/=10;
    return ans;
  }
  bigint operator ^(const bigint &v){
    bigint ans=1,a=*this,b=v;
    while(!b.isZero()){
      if(b%2)
	ans*=a;
      a*=a,b/=2;
    }
    return ans;
  }
  /*</arpa>*/
  bigint() :
    sign(1) {
  }
 
  bigint(long long v) {
    *this = v;
  }
 
  bigint(const string &s) {
    read(s);
  }
 
  void operator=(const bigint &v) {
    sign = v.sign;
    a = v.a;
  }
 
  void operator=(long long v) {
    sign = 1;
    if (v < 0)
      sign = -1, v = -v;
    for (; v > 0; v = v / base)
      a.push_back(v % base);
  }
 
  bigint operator+(const bigint &v) const {
    if (sign == v.sign) {
      bigint res = v;
 
      for (long long i = 0, carry = 0; i < (long long) max(a.size(), v.a.size()) || carry; ++i) {
	if (i == (long long) res.a.size())
	  res.a.push_back(0);
	res.a[i] += carry + (i < (long long) a.size() ? a[i] : 0);
	carry = res.a[i] >= base;
	if (carry)
	  res.a[i] -= base;
      }
      return res;
    }
    return *this - (-v);
  }
 
  bigint operator-(const bigint &v) const {
    if (sign == v.sign) {
      if (abs() >= v.abs()) {
	bigint res = *this;
	for (long long i = 0, carry = 0; i < (long long) v.a.size() || carry; ++i) {
	  res.a[i] -= carry + (i < (long long) v.a.size() ? v.a[i] : 0);
	  carry = res.a[i] < 0;
	  if (carry)
	    res.a[i] += base;
	}
	res.trim();
	return res;
      }
      return -(v - *this);
    }
    return *this + (-v);
  }
 
  void operator*=(long long v) {
    if (v < 0)
      sign = -sign, v = -v;
    for (long long i = 0, carry = 0; i < (long long) a.size() || carry; ++i) {
      if (i == (long long) a.size())
	a.push_back(0);
      long long cur = a[i] * (long long) v + carry;
      carry = (long long) (cur / base);
      a[i] = (long long) (cur % base);
      //asm("divl %%ecx" : "=a"(carry), "=d"(a[i]) : "A"(cur), "c"(base));
    }
    trim();
  }
 
  bigint operator*(long long v) const {
    bigint res = *this;
    res *= v;
    return res;
  }
 
  friend pair<bigint, bigint> divmod(const bigint &a1, const bigint &b1) {
    long long norm = base / (b1.a.back() + 1);
    bigint a = a1.abs() * norm;
    bigint b = b1.abs() * norm;
    bigint q, r;
    q.a.resize(a.a.size());
 
    for (long long i = a.a.size() - 1; i >= 0; i--) {
      r *= base;
      r += a.a[i];
      long long s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
      long long s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
      long long d = ((long long) base * s1 + s2) / b.a.back();
      r -= b * d;
      while (r < 0)
	r += b, --d;
      q.a[i] = d;
    }
 
    q.sign = a1.sign * b1.sign;
    r.sign = a1.sign;
    q.trim();
    r.trim();
    return make_pair(q, r / norm);
  }
 
  bigint operator/(const bigint &v) const {
    return divmod(*this, v).first;
  }
 
  bigint operator%(const bigint &v) const {
    return divmod(*this, v).second;
  }
 
  void operator/=(long long v) {
    if (v < 0)
      sign = -sign, v = -v;
    for (long long i = (long long) a.size() - 1, rem = 0; i >= 0; --i) {
      long long cur = a[i] + rem * (long long) base;
      a[i] = (long long) (cur / v);
      rem = (long long) (cur % v);
    }
    trim();
  }
 
  bigint operator/(long long v) const {
    bigint res = *this;
    res /= v;
    return res;
  }
 
  long long operator%(long long v) const {
    if (v < 0)
      v = -v;
    long long m = 0;
    for (long long i = a.size() - 1; i >= 0; --i)
      m = (a[i] + m * (long long) base) % v;
    return m * sign;
  }
 
  void operator+=(const bigint &v) {
    *this = *this + v;
  }
  void operator-=(const bigint &v) {
    *this = *this - v;
  }
  void operator*=(const bigint &v) {
    *this = *this * v;
  }
  void operator/=(const bigint &v) {
    *this = *this / v;
  }
 
  bool operator<(const bigint &v) const {
    if (sign != v.sign)
      return sign < v.sign;
    if (a.size() != v.a.size())
      return a.size() * sign < v.a.size() * v.sign;
    for (long long i = a.size() - 1; i >= 0; i--)
      if (a[i] != v.a[i])
	return a[i] * sign < v.a[i] * sign;
    return false;
  }
 
  bool operator>(const bigint &v) const {
    return v < *this;
  }
  bool operator<=(const bigint &v) const {
    return !(v < *this);
  }
  bool operator>=(const bigint &v) const {
    return !(*this < v);
  }
  bool operator==(const bigint &v) const {
    return !(*this < v) && !(v < *this);
  }
  bool operator!=(const bigint &v) const {
    return *this < v || v < *this;
  }
 
  void trim() {
    while (!a.empty() && !a.back())
      a.pop_back();
    if (a.empty())
      sign = 1;
  }
 
  bool isZero() const {
    return a.empty() || (a.size() == 1 && !a[0]);
  }
 
  bigint operator-() const {
    bigint res = *this;
    res.sign = -sign;
    return res;
  }
 
  bigint abs() const {
    bigint res = *this;
    res.sign *= res.sign;
    return res;
  }
 
  long long longValue() const {
    long long res = 0;
    for (long long i = a.size() - 1; i >= 0; i--)
      res = res * base + a[i];
    return res * sign;
  }
 
  friend bigint gcd(const bigint &a, const bigint &b) {
    return b.isZero() ? a : gcd(b, a % b);
  }
  friend bigint lcm(const bigint &a, const bigint &b) {
    return a / gcd(a, b) * b;
  }
 
  void read(const string &s) {
    sign = 1;
    a.clear();
    long long pos = 0;
    while (pos < (long long) s.size() && (s[pos] == '-' || s[pos] == '+')) {
      if (s[pos] == '-')
	sign = -sign;
      ++pos;
    }
    for (long long i = s.size() - 1; i >= pos; i -= base_digits) {
      long long x = 0;
      for (long long j = max(pos, i - base_digits + 1); j <= i; j++)
	x = x * 10 + s[j] - '0';
      a.push_back(x);
    }
    trim();
  }
 
  friend istream& operator>>(istream &stream, bigint &v) {
    string s;
    stream >> s;
    v.read(s);
    return stream;
  }
 
  friend ostream& operator<<(ostream &stream, const bigint &v) {
    if (v.sign == -1)
      stream << '-';
    stream << (v.a.empty() ? 0 : v.a.back());
    for (long long i = (long long) v.a.size() - 2; i >= 0; --i)
      stream << setw(base_digits) << setfill('0') << v.a[i];
    return stream;
  }
 
  static vector<long long> convert_base(const vector<long long> &a, long long old_digits, long long new_digits) {
    vector<long long> p(max(old_digits, new_digits) + 1);
    p[0] = 1;
    for (long long i = 1; i < (long long) p.size(); i++)
      p[i] = p[i - 1] * 10;
    vector<long long> res;
    long long cur = 0;
    long long cur_digits = 0;
    for (long long i = 0; i < (long long) a.size(); i++) {
      cur += a[i] * p[cur_digits];
      cur_digits += old_digits;
      while (cur_digits >= new_digits) {
	res.push_back((long long)(cur % p[new_digits]));
	cur /= p[new_digits];
	cur_digits -= new_digits;
      }
    }
    res.push_back((long long) cur);
    while (!res.empty() && !res.back())
      res.pop_back();
    return res;
  }
 
  typedef vector<long long> vll;
 
  static vll karatsubaMultiply(const vll &a, const vll &b) {
    long long n = a.size();
    vll res(n + n);
    if (n <= 32) {
      for (long long i = 0; i < n; i++)
	for (long long j = 0; j < n; j++)
	  res[i + j] += a[i] * b[j];
      return res;
    }
 
    long long k = n >> 1;
    vll a1(a.begin(), a.begin() + k);
    vll a2(a.begin() + k, a.end());
    vll b1(b.begin(), b.begin() + k);
    vll b2(b.begin() + k, b.end());
 
    vll a1b1 = karatsubaMultiply(a1, b1);
    vll a2b2 = karatsubaMultiply(a2, b2);
 
    for (long long i = 0; i < k; i++)
      a2[i] += a1[i];
    for (long long i = 0; i < k; i++)
      b2[i] += b1[i];
 
    vll r = karatsubaMultiply(a2, b2);
    for (long long i = 0; i < (long long) a1b1.size(); i++)
      r[i] -= a1b1[i];
    for (long long i = 0; i < (long long) a2b2.size(); i++)
      r[i] -= a2b2[i];
 
    for (long long i = 0; i < (long long) r.size(); i++)
      res[i + k] += r[i];
    for (long long i = 0; i < (long long) a1b1.size(); i++)
      res[i] += a1b1[i];
    for (long long i = 0; i < (long long) a2b2.size(); i++)
      res[i + n] += a2b2[i];
    return res;
  }
 
  bigint operator*(const bigint &v) const {
    vector<long long> a6 = convert_base(this->a, base_digits, 6);
    vector<long long> b6 = convert_base(v.a, base_digits, 6);
    vll a(a6.begin(), a6.end());
    vll b(b6.begin(), b6.end());
    while (a.size() < b.size())
      a.push_back(0);
    while (b.size() < a.size())
      b.push_back(0);
    while (a.size() & (a.size() - 1))
      a.push_back(0), b.push_back(0);
    vll c = karatsubaMultiply(a, b);
    bigint res;
    res.sign = sign * v.sign;
    for (long long i = 0, carry = 0; i < (long long) c.size(); i++) {
      long long cur = c[i] + carry;
      res.a.push_back((long long) (cur % 1000000));
      carry = (long long) (cur / 1000000);
    }
    res.a = convert_base(res.a, 6, base_digits);
    res.trim();
    return res;
  }
};


const long long N = 1<<17;
long long n;
bigint k, a[N];

struct node{
	bigint cnt;
	void assign(bigint value){
		 cnt = value;
	}
	void combine(node &left, node &right){
		cnt = (left.cnt*right.cnt)%k;
	}
};

node tree[2*N];

// [l, r)
void build(long long id = 1, long long l = 0, long long r = n){
	if(l+1 == r){
		tree[id].assign(a[l]);
		return;
	}
	long long left = id<<1, right = left+1, mid = (l+r)>>1;
	
	build(left, l, mid); build(right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
	return;
}

bigint query(long long x, long long y, long long id = 1, long long l = 0, long long r = n){
	if(x >= r or l >= y) return 1;
	if(x <= l && r <= y) return tree[id].cnt;
	
	long long left = id<<1, right = left+1, mid = (l+r)>>1;
	
	return (query(x, y, left, l, mid)*query(x, y, right, mid, r))%k;
}

long long MOD = 1e9 + 9;

long long dp[N];

int main(){ _
	cin >> n >> k;
	for(long long i = 0; i < n; i++){
		cin >> a[i];
		a[i] = a[i]%k;
	}
	
	build();
	
	bigint zero = 0;
	
	if(a[0]%k == zero){
		dp[1] = 1;
	}
	else{
		dp[1] = 0;
	}
	
	long long last = 0;
	for(long long i = 1; i < n; i++){
		if(a[i] == zero){
			if(dp[i] > 0){
				dp[i+1] = ((dp[i]*2ll)+1)%MOD;
			}
			else{
				dp[i+1] = 1;
			}
			
			last = i;
			
//			tr(func, line, i, dp[i+1]);
			
			continue;
		}
		
		
		bigint res = query(0,i+1);
		if(res != zero){
			dp[i+1] = dp[i];
			continue;
		}
		
		long long low = last, hi = i, mid;
		while(low <= hi){
			mid = (low+hi)/2;
			res = query(low, hi+1);
			
			if(res == zero){
				low = mid+1;	
			}
			else{
				hi = mid-1;
			}
		}
		
		low -= 1;
		if(low <= 0){
			dp[i+1] = (dp[i]+1)%MOD;
		}
		else{
			dp[i+1] = (dp[low]+1+dp[i])%MOD;
		}
		
		last = max(last, low);
		
//		tr(func, line, i, dp[i+1], low);
	}

	cout << (dp[n]-dp[n-1]+MOD)%MOD << endl;	
	
	return 0;
}
