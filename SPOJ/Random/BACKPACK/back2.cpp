#include <iostream>
#include <cstring>
using namespace std;
int main(void) {
int t;
cin >> t;
while (t--) {
int v, n;
cin >> v >> n;
v /= 10;
int V[60][4], P[60][4], G[60];
memset(V, 0, sizeof(V));
memset(P, 0, sizeof(P));
memset(G, 0, sizeof(G));
// read input
for (int i = 1; i <= n; i++) {
int v, c, u;
cin >> v >> c >> u;
v /= 10;
if (!u) {
V[i][0] = v;
P[i][0] = v * c;
} else {
G[u]++;
V[u][G[u]] = v;
P[u][G[u]] = v * c;
}
}
// calculate volume and profit of groups of goods
for (int i = 0; i <= n; i++) {
V[i][3] = V[i][0] + V[i][1] + V[i][2];
P[i][3] = P[i][0] + P[i][1] + P[i][2];
V[i][1] = V[i][0] + V[i][1];
P[i][1] = P[i][0] + P[i][1];
V[i][2] = V[i][0] + V[i][2];
P[i][2] = P[i][0] + P[i][2];
}
short dp[3201][61];
// reset first column
for (int j = 0; j <= v; j++) {
dp[j][0] = 0;
}
// reset first row
for (int i = 0; i <= n; i++) {
dp[0][i] = 0;
}
for (int j = 1; j <= v; j++) {
for (int i = 1; i <= n; i++) {
int new_dp = max(dp[j-1][i], dp[j][i-1]);
// save some time
if (P[i][0] > 0) {
// instead of classic dp max() we need to go through all the group combinations of allowed goods
for (int k = 0; k < 4; k++) {
int v = j - V[i][k];
if (v >= 0) {
new_dp = max(new_dp, dp[v][i-1] + P[i][k]);
}
}
}
dp[j][i] = new_dp;
}
}
cout << dp[v][n] * 10 << endl;
}
return 0;
}
