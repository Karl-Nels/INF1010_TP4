#include "Gestionnaire.h"

vector<Usager *> Gestionnaire::obtenirUsagers() const
{
    return usagers_;
}

void Gestionnaire::afficherLesProfils() const
{
    // TODO
	for (unsigned i = 0; i < usagers_.size(); i++)

		usagers_[i]->afficherProfil();

}

double Gestionnaire::obtenirChiffreAffaires() const
{
    // TODO
	double chiffreAffaires;

	for (unsigned i = 0; i < usagers_.size(); i++)
	{
		chiffreAffaires += (*usagers_[i]).obtenirTotalAPayer();
	}
}

void Gestionnaire::ajouterUsager(Usager *usager)
{
    // TODO
	if (find(usagers_.begin(), usagers_.end(), usager) != usagers_.end())
	{

		cout << "L'usager y figure deja, veuillez reessayer !" << endl;
	}
	else
	{
		usagers_.push_back(usager);
	}
	
}

void Gestionnaire::reinitialiser()
{
    // TODO
	for (unsigned i = 0; i < usagers_.size(); i++)
	{
		(*usagers_[i]).reinitialiser();
	}
}

void Gestionnaire::encherir(Client *client, ProduitAuxEncheres *produit, double montant) const
{
    // TODO

	if (montant <= produit->obtenirPrix())
	{
		cout << "Veuillez reessayer avec un prix superieur!" << endl;
	}
	else
	{
		produit->mettreAJourEnchere(client, montant);
	}
}
