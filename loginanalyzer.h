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
    int RankName(string userName);

private slots:
    void on_pushButton_clicked();

private:
    Ui::LoginAnalyzer *ui;
};
#endif // LOGINANALYZER_H
