#ifndef BOTANISTE_CPP
#define BOTANISTE_CPP

#include "botaniste.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

    Botaniste::Botaniste(): _name("titouan"){}
    Botaniste::Botaniste(string name) : _name(name){}

    string Botaniste::getNameBota(){ 
        return _name;
    } 

    int Botaniste::getNbrPlante(){ 
        return _nbrPlante;
    } 

    int Botaniste::getMonnaie(){ 
        return _monnaie;
    } 

    void Botaniste::setMonnaie(int prix){ 
        _monnaie += prix;
    } 

    void Botaniste::setNameBota(string nouveauNomBota){ 
        _name = nouveauNomBota;
    } 

    






    





#endif