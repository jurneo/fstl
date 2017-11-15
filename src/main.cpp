#include <QApplication>

#include "app.h"
#include <QSurfaceFormat>
int main(int argc, char *argv[])
{
    App a(argc, argv);
    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setVersion(4, 3);
    format.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(format);

    return a.exec();
}
