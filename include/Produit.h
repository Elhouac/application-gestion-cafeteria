#ifndef PRODUIT_H
#define PRODUIT_H

#include <string>
using namespace std;

class Produit {
private:
    int idProduit;
    string nom;
    double prix;
    string categorie;
    int stock;

public:
    Produit();
    Produit(int id, const string& nom, double prix, 
            const string& categorie, int stock);
    
    // Getters
    int getIdProduit() const;
    string getNom() const;
    double getPrix() const;
    string getCategorie() const;
    int getStock() const;
    
    // Setters
    void setIdProduit(int id);
    void setNom(const string& nom);
    void setPrix(double prix);
    void setCategorie(const string& categorie);
    void setStock(int stock);
    
    // Méthodes
    bool estDisponible(int quantite = 1) const;
    bool retirerStock(int quantite);
    void ajouterStock(int quantite);
    void afficher() const;
    
    // Opérateurs
    bool operator==(const Produit& autre) const;
};

#endif // PRODUIT_H

