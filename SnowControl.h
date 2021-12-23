#pragma once
#include <vector> 
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

class Snowball {
public:
	float x = 200, y = SCREEN_HEIGHT; 
	float acceleration = 0.2f; 
	float velocity = 0, fallSpeed = 2; // make fallspeed random 
	Snowball(); 
	void Render(); 
	void Move(); 
	void Wrap();
};

class SnowControl // should use singleton pattern to ensure only 1 particle system exists 
{
public: 
	SnowControl();
	void Update(); 
private:
		Snowball snowballs[400]; 
};
