#ifndef BOTANISTE_H
#define BOTANISTE_H

#include <string>
#include <vector>

using namespace std;

class Botaniste{

    protected:
        string _name;
        int _nbrPlante = 1;
        int _monnaie = 100;

    public:
        Botaniste();
        Botaniste(string name);
        string getNameBota(); 
        int getNbrPlante(); 
        int getMonnaie(); 

        void setMonnaie(int prix);

        void setNameBota(string nouveauNom);
        


};

#endif