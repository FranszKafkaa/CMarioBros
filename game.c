#include "game.h"
#include "Component.h"

void main_game(){
    ALLEGRO_DISPLAY *janela = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER *tempo = NULL;

    def Player;
    Components allComponents[100];

    al_init();
    al_init_image_addon();
    al_install_keyboard();

    janela = al_create_display(ALTURA, LARGURA);

    al_set_window_title(janela,"Super Mario Bros");

    signed short int done = 0;


    tempo = al_create_timer(1/MAX_FPS);
    event_queue = al_create_event_queue();


    setPlayer(&Player);

    al_register_event_source(event_queue, al_get_display_event_source(janela));
    al_register_event_source(event_queue, al_get_timer_event_source(tempo));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_start_timer(tempo);

    while (!done){
        ALLEGRO_EVENT evento;

        al_wait_for_event(event_queue, &evento);

        //Game Components Events
        EventPlayer(&evento, &Player);
        
        //End Section of Events 

        if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){       
            done ++;
        }
                
            playerUpdate(&Player);      

            al_flip_display();
            al_clear_to_color(al_map_rgb(107,140,255));   
    }

    al_destroy_timer(tempo);
    al_destroy_event_queue(event_queue);
    al_destroy_display(janela);

}