#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<queue>
#include<stack>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int a, b;

int dist(int x1, int x2, int y1, int y2){
	return (x1-x2)*(x1-x2) +(y1-y2)*(y1-y2);
}

int main(){
	sd2(a,b);
	
	for(int y1 = 1; y1 < a; y1++){
		int tmp = a*a - y1*y1, flag = 0;
		int x1 = sqrt(tmp);
		if(x1*x1 == tmp){
			flag = 1;		
		}
		else if((x1+1)*(x1+1) == tmp){
			flag = 1;
			x1++;
		}
		else if((x1-1)*(x1-1) == tmp){	
			x1--;
			flag = 1;
		}
		
		if(flag == 1){
			//cout << x1 << " " << y1 << endl;
			for(int y2 = 1; y2 < b; y2++){
				tmp = b*b - y2*y2, flag = 0;
				int x2 = sqrt(tmp);
				if(x2*x2 == tmp){
					flag = 1;		
				}
				else if((x2+1)*(x2+1) == tmp){
					flag = 1;
					x2++;
				}
				else if((x2-1)*(x2-1) == tmp){	
					x2--;
					flag = 1;
				}
				
				if(flag == 1 and x1 != x2 and -y1*y2 + x1*x2 == 0 and dist(x1,x2,y1,-y2) == (a*a + b*b)){
					cout << "YES\n";
					cout << "0 0\n";
					cout << x1 << " " << y1 << "\n";
					cout << x2 << " " << -y2 << "\n";
					return 0;
				}
			}
		}
	}
	
	cout << "NO\n";
	
	return 0;
}
