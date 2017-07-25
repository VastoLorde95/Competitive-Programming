#include<iostream>
#include<string>
using namespace std;
int main(){
	int col;
	cin>>col;
	while(col != 0){
		string code = "";
		string original = "";
		cin>>code;
		int l = code.length();
		int i = 0, j = 0, k = 1, m = 0;
		int jump1 = 2*col - 1, jump2 = 1;
		while(j<l){
			original += code[i];
			if(m%2 == 0){
				i += jump1;
			}
			else{
				i += jump2;
			}
			
			if(i >= l){
				i = k;
				k++;
				jump1 -= 2;
				jump2 += 2;
				m = -1;
			}
			j++;
			m++;
		}
		cout<<original<<endl;
		cin>>col;
	}
	return 0;
}
