#include "enemy.h"

Enemy::Enemy() {
    spriteToDraw = NULL;
    wi = NULL;
    he = NULL;
    x = MAX_X;
    y = MAX_Y;

}
void Enemy::SetSprite(ALLEGRO_BITMAP* sprite) {
    spriteToDraw = sprite;
    wi = al_get_bitmap_width(spriteToDraw);
    he = al_get_bitmap_height(spriteToDraw);

}

float Enemy::GetWi() {

    return wi;
}

float Enemy::GetHe() {

    return he;

}

int Enemy::GetX() {

    return x;

}

int Enemy::GetY() {

    return y;

}

void Enemy::SetX(int newValue) {

    if (newValue <= MAX_X && newValue >= MIN_X) {
        x = newValue;
    } else {

        x = GetX();

    }

}

void Enemy::SetY(int newValue) {

    if (newValue <= MAX_Y && newValue >= MIN_Y) {
        y = newValue;
    } else {

        y = GetY();

    }

}


bool Enemy::isDead(){
    return dead;
}

//targetX and Y is the central point of the target Bitmap


void Enemy::SetDead() {

    dead = true;

}




void Enemy::Draw(float scaleX, float scaleY) {
    int i;
    if (!dead) {

        al_draw_scaled_rotated_bitmap(spriteToDraw,
                GetWi() / 2.0,
                GetHe(),
                (x),
                (y+he),
                scaleX, scaleY, 0, 0);
        
    }
}