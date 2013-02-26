/* 
 * File:   enemy.h
 * Author: luiz
 *
 * Created on February 26, 2013, 3:33 PM
 */

#ifndef ENEMY_H
#define	ENEMY_H
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
#include <typeinfo>

using namespace std;


#define MAX_X 1366
#define MIN_X 0
#define MAX_Y 768
#define MIN_Y 0

class Enemy{

public:
       Enemy();
       

       void Draw(float scaleX=1, float scaleY=1);
       float GetWi();
       float GetHe();
       
       void SetSprite(ALLEGRO_BITMAP *sprite);
       
       int GetX();
       void SetX( int newValue);
       
       int GetY();
       void SetY( int newValue);
       
       void SetDead();

protected:
        int x;
        int y;
        float wi;
        float he;
        ALLEGRO_BITMAP *spriteToDraw;
        
        bool dead;

};




#endif	/* ENEMY_H */

