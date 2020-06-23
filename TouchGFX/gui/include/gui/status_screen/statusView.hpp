#ifndef STATUSVIEW_HPP
#define STATUSVIEW_HPP

#include <gui_generated/status_screen/statusViewBase.hpp>
#include <gui/status_screen/statusPresenter.hpp>

class statusView : public statusViewBase
{
public:
    statusView();
    virtual ~statusView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void saveLEDState(bool* bLEDStatus);
	void updateLEDState(bool* bLEDStatus);

protected:
    bool currLEDStatus[27];
};

#endif // STATUSVIEW_HPP
