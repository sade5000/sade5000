#ifndef MENU_FONT_H
#define MENU_FONT_H
#include "game_lib.h"

class menu_font
{
    public:
        menu_font(SDL_Renderer* render ,std::string file , int fontSize, std::string text,SDL_Color textColor );

        void DrawMenuFont(SDL_Renderer* render,int posX , int posY);

        SDL_Texture* LoadFont(SDL_Renderer* render,std::string file , int fontSize, std::string text, SDL_Color textColor);

        virtual ~menu_font();


    protected:

    private:

        TTF_Font* font = NULL;
        SDL_Texture* texture = NULL;
        const int BUTTON_TEXT_WIDTH = 150;
        const int BUTTON_TEXT_HEIGHT = 20;

        menu_font(const menu_font& other){}
        void operator=(const menu_font& other){}
};

#endif // MENU_FONT_H
