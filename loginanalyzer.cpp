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

    QString usrRes = "very cool";
    QString pwrRes = "weak";

    QMessageBox::information(this, "Results", "Your user name is:  " + usrRes + '\n' + "Your password is: " + pwrRes);
}

