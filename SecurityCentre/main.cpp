#include "Model/AgentDevice.h"
#include "Model/DetectorDevice.h"
#include "Model/ValidDataWrapper.h"
#include "Model/DeviceStorage.h"
#include "Model/fingerprintagent.h"
#include "Model/rfidagent.h"
#include "MainWindow.h"
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

    std::vector<long> validFingerprint = { 853484584L, 378473456L, 237945778L };
    auto fingerprintValidData = std::make_unique<ValidDataWrapper<long>>(validFingerprint);
    auto fingerprintAgent = std::make_shared<FingerprintAgent>(3, std::move(fingerprintValidData));

    auto smokeDetector = std::make_shared<DetectorDevice>(4);
    auto movementCorridorDetector = std::make_shared<DetectorDevice>(5);
    auto movementConferenceRoomDetector = std::make_shared<DetectorDevice>(6);

    auto deviceStorage = std::make_shared<DeviceStorage>();
    deviceStorage->addDevice(facialAgent);
    deviceStorage->addDevice(rfidAgent);
    deviceStorage->addDevice(fingerprintAgent);
    deviceStorage->addDevice(smokeDetector);
    deviceStorage->addDevice(movementCorridorDetector);
    deviceStorage->addDevice(movementConferenceRoomDetector);

    QApplication a(argc, argv);
    MainWindow w(deviceStorage);
    QObject::connect(facialAgent.get(), &AgentDevice::accessGranted, &w, &MainWindow::accessGranted);
    QObject::connect(rfidAgent.get(), &AgentDevice::accessGranted,  &w, &MainWindow::accessGranted);
    QObject::connect(fingerprintAgent.get(), &AgentDevice::accessGranted, &w, &MainWindow::accessGranted);

    QObject::connect(facialAgent.get(), &AgentDevice::accessDenied, &w, &MainWindow::accessDenied);
    QObject::connect(rfidAgent.get(), &AgentDevice::accessDenied, &w, &MainWindow::accessDenied);
    QObject::connect(fingerprintAgent.get(), &AgentDevice::accessDenied, &w, &MainWindow::accessDenied);

    QObject::connect(smokeDetector.get(), &DetectorDevice::signalRegistered, &w, &MainWindow::signalRegistered);
    QObject::connect(movementCorridorDetector.get(), &DetectorDevice::signalRegistered, &w, &MainWindow::signalRegistered);
    QObject::connect(movementConferenceRoomDetector.get(), &DetectorDevice::signalRegistered, &w, &MainWindow::signalRegistered);

    w.show();
    return a.exec();
}
