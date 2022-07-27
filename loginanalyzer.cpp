#include "loginanalyzer.h"
#include "ui_loginanalyzer.h"
#include "Sorts.h"
#include <QMessageBox>
#include <iostream>
#include <sstream>
#include <fstream>
#include <chrono>
#include <string>

using namespace std;
using namespace std::chrono;

typedef high_resolution_clock Clock;

LoginAnalyzer::LoginAnalyzer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginAnalyzer)
{
    ui->setupUi(this);
}

LoginAnalyzer::~LoginAnalyzer()
{
    delete ui;
}

void LoginAnalyzer::on_pushButton_clicked()
{
    // load data =================================================//
    vector<string> usrName1, usrName2, pwrd1, pwrd2;
    cout << "loading data..." << endl;
    LoadDataSets(usrName1, usrName2, pwrd1, pwrd2);

    cout << "Quick sort start..." << endl;
    auto t1 = Clock::now();
    usrName1 = QuickSort(usrName1, 0, usrName1.size() - 1);
    auto t2 = Clock::now();
    cout << "Quick sort end..." << endl;
    cout << "Quick sort duration: " << duration_cast<nanoseconds>(t2 - t1).count() << endl;

    cout << "Tim sort start..." << endl;
    t1 = Clock::now();
    usrName2 = TimSort(usrName2);
    t2 = Clock::now();
    cout << "Tim sort end..." << endl;
    cout << "Tim sort duration: " << duration_cast<nanoseconds>(t2 - t1).count() << endl;

    cout << "sorting complete..." << endl;
    cout << "Start ranking..." << endl;

    // Rank userID and password ================================== //

    // input from user
    string userNameInput = ui->lineEdit->text().toStdString();
    string passwordInput = ui->lineEdit_2->text().toStdString();

    // strings that are displayed as results
    QString usrRes = "unranked";
    QString pwrRes = "unranked";

    // userID ranking
    usrRes = QString::fromStdString(RankName(userNameInput, usrName1));

    // password ranking
    pwrRes = QString::fromStdString(RankPassword(passwordInput, pwrd1));

    cout << "Ranking complete..." << endl;

    // display results ================================================ //
    cout << "Displaying results..." << endl;
    QMessageBox::information(this, "Results", "Your user name is:  " + usrRes + '\n' + "Your password is: " + pwrRes);
}

string RankValtoText(int rankVal)
{
    string textResult;

    if (rankVal == 10)
    {
        textResult = "cool10";
    }
    else if (rankVal == 9)
    {
        textResult = "cool9";
    }
    else if (rankVal == 8)
    {
        textResult = "cool8";
    }
    else if (rankVal == 7)
    {
        textResult = "cool7";
    }
    else if (rankVal == 6)
    {
        textResult = "cool6";
    }
    else if (rankVal == 5)
    {
        textResult = "cool5";
    }
    else if (rankVal == 4)
    {
        textResult = "cool4";
    }
    else if (rankVal == 3)
    {
        textResult = "cool3";
    }
    else if (rankVal == 2)
    {
        textResult = "cool2";
    }
    else if (rankVal == 1)
    {
        textResult = "cool1";
    }
    else if (rankVal < 1)
    {
        textResult = "totally no cool";
    }

    return textResult;
}

string LoginAnalyzer::RankName(string userName, vector<string>& sortedNames)
{
    int rankRes = 10; // starts at max rank

    // check length
    if (userName.length() > 10)
    {
        rankRes--;
    }

    // check if unique
    if (binary_search(sortedNames.begin(), sortedNames.end(), userName))
    {
        rankRes -= 5;
    }

    return RankValtoText(rankRes);
}

string LoginAnalyzer::RankPassword(string password, vector<string>& sortedPasswords) {

    int passwordRank = 0;
    bool wasFound = false;
    bool isLong = false;
    bool hasLower = false;
    bool hasUpper = false;
    bool hasNumber = false;
    bool hasSpecialChar = false;

    // check if password found in breached data
    if (binary_search(sortedPasswords.begin(), sortedPasswords.end(), password)) {
        wasFound = true;
    }
    else {
        passwordRank++;
    }

    // check if password is at least 8 characters
    if (password.size() >= 8) {
        isLong = true;
        passwordRank++;
    }

    for (int i = 0; i < password.size(); i++) {
        // check if password has lowercase letter
        if (password.at(i) >= 'a' && password.at(i) <= 'z') {
            if (hasLower == false) {
                // lowercase letter found
                hasLower = true;
                passwordRank++;
            }
        }

        // check if password has uppercase letter
        if (password.at(i) >= 'A' && password.at(i) <= 'Z') {
            if (hasUpper == false) {
                // uppercase letter found
                hasUpper = true;
                passwordRank++;
            }
        }

        // check if password has number
        if (password.at(i) >= '0' && password.at(i) <= '9') {
            if (hasNumber == false) {
                // number found
                hasNumber = true;
                passwordRank++;
            }
        }

        // check if password has special character
        if ((password.at(i) >= ' ' && password.at(i) <= '/')
            || (password.at(i) >= ':' && password.at(i) <= '@')
            || (password.at(i) >= '[' && password.at(i) <= '`')
            || (password.at(i) >= '{' && password.at(i) <= '~')) {
            if (hasSpecialChar == false) {
                // special character found
                hasSpecialChar = true;
                passwordRank++;
            }
        }
    }

    if (passwordRank == 6) {
        return "strong";
    }
    else {
        return "weak";
    }
}


void LoginAnalyzer::LoadDataSets(vector<string>& uN, vector<string>& uN2, vector<string>& pW, vector<string>& pW2)
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
