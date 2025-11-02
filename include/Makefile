CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2
SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
TARGET = $(BINDIR)/cafeteria

.PHONY: all clean directories

all: directories $(TARGET)

directories:
	@mkdir -p $(OBJDIR) $(BINDIR)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)
	@echo "\n✓ Compilation réussie! Exécutable: $(TARGET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(BINDIR)
	@echo "Nettoyage terminé."

run: $(TARGET)
	./$(TARGET)

help:
	@echo "Commandes disponibles:"
	@echo "  make        - Compiler le projet"
	@echo "  make run    - Compiler et exécuter"
	@echo "  make clean  - Nettoyer les fichiers générés"
	@echo "  make help   - Afficher cette aide"


