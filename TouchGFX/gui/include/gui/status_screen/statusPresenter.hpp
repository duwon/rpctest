#ifndef STATUSPRESENTER_HPP
#define STATUSPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class statusView;

class statusPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    statusPresenter(statusView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~statusPresenter() {};

	virtual void updateLEDState(bool* bLEDStatus);

private:
    statusPresenter();

    statusView& view;
};

#endif // STATUSPRESENTER_HPP
