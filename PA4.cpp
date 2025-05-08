#include "PA4.h"

Package * loadPackages(ifstream& infile, string * driverName, int * numPackages){
	string trashbin = "", name = "";

	getline(infile, *driverName);

	int count = 0;
    while (infile.good()) {
        string line;
        getline(infile, line);
        if (!line.empty()) {
            count++;
        }
    }
    infile.clear();
    infile.seekg(0, ios::beg);

	count /= 5;

	Package * packages = new Package[count];
	
	getline(infile, trashbin);

	for (int i = 0; i < count; i++){
		infile >> packages[i].id;
		infile >> packages[i].weight;
		infile >> packages[i].width;
		infile >> packages[i].length;
		infile >> packages[i].height;
	}

	*numPackages = count;
	return packages;
	return NULL;
}


void computePackageStats(const Package packages[], const int numPackages, int * heaviestId, double * heaviestWeight, double * avgWeight) {
	int index = 0;
	double sumWeight = 0.0;
	for (int i = 0; i < numPackages; i++){
		sumWeight += packages[i].weight;
		if (packages[i].weight > packages[index].weight){
			index = i;
		}
	}
	*heaviestId = packages[index].id;
	*heaviestWeight = packages[index].weight;
	*avgWeight = sumWeight / numPackages;
}

void printPackageInfo(const Package packageInfo[], const string driverName, const int numPackages, const int heaviestId, const double heaviestWeight, const double avgWeight){
	cout << driverName << " is carrying " << numPackages << " packages." << endl << endl;
	cout << "Package Information" << endl;
	cout << "_____________________________" << endl;
	
	for (int i = 0; i < numPackages; i++){
		cout << "Package ID: " << packageInfo[i].id << endl;
		cout << "Package Weight: " << packageInfo[i].weight << endl;
		cout << "Package Width: " << packageInfo[i].width << endl;
		cout << "Package Length: " << packageInfo[i].length << endl;
		cout << "Package Height: " << packageInfo[i].height << endl << endl;
	}
	
	cout << "Package Stats" << endl;
	cout << "_____________________________" << endl;
	cout << "ID of heaviest package: " << heaviestId << endl;
	cout << "Weight of heaviest package: " << heaviestWeight << endl;
	cout << "Average weight of packages on truck: " << avgWeight << endl;
	cout << "_____________________________" << endl;

}

void extraCredit(LetterOccurrence letters[]){
	string phrase = "";
	int numChars = 0;
	cout << "Enter a string: ";
	getline(cin, phrase);
	while(phrase != "quit"){
		for (int i = 'A'; i < 123; i++){
			letters[i].count = 0;
			letters[i].frequency = 0.0;
		}
		numChars = 0;
		for (int i = 0; i < phrase.size(); i++){
			char currChar = phrase[i];
			if (phrase.substr(i,1) != " "){
				letters[currChar].count++;
				numChars++;
			}
		}
		calculateFrequency(letters, numChars);
		printHistogram(letters);
		cout << "Enter a string: ";
		getline(cin, phrase);
	}
}

void printHistogram(const LetterOccurrence letters[]){
	int max = letters[65].count;
	char maxLetter = '\0';
	for (int i = 65; i < 123; i++){
		if (letters[i].count > max){
			max = letters[i].count;
			maxLetter = (char)i;
		}
	}
	cout << endl;
	for (int i = max; i > 0; i--){
		for (int j = 65; j < 91; j++){
			if (letters[j].count <= max && letters[j].count >= i){
				cout << "*";
			}
			else{
				cout << " ";
			}
		}
		for (int j = 97; j < 123; j++){
			if (letters[j].count <= max && letters[j].count >= i){
				cout << "*";
			}
			else{
				cout << " ";
			}
		}
		cout << endl;
	}
	cout << "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" << endl;
	cout << "The letter with the maximum number of occurance is " << maxLetter << " with " << max << " occurances." << endl;
	cout << "The frequency of the letter with the maximum number of occurrences is " << letters[maxLetter].frequency << endl;
}

void calculateFrequency(LetterOccurrence letters[], int size){
	for (int i = 65; i < 91; i++){
		letters[i].frequency = letters[i].count / (double)size;
	}
	for (int i = 97; i < 123; i++){
		letters[i].frequency = letters[i].count / (double)size;
	}
}