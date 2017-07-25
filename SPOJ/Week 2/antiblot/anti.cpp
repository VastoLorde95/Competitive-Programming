#include<iostream>
#include<string>
using namespace std;
/*Ths function subtracts two given strings of numbers. This function runs only for positive integers and assumes that a > b*/

string add(string a, string b);
string sub(string a, string b);
string multiply(string a, string b);
string naive_multiply(string &a, string &b);

/*
*  A few helper functions
*/


/*This appends m 0s to the end of the string to act as a multiplication by 10^m*/
string shift_left(string &a, int m){
	while(m--){
		a = a + (char)(48);
	}
	return a;
}

/*This function removes all valueless 0s from the starting of the string*/
void unpad_zeroes(string &a){
	int i = 0;
	int l = a.length();
	string zero("0");
	while(a[i] == '0'){
		i++;
	}
	a = a.substr(i);
	if(a.length() == 0){
		a = zero;
	}
}

/*This appends 'l' of zeroes to the beggining of the string*/
void pad(string &a, int l){
	while(l--){
		a = '0' + a;
	}
	
	//return a;
}



/*This function adds the two numbers a and b using grade school addition method*/
string add(string a, string b){	
	/* 	
	*	If a is negative, the result is (b-a)
	*	If b is negative, the result is (a-b)
	*	If a and b are both negative the result is -(b+a)
	*/
	if(a[0] == '-' and b[0] == '-')
		return '-' + add(a.substr(1), b.substr(1));
	else if(a[0] == '-')
		return sub(b, a.substr(1));
	else if(b[0] == '-')
		return sub(a, b.substr(1));
	
	unpad_zeroes(a);
	unpad_zeroes(b);
	
	int a_length = a.length(), b_length = b.length();
	if(a == "0")	
		return b;
	else if(b == "0")
		return a;

	string c = "";		//This is the new string where the result will be stored
	
	int digit1, digit2, total = 0, carry = 0, j = b_length -1, i = a_length -1;		//digit1 and digit2 are the digits of a and b respectively
	
	for(; j >= 0 && i >= 0; j--){	//The loop runs till either of the numbers a or b run out of digits to compute upon
	
		//The character is converted from its ASCII value to an integer value, computed upon and then converted back to ASCII
		digit1 = a[i] - 48;		
		digit2 = b[j] - 48;
		
		total = digit1 + digit2 + carry;
		carry = total / 10;
		
		if(carry != 0) total -= 10;	
		//The total should always be a single digit, so if a carry is present, it means that the number is greater than 10
		
		c = char(total + 48) + c;
		
		i--;
	}
	if(i >= 0){				//This handles the case where a has more digits than b
		while(i >= 0){
		
			digit1 = a[i] - 48;
			
			total = digit1 + carry;
			carry = total/10;
			
			if(carry!=0) total -= 10;
			
			
			c = (char)(total + 48) + c;
			
			i--;
		}
	}
	if(j >= 0){							//This handles the case where b has more digits than a
		while(j>=0){
			digit2 = b[j] - 48;	
			total = digit2 + carry;
			carry = total/10;	
			if(carry!=0) total -= 10;		
			c = (char)(total + 48) + c;
			
			j--;
		}
	}
	
	if (carry != 0) c = char(carry + 48) + c;		//This takes care of the final carry over if any
	
	unpad_zeroes(c);
	return c;
}





/*Ths function subtracts two given strings of numbers*/
string sub(string a, string b){
	/* 	
	*	If a is negative, the result is -(b+a)
	*	If b is negative, the result is (a+b)
	*	If a and b are both negative the result is 	(b-a)
	*/
	if(a[0] == '-' and b[0] == '-')
		return sub(b.substr(1), a.substr(1));
	else if(a[0] == '-')
		return '-' + add(a.substr(1), b);
	else if(b[0] == '-')
		return add(a, b.substr(1));
	
	/*We pad the two numbers and check which one is bigger so that we can assert wether the result is negative or not*/
	int a_length = a.length(), b_length = b.length(), borrow_from, i, j;
	
	bool is_negative = false;		// Is the result of the subtraction negative? It is false by default

	string c = "", temp ="";		//The temp string has been made to accomodate string swaps
	
	if(a_length > b_length){
		pad(b, a_length - b_length);
		j = b_length - 1;
		i = a_length - 1;
	}		
	else if(a_length < b_length){
		pad(a , b_length - a_length);
		j = a_length - 1;
		i = b_length - 1;
	}
	else{
		j = a_length - 1;
		i = j;
	}
	
	/*
		This method to compare strings works accurately only if they are of equal length.
	    Hence we are padding them with zeroes if they are of unequal length
	 */
	if(b>a){
		is_negative = true;		//This means the result will be negative
		temp = a;
		a = b;
		b = temp;
	}
	
	unpad_zeroes(a);
	unpad_zeroes(b);
	
	if(b == "0"){
		return a;
	}

	for(j; j >= 0; j--){
		if(b[j] <= a[i]){	
			 //This is the case where we dont have to borrow from the next digits
			 c = (char) (a[i] - b[j] + 48) + c;	
		}
		else{	
			//In this case we have to borrow
			borrow_from = i - 1;	
			
			while(a[borrow_from] == '0'){	
				//This loop gives us the first index from where we can borrow a digit
				 borrow_from--;
			}
			a[borrow_from++]--;
			while(borrow_from < i) a[borrow_from++] = 57;
			
			c = char(a[i] - b[j] + 58) + c; // After succesfully borrowing, we can now subtract the numbers
		}
		i--;
	}
	if(i >= 0){			
		//In case the string a has more digits than b, then the remaining digits are appended in this loop
		while(i>=0){
			c = a[i] + c;
			i--;
		}
	}
	unpad_zeroes(c);
	if(is_negative)
		return '-' + c;
	
	return c;
}


bool contains_machula(string a){
	//cout<<a<<endl;
	int i = 0;
	int l = a.length();
	while(i < l){
		if(a[i] == 'm')
			return true;
		i++;
	}
	return false;
}

int main(){
	int t;
	cin>>t;
	string a, b, c, d, e;
	while(t--){
		cin>>a>>b>>c>>d>>e;
		if(contains_machula(a)){
			cout<<sub(e,c)<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<endl;
		}
		else if(contains_machula(c)){
			cout<<a<<" "<<b<<" "<<sub(e,a)<<" "<<d<<" "<<e<<endl;
		}
		else{
			cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<add(a,c)<<endl;
		}
	}
	return 0;
}
