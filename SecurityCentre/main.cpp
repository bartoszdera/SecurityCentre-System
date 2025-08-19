#include "Model/ValidDataWrapper.h"
#include "Model/DeviceStorage.h"
#include "mainwindow.h"
#include "Model/facialrecognitionagent.h"

#include <QApplication>
#include <memory>
#include <qobject.h>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
    std::vector<std::string> validFacial = { "Alice", "Bob", "Charlie" };
    auto facialValidData = std::make_unique<ValidDataWrapper<std::string>>(validFacial);
    auto facialAgent = std::make_shared<FacialRecognitionAgent>(1, std::move(facialValidData));

    auto deviceStorage = std::make_shared<DeviceStorage>();
    deviceStorage->addDevice(facialAgent);

    QApplication a(argc, argv);
    MainWindow w(deviceStorage);
    w.show();
    return a.exec();
}
