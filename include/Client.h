#ifndef CLIENT_H
#define CLIENT_H

#include <string>
using namespace std;

class Client {
private:
    int idClient;
    string nom;
    string prenom;
    string email;
    double solde;

public:
    Client();
    Client(int id, const string& nom, const string& prenom, 
           const string& email, double solde = 0.0);
    
    // Getters
    int getIdClient() const;
    string getNom() const;
    string getPrenom() const;
    string getEmail() const;
    double getSolde() const;
    
    // Setters
    void setIdClient(int id);
    void setNom(const string& nom);
    void setPrenom(const string& prenom);
    void setEmail(const string& email);
    void setSolde(double solde);
    
    // Méthodes
    void crediter(double montant);
    bool debiter(double montant);
    void afficher() const;
    
    // Opérateurs
    bool operator==(const Client& autre) const;
};

#endif // CLIENT_H

