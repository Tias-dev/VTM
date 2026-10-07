#include <QApplication>
#include <QIcon>

#include "configuration.h"
#include "mainwindow.h"
#include "vmttheme.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    QApplication::setApplicationName("Virtual Turing Machine");
    QApplication::setOrganizationDomain("mai.ru");
    Q_INIT_RESOURCE(resources);

    Configuration::GetInstance().Init(&a);
    if (Configuration::GetInstance().IsDarkTheme()) {
        VmtTheme::setDarkMode(true, &a);
    } else {
        VmtTheme::applyApplication(&a);
    }

    a.setWindowIcon(QIcon(":/images/app.icns"));
    MainWindow w;
    w.show();

    return a.exec();
}
