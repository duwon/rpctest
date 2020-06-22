#ifndef CONTROLVIEW_HPP
#define CONTROLVIEW_HPP

#include <gui_generated/control_screen/controlViewBase.hpp>
#include <gui/control_screen/controlPresenter.hpp>

class controlView : public controlViewBase
{
public:
    controlView();
    virtual ~controlView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // CONTROLVIEW_HPP
