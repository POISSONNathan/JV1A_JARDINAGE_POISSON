#ifndef PLANTE_CPP
#define PLANTE_CPP

#include "plante.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

    Plante::Plante(): _name("titouan"), _espece("truc"){}
    Plante::Plante(string name,string espece) : _name(name),_espece(espece){}

    string Plante::getName(){ 
        return _name;
    } 

    string Plante::getEspece(){ 
        return _espece;
    }

    int Plante::getHydra(){ 
        return _hydra;
    }
    
    int Plante::getSante(){ 
        return _sante;
    }  

    int Plante::getMaturite(){ 
        return _maturite;
    }

    void Plante::setEngrais(){ 
        _maturite += 3;
    } 

    void Plante::setTailler(){ 
        _sante += 15;
    } 

    void Plante::setAroser(){ 
        _hydra += 10;
    } 

    void Plante::setUpdateJour(){ 
        if (_sante > 10){
            _maturite += 3;
        }
        else if (_sante < -10){
            _maturite += 1;
        }
        else{
            _maturite += 2;
        }

        _sante -= 15;
        _hydra -= 10;
    } 

    int Plante::getPrix(){
        return _prix;
    }

    void Plante::setNamePlante(string nouveauNom){ 
        _name = nouveauNom;
    } 







#endif