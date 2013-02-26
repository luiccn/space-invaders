/* 
 * File:   character.h
 * Author: luiz
 *
 * Created on February 24, 2013, 4:32 PM
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
#include <typeinfo>

using namespace std;

#ifndef CHARACTER_H
#define	CHARACTER_H
#define MAX_X 1366
#define MIN_X 0
#define MAX_Y 768
#define MIN_Y 0

class Character{

public:
       Character();
       


       float GetWi();
       float GetHe();
       
       void SetSprite(ALLEGRO_BITMAP *sprite);
       
       int GetX();
       void SetX( int newValue);
       
       int GetY();
       void SetY( int newValue);
       
       void DrawChar(float scaleX=1, float scaleY=1);
       
       int GetScore();
       int setScore(int newValue);
       
       bool IsDead();
       void SetDead( bool newValue);

protected:
        int x;
        int y;
        float wi;
        float he;
        int score;
        ALLEGRO_BITMAP *spriteToDraw;
        
        bool visible;
        bool dead;

};

#endif	/* CHARACTER_H */

