#include "character.h"

Character::Character(){
    spriteToDraw=NULL;
    wi=NULL;
    he=NULL;
    x = (MAX_X)/2.0;
    y = MAX_Y;
  
    visible = true;
    dead = false;

}

void Character::SetSprite(ALLEGRO_BITMAP* sprite){
    spriteToDraw=sprite;
    wi=al_get_bitmap_width(spriteToDraw);
    he=al_get_bitmap_height(spriteToDraw);
   
}

float Character::GetWi(){

    return wi;
}

float Character::GetHe(){

    return he;

}


int Character::GetX(){

    return x;

}

int Character::GetY(){

    return y;

}

void Character::SetX( int newValue){

    if( newValue <= MAX_X && newValue >= MIN_X){
        x = newValue;
    } else {
    
        x = GetX();
           
    }

}

void Character::SetY( int newValue){

    if( newValue <= MAX_Y && newValue >= MIN_Y){
        y = newValue;
    } else {
    
        y = GetY();
           
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



void Character::DrawChar(float scaleX, float scaleY){
    al_draw_scaled_rotated_bitmap(spriteToDraw,GetWi()/2.0,GetHe(),
            (x),
            (y),
            scaleX,scaleY,0,0);
    al_flip_display();
}