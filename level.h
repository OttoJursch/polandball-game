#ifndef LEVEL_H
#define LEVEL_H
#include <vector>
#include "GameObjects/Actors/actor.h"
#include "Graphics/camera.h"
#include "GameObjects/Platforms/platform.h"
#include "GameObjects/Actors/player.h"
#include <QSet>
#include "GameObjects/kdtree.h"
#include <QObject>
#include "Event/keyevent.h"
#include "Event/eventbus.h"

class Level : public QObject
{
    Q_OBJECT

public:
    Level(Player *, const char *, int);
    Level(Player *, std::vector<GameObject *>, int);
    virtual ~Level();
    void update();
    void ActorPlatformCollisions();
    KDTree<GameObject*> * getObjects();
    void handlePress(int);
    void handleRelease(int);

public slots:
    EVENT_BUS void handleKeyEvent(KeyEvent);
    EVENT_BUS void handleDeleteEvent(DeleteEvent);

private:
    Player * player;
    KDTree<GameObject*> tree;
    void checkCollisions();
    void actorCollisions(Actor*, GameObject*);
    int gravity = -1;

};

int distance(Actor *, GameObject*);

#endif // LEVEL_H
