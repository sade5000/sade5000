#ifndef COLLISION_MAIN_SCREEN_H
#define COLLISION_MAIN_SCREEN_H
#include "game_lib.h"

#define GOBUTTON 2


class collision_main_screen
{
    public:


        collision_main_screen(SDL_Event event,int recX , int recY , int recW , int recH);
        inline bool CollisionFlag(){return collision_flag;}
        inline int GetRedColChange(){return red_col_change;}
        inline int GetBlueColChange(){return blue_col_change;}
        inline bool GetWeHaveSelection(){return weHaveSelection;}


        virtual ~collision_main_screen();


    protected:

    private:
        collision_main_screen(const collision_main_screen& other){}
        void operator=(const collision_main_screen& other){}


        int Xpos_mouse = 0 ; int Ypos_mouse = 0 ;
        SDL_Rect col_src = { 0, 0 , 0 ,0};
        bool collision_flag = false;
        int red_col_change = 0; int blue_col_change = 0;
        int count_clicks = 0;
        bool weHaveSelection = false;
};

#endif // COLLISION_MAIN_SCREEN_H
