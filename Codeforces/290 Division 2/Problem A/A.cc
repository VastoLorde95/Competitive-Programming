#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<math.h>

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z);

using namespace std;

int main(){
	int n, m;
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(i%2 == 1){
				cout<<"#";
			}
			else{
				if(j == m and i%2 == 0 and i%4 != 0){
					cout<<"#";
				}
				else if(j == 1 and i%4 == 0){
					cout<<"#";
				}
				else{
					cout<<".";
				}
			}
			
		}
		cout<<endl;
	}
	return 0;
}
