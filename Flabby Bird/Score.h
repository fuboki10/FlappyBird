#pragma once
#include<SDL.h>
#include<SDL_ttf.h>
class Score
{
private:
	SDL_Texture *texture;
	int width;
	int height;
	static const int font_size = 24;
	TTF_Font *font;
	int points;
	SDL_Surface *text_surface;
	SDL_Surface*surface;
	Uint32 Gmask,Bmask,Amask,Rmask;
public:
	void draw(SDL_Renderer *renderer);
	Score(int points);
	~Score(void);
};

