#ifndef MAINCHAR_H
#define MAINCHAR_H
#include "object.h"
#include <cmath>

class MainChar: public Object {
 public:
 MainChar (QPixmap *pm, int nx, int ny);
 void move(int count); 
 void keySignal(QKeyEvent *e);
 void keyRelease(QKeyEvent *r);
 void walk();
 void crouch();
 void jump();
 int num;
 double time;
 double ty;
 bool stopWalking;
 bool walking;
 bool pause;
 bool jumping;
 bool dj;
 bool doubleJump;
 bool egg;
};

MainChar::MainChar(QPixmap *pm, int nx, int ny ) : Object( pm, nx, ny ) {
 num = 0;
 vX = 0;
 walking = false;
 egg = false;
 jumping = false;
 doubleJump = false;
 stopWalking = false;
 pause = false;
}
void MainChar::move(int count) {
if(count%40 == 0){
 if(walking == true){
  egg = false;
  jumping = false;
  dj = false;
  doubleJump = false;
  walk();
 }
 else if(egg == true && num <=2){
  crouch();
 }
}
if(count%4 == 0){
 if(jumping == true){
  jump();
 }
}
}

void MainChar::keySignal(QKeyEvent *e){
 switch(e->key()){
   case Qt::Key_Up:
      cout<<"UP KEY\n";
      if(jumping == false){
       if(walking == true){
         pause = true;
         walking = false;
        }
       jumping = true;
       ty = 0;
       time = 0;
       num = 0;
      }
      else if(dj == true){
         cout<<"DOUBLE JUMP\n";
         doubleJump = true;
       }
       break;
   case Qt::Key_Right:
     if(jumping == false && egg == false && stopWalking == false){
      walking = true;
      vX = 1;
     }
     else if(jumping == false && egg == false){
      vX = 0;
      num = 0;
      walk();
      num = 0;
      walking = false;
      stopWalking = false;
     }
      break;
   case Qt::Key_Down:
      if(egg == false && jumping == false){
        walking = false;
        egg = true;
        num = 0;
        vX = 0;
       }
       break;
   case Qt::Key_Left:
      walking = false;
      vX = 0;
      cout<<"LEFT KEY\n"; 
      break;
   case Qt::Key_Space:
     cout<<"SPACE KEY\n";
     break;
  }
}

void MainChar::keyRelease(QKeyEvent *e){
 switch(e->key()){
   case Qt::Key_Up:
       if(jumping == true && doubleJump == false){
         dj = true;
       }
       break;
   case Qt::Key_Right:
     if(walking == true){
      stopWalking = true;
      }
      break;
   case Qt::Key_Down:
      cout<<"RELEASE DOWN KEY\n";
      if(egg == true){
        egg = false;
        walk();
        num = 0;
       }
       break;
   case Qt::Key_Left:
      stopWalking = true;
      break;
   case Qt::Key_Space:
     cout<<"SPACE KEY\n";
     break;
  }
}

void MainChar::crouch(){
 QPixmap *pm = new QPixmap("/home/cs102/game_eirinber/Pictures/Egg2.png");
 setPixmap(*pm);
}

void MainChar::jump(){
  QPixmap *pm = new QPixmap("/home/cs102/game_eirinber/Pictures/Jump1.png");
  int vi = 50;
  if(dj == true && doubleJump == true){
    time = 0;
    vi = 10;
    dj = false;
  }
  float yi = vi*time + -5*time*time;
  time += .1;
  float yf = vi*time + -5*time*time;
  if(doubleJump == true && (yi - yf)<0){
   double t = time/0.4;
   int pic = (int)t;
    switch(pic){
     case 1: 
      pm = new QPixmap("/home/cs102/game_eirinber/Pictures/Jump4.png"); break;
     case 2: 
      pm = new QPixmap("/home/cs102/game_eirinber/Pictures/Jump5.png"); break;
     case 3: 
      pm = new QPixmap("/home/cs102/game_eirinber/Pictures/Jump6.png"); break;
     case 4: 
      pm = new QPixmap("/home/cs102/game_eirinber/Pictures/Jump7.png"); break;
     case 5: 
      pm = new QPixmap("/home/cs102/game_eirinber/Pictures/Jump8.png"); break;
     case 6: 
      pm = new QPixmap("/home/cs102/game_eirinber/Pictures/Jump9.png"); break;
     case 7: 
      pm = new QPixmap("/home/cs102/game_eirinber/Pictures/Jump10.png"); break;
     default:
      pm = new QPixmap("/home/cs102/game_eirinber/Pictures/Jump11.png"); break;
    }
  }
  else if(doubleJump == true){
    pm = new QPixmap("/home/cs102/game_eirinber/Pictures/Jump3.png");
  }
  if(ty == 0 && doubleJump == false){
   pm = new QPixmap("/home/cs102/game_eirinber/Pictures/Jump1.png");
  }
  else if((yi-yf)>0 && doubleJump == false){
   pm = new QPixmap("/home/cs102/game_eirinber/Pictures/Jump3.png");
  }
  else if(doubleJump == false){
   pm = new QPixmap("/home/cs102/game_eirinber/Pictures/Jump2.png");
  }
  ty += (yi-yf);
  if(ty < 0){
  moveBy(0, yi-yf);
  }
  else{
   moveBy(0, yi-yf-ty);
   jumping = false;
   dj = false;
   doubleJump = false;
   if(pause == true){
    walking = true;
    pause = false;
   }
   pm = new QPixmap("/home/cs102/game_eirinber/Pictures/YW1.png");
  }
  setPixmap(*pm);
}

void MainChar::walk(){
 QPixmap *pm = new QPixmap("/home/cs102/game_eirinber/Pictures/YW1.png");
  switch(num){
   case 1: pm = new QPixmap("/home/cs102/game_eirinber/Pictures/YW2.png"); break;
   case 2: pm = new QPixmap("/home/cs102/game_eirinber/Pictures/YW3.png"); break;
   case 3: pm = new QPixmap("/home/cs102/game_eirinber/Pictures/YW4.png"); break;
   case 4: pm = new QPixmap("/home/cs102/game_eirinber/Pictures/YW5.png"); break;
   case 5: pm = new QPixmap("/home/cs102/game_eirinber/Pictures/YW6.png"); break;
   case 6: pm = new QPixmap("/home/cs102/game_eirinber/Pictures/YW7.png"); break;
   case 7: pm = new QPixmap("/home/cs102/game_eirinber/Pictures/YW8.png"); break;
   }
   if(num <= 6){
    num++;
   }
   else{
    num = 0;
   }
  setPixmap(*pm);
}

#endif // MAINCHAR_H
