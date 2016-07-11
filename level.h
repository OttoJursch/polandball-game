#ifndef LEVEL_H
#define LEVEL_H
#include <vector>
#include "GameObjects/Actors/actor.h"
#include "Graphics/camera.h"
#include "GameObjects/Platforms/platform.h"
#include "GameObjects/Actors/player.h"
#include "GameObjects/kdtree.h"

class Level
{

public:
    Level(Player *);
    Level(Player *, std::vector<GameObject *>);
    void update();
    void applyGravity();
    void ActorPlatformCollisions();
    std::vector<GameObject *> getObjects();

private:
    std::vector<GameObject *> objects;
    std::vector<Actor *> actors;
    std::vector<Platform *> plats;
    //this is stupid, change to double later
    KDTree tree;
    void checkCollisions();
    void actorCollisions(Actor*, GameObject*);
    int gravity;

};

#endif // LEVEL_H
