#include<iostream>
#include<cmath>
using namespace std;
int no_of_rectangles(int n){
	float count = 0;
	int i = 1;
	int bound = (int) sqrt(n);
	while(i <= bound){
		if(n%i == 0) count += 1;
		i += 1;
	}
	return count;
}
int no_of_rectangles2(int n){
	if((n & (n-1)) == 0){
		float count = 0;
		while(n>0){
			n = n>>1;
			count++;
		}
		return ceil(count/2); 
	}
	else{
		float count = 1;
		int i = 2;
		int bound = (int) sqrt(n);
		while(i <= bound){
			if(n%i == 0) count += 1;
			i += 1;
		}
		return count; 
	}
}
int main(){
	int n, i = 2, total = 1;
	cin>>n;
	while(i <= n){
		if(i%2 == 1)
			total += no_of_rectangles(i);
		else 
			total += no_of_rectangles2(i);
		i++;
	}
	cout<<total<<endl;
	return 0;
}

