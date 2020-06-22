/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef FRONTENDAPPLICATIONBASE_HPP
#define FRONTENDAPPLICATIONBASE_HPP

#include <mvp/MVPApplication.hpp>
#include <gui/model/Model.hpp>

class FrontendHeap;

class FrontendApplicationBase : public touchgfx::MVPApplication
{
public:
    FrontendApplicationBase(Model& m, FrontendHeap& heap);
    virtual ~FrontendApplicationBase() { }

    // start
    void gotostartScreenNoTransition();

    void gotostartScreenSlideTransitionEast();

    // status
    void gotostatusScreenNoTransition();

protected:
    touchgfx::Callback<FrontendApplicationBase> transitionCallback;
    FrontendHeap& frontendHeap;
    Model& model;

    // start
    void gotostartScreenNoTransitionImpl();

    void gotostartScreenSlideTransitionEastImpl();

    // status
    void gotostatusScreenNoTransitionImpl();
};

#endif // FRONTENDAPPLICATIONBASE_HPP