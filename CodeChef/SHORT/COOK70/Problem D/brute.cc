#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define ll long long
#define MOD 1000000009LL
#define BASE 1005LL
#define N 211111
ll VAL[256];
char s[N];
int n;
ll hsh[N];
ll bpw[N];
void init() {
    VAL['a'] = 455;
    VAL['b'] = 563;
    VAL['c'] = 928;
    VAL['d'] = 468;
    VAL['e'] = 510;
    VAL['f'] = 590;
    VAL['g'] = 186;
    VAL['h'] = 514;
    VAL['i'] = 633;
    VAL['j'] = 797;
    VAL['k'] = 95;
    VAL['l'] = 305;
    VAL['m'] = 92;
    VAL['n'] = 813;
    VAL['o'] = 697;
    VAL['p'] = 43;
    VAL['q'] = 987;
    VAL['r'] = 969;
    VAL['s'] = 657;
    VAL['t'] = 619;
    VAL['u'] = 159;
    VAL['v'] = 16;
    VAL['w'] = 531;
    VAL['x'] = 60;
    VAL['y'] = 191;
    VAL['z'] = 243;

    hsh[0] = 0;
    bpw[0] = 1;
    for (int i = 0; i < n; i++) {
        hsh[i+1] = (hsh[i] * BASE + VAL[s[i]]) % MOD;
        bpw[i+1] = bpw[i] * BASE % MOD;
    }
}

ll shash(int i, int j) {
    ll res = (hsh[j] - hsh[i] * bpw[j-i]) % MOD;
    if (res < 0) res += MOD;
    return res;
}

int get_lcp(int i, int j, int k, int l) {
    int L = 0;
    int R = l+1;
    while (R - L > 1) {
        int M = L + R >> 1;
        ll hmid = shash(j, j+M);
        (k+M <= n && shash(i, i+M) == hmid && hmid == shash(k, k+M) ? L : R) = M;
    }
    return L;
}

int get_lcs(int i, int j, int k, int l) {
    int L = 0;
    int R = l+1;
    while (R - L > 1) {
        int M = L + R >> 1;
        ll hmid = shash(j-M+1, j+1);
        (i-M+1 >= 0 && shash(i-M+1, i+1) == hmid && hmid == shash(k-M+1, k+1) ? L : R) = M;
    }
    return L;
}

int main() {
    scanf("%s", s);
    n = strlen(s);
    init();
    ll interesting = 0, boring = 0;
    for (int l = 1; l <= n/3; l++) {
        for (int i = 0; i < n-2*l; i += l) {
            int j = i + l;
            int k = j + l;
            int right = get_lcp(i, j, k, l+1);
            int left = get_lcs(i, j, k, l);
            int total = min(right, l) + left - 1;
            if (total >= l) {
                if (right > l) {
                    boring += total - l + 1;
                } else {
                    boring += total - l;
                    interesting++;
                }
            }
        }
    }

    printf("%lld %lld\n", interesting, boring);
}
