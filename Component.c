#include "Component.h"


void setComponent(Components *Component){

    Component->obj.Sprite = al_load_bitmap("");

}

void updateComponent(Components *Component){
    Component->obj.x ++;
}