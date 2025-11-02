#ifndef PERSONNEL_H
#define PERSONNEL_H

#include <string>
using namespace std;

class Personnel {
protected:
    int id;
    string nom;
    string prenom;

public:
    Personnel();
    Personnel(int id, const string& nom, const string& prenom);
    
    // Getters
    int getId() const;
    string getNom() const;
    string getPrenom() const;
    
    // Setters
    void setId(int id);
    void setNom(const string& nom);
    void setPrenom(const string& prenom);
    
    // Méthodes
    virtual void afficher() const;
    bool operator==(const Personnel& autre) const;
};

class Serveur : public Personnel {
public:
    Serveur();
    Serveur(int id, const string& nom, const string& prenom);
    void afficher() const override;
};

class Cuisinier : public Personnel {
public:
    Cuisinier();
    Cuisinier(int id, const string& nom, const string& prenom);
    void afficher() const override;
};

class Caissier : public Personnel {
public:
    Caissier();
    Caissier(int id, const string& nom, const string& prenom);
    void afficher() const override;
};

class Responsable : public Personnel {
public:
    Responsable();
    Responsable(int id, const string& nom, const string& prenom);
    void afficher() const override;
};

#endif // PERSONNEL_H

