/* 
 * File:   character.h
 * Author: luiz
 *
 * Created on February 24, 2013, 4:32 PM
 */

#ifndef CHARACTER_H
#define	CHARACTER_H
#define MAX_X 1024
#define MIN_X 0
#define MAX_Y 768
#define MIN_Y 0

class Character{

public:
       Character(BITMAP* sprite);

       int GetX();
       void SetX( int newValue);
       
       int GetY();
       void SetY( int newValue);
       
       void DrawChar();
       
       int GetScore();
       int setScore(int newValue);
       
       bool IsDead();
       void SetDead( bool newValue, BITMAP* tempBitmap);

protected:
        int x;
        int y;
        int score;
        BITMAP* spriteToDraw;
        
        bool visible;
        bool dead;

};

#endif	/* CHARACTER_H */

