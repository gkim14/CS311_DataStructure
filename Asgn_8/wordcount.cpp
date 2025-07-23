// wordcount.cpp 
// Grace Kim and Jonathan Brough
// 2024-12-04
//
// For CS 311 Fall 2024
// Program for Assignment 8 - Excercise A
// Takes wordcount_test.txt and counts words

#include <iostream>
using std::cin;
using std::cout;
#include <fstream>
using std::ifstream;
#include <string>
using std::string;
using std::getline;
#include <map>
using std::map;

// Main program
int main()
{
    string fileName;
    cout << "Enter in a file name: ";
    getline(cin, fileName); // Read Input

    // check for no name/ spaces or tabs in name
    if(fileName == "" || !(fileName.find(" ") == fileName.npos) 
                            || !(fileName.find("\t") == fileName.npos))
    {
        cout << "Invalid file name\n";
        return 1; 
    }

    ifstream file(fileName);
    //check if file was opened
    if(!file)
    {
        if(!(file.eof()))
            cout << "Failed to open file " << fileName << "\n";
        return 1;
    }

    map<string, int> m; 

    string word;
    // add words to map
    while(file >> word)
    {
        if(!file)
        {
            if(!file.eof())
            cout << "Error occurred while reading file\n";
            return 1;
        }
        if(m.find(word) == m.end())
            m[word] = 1;
        else
            m[word] += 1;
    }

    if(m.size()==0)
        cout << "File is empty\n";
    else
    {
        cout << "Number of distinct words: " << m.size() << "\n";
        //print every element in map
        for(const auto& [w, count]: m)
            cout << w << ": " << count << "\n";
    }
}
