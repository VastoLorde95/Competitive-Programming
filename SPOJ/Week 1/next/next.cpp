#include<iostream>
using namespace std;
int main(){
	unsigned long a,b,c;
	cin>>a>>b>>c;
	while(a != 0, b != 0, c != 0){
		if(c-b == b-a){
			cout<<"AP "<< c + c - b<<endl;
		}
		else{
			cout<<"GP "<< c * (c/b) <<endl;
		}
		cin>>a>>b>>c;
	}	
	return 0;
}
	
