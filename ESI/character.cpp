#include "character.h"

Character::Character(BITMAP* sprite){
    
    spriteToDraw=sprite;
    x = MAX_X/2;
    y = MAX_Y;
    
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
        DrawChar(spriteToDraw);
    } else {
    
        x = newValue;
           
    }

}

void Character::SetY( int newValue){

    if( newValue <= MAX_Y && newValue >= MIN_Y && visible){
        y = newValue;
        DrawChar(spriteToDraw);
    } else {
    
        y = newValue;
           
    }

}

bool Character::IsDead(){

    return dead;
}

void Character::SetDead(bool newValue, BITMAP* tempBitmap){

    visible = (!newValue);
    dead = newValue;

    if(dead){
        SetY(MAX_Y);
        SetX(MAX_X/2);
    }

}



void Character::DrawChar(){

    al_draw_bitmap(spriteToDraw,GetX(),GetY(),0);

}
