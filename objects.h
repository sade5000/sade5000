#ifndef OBJECTS_H
#define OBJECTS_H

#include "game_lib.h"
#include "menu_font.h"

class Objects
{
    public:
        Objects(SDL_Renderer* render,std::string file,int fontSize,std::string text,SDL_Color color,int ID);

        void square(SDL_Renderer* renderer, int Xpos , int Ypos , int Width , int height,Uint8 red, Uint8 green , Uint8 blue , Uint8 alpha);
        void frame(SDL_Renderer* renderer, int Xpos , int Ypos , int Width , int height,Uint8 red, Uint8 green , Uint8 blue , Uint8 alpha);

        void DrawButton(class menu_font& MNF, SDL_Renderer* render , int posX , int posY);


        SDL_Surface* LoadSurface(std::string pic_path , SDL_Window* window);///Load BKG PNG

        SDL_Texture*LoadTexture(std::string path, SDL_Renderer* render);

        void DrawFrameTexture(SDL_Renderer* render,int posX , int posY , int wide , int high);
        void DrawBKGTexture(SDL_Renderer* render, int wide , int high);
        void DrawLogoTexture(SDL_Renderer* render,int posX , int posY , int wide , int high);
        int SetUpPosition(int posX , int posY);

        inline int GetButtonId(){return button_ID;}

        void static_draw_fnc();
        void dinamic_rend_func();

        virtual ~Objects();


    protected:

    private:
        SDL_Texture* texture = NULL;
        Objects(const Objects& other){}
        void operator=(const Objects& other){}

        SDL_Rect src;
        SDL_Rect dst;

        SDL_Surface* OptimizedEndSurface = NULL ;
        SDL_Surface* gWindow = NULL; /// Window surface
        SDL_Surface* gScreenSurface= NULL; /// surface contained by window
        SDL_Surface* gPNGSurface = NULL; ///curent display png img
        int button_ID = 0;



};

#endif // OBJECTS_H
