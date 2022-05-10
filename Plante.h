#ifndef PLANTE_H
#define PLANTE_H

#include <string>

using namespace std;

class Plante{

    protected:
        string _name;
        string _espece;
        int _hydra = 5;
        int _sante = 5;
        int _maturite = 1;
        int _prix;

    public:
        Plante();
        Plante(string name,string espece);
        string getName(); 
        string getEspece(); 
        int getHydra();
        int getSante();
        int getMaturite();
        int getPrix();

        void setEngrais();
        void setTailler();
        void setAroser();
        void setUpdateJour();

        void setNamePlante(string nom);
        


};

#endif