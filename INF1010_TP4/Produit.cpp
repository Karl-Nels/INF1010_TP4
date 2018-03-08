#include "Produit.h"
#include "Fournisseur.h"
#include <iostream>
#include <string>

Produit::Produit(Fournisseur *fournisseur, const string &nom, int reference, double prix)
    : fournisseur_(fournisseur),
      nom_(nom),
      reference_(reference),
      prix_(prix)
{
    if (fournisseur_ != nullptr)
        fournisseur_->ajouterProduit(this);
}

string Produit::obtenirNom() const
{
    return nom_;
}

int Produit::obtenirReference() const
{
    return reference_;
}

double Produit::obtenirPrix() const
{
    // TODO
	return prix_;
}

Fournisseur *Produit::obtenirFournisseur() const
{
    return fournisseur_;
}

void Produit::afficher() const
{
    // TODO
	cout << "Prix ordinaire: " << prix_ << endl;
}

void Produit::modifierNom(const string &nom)
{
    nom_ = nom;
}

void Produit::modifierReference(int reference)
{
    reference_ = reference;
}

void Produit::modifierPrix(double prix)
{
    prix_ = prix;
}

void Produit::modifierFournisseur(Fournisseur *fournisseur)
{
    fournisseur_ = fournisseur;
}
