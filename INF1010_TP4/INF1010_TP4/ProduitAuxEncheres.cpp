#include "ProduitAuxEncheres.h"

ProduitAuxEncheres::ProduitAuxEncheres(double prix)
	: Produit(),
	prixInitial_(prix),
	encherisseur_(nullptr)
{
}

ProduitAuxEncheres::ProduitAuxEncheres(Fournisseur *fournisseur, const string &nom,
	int reference, double prix)
	: Produit(fournisseur, nom, reference, prix),
	prixInitial_(prix),
	encherisseur_(nullptr)
{
}

double ProduitAuxEncheres::obtenirPrixInitial() const
{
	return prixInitial_;
}

Client *ProduitAuxEncheres::obtenirEncherisseur() const
{
	return encherisseur_;
}

void ProduitAuxEncheres::afficher() const
{
	// TODO
	cout << "Prix: " << prix_ << endl;
}

void ProduitAuxEncheres::modifierPrixInitial(double prixInitial)
{
	prixInitial_ = prixInitial;
}

void ProduitAuxEncheres::mettreAJourEnchere(Client *encherisseur, double nouveauPrix)
{
	// TODO
	if (encherisseur_== nullptr) {
		encherisseur_ = encherisseur;
	}
	else if (encherisseur->obtenirIdentifiant() != encherisseur_->obtenirIdentifiant()) {

		if (nouveauPrix > prix_) {

			vector<Produit*> panier = encherisseur_->obtenirPanier();

			for (size_t i = 0; i < panier.size(); i++) {

				if (panier[i]->obtenirPrix() == prix_) {

					prix_ = nouveauPrix;
					encherisseur->ajouterProduit(panier[i]);
					encherisseur_->enleverProduit(panier[i]);
				}

			}

		}
	}
}
