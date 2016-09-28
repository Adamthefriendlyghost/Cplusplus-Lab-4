//Age Calculation Program

#include <iostream>

using namespace std;

int main() {

	int ages[5];
	int AddTotal = 0;
	int Average = 0;
	int NumAbove = 0;
	int NumBelow = 0;

	for (int i = 0; i < 5; i++) {

		cout << "Please enter age number " << i + 1;
		cin >> ages[i];

	}

	for (int l = 0; l < 5; l++) {

		AddTotal = AddTotal + ages[l];
		Average = AddTotal / 5;

	}

	for (int m = 0; m < 5; m++) {

		if (ages[m] > Average) {

			NumAbove = NumAbove + 1;

		}
		if (ages[m] < Average) {

			NumBelow = NumBelow + 1;

		}

	}
	
	cout << "The Average Age is: " << Average << endl;
	cout << "The Number of Ages Above the Average is: " << NumAbove << endl;
	cout << "The Number of Ages Below the Average is: " << NumBelow << endl;
}