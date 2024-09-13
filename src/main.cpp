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
    openknx.addModule(1, openknxLogic);
    openknx.addModule(4, openknxGPIOModule); // before any using modules !
    openknx.addModule(2, openknxSwitchActuatorModule);
    openknx.addModule(3, openknxFileTransferModule);
    
    openknx.setup();
    pinMode(OKNXHW_REG1_APP_SA_4xSELV_12VADC, INPUT);   // Debug
}

uint32_t last_u_meas = 0;
bool toggle = 1;
void loop()
{
    openknx.loop();
    if(delayCheckMillis(last_u_meas, 1000))
    {
        last_u_meas = millis();
        int u_meas = analogRead(OKNXHW_REG1_APP_SA_4xSELV_12VADC);
        //logDebug("", "Analog: %f V", u_meas*4.0*3.3/1024);

        //openknxSwitchActuatorModule.doSwitchChannel(0, toggle);
        //openknxSwitchActuatorModule.doSwitchChannel(1, toggle);
        //openknxSwitchActuatorModule.doSwitchChannel(2, toggle);
        //openknxSwitchActuatorModule.doSwitchChannel(3, toggle);
        toggle = !toggle;
    }
}