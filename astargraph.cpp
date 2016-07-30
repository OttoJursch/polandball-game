#include "astargraph.h"
#include <QSet>
#include <unordered_map>
#include "ourmath.h"
using namespace std;

void AstarGraph::addNode(QPoint * point){
    AstarNode * node = new AstarNode(point);
    vector<AstarNode*> nodes = tree.rangeSearch(node, 25);
    for(int i = nodes.size()-1; i >= 0; i--){
        if(!intersectsPlat(node, nodes[i])){
            node->addNeighbor(nodes[i]);
            nodes[i]->addNeighbor(node);
        }
    }
    tree.insert(node);
}

void AstarGraph::addPlat(Platform * plat){
    plats.push_back(plat);
}

bool AstarGraph::intersectsPlat(AstarNode * one, AstarNode * two){
    return false;

}

vector<QPoint*> AstarGraph::findPath(QPoint * start, QPoint * end){
    //find the two closest nodes in the graph
    AstarNode* startNode = new AstarNode(start);
    AstarNode* endNode = new AstarNode(end);
    //found them
    AstarNode *startNeighbor = tree.kNN(startNode, 1)[0];
    AstarNode *endNeighbor = tree.kNN(endNode, 1)[0];

    //Now do the Astar search
    QSet<AstarNode*> closedSet = QSet<AstarNode*>();
    QSet<AstarNode*> openSet = QSet<AstarNode*>();
    openSet.insert(startNeighbor);
    unordered_map<AstarNode*, AstarNode*> cameFrom = unordered_map<AstarNode*, AstarNode*>();
    unordered_map<AstarNode*, int> gScore = unordered_map<AstarNode*, int>();
    gScore[startNeighbor] = 0;
    unordered_map<AstarNode*, int> fScore = unordered_map<AstarNode*, int>();
    fScore[startNeighbor] = distance(startNeighbor, endNeighbor);
    while(openSet.size() > 0){
        AstarNode* current;
        for(auto it = openSet.begin(); it != openSet.end(); ++it){
            AstarNode* node = *it;
            if(current == 0 || fScore[node] < fScore[current]){
                current = node;
            }
        }
        if(current->x() == endNeighbor->x() && current->y() == endNeighbor->y()){
            vector<QPoint*> totalPath = vector<QPoint*>();
            totalPath.push_back(new QPoint(current->x(), current->y()));
            while(cameFrom.find(current) != cameFrom.end()){
                current = cameFrom[current];
                totalPath.push_back(new QPoint(current->x(), current->y()));
            }
            return totalPath;
        }

        openSet.remove(current);
        closedSet += (current);
        vector<AstarNode*> neighbors = current->getNeighbors();
        for(int i = 0; i < neighbors.size(); i++){
            AstarNode* neighbor = neighbors[i];
            if(closedSet.contains(neighbor)){
                continue;
            }
            int tentGScore = gScore[current] + distance(current, neighbor);
            if(!openSet.contains(neighbor)){
               openSet += neighbor;
            }
            else if(tentGScore >= gScore[neighbor]){
                continue;
            }
            cameFrom[neighbor] = current;
            gScore[neighbor] = tentGScore;
            fScore[neighbor] = tentGScore + distance(endNeighbor, neighbor);
        }
    }
}

int AstarGraph::getNodeDist(){
    return this->nodeDist;
}