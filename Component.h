#ifndef COMPONENT_H
#define COMPONENT_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#define GAME_VELOCITY 10

typedef struct GameObjects {
    double x,y;
    int weight, height;
    ALLEGRO_BITMAP *Sprite;

} GameObjects;

typedef struct Player{
    GameObjects initate;
    int turn;
    signed short int pulando,count,tecla;    

} def;

typedef struct Components{
    GameObjects obj;
    signed short int Enemy;

} Components;

def Player;
Components allComponents[100];


//Player Functions
void EventPlayer(ALLEGRO_EVENT *evento, def *Player);
void playerUpdate(def *Player);
void setPlayer(def *Player);
// End of Player Functions



#endif //COMPONENT_H