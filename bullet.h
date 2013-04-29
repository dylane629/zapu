#ifndef BULLET_H
#define BULLET_H
#include "foreground.h"

class Bullet: public Foreground {
 public:
 Bullet (QPixmap *pm, int nx, int ny);
 void move(int count); // Implement the move method
 void sink();
 void setGround(int y);
 void keySignal(QKeyEvent *e);
 void keyRelease(QKeyEvent *r);
 void collideUp(int num);
 void collideDown(int num);
 bool sinking;
};

Bullet::Bullet( QPixmap *pm, int nx, int ny ) : Foreground( pm, nx, ny ) {
 srand(time(NULL));
 int py = rand()%3+1;
 switch(py){
 case 1: py = -200; break;
 case 2: py = -100; break;
 case 3: py = -70; break;
 }
 cout<<"PY: "<<py<<endl;
 setPos(768, py);
 setZValue(2);
 sinking = false;
//Any specific initialization code for BigThing goes here.
}
void Bullet::move(int count) {
if(count%2 == 0){
 if(sinking == false){
  moveBy(-1, 0);
 }
 else{
  moveBy(0, 1);
 }
}
//Implement the movement behavior of BigThing here. This is required.
}

void Bullet::collideUp(int num){
 //yoshi case
 if(num == 0){
 
 }
}

void Bullet::collideDown(int num){
//yoshi case
 if(num == 0){
   sinking = true;
 }
}

#endif // BULLET_H