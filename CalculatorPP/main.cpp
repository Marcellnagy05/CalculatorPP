#include "CalculatorPP.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    CalculatorPP window;
    window.show();
    return app.exec();
}
