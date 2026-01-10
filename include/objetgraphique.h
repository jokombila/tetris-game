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
};

#endif // OBJETGRAPHIQUE_H
