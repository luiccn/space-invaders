#include "character.h"

Character::Character(ALLEGRO_BITMAP *sprite){
    
    spriteToDraw=sprite;
    x = (MAX_X-al_get_bitmap_width(spriteToDraw))/2.0;
    y = MAX_Y-al_get_bitmap_height(spriteToDraw);
    
    visible = true;
    dead = false;

}

int Character::GetX(){

    return x;

}

int Character::GetY(){

    return y;

}

void Character::SetX( int newValue){

    if( newValue <= MAX_X && newValue >= MIN_X && visible){
        x = newValue;
        DrawChar();
    } else {
    
        x = newValue;
           
    }

}

void Character::SetY( int newValue){

    if( newValue <= MAX_Y && newValue >= MIN_Y && visible){
        y = newValue;
        DrawChar();
    } else {
    
        y = newValue;
           
    }

}

bool Character::IsDead(){

    return dead;
}

void Character::SetDead(bool newValue){

    visible = (!newValue);
    dead = newValue;

    if(dead){
        SetY(MAX_Y);
        SetX(MAX_X/2);
    }

}



void Character::DrawChar(){

    al_draw_bitmap(spriteToDraw,GetX(),GetY(),0);
    al_flip_display();

}