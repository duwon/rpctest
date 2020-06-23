#include <gui/control_screen/controlView.hpp>
#include <gui/control_screen/controlPresenter.hpp>

controlPresenter::controlPresenter(controlView& v)
    : view(v)
{

}

void controlPresenter::activate()
{

}

void controlPresenter::deactivate()
{

}

void controlPresenter::sendControlMessage(int btnNum)
{
    model->sendControlMessage(btnNum);
}


