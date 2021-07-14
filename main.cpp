/*

    Compare time complexity for various sorting algorithms
    June 18, 2020
*/

#include <iostream>
#include <chrono>
#include <map>
#include <algorithm>
#include <fstream>
#include "sort.h"


/*
    validateResult
    tests that vector is sorted and has 10,000 elements
    testCase: the returned vector to test
 */
bool validateResult(vector<double> testCase) {
    return is_sorted(testCase.begin(), testCase.end()) && testCase.size() == 10000;
}

int main() {
    
    map<string, double> results;
    Sort test;

    vector<double> sortedResult;
    string testName;
    auto startTime = chrono::high_resolution_clock::now();
    auto stopTime = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> millis;
    
    
    
    
    /**************************************************QUICK SORT ************************************************/
    
    // run tests and get times for quick sort
    testName = "quick sort, unsorted";
    startTime = chrono::high_resolution_clock::now();
    sortedResult = test.quickSort(test.data);
    stopTime = chrono::high_resolution_clock::now();
    millis = stopTime - startTime;
    if (validateResult(sortedResult)) {
        results.insert({ testName, (double)millis.count() });
    }
    else {
        results.insert({ testName, -1.0 });
    }
    
    
    testName = "quick sort, sorted";
    startTime = chrono::high_resolution_clock::now();
    sortedResult = test.quickSort(test.sortedData);
    stopTime = chrono::high_resolution_clock::now();
    millis = stopTime - startTime;
    if (validateResult(sortedResult)) {
        results.insert({ testName, (double)millis.count() });
    }
    else {
        results.insert({ testName, -1.0 });
    }
    
    
    testName = "quick sort, reverse sorted";
    startTime = chrono::high_resolution_clock::now();
    sortedResult = test.quickSort(test.reverseSortedData);
    stopTime = chrono::high_resolution_clock::now();
    millis = stopTime - startTime;
    if (validateResult(sortedResult)) {
        results.insert({ testName, (double)millis.count() });
    }
    else {
        results.insert({ testName, -1.0 });
    }
   
    
   
    
    /************************************************** SELECTON SORT ************************************************/
    
    // run tests and get times for selection sort
    testName = "selection sort, unsorted";
    startTime = chrono::high_resolution_clock::now();
    sortedResult = test.selectionSort(test.data);
    stopTime = chrono::high_resolution_clock::now();
    millis = stopTime - startTime;
    if (validateResult(sortedResult)) {
        results.insert({ testName, (double)millis.count() });
    }
    else {
        results.insert({ testName, -1.0 });
    }
    
    
    testName = "selection sort, sorted";
    startTime = chrono::high_resolution_clock::now();
    sortedResult = test.selectionSort(test.sortedData);
    stopTime = chrono::high_resolution_clock::now();
    millis = stopTime - startTime;
    if (validateResult(sortedResult)) {
        results.insert({ testName, (double)millis.count() });
    }
    else {
        results.insert({ testName, -1.0 });
    }
    
    
    testName = "selection sort, reverse sorted";
    startTime = chrono::high_resolution_clock::now();
    sortedResult = test.selectionSort(test.reverseSortedData);
    stopTime = chrono::high_resolution_clock::now();
    millis = stopTime - startTime;
    if (validateResult(sortedResult)) {
        results.insert({ testName, (double)millis.count() });
    }
    else {
        results.insert({ testName, -1.0 });
    }
    
    
    
    
    /************************************************** INSERTION SORT ************************************************/
    
    // run tests and get times for insertion sort
    testName = "insertion sort, unsorted";
    startTime = chrono::high_resolution_clock::now();
    sortedResult = test.insertionSort(test.data);
    stopTime = chrono::high_resolution_clock::now();
    millis = stopTime - startTime;
    if (validateResult(sortedResult)) {
        results.insert({ testName, (double)millis.count() });
    }
    else {
        results.insert({ testName, -1.0 });
    }
    
    
    testName = "insertion sort, sorted";
    startTime = chrono::high_resolution_clock::now();
    sortedResult = test.insertionSort(test.sortedData);
    stopTime = chrono::high_resolution_clock::now();
    millis = stopTime - startTime;
    if (validateResult(sortedResult)) {
        results.insert({ testName, (double)millis.count() });
    }
    else {
        results.insert({ testName, -1.0 });
    }
    
    
    testName = "insertion sort, reverse sorted";
    startTime = chrono::high_resolution_clock::now();
    sortedResult = test.insertionSort(test.reverseSortedData);
    stopTime = chrono::high_resolution_clock::now();
    millis = stopTime - startTime;
    if (validateResult(sortedResult)) {
        results.insert({ testName, (double)millis.count() });
    }
    else {
        results.insert({ testName, -1.0 });
    }
    
    
    
    
    /************************************************** SHELL SORT ************************************************/
    
    // run tests and get times for shell sort
    testName = "shell sort, unsorted";
    startTime = chrono::high_resolution_clock::now();
    sortedResult = test.shellSort(test.data);
    stopTime = chrono::high_resolution_clock::now();
    millis = stopTime - startTime;
    if (validateResult(sortedResult)) {
        results.insert({ testName, (double)millis.count() });
    }
    else {
        results.insert({ testName, -1.0 });
    }
    
    
    testName = "shell sort, sorted";
    startTime = chrono::high_resolution_clock::now();
    sortedResult = test.shellSort(test.sortedData);
    stopTime = chrono::high_resolution_clock::now();
    millis = stopTime - startTime;
    if (validateResult(sortedResult)) {
        results.insert({ testName, (double)millis.count() });
    }
    else {
        results.insert({ testName, -1.0 });
    }
    
    
    testName = "shell sort, reverse sorted";
    startTime = chrono::high_resolution_clock::now();
    sortedResult = test.shellSort(test.reverseSortedData);
    stopTime = chrono::high_resolution_clock::now();
    millis = stopTime - startTime;
    if (validateResult(sortedResult)) {
        results.insert({ testName, (double)millis.count() });
    }
    else {
        results.insert({ testName, -1.0 });
    }
    
    
    
    
    /************************************************** HEAP SORT ************************************************/
    
    // run tests and get times for heap sort
    testName = "heap sort, unsorted";
    startTime = chrono::high_resolution_clock::now();
    sortedResult = test.heapSort(test.data);
    stopTime = chrono::high_resolution_clock::now();
    millis = stopTime - startTime;
    if (validateResult(sortedResult)) {
        results.insert({ testName, (double)millis.count() });
    }
    else {
        results.insert({ testName, -1.0 });
    }
    
    
    testName = "heap sort, sorted";
    startTime = chrono::high_resolution_clock::now();
    sortedResult = test.heapSort(test.sortedData);
    stopTime = chrono::high_resolution_clock::now();
    millis = stopTime - startTime;
    if (validateResult(sortedResult)) {
        results.insert({ testName, (double)millis.count() });
    }
    else {
        results.insert({ testName, -1.0 });
    }
    
    
    testName = "heap sort, reverse sorted";
    startTime = chrono::high_resolution_clock::now();
    sortedResult = test.heapSort(test.reverseSortedData);
    stopTime = chrono::high_resolution_clock::now();
    millis = stopTime - startTime;
    if (validateResult(sortedResult)) {
        results.insert({ testName, (double)millis.count() });
    }
    else {
        results.insert({ testName, -1.0 });
    }

    

    
    /************************************************** STD SORT ************************************************/
    
    // run tests and get times for std sort
    testName = "std::sort, unsorted";
    startTime = chrono::high_resolution_clock::now();
    sortedResult = test.sortUsingStdSort(test.data);
    stopTime = chrono::high_resolution_clock::now();
    millis = stopTime - startTime;
    if (validateResult(sortedResult)) {
        results.insert({ testName, (double)millis.count() });
    }
    else {
        results.insert({ testName, -1.0 });
    }
    
    
    testName = "std::sort, sorted";
    startTime = chrono::high_resolution_clock::now();
    sortedResult = test.sortUsingStdSort(test.sortedData);
    stopTime = chrono::high_resolution_clock::now();
    millis = stopTime - startTime;
    if (validateResult(sortedResult)) {
        results.insert({ testName, (double)millis.count() });
    }
    else {
        results.insert({ testName, -1.0 });
    }
    
    
    testName = "std::sort, reverse sorted";
    startTime = chrono::high_resolution_clock::now();
    sortedResult = test.sortUsingStdSort(test.reverseSortedData);
    stopTime = chrono::high_resolution_clock::now();
    millis = stopTime - startTime;
    if (validateResult(sortedResult)) {
        results.insert({ testName, (double)millis.count() });
    }
    else {
        results.insert({ testName, -1.0 });
    }
    


    
    // display test results
    bool hasErrors = false;
    const string DIVIDER = "---------------------------------------------------------\n";
    cout << setw(40) << left << "ALGORITHM" << setw(15) << "TIME" << endl;
    cout << DIVIDER;
    for (auto testItem : results) {
        if (testItem.second == -1.0) {
            hasErrors = true;
        }
        else {
            cout << setw(40) << left << testItem.first << setw(15) << to_string(testItem.second) + " ms" << endl;
        }
    }
    
    
    cout << DIVIDER;
    
    // if hasErrors, display warning; otherwise, generate CSV of data
    if (hasErrors) {
        cout << DIVIDER;
        cout << "WARNING, THE FOLLOWING TEST(S) FAILED:" << endl;
        for (auto testItem : results) {
            if (testItem.second == -1.0) {
                cout << "\t" << testItem.first << endl;
            }
        }
    }
    else {
        cout << "Generating CSV file" << endl;
        
        fstream data;
        data.open("results.csv", ios::out);
        if (data.is_open()) {
            data << "ALGORITHM,SORT STATUS,TIME" << endl;
            for (auto testItem : results) {
                data << testItem.first << "," << testItem.second << endl;
            }
            
            data.close();
        }
        else {
            cout << "Error writing results.csv file" << endl;
        }
    }
    
    cout << endl;
    return 0;
}



/*
        SAMPLE OUTPUT:
 
        ALGORITHM                               TIME
        ---------------------------------------------------------
        heap sort, reverse sorted               2.682714 ms
        heap sort, sorted                       2.831398 ms
        heap sort, unsorted                     3.149134 ms
        insertion sort, reverse sorted          301.917421 ms
        insertion sort, sorted                  0.166026 ms
        insertion sort, unsorted                149.368971 ms
        quick sort, reverse sorted              3.620843 ms
        quick sort, sorted                      2.568633 ms
        quick sort, unsorted                    3.274358 ms
        selection sort, reverse sorted          1193.584412 ms
        selection sort, sorted                  452.426576 ms
        selection sort, unsorted                988.154525 ms
        shell sort, reverse sorted              1.473298 ms
        shell sort, sorted                      0.797505 ms
        shell sort, unsorted                    3.164790 ms
        std::sort, reverse sorted               0.102912 ms
        std::sort, sorted                       0.100847 ms
        std::sort, unsorted                     0.110296 ms
        ---------------------------------------------------------
        Generating CSV file

        Program ended with exit code: 0
 */
