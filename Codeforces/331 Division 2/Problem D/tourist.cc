#include <bits/stdc++.h>

using namespace std;

const int N = 2010;

double f[N][N][2][2];
int x[N];
int lf[N], rg[N];

inline double get(int i, int j, int ti, int tj) {
  return (i > j ? 0.0 : f[i][j][ti][tj]);
}

int main() {
  int n, h;
  double p;
  cin >> n >> h >> p;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  sort(x, x + n);
  lf[0] = 0;
  for (int i = 1; i < n; i++) {
    if (x[i] - x[i - 1] < h) {
      lf[i] = lf[i - 1];
    } else {
      lf[i] = i;
    }
  }
  rg[n - 1] = n - 1;
  for (int i = n - 2; i >= 0; i--) {
    if (x[i + 1] - x[i] < h) {
      rg[i] = rg[i + 1];
    } else {
      rg[i] = i;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i; j < n; j++) {
      for (int ti = 0; ti < 2; ti++) {
        for (int tj = 0; tj < 2; tj++) {
          double res = 0.0;
          if (i == j) {
            {
              int from = x[i] - h;
              int to = x[i];
              if (i > 0) {
                from = max(from, ti == 0 ? x[i - 1] : x[i - 1] + h);
              }
              if (j < n - 1) {
                to = min(to, tj == 1 ? x[j + 1] : x[j + 1] - h);
              }
              if (from < to) {
                res += (to - from) * p;
              }
            }
            {
              int from = x[i];
              int to = x[i] + h;
              if (i > 0) {
                from = max(from, ti == 0 ? x[i - 1] : x[i - 1] + h);
              }
              if (j < n - 1) {
                to = min(to, tj == 1 ? x[j + 1] : x[j + 1] - h);
              }
              if (from < to) {
                res += (to - from) * (1 - p);
              }
            }
          } else {
            {
              int from = x[i] - h;
              int to = x[i];
              if (i > 0) {
                from = max(from, ti == 0 ? x[i - 1] : x[i - 1] + h);
              }
              if (j < n - 1) {
                to = min(to, tj == 1 ? x[j + 1] : x[j + 1] - h);
              }
              if (from < to) {
                res += (to - from) * p;
              }
              res += f[i + 1][j][0][tj] * p;
            }
            {
              int from = x[i];
              int to = x[rg[i]] + h;
              if (i > 0) {
                from = max(from, ti == 0 ? x[i - 1] : x[i - 1] + h);
              }
              if (j < n - 1) {
                to = min(to, tj == 1 ? x[j + 1] : x[j + 1] - h);
              }
              if (from < to) {
                res += (to - from) * (1 - p);
              }
              res += get(rg[i] + 1, j, 1, tj) * (1 - p);
            }
            {
              int from = x[j];
              int to = x[j] + h;
              if (i > 0) {
                from = max(from, ti == 0 ? x[i - 1] : x[i - 1] + h);
              }
              if (j < n - 1) {
                to = min(to, tj == 1 ? x[j + 1] : x[j + 1] - h);
              }
              if (from < to) {
                res += (to - from) * (1 - p);
              }
              res += f[i][j - 1][ti][1] * (1 - p);
            }
            {
              int from = x[lf[j]] - h;
              int to = x[j];
              if (i > 0) {
                from = max(from, ti == 0 ? x[i - 1] : x[i - 1] + h);
              }
              if (j < n - 1) {
                to = min(to, tj == 1 ? x[j + 1] : x[j + 1] - h);
              }
              if (from < to) {
                res += (to - from) * p;
              }
              res += get(i, lf[j] - 1, ti, 0) * p;
            }
            res *= 0.5;
          }
          f[i][j][ti][tj] = res;
        }
      }
    }
  }
  printf("%.17f\n", f[0][n - 1][0][0]);
  return 0;
}
