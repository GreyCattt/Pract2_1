/*
* Task3: A set of sequences of values ??is given
A[m,n]A[m,n]A[m,n], where m is the sequence number and n is the number
elements in the mth sequence. Find the maximum negative
plural value.
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

	int min_value = A[0][0]; // Search for the minimum value by absolute value
	for (const vector<int>& sequence : A) {
		for (int value : sequence) {
			if (value < min_value)
			{
				min_value = value;
			}
		}
	}

	cout << "Generated sequences:\n";//Output results
	for (int i = 0; i < m; i++) {
		cout << "Sequence " << setw(2) << i + 1 << ": ";
		for (int value : A[i]) {
			cout << setw(3) << value << " ";
		}
		cout << endl;
	}

	cout << "\nThe minimum absolute value from all sequences: " << min_value << endl;



	return 0;
}