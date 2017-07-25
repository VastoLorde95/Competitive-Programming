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
	int n, digits[1000], number[1000], maxl, l, ind, prev, ans, temp, off, x, flag;
	vector<pair<int,int> > indices;
	char c;
	sd(n);
	for(int i = 0; i < n; i++){
		scanf(" %c",&c);
		digits[i] = c - 48;
	}	
	
	prev = digits[0], ind = 0, maxl = 1, l = 1;
	for(int i = 1; i < n; i++){
		if(digits[i] == prev){
			l++;
		}	
		else{
			if(l > maxl){
				indices.clear();
				indices.push_back(make_pair(l, ind));
				maxl = l;
			}
			else if(l == maxl){
				indices.push_back(make_pair(l, ind));
			}
			l = 1;
			prev = digits[i];
			ind = i;
		}
	}
	if(maxl == 1){
		indices.push_back(make_pair(1, n-1));
	}
	else if(digits[n-1] == digits[n-2]){
		if(l > maxl){
			indices.clear();
			indices.push_back(make_pair(l, ind));
			maxl = l;
		}
		else if(l == maxl){
			indices.push_back(make_pair(l, ind));
		}
	}
	sort(indices.begin(), indices.end(), greater<pair<int, int> >());
	
	
	
	off = indices[0].second;
	temp = (10 - digits[indices[0].second])%10;
	for(int i = 0; i < n; i++){
		number[i] = (digits[(i+off)%n] + temp)%10;
	}
	for(int i = 1; i < indices.size(); i++){
		off = indices[i].second;
		temp = (10 - digits[off])%10;
		flag = -1;
		for(int j = 0; j < n; j++){
			x = (digits[(j+off)%n] + temp) %10;
			if( x > number[j]){
				j = n;
			}
			else if(x < number[j]){
				flag = j;
				j = n;
			}	
		}
		if(flag != -1){
			for(int j = flag; j < n; j++){
				number[j] = (digits[(j+off)%n] + temp)%10;		
			}
		}
	}
	
	for(int i = 0; i < n; i++)
		cout<<number[i];
	cout<<endl;
	
	return 0;
}
