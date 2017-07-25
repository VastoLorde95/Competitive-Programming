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

int main(){
	string input;
	int points[1000][1000], l, x, y, ans;
	cin>>input;
	while(input[0] != 'Q'){
		memset(points, 0, sizeof(points));
		l = input.length();
		x = 0, y = 0, ans = 0;
		points[x][y] = 1;
		for(int i = 0; i < l-1 ; i++){
			if(input[i] == 'U') y ++;
			else if(input[i] == 'D') y--;
			else if(input[i] == 'L') x--;
			else if(input[i] == 'R') x++;
			//cout<<x<<" "<<y<<endl;
			if(points[x][y] == 1){
				ans += 1;
			}	
			else{
				points[x][y] = 1;
			}
		}
		cout<<ans<<endl;
		cin>>input;
	}
	return 0;
}
