#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<utility>
#include<map>
#include<vector>

#define SD(x) scanf("%d",&x);
#define print(x,y,z) printf("%d %d %d\n",x,y,z);
#define print2(x) printf("%d\n",x);
#define SULL(x) scanf("%ull",&x)
#define MOD 1000000007

using namespace std;

vector<int> dp1[1001];
vector<int> dp2[1001];
vector<int> dp3[1001];
int L, N, i, j;
int c[201][201], re[1001];

int main(){
	int t;
	cin>>t;
	
	int c1, c2, c3, m, flag;
	while(t--){
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(0);
		vector<int> v2 (v1);
		vector<int> v3 (v1);
		dp1[0] = v1;
		dp2[0] = v2;
		dp3[0] = v3;
		
		SD(L);
		SD(N);
		for(i = 1; i <= L; i++){
			for( j = 1; j <= L; j++){
					SD(c[i][j]);
			} 
		}
		
		for(i = 1; i <= N; i++){
				SD(re[i]);
				v1[0] = re[i];
				v2[1] = re[i];
				v3[2] = re[i];
				
				j = re[i];
				
				flag = 0;
				//case 1
				if( j == dp1[i-1][0] or j == dp1[i-1][1] or j == dp1[i-1][2]){
					c1 = dp1[i-1][3];
					flag = 1;
					}
				else
					c1 = c[dp1[i-1][0]][j] + dp1[i-1][3];
				if( j == dp2[i-1][0] or j == dp2[i-1][1] or j == dp2[i-1][2]){
					c2 = dp2[i-1][3];
					flag = 2;
					}
				else
					c2 = c[dp2[i-1][0]][j] + dp2[i-1][3];
				if( j == dp3[i-1][0] or j == dp3[i-1][1] or j == dp3[i-1][2]){
					c3 = dp3[i-1][3];
					flag = 3;
					}
				else
					c3 = c[dp3[i-1][0]][j] + dp3[i-1][3];
					
				m = min(min(c1, c2), c3);
				if( m == c1){
					if(flag == 1) v1[0] = dp1[i-1][0]; else v1[0] = j;
					v1[1] = dp1[i-1][1];
					v1[2] = dp1[i-1][2];
				}
				else if( m == c2){
					if(flag == 2) v1[0] = dp2[i-1][0]; else v1[0] = j;
					v1[1] = dp2[i-1][1];
					v1[2] = dp2[i-1][2];
				}
				else if( m == c3){
					if(flag == 3) v1[0] = dp3[i-1][0]; else v1[0] = j;
					v1[1] = dp3[i-1][1];
					v1[2] = dp3[i-1][2];
				}
				
				v1[3] = m;	
				
				
				
				
				flag = 0;
				//case 2
				if( j == dp1[i-1][0] or j == dp1[i-1][1] or j == dp1[i-1][2]){
					c1 = dp1[i-1][3];
					flag = 1;
					}
				else
					c1 = c[dp1[i-1][1]][j] + dp1[i-1][3];
				if( j == dp2[i-1][0] or j == dp2[i-1][1] or j == dp2[i-1][2]){
					c2 = dp2[i-1][3];
					flag = 2;
					}
				else
					c2 = c[dp2[i-1][1]][j] + dp2[i-1][3];
				if( j == dp3[i-1][0] or j == dp3[i-1][1] or j == dp3[i-1][2]){
					c3 = dp3[i-1][3];
					flag = 3;
					}
				else
					c3 = c[dp3[i-1][1]][j] + dp3[i-1][3];
					
				m = min(min(c1, c2), c3);
				if( m == c1){
					if(flag == 1) v2[1] = dp1[i-1][1]; else v2[1] = j;
					v2[0] = dp1[i-1][0];
					v2[2] = dp1[i-1][2];
				}
				else if( m == c2){
					if(flag == 2) v2[1] = dp2[i-1][1]; else v2[1] = j;
					v2[0] = dp2[i-1][0];
					v2[2] = dp2[i-1][2];
				}
				else if( m == c3){
					if(flag == 3) v2[1] = dp3[i-1][1]; else v2[1] = j;
					v2[0] = dp3[i-1][0];
					v2[2] = dp3[i-1][2];
				}
				
				v2[3] = m;
				
				
				
				flag = 0;
				//case 3
				if( j == dp1[i-1][0] or j == dp1[i-1][1] or j == dp1[i-1][2]){
					c1 = dp1[i-1][3];
					flag = 1;
					}
				else
					c1 = c[dp1[i-1][2]][j] + dp1[i-1][3];
				if( j == dp2[i-1][0] or j == dp2[i-1][1] or j == dp2[i-1][2]){
					c2 = dp2[i-1][3];
					flag = 2;
					}
				else
					c2 = c[dp2[i-1][2]][j] + dp2[i-1][3];
				if( j == dp3[i-1][0] or j == dp3[i-1][1] or j == dp3[i-1][2]){
					c3 = dp3[i-1][3];
					flag = 3;
					}
				else
					c3 = c[dp3[i-1][2]][j] + dp3[i-1][3];
					
				m = min(min(c1, c2), c3);
				if( m == c1){
					//cout<<i<<endl;
					if(flag == 1) v3[2] = dp1[i-1][2]; else v3[2] = j;
					//cout<<"what is it? "<<v3[2]<<" "<<m<<endl;
					v3[0] = dp1[i-1][0];
					v3[1] = dp1[i-1][1];
				}
				else if( m == c2){
					if(flag == 2) v3[2] = dp2[i-1][2]; else v3[2] = j;
					v3[0] = dp2[i-1][0];
					v3[1] = dp2[i-1][1];
				}
				else if( m == c3){
					if(flag == 3) v3[2] = dp3[i-1][2]; else v3[2] = j;
					v3[0] = dp3[i-1][0];
					v3[1] = dp3[i-1][1];
				}
				
				v3[3] = m;
					
				
				dp1[i] = v1;
				dp2[i] = v2;
				dp3[i] = v3;				
			}
		
		for(int i = 1; i <= N; i++)
			cout<<dp1[i][3]<<" ";
		cout<<endl;
		for(int i = 1; i <= N; i++)
			cout<<dp2[i][3]<<" ";
		cout<<endl;
		for(int i = 1; i <= N; i++)
			cout<<dp3[i][3]<<" ";
		cout<<endl;
		cout<<min(min(dp1[N][3], dp2[N][3]), dp3[N][3])<<endl;
		}
		
	return 0;
	}
