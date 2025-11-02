#include "../include/Commande.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>
using namespace std;

Commande::Commande() 
    : idCommande(0), idClient(0), idServeur(0), idCuisinier(0),
      date(""), heure(""), etat(EtatCommande::EN_ATTENTE), total(0.0) {}

Commande::Commande(int id, int idClient, int idServeur, const string& date, const string& heure)
    : idCommande(id), idClient(idClient), idServeur(idServeur), idCuisinier(0),
      date(date), heure(heure), etat(EtatCommande::EN_ATTENTE), total(0.0) {}

int Commande::getIdCommande() const {
    return idCommande;
}

int Commande::getIdClient() const {
    return idClient;
}

int Commande::getIdServeur() const {
    return idServeur;
}

int Commande::getIdCuisinier() const {
    return idCuisinier;
}

string Commande::getDate() const {
    return date;
}

string Commande::getHeure() const {
    return heure;
}

EtatCommande Commande::getEtat() const {
    return etat;
}

double Commande::getTotal() const {
    return total;
}

vector<LigneCommande>& Commande::getLignes() {
    return lignes;
}

const vector<LigneCommande>& Commande::getLignes() const {
    return lignes;
}

void Commande::setIdCommande(int id) {
    idCommande = id;
}

void Commande::setIdClient(int id) {
    idClient = id;
}

void Commande::setIdServeur(int id) {
    idServeur = id;
}

void Commande::setIdCuisinier(int id) {
    idCuisinier = id;
}

void Commande::setDate(const string& date) {
    this->date = date;
}

void Commande::setHeure(const string& heure) {
    this->heure = heure;
}

void Commande::setEtat(EtatCommande etat) {
    this->etat = etat;
}

void Commande::ajouterProduit(const Produit& produit, int quantite) {
    if (quantite > 0 && produit.estDisponible(quantite)) {
        lignes.push_back(LigneCommande(produit, quantite));
        calculerTotal();
    }
}

void Commande::calculerTotal() {
    total = 0.0;
    for (const auto& ligne : lignes) {
        total += ligne.prixUnitaire * ligne.quantite;
    }
}

void Commande::afficher() const {
    cout << "\n=== Commande #" << idCommande << " ===" << endl;
    cout << "Date: " << date << " | Heure: " << heure << endl;
    cout << "Client ID: " << idClient << " | Serveur ID: " << idServeur << endl;
    cout << "État: " << etatToString() << endl;
    cout << "\nProduits:" << endl;
    for (const auto& ligne : lignes) {
        cout << "  - " << ligne.produit.getNom() 
             << " x" << ligne.quantite 
             << " (" << fixed << setprecision(2) 
             << ligne.prixUnitaire << " DH)" << endl;
    }
    cout << "\nTotal: " << fixed << setprecision(2) << total << " DH" << endl;
}

string Commande::etatToString() const {
    switch (etat) {
        case EtatCommande::EN_ATTENTE: return "En attente";
        case EtatCommande::EN_PREPARATION: return "En préparation";
        case EtatCommande::PRETE: return "Prête";
        case EtatCommande::SERVIE: return "Servie";
        case EtatCommande::ANNULEE: return "Annulée";
        default: return "Inconnu";
    }
}

string Commande::getCurrentDate() {
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    ostringstream oss;
    oss << (now->tm_year + 1900) << "-"
        << setfill('0') << setw(2) << (now->tm_mon + 1) << "-"
        << setfill('0') << setw(2) << now->tm_mday;
    return oss.str();
}

string Commande::getCurrentTime() {
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    ostringstream oss;
    oss << setfill('0') << setw(2) << now->tm_hour << ":"
        << setfill('0') << setw(2) << now->tm_min << ":"
        << setfill('0') << setw(2) << now->tm_sec;
    return oss.str();
}

bool Commande::operator==(const Commande& autre) const {
    return idCommande == autre.idCommande;
}

