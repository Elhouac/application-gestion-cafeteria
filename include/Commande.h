#ifndef COMMANDE_H
#define COMMANDE_H

#include <string>
#include <vector>
#include <ctime>
#include "Produit.h"
using namespace std;

struct LigneCommande {
    Produit produit;
    int quantite;
    double prixUnitaire;
    
    LigneCommande(const Produit& p, int qty) 
        : produit(p), quantite(qty), prixUnitaire(p.getPrix()) {}
};

enum class EtatCommande {
    EN_ATTENTE,
    EN_PREPARATION,
    PRETE,
    SERVIE,
    ANNULEE
};

class Commande {
private:
    int idCommande;
    int idClient;
    int idServeur;
    int idCuisinier;
    string date;
    string heure;
    EtatCommande etat;
    double total;
    vector<LigneCommande> lignes;

public:
    Commande();
    Commande(int id, int idClient, int idServeur, const string& date, const string& heure);
    
    // Getters
    int getIdCommande() const;
    int getIdClient() const;
    int getIdServeur() const;
    int getIdCuisinier() const;
    string getDate() const;
    string getHeure() const;
    EtatCommande getEtat() const;
    double getTotal() const;
    vector<LigneCommande>& getLignes();
    const vector<LigneCommande>& getLignes() const;
    
    // Setters
    void setIdCommande(int id);
    void setIdClient(int id);
    void setIdServeur(int id);
    void setIdCuisinier(int id);
    void setDate(const string& date);
    void setHeure(const string& heure);
    void setEtat(EtatCommande etat);
    
    // Méthodes
    void ajouterProduit(const Produit& produit, int quantite);
    void calculerTotal();
    void afficher() const;
    string etatToString() const;
    static string getCurrentDate();
    static string getCurrentTime();
    
    // Opérateurs
    bool operator==(const Commande& autre) const;
};

#endif // COMMANDE_H

