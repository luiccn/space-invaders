/* 
 * File:   main.cpp
 * Author: Luiz Carlos Ciafrino & Priscila Lima
 *
 * 
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
#include </home/luiz/work/eduinvaders-code/trunk/ESI/character.h>
#include </home/luiz/work/eduinvaders-code/trunk/ESI/laser.h>

#include <typeinfo>
#define X 1366
#define Y 768
const float FPS = 1000.0;

using namespace std;

ALLEGRO_DISPLAY *janela = NULL;
ALLEGRO_FONT *fonteMenu = NULL;
ALLEGRO_FONT *fonte2 = NULL;
ALLEGRO_FONT *choice = NULL;
ALLEGRO_BITMAP *imagem = NULL;
ALLEGRO_BITMAP *sbvb = NULL;
ALLEGRO_BITMAP *priscila = NULL;
ALLEGRO_BITMAP *ship = NULL;
ALLEGRO_BITMAP *laser = NULL;
ALLEGRO_SAMPLE *music = NULL;

Character myship;
Laser mylaser;

bool done = false;



int draw_menu(int pos = 1) {

    imagem = al_load_bitmap("images/display.png");

    char *menuOptions[4] = {"Start Game", "Credits", "About this game", "Quit"};
    // Loading font files
    fonteMenu = al_load_font("fonts/Squareo.ttf", 39, 0);
    if (!fonteMenu) {
        al_destroy_display(janela);
        fprintf(stderr, "Falha ao carregar fonte.\n");
        return -1;
    }

    fonte2 = al_load_font("fonts/Space Shop.ttf", 72, 0);
    if (!fonte2) {
        al_destroy_display(janela);
        fprintf(stderr, "Falha ao carregar fonte 2.\n");
        return -1;
    }

    choice = al_load_font("fonts/spacefont.ttf", 36, 0);

    // Game wallpaper
    al_draw_bitmap(imagem, 0, 0, 0);

    al_draw_text(choice, al_map_rgb(255, 255, 255), X / 3 - 40, 350 + 50 * pos, ALLEGRO_ALIGN_LEFT, "Q");

    //menu options
    al_draw_text(fonte2, al_map_rgb(0, 235, 0), 10, 10, ALLEGRO_ALIGN_LEFT, "J");
    al_draw_text(fonte2, al_map_rgb(0, 235, 0), X - 10, 50, ALLEGRO_ALIGN_RIGHT, "N");
    al_draw_text(fonteMenu, al_map_rgb(50, 200, 115), X / 3, 400, ALLEGRO_ALIGN_LEFT, menuOptions[0]);
    al_draw_text(fonteMenu, al_map_rgb(50, 200, 115), X / 3, 450, ALLEGRO_ALIGN_LEFT, menuOptions[1]);
    al_draw_text(fonteMenu, al_map_rgb(50, 200, 115), X / 3, 500, ALLEGRO_ALIGN_LEFT, menuOptions[2]);
    al_draw_text(fonteMenu, al_map_rgb(50, 200, 115), X / 3, 550, ALLEGRO_ALIGN_LEFT, menuOptions[3]);

    al_flip_display();

}

int Game() {

    fonte2 = al_load_font("fonts/Space Shop.ttf", 72, 0);

    ship = al_load_bitmap("images/ship.png");
    myship.SetSprite(ship);

    laser = al_load_bitmap("images/gun.png");
    mylaser.SetSprite(laser);

    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_text(fonte2, al_map_rgb(0, 235, 0), 10, 10, ALLEGRO_ALIGN_LEFT, "J");
    al_draw_text(fonte2, al_map_rgb(0, 235, 0), X - 10, 10, ALLEGRO_ALIGN_RIGHT, "N");
    myship.DrawChar();
    al_flip_display();

    bool donePlaying=0;
    
    ALLEGRO_KEYBOARD_STATE keyState;
    float laserspeed = 10.0;
    float speed = 12.0;
    float laserMove = 0;
    float toMove = 0;

    ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));

    al_start_timer(timer);

    while (!done && !donePlaying) {
        ALLEGRO_EVENT events;
        al_wait_for_event(event_queue, &events);

        if (events.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch (events.keyboard.keycode) {
                case ALLEGRO_KEY_ESCAPE:
                    done = true;
                    break;


            }
        }



        if (events.type == ALLEGRO_EVENT_TIMER) {
            al_get_keyboard_state(&keyState);



            if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT)) {
                if (al_key_down(&keyState, ALLEGRO_KEY_SPACE)) {
                    toMove += speed;
                    laserMove = 1;
                } else toMove += speed;
            }
            else if (al_key_down(&keyState, ALLEGRO_KEY_LEFT)) {
                if (al_key_down(&keyState, ALLEGRO_KEY_SPACE)) {
                    toMove -= speed;
                    laserMove = 1;
                } else toMove -= speed;
            } else if (al_key_down(&keyState, ALLEGRO_KEY_ESCAPE))
                done = true;
            else if (al_key_down(&keyState, ALLEGRO_KEY_SPACE))
                laserMove = 1;
            else if (al_key_down(&keyState, ALLEGRO_KEY_B)){
                donePlaying=1;
                draw_menu();}


        }


        int i = 0;

        if (laserMove) {
            mylaser.SetX(myship.GetX());
            mylaser.SetY(myship.GetY());
            for (int i = 0; i < 15; i++) {
                mylaser.SetY(mylaser.GetY() - 51.0);
                mylaser.Shoot();
                al_clear_to_color(al_map_rgb(0, 0, 0));
                myship.DrawChar();
                al_flip_display();
                laserMove = 0;
            }
        }

        al_clear_to_color(al_map_rgb(0, 0, 0));
        myship.SetX(myship.GetX() + toMove);
        myship.DrawChar();
        al_flip_display();

        al_clear_to_color(al_map_rgb(0, 0, 0));

        myship.SetX(myship.GetX() + toMove);
        myship.DrawChar();
        al_flip_display();
        toMove = 0;
    }


    return 0;

}

void rotate(const char * myimg, int quarter = 2) {

    sbvb = al_load_bitmap(myimg);


    if (!sbvb)
        cout << "error" << endl;


    float angle = 0.5;
    for (int i = 0; i < 120; i++) {

        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(imagem, 0, 0, 0);
        al_draw_scaled_rotated_bitmap(sbvb, al_get_bitmap_width(sbvb) / 2.0, al_get_bitmap_height(sbvb) / 2.0, X * quarter / 4, Y / 2, 1.5, 1.5, angle, 0);
        al_flip_display();
        angle += 0.1;
    }
    al_rest(0.3);
}



void rotateTwo(const char * myimg, const char * myimg2) {

    sbvb = al_load_bitmap(myimg);
    priscila = al_load_bitmap(myimg2);
    imagem = al_load_bitmap("images/about.png");



    float angle = 0.5;
    for (int i = 0; i < 120; i++) {

        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(imagem, 0, 0, 0);
        al_draw_scaled_rotated_bitmap(sbvb, al_get_bitmap_width(sbvb) / 2.0, al_get_bitmap_height(sbvb) / 2.0, X / 4, Y / 2, 1.5, 1.5, angle, 0);
        al_draw_scaled_rotated_bitmap(priscila, al_get_bitmap_width(priscila) / 2.0, al_get_bitmap_height(priscila) / 2.0, X * 3 / 4, Y / 2, 1.5, 1.5, angle, 0);
        al_flip_display();
        angle += 0.1;
    }
    al_rest(0.3);
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_flip_display();
    al_draw_bitmap(imagem, 0, 0, 0);
    al_flip_display();
    //al_rest(8.0);
}

void call_credits() {
    imagem = al_load_bitmap("images/credits.png");
    al_draw_bitmap(imagem, 0, 0, 0);
    al_flip_display();
    rotateTwo("images/ciafrino.png", "images/sbvb.png");

}


void call_about(){
    imagem = al_load_bitmap("images/about.png");
    al_draw_bitmap(imagem,0,0,0);
    al_flip_display();
           
}





int load_menu() {
    int pos = 1;
    char *menuOptions[4] = {"Start Game", "Credits", "About this game", "Quit"};

    // loading font files
    fonteMenu = al_load_font("fonts/Squareo.ttf", 39, 0);
    if (!fonteMenu) {
        al_destroy_display(janela);
        fprintf(stderr, "Falha ao carregar fonte.\n");
        return -1;
    }

    choice = al_load_font("fonts/spacefont.ttf", 36, 0);



    draw_menu();


    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_keyboard_event_source());


    while (!done) {
        ALLEGRO_EVENT events;
        al_wait_for_event(event_queue, &events);
        if (events.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch (events.keyboard.keycode) {

                case ALLEGRO_KEY_DOWN:
                    draw_menu(pos);
                    pos += 1;
                    if (pos > 4)
                        pos = 1;
                    draw_menu(pos);
                    break;
                case ALLEGRO_KEY_UP:
                    draw_menu(pos);
                    pos -= 1;
                    if (pos < 1)
                        pos = 4;
                    draw_menu(pos);
                    break;
                case ALLEGRO_KEY_ESCAPE:
                    done = true;
                    break;
                case ALLEGRO_KEY_B: //back to main menu
                    draw_menu(pos);
                    break;
                case ALLEGRO_KEY_ENTER:
                    switch (pos) {
                        case 1:
                            //start game
                            Game();
                            draw_menu(pos);
                            break;
                        case 2:
                            //credits
                            call_credits();
                            break;
                        case 3:
                            call_about();
                            break;
                        case 4:
                            done = true;
                            break;
                    }
                    break;
                case ALLEGRO_KEY_A:
                    rotate("images/sbvb.png");
                    al_flip_display();
                    draw_menu(pos);
                    break;

            }
        }

    }

    return 0;
}

int install_periferics() {
    // if we have trouble the function returns 1 and close the app
    if (!al_install_mouse()) {
        return 1;
    }

    if (!al_install_keyboard()) {
        return 1;
    }

}

void load_music() {
    al_install_audio();
    al_init_acodec_addon();
    music = al_load_sample("sound/intro.ogg");
    al_play_sample(music, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
}

int main(void) {




    imagem = al_load_bitmap("images/display.png");
    sbvb = al_load_bitmap("images/sbvb.png");
    ship = al_load_bitmap("images/ship.png");




    al_set_new_display_flags(ALLEGRO_FULLSCREEN);

    // the library
    if (!al_init()) {
        fprintf(stderr, "Falha ao inicializar a Allegro.\n");
        return -1;
    }

    // font addon initialization
    al_init_font_addon();

    if (!al_install_audio()) {
        fprintf(stderr, "Falha ao inicializar add-on allegro_ttf.\n");
        return -1;
    }
    // resources initialization
    if (!al_init_ttf_addon()) {
        fprintf(stderr, "Falha ao inicializar add-on allegro_ttf.\n");
        return -1;
    }

    if (!al_reserve_samples(1)) {
        fprintf(stderr, "failed to reserve samples!\n");
        return -1;
    }

    // main window creation      
    janela = al_create_display(X, Y);
    if (!janela) {
        fprintf(stderr, "Falha ao criar janela.\n");
        return -1;
    }




    load_music();

    // clearing screen to a determined color
    al_clear_to_color(al_map_rgb(255, 220, 220));

    if (!al_init_image_addon()) {
        fprintf(stderr, "failed to reserve samples!\n");
        return -1;
    }



    install_periferics();



    //    draw_menu();
    load_menu();



    al_flip_display();



    // deallocating fonts and window
    al_destroy_font(fonteMenu);
    al_destroy_display(janela);
    allegro_exit();

    return 0;
}

