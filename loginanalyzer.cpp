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
    cout << "button was clicked" << endl;

    QMessageBox::information(this, "Results", "UserName: " + ui->lineEdit->text() + '\n' + "Password: " + ui->lineEdit_2->text());
}

