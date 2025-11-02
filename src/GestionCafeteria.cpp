#include "../include/GestionCafeteria.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

GestionCafeteria::GestionCafeteria()
    : dernierIdClient(0), dernierIdProduit(0), dernierIdCommande(0),
      dernierIdServeur(0), dernierIdCuisinier(0), dernierIdCaissier(0), dernierIdResponsable(0) {}

// Gestion des clients
void GestionCafeteria::ajouterClient(const string& nom, const string& prenom, 
                                     const string& email, double solde) {
    dernierIdClient++;
    clients.push_back(Client(dernierIdClient, nom, prenom, email, solde));
    cout << "Client ajouté avec succès! ID: " << dernierIdClient << endl;
}

Client* GestionCafeteria::trouverClient(int id) {
    auto it = find_if(clients.begin(), clients.end(),
        [id](const Client& c) { return c.getIdClient() == id; });
    return (it != clients.end()) ? &(*it) : nullptr;
}

void GestionCafeteria::listerClients() const {
    cout << "\n=== Liste des Clients ===" << endl;
    if (clients.empty()) {
        cout << "Aucun client enregistré." << endl;
        return;
    }
    for (const auto& client : clients) {
        client.afficher();
    }
}

// Gestion des produits
void GestionCafeteria::ajouterProduit(const string& nom, double prix, 
                                       const string& categorie, int stock) {
    dernierIdProduit++;
    produits.push_back(Produit(dernierIdProduit, nom, prix, categorie, stock));
    cout << "Produit ajouté avec succès! ID: " << dernierIdProduit << endl;
}

Produit* GestionCafeteria::trouverProduit(int id) {
    auto it = find_if(produits.begin(), produits.end(),
        [id](const Produit& p) { return p.getIdProduit() == id; });
    return (it != produits.end()) ? &(*it) : nullptr;
}

void GestionCafeteria::listerProduits() const {
    cout << "\n=== Liste des Produits ===" << endl;
    if (produits.empty()) {
        cout << "Aucun produit enregistré." << endl;
        return;
    }
    for (const auto& produit : produits) {
        produit.afficher();
    }
}

void GestionCafeteria::modifierProduit(int id, const string& nom, double prix, 
                                       const string& categorie, int stock) {
    Produit* produit = trouverProduit(id);
    if (produit) {
        produit->setNom(nom);
        produit->setPrix(prix);
        produit->setCategorie(categorie);
        produit->setStock(stock);
        cout << "Produit modifié avec succès!" << endl;
    } else {
        cout << "Produit introuvable!" << endl;
    }
}

// Gestion des commandes
void GestionCafeteria::creerCommande(int idClient, int idServeur) {
    if (!trouverClient(idClient)) {
        cout << "Client introuvable!" << endl;
        return;
    }
    if (!trouverServeur(idServeur)) {
        cout << "Serveur introuvable!" << endl;
        return;
    }
    
    dernierIdCommande++;
    Commande cmd(dernierIdCommande, idClient, idServeur, 
                 Commande::getCurrentDate(), Commande::getCurrentTime());
    commandes.push_back(cmd);
    cout << "Commande créée avec succès! ID: " << dernierIdCommande << endl;
}

Commande* GestionCafeteria::trouverCommande(int id) {
    auto it = find_if(commandes.begin(), commandes.end(),
        [id](const Commande& c) { return c.getIdCommande() == id; });
    return (it != commandes.end()) ? &(*it) : nullptr;
}

void GestionCafeteria::listerCommandes() const {
    cout << "\n=== Liste des Commandes ===" << endl;
    if (commandes.empty()) {
        cout << "Aucune commande enregistrée." << endl;
        return;
    }
    for (const auto& commande : commandes) {
        commande.afficher();
    }
}

void GestionCafeteria::listerCommandesParClient(int idClient) const {
    cout << "\n=== Commandes du Client #" << idClient << " ===" << endl;
    bool trouve = false;
    for (const auto& commande : commandes) {
        if (commande.getIdClient() == idClient) {
            commande.afficher();
            trouve = true;
        }
    }
    if (!trouve) {
        cout << "Aucune commande trouvée pour ce client." << endl;
    }
}

void GestionCafeteria::listerCommandesParServeur(int idServeur) const {
    cout << "\n=== Commandes du Serveur #" << idServeur << " ===" << endl;
    bool trouve = false;
    for (const auto& commande : commandes) {
        if (commande.getIdServeur() == idServeur) {
            commande.afficher();
            trouve = true;
        }
    }
    if (!trouve) {
        cout << "Aucune commande trouvée pour ce serveur." << endl;
    }
}

void GestionCafeteria::listerCommandesParCuisinier(int idCuisinier) const {
    cout << "\n=== Commandes du Cuisinier #" << idCuisinier << " ===" << endl;
    bool trouve = false;
    for (const auto& commande : commandes) {
        if (commande.getIdCuisinier() == idCuisinier) {
            commande.afficher();
            trouve = true;
        }
    }
    if (!trouve) {
        cout << "Aucune commande trouvée pour ce cuisinier." << endl;
    }
}

void GestionCafeteria::changerEtatCommande(int idCommande, EtatCommande nouvelEtat) {
    Commande* cmd = trouverCommande(idCommande);
    if (cmd) {
        cmd->setEtat(nouvelEtat);
        cout << "État de la commande modifié avec succès!" << endl;
    } else {
        cout << "Commande introuvable!" << endl;
    }
}

void GestionCafeteria::assignerCuisinier(int idCommande, int idCuisinier) {
    Commande* cmd = trouverCommande(idCommande);
    if (!cmd) {
        cout << "Commande introuvable!" << endl;
        return;
    }
    if (!trouverCuisinier(idCuisinier)) {
        cout << "Cuisinier introuvable!" << endl;
        return;
    }
    cmd->setIdCuisinier(idCuisinier);
    cmd->setEtat(EtatCommande::EN_PREPARATION);
    cout << "Cuisinier assigné avec succès!" << endl;
}

// Gestion du personnel
void GestionCafeteria::ajouterServeur(const string& nom, const string& prenom) {
    dernierIdServeur++;
    serveurs.push_back(Serveur(dernierIdServeur, nom, prenom));
    cout << "Serveur ajouté avec succès! ID: " << dernierIdServeur << endl;
}

void GestionCafeteria::ajouterCuisinier(const string& nom, const string& prenom) {
    dernierIdCuisinier++;
    cuisiniers.push_back(Cuisinier(dernierIdCuisinier, nom, prenom));
    cout << "Cuisinier ajouté avec succès! ID: " << dernierIdCuisinier << endl;
}

void GestionCafeteria::ajouterCaissier(const string& nom, const string& prenom) {
    dernierIdCaissier++;
    caissiers.push_back(Caissier(dernierIdCaissier, nom, prenom));
    cout << "Caissier ajouté avec succès! ID: " << dernierIdCaissier << endl;
}

void GestionCafeteria::ajouterResponsable(const string& nom, const string& prenom) {
    dernierIdResponsable++;
    responsables.push_back(Responsable(dernierIdResponsable, nom, prenom));
    cout << "Responsable ajouté avec succès! ID: " << dernierIdResponsable << endl;
}

Serveur* GestionCafeteria::trouverServeur(int id) {
    auto it = find_if(serveurs.begin(), serveurs.end(),
        [id](const Serveur& s) { return s.getId() == id; });
    return (it != serveurs.end()) ? &(*it) : nullptr;
}

Cuisinier* GestionCafeteria::trouverCuisinier(int id) {
    auto it = find_if(cuisiniers.begin(), cuisiniers.end(),
        [id](const Cuisinier& c) { return c.getId() == id; });
    return (it != cuisiniers.end()) ? &(*it) : nullptr;
}

Caissier* GestionCafeteria::trouverCaissier(int id) {
    auto it = find_if(caissiers.begin(), caissiers.end(),
        [id](const Caissier& c) { return c.getId() == id; });
    return (it != caissiers.end()) ? &(*it) : nullptr;
}

Responsable* GestionCafeteria::trouverResponsable(int id) {
    auto it = find_if(responsables.begin(), responsables.end(),
        [id](const Responsable& r) { return r.getId() == id; });
    return (it != responsables.end()) ? &(*it) : nullptr;
}

void GestionCafeteria::listerServeurs() const {
    cout << "\n=== Liste des Serveurs ===" << endl;
    if (serveurs.empty()) {
        cout << "Aucun serveur enregistré." << endl;
        return;
    }
    for (const auto& serveur : serveurs) {
        serveur.afficher();
    }
}

void GestionCafeteria::listerCuisiniers() const {
    cout << "\n=== Liste des Cuisiniers ===" << endl;
    if (cuisiniers.empty()) {
        cout << "Aucun cuisinier enregistré." << endl;
        return;
    }
    for (const auto& cuisinier : cuisiniers) {
        cuisinier.afficher();
    }
}

void GestionCafeteria::listerCaissiers() const {
    cout << "\n=== Liste des Caissiers ===" << endl;
    if (caissiers.empty()) {
        cout << "Aucun caissier enregistré." << endl;
        return;
    }
    for (const auto& caissier : caissiers) {
        caissier.afficher();
    }
}

void GestionCafeteria::listerResponsables() const {
    cout << "\n=== Liste des Responsables ===" << endl;
    if (responsables.empty()) {
        cout << "Aucun responsable enregistré." << endl;
        return;
    }
    for (const auto& responsable : responsables) {
        responsable.afficher();
    }
}

void GestionCafeteria::afficherStatistiques() const {
    cout << "\n=== Statistiques de la Cafétéria ===" << endl;
    cout << "Nombre de clients: " << clients.size() << endl;
    cout << "Nombre de produits: " << produits.size() << endl;
    cout << "Nombre de commandes: " << commandes.size() << endl;
    cout << "Nombre de serveurs: " << serveurs.size() << endl;
    cout << "Nombre de cuisiniers: " << cuisiniers.size() << endl;
    cout << "Nombre de caissiers: " << caissiers.size() << endl;
    cout << "Nombre de responsables: " << responsables.size() << endl;
    
    double totalCommandes = 0.0;
    for (const auto& cmd : commandes) {
        totalCommandes += cmd.getTotal();
    }
    cout << "Chiffre d'affaires total: " << fixed << setprecision(2) 
         << totalCommandes << " DH" << endl;
}

void GestionCafeteria::sauvegarderDonnees() const {
    // Implémentation simplifiée - peut être améliorée avec JSON ou base de données
    cout << "Sauvegarde des données..." << endl;
    // TODO: Implémenter la sauvegarde dans des fichiers
}

void GestionCafeteria::chargerDonnees() {
    cout << "Chargement des données..." << endl;
    // TODO: Implémenter le chargement depuis des fichiers
}

