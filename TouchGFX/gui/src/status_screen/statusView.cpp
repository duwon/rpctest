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

bool status_img01 = false;
void statusView::btnEquip01_clicked()
{
	if (status_img01 == false)
	{
		statusLED01.setBitmap(touchgfx::Bitmap(BITMAP_B08_LED_R_ID));
		statusLED02.setBitmap(touchgfx::Bitmap(BITMAP_B08_LED_R_ID));
		statusLED03.setBitmap(touchgfx::Bitmap(BITMAP_B08_LED_R_ID));
		statusLED04.setBitmap(touchgfx::Bitmap(BITMAP_B08_LED_R_ID));
		statusLED05.setBitmap(touchgfx::Bitmap(BITMAP_B08_LED_R_ID));
		statusLED06.setBitmap(touchgfx::Bitmap(BITMAP_B08_LED_R_ID));
		statusLED07.setBitmap(touchgfx::Bitmap(BITMAP_B08_LED_R_ID));
		statusLED08.setBitmap(touchgfx::Bitmap(BITMAP_B08_LED_R_ID));
		statusLED09.setBitmap(touchgfx::Bitmap(BITMAP_B08_LED_R_ID));
		status_img01 = true;
	}
	else
	{
		statusLED01.setBitmap(touchgfx::Bitmap(BITMAP_B07_LED_G_ID));
		statusLED02.setBitmap(touchgfx::Bitmap(BITMAP_B07_LED_G_ID));
		statusLED03.setBitmap(touchgfx::Bitmap(BITMAP_B07_LED_G_ID));
		statusLED04.setBitmap(touchgfx::Bitmap(BITMAP_B07_LED_G_ID));
		statusLED05.setBitmap(touchgfx::Bitmap(BITMAP_B07_LED_G_ID));
		statusLED06.setBitmap(touchgfx::Bitmap(BITMAP_B07_LED_G_ID));
		statusLED07.setBitmap(touchgfx::Bitmap(BITMAP_B07_LED_G_ID));
		statusLED08.setBitmap(touchgfx::Bitmap(BITMAP_B07_LED_G_ID));
		statusLED09.setBitmap(touchgfx::Bitmap(BITMAP_B07_LED_G_ID));
		status_img01 = false;
	}
	
	statusLED01.invalidate();
	statusLED02.invalidate();
	statusLED03.invalidate();
	statusLED04.invalidate();
	statusLED05.invalidate();
	statusLED06.invalidate();
	statusLED07.invalidate();
	statusLED08.invalidate();
	statusLED09.invalidate();
	
	touchgfx::Image statusLED[27] = { statusLED01, statusLED02, statusLED03, statusLED04, statusLED05, statusLED06, statusLED07, statusLED08, statusLED09,
	statusLED10, statusLED11, statusLED12, statusLED13, statusLED14, statusLED15, statusLED16, statusLED17, statusLED18,
	statusLED19, statusLED20, statusLED21, statusLED22, statusLED23, statusLED24, statusLED25, statusLED26, statusLED27 };
	
	for (int i = 0; i < 27; i++)
	{
		if (status_img01 == true)
		{
			statusLED[i].setBitmap(touchgfx::Bitmap(BITMAP_B07_LED_G_ID));
		}
		else
		{
			statusLED[i].setBitmap(touchgfx::Bitmap(BITMAP_B08_LED_R_ID));
		}
		statusLED[i].invalidate();
	}
	
	if (status_img01 == false)
	{
		statusLED[10].setBitmap(touchgfx::Bitmap(BITMAP_B07_LED_G_ID));
		statusLED[11].setBitmap(touchgfx::Bitmap(BITMAP_B07_LED_G_ID));
		statusLED[12].setBitmap(touchgfx::Bitmap(BITMAP_B07_LED_G_ID));
		statusLED[13].setBitmap(touchgfx::Bitmap(BITMAP_B07_LED_G_ID));
		statusLED15.setBitmap(touchgfx::Bitmap(BITMAP_B07_LED_G_ID));
	}
	else
	{
		statusLED[10].setBitmap(touchgfx::Bitmap(BITMAP_B08_LED_R_ID));
		statusLED[11].setBitmap(touchgfx::Bitmap(BITMAP_B08_LED_R_ID));
		statusLED[12].setBitmap(touchgfx::Bitmap(BITMAP_B08_LED_R_ID));
		statusLED[13].setBitmap(touchgfx::Bitmap(BITMAP_B08_LED_R_ID));
		statusLED15.setBitmap(touchgfx::Bitmap(BITMAP_B08_LED_R_ID));
	}
	statusLED[10].invalidate();
	statusLED[11].invalidate();
	statusLED[12].invalidate();
	statusLED[13].invalidate();
	statusLED15.invalidate();
}

void statusView::updateLEDState(bool* bLEDStatus)
{
	touchgfx::Image led[27] = { statusLED01, statusLED02, statusLED03, statusLED04, statusLED05, statusLED06, statusLED07, statusLED08, statusLED09,\
		statusLED10, statusLED11, statusLED12, statusLED13, statusLED14, statusLED15, statusLED16, statusLED17, statusLED18,\
		statusLED19, statusLED20, statusLED21, statusLED22, statusLED23, statusLED24, statusLED25, statusLED26, statusLED27 };

	for (int i = 0; i < 27; i++)
	{
		if (bLEDStatus[i] == true)
		{
			led[i].setBitmap(touchgfx::Bitmap(BITMAP_B07_LED_G_ID));
		}
		else
		{
			led[i].setBitmap(touchgfx::Bitmap(BITMAP_B08_LED_R_ID));
		}
		led[i].invalidate();
	}
}
