#include <gui/start_screen/startView.hpp>
#include "user.h"

startView::startView()
{
    
}

void startView::setupScreen()
{
    startViewBase::setupScreen();
    char* firmwareVersion = FIRMWARE_VSERSION;
    Unicode::strncpy(tbFirmwareVersionBuffer, firmwareVersion, sizeof(firmwareVersion));
}

void startView::tearDownScreen()
{
    startViewBase::tearDownScreen();
}
