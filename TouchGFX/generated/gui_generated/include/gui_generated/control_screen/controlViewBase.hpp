/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef CONTROLVIEWBASE_HPP
#define CONTROLVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/control_screen/controlPresenter.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/Button.hpp>

class controlViewBase : public touchgfx::View<controlPresenter>
{
public:
    controlViewBase();
    virtual ~controlViewBase() {}
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Image bg;
    touchgfx::Button btnSelStatus;
    touchgfx::Button btnSelControl;

private:

};

#endif // CONTROLVIEWBASE_HPP
