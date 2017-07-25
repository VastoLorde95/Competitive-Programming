#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define cin fin
#define cout fout

ifstream fin("input.txt");
ofstream fout("output.txt");

const int N = 1e5 + 5, oo = (1 << 30);
int t[N], dp1[N], dp2[N];

int main() { _
    int n, cnt = 0, ans = oo;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        dp1[i] = (i? dp1[i - 1]: 0);
        dp2[i] = (i? dp2[i - 1]: 0);
        if (t < 0)
            ++dp1[i];
        else if (t > 0)
            ++dp2[i];
        else
            ++cnt;
    }
    for (int i = 1; i < n; ++i)
        ans = min(ans, dp2[i - 1] + dp1[n - 1] - dp1[i - 1]);
    cout << ans + cnt;
}
