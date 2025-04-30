/*
 Name: Maya Stelzer
 Class: CPSC 122, Spring 2023
 Date: Feburary 16, 2023
 Programming Assignment: PA3                                                                      
 Description: Pointers
 Notes:
*/

#include "PA3.h"

////////////////////////////////////
//TASK 1
////////////////////////////////////

/*************************************************************
 * Function: answerIntegerQuestions
 * Date Created: 2/13/23
 * Date Last Modified: 2/16/23
 * Description: calls the 3 functions to test
 * Input parameters: int num and bool pointers
 * Returns: none
 * Pre: num and pointers are passed in
 * Post: bool pointers are assigned
 *************************************************************/
void answerIntegerQuestions(int num, bool * isMultiple, bool * isSumEven, bool * isPrime) {
	*isMultiple = ifMultiple(num);
	*isSumEven = ifSumEvenOrOdd(num);
	*isPrime = ifPrime(num);
}

/*************************************************************
 * Function: ifMultiple
 * Date Created: 2/13/23
 * Date Last Modified: 2/16/23
 * Description: checks if num is a multiple of 7, 11, or 13
 * Input parameters: int number
 * Returns: bool if yes or no
 * Pre: num is passed in
 * Post: bool is returned if yes or no
 *************************************************************/
bool ifMultiple(int num){
	if ((num % 7 == 0) || (num % 11 == 0) || (num % 13 == 0)){
		return true;
	}
	else{
		return false;
	}
}

/*************************************************************
 * Function: ifSumEvenOrOdd
 * Date Created: 2/13/23
 * Date Last Modified: 2/16/23
 * Description: checks if sum of digits is even or odd
 * Input parameters: int number
 * Returns: bool if sum is even or odd
 * Pre: num is passed in
 * Post: bool is returned if even or odd
 *************************************************************/
bool ifSumEvenOrOdd(int num){
	int sum = 0, m;
	while (num > 0){
		m = num % 10;
		sum+=m;
		num/=10;
	}
	if (sum % 2 == 0){
		return true;
	}
	else{
		return false;
	}
}

/*************************************************************
 * Function: ifPrime
 * Date Created: 2/13/23
 * Date Last Modified: 2/16/23
 * Description: checks if number is prime
 * Input parameters: int number
 * Returns: bool if prime or not
 * Pre: num is passed in
 * Post: bool is returned if true or false
 *************************************************************/
bool ifPrime(int num){
	if (num == 0 || num == 1){
		return false;
	}
	for (int i = 2; i <= num/2; i++){
		if (num % i == 0){
			return false;
		}
	}
	return true;
}

/*************************************************************
 * Function: runTask1
 * Date Created: 2/13/23
 * Date Last Modified: 2/16/23
 * Description: runs task 1
 * Input parameters: none
 * Returns: none
 * Pre: numbers text file is created
 * Post: completes task 1
 *************************************************************/
void runTask1(){
	ifstream numbers;
	numbers.open("../numbers.txt");
	if (!numbers.is_open()){
		cout << "unable to open file" << endl;
	}
	int num = 0;
	bool isMultiple, isSumEven, isPrime;
	bool * isMultiplePtr = &isMultiple;
	bool * isSumEvenPtr = &isSumEven;
	bool * isPrimePtr = &isPrime;

	while (!numbers.eof()){
		numbers >> num;
		if (numbers.good()){
			answerIntegerQuestions(num, isMultiplePtr, isSumEvenPtr, isPrimePtr);
			if (isMultiple){
				cout << num << " is a multiple of 7, 11, or 13" << endl;
			}
			else{
				cout << num << " isn't a multiple of 7, 11, or 13" << endl;
			}
			if (isSumEven){
				cout << "The sum of the digits is even" << endl;
			}
			else{
				cout << "The sum of the digits is odd" << endl;
			}
			if (isPrime){
				cout << num << " is a prime number" << endl;
			}
			else{
				cout << num << " isn't a prime number" << endl;
			}
		}
	}
	numbers.close();
}

////////////////////////////////////
// TASK 2
////////////////////////////////////

/*************************************************************
 * Function: findWinningLotteryTicket
 * Date Created: 2/13/23
 * Date Last Modified: 2/16/23
 * Description: checks if user's ticket matches winning numbers
 * Input parameters: user's input, array of winning tickets, and number of winning tickets
 * Returns: bool if wins or not
 * Pre: array is assigned
 * Post: bool is returned
 *************************************************************/
bool findWinningLotteryTicket(const int winningTicketNum, const int * playerNumbers, const int numPlayerNumbers) {
	for (int i = 0; i < numPlayerNumbers; i++) {
		if (*(playerNumbers + i) == winningTicketNum) {
			return true;
		}
	}
	return false;
}

/*************************************************************
 * Function: runTask2
 * Date Created: 2/13/23
 * Date Last Modified: 2/16/23
 * Description: runs task 2
 * Input parameters: none
 * Returns: none
 * Pre: none
 * Post: tells if user's input is a ticket winner
 *************************************************************/
void runTask2(){
    int lotteryNum;
	int playerNumbers[] = {13579, 26791, 26792, 33445, 55555, 62483, 77777, 79422, 85647, 93121};
	int numPlayerNumbers = 10;
	cout << "Enter your 5-digit lottery number this week: " << endl;
	cin >> lotteryNum;
	if (findWinningLotteryTicket(lotteryNum, playerNumbers, numPlayerNumbers)){
		cout << "Your ticket was a winner!" << endl;
	}
	else{
		cout << "Sorry, try again next week" << endl;
	}
}

////////////////////////////////////
// TASK 3
////////////////////////////////////

/*************************************************************
 * Function: createWordsArray
 * Date Created: 2/13/23
 * Date Last Modified: 2/16/23
 * Description: reads from the input words input file, assigns to array, and sorts
 * Input parameters: infile and number of words
 * Returns: array of words
 * Pre: infile is opened
 * Post: array contains sorted words
 *************************************************************/
string * createWordsArray(ifstream& infile, const int num){
	string newWord = "";
	string * words = new string[num];
	for (int i = 0; i < num; i++){
		infile >> newWord;
		if(infile.good()){
			words[i] = newWord;
		}
	}
	bubbleSortArrayGaddis(words, num);
	return words;
}

/*************************************************************
 * Function: generateSentence
 * Date Created: 2/13/23
 * Date Last Modified: 2/16/23
 * Description: generates a random sentence from arrays
 * Input parameters: pointer string, arrays, and array sizes
 * Returns: none
 * Pre: arrays are full of words
 * Post: sentence pointer is assigned random words
 *************************************************************/
void generateSentence(string * sentence, const string * articlesArr, const int articlesSize, const string * nounsArr, 
		const int nounsSize, const string * verbsArr, const int verbsSize, const string * prepsArr, const int prepsSize) {
	string article1 = articlesArr[rand() % (articlesSize)];
	string noun1 = nounsArr[rand() % (nounsSize)];
	string verb = verbsArr[rand() % (verbsSize)];
	string preposition = prepsArr[rand() % (prepsSize)];
	string article2 = articlesArr[rand() % (articlesSize)];
	string noun2 = nounsArr[rand() % (nounsSize)];
	article1[0] = toupper(article1[0]);
	*sentence = article1 + " " + noun1 + " " + verb + " " + preposition + " " + article2 + " " + noun2 + "!";
}

/*************************************************************
 * Function: runTask3
 * Date Created: 2/13/23
 * Date Last Modified: 2/16/23
 * Description: runs task 3
 * Input parameters: none
 * Returns: none
 * Pre: input words text is created
 * Post: task 3 is ran
 *************************************************************/
void runTask3(){
	ifstream words;
	words.open("../input_words.txt");
	if (!words.is_open()){
		cout << "unable to open file" << endl;
	}
	int numSentences = 0;
	words >> numSentences;
	
	string wordType, trashbin = "";
	int numWordsArticles, numWordsNouns, numWordsVerbs, numWordsPreposition;

	words >> wordType;
	words >> numWordsArticles;
	string * articlesArr = createWordsArray(words, numWordsArticles);
	
	
	words >> wordType;
	words >> numWordsNouns;
	string * nounsArr = createWordsArray(words, numWordsNouns);


	words >> wordType;
	words >> numWordsVerbs;
	string * verbsArr = createWordsArray(words, numWordsVerbs);
	

	words >> wordType;
	words >> numWordsPreposition;
	string * prepsArr = createWordsArray(words, numWordsPreposition);
	
	cout << "articles: ";
	for (int i = 0; i < numWordsArticles; i++){
		cout << prepsArr[i] << ", ";
	}
	cout << endl;
	
	cout << "nouns: ";
	for (int i = 0; i < numWordsNouns; i++){
		cout << nounsArr[i] << ", ";
	}
	cout << endl;

	cout << "verbs: ";
	for (int i = 0; i < numWordsVerbs; i++){
		cout << verbsArr[i] << ", ";
	}
	cout << endl;

	cout << "preposition: ";
	for (int i = 0; i < numWordsPreposition; i++){
		cout << prepsArr[i] << ", ";
	}
	cout << endl;

	string sentence = "";

	for (int i = 0; i < numSentences; i++){
		generateSentence(&sentence, articlesArr, numWordsArticles, nounsArr, numWordsNouns, verbsArr, numWordsVerbs, prepsArr, numWordsPreposition);
		cout << i + 1 << ". " << sentence << endl;
	}
	delete[] articlesArr;
    delete[] nounsArr;
    delete[] verbsArr;
    delete[] prepsArr;

	words.close();
}

/*************************************************************
 * Function: bubbleSortArrayGaddis
 * Date Created: 2/13/23
 * Date Last Modified: 2/16/23
 * Description: sorts an array with bubble sort
 * Input parameters: string array and int of size of array
 * Returns: none
 * Pre: array and size is declared
 * Post: array is sorted
 *************************************************************/
void bubbleSortArrayGaddis(string array[], int size) {
   int maxElement;
   int index;

   for (maxElement = size - 1; maxElement > 0; maxElement--) {
      for (index = 0; index < maxElement; index++) {
         if (array[index] > array[index + 1]) {
            swap(array[index], array[index + 1]);
         }
      }
   }
}

/*************************************************************
 * Function: swap
 * Date Created: 2/13/23
 * Date Last Modified: 2/16/23
 * Description: swaps the value of a and b
 * Input parameters: pointer a and b
 * Returns: none
 * Pre: a and b are initialized
 * Post: the values of a and b and swapped 
 *************************************************************/
void swap(int &a, int &b) {
   int temp = a;
   a = b;
   b = temp;
}