#include "menu_font.h"

menu_font::menu_font(SDL_Renderer* render ,std::string file , int fontSize, std::string text,SDL_Color textColor )
{


    LoadFont(render,file.c_str(),fontSize,text.c_str(),textColor);
    SDL_QueryTexture(texture,NULL,NULL,NULL,NULL);
    //ctor
}


void menu_font::DrawMenuFont(SDL_Renderer* render,int posX , int posY)
{
    SDL_Rect dst;
    dst.x = posX;
    dst.y = posY;
    dst.w = BUTTON_TEXT_WIDTH;
    dst.h = BUTTON_TEXT_HEIGHT;

    SDL_RenderCopy(render,texture,NULL, &dst);

}


SDL_Texture* menu_font::LoadFont(SDL_Renderer* render ,std::string file , int fontSize, std::string text,SDL_Color textColor )
{
    font = TTF_OpenFont(file.c_str() ,fontSize);
    SDL_Surface* surface = TTF_RenderText_Blended(font,text.c_str() ,textColor);


    texture = SDL_CreateTextureFromSurface(render , surface);
    SDL_FreeSurface(surface);
    return texture;

}




menu_font::~menu_font()
{
    TTF_CloseFont(font);
    SDL_DestroyTexture(texture);
    //dtor
}

