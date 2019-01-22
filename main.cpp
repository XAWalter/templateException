#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <stdexcept>
#include <time.h>


using namespace std;


//find the min value in vector starting at the passed index
template <typename T>
unsigned min_index(const vector<T> &vals, unsigned index) {
	typename vector<T>::const_iterator itr = vals.begin();
	
	//make itr point to index
	while (itr < vals.end()) {
		if (*itr == vals.at(index)) {
			break;
		}
		itr++;
	}

	T min = *itr;
	unsigned minIndex = 0;

	//store min val in min
	while (itr < vals.end()) {
		if (min >= *itr) {
			min = *itr;
		}
		itr++;
	}

	itr = vals.begin();
	//make itr point to index
	while (itr < vals.end()) {
		if (*itr == vals.at(index)) {
			break;
		}
		itr++;
	}

	//find index of min
	while (itr < vals.end()) {
		if (*itr == min) {
			break;
		}
		minIndex++;
		itr++;
	}
	minIndex = minIndex + index;
	return minIndex;
}

//sort using selection sort
template<typename T>
void selection_sort(vector<T> &vals) {
	unsigned low = 0;
	unsigned high = vals.size() -1 ;
	unsigned minI;

	T temp;
	
	while (low != high) {
		minI = min_index(vals, low);
		temp = vals.at(low);
		vals.at(low) = vals.at(minI);
		vals.at(minI) = temp;
		low++;
	}
}

//get value in vector at passed index
template<typename T>
T getElement(vector<T> vals, unsigned index) {
		return vals.at(index);
}

//create a vector of chars with size of 0 to 26
vector<char> createCVector() {
	int vecSize = rand() % 26;
	char c = 'a';
	vector<char> vals;
	for (int i = 0; i < vecSize; i++)
	{
		vals.push_back(c);
		c++;
	}
	return vals;
}

//create a vector of ints with size of 0 to 26
vector<int> createIVector() {
	int vecSize = rand() % 26;
	vector<int> vals;
	for (int i = 0; i < vecSize; i++)
	{
		vals.push_back(rand()%90+1);
		cout << vals.at(i) << endl;
	}
	return vals;
}

//print whole vector
template<typename T>
void print(vector<T> &vals) {
	for (typename vector<T>::const_iterator itr = vals.begin(); itr < vals.end(); itr++) {
		cout << *itr << endl;
	}
}

int main() {

	try {
		srand(time(0));
		vector<int> vals = createIVector();
		int curInt;
		int index;
		int numOfRuns = 10;
		while (--numOfRuns >= 0) {
			cout << "Enter a number: " << endl;
			cin >> index;
			curInt = getElement(vals, index);
			cout << "Element located at " << index << ": is " << curInt << endl;
		}
		selection_sort(vals);

		cout << "Sorted Vector: " << endl;
		print(vals);
	}
	//stackoverflow
	catch (out_of_range& oor) {
		cout << "out of range exception occured: " << oor.what() << endl;
	}

	system("pause");
	return 0;
}