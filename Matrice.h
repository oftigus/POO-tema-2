#ifndef POO_TEMA_2_MATRICE_H
#define POO_TEMA_2_MATRICE_H

#include "Complex.h"

template <class T>
class Matrice {
protected:
    unsigned int linii, coloane;

    struct pozitie
    {
        unsigned int linie;
        unsigned int coloana;
    };

    struct nod
    {
        Complex<T> val;
        struct pozitie poz;
        struct nod *next;
    };

    struct nod *head;

    int comparaPoz(struct pozitie p1, struct pozitie p2);

public:
    //metode comune pentru toate tipurile de matrice:
    Matrice(unsigned int linii, unsigned int coloane);
    void adauga(Complex<T> z, unsigned int linie, unsigned int coloana);
    Matrice<T> transpusa();
    Matrice operator+(const Matrice &z);
    Matrice operator*(Matrice &z);
    template <class Y> friend std::ostream &operator<< (std::ostream &os, const Matrice<Y> &matrice);
    template <class Y> friend std::istream &operator>> (std::istream &is, Matrice<Y> &matrice);

    //functii virtuale:
    virtual Complex<T> determinant();
};


#endif //POO_TEMA_2_MATRICE_H
