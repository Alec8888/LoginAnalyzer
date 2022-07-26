#include "loginanalyzer.h"
#include "Sorts.h"

#include <QApplication>
#include <iostream>
#include <sstream>
#include <fstream>
#include <chrono>
using namespace std::chrono;

typedef high_resolution_clock Clock;

void LoadDataSets(vector<string>& uN, vector<string>& uN2, vector<string>& pW, vector<string>& pW2)
{
    // load userNames ----------------------------------------------//
    fstream inFile;

    inFile.open("C:/Users/8888a/OneDrive/Documents/LoginAnalyzer/users.csv");
    //vector<string> userNames;
    if (inFile.is_open())
    {
        string line, user, firstRow;

        getline(inFile, firstRow);

        for (int i = 0; i < 500000; i++)
        {
            getline(inFile, line);

            stringstream ss(line);
            getline(ss, user, ',');

            uN.push_back(user);
            uN2.push_back(user);
        }
        inFile.close();
    }
    else
    {
        cout << "Error: user file did not open" << endl;
    }

    // debug print
//    cout << "Printing some user names ------------------------------------" << endl;
//    for (int i = 0; i < 50; i++)
//    {
//        cout << uN.at(i) << endl;
//    }


    // Load Passwords ---------------------------------------------------//
    inFile.open("C:/Users/8888a/OneDrive/Documents/LoginAnalyzer/passwords.csv");
    //vector<string> userNames;
    if (inFile.is_open())
    {
        string line, user, firstRow;

        getline(inFile, firstRow);

        for (int i = 0; i < 500000; i++)
        {
            getline(inFile, line);

            stringstream ss(line);
            getline(ss, user, ',');

            pW.push_back(user);
            pW2.push_back(user);
        }
        inFile.close();
    }
    else
    {
        cout << "Error: password file did not open" << endl;
    }

    // debug print
//    cout << "Printing some passwords ------------------------------------" << endl;
//    for (int i = 0; i < 10; i++)
//    {
//        cout << pW.at(i) << endl;
//    }
}

int main(int argc, char *argv[])
{

    vector<string> usrName1, usrName2, pwrd1, pwrd2;
    cout << "loading data...." << endl;
    LoadDataSets(usrName1, usrName2, pwrd1, pwrd2);


    cout << "Quick sort start......" << endl;
    auto t1 = Clock::now();
    usrName1 = QuickSort(usrName1, 0, usrName1.size() - 1);
    auto t2 = Clock::now();
    cout << "Quick sort end......" << endl;
    cout << "Quick sort duration: " << duration_cast<nanoseconds>(t2 - t1).count() << endl;

//    cout << "Merge sort start......" << endl;
//    t1 = Clock::now();
//    usrName1 = MergeSort(usrName2, 0, usrName2.size() - 1);
//    //sort(usrName1.begin(), usrName1.end());
//    t2 = Clock::now();
//    cout << "Merge sort end......" << endl;
//    cout << "Merge sort duration: " << duration_cast<nanoseconds>(t2 - t1).count() << endl;

    cout << "Tim sort start......" << endl;
    t1 = Clock::now();
    usrName2 = TimSort(usrName2);
    t2 = Clock::now();
    cout << "Tim sort end......" << endl;
    cout << "Tim sort duration: " << duration_cast<nanoseconds>(t2 - t1).count() << endl;

    cout << "sorting complete........" << endl;

    // debug print 1
    cout << "Sorted usrNames1: " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << usrName1.at(i) << endl;
    }

    // debug print 2
    cout << "Sorted usrNames2: " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << usrName2.at(i) << endl;
    }


    QApplication a(argc, argv);
    LoginAnalyzer w;
    w.show();
    return a.exec();
}
