#ifndef OBJETGRAPHIQUE_H
#define OBJETGRAPHIQUE_H

struct point
{
    float x;
    float y;
};


class ObjetGraphique
{
    protected:
        point coordonnes;
        int taille;



    public:
        ObjetGraphique(point p = {0,0}, int taille =15);
        int getX();
        int getY();
        void setX(int decalage);
        void setY(int decalage);
};

#endif // OBJETGRAPHIQUE_H
