/* 
 * File:   main.cpp
 * Author: priscila
 *
 * Created on February 21, 2013, 01:22 AM
 */

#include <cstdlib>
#include <allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/keyboard.h>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

ALLEGRO_DISPLAY *janela = NULL;
ALLEGRO_FONT *fonteMenu = NULL;
ALLEGRO_FONT *fonte2 = NULL;
ALLEGRO_FONT *choice = NULL;
ALLEGRO_BITMAP *imagem = NULL;
ALLEGRO_SAMPLE *music = NULL;

bool done = false;


const int X = 1024;
const int Y = 768;

int draw_menu(int pos=1){
    imagem = al_load_bitmap("images/display.png");
    
    if (!imagem)
        cout << "error" << endl;
    
    char *menuOptions[4] = { "Start Game", "Credits", "About this game", "Quit" }; 
     // Carregando o arquivo de fonte
    fonteMenu = al_load_font("fonts/Squareo.ttf", 39, 0);
    if (!fonteMenu)
    {
        al_destroy_display(janela);
        fprintf(stderr, "Falha ao carregar fonte.\n");
        return -1;
    }
    //plano de fundo
    al_draw_bitmap(imagem, 0, 0, 0);
    
    al_draw_text(choice, al_map_rgb(255, 255, 255), X / 3 - 40, 350+50*pos, ALLEGRO_ALIGN_LEFT, "Q");
    
    //menu options
    al_draw_text(fonte2, al_map_rgb(0, 235, 0), 10, 10, ALLEGRO_ALIGN_LEFT, "J");
    al_draw_text(fonte2, al_map_rgb(0, 235, 0), X - 10, 50, ALLEGRO_ALIGN_RIGHT, "N");
    al_draw_text(fonteMenu, al_map_rgb(50, 200, 115), X / 3, 400, ALLEGRO_ALIGN_LEFT, menuOptions[0]);
    al_draw_text(fonteMenu, al_map_rgb(50, 200, 115), X / 3, 450, ALLEGRO_ALIGN_LEFT, menuOptions[1]);
    al_draw_text(fonteMenu, al_map_rgb(50, 200, 115), X / 3, 500, ALLEGRO_ALIGN_LEFT, menuOptions[2]);
    al_draw_text(fonteMenu, al_map_rgb(50, 200, 115), X / 3, 550, ALLEGRO_ALIGN_LEFT, menuOptions[3]);
    
    

    
    al_flip_display();
    
}


void rotate_sbvb(){
    
    ALLEGRO_BITMAP *sbvb;
    
    sbvb = al_load_bitmap("images/sbvb.png");
    
    
    if (!sbvb)
        cout << "error" << endl;
  
    
    float angle=0.5;
    for(int i=0; i< 50; i++){
        
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(imagem, 0, 0, 0);
        al_draw_scaled_rotated_bitmap(sbvb,321/2.0,315/2.0,1024/2,768/2,1.5,1.5,angle,0);
        al_flip_display();
        angle+=0.1;
    }
        
     
     
}
        


 int load_menu(){
     int pos = 1;
     char *menuOptions[4] = { "Start Game", "Credits", "About this game", "Quit" }; 
     // Carregando o arquivo de fonte
    fonteMenu = al_load_font("fonts/Squareo.ttf", 39, 0);
    if (!fonteMenu)
    {
        al_destroy_display(janela);
        fprintf(stderr, "Falha ao carregar fonte.\n");
        return -1;
    }
    
    choice = al_load_font("fonts/spacefont.ttf", 36, 0);
  
     
    
    draw_menu();
    
    
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    
    
    while(!done){
        ALLEGRO_EVENT events;
        al_wait_for_event(event_queue, &events);
        if(events.type == ALLEGRO_EVENT_KEY_DOWN){
            switch(events.keyboard.keycode){
              
                case ALLEGRO_KEY_DOWN:
                    draw_menu(pos); 
                    pos+=1;                              
                    if (pos>4)
                        pos = 1;
                    draw_menu(pos);
                    //al_draw_text(choice, al_map_rgb(255, 255, 255), X / 3 - 40, 350+50*pos, ALLEGRO_ALIGN_LEFT, "Q");
                    al_flip_display();
                    break;
                case ALLEGRO_KEY_UP:
                    draw_menu(pos); 
                    pos-=1;                                  
                    if (pos<1)
                        pos = 4;
                    draw_menu(pos);                 
                    al_flip_display();
                    break;
                case ALLEGRO_KEY_ESCAPE:
                    done = true;
                    break;
                case ALLEGRO_KEY_ENTER:
                    switch (pos){
                        case 1:
                            //start game
                            break;
                        case 2:
                            //credits
                            break;
                        case 3:
                            rotate_sbvb();
                            al_flip_display();
                            break;
                        case 4:
                            done = true;
                            break;
                    }
                case ALLEGRO_KEY_A: //ainda em testes
                    rotate_sbvb();
                    al_flip_display();
                    draw_menu(pos);
                    break;
                    
            }
        }
            
    }    
    
    return 0;
}
 
 int install_periferics(){
     // if we get trouble the function returns 1 and close the app
    if ( !al_install_mouse() ){
        return 1; 
    }
    
    if ( !al_install_keyboard() ) {
        return 1;
    }
     
 }
 
 void load_music(){
    al_install_audio();
    al_init_acodec_addon();
    music = al_load_sample("sound/intro.ogg");
    al_play_sample(music, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL);   
 }
 
int main(void)
{
   // al_set_new_display_flags(ALLEGRO_FULLSCREEN);
     
    // the library
    if (!al_init())
    {
        fprintf(stderr, "Falha ao inicializar a Allegro.\n");
        return -1;
    }
      
    // Inicialização do add-on para uso de fontes
    al_init_font_addon();
    
    if (!al_install_audio())
    {
        fprintf(stderr, "Falha ao inicializar add-on allegro_ttf.\n");
        return -1;
    }
    // Inicialização dos recursos que serão utilizados
    if (!al_init_ttf_addon())
    {
        fprintf(stderr, "Falha ao inicializar add-on allegro_ttf.\n");
        return -1;
    }
 
    if (!al_reserve_samples(1)){
      fprintf(stderr, "failed to reserve samples!\n");
      return -1;
    }
       
    // Criação da nossa janela        
    janela = al_create_display(X, Y);
    if (!janela)
    {
        fprintf(stderr, "Falha ao criar janela.\n");
        return -1;
    }
    
    
    // Carregando outro arquivo de fonte
    fonte2 = al_load_font("fonts/Space Shop.ttf", 72, 0);
    if (!fonte2)
    {
        al_destroy_display(janela);
        fprintf(stderr, "Falha ao carregar fonte 2.\n");
        return -1;
    }
    
    load_music();
    
    // Preenchemos a tela com uma cor
    al_clear_to_color(al_map_rgb(255, 220, 220));
    
    if (!al_init_image_addon()){
      fprintf(stderr, "failed to reserve samples!\n");
      return -1;
    }
     
    //load images
    imagem = al_load_bitmap("images/display.png");
    // draw the image on screen
    al_draw_bitmap(imagem, 0, 0, 0);
    
    // Texto alinhado à esquerda
    al_draw_text(fonte2, al_map_rgb(0, 235, 0), 10, 10, ALLEGRO_ALIGN_LEFT, "J");
 
    // Texto alinhado à direita
    al_draw_text(fonte2, al_map_rgb(0, 235, 0), X - 10, 50, ALLEGRO_ALIGN_RIGHT, "N");
    
    install_periferics();
        
  
    load_menu();
    

    
    al_flip_display();
     
    // Tela é exibida por 8 segundos
  //  al_rest(14.0);
 
    // Desalocação da fonte e da janela
    al_destroy_font(fonteMenu);
    al_destroy_display(janela);
    allegro_exit();
 
    return 0;
}

