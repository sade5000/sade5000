#include "objects.h"

Objects::Objects(SDL_Renderer* render,std::string file,int fontSize,std::string text,SDL_Color color)
{
    menu_font MNF(render,file.c_str(),fontSize,text.c_str(),color);


    //ctor
}

void Objects::square(SDL_Renderer* renderer, int Xpos , int Ypos , int Width , int height, Uint8 red, Uint8 green , Uint8 blue , Uint8 alpha )
{
    SDL_SetRenderDrawColor(renderer , red, green, blue,alpha);
    SDL_Rect src;

    src.x = Xpos;
    src.y = Ypos;
    src.w = Width;
    src.h = height;


    SDL_RenderFillRect(renderer,&src);

    SDL_SetRenderDrawColor(renderer , 60, 60, 60,255);

}



void Objects::frame(SDL_Renderer* renderer, int Xpos , int Ypos , int Width , int height,Uint8 red, Uint8 green , Uint8 blue , Uint8 alpha)
{
        SDL_SetRenderDrawColor(renderer , red, green, blue,alpha);
        SDL_Rect src;

        src.x = Xpos;
        src.y = Ypos;
        src.w = Width;
        src.h = height;


    SDL_RenderDrawRect(renderer,&src);

    SDL_SetRenderDrawColor(renderer , 60, 60, 60,255);



}

SDL_Surface* Objects::LoadSurface(std::string pic_path , SDL_Window* window)///window BKG
{

    gScreenSurface = SDL_GetWindowSurface(window);
    SDL_Surface* loadedSurface = IMG_Load(pic_path.c_str());
    if(loadedSurface == NULL)
    {
        std::cout<<"Unable to load surface or IMG error"<<IMG_GetError()<<std::endl;
    }
    else
    {
        OptimizedEndSurface = SDL_ConvertSurface(loadedSurface , gScreenSurface->format , 0);
        if(OptimizedEndSurface == NULL)
        {
            std::cout<<" Unable to optimize surface"<<SDL_GetError()<<std::endl;

        }
        SDL_FreeSurface(loadedSurface);
    }

    return OptimizedEndSurface;

}

SDL_Texture* Objects::LoadTexture(std::string path, SDL_Renderer* render)
{
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if(loadedSurface == NULL)
    {
        std::cout<<"Unable to loade IMG"<<IMG_GetError()<<std::endl;
    }
    else
    {
        texture = SDL_CreateTextureFromSurface(render , loadedSurface);
        if(texture == NULL)
        {
            std::cout<<"Unable to create button frame texture"<<SDL_GetError()<<std::endl;
        }
        SDL_FreeSurface(loadedSurface);
    }
    return texture;
}

void Objects::DrawFrameTexture(SDL_Renderer* render , int posX , int posY , int wide , int high)
{
    SDL_Rect src;
    SDL_Rect dst;

    src.x = 0;
    src.y = 0;
    src.w = 400;
    src.h = 85;


    dst.x = posX;
    dst.y = posY;
    dst.w = wide;
    dst.h = high;

    SDL_RenderCopy(render , texture , &src , &dst);

}

void Objects::DrawBKGTexture(SDL_Renderer* render , int wide , int high)
{
    SDL_Rect src;
    SDL_Rect dst;

    src.x = 0;
    src.y = 0;
    src.w = wide;
    src.h = high;


    dst.x = 0;
    dst.y = 0;
    dst.w = wide;
    dst.h = high;

    SDL_RenderCopy(render , texture , &src , &dst);

}

void Objects::DrawLogoTexture(SDL_Renderer* render , int posX , int posY , int wide , int high)
{

    SDL_Rect src;
    SDL_Rect dst;

    src.x = 0;
    src.y = 0;
    src.w = wide;
    src.h = high;


    dst.x = posX;
    dst.y = posY;
    dst.w = wide;
    dst.h = high;

    SDL_RenderCopy(render , texture , &src , &dst);


}



void Objects::DrawButton(class menu_font& MNF, SDL_Renderer* render , int posX , int posY )
{

    MNF.DrawMenuFont(render,posX,posY);

}



Objects::~Objects()
{
    SDL_FreeSurface(gWindow);
    SDL_FreeSurface(gScreenSurface);
    SDL_FreeSurface(gPNGSurface);
    //dtor
}

