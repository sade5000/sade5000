#include "menu_screen.h"

menu_screen::menu_screen(std::string& tittle , const int SCREEN_WIDTH , const int SCREEN_HEIGTH, Uint32 index)
{

    menuWindow = SDL_CreateWindow(tittle.c_str() , SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH, SCREEN_HEIGTH, index);
    if(menuWindow == NULL)
    {
        std::cout << "Window fail to compile!!! Error " << SDL_GetError()<<std::endl;
    }
    menuRenderer = SDL_CreateRenderer(menuWindow , -1 , SDL_RENDERER_ACCELERATED);
    if(menuRenderer == NULL)
    {
        std::cout << "Renderer fail !!! Error " << SDL_GetError() << std::endl;
        exit(1);
    }



    //ctor
}

void menu_screen::Clr_scr()
{
    SDL_RenderClear(menuRenderer);

}

int menu_screen::comute(bool flag)
{

    if(flag == true)
    {
        bool_converter = 4;

    }
    else
        bool_converter = 2;
    return bool_converter;
}



void menu_screen::mainLoop()
{
    Objects OBJ(menuRenderer,file_text.c_str(), num_of_lines_per_text , button_text.c_str() , blue_text);
    menu_font MNF(menuRenderer,file_text.c_str(), num_of_lines_per_text , button_text.c_str() , blue_text);

    Objects* pObj = (Objects*)malloc(sizeof(Objects));
    Objects* pObj_1 = (Objects*)malloc(sizeof(Objects));
    pObj->LoadTexture("./res/BKG_1.png",GetRenderer());
    pObj_1->LoadTexture("./res/LOGO_1.png",GetRenderer());
    OBJ.LoadTexture("./res/frame_400x85_btn.png",GetRenderer());

    while(menuRun == false)
    {
        menu_screen::Clr_scr();
        menu_screen::SetBKG(menuRenderer);
        pObj->DrawBKGTexture(GetRenderer(),800,600);
        pObj_1->DrawLogoTexture(GetRenderer(), 0 , 400,800,200);


        OBJ.DrawFrameTexture(GetRenderer() , Xpos_button ,Ypos_button , Width_button , Higth_button );
        OBJ.square(GetRenderer() , Xpos_button + 4 ,Ypos_button + 4,Width_button  - 8, Higth_button - 8 ,red_button,green_button,blue_button,alpha_button);

        OBJ.frame(GetRenderer() , Xpos_button,Ypos_button,Width_button,Higth_button,0,0,0,255);
        OBJ.DrawButton(MNF, menuRenderer, Xpos_text , Ypos_text);

        ///EVENTS////////////

        while(SDL_PollEvent(&event))
        {
            collision_main_screen CMS(event, Xpos_button,Ypos_button,Width_button,Higth_button);

            comute(CMS.CollisionFlag());
            switch(event.type)
            {
                case SDL_QUIT:
                {
                    menuRun = true;
                }break;
                case SDL_MOUSEBUTTONDOWN:
                {

                    switch(event.button.clicks)
                    {
                        case SDL_BUTTON_LEFT:
                        {
                            click_value = 1;
                                            //std::cout<<"lft btn pressed"<<std::endl;
                        }break;

                        default:
                        {
                            ///
                        }break;
                    }
                }break;
                case SDL_MOUSEBUTTONUP:
                {
                    click_value = 0;

                }break;

                default:
                {
                    ///
                }break;
            }

            if(CMS.CollisionFlag() == 1)
            {
                red_button = CMS.GetRedColChange();
                blue_button = CMS.GetBlueColChange();

                    ///
            }
            else
            {
                red_button = 20;
                blue_button = 50;
            }
       // std::cout<<"click_value: "<<click_value<<std::endl;
           // menu_methods MNF(event,CMS.CollisionFlag(),click_value); blocking the loop #@#$@$#$%^%$^&
        }

        ///END OF EVENTS/////



        ///RENDER

        SDL_RenderPresent(menuRenderer);

    //std::cout << "click_value: "<<click_value<<std::endl;
        ///END OF RENDER///
    }
    pObj = NULL;

}

void menu_screen::SetBKG(SDL_Renderer* render)
{
    SDL_SetRenderDrawColor(render,red,green,blue,alpha);
}



menu_screen::~menu_screen()
{
    SDL_DestroyRenderer(menuRenderer);
    SDL_DestroyWindow(menuWindow);
    //dtor
}

