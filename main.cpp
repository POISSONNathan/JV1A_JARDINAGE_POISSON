#include "Orchidee.cpp"
#include "Fleur.cpp"
#include "Botaniste.cpp"
#include <iostream>
#include <string>

using namespace std;

int main(){

    Plante * maPlante;
    string nouveauNom;
    string nouveauNomBota;

    vector<Plante*> monJardin = {};

    int jour = 1;
    int choix;
    int choixAct;

    Botaniste * moi = new Botaniste();
    cout << "Comment veux tu t'appeler ? (nom sans espace) -> ";
    cin >> nouveauNomBota;
    moi->setNameBota(nouveauNomBota);

    bool planteMorte = false;
    int choixPlante;
    int choixDebutJour;
    int placeJardin = 0;
    string nouveauNomPlante;

    bool engraiBlock = false;

    while (jour <= 7){
        bool finJour = false;

        cout << "Vous êtes rendu au jour " << jour << endl << endl;

        cout << "Inventaire de " << moi->getNameBota() << endl << "Nombre de plante : " << moi->getNbrPlante() << endl << "Espece : " << moi->getMonnaie() << endl << endl;

        cout << "Voulez vous achetez une plante ? 1 : oui / 2 : non - > "; 
        cin >> choixDebutJour;

        if (choixDebutJour == 1){
            cout << moi->getNameBota() << " tu veux acheter quelle type de plante pour ton jardin ? 1 : Orchidée (20€) / 2 : Fleur (25€)" << endl;
            cin >> choix;

            if (choix == 1){
                monJardin.push_back(new Orchidee());
                cout << "Vous avez acheté une " << monJardin[placeJardin]->getEspece() << endl;
                moi->setMonnaie(monJardin[placeJardin]->getPrix());
            }
            
            if (choix == 2){
                monJardin.push_back(new Fleur());
                cout << "Vous avez acheté une "  << monJardin[placeJardin]->getEspece() << endl;
                moi->setMonnaie(monJardin[placeJardin]->getPrix());

                cout << "Comment veux tu appeler ta plante ? (nom sans espace) -> ";
                cin >> nouveauNomPlante;
                monJardin[placeJardin]->setNamePlante(nouveauNomPlante);
            }

            placeJardin ++;
        }

        cout << "De quelle plante tu veux t'occuper ? (entre son numéro ex: 2 pour la deuxième si tu en possède ce nombre) -> ";
        cin >> choixPlante;

        cout << "Etat de la " << choixPlante << "e plante :" << endl << "Nom : " << monJardin[choixPlante-1]->getName() << endl << "Espece : " << monJardin[choixPlante-1]->getEspece() << endl << "Hydratation : " << monJardin[choixPlante-1]->getHydra() << endl << "Santé : " << monJardin[choixPlante-1]->getSante() << endl << "Maturité : " << monJardin[choixPlante-1]->getMaturite() << endl << endl;
        
        if (monJardin[choixPlante-1]->getSante() < -30 || monJardin[choixPlante-1]->getSante() > 30){
            cout << "Votre plante est en mauvaise santé !" << endl;
        }
        if (monJardin[choixPlante-1]->getSante() < -50 || monJardin[choixPlante-1]->getSante() > 50){
            planteMorte = true;
            break;
        }

        if (monJardin[choixPlante-1]->getHydra() > 30){
            cout << "Votre plante est en train de se noyer !" << endl << endl;
        }
        if (monJardin[choixPlante-1]->getHydra() < -30){
            cout << "Votre plante est en manque d'eau !" << endl << endl;
        }

        while (finJour == false){
            cout << "Que veux tu faires à ta plante ?" << endl;
            cout << "1 = donner de l'engrais / 2 = la tailler / 3 = l'aroser / 4 : dormir -> ";
            cin >> choixAct;


            if (choixAct == 1){
                if(engraiBlock == false) {
                    monJardin[choixPlante-1]->setEngrais();
                    cout << "Vous avez mis de l'engrais sur " << monJardin[choixPlante-1]->getName() << endl;
                }
                else{
                    "Vous ne pouvez pas réutilisez d'engrais aujourd'hui, dommage";
                }
                engraiBlock = true;
            }

            if (choixAct == 2){
                monJardin[choixPlante-1]->setTailler();
                cout << "Vous avez taillé " << monJardin[choixPlante-1]->getName() << endl << endl;
            }

            if (choixAct == 3){
                monJardin[choixPlante-1]->setAroser();
                cout << "Vous avez aroser " << monJardin[choixPlante-1]->getName() << endl << endl;
            }

            if (choixAct == 4){
                monJardin[choixPlante-1]->setAroser();
                cout << "Vous dormez et passez au jour suivant" << endl << endl;
                finJour = true;
            }
        }

        monJardin[choixPlante-1]->setUpdateJour();
        engraiBlock = false;
        jour++;
    }
    cout << "Fin de semaine !" << endl << endl;

    if (planteMorte == true){
        cout << "Votre plante est morte, triste !" << endl;
    }
    else{
        cout << "Inventaire de " << moi->getNameBota() << endl << "Nombre de plante : " << moi->getNbrPlante() << endl << "Espece : " << moi->getMonnaie() << endl << endl;
    }


    
        
    
    return 0;
}