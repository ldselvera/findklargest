#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;

int *find3Largest(int[], int);

int main() {

	int size;

	cout << "Enter size of array:";
	cin >> size;
	
	int *a = new int[size];								//New array to hold largest 3 numbers
	int *largest3 = new int[3];							//Array to hold random numbers

	if (size <= 0) {
		cout << "Invalid size.";
	}
	else {		
		srand(time(NULL));								//Create random number

		for (int i = 0; i < size; i++)
		{
			a[i] = rand();								//Fill array with random numbers
		}

		for (int i = 0; i < size; i++)
		{
			cout << a[i] << " ";						//Output array of random numbers
			if ((i + 1) % 25 == 0)						//Provide better view array
				cout << endl;
		}

		cout << endl;
		largest3 = find3Largest(a, size);				//Find 3 largest numbers and fill largest3 array

		cout << endl;

		cout << "Largest 3 numbers:" << endl;
		for (int i = 0; i < size; i++) {
			cout << largest3[i] << " ";					//Output largest3 array
		}
	}
	cout << endl<<endl;
	system("Pause");
		
	return 0;
	
	delete[] a;											//Deallocate dynamic arrays
	delete[] largest3;

}

//Function to find 3 largest number in an array.
//Precondition: Prior to search, the array must not be empty.
//Postcondition: The array is the old array containing the 
//3 largest numbers in the first 3 index.
int *find3Largest(int a[], int n)
{
	auto started = chrono::high_resolution_clock::now();//Start chronometer	
	int maxi, maxj, maxk;								//Hold max numbers in array
	if (n<=3) {											//If array is less than 3, return input array
		return a;
	}

	int sum = a[0] + a[1] + a[2];						//Set sum to the addition of first 3 elements in array
		for (int i = 0; i < n; i++) {				
			for (int j = i + 1; j < n; j++) {
				for (int k = j + 1; k < n; k++) {
					int newsum = a[i] + a[j] + a[k];	//Set new sum to the addition of another combination of 3 elements in array
					if (sum < newsum) {					//If new sum is greater than sum, max i, j, or k must change
						maxi = a[i];
						maxj = a[j];
						maxk = a[k];
						sum = newsum;					
					}
				}
			}
		}
	a[0] = maxi;										//Set first element in array to maxi
	a[1] = maxj;										//Set second element in array to maxj
	a[2] = maxk;										//Set third element in array to maxk
	auto done = chrono::high_resolution_clock::now();	//End chronometer
	cout << endl;
	//Output execution time
	cout << "Execution time: " << chrono::duration_cast<std::chrono::nanoseconds>(done - started).count() << " nanoseconds";
	cout << endl;
	return a;											//Return array with largest 3 elements in first 3 index
}
	
