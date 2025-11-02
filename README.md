# Application de Gestion de Cafétéria - C++

Application complète de gestion de cafétéria développée en C++ selon un diagramme UML spécifique. Le système permet de gérer les clients, produits, commandes et le personnel de la cafétéria.

## 📋 Structure du Projet

```
cafeteria_cpp/
├── include/           # Fichiers d'en-tête (.h)
│   ├── Client.h
│   ├── Produit.h
│   ├── Commande.h
│   ├── Personnel.h
│   └── GestionCafeteria.h
├── src/              # Fichiers source (.cpp)
│   ├── Client.cpp
│   ├── Produit.cpp
│   ├── Commande.cpp
│   ├── Personnel.cpp
│   ├── GestionCafeteria.cpp
│   └── main.cpp
├── Makefile          # Fichier de compilation
└── README.md         # Ce fichier
```

## 🏗️ Architecture

### Classes Principales

1. **Client**
   - Attributs: id, nom, prenom, email, solde
   - Fonctionnalités: créditer/débiter le solde

2. **Produit**
   - Attributs: id, nom, prix, categorie, stock
   - Fonctionnalités: gestion du stock

3. **Commande**
   - Attributs: id, date, heure, etat, total
   - Relations: Client, Serveur, Cuisinier, Produits
   - États: EN_ATTENTE, EN_PREPARATION, PRETE, SERVIE, ANNULEE

4. **Personnel** (classe de base)
   - Attributs: id, nom, prenom
   - Classes dérivées:
     - **Serveur**: Prend les commandes, sert les clients
     - **Cuisinier**: Prépare les commandes
     - **Caissier**: Gère les transactions
     - **Responsable**: Modifie les produits, reçoit les rapports

5. **GestionCafeteria**
   - Classe principale qui orchestre toutes les opérations
   - Gestion centralisée de toutes les entités

## 🔧 Compilation et Exécution

### Prérequis
- Compilateur C++ compatible C++11 (g++, clang++, etc.)
- Make (optionnel, mais recommandé)

### Compilation avec Makefile

```bash
# Compiler le projet
make

# Compiler et exécuter
make run

# Nettoyer les fichiers générés
make clean

# Afficher l'aide
make help
```

### Compilation manuelle

```bash
# Créer les dossiers nécessaires
mkdir -p obj bin

# Compiler tous les fichiers source
g++ -std=c++11 -Wall -Wextra -O2 -Iinclude -c src/*.cpp -o obj/*.o

# Lier tous les objets
g++ obj/*.o -o bin/cafeteria

# Exécuter
./bin/cafeteria
```

### Compilation sur Windows

#### Option 1: Script automatique (recommandé)
```batch
compile.bat
```

#### Option 2: MinGW manuellement
```batch
# Créer les dossiers
mkdir obj bin

# Compiler tous les fichiers
g++ -std=c++11 -Wall -Wextra -O2 -Iinclude -c src\*.cpp

# Lier et créer l'exécutable
g++ obj\*.o -o bin\cafeteria.exe

# Exécuter
bin\cafeteria.exe
```

#### Option 3: Visual Studio
- Ouvrir le dossier comme projet
- Configurer les include directories (include/)
- Ajouter tous les fichiers .cpp de src/ au projet
- Compiler et exécuter

## 🚀 Utilisation

### Menu Principal

1. **Gestion des Clients**
   - Ajouter un client
   - Lister les clients
   - Créditer un client

2. **Gestion des Produits**
   - Ajouter un produit
   - Lister les produits
   - Modifier un produit (nom, prix, catégorie, stock)

3. **Gestion des Commandes**
   - Créer une commande
   - Ajouter des produits à une commande
   - Lister toutes les commandes
   - Lister les commandes par client/serveur
   - Changer l'état d'une commande
   - Assigner un cuisinier à une commande

4. **Gestion du Personnel**
   - Ajouter serveur, cuisinier, caissier, responsable
   - Lister chaque type de personnel

5. **Statistiques**
   - Afficher le nombre d'entités
   - Afficher le chiffre d'affaires total

6. **Données de démonstration**
   - Charger des exemples pour tester l'application

## 📊 Relations UML Implémentées

- ✅ Client → Commande (1 à plusieurs)
- ✅ Client ↔ Serveur (plusieurs à un)
- ✅ Serveur → Commande (1 à plusieurs)
- ✅ Serveur → Cuisinier (transmission de commandes)
- ✅ Serveur → Caissier (transmission d'informations)
- ✅ Commande → Cuisinier (préparation)
- ✅ Commande → Produit (1 à plusieurs via LigneCommande)
- ✅ Caissier → Responsable (rapports)
- ✅ Produit ↔ Responsable (modification)

## 🎯 Fonctionnalités

### Gestion des Clients
- Création et modification de comptes clients
- Gestion du solde (crédit/débit)
- Affichage des informations clients

### Gestion des Produits
- Création et modification de produits
- Gestion automatique du stock
- Vérification de disponibilité

### Gestion des Commandes
- Création de commandes avec date/heure automatiques
- Ajout multiple de produits
- Calcul automatique du total
- Suivi des états de commande
- Assignation de cuisiniers

### Gestion du Personnel
- Gestion de tous les types de personnel
- Hiérarchie via héritage (Personnel comme classe de base)

## 📝 Exemple d'Utilisation

1. **Charger les données de démonstration** (option 6)
2. **Lister les clients** pour voir les IDs
3. **Lister les produits** pour voir les IDs
4. **Créer une commande** en spécifiant l'ID client et serveur
5. **Ajouter des produits** à la commande
6. **Assigner un cuisinier** à la commande
7. **Changer l'état** de la commande au fur et à mesure
8. **Consulter les statistiques** pour voir le chiffre d'affaires

## 🔄 Améliorations Futures

- [ ] Persistance des données dans des fichiers
- [ ] Interface graphique (Qt/GTK)
- [ ] Gestion des paiements
- [ ] Système de facturation
- [ ] Rapports détaillés
- [ ] Authentification des utilisateurs
- [ ] Base de données (SQLite/MySQL)

## 👥 Auteurs

Projet développé pour l'EMSI - École Marocaine des Sciences de l'Ingénieur

## 📄 Licence

Ce projet est à des fins éducatives.

