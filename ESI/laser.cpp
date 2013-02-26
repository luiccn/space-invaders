#include "laser.h"

Laser::Laser() {
    spriteToDraw = NULL;
    wi = NULL;
    he = NULL;
    x = MAX_X;
    y = MAX_Y;

    dead = false;

}

void Laser::SetSprite(ALLEGRO_BITMAP* sprite) {
    spriteToDraw = sprite;
    wi = al_get_bitmap_width(spriteToDraw);
    he = al_get_bitmap_height(spriteToDraw);

}

float Laser::GetWi() {

    return wi;
}

float Laser::GetHe() {

    return he;

}

int Laser::GetX() {

    return x;

}

int Laser::GetY() {

    return y;

}

void Laser::SetX(int newValue) {

    if (newValue <= MAX_X && newValue >= MIN_X) {
        x = newValue;
    } else {

        x = GetX();

    }

}

void Laser::SetY(int newValue) {

    if (newValue <= MAX_Y && newValue >= MIN_Y) {
        y = newValue;
    } else {

        y = GetY();

    }

}

//targetX and Y is the central point of the target Bitmap

bool Laser::didHit(int targetX, int targetY, int targetWi, int targetHe) {
    if (x <= targetX + 0.5 * targetWi &&
            x >= targetX - 0.5 * targetWi &&
            y <= targetY + 0.5 * targetHe &&
            y >= targetY - 0.5 * targetHe) {
        return true;
        SetDead();
    }
    else return false;

}

void Laser::SetDead() {

    dead = true;

}

void Laser::Shoot(float scaleX, float scaleY) {
    int i;
    if (!dead) {

        al_draw_scaled_rotated_bitmap(spriteToDraw,
                GetWi() / 2.0,
                GetHe(),
                (x),
                (y+he),
                scaleX, scaleY, 0, 0);
        al_flip_display();
        
    }
}