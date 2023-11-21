#include "menu_methods.h"

menu_methods::menu_methods(SDL_Event event , bool flag , int ID)
{
    if(SDL_PollEvent(&event))
    {

        if(event.button.clicks == SDL_BUTTON_LEFT)
            if( ID == 1 && flag == 1)
            {
                std::cout<<"you have a selection"<<std::endl;
            }
            else;

    }


    //ctor
}
bool menu_methods::buttonSelectionMethod()
{





}



menu_methods::~menu_methods()
{
    //dtor
}

menu_methods::menu_methods(const menu_methods& other)
{
    //copy ctor
}

menu_methods& menu_methods::operator=(const menu_methods& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
