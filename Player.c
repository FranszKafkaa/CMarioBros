#include "Component.h"


void setPlayer (def *Player){
    Player->x = 100;
    Player->y = 300;

    Player->count = 0;
    Player->pulando = 0;
    Player->tecla = 0;

    Player->sprite_player = al_load_bitmap("sprite/mario.bmp");
    al_convert_mask_to_alpha(Player->sprite_player,al_map_rgb(255,0,255));

    Player->weight = al_get_bitmap_width(Player->sprite_player);
    Player->height = al_get_bitmap_height(Player->sprite_player);
}

void playerUpdate(def *Player){
    
    if (Player->tecla == 1){
        Player->turn = 0;
        

    }else if (Player->tecla == -1){
        Player->turn = 1;

    }
    Player->x += 5 * Player->tecla;

    al_draw_bitmap(Player->sprite_player, Player->x, Player->y,Player->turn);
    
}

void EventPlayer(ALLEGRO_EVENT *evento, def *Player){

    if(evento->type == ALLEGRO_EVENT_KEY_DOWN){
        switch(evento->keyboard.keycode){
            case ALLEGRO_KEY_LEFT:
                Player->count ++;
                Player->tecla += -1;
            break;

            case ALLEGRO_KEY_RIGHT:
                Player->count ++;
                Player->tecla = 1;
            break;
        }
    }



    if(evento->type == ALLEGRO_EVENT_KEY_UP){
        if(evento->keyboard.keycode == ALLEGRO_KEY_LEFT || evento->keyboard.keycode == ALLEGRO_KEY_RIGHT){
            Player->count --;

            if(Player->count == 0){
                Player->tecla = 0;

            }else if (evento->keyboard.keycode == ALLEGRO_KEY_LEFT){
                Player->tecla = 1;
                }else if(evento->keyboard.keycode == ALLEGRO_KEY_RIGHT){
                    Player->tecla = -1;
                }

            }
        }

}