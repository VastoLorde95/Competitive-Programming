#include <bits/stdc++.h>

using namespace std;

const int MAXN = 125100, INF = 1E9;
const unsigned int P = 17;
//const int MOD = 1E9 + 9;

char s[MAXN], t[MAXN];
int n, q;

unsigned int p[MAXN];
unsigned int hshs[11][MAXN];
unsigned int hsht[11][MAXN];
int nxt[11][MAXN];

unsigned int getHashS(int who, int st, int fin) {
    unsigned int res = hshs[who][fin];
    if (st > 0) {
        res -= hshs[who][st - 1];
    }
    res *= p[MAXN - 1 - st];

    return res;
}

unsigned int getHashT(int who, int st, int fin) {
    unsigned int res = hsht[who][fin];
    if (st > 0) {
        res -= hsht[who][st - 1];
    }
    res *= p[MAXN - 1 - st];

    return res;
}

bool used[11];
int to[11];

int bin(int st, int fin, const int poss, const int post) {
    if (st == fin) {
        return st;
    }
    int med = (st + fin + 1) / 2;
    bool ok = true;
    for (int i = 0; i < 10; i++) {
        unsigned int A = getHashS(i, poss, poss + med - 1);
        unsigned int B = getHashT(to[i], post, post + med - 1);
        if (A != B) {
            ok = false;
            break;
        }
    }
    if (ok) {
        return bin(med, fin, poss, post);
    }
    else {
        return bin(st, med - 1, poss, post);
    }
}

void solve() {
    scanf("%d%d", &n, &q);
    assert(n <= 125000);
    assert(q <= 50000);
    scanf("%s%s", s, t);

    assert( strlen(s) == n );
    assert( strlen(t) == n );

    for (int i = 0; i < n; i++) {
        assert(s[i] >= 'a' && s[i] <= 'j');
        assert(t[i] >= 'a' && t[i] <= 'j');
    }

    for (int j = 0; j < 11; j++) {
        nxt[j][n] = INF;
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 11; j++) {
            nxt[j][i] = nxt[j][i + 1];
        }
        nxt[ s[i] - 'a' ][i] = i;
    }

    for (int who = 0; who < 10; who++) {
        hshs[who][0] = (s[0] - 'a' == who);
        for (int i = 1; i < n; i++) {
            hshs[who][i] = (hshs[who][i - 1] + p[i]*(unsigned int)(s[i] - 'a' == who) );
        }
    }

    for (int who = 0; who < 10; who++) {
        hsht[who][0] = (t[0] - 'a' == who);
        for (int i = 1; i < n; i++) {
            hsht[who][i] = (hsht[who][i - 1] + p[i]*(unsigned int)(t[i] - 'a' == who) );
        }
    }

    for (int it = 0; it < q; it++) {
        int poss, post;
        scanf("%d%d", &poss, &post);

        assert(1 <= poss && poss  <= n);
        assert(1 <= post && post  <= n);

        poss--; post--;


        memset(used, 0, sizeof(used) );
        memset(to, -1, sizeof(to) );

        vector<pair<int, int> > ord;
        for (int i = 0; i < 10; i++) {
            //cerr << i << "  " << nxt[i][poss] << endl;
            ord.push_back( make_pair( nxt[i][poss], i ) );
        }
        sort(ord.begin(), ord.end() );

        for (int i = 0; i < 10; i++) {
            int who = ord[i].second;
            int whs = ord[i].first, wht;
            wht = post + whs - poss;
            if (wht < n && used[ t[wht] - 'a' ] == false) {
                used[ t[wht] - 'a' ] = true;
                to[who] = t[wht] - 'a';
            }
            else {
                for (int j = 0; j < 10; j++) {
                    if (used[j] == false) {
                        used[j] = true;
                        to[who] = j;
                        break;
                    }
                }
            }
        }

        int can = min(n - poss, n - post);
        int l = bin(0, can, poss, post);
        int finish = poss + l - 1;
        memset(used, 0, sizeof(used) );
        memset(to, -1, sizeof(to) );
        for (int i = 0; i < 10; i++) {
            int who = ord[i].second;
            int whs = ord[i].first, wht;
            wht = post + whs - poss;
            if (whs <= finish) {
                used[ t[wht] - 'a' ] = true;
                to[who] = t[wht] - 'a';
            }
        }
        for (int i = 0; i < 10; i++) {
            if (to[i] == -1) {
                for (int j = 0; j < 10; j++) {
                    if (used[j] == false) {
                        used[j] = true;
                        to[i] = j;
                        break;
                    }
                }
            }
        }

        printf("%d ", l);
        for (int i = 0; i < 10; i++) {
            printf("%c", (char)(to[i] + 'a') );
        }
        printf("\n");
    }
}

int main() {

    p[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        p[i] = p[i - 1] * P;
    }

    int test;
    cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}
