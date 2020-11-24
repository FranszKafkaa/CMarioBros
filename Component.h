#ifndef COMPONENT_H
#define COMPONENT_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

typedef struct Player{
    double x,y;
    int weight, height, turn;
    signed short int pulando,count,tecla;
    

    ALLEGRO_BITMAP *sprite_player;

} def;

def Player;



void EventPlayer(ALLEGRO_EVENT *evento, def *Player);
void playerUpdate(def *Player);
void setPlayer(def *Player);




#endif //COMPONENT_H