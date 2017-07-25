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
	int t, no_of_rounds, n, i, j, temp, count;
	set<int> data[1001];
	int no_opp[1001];
	sd(t);
	
	while(t--){
		sd(n);
		no_of_rounds = ceil(log(n)/log(2)), count = 0;
		
		for(i = 1; i <= n; i++){
			sd(no_opp[i]);
			for(j = 1; j <= no_opp[i]; j++){
				sd(temp);
				data[temp].insert(i);
			}
		}
		
		/*cout<<no_of_rounds<<endl;
		for( i = 0; i < n; i++){
			set<int>::iterator it = data[i].begin();
			while(it != data[i].end()){
				cout<<*it<<" ";
				it++;
			}
			cout<<endl;
		}*/
		
		
				
		
		
	}
	return 0;
	}
