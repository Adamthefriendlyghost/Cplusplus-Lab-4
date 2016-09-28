//Sorting Numbers - Adam Jackson 26/09/2016

//Usual Headers
#include <iostream>
using namespace std;

//Main Program
int main() {

	//Initialising Array
	const int ArrSize = 10;
	int NumArray[ArrSize];
	
	//Initialising Temporary Storage Variable
	int temp = 0;
	
	//Inputting the Numbers into the Array
	for (int i = 0; i < ArrSize; i++) {

		cout << "Please enter number " << i+1 << endl;
		cin >> NumArray[i];
	}

	//Looping through all variables
	for (int j = 0; j < ArrSize - 1; j++) {
		
		//Checking if all variables need sorted
		for (int l = 0; l < ArrSize - 1; l++) {

			//Sorting all Numbers
			if (NumArray[l] > NumArray[l + 1]) {
				temp = NumArray[l];
				NumArray[l] = NumArray[l + 1];
				NumArray[l + 1] = temp;
			}

		}

	}

	//Displaying all Array entries
	for (int m = 0; m < ArrSize; m++) {
		cout << NumArray[m];
	}
}