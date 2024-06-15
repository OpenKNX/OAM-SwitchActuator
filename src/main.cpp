#include "Logic.h"
#include "SwitchActuator.h"
#include "FileTransferModule.h"
#include "OpenKNX.h"
#include "hardware.h"

void setup()
{
    const uint8_t firmwareRevision = 0;

    openknx.init(firmwareRevision);
    openknx.addModule(1, openknxLogic);
    openknx.addModule(2, openknxSwitchActuatorModule);
    openknx.addModule(3, openknxFileTransferModule);
    openknx.setup();
}

void loop()
{
    openknx.loop();
}