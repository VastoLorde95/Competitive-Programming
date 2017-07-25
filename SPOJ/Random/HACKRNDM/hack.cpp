#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>

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
	map<int,int> a;
	int n, k, i, temp, count = 0;
	sd2(n,k);
	int array[n];
	for(i = 0; i < n; i++){
		sd(temp);
		a[temp] = 1;
		array[i] = temp;
	}
	for(i = 0; i < n; i++){
		if(a.find(array[i] - k ) != a.end())
			count++;
	}
	cout<<count<<endl;
	return 0;
}
