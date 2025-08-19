#include "detectordevice.h"
#include <iostream>
#include <string>

void DetectorDevice::registerSignal()
{
    time_t rawtime;
    time ( &rawtime );
    auto timeinfo = localtime ( &rawtime );

    std::string logMessage = "Movement detected!";
    auto log = asctime(timeinfo) + logMessage;
    addLog(log);

    // TODO
    std::cout << "QT Signal will be transmitted to show the action" << std::endl;
}
