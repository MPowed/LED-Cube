#ifndef _CUBECODE_H_
#define _CUBECODE_H_

#include "cubeplex.h"

int color = blue;//random(7);
long animationTotal, animationAmount;
/********************************* PLANAR SPIN ********************************\
  | A plane of light spins around the virtical center of the cube and changes    |
  | colors after a certian number of rotations                                   |
  |                                                                              |
  | Written By: Asher Glick                                                      |
  \******************************************************************************/
/*void planarSpin() {
  continuePattern = true;
  int animationSpeed = 50;
  int spinsPerColor = 4; // a spin is actually half a revolution
  animationTotal = 14;
  animationAmount = 0;
  while (continuePattern) {
    int x = 0;
    int y = 0;
    for (int i = 0; i < spinsPerColor; i++) {
      for (int x = 0; x < 3; x++) {
        drawLine(color, x, 0, 0, 3 - x, 3, 0);
        drawLine(color, x, 0, 1, 3 - x, 3, 1);
        drawLine(color, x, 0, 2, 3 - x, 3, 2);
        drawLine(color, x, 0, 3, 3 - x, 3, 3);
        flushBuffer();
        clearBuffer();
        delay(animationSpeed);
      }
      for (int y = 0; y < 3; y++) {
        drawLine(color, 3, y, 0, 0, 3 - y, 0);
        drawLine(color, 3, y, 1, 0, 3 - y, 1);
        drawLine(color, 3, y, 2, 0, 3 - y, 2);
        drawLine(color, 3, y, 3, 0, 3 - y, 3);
        flushBuffer();
        clearBuffer();
        delay(animationSpeed);
      }
    }
    color = nextColor(color);
	if(animationAmount == animationTotal)
	{
		continuePattern = false;
	}
	animationAmount++;
  }
}*/

void planarSpin() {
  int animationSpeed = 50;
  int spinsPerColor = 4; // a spin is actually half a revolution

  for (int g = 0; g <= 30; g++) {
    int x = 0;
    int y = 0;
    for (int i = 0; i < spinsPerColor; i++) {
      for (int x = 0; x < 3; x++) {
        drawLine(color, x, 0, 0, 3 - x, 3, 0);
        drawLine(color, x, 0, 1, 3 - x, 3, 1);
        drawLine(color, x, 0, 2, 3 - x, 3, 2);
        drawLine(color, x, 0, 3, 3 - x, 3, 3);
        flushBuffer();
        clearBuffer();
        delay(animationSpeed);
      }
      for (int y = 0; y < 3; y++) {
        drawLine(color, 3, y, 0, 0, 3 - y, 0);
        drawLine(color, 3, y, 1, 0, 3 - y, 1);
        drawLine(color, 3, y, 2, 0, 3 - y, 2);
        drawLine(color, 3, y, 3, 0, 3 - y, 3);
        flushBuffer();
        clearBuffer();
        delay(animationSpeed);
      }
    }
    color = nextColor(color);
  }
}

/********************************** FOUNTIAN **********************************\
  | Light shoots up the middle of the cube then once it reaches the top fall     |
  | back down on the outside of the cube. After it hits the bottom it changes    |
  | color and starts again                                                       |
  |                                                                              |
  | Written By: Asher Glick                                                      |
  \******************************************************************************/
/*void fountian() {
  continuePattern = true;
  int animationSpeed = 100;
  animationTotal = 14;
  animationAmount = 0;
  while (continuePattern) {
    for (int z = 0; z <= 3; z++) {
      drawBoxWalls(color, 1, 1, z, 2, 2, z);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    for (int z = 3; z >= 0; z--) {
      drawBoxWalls(color, 0, 0, z, 3, 3, z);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    color = nextColor(color);
	if(animationAmount == animationTotal)
	{
		continuePattern = false;
	}
	animationAmount++;
  }
}*/

void fountian() {
  int animationSpeed = 100;
  for (int x = 0; x <= 40; x++) {
    for (int z = 0; z <= 3; z++) {
      drawBoxWalls(color, 1, 1, z, 2, 2, z);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    for (int z = 3; z >= 0; z--) {
      drawBoxWalls(color, 0, 0, z, 3, 3, z);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    color = nextColor(color);
  }
}

/********************************** TRI-FADE **********************************\
  | This animation fades through the red green and blue colors of the leds       |
  | creating different mixtures of each of the colors.                           |
  |                                                                              |
  | Written By: Asher Glick                                                      |
  \******************************************************************************/
void trifade() {
  continuePattern = true;
  int animationSpeed = 100;
  animationTotal = 14;
  animationAmount = 0;
  while (continuePattern) {
    // blue fade out, red fade in
    for (int i = 1; i <= 8; i++) {
      drawBox(blue, 9 - i, 0, 0, 0, 3, 3, 3);
      drawBox(red, i, 0, 0, 0, 3, 3, 3);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    // red fade out, green fade in
    for (int i = 1; i <= 8; i++) {
      drawBox(red, 9 - i, 0, 0, 0, 3, 3, 3);
      drawBox(green, i, 0, 0, 0, 3, 3, 3);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    // green fade out, blue fade in
    for (int i = 1; i <= 8; i++) {
      drawBox(green, 9 - i, 0, 0, 0, 3, 3, 3);
      drawBox(blue, i, 0, 0, 0, 3, 3, 3);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
	if(animationAmount == animationTotal)
	{
		continuePattern = false;
	}
	animationAmount++;
  }
}

/******************************** SHIFT SQUARES *******************************\
  | Three 2x2x2 squares start on the cube each a red green or blue. then they    |
  | randomly move around the cube one at a time, if they crash into each other   |
  | then then both leds turn on and while they occupy the same space they apear  |
  | a different color                                                            |
  |                                                                              |
  | Written By: Asher Glick                                                      |
  \******************************************************************************/
/*void shiftSquares() {
  int animationSpeed = 100;

  int blx = 2; // blue x
  int bly = 0; // blue y
  int blz = 0; // blue z

  int rdx = 0; // red x
  int rdy = 2; // red y
  int rdz = 0; // red z

  int gnx = 0; // green x
  int gny = 0; // green y
  int gnz = 2; // green z

  int * mover = &blx;
  continuePattern = true;

  while (continuePattern) {
    switch (random(0, 9)) {
      case 0: mover = &blx; break;
      case 1: mover = &bly; break;
      case 2: mover = &blz; break;
      case 3: mover = &rdx; break;
      case 4: mover = &rdy; break;
      case 5: mover = &rdz; break;
      case 6: mover = &gnx; break;
      case 7: mover = &gny; break;
      case 8: mover = &gnz; break;
    }
    *mover = (((*mover) + 2) % 4) - 1;
    drawBox(blue , abs(blx), abs(bly), abs(blz), abs(blx) + 1, abs(bly) + 1, abs(blz) + 1);
    drawBox(red  , abs(gnx), abs(gny), abs(gnz), abs(gnx) + 1, abs(gny) + 1, abs(gnz) + 1);
    drawBox(green, abs(rdx), abs(rdy), abs(rdz), abs(rdx) + 1, abs(rdy) + 1, abs(rdz) + 1);
    flushBuffer();
    clearBuffer();
    delay(animationSpeed);
    *mover = (((*mover) + 2) % 4) - 1;
    drawBox(blue , abs(blx), abs(bly), abs(blz), abs(blx) + 1, abs(bly) + 1, abs(blz) + 1);
    drawBox(red  , abs(gnx), abs(gny), abs(gnz), abs(gnx) + 1, abs(gny) + 1, abs(gnz) + 1);
    drawBox(green, abs(rdx), abs(rdy), abs(rdz), abs(rdx) + 1, abs(rdy) + 1, abs(rdz) + 1);
    flushBuffer();
    clearBuffer();
    delay(animationSpeed * 2);
  }
}*/

void shiftSquares() {
  int animationSpeed = 100;

  int blx = 2; // blue x
  int bly = 0; // blue y
  int blz = 0; // blue z

  int rdx = 0; // red x
  int rdy = 2; // red y
  int rdz = 0; // red z

  int gnx = 0; // green x
  int gny = 0; // green y
  int gnz = 2; // green z

  int * mover = &blx;
  

   for (int x = 0; x <= 125; x++){
	Serial.println(x);
	   
    switch (random(0, 9)) {
      case 0: mover = &blx; break;
      case 1: mover = &bly; break;
      case 2: mover = &blz; break;
      case 3: mover = &rdx; break;
      case 4: mover = &rdy; break;
      case 5: mover = &rdz; break;
      case 6: mover = &gnx; break;
      case 7: mover = &gny; break;
      case 8: mover = &gnz; break;
    }
    *mover = (((*mover) + 2) % 4) - 1;
    drawBox(blue , abs(blx), abs(bly), abs(blz), abs(blx) + 1, abs(bly) + 1, abs(blz) + 1);
    drawBox(red  , abs(gnx), abs(gny), abs(gnz), abs(gnx) + 1, abs(gny) + 1, abs(gnz) + 1);
    drawBox(green, abs(rdx), abs(rdy), abs(rdz), abs(rdx) + 1, abs(rdy) + 1, abs(rdz) + 1);
    flushBuffer();
    clearBuffer();
    delay(animationSpeed);
    *mover = (((*mover) + 2) % 4) - 1;
    drawBox(blue , abs(blx), abs(bly), abs(blz), abs(blx) + 1, abs(bly) + 1, abs(blz) + 1);
    drawBox(red  , abs(gnx), abs(gny), abs(gnz), abs(gnx) + 1, abs(gny) + 1, abs(gnz) + 1);
    drawBox(green, abs(rdx), abs(rdy), abs(rdz), abs(rdx) + 1, abs(rdy) + 1, abs(rdz) + 1);
    flushBuffer();
    clearBuffer();
    delay(animationSpeed * 2);
  }
}

/*********************************** TUNNEL ***********************************\
  |
  \******************************************************************************/
/*void tunnel() {
  continuePattern = true;
  int animationSpeed = 100;
  animationTotal = 150;
  animationAmount = 0;
  int color1[]  = {R, R, R, R, B, B, B, B};
  int bright1[] = {2, 4, 6, 8, 2, 4, 6, 8};
  int color2[]  = {B, B, B, B, R, R, R, R};
  //int bright2[] = {6,4,2,0,6,4,2,0};
  int bright2[] = {8, 6, 4, 2, 8, 6, 4, 2};

  int index[]   = {0, 1, 2, 3, 4, 5, 6, 7};

  while (continuePattern) {
    drawBoxWalls(color1[index[0]], bright1[index[0]], 1, 1, 0, 2, 2, 0);
    drawBoxWalls(color2[index[0]], bright2[index[0]], 1, 1, 0, 2, 2, 0);
    drawBoxWalls(color1[index[1]], bright1[index[1]], 1, 1, 1, 2, 2, 1);
    drawBoxWalls(color2[index[1]], bright2[index[1]], 1, 1, 1, 2, 2, 1);
    drawBoxWalls(color1[index[2]], bright1[index[2]], 1, 1, 2, 2, 2, 2);
    drawBoxWalls(color2[index[2]], bright2[index[2]], 1, 1, 2, 2, 2, 2);
    drawBoxWalls(color1[index[3]], bright1[index[3]], 1, 1, 3, 2, 2, 3);
    drawBoxWalls(color2[index[3]], bright2[index[3]], 1, 1, 3, 2, 2, 3);

    drawBoxWalls(color1[index[4]], bright1[index[4]], 0, 0, 3, 3, 3, 3);
    drawBoxWalls(color2[index[4]], bright2[index[4]], 0, 0, 3, 3, 3, 3);
    drawBoxWalls(color1[index[5]], bright1[index[5]], 0, 0, 2, 3, 3, 2);
    drawBoxWalls(color2[index[5]], bright2[index[5]], 0, 0, 2, 3, 3, 2);
    drawBoxWalls(color1[index[6]], bright1[index[6]], 0, 0, 1, 3, 3, 1);
    drawBoxWalls(color2[index[6]], bright2[index[6]], 0, 0, 1, 3, 3, 1);
    drawBoxWalls(color1[index[7]], bright1[index[7]], 0, 0, 0, 3, 3, 0);
    drawBoxWalls(color2[index[7]], bright2[index[7]], 0, 0, 0, 3, 3, 0);


    flushBuffer();
    clearBuffer();
    for (int i = 0; i < 8; i++) {
      //index[i] = index[i]==7?0:index[i]+1;
      index[i] = (index[i] + 1) % 8;
    }
    delay(animationSpeed);
	if(animationAmount >= animationTotal)
	{
		continuePattern = false;
	}
	animationAmount++;
	Serial.println(animationAmount);
	
  }
}*/

void tunnel() {
  int animationSpeed = 100;
  int color1[]  = {R, R, R, R, B, B, B, B};
  int bright1[] = {2, 4, 6, 8, 2, 4, 6, 8};
  int color2[]  = {B, B, B, B, R, R, R, R};
  //int bright2[] = {6,4,2,0,6,4,2,0};
  int bright2[] = {8, 6, 4, 2, 8, 6, 4, 2};

  int index[]   = {0, 1, 2, 3, 4, 5, 6, 7};

  for(int x = 0; x <= 350; x++) {
    drawBoxWalls(color1[index[0]], bright1[index[0]], 1, 1, 0, 2, 2, 0);
    drawBoxWalls(color2[index[0]], bright2[index[0]], 1, 1, 0, 2, 2, 0);
    drawBoxWalls(color1[index[1]], bright1[index[1]], 1, 1, 1, 2, 2, 1);
    drawBoxWalls(color2[index[1]], bright2[index[1]], 1, 1, 1, 2, 2, 1);
    drawBoxWalls(color1[index[2]], bright1[index[2]], 1, 1, 2, 2, 2, 2);
    drawBoxWalls(color2[index[2]], bright2[index[2]], 1, 1, 2, 2, 2, 2);
    drawBoxWalls(color1[index[3]], bright1[index[3]], 1, 1, 3, 2, 2, 3);
    drawBoxWalls(color2[index[3]], bright2[index[3]], 1, 1, 3, 2, 2, 3);

    drawBoxWalls(color1[index[4]], bright1[index[4]], 0, 0, 3, 3, 3, 3);
    drawBoxWalls(color2[index[4]], bright2[index[4]], 0, 0, 3, 3, 3, 3);
    drawBoxWalls(color1[index[5]], bright1[index[5]], 0, 0, 2, 3, 3, 2);
    drawBoxWalls(color2[index[5]], bright2[index[5]], 0, 0, 2, 3, 3, 2);
    drawBoxWalls(color1[index[6]], bright1[index[6]], 0, 0, 1, 3, 3, 1);
    drawBoxWalls(color2[index[6]], bright2[index[6]], 0, 0, 1, 3, 3, 1);
    drawBoxWalls(color1[index[7]], bright1[index[7]], 0, 0, 0, 3, 3, 0);
    drawBoxWalls(color2[index[7]], bright2[index[7]], 0, 0, 0, 3, 3, 0);


    flushBuffer();
    clearBuffer();
    for (int i = 0; i < 8; i++) {
      //index[i] = index[i]==7?0:index[i]+1;
      index[i] = (index[i] + 1) % 8;
    }
    delay(animationSpeed);
	
  }
}


/******************************** CHASE THE DOT *******************************\
  | A single point of light moves around the cube randomly and changes colors    |
  | when it tries to go out of bounds                                            |
  |                                                                              |
  | Inspired By: Jonah Glick                                                     |
  | Written By: Asher Glick                                                      |
  \******************************************************************************/
void chaseTheDot() {
  continuePattern = true;
  int animationSpeed = 100;

  int xpos = 0;
  int ypos = 0;
  int zpos = 0;

  while (continuePattern) {
    switch (random(0, 6)) {
      case 0:
        if (xpos > 0) {
          xpos--;
          break;
        }
        else color = nextColor(color);
      case 1:
        if (xpos < 3) {
          xpos++;
          break;
        }
        else color = nextColor(color);
        xpos--; break;

      case 2:
        if (ypos > 0) {
          ypos--;
          break;
        }
        else color = nextColor(color);
      case 3:
        if (ypos < 3) {
          ypos++;
          break;
        }
        else color = nextColor(color);
        ypos--; break;

      case 4:
        if (zpos > 0) {
          zpos--;
          break;
        }
        else color = nextColor(color);
      case 5:
        if (zpos < 3) {
          zpos++;
          break;
        }
        else color = nextColor(color);
        zpos--; break;
    }
    drawLed(color, xpos, ypos, zpos);
    flushBuffer();
    clearBuffer();
    delay(animationSpeed);
  }
}
/********************************* PLANAR FLOP ********************************\
  |
  \******************************************************************************/
/******************************* PLANAR FLOP 3D *******************************\
  | Version 2 of the planar flop, doing more complicated maths and 3D vectors    |
  | 'n stuff. Making this function found the bug of reversed z axis line drawing |
  \******************************************************************************/
/*void planarFlop3D() {
  continuePattern = true;
  int animationSpeed = 50;
  animationTotal = 28;
  animationAmount = 0;
  while (continuePattern) {

    for (int y = 3; y > 0; y--) {
      for (int z = 0; z < 4; z++) drawLine(color, 0, 3, z, 3, y, z);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    for (int x = 3; x > 0; x--) {
      for (int z = 0; z < 4; z++) drawLine(color, 0, 3, z, x, 0, z);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }


    for (int x = 0; x < 3; x++) {
      for (int y = 0; y < 4; y++) drawLine(color, 0, y, 0, x, y, 3);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    for (int z = 3; z > 0; z--) {
      for (int y = 0; y < 4; y++) drawLine(color, 0, y, 0, 3, y, z);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }

    for (int z = 0; z < 3; z++) {
      for (int x = 0; x < 4; x++) drawLine(color, x, 0, 0, x, 3, z);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    for (int y = 3; y > 0; y--) {
      for (int x = 0; x < 4; x++) drawLine(color, x, 0, 0, x, y, 3);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }

    for (int y = 0; y < 3; y++) {
      for (int z = 0; z < 4; z++) drawLine(color, 3, 0, z, 0, y, z);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    for (int x = 0; x < 3; x++) {
      for (int z = 0; z < 4; z++) drawLine(color, 3, 0, z, x, 3, z);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }

    for (int x = 3; x > 0; x--) {
      for (int y = 0; y < 4; y++) drawLine(color, 3, y, 3, x, y, 0);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    for (int z = 0; z < 3; z++) {
      for (int y = 0; y < 4; y++) drawLine(color, 3, y, 3, 0, y, z);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }

    for (int z = 3; z > 0; z--) {
      for (int x = 0; x < 4; x++) drawLine(color, x, 3, 3, x, 0, z);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    for (int y = 0; y < 3; y++) {
      for (int x = 0; x < 4; x++) drawLine(color, x, 3, 3, x, y, 0);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    color = nextColor(color);
	if(animationAmount == animationTotal)
	{
		continuePattern = false;
	}
	animationAmount++;
  }
}*/

void planarFlop3D() {
  continuePattern = true;
  int animationSpeed = 50;
  for (int x = 0; x <= 15; x++) {
	Serial.println(x);
    for (int y = 3; y > 0; y--) {
      for (int z = 0; z < 4; z++) drawLine(color, 0, 3, z, 3, y, z);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    for (int x = 3; x > 0; x--) {
      for (int z = 0; z < 4; z++) drawLine(color, 0, 3, z, x, 0, z);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }


    for (int x = 0; x < 3; x++) {
      for (int y = 0; y < 4; y++) drawLine(color, 0, y, 0, x, y, 3);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    for (int z = 3; z > 0; z--) {
      for (int y = 0; y < 4; y++) drawLine(color, 0, y, 0, 3, y, z);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }

    for (int z = 0; z < 3; z++) {
      for (int x = 0; x < 4; x++) drawLine(color, x, 0, 0, x, 3, z);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    for (int y = 3; y > 0; y--) {
      for (int x = 0; x < 4; x++) drawLine(color, x, 0, 0, x, y, 3);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }

    for (int y = 0; y < 3; y++) {
      for (int z = 0; z < 4; z++) drawLine(color, 3, 0, z, 0, y, z);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    for (int x = 0; x < 3; x++) {
      for (int z = 0; z < 4; z++) drawLine(color, 3, 0, z, x, 3, z);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }

    for (int x = 3; x > 0; x--) {
      for (int y = 0; y < 4; y++) drawLine(color, 3, y, 3, x, y, 0);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    for (int z = 0; z < 3; z++) {
      for (int y = 0; y < 4; y++) drawLine(color, 3, y, 3, 0, y, z);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }

    for (int z = 3; z > 0; z--) {
      for (int x = 0; x < 4; x++) drawLine(color, x, 3, 3, x, 0, z);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    for (int y = 0; y < 3; y++) {
      for (int x = 0; x < 4; x++) drawLine(color, x, 3, 3, x, y, 0);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    color = nextColor(color);
  }
}

void SeqTheDot() {
continuePattern = true;

int animationSpeed = 200; // change this to speed up or down.

// color= green; // change this to set a specific color or comment it out to cycle.

int xpos = 0;

int ypos = 0;

int zpos = 0;

while (continuePattern) {
// switch(random(0,6)) {

// Instead of random, we want to sequence, so we increment x each loop

// and increment each y at max x, and reset x to 0, at each y max we

// increment the z and reset the y, and the x.

for (xpos; xpos < 4; xpos++) {

for (ypos; ypos < 4; ypos++) {

for (zpos; zpos < 4; zpos++) {

// drawLed(color,1,1,3); // use this one to light up a specific LED

drawLed(color,xpos,ypos,zpos);

flushBuffer();

clearBuffer();

delay(animationSpeed);

} zpos=0;

} ypos=0;

} xpos=0;
color=nextColor(color);
} 
   
}

#endif