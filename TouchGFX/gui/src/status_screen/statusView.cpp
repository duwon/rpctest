#include <gui/status_screen/statusView.hpp>
#include "BitmapDatabase.hpp"

statusView::statusView()
{

}

void statusView::setupScreen()
{
    statusViewBase::setupScreen();
}

void statusView::tearDownScreen()
{
    statusViewBase::tearDownScreen();
}

void statusView::updateLEDState(bool* bLEDStatus)
{
	touchgfx::Image * statusLED[27] = {	&statusLED01, &statusLED02, &statusLED03, &statusLED04, &statusLED05, &statusLED06, &statusLED07, &statusLED08, &statusLED09,\
									&statusLED10, &statusLED11, &statusLED12, &statusLED13, &statusLED14, &statusLED15, &statusLED16, &statusLED17, &statusLED18,\
									&statusLED19, &statusLED20, &statusLED21, &statusLED22, &statusLED23, &statusLED24, &statusLED25, &statusLED26, &statusLED27 };

	for (int i = 0; i < 27; i++)
	{
		if (bLEDStatus[i] == true)
		{
			statusLED[i]->setBitmap(touchgfx::Bitmap(BITMAP_B07_LED_G_ID));
		}
		else
		{
			statusLED[i]->setBitmap(touchgfx::Bitmap(BITMAP_B08_LED_R_ID));
		}
		statusLED[i]->invalidate();
	}
}
