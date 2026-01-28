#ifndef TETROMINO_H
#define TETROMINO_H
#include <QPainter>
#include "objetgraphique.h"


using namespace std;

class Tetromino : public ObjetGraphique
{
protected:
    string couleur;
    string type;
    int position;
    int Mat[4][4][4]; // int Mat[4][4][4];
    point coordonnesGrille;


public:
    Tetromino(point p={0,0}, point p2={0,0}, int taille=15, string c = "rose", string t = "I", int k=0);
    void dessiner(QPainter * p);
    void deplacerDe(int dx, int dy);
    void Pivoter();
    int** getmattetro(int i,int j);

    string GetCouleur();
    string Gettype();


    int getI();
    int getJ();
};

#endif // TETROMINO_H
