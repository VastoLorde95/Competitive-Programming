/*
 * Hash problem sample solution by Jelani Nelson
 *
 */

#include <iostream>
using namespace std;
typedef long long LL;

// if high, calculate size of intersection of u%m,(u+d)%m,...,(u+n*d)%m with
// [-L+1, 0].  else, calculate size of intersection with [0, L-1].
LL calc(LL u, LL d, LL n, LL L, LL m, bool high) {
  if (!L)
    return 0;
  if (m == 1 || L >= m)
    return n + 1;
  if (!d || !n)
    return (high ? (!u || (u > m - L)) : (u < L)) * (n + 1);
  
  LL k;
  if (high)
    k = (u + n*d + m - 1)/m + !u;
  else 
    k = (u + n*d)/m + 1;
  
  LL f0 = 0, f1 = 0;
  if (high) {
    if (!u)
      f0 = 1;
    else {
      LL c1 = max((m - L + 1 - u + d - 1)/d, 0LL);
      LL c2 = min((m - u)/d, n);
      f0 = max(c2 - c1 + 1, 0LL);
    }
    LL w = (u + n*d + m - 1)/m * m;
    LL c = (w - L + 1 - u + d - 1)/d;
    if (k > 1)
      f1 = max(n - c + 1, 0LL);
  } else {
    if (u <= L - 1)
      f0 = min((L - 1 - u)/d, n) + 1;
    LL w = (u + n*d)/m * m;
    LL c = (w - u + d - 1)/d;
    if (k > 1)
      f1 = max(min((w + L - 1 - u)/d, n) - c + 1, 0LL);
  }
  
  if (k <= 2)
    return f0 + f1;
  if (d == 1)
    return f0 + f1 + L*(k - 2);
  
  LL r = L % d, s = m % d, t;
  if (high) {
    LL e = (u + ((1+!!u)*m - u)/d * d) % m;
    if (!e)
      e = m;
    e = m - e;
    if (s <= d/2)
      t = calc(e % d, s, k - 3, r, d, 0);
    else
      t = calc((d - (e % d)) % d, d - s, k - 3, r, d, 1);
  } else {
    LL e = (u + (m - u + d - 1)/d * d) % m;
    if (d - s <= d/2)
      t = calc(e % d, d - s, k - 3, r, d, 0);
    else
      t = calc((d - (e % d)) % d, s, k - 3, r, d, 1);
  }
  
  return f0 + f1 + (k - 2)*(L/d) + t;
}

// calculate number of values a*x+b,a*(x+1)+b,...,a*(x+n)+b
// that land in [c, d] when taken modulo m. running time is
// O(min(log(a), log(n)))
int main() {
  LL a, b, x, n, c, d, m, no_cases;
  cin >> no_cases;
  while (no_cases--) {
    cin >> a >> b >> x >> n >> c >> d >> m;
    LL u = (a*x + b) % m;
    LL ret = n + 1 - calc(u, a, n, c, m, 0) - calc(u, a, n, m - d, m, 1);
    ret += calc(u, a, n, 1, m, 0);
    cout << ret << endl;
  }
  return 0; 
}  
