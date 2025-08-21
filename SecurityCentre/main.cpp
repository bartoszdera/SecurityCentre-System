#include "Model/ValidDataWrapper.h"
#include "Model/DeviceStorage.h"
#include "Model/fingerprintagent.h"
#include "Model/rfidagent.h"
#include "mainwindow.h"
#include "Model/facialrecognitionagent.h"

#include <QApplication>
#include <memory>
#include <qobject.h>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
    std::vector<std::string> validFacial = { "twarz1", "twarz2", "twarz3" };
    auto facialValidData = std::make_unique<ValidDataWrapper<std::string>>(validFacial);
    auto facialAgent = std::make_shared<FacialRecognitionAgent>(1, std::move(facialValidData));

    std::vector<int> validRFID = { 23, 15, 1 };
    auto rfidValidData = std::make_unique<ValidDataWrapper<int>>(validRFID);
    auto rfidAgent = std::make_shared<RFIDAgent>(2, std::move(rfidValidData));

    std::vector<long> validFingerprint = { 853484584, 378473456, 237945778 };
    auto fingerprintValidData = std::make_unique<ValidDataWrapper<long>>(validFingerprint);
    auto fingerprintAgent = std::make_shared<FingerprintAgent>(3, std::move(fingerprintValidData));

    auto deviceStorage = std::make_shared<DeviceStorage>();
    deviceStorage->addDevice(facialAgent);
    deviceStorage->addDevice(rfidAgent);
    deviceStorage->addDevice(fingerprintAgent);

    QApplication a(argc, argv);
    MainWindow w(deviceStorage);
    w.show();
    return a.exec();
}
