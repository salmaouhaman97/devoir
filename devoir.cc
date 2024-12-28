#include <iostream>
#include <string>

using namespace std;

class Souris {
    double poids;
    string couleur;
    unsigned int age;
    unsigned int esperance_vie;
    bool clonee;

public:
    // Constructeur principal
    Souris(double p, string c, unsigned int a = 0, unsigned int ev = 36) 
        : poids(p), couleur(c), age(a), esperance_vie(ev), clonee(false) {
        cout << "Une nouvelle souris !" << endl;
    }

    // Constructeur de copie
    Souris(const Souris& other) 
        : poids(other.poids), couleur(other.couleur), age(other.age), esperance_vie(other.esperance_vie * 4 / 5), clonee(true) {
        cout << "Clonage d’une souris !" << endl;
    }

    // Destructeur
    ~Souris() {
        cout << "Fin d’une souris..." << endl;
    }

    // Méthode afficher
    void afficher() const {
        cout << "Une souris " << couleur << (clonee ? ", clonee," : "") 
             << " de " << age << " mois et pesant " << poids << " grammes" << endl;
    }

    // Méthode vieillir
    void vieillir() {
        ++age;
        if (clonee && age > esperance_vie / 2) {
            couleur = "verte";
        }
    }

    // Méthode évolue
    void evolue() {
        while (age < esperance_vie) {
            afficher();
            vieillir();
        }
    }
};

int main() {
    Souris a(50, "blanche", 2);      // Une souris blanche, non clonée
    Souris b(45, "grise");           // Une souris grise, non clonée
    Souris c(b);                     // Clonage de b, copie avec une espérance de vie réduite

    a.evolue();
    b.evolue();
    c.evolue();

    return 0;
}
