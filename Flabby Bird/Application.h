#pragma once
#include<SDL.h>
class Application
{
private:
	SDL_Window *window;
	SDL_Renderer *renderer;
public:
	static const auto SCREEN_WIDTH=1280;
	static const auto SCREEN_HEIGHT=720;
public:
	Application();
	int exec();
	~Application();
};

