#include <QApplication>
#include <QIcon>
#include <QScreen>
#include <QStyle>
#include "CalculatorWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/Images/Icon.ico"));

    CalculatorWindow window;
    window.show();

    // Center window reliably after show
    QScreen *screen = QGuiApplication::primaryScreen();
    if (screen) {
        QRect screenGeom = screen->availableGeometry();
        QRect windowGeom = window.frameGeometry();
        windowGeom.moveCenter(screenGeom.center());
        window.move(windowGeom.topLeft());
    }

    return app.exec();
}
