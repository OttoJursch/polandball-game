#include "gameobject.h"
#include <stdio.h>

GameObject::GameObject(int x, int y, int h, int w, int rad, std::string name)
{
    xPos = x;
    yPos = y;
    height = h;
    this->name = name;
    width = w;
    collRad= rad;
    this->grav = true;
}

bool GameObject::getGrav(){
    return grav;
}

void GameObject::setGrav(bool grav){
    this->grav = grav;
}

int GameObject::getCollRadius(){
    return collRad;
}

int GameObject::x(){
    return xPos;
}

bool GameObject::equals(GameObject * other){
    if(other == 0){
        return false;
    }
    return other->name == this->name && this->x() == other->x() && this->y() == other->y();
}

QPoint * GameObject::getDrawingPosition(){
    QPoint * point = new QPoint(drawingX, drawingY);
    return point;
}


int GameObject::y(){
    return yPos;
}

int GameObject::getHeight(){
    return height;
}

int GameObject::getWidth(){
    return width;
}

void GameObject::setX(int newX){
    xPos = newX;
}

void GameObject::setY(int newY){
    yPos = newY;
}

QPoint * GameObject::getPosition(){
    QPoint * point = new QPoint(xPos, yPos);
    return point;
}
