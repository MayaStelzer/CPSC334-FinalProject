#include "PA4.h"

int main(int argc, char * argv[]) {
	string driverName = "";
	string * driverNamePtr = &driverName;
	int numPackages = 0, heaviestId = 0;
	int * numPackagesPtr = &numPackages;
	int * heaviestIdPtr = &heaviestId;
	double heaviestWeight = 0, avgWeight = 0.0;
	double * heaviestWeightPtr = &heaviestWeight;
	double *avgWeightPtr = &avgWeight;
	LetterOccurrence letters[123];

	cout << "done" << endl;

	ifstream infile;
	infile.open(argv[1]);
	if(!infile.is_open()){
		cout << "Unable to open file: " << argv[1] << endl;
	}
	else{
		cout << "Successfully opened the file: " << argv[1] << endl;
	}
	
	Package * packageInfo = loadPackages(infile, driverNamePtr, numPackagesPtr);

	computePackageStats(packageInfo, numPackages, heaviestIdPtr, heaviestWeightPtr, avgWeightPtr);

	printPackageInfo(packageInfo, driverName, numPackages, heaviestId, heaviestWeight, avgWeight);
	
	infile.close();

	extraCredit(letters);
	
	return 0;
}
