#ifndef GESTION_CAFETERIA_H
#define GESTION_CAFETERIA_H

#include <vector>
#include <string>
#include "Client.h"
#include "Produit.h"
#include "Commande.h"
#include "Personnel.h"
using namespace std;

class GestionCafeteria {
private:
    vector<Client> clients;
    vector<Produit> produits;
    vector<Commande> commandes;
    vector<Serveur> serveurs;
    vector<Cuisinier> cuisiniers;
    vector<Caissier> caissiers;
    vector<Responsable> responsables;
    
    int dernierIdClient;
    int dernierIdProduit;
    int dernierIdCommande;
    int dernierIdServeur;
    int dernierIdCuisinier;
    int dernierIdCaissier;
    int dernierIdResponsable;

public:
    GestionCafeteria();
    
    // Gestion des clients
    void ajouterClient(const string& nom, const string& prenom, const string& email, double solde = 0.0);
    Client* trouverClient(int id);
    void listerClients() const;
    
    // Gestion des produits
    void ajouterProduit(const string& nom, double prix, const string& categorie, int stock);
    Produit* trouverProduit(int id);
    void listerProduits() const;
    void modifierProduit(int id, const string& nom, double prix, const string& categorie, int stock);
    
    // Gestion des commandes
    void creerCommande(int idClient, int idServeur);
    Commande* trouverCommande(int id);
    void listerCommandes() const;
    void listerCommandesParClient(int idClient) const;
    void listerCommandesParServeur(int idServeur) const;
    void listerCommandesParCuisinier(int idCuisinier) const;
    void changerEtatCommande(int idCommande, EtatCommande nouvelEtat);
    void assignerCuisinier(int idCommande, int idCuisinier);
    
    // Gestion du personnel
    void ajouterServeur(const string& nom, const string& prenom);
    void ajouterCuisinier(const string& nom, const string& prenom);
    void ajouterCaissier(const string& nom, const string& prenom);
    void ajouterResponsable(const string& nom, const string& prenom);
    
    Serveur* trouverServeur(int id);
    Cuisinier* trouverCuisinier(int id);
    Caissier* trouverCaissier(int id);
    Responsable* trouverResponsable(int id);
    
    void listerServeurs() const;
    void listerCuisiniers() const;
    void listerCaissiers() const;
    void listerResponsables() const;
    
    // Sauvegarde et chargement
    void sauvegarderDonnees() const;
    void chargerDonnees();
    
    // Statistiques
    void afficherStatistiques() const;
};

#endif // GESTION_CAFETERIA_H

