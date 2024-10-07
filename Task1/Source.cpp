/**
* Done by:
* Student Name: Ivan Rudiy
* Student Group: 123
*Pract 2.1
*
*Task2: A set of sequences of values ​​is given
*A[m, n]A[m, n]A[m, n], where m is the sequence number and n is the number
*elements in the m - th sequence.Find placement indices
*minimum value in the plural.
*/
	#include <iostream>
	#include <vector>
	#include <cstdlib>
	#include <ctime>
	#include <iomanip> 
	using namespace std;
	int main()
	{
		srand(static_cast<unsigned>(time(0)));

		int m;
		cout << "Enter number of sequences: ";
		cin >> m;

		int n;
		cout << "Enter length of each sequence: ";
		cin >> n;

		vector<vector<int>> A(m); // Create set of sequences

		for (int i = 0; i < m; i++) // fill this two-dimensional vector/array with random values from -99 to 99
		{
			A[i].resize(n);
			for (int j = 0; j < n; j++) {
				A[i][j] = (rand() % 199) - 99;
			}
		}

		int min_value = A[0][0]; // Search for the minimum value
		for (const vector<int>& sequence : A) {
			for (int value : sequence) {
				if ( value < min_value)
				{
					min_value = value;
				}
			}
		}


		cout << "Generated sequences:\n";//Output results, copy code from example 
		for (int i = 0; i < m; i++) {
			cout << "Sequence " << setw(2) << i + 1 << ": ";
			for (int value : A[i]) {
				cout << setw(3) << value << " ";
			}
			cout << endl;
		}

		bool found = false;//found index of minimal value
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (A[i][j] == min_value) {
					cout << "Number " << min_value << " found at index [" << i << "][" << j << "]." << endl;
					found = true;
				}
			}
		}


		return 0;
	}