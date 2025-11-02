#include "../include/Produit.h"
#include <iostream>
#include <iomanip>
using namespace std;

Produit::Produit() : idProduit(0), nom(""), prix(0.0), categorie(""), stock(0) {}

Produit::Produit(int id, const string& nom, double prix, 
                 const string& categorie, int stock)
    : idProduit(id), nom(nom), prix(prix), categorie(categorie), stock(stock) {}

int Produit::getIdProduit() const {
    return idProduit;
}

string Produit::getNom() const {
    return nom;
}

double Produit::getPrix() const {
    return prix;
}

string Produit::getCategorie() const {
    return categorie;
}

int Produit::getStock() const {
    return stock;
}

void Produit::setIdProduit(int id) {
    idProduit = id;
}

void Produit::setNom(const string& nom) {
    this->nom = nom;
}

void Produit::setPrix(double prix) {
    this->prix = prix;
}

void Produit::setCategorie(const string& categorie) {
    this->categorie = categorie;
}

void Produit::setStock(int stock) {
    this->stock = stock;
}

bool Produit::estDisponible(int quantite) const {
    return stock >= quantite;
}

bool Produit::retirerStock(int quantite) {
    if (quantite > 0 && stock >= quantite) {
        stock -= quantite;
        return true;
    }
    return false;
}

void Produit::ajouterStock(int quantite) {
    if (quantite > 0) {
        stock += quantite;
    }
}

void Produit::afficher() const {
    cout << "ID: " << idProduit << " | "
         << nom << " | "
         << "Prix: " << fixed << setprecision(2) << prix << " DH | "
         << "Catégorie: " << categorie << " | "
         << "Stock: " << stock << endl;
}

bool Produit::operator==(const Produit& autre) const {
    return idProduit == autre.idProduit;
}

