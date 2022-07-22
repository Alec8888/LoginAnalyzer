#include "loginanalyzer.h"

#include <QApplication>
#include <iostream>
#include <sstream>
#include <fstream>

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
    for (int i = 0; i < 100; i++)
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
    cout << "Printing some passwords ------------------------------------" << endl;
    for (int i = 0; i < 100; i++)
    {
        cout << pW.at(i) << endl;
    }



}

int main(int argc, char *argv[])
{

    vector<string> usrName1, usrName2, pwrd1, pwrd2;
    LoadDataSets(usrName1, usrName2, pwrd1, pwrd2);


    QApplication a(argc, argv);
    LoginAnalyzer w;
    w.show();
    return a.exec();
}
