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
    Objects OBJ(menuRenderer,file_text.c_str(), num_of_lines_per_text , button_text.c_str() , blue_text, 1);
    menu_font MNF(menuRenderer,file_text.c_str(), num_of_lines_per_text , button_text.c_str() , blue_text);

    Objects* pObj = (Objects*)malloc(sizeof(Objects));
    Objects* pObj_1 = (Objects*)malloc(sizeof(Objects));
    //collision_main_screen* pCMS = (collision_main_screen*)malloc(sizeof(collision_main_screen));
    pObj->LoadTexture("./res/Cher_bkg_img_800x600.jpg",GetRenderer());
    pObj_1->LoadTexture("./res/LOGO_1.png",GetRenderer());
    OBJ.LoadTexture("./res/frame_400x85_btn.png",GetRenderer());


    while(menuRun == false)
    {
        menu_screen::Clr_scr();
        menu_screen::SetBKG(menuRenderer);
        pObj->DrawBKGTexture(GetRenderer(),bkg_texture_w,bkg_texture_h);
        pObj_1->DrawLogoTexture(GetRenderer(), logo_texture_x , logo_texutre_y,logo_texture_w,logo_texture_h);
        //menu_methods MMT;

        OBJ.DrawFrameTexture(GetRenderer() , Xpos_button ,Ypos_button , Width_button , Higth_button );
        OBJ.square(GetRenderer() , Xpos_button + 4 ,Ypos_button + 4,Width_button  - 8, Higth_button - 8 ,red_button,green_button,blue_button,alpha_button);

        OBJ.frame(GetRenderer() , Xpos_button,Ypos_button,Width_button,Higth_button,0,0,0,255);
        OBJ.DrawButton(MNF, menuRenderer, Xpos_text , Ypos_text);

        ///EVENTS////////////

        while(SDL_PollEvent(&event))
        {
            collision_main_screen CMS(event, Xpos_button,Ypos_button,Width_button,Higth_button);
            //std::cout<<"flag: "<<CMS.GetWeHaveSelection()<<std::endl;

            menu_screen::button_off(CMS.GetWeHaveSelection(),MNF);
           // menu_methods MMT(GetRenderer(),CMS,OBJ);
            //MMT.Loop_methods(event, 1 , CMS.GetWeHaveSelection(),GetRenderer());

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
           //menu_screen::button_off(pCMS->GetWeHaveSelection()); COre dumped #@$#%$^&^*&


        }

        ///END OF EVENTS/////



        ///RENDER
        //
        SDL_RenderPresent(menuRenderer);

    //std::cout << "click_value: "<<click_value<<std::endl;
        ///END OF RENDER///
    }
//    pCMS = NULL;
    pObj = NULL;
    pObj_1 = NULL;

}

void menu_screen::SetBKG(SDL_Renderer* render)
{
    SDL_SetRenderDrawColor(render,red,green,blue,alpha);
}

int menu_screen::button_off(bool on_flag, menu_font& Mnf)
{

    if(on_flag == true)
    {
        Clr_scr();
        red_button = 0 ;
        green_button = 0;
        blue_button = 0;
        alpha_button = 0;

        Xpos_button = 0;
        Ypos_button = 0;
        Width_button = 0;
        Higth_button = 0;

        button_text.append("");
        Xpos_text = 0;
        Ypos_text = 0 ;
        num_of_lines_per_text =0;
        Mnf.SetButtonText(0,0);
        bkg_texture_w = 0;
        bkg_texture_h = 0;

        logo_texture_x = 0;
        logo_texutre_y = 0;
        logo_texture_w = 0;
        logo_texture_h = 0;
        //SDL_RenderClear(GetRenderer());


    }
    else
        on_flag = false;
return 0;

}


menu_screen::~menu_screen()
{
    SDL_DestroyRenderer(menuRenderer);
    SDL_DestroyWindow(menuWindow);
    //dtor
}

