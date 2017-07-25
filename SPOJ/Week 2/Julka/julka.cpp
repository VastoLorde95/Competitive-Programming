#include<iostream>
#include<string>
using namespace std;
string div_by_two(string a){
	int a_length = a.length();
	int i, t;
	int carry = 0;
	string c = "";
	for(i = 0; i < a_length; i++){
		t = a[i] - 48;
		c = c + (char) ((( t + carry )/2) + 48);
		if ( t%2 == 1){
			carry = 10;
		}
		else{
			carry = 0;
		}
	}
	int j = 0;
	while(c[j] == '0'){
		c = c.substr(j+1);
	}
	
	if(c.length() == 0){
		c = '0';
	}
	return c;
}


string sub(string a, string b){
	int a_length = a.length(), b_length = b.length();
	string c = "";
	int borrow_from, i = a_length -1, j;
	for(j = b_length -1; j >= 0; j--){
		if(b[j] <= a[i]){
			c = (char) (a[i] - b[j] + 48) + c;
		}
		else{
			borrow_from = i - 1;
			while(a[borrow_from] == '0'){
				borrow_from--;
			}
			a[borrow_from++]--;
			while(borrow_from < i){
				a[borrow_from++] = 57;
			}
			c = char(a[i] - b[j] + 58) + c;
		}
		i--;
	}
	
	if(i >= 0){
		while(i>=0){
			c = a[i] + c;
			i--;
		}
	}
	
	j = 0;
	while(c[j] == '0'){
		c = c.substr(j+1);
	}
	
	if(c.length() == 0){
		c = '0';
	}
	
	return c;
}

string add(string a, string b){
	int a_length = a.length(), b_length = b.length();
	string c = "";
	int i = a_length -1, j;
	int t1, t2,total,carry = 0;
	for(j = b_length -1; j >= 0 && i >= 0; j--){
		t1 = a[i] - 48;
		t2 = b[j] - 48;
		total = t1 + t2 + carry;
		carry = total/10;
		if(carry!=0)
			total -= 10;
		c = char(total + 48) + c;
		i--;
	}
	if(i >= 0){
		while(i>=0){
			t1 = a[i] - 48;
			total = t1 + carry;
			carry = total/10;
			if(carry!=0)
				total -= 10;
			c = (char)(total + 48) + c;
			i--;
		}
	}
	if(j >= 0){
		while(j>=0){
			t1 = b[j] - 48;
			total = t1 + carry;
			carry = total/10;
			if(carry!=0)
				total -= 10;
			c = (char)(total + 48) + c;
			j--;
		}
	}
	if (carry != 0)
	{
		c = char(carry + 48) + c;
	}
	j = 0;
	while(c[j] == '0'){
		c = c.substr(j+1);
	}
	
	if(c.length() == 0){
		c = '0';
	}
	
	return c;
}

int main(){
	string apples, diff, temp1, temp2;
	int t = 10;
	while(t--){
		cin>>apples;
		cin>>diff;
		temp1 = sub(apples, diff);
		if (temp1.length() == 1 && temp1[0] == '1'){
			cout<<diff<<endl;
			cout<<temp1<<endl;
		}
		else{
			temp1 = div_by_two(temp1);
			cout<<add(temp1, diff)<<endl;
			cout<<temp1<<endl;
		}
	}
    return 0;
}
