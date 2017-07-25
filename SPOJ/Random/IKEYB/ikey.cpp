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
#define print(x) printf("%d\n",x);
#define print2(x,y) printf("%d %d\n",x,y);
#define print3(x,y,z) printf("%d %d %d\n",x,y,z);
#define printull(x) printf("%ull\n",x);

using namespace std;
int t, k, l, freq[90], pos, cap, number=1, dp[90][90][90], INF = 100000000, mini;
char keys[100], letters[100], first_char;
string result[90];
int main(){
	sd(t);
	while(number <= t){
		sd2(k,l);
		scanf("%s",keys);
		scanf("%s",letters);
		first_char = letters[0];
		for(int i = 0; i < l; i++){
			sd(freq[i]);
		}
		for(int i = 0; i < k; i++){
			result[i] = "";
			for(int j = 0; j < l; j++){
				for(int p = 0; p < l; p++){
					dp[i][j][p] = INF;
				}
			}
		}
		dp[0][0][0] = freq[0];
		for(int i = 1; i < l; i++){
			dp[0][i][i] = (dp[0][i-1][i-1] + (i+1)*freq[i]);
		}
		
		for(int i = 1; i < k; i++){//which key
			for(int j = i; j < l; j++){//which letter
				for(int p = 0; p <= j - i; p++){//width of that button
					if(p == 0){
						mini = INF;
						for(int q = 0; q < j; q++){
							mini = min(mini,dp[i-1][j-1][q]);
							
						}
						dp[i][j][p] = mini + (p+1)*freq[j];
					}
					else{
						dp[i][j][p] = dp[i][j-1][p-1] + (p+1)*freq[j];
					}
				}
			}
		}
		cap = l-1;
		for(int i = k-1; i >= 0; i--){
			for(int j = cap; j >= 0; j--){
				mini = INF, pos = -1;
				for(int p = 0; p < j; p++){
					if(dp[i][j][p] <= mini){
						mini = dp[i][j][p];
						pos = p;
					}
				}
				cap = cap - pos - 1;
				while(pos >= 0){
					result[i] = letters[j--] + result[i];
					pos--;
				}
				j = -1;
			}
		}
		if(result[0][0] != first_char){
			result[0] = first_char + result[0];
		}
		printf("Keypad #%d:\n",number);
		for(int i = 0; i < k; i++){
			printf("%c: ",keys[i]);
			printf("%s\n",result[i].c_str());
		}
		printf("\n");
		number++;
	}
	return 0;
}
