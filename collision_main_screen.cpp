#include "collision_main_screen.h"

collision_main_screen::collision_main_screen(SDL_Event event , int recX , int recY , int recW , int recH )
{

    if(event.type == SDL_MOUSEMOTION | event.button.clicks == SDL_BUTTON_LEFT)
    {

            count_clicks = 1;





        SDL_GetMouseState(&Xpos_mouse , &Ypos_mouse);\
        col_src.x = recX;
        col_src.y = recY;
        col_src.w = recW;
        col_src.h = recH;

        int l1 = Xpos_mouse -1;
        int r1 = Xpos_mouse +1;
        int t1 = Ypos_mouse -1;
        int b1 = Ypos_mouse +1;

        int l2 = col_src.x;
        int r2 = col_src.x + col_src.w;
        int t2 = col_src.y;
        int b2 = col_src.y + col_src.h;

        if(!(l1 > r2 || l2 > r1 || t1 > b2 || t2 > b1))
        {
            //std::cout << "collision detected"<<std::endl;

            collision_flag = true;
            red_col_change = 100;
            blue_col_change = 150;
            if(event.button.clicks == SDL_BUTTON_LEFT)///BUTTON CLICK & COLLISION
            {
                weHaveSelection = true;
                std::cout << "BANG BANG " <<std::endl;
            }

        }
        else
        {
            count_clicks = 0;
            collision_flag = false;

        }


        //std::cout << "coll_flag: "<<collision_flag<<std::endl;
    }

    //std::cout << "print clicks " <<count_clicks<<std::endl;
    //std::cout << "weHaveSelection: " <<weHaveSelection<<std::endl;
    //ctor

}

collision_main_screen::~collision_main_screen()
{
    //dtor
}

