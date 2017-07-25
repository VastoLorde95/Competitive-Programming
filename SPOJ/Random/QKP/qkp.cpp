#include <cstdio>
#define FOR(i,n) for(int i = 0; i < n; ++i)
int dq[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1},
{1, 1}, {1, 0}, {1, -1}, {0, -1}};
int dk[8][2] = {{-2,-1},{-1,-2}, {1,-2}, {2, -1},
{-2, 1},{-1, 2}, {1, 2}, {2, 1}};
int ss;
char b[1000][1000];
void read(char T){
int k, x, y; scanf("%d", &k); ss -= k;
while(k-- && scanf("%d %d", &x, &y) == 2) b[--x][--y] = T;
}
int main(void){
for(int bn = 1, c, r; scanf("%d %d", &r, &c) == 2 && (r || c); ++bn){
ss = r * c;
FOR(i, r) FOR(j, c) b[i][j] = '.';
read('Q'); read('K'); read('P');
FOR(i, r) FOR(j, c)
if(b[i][j] == 'K') FOR(d, 8){
int ni = i + dk[d][0], nj = j + dk[d][1];
if(ni < 0 || nj < 0 || ni >= r || nj >= c) continue;
ss -= b[ni][nj] == '.';
if(b[ni][nj] == '.') b[ni][nj] = 'A';
}
else if(b[i][j] == 'Q') FOR(d, 8){
int ni = i + dq[d][0], nj = j + dq[d][1];
while(ni >= 0 && ni < r && nj >= 0 && nj < c){
if(b[ni][nj] > 'A') break;
ss -= b[ni][nj] == '.';
b[ni][nj] = 'A';
ni += dq[d][0];
nj += dq[d][1];
}
}
printf("Board %d has %d safe squares.\n", bn, ss);
}
return 0;
}
