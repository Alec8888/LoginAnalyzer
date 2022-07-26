#include "loginanalyzer.h"
#include "ui_loginanalyzer.h"
#include <QMessageBox>

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

    QString usrRes = "unranked"; // debug
    QString pwrRes = "unranked"; // debug

    string uN = ui->lineEdit->text().toStdString();
    string pW = ui->lineEdit_2->text().toStdString();

    if (RankName(uN) == 10)
    {
        usrRes = "very cool";
    }
    else
    {
        usrRes = "not cool";
    }



    QMessageBox::information(this, "Results", "Your user name is:  " + usrRes + '\n' + "Your password is: " + pwrRes);
}

int LoginAnalyzer::RankName(string userName)
{
    int rankRes = 10;
    if (userName.length() < 8)
    {
        rankRes -= 2;
    }

    return rankRes;
}
