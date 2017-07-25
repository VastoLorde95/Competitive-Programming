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
#define sd2(x,y) scanf("%d %d",&x,&y);
#define sd3(x,y,z) scanf("%d %d %d",&x,&y,&z);
#define sull(x) scanf("%ull",&x);

using namespace std;
string S, T;
int l1, l2;


int main(){
	cin>>S;
	int matrix[1001][1001], temp;
	while(S[0] != '#'){
		cin>>T;
		l1 = S.length(), l2 = T.length();
		
		for(int i = 0; i <= l1; i++){
			matrix[0][i] = 0;
		}
		for(int i = 0; i <= l2; i++){
			matrix[i][0] = 0;
		}
		
		//cout<<S<<endl;
		//cout<<T<<endl;
		
		for(int i = 1; i <= l1; i++){
			for(int j = 1; j <= l2; j++){
				if(S[i-1] == T[j-1]){
					//cout<<S[i]<<" "<<T[j]<<endl;
					matrix[i][j] = matrix[i-1][j-1] + 1;
				}
				else{
					matrix[i][j] = max(matrix[i-1][j],matrix[i][j-1]);
				}
			}
		}
		temp = matrix[l1][l2];
		//cout<<temp<<endl;
		printf("%d\n",((l1-temp)*15)+((l2-temp)*30));
		cin>>S;
	}
	return 0;
}
