#ifndef MENU_SCREEN_H
#define MENU_SCREEN_H

#pragma once
#include "game_lib.h"
#include "objects.h"
#include "collision_main_screen.h"
#include "menu_methods.h"
class menu_screen
{
    public:
        menu_screen(std::string& tittle , const int SCREEN_WIDTH , const int SCREEN_HEIGTH, Uint32 index );
        inline bool MenuRun(){return menuRun;}
        inline SDL_Window* GetWindow(){return menuWindow;}
        inline SDL_Renderer* GetRenderer(){return menuRenderer;}

        void mainLoop();
        void Clr_scr();
        virtual ~menu_screen();
        void SetBKG(SDL_Renderer* render );
        int comute(bool flag);


    protected:

    private:
        bool menuRun = false;
        SDL_Window* menuWindow = NULL;
        SDL_Renderer* menuRenderer = NULL;
        SDL_Event event;
        menu_screen(const menu_screen& other){}
        void operator=(const menu_screen& other){}
        Uint8 red = 60; Uint8 green  = 60; Uint8 blue = 60; Uint8 alpha = 255;///GLOBAL BKG
        bool CollisionFlag = false;
        bool onMousePressed = false;
        int bool_converter = 0;
        int click_value = 0;


        ///Text var
        SDL_Color red_text = { 255, 0 , 0 };
        SDL_Color blue_text = { 0 , 0, 255 };
        std::string file_text = "./TTF/Caladea-Bold.ttf";
        std::string button_text = " CHER's_Button_1 ";
        int num_of_lines_per_text = 20;
        int Xpos_text = 125; int Ypos_text = 110;
        ///End of text var

        ///Button var
        int Xpos_button = 100; int Ypos_button = 100;
        int Width_button = 200 ; int Higth_button = 40;
        Uint8 red_button = 0 ; Uint8 green_button = 160;
        Uint8 blue_button = 0; Uint8 alpha_button = 255;
        ///End of button var


};

#endif // MENU_SCREEN_H
