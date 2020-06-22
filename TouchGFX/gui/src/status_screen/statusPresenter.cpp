#include <gui/status_screen/statusView.hpp>
#include <gui/status_screen/statusPresenter.hpp>

statusPresenter::statusPresenter(statusView& v)
    : view(v)
{

}

void statusPresenter::activate()
{

}

void statusPresenter::deactivate()
{

}

void statusPresenter::updateLEDState(bool* bLEDStatus)
{
	view.updateLEDState(bLEDStatus);
}
