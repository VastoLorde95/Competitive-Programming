#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <stack>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

long long k, x, n, m, dp[51][3], tot;
string s1, s2;

int main(){
	cin >> k >> x >> n >> m;
	for(int i = 0; i <= 100; i++){
		for(int j = 0; j <= 100; j++){
			for(int p1 = 0; p1 < 4; p1++){
				for(int q1 = 0; q1 < 4; q1++){
					for(int p2 = 0; p2 < 4; p2++){
						for(int q2 = 0; q2 < 4; q2++){
							int l1 = i + i + (p1 > 0) + (q1 > 0);
							int l2 = j + j + (p2 > 0) + (q2 > 0);
							if(l1 > n or l2 > m) continue;
							
							dp[1][0] = i, dp[1][1] = p1, dp[1][2] = q1;
							dp[2][0] = j, dp[2][1] = p2, dp[2][2] = q2;
							
							for(int a = 3; a <= k; a++){
								dp[a][0] = dp[a-2][0] + dp[a-1][0];
								dp[a][1] = dp[a-2][1];
								dp[a][2] = dp[a-1][2];
								if(dp[a-2][2] == 1 and dp[a-1][1] == 2) dp[a][0]++;		
							}							
							
							if(dp[k][0] == x){
								while(i > 0) s1 += "AC", i--;
								while(j > 0) s2 += "AC", j--;
								
								for(int tmp = 0; tmp < n-l1; tmp++) s1 += 'B';
								for(int tmp = 0; tmp < m-l2; tmp++) s2 += 'B';
								
								if(p1 == 1) s1 = 'A' + s1;
								else if(p1 == 2) s1 = 'C' + s1;
								else if(p1 == 3) s1 = 'B' + s1;
								
								if(p2 == 1) s2 = 'A' + s2;
								else if(p2 == 2) s2 = 'C' + s2;
								else if(p2 == 3) s2 = 'B' + s2;
								
								if(q1 == 1) s1 = s1 + 'A';
								else if(q1 == 2) s1 = s1 + 'C';
								else if(q1 == 3) s1 = s1 + 'B';
								
								if(q2 == 1) s2 = s2 + 'A';
								else if(q2 == 2) s2 = s2 + 'C';
								else if(q2 == 3) s2 = s2 + 'B';
								
								cout << s1 << "\n" << s2 << "\n";
								return 0;
							}
						}
					}
				}
			}
		}
	}	
	
	puts("Happy new year!");
	return 0;
}
