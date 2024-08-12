#include "Logic.h"
#include "SwitchActuatorModule.h"
#include "GPIOModule.h"
#include "FileTransferModule.h"
#include "OpenKNX.h"
#include "hardware.h"

void setup()
{
    const uint8_t firmwareRevision = 0;

    openknx.init(firmwareRevision);
    //openknx.addModule(1, openknxLogic);
    openknx.addModule(4, openknxGPIOModule); // before any using modules !
    //openknx.addModule(2, openknxSwitchActuatorModule);
    //openknx.addModule(3, openknxFileTransferModule);
    
    openknx.setup();
    openknxGPIOModule.pinMode(24, OUTPUT);
}

void loop()
{
    openknx.loop();
    openknxGPIOModule.digitalWrite(24, HIGH);
    delay(200);
    openknxGPIOModule.digitalWrite(24, LOW);
    delay(1000);
}