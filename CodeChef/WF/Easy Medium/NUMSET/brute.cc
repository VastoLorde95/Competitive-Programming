#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define next Next

const int MAX_ELEMENT = 1000;

int smallerThanRoot;
int primesCount;
int remap[MAX_ELEMENT + 10];
int next[MAX_ELEMENT + 10];
vector<int> initial, variants[MAX_ELEMENT + 10];
vector<int> dp[MAX_ELEMENT + 10];

void generateSmallPrimes () {
    for(int i = 2; i <= MAX_ELEMENT; i++) {
        bool isPrime = true;
        for(int j = 2; j * j <= i; j++) if (i % j == 0) {
            isPrime = false;
            break;
        }
        if (isPrime) {
            remap[i] = ++primesCount;
        }
    }
    smallerThanRoot = 0;
    for(int i = 2; i * i <= MAX_ELEMENT; i++) if (remap[i] != 0) {
        ++smallerThanRoot;
    }
}

int main(int argc, const char * argv[]) {
    generateSmallPrimes();
    int testCases;
    cin >> testCases;
    while (testCases--) {
        for(int i = 1; i <= MAX_ELEMENT; i++) {
            variants[i].clear();
        }
        initial.clear();
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            int cur;
            cin >> cur;
            int mask = 0;
            for(int j = 2; j * j <= MAX_ELEMENT; j++) {
                while (cur % j == 0) {
                    mask |= (1 << (remap[j] - 1));
                    cur /= j;
                }
            }
            if (cur != 1) {
                variants[remap[cur]].push_back(mask);
            } else {
                initial.push_back(mask);
            }
        }
        for(int i = 1; i <= primesCount + 1; i++) if (variants[i].size() > 0 || i == primesCount + 1 || i == 1) {
            dp[i].resize(1 << smallerThanRoot);
            fill(dp[i].begin(), dp[i].end(), 0);
        } else {
            dp[i].clear();
        }
        next[primesCount + 1] = primesCount + 1;
        for(int i = primesCount; i >= 1; i--) if (dp[i].size() != 0) next[i] = i; else next[i] = next[i + 1];
        dp[1][0] = 0;
        for(int option : initial) {
            for(int j = 0; j < (1 << smallerThanRoot); j++) if ((j & option) == 0) {
                dp[1][j + option] = max(dp[1][j + option], dp[1][j] + 1);
            }
        }
        for(int i = 1; i <= primesCount; i++) if (dp[i].size() > 0) {
            for(int j = 0; j < (1 << smallerThanRoot); j++) {
                dp[next[i + 1]][j] = max(dp[next[i + 1]][j], dp[i][j]);
            }
            for(int option : variants[next[i + 1]]) {
                for(int j = 0; j < (1 << smallerThanRoot); j++) if ((j & option) == 0) {
                    dp[next[i + 1]][j + option] = max(dp[next[i + 1]][j + option], dp[i][j] + 1);
                }
            }
        }
        int ret = 0;
        for(int i = 0; i < (1 << smallerThanRoot); i++) {
            ret = max(ret, dp[primesCount + 1][i]);
        }
        cout << ret << endl;
    }
    return 0;
}
