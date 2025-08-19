#include "Model/devicestorage.h"
#include "mainwindow.h"
#include "Model/rfidagent.h"
#include "Model/fingerprintagent.h"
#include "Model/facialrecognitionagent.h"

#include <QApplication>
#include <memory>
#include <qobject.h>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
    std::vector<std::string> dummyFacials = {"face1", "face2", "face3"};
    auto facialAgent = std::make_shared<FacialRecognitionAgent<std::string>>(1, ValidData<std::string>(dummyFacials));
    DeviceStorage deviceStorage;
    deviceStorage.addDevice(facialAgent);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
