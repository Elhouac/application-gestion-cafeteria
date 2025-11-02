@echo off
REM Script de compilation pour Windows (MinGW/MSVC)

echo Compilation de l'application Cafeteria...

REM Créer les dossiers nécessaires
if not exist "obj" mkdir obj
if not exist "bin" mkdir bin

REM Vérifier si g++ est disponible
where g++ >nul 2>&1
if %ERRORLEVEL% EQU 0 (
    echo Utilisation de MinGW (g++)...
    g++ -std=c++11 -Wall -Wextra -O2 -Iinclude -c src\Client.cpp -o obj\Client.o
    g++ -std=c++11 -Wall -Wextra -O2 -Iinclude -c src\Produit.cpp -o obj\Produit.o
    g++ -std=c++11 -Wall -Wextra -O2 -Iinclude -c src\Commande.cpp -o obj\Commande.o
    g++ -std=c++11 -Wall -Wextra -O2 -Iinclude -c src\Personnel.cpp -o obj\Personnel.o
    g++ -std=c++11 -Wall -Wextra -O2 -Iinclude -c src\GestionCafeteria.cpp -o obj\GestionCafeteria.o
    g++ -std=c++11 -Wall -Wextra -O2 -Iinclude -c src\main.cpp -o obj\main.o
    g++ obj\Client.o obj\Produit.o obj\Commande.o obj\Personnel.o obj\GestionCafeteria.o obj\main.o -o bin\cafeteria.exe
    if %ERRORLEVEL% EQU 0 (
        echo.
        echo Compilation reussie! Executable cree: bin\cafeteria.exe
        echo.
        echo Pour executer: bin\cafeteria.exe
    ) else (
        echo Erreur de compilation!
    )
) else (
    echo g++ n'est pas trouve dans le PATH.
    echo Installez MinGW ou ajoutez-le au PATH.
    echo.
    echo Alternative: Utilisez Visual Studio ou un autre IDE C++.
)

pause


