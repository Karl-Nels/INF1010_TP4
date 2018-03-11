#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include <string>
#include <vector>
#include "Usager.h"
#include "Produit.h"
#include "ProduitAuxEncheres.h"

using namespace std;

class Fournisseur : public Usager
{
  public:
    Fournisseur();
    Fournisseur(const string &nom, const string &prenom, int identifiant, const string &codePostal);

    vector<Produit *> obtenirCatalogue() const;
    void afficherCatalogue() const;
    void afficherProfil() const;
	virtual double obtenirTotalAPayer() const;
    void reinitialiser();
    void ajouterProduit(Produit *produit);
    void enleverProduit(Produit *produit);

  private:
    vector<Produit *> catalogue_;
};

#endif
