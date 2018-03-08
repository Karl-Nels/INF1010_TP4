#include "Fournisseur.h"
#include <iostream>

Fournisseur::Fournisseur()
    : Usager()
{
}

Fournisseur::Fournisseur(const string &nom, const string &prenom, int identifiant,
                         const string &codePostal)
    : Usager(nom, prenom, identifiant, codePostal)
{
}

vector<Produit *> Fournisseur::obtenirCatalogue() const
{
    return catalogue_;
}

void Fournisseur::afficherCatalogue() const
{
    cout << "CATALOGUE (de " << obtenirNom() << ")"
         << "\n";
    for (unsigned int i = 0; i < catalogue_.size(); i++)
        catalogue_[i]->afficher();
    cout << endl;
}

double Fournisseur::obtenirTotalAPayer() const {

	double totalAPayer = 0.0;
	return totalAPayer;
}

void Fournisseur::afficherProfil() const
{
    // TODO
	Usager::afficherProfil();
	cout << "\t\t catalogue:	" << catalogue_.size() << " elements." << endl;
}

void Fournisseur::reinitialiser()
{
	// TODO
	for (size_t i = 0; i < catalogue_.size(); i++) {

		ProduitAuxEncheres *prod = dynamic_cast<ProduitAuxEncheres *>(catalogue_[i]);

		if (prod == catalogue_[i]) {

			prod->mettreAJourEnchere(nullptr, prod->obtenirPrixInitial());
			catalogue_[i] = prod;
		}
		for (size_t i = 0; i < catalogue_.size(); i++) {


			catalogue_[i]->modifierFournisseur(nullptr);
			catalogue_[i]->modifierNom("outil");
			catalogue_[i]->modifierPrix(0.0);
			catalogue_[i]->modifierReference(0);
			catalogue_.pop_back();
		}
	}
}

void Fournisseur::ajouterProduit(Produit *produit)
{
    for (unsigned int i = 0; i < catalogue_.size(); i++)
        if (catalogue_[i] == produit)
            return;
    Fournisseur *fournisseur = produit->obtenirFournisseur();
    if (fournisseur != nullptr && fournisseur != this)
        fournisseur->enleverProduit(produit);
    catalogue_.push_back(produit);
}

void Fournisseur::enleverProduit(Produit *produit)
{
    produit->modifierFournisseur(nullptr);
    for (unsigned int i = 0; i < catalogue_.size(); i++)
    {
        if (catalogue_[i] == produit)
        {
            catalogue_[i] = catalogue_[catalogue_.size() - 1];
            catalogue_.pop_back();
            return;
        }
    }
}
