//WORD COUNT
/*Develop a program that counts the number of words in a given text file. Prompt the user to enter the file name and display
 the total word count.*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// Function to count words in a string
int countWords(const string &text) {
    stringstream ss(text);
    string word;
    int count = 0;
    
    while (ss >> word) {
        count++;
    }
    
    return count;
}

int main() {
    string filename;
    cout << "Enter the name of the text file: ";
    cin >> filename;
    
    ifstream inputFile(filename);
    
    if (!inputFile) {
        cerr << "Error: Unable to open the file " << filename << endl;
        return 1;
    }
    
    string line;
    int totalWordCount = 0;
    
    while (getline(inputFile, line)) {
        totalWordCount += countWords(line);
    }
    
    inputFile.close();
    
    cout << "Total word count in the file is: " << totalWordCount << endl;
    
    return 0;
}
