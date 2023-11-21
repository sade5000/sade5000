#ifndef MENU_METHODS_H
#define MENU_METHODS_H
#include "game_lib.h"

class menu_methods
{
    public:
        menu_methods(SDL_Event event , bool flag , int ID);
        bool buttonSelectionMethod();




        virtual ~menu_methods();




        menu_methods(const menu_methods& other);
        menu_methods& operator=(const menu_methods& other);

    protected:

    private:

};

#endif // MENU_METHODS_H
