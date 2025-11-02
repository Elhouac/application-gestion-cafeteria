#include "../include/Personnel.h"
#include <iostream>
using namespace std;

// Personnel de base
Personnel::Personnel() : id(0), nom(""), prenom("") {}

Personnel::Personnel(int id, const string& nom, const string& prenom)
    : id(id), nom(nom), prenom(prenom) {}

int Personnel::getId() const {
    return id;
}

string Personnel::getNom() const {
    return nom;
}

string Personnel::getPrenom() const {
    return prenom;
}

void Personnel::setId(int id) {
    this->id = id;
}

void Personnel::setNom(const string& nom) {
    this->nom = nom;
}

void Personnel::setPrenom(const string& prenom) {
    this->prenom = prenom;
}

void Personnel::afficher() const {
    cout << "ID: " << id << " | " << prenom << " " << nom << endl;
}

bool Personnel::operator==(const Personnel& autre) const {
    return id == autre.id;
}

// Serveur
Serveur::Serveur() : Personnel() {}

Serveur::Serveur(int id, const string& nom, const string& prenom)
    : Personnel(id, nom, prenom) {}

void Serveur::afficher() const {
    cout << "[SERVEUR] ID: " << id << " | " << prenom << " " << nom << endl;
}

// Cuisinier
Cuisinier::Cuisinier() : Personnel() {}

Cuisinier::Cuisinier(int id, const string& nom, const string& prenom)
    : Personnel(id, nom, prenom) {}

void Cuisinier::afficher() const {
    cout << "[CUISINIER] ID: " << id << " | " << prenom << " " << nom << endl;
}

// Caissier
Caissier::Caissier() : Personnel() {}

Caissier::Caissier(int id, const string& nom, const string& prenom)
    : Personnel(id, nom, prenom) {}

void Caissier::afficher() const {
    cout << "[CAISSIER] ID: " << id << " | " << prenom << " " << nom << endl;
}

// Responsable
Responsable::Responsable() : Personnel() {}

Responsable::Responsable(int id, const string& nom, const string& prenom)
    : Personnel(id, nom, prenom) {}

void Responsable::afficher() const {
    cout << "[RESPONSABLE] ID: " << id << " | " << prenom << " " << nom << endl;
}

