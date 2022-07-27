#ifndef LOGINANALYZER_H
#define LOGINANALYZER_H

#include <QWidget>
#include <iostream>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class LoginAnalyzer; }
QT_END_NAMESPACE

class LoginAnalyzer : public QWidget
{
    Q_OBJECT

public:
    LoginAnalyzer(QWidget *parent = nullptr);
    ~LoginAnalyzer();

    string RankName(string userName, vector<string>& sortedNames);
    string RankPassword(string password, vector<string>& sortedPasswords);
    void LoadDataSets(vector<string>& uN, vector<string>& uN2, vector<string>& pW, vector<string>& pW2);

private slots:
    void on_pushButton_clicked();

private:
    Ui::LoginAnalyzer *ui;
};
#endif // LOGINANALYZER_H
