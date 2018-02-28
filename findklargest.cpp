#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;

int *findkLargest(int[],int[], int, int);

int main() {

	int k;											//Number of largest to be found
	int n;											//Size of initial array 

	cout << "Enter array size:" << endl;
	cin >> n;

	int *arr = new int[n];							//Array to be filled with random numbers

	cout << "How many largest numbers?" << endl;
	cin >> k;								

	srand(time(NULL));
						
	for (int i = 0; i < n; i++)						//Fill array with random numberes
	{
		arr[i] = rand();
	}

	cout << endl;
	cout << "List with random generated numbers:" << endl<<endl;
	for (int i = 0; i < n; i++)						//Output array with random numbers
	{
		cout <<arr[i]<<" ";
		if (0 == ((i+1) % 25))						//Provide better view of array
			cout << endl;
	}

	cout << endl;
	
	int *maxnum = new int[k];						//Array to hold largest k numbers
	maxnum = findkLargest(arr, maxnum, k, n);		//Find largest k numbers and fill maxnum array

	cout << endl;
	if (k > 0 && k <= n) {
		cout << "Largest " << k << " numbers:" << endl<<endl;
		for (int i = 0; i < k; i++)					//Output largest k numbers
		{
			cout << maxnum[i]<<" ";
			if (((i+1) % 25) == 0)
				cout << endl;
		}
	}
	

	cout << endl<<endl;
	
	delete[] arr;									//Deallocate dynamic arrays
	delete[] maxnum;
  
	system("Pause");
	return 0;
}

int *findkLargest(int arr[], int maxnum[], int k, int n) {
	
	auto started = chrono::high_resolution_clock::now();	//Start chronometer

	if (k <= 0 || k > n) {									//If k bigger than array size, or less or equal to 0, Output invalid number
		cout << endl;
		cout << "Invalid number of largest numbers" << endl;
		return 0;
	}
	else if (k == n)										//If k is equal to input array size, return whole array
		return arr;

	for (int i = 0; i < k; i++) {							//Copy the first K elements to maxnum array
		maxnum[i] = arr[i];
	}

	for (int i = k; i < n; i++) {
		int smallest = maxnum[0];							//Initialize smalles number with first element of maxnum
		int j = 0;											//Index of smalles number is 0
		for (int l = 0; l < k; l++) {
			if (smallest > maxnum[l]) {						//If lth maxnum element is less than smallest, there is a new smallest
				smallest = maxnum[l];						//New smallest found in maxnum
				j = l;										//Index of new smallest
			}
		}
		if (arr[i] > maxnum[j])								//If element in remainder array is greater than maxnum smallest
			maxnum[j] = arr[i];								//Set maxnum smallest index to element greater of remainder array
	}

	auto done = chrono::high_resolution_clock::now();		//End chronometer
	cout << endl;
	//Display executing time in nanoseconds
	cout <<"Execution time: "<< chrono::duration_cast<std::chrono::nanoseconds>(done - started).count()<<" nanoseconds";
	cout << endl;
	return maxnum;
}
		
	
