#ifndef CONTROLPRESENTER_HPP
#define CONTROLPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class controlView;

class controlPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    controlPresenter(controlView& v);

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

    virtual ~controlPresenter() {};

private:
    controlPresenter();

    controlView& view;
};

#endif // CONTROLPRESENTER_HPP
