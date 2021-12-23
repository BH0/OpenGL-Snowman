#include "SnowControl.h"
#include "Shape.h" 
#include "Random.h" 
#include <iostream>
#include <cstdlib>

SnowControl::SnowControl() {
    auto snowballsSize = sizeof(snowballs) / sizeof(snowballs[0]);
    for (int i = 0; i < snowballsSize; i++) {
        Snowball snowball = Snowball();
        snowballs[i] = snowball; 
    } 
}
void SnowControl::Update() {
	for (auto& snowball : snowballs) {
		snowball.Move(); 
        snowball.Render(); 
    } 
}
Snowball::Snowball() {
    velocity = 0; fallSpeed = Random::Float() * 1.2; 
}
void Snowball::Render() {  
    Shape::Cuboid(x, y, 8, 4, true); 
}
void Snowball::Move() {
	y -= fallSpeed; 
    x += velocity + acceleration; 
    Wrap(); 
    if (y < 0) {
        y = SCREEN_HEIGHT; 
        x = Random::Float() * SCREEN_WIDTH;
    } 
} 

void Snowball::Wrap() {
    if (x > SCREEN_WIDTH) {
        x = 0;
    }
    if (x < 0) {
        x = SCREEN_HEIGHT;
    }
}