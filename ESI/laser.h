/* 
 * File:   laser.h
 * Author: luiz
 *
 * Created on February 25, 2013, 8:05 PM
 */

#ifndef LASER_H
#define	LASER_H
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

class Laser{

public:
       Laser();
       


       float GetWi();
       float GetHe();
       
       void SetSprite(ALLEGRO_BITMAP *sprite);
       
       int GetX();
       void SetX( int newValue);
       
       int GetY();
       void SetY( int newValue);
       
       void Shoot(float scaleX=1, float scaleY=2);
       
       bool didHit(int targetX, int targetY, int targetWi, int targetHe);
       void SetDead();

protected:
        int x;
        int y;
        float wi;
        float he;
        int score;
        ALLEGRO_BITMAP *spriteToDraw;
        
        bool dead;

};



#endif	/* LASER_H */

