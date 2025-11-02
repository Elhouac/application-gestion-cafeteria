#include "../include/Client.h"
#include <iostream>
#include <iomanip>
using namespace std;

Client::Client() : idClient(0), nom(""), prenom(""), email(""), solde(0.0) {}

Client::Client(int id, const string& nom, const string& prenom, 
               const string& email, double solde)
    : idClient(id), nom(nom), prenom(prenom), email(email), solde(solde) {}

int Client::getIdClient() const {
    return idClient;
}

string Client::getNom() const {
    return nom;
}

string Client::getPrenom() const {
    return prenom;
}

string Client::getEmail() const {
    return email;
}

double Client::getSolde() const {
    return solde;
}

void Client::setIdClient(int id) {
    idClient = id;
}

void Client::setNom(const string& nom) {
    this->nom = nom;
}

void Client::setPrenom(const string& prenom) {
    this->prenom = prenom;
}

void Client::setEmail(const string& email) {
    this->email = email;
}

void Client::setSolde(double solde) {
    this->solde = solde;
}

void Client::crediter(double montant) {
    if (montant > 0) {
        solde += montant;
    }
}

bool Client::debiter(double montant) {
    if (montant > 0 && montant <= solde) {
        solde -= montant;
        return true;
    }
    return false;
}

void Client::afficher() const {
    cout << "ID: " << idClient << " | "
         << prenom << " " << nom << " | "
         << "Email: " << email << " | "
         << "Solde: " << fixed << setprecision(2) << solde << " DH" << endl;
}

bool Client::operator==(const Client& autre) const {
    return idClient == autre.idClient;
}

