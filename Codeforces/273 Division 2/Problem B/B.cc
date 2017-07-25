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

int n, m;

int main(){
	cin>>n>>m;
	if(n == m){
		cout<<"0 0\n";
		return 0;
	}	
	else{
		n -= m; //itne aadmi bach gaye
		long long mx = (1LL*(n)*(n+1))/2;
		long long a = n/m, b = n%m;
		long long mn = (b*(((a+2)*(a+1)))/2) + (1LL*m-b)*(((a+1)*(a))/2);
		cout<<mn<<" "<<mx<<endl;
	}
	
	
	return 0;
}
