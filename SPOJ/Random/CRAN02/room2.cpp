#include <iostream>
#include <map>

using namespace std;

int main ( int argc ,char * argv[] ) {

	int t;
	cin >> t;

	map< long long int , long long int > sum_p;
	map< long long int , long long int>::iterator itr;

	while ( t-- ) {


		long long int count = 0;
		long long int n;

		cin >> n;

		long long int array[n];

		cin >> array[0];

		sum_p[ array[0] ] ++;

		for ( int i = 1 ; i < n ; i++ ) {
			cin >> array[i];
			array[i] += array[i-1];
			sum_p[ array[i] ] ++;
		}


		for ( itr = sum_p.begin() ; itr != sum_p.end() ; itr++ ) {
			long long int a,b;

			a = itr->first;
			b = itr->second;

			if ( a != 0 ) {
				count += b * (b-1) / 2;
			}
			else {
				count += b + (b * (b-1)/2 );
			}
		}

		cout << count << endl;
		sum_p.clear();
	}

	return 0;

}





