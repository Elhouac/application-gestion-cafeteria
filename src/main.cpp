#include "../include/GestionCafeteria.h"
#include <iostream>
#include <limits>
using namespace std;

void afficherMenuPrincipal() {
    cout << "\n╔════════════════════════════════════════╗" << endl;
    cout << "║     SYSTÈME DE GESTION CAFETERIA       ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;
    cout << "\n1.  Gestion des Clients" << endl;
    cout << "2.  Gestion des Produits" << endl;
    cout << "3.  Gestion des Commandes" << endl;
    cout << "4.  Gestion du Personnel" << endl;
    cout << "5.  Statistiques" << endl;
    cout << "6.  Données de démonstration" << endl;
    cout << "0.  Quitter" << endl;
    cout << "\nVotre choix: ";
}

void afficherMenuClient() {
    cout << "\n=== GESTION DES CLIENTS ===" << endl;
    cout << "1. Ajouter un client" << endl;
    cout << "2. Lister les clients" << endl;
    cout << "3. Créditer un client" << endl;
    cout << "0. Retour" << endl;
    cout << "Votre choix: ";
}

void afficherMenuProduit() {
    cout << "\n=== GESTION DES PRODUITS ===" << endl;
    cout << "1. Ajouter un produit" << endl;
    cout << "2. Lister les produits" << endl;
    cout << "3. Modifier un produit" << endl;
    cout << "0. Retour" << endl;
    cout << "Votre choix: ";
}

void afficherMenuCommande() {
    cout << "\n=== GESTION DES COMMANDES ===" << endl;
    cout << "1. Créer une commande" << endl;
    cout << "2. Ajouter un produit à une commande" << endl;
    cout << "3. Lister toutes les commandes" << endl;
    cout << "4. Lister commandes par client" << endl;
    cout << "5. Lister commandes par serveur" << endl;
    cout << "6. Changer l'état d'une commande" << endl;
    cout << "7. Assigner un cuisinier à une commande" << endl;
    cout << "0. Retour" << endl;
    cout << "Votre choix: ";
}

void afficherMenuPersonnel() {
    cout << "\n=== GESTION DU PERSONNEL ===" << endl;
    cout << "1. Ajouter un serveur" << endl;
    cout << "2. Ajouter un cuisinier" << endl;
    cout << "3. Ajouter un caissier" << endl;
    cout << "4. Ajouter un responsable" << endl;
    cout << "5. Lister les serveurs" << endl;
    cout << "6. Lister les cuisiniers" << endl;
    cout << "7. Lister les caissiers" << endl;
    cout << "8. Lister les responsables" << endl;
    cout << "0. Retour" << endl;
    cout << "Votre choix: ";
}

void chargerDonneesDemo(GestionCafeteria& gestion) {
    // Clients de démonstration
    gestion.ajouterClient("Amrani", "Sara", "sara.amrani@emsi-edu.ma", 500.0);
    gestion.ajouterClient("Alami", "Ahmed", "ahmed.alami@emsi-edu.ma", 300.0);
    gestion.ajouterClient("Bennani", "Fatima", "fatima.bennani@emsi-edu.ma", 200.0);
    
    // Produits de démonstration
    gestion.ajouterProduit("Café", 8.0, "Boissons", 100);
    gestion.ajouterProduit("Thé", 6.0, "Boissons", 80);
    gestion.ajouterProduit("Sandwich", 25.0, "Plats", 50);
    gestion.ajouterProduit("Pizza", 45.0, "Plats", 30);
    gestion.ajouterProduit("Salade", 18.0, "Plats", 40);
    gestion.ajouterProduit("Gâteau", 15.0, "Desserts", 60);
    
    // Personnel de démonstration
    gestion.ajouterServeur("Tazi", "Hassan", "Hassan");
    gestion.ajouterServeur("Bennani", "Aicha", "Aicha");
    
    gestion.ajouterCuisinier("Alaoui", "Mohammed", "Mohammed");
    gestion.ajouterCuisinier("Idrissi", "Khadija", "Khadija");
    
    gestion.ajouterCaissier("Fassi", "Youssef", "Youssef");
    
    gestion.ajouterResponsable("El Amrani", "Said", "Said");
    
    cout << "\n✓ Données de démonstration chargées avec succès!" << endl;
}

void gererClients(GestionCafeteria& gestion) {
    int choix;
    do {
        afficherMenuClient();
        cin >> choix;
        cin.ignore();
        
        if (choix == 1) {
            string nom, prenom, email;
            double solde;
            cout << "Nom: ";
            getline(cin, nom);
            cout << "Prénom: ";
            getline(cin, prenom);
            cout << "Email: ";
            getline(cin, email);
            cout << "Solde initial: ";
            cin >> solde;
            gestion.ajouterClient(nom, prenom, email, solde);
        } else if (choix == 2) {
            gestion.listerClients();
        } else if (choix == 3) {
            int id;
            double montant;
            cout << "ID du client: ";
            cin >> id;
            Client* client = gestion.trouverClient(id);
            if (client) {
                cout << "Montant à créditer: ";
                cin >> montant;
                client->crediter(montant);
                cout << "Client crédité avec succès!" << endl;
            } else {
                cout << "Client introuvable!" << endl;
            }
        }
    } while (choix != 0);
}

void gererProduits(GestionCafeteria& gestion) {
    int choix;
    do {
        afficherMenuProduit();
        cin >> choix;
        cin.ignore();
        
        if (choix == 1) {
            string nom, categorie;
            double prix;
            int stock;
            cout << "Nom: ";
            getline(cin, nom);
            cout << "Prix: ";
            cin >> prix;
            cin.ignore();
            cout << "Catégorie: ";
            getline(cin, categorie);
            cout << "Stock: ";
            cin >> stock;
            gestion.ajouterProduit(nom, prix, categorie, stock);
        } else if (choix == 2) {
            gestion.listerProduits();
        } else if (choix == 3) {
            int id;
            string nom, categorie;
            double prix;
            int stock;
            cout << "ID du produit: ";
            cin >> id;
            cin.ignore();
            cout << "Nouveau nom: ";
            getline(cin, nom);
            cout << "Nouveau prix: ";
            cin >> prix;
            cin.ignore();
            cout << "Nouvelle catégorie: ";
            getline(cin, categorie);
            cout << "Nouveau stock: ";
            cin >> stock;
            gestion.modifierProduit(id, nom, prix, categorie, stock);
        }
    } while (choix != 0);
}

void gererCommandes(GestionCafeteria& gestion) {
    int choix;
    do {
        afficherMenuCommande();
        cin >> choix;
        cin.ignore();
        
        if (choix == 1) {
            int idClient, idServeur;
            cout << "ID du client: ";
            cin >> idClient;
            cout << "ID du serveur: ";
            cin >> idServeur;
            gestion.creerCommande(idClient, idServeur);
        } else if (choix == 2) {
            int idCommande, idProduit, quantite;
            cout << "ID de la commande: ";
            cin >> idCommande;
            Commande* cmd = gestion.trouverCommande(idCommande);
            if (cmd) {
                cout << "ID du produit: ";
                cin >> idProduit;
                Produit* produit = gestion.trouverProduit(idProduit);
                if (produit) {
                    cout << "Quantité: ";
                    cin >> quantite;
                    if (produit->estDisponible(quantite)) {
                        cmd->ajouterProduit(*produit, quantite);
                        produit->retirerStock(quantite);
                        cout << "Produit ajouté à la commande!" << endl;
                    } else {
                        cout << "Stock insuffisant!" << endl;
                    }
                } else {
                    cout << "Produit introuvable!" << endl;
                }
            } else {
                cout << "Commande introuvable!" << endl;
            }
        } else if (choix == 3) {
            gestion.listerCommandes();
        } else if (choix == 4) {
            int idClient;
            cout << "ID du client: ";
            cin >> idClient;
            gestion.listerCommandesParClient(idClient);
        } else if (choix == 5) {
            int idServeur;
            cout << "ID du serveur: ";
            cin >> idServeur;
            gestion.listerCommandesParServeur(idServeur);
        } else if (choix == 6) {
            int idCommande, etat;
            cout << "ID de la commande: ";
            cin >> idCommande;
            cout << "Nouvel état (0=En attente, 1=En préparation, 2=Prête, 3=Servie, 4=Annulée): ";
            cin >> etat;
            gestion.changerEtatCommande(idCommande, static_cast<EtatCommande>(etat));
        } else if (choix == 7) {
            int idCommande, idCuisinier;
            cout << "ID de la commande: ";
            cin >> idCommande;
            cout << "ID du cuisinier: ";
            cin >> idCuisinier;
            gestion.assignerCuisinier(idCommande, idCuisinier);
        }
    } while (choix != 0);
}

void gererPersonnel(GestionCafeteria& gestion) {
    int choix;
    do {
        afficherMenuPersonnel();
        cin >> choix;
        cin.ignore();
        
        if (choix == 1) {
            string nom, prenom;
            cout << "Nom: ";
            getline(cin, nom);
            cout << "Prénom: ";
            getline(cin, prenom);
            gestion.ajouterServeur(nom, prenom);
        } else if (choix == 2) {
            string nom, prenom;
            cout << "Nom: ";
            getline(cin, nom);
            cout << "Prénom: ";
            getline(cin, prenom);
            gestion.ajouterCuisinier(nom, prenom);
        } else if (choix == 3) {
            string nom, prenom;
            cout << "Nom: ";
            getline(cin, nom);
            cout << "Prénom: ";
            getline(cin, prenom);
            gestion.ajouterCaissier(nom, prenom);
        } else if (choix == 4) {
            string nom, prenom;
            cout << "Nom: ";
            getline(cin, nom);
            cout << "Prénom: ";
            getline(cin, prenom);
            gestion.ajouterResponsable(nom, prenom);
        } else if (choix == 5) {
            gestion.listerServeurs();
        } else if (choix == 6) {
            gestion.listerCuisiniers();
        } else if (choix == 7) {
            gestion.listerCaissiers();
        } else if (choix == 8) {
            gestion.listerResponsables();
        }
    } while (choix != 0);
}

int main() {
    GestionCafeteria gestion;
    int choix;
    
    cout << "Bienvenue dans le Système de Gestion de Cafétéria!" << endl;
    
    do {
        afficherMenuPrincipal();
        cin >> choix;
        cin.ignore();
        
        switch (choix) {
            case 1:
                gererClients(gestion);
                break;
            case 2:
                gererProduits(gestion);
                break;
            case 3:
                gererCommandes(gestion);
                break;
            case 4:
                gererPersonnel(gestion);
                break;
            case 5:
                gestion.afficherStatistiques();
                break;
            case 6:
                chargerDonneesDemo(gestion);
                break;
            case 0:
                cout << "\nMerci d'avoir utilisé le système. Au revoir!" << endl;
                break;
            default:
                cout << "Choix invalide!" << endl;
                break;
        }
    } while (choix != 0);
    
    return 0;
}

