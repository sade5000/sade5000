#include "game_lib.h"
#include "menu_screen.h"
#include "objects.h"

struct Tools
{
    bool screen_flag = false;
    Uint32 screen_index_flag ;
    Uint32 SDL_FLAG_SCREEN = SDL_WINDOW_SHOWN ;
    Uint32 SDL_GL_FLAG_SCREEN = SDL_WINDOW_OPENGL;
    Uint32 SDL_WIND_FULL_AND_SHOW_WIND = SDL_WINDOW_SHOWN| SDL_WINDOW_FULLSCREEN;

    std::array <Uint32 , 3> REAL_FLAG_ON = {SDL_WIND_FULL_AND_SHOW_WIND , SDL_FLAG_SCREEN , SDL_GL_FLAG_SCREEN};
};


struct MenuScreenTools
{
    std::string tittle = " Gamve V1.2 ";
    int MAIN_SCREEN_WIDTH = 800;
    int MAIN_SCREEN_HEIGTH = 600;



};

///GLOBALS//

SDL_Event globalEvent;
bool globalRun = false;



void MenuScreenUpdate()
{

    MenuScreenTools MST;
    Tools tool;

    menu_screen MNS(MST.tittle,MST.MAIN_SCREEN_WIDTH,MST.MAIN_SCREEN_HEIGTH,tool.SDL_FLAG_SCREEN);

    ///LOOOOOOOOP////
    MNS.mainLoop();



}




int main (int argc , char** args)
{

    if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        std::cout<<"SDL library fail to initialize !!! Error" << SDL_GetError() << std::endl;
        exit(1);
    }
    if(TTF_Init() == -1)
    {
        std::cout<<"TTF library fail to initialize !!! Error" << TTF_GetError() << std::endl;
        exit(1);
    }
    if(IMG_Init(IMG_INIT_JPG|IMG_INIT_PNG|IMG_INIT_TIF|IMG_INIT_WEBP|IMG_INIT_AVIF) == 0)
    {
        std::cout<<"IMG library fail to initialize"<< IMG_GetError()<<std::endl;

    }


    MenuScreenUpdate();





   // std::cout << "Hello World " <<std::endl;
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
    return 1;

}
