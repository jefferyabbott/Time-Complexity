#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include "sort.h"

using namespace std;


/*
    Sort
    constructor that reads in values from three sample files of
    random doubles, unsorted, sorted and sorted in reverse order.
 */
Sort::Sort() {
	readFile("sampleData.txt", data);
    readFile("sampleDataSorted.txt", sortedData);
    readFile("sampleDataSortedReverse.txt", reverseSortedData);
}



/*
    readFile
    reads doubles from file and adds them to a vector
    fileName: the file to read from
    vect: reference to vector where values are inserted
 */
void Sort::readFile(string fileName, vector<double> &vect) {
	ifstream fileReader(fileName);
	if (fileReader.is_open()) {
		double num;
		while (fileReader >> num) {
			vect.push_back(num);
		}
        fileReader.close();
	} else {
		cout << "ERROR reading file " << fileName << endl;
	}
	
}



// selectionSort - Nicolas Chun
vector<double> Sort::selectionSort(vector<double> s1) {
    double smallestInd = 0.0, tempValue = 0.0;
    for (int outerLoop = 0; outerLoop < s1.size(); outerLoop++) {
        smallestInd = outerLoop;
        for (int innerLoop = outerLoop + 1; innerLoop < s1.size(); innerLoop++) {
            if (s1.at(innerLoop) < s1.at(smallestInd)) {
                tempValue = s1.at(smallestInd);
                s1.at(smallestInd) = s1.at(innerLoop);
                s1.at(innerLoop) = tempValue;
            }
        }
    }
    return s1;
}



// insertionSort - Hung Nguyen
vector<double> Sort::insertionSort(vector<double> vect) {
	long size = vect.size();
	double temp;
	int i, j;
	for (i = 1; i < size; ++i) {
   	 temp = vect[i];
    	 for (j = i; j>0 && vect[j - 1] > temp; j--) {
        	vect[j] = vect[j-1];
   	 }
    	vect[j] = temp;
	}
    return vect;
}



// shellSort - Jeffery Abbott
/*  sorts vector by breaking it into smaller list by gap size.
    gap size of 1000 is used
    vect: copy of the vector to sort
*/
vector<double> Sort::shellSort(vector<double> vect) {
    long size = vect.size();
    for (int gap = 1000; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i += 1) {
            double temp = vect[i];
            int j;
            for (j = i; j >= gap && vect[j - gap] > temp; j -= gap) {
                vect[j] = vect[j - gap];
            }
            vect[j] = temp;
        }
    }
    return vect;
}



// heapSort - Huu Hau Nguyen
vector<double> Sort::heapSort(vector<double>& vect) {
    long n = vect.size();
    double temp;
    // Build heap (rearrange array)
    for (long i = n / 2 - 1; i >= 0; i--)
        heapify(vect, n, i);

    // One by one extract an element from heap
    for (long i = n - 1; i > 0; i--) {
        // Move current root to end
        temp=vect[0];
        vect[0]=vect[i];
        vect[i]=temp;
        // call max heapify on the reduced heap
        heapify(vect, i, 0);
    }
    return vect;
}



// heapify (heapSort helper function) - Huu Hau Nguyen
void Sort::heapify(vector<double>& vect, long n, long i) {
    double temp;
    long largest = i;
    long l = (2*i) + 1;
    long r = (2*i) + 2;

    if (l < n && vect[l] > vect[largest])
        largest = l;

    if (r < n && vect[r] > vect[largest])
        largest = r;

    if (largest != i) {
        temp = vect[i];
        vect[i]=vect[largest];
        vect[largest]=temp;
        heapify(vect, n, largest);
    }
}



// quickSort - Michael Ekman
// Performs quicksort iteratively using stacks
vector<double> Sort::quickSort(vector<double> vect) {
    stack<int> stack;
    stack.push(0);
    stack.push(int(vect.size() - 1));

    while (!stack.empty()) {
        int right = stack.top();
        stack.pop();
        int left = stack.top();
        stack.pop();

        int pivot = partition(vect, left, right);
        if (pivot - 1 > left) {
            stack.push(left);
            stack.push(pivot - 1);
        }

        if (pivot + 1 < right) {
            stack.push(pivot + 1);
            stack.push(right);
        }
    }
    return vect;
}



// partition (quickSort helper function) - Michael Ekman
/*  Selects median of left, right, and middle elements within the vector.
    Then puts the median in its sorted location in the vector
 */
int Sort::partition(vector<double>& v, int left, int right) {
    double pivot;
    double mid = v[(left + right) / 2];

    //find median
    if ((v[left] < v[right] && v[left] > mid) || (v[left] > v[right] && v[left] < mid)) {
        pivot = v[left];
        swapForQuickSort(v, left, right);
    } else if ((v[right] > v[left] && v[right] < mid) || (v[right] < v[left] && v[right] > mid)) {
        pivot = v[right];
    } else {
        pivot = mid;
        swapForQuickSort(v, (left + right) / 2, right);
    }
    //checks from left for numbers smaller than pivot
    //works on basis that numbers before found num are bigger
    int count = left;
    for (int i = left; i < right; i++) {
        if (v[i] <= pivot) {
            swapForQuickSort(v, count, i);
            count++;
        }
    }
    swapForQuickSort(v, count, right);
    return count;
}



// swapForQuickSort (quickSort helper function) - Michael Ekman
// Swaps two elements in referenced vector
void Sort::swapForQuickSort(vector<double> &vect, double ind1, double ind2) {
    double temp = vect[ind1];
    vect[ind1] = vect[ind2];
    vect[ind2] = temp;
}



// sortUsingStdSort - Jeffery Abbott
vector<double> Sort::sortUsingStdSort(vector<double> vect) {
    sort(vect.begin(), vect.end());
    return vect;
}



// print - Michael Ekman
void Sort::print(vector<double> vect) {
	for (int i = 0; i < vect.size(); i++) {
		if (i + 1 != vect.size()) {
			cout << vect[i] << ", ";
		} else {
			cout << vect[i] << endl;
		}
	}
}
