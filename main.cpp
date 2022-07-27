#include "loginanalyzer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    cout << "Program start..." << endl;
    QApplication a(argc, argv);
    LoginAnalyzer w;
    w.show();
    return a.exec();
}
