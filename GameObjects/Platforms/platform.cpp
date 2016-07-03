#include "platform.h"

Platform::Platform(int x, int y, int h, int w) : GameObject(x, y, h, w){
}

void Platform::draw(QPainter * painter){
    painter->setBrush(Qt::white);
    QPoint *point = getDrawingPosition();
    painter->drawRect(point->x(), point->y(), drawingHeight, drawingWidth);
    printf("im still here");
}

void Platform::update(){}