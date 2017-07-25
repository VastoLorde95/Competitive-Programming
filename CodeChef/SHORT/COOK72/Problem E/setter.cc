#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <set>
#include <map>
#include <complex>
#include <iostream>
#include <time.h>
#include <stack>
#include <stdlib.h>
#include <memory.h>
#include <bitset>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

const int MaxN = 5e2 + 10;
const int MOD = 1e9 + 7;
const int INF = 1e9;

typedef __float128 mytype;

int p[MaxN], was[MaxN], m;
mytype mat[MaxN][MaxN], f[MaxN], res[MaxN];
vector < vector < int > > all;
vector < int > cur;

void genAll(int n, int last = 1){
  if(n == 0){
    m++;
    all.push_back(cur);
    return;
  }
  for(int nlast = last; nlast <= n; ++nlast){
    cur.push_back(nlast);
    genAll(n - nlast, nlast);
    cur.pop_back();
  }
}

int getIndex(vector < int > val){
  return lower_bound(all.begin(), all.end(), val) - all.begin() + 1;
}

template < class T >
T myabs(T x){
  if(x < 0){
    return -x;
  }
  return x;
}

void solve(){
  for(int it = 1; it <= m; ++it){
    int where = -1;
    for(int row = it; row <= m; ++row){
      if(where == -1 || myabs(mat[row][it]) > myabs(mat[where][it])){
        where = row;
      }
    }
    assert(myabs(mat[where][it]) > 1e-11);
    for(int col = 1; col <= m; ++col){
      swap(mat[it][col], mat[where][col]);
    }
    swap(f[it], f[where]);
    for(int row = it + 1; row <= m; ++row){
      mytype val = mat[row][it] / mat[it][it];
      for(int col = 1; col <= m; ++col){
        mat[row][col] -= val * mat[it][col];
      }
      f[row] -= val * f[it];
    }
  }
  for(int row = m; row >= 1; --row){
    for(int nrow = row + 1; nrow <= m; ++nrow){
      f[row] -= mat[row][nrow] * f[nrow];
    }
    f[row] /= mat[row][row];
  }
}

vector < int > makeCycle(int len, int shift){
  vector < int > res;
  for(int i = 0; i < len; ++i){
    res.push_back((i + 1) % len + shift);
  }
  return res;
}

vector < int > makePermutation(vector < int > cycles){
  vector < int > res;
  for(int i = 0; i <(int)cycles.size(); ++i){
    vector < int > f = makeCycle(cycles[i],(int)res.size());
    res.insert(res.end(), f.begin(), f.end());
  }
  return res;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t --> 0){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
      scanf("%d", &p[i]);
      was[i] = 0;
    }
    
    vector<int> cycles;
    for(int i = 1; i <= n; ++i){
      if(was[i] == 1){
        continue;
      }
      int j = i, c = 0;
      do{
        was[j] = 1;
        j = p[j];
        c++;
      } while(j != i);
      cycles.push_back(c);
    }
    all.clear();
    
    m = 0;
    genAll(n);
    sort(all.begin(), all.end());
    sort(cycles.begin(), cycles.end());
    
    for(int i = 1; i <= m; ++i){
      for(int j = 1; j <= m; ++j){
        mat[i][j] = 0;
      }
      f[i] = 0.0;
    }
    
    for(int i = 1; i <= m; ++i){
      mat[i][i] = f[i] = 1.0;
    }
    
    f[getIndex(makePermutation(vector<int>(n, 1)))] = 0;
    
    for(int i = 0; i <(int)all.size(); ++i){
      vector < int > cur = all[i];
      if(cur.size() == n) continue;
      
      vector < int > p = makePermutation(cur);
      for(int l = 0; l <(int)p.size(); ++l){
        for(int r = l + 1; r <(int)p.size(); ++r){
          swap(p[l], p[r]);
          vector < int > w(p.size());
          vector < int > tmp;
          for(int it = 0; it <(int)w.size(); ++it){
            if(w[it] == 1){
              continue;
            }
            int jt = it, cnt = 0;
            do{
              w[jt] = 1;
              jt = p[jt];
              cnt++;
            } while(jt != it);
            tmp.push_back(cnt);
          }
          sort(tmp.begin(), tmp.end());
          mat[getIndex(cur)][getIndex(tmp)] += -2.0 / n /(n - 1);
          swap(p[l], p[r]);
        }
      }
    }
    solve();
    cout.precision(7);
    cout << fixed <<(long double) f[getIndex(cycles)] + 1e-11 << endl;
  }
  return 0;
}
