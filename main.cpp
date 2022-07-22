#include "loginanalyzer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginAnalyzer w;
    w.show();
    return a.exec();
}
