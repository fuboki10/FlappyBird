#pragma once
#include<SDL.h>
#include"Bird.h"
#include"pipe.h"
#include<vector>
#include"Score.h"
class Game
{
private:
	SDL_Renderer *renderer;
	SDL_Texture *pipeTexture;
	Bird bird;
	pipe m_pipe;
	Score score;
	int points;
	std::vector<pipe> tubeList;
	int counter;
public:
	Game(SDL_Renderer *renderer);
	int exec();
	bool tick(bool isMouseDown);
};

