/*
Cameron Tyree
CIS 1202 101
Jan 11 2023
*/

#include "personalLibrary.h"

void loadArrays(string[], int[], float[], int);
void calculateValues(int[], float[], float[], int);
void displayTable(string[], int[], float[], float[], int);

int main() {

	const int SIZE = 20;
	string product[SIZE];
	int quanity[SIZE];
	float cost[SIZE];
	float value[SIZE];
	int items = 0;

	loadArrays(product, quanity, cost, SIZE);
	calculateValues(quanity, cost, value, SIZE);
	displayTable(product, quanity, cost, value, SIZE);
	endProgram();
}

void loadArrays(string product[], int quanity[], float cost[], int SIZE) {
	ifstream fin;
	int items = 0;
	fin.open("inventory.txt");
	if (fin.is_open()) {
		while (items < SIZE && fin >> product[items] >> quanity[items] >> cost[items]) {
			items++;
		}
	}
	else {
		cout << "Unable to open file";
	}

}
void calculateValues(int quanity[], float cost[], float value[], int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		value[i] = quanity[i] * cost[i];
	}
}
void displayTable(string product[], int quanity[], float cost[], float value[], int SIZE) {

	float totalValue = 0;
	float highestValue = 0;
	float storage = 0;
	int highestIndex = -1;
	float averageValue = 0;
	cout << setw(15) << left << "Product Code" << setw(15) << "Quanity" << setw(15)
		<< "Cost Each" << setw(15) << "Total Value" << endl;

	for (int i = 0; i < 6; i++) {
		cout << setw(15) << left << product[i] << setw(15) << quanity[i]
			<< setw(15) << fixed << setprecision(2) << cost[i] << setw(15) << value[i];
		totalValue += value[i];
		if (value[i] > 9000) {
			cout << " !!! - Over $9000";
		}
		cout << endl;
		if (value[i] > highestValue) {
			highestValue = value[i];
			highestIndex = i;
		}
	}
	if (highestIndex != -1) {
		cout << "\nThe product with the highest invenory value is " << product[highestIndex] << endl;
	}
	for (int i = 0; i < SIZE; i++) {
		averageValue = quanity[i] / totalValue;
	}
		cout << "The average cost of an inventory item is $" << fixed << setprecision << averageValue;
}
