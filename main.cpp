#include "loginanalyzer.h"
#include "Sorts.h"

#include <QApplication>
#include <iostream>
#include <sstream>
#include <fstream>
#include <time.h>

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
    cout << "Printing some user names ------------------------------------" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << uN.at(i) << endl;
    }


    // Load Passwords ---------------------------------------------------//
    //fstream inFile;

    inFile.open("C:/Users/8888a/OneDrive/Documents/LoginAnalyzer/passwords.csv");
    //vector<string> userNames;
    if (inFile.is_open())
    {
        string line, user, firstRow;

        getline(inFile, firstRow);

        for (int i = 0; i < 100; i++)
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
    cout << "Printing some passwords ------------------------------------" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << pW.at(i) << endl;
    }
}

int main(int argc, char *argv[])
{

    vector<string> usrName1, usrName2, pwrd1, pwrd2;
    cout << "loading data...." << endl;
    LoadDataSets(usrName1, usrName2, pwrd1, pwrd2);




    cout << "Quick sort start......" << endl;
    auto t1 = Clock::now();
    //usrName2 = QuickSort(usrName1, 0, usrName1.size() - 1);
    auto t2 = Clock::now();
    cout << "Quick sort end......" << endl;

    cout << "Merge sort start......" << endl;
    usrName1 = MergeSort(usrName1, 0, usrName1.size() - 1);
    cout << "Merge sort end......" << endl;

    cout << "sorting should be complete........" << endl;

    // debug print
    cout << "Sorted usrName1 -------------------------------------------------" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << usrName1.at(i) << endl;
    }


    QApplication a(argc, argv);
    LoginAnalyzer w;
    w.show();
    return a.exec();
}
