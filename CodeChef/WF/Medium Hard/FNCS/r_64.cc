#include <cstdio>
#include <cstdlib>
typedef unsigned long long int ll;
const int sz = 100200;
const int P = 322;
 
void gi(int &x){char c = getchar(); x = 0; while (c < '0' || c > '9') c = getchar(); while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();}
void pi(ll x){if (x > 9) pi(x / 10); putchar(x % 10 + 48);}
 
int B, n;
int beg[P], end[P], chunk[sz];
int L[sz], R[sz], A[sz];
ll presum[sz], PRESUM[P], ANS[P];
int fac[P][sz];
int tat[sz];
 
void init(){
  int i, j, k;
  gi(n);
  
  for (B = 1; B * B <= n; B++);
  
  for (i = 1; i <= n; i++) gi(A[i]);
  
  /*
  	chunk[i] = chunk which point i belongs to
  	beg[i] = start point of chunk i
  	end[i] = end point of chunk i
  */
  for (i = 1; i <= n; i++) end[chunk[i] = (i + B - 1) / B] = i;
  for (i = n; i; i--) beg[chunk[i]] = i;
  
  for (i = 1; i <= n; i++) gi(L[i]), gi(R[i]);
  
  for (i = 1; i <= n; i++){
    tat[L[i]]++; tat[R[i] + 1]--;
    presum[i] = A[i];
    
    if (i != beg[chunk[i]]) presum[i] += presum[i - 1];
    
    if (i == end[chunk[i]]){
      k = chunk[i];
      PRESUM[k] = PRESUM[k - 1] + presum[i];
      for (j = 1; j <= n; j++){
		fac[k][j] = fac[k][j - 1] + tat[j];
		ANS[k] += 1ll * A[j] * fac[k][j];
		
		tat[j] = 0;
      }
    }
  }
}
 
void change(int x, int y){
  int k = chunk[x], delta = y - A[x]; A[x] = y;
  for (; k <= chunk[n]; k++) PRESUM[k] += delta;
  for (k = 1; k <= chunk[n]; k++)
    ANS[k] += 1ll * delta * fac[k][x];
  for (k = chunk[x]; x <= end[k]; x++) presum[x] += delta;
}
#define ANS(r) (PRESUM[chunk[r] - 1] + presum[r])
 
ll query(int l, int r){
  int k, j, c1, c2; ll ans = 0;
  if (r - l <= B){
  	for (k = l; k <= r; k++)
  		ans += ANS(R[k]) - ANS(L[k] - 1);
  	return ans;
  }
  
  for (k = 1; k <= chunk[n]; k++){
    c1 = (beg[k] >= l && beg[k] <= r);
    c2 = (end[k] >= l && end[k] <= r);
    if (c1 && c2) ans += ANS[k];
    else if (c1){
      for (j = beg[k]; j <= r; j++)
	ans += ANS(R[j]) - ANS(L[j] - 1);
    } else if (c2){
      for (j = l; j <= end[k]; j++)
	ans += ANS(R[j]) - ANS(L[j] - 1);
    }
  }
  return ans;
}
 
int main(){
  int Q, a, b, c;
  init();
  gi(Q);
  while (Q--){
    gi(a); gi(b); gi(c);
    if (a == 1) change(b, c);
    else pi(query(b, c)), putchar('\n');
  }
  return 0;
}
