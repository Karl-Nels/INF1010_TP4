#include "Client.h"
#include <iostream>
#include "ProduitAuxEncheres.h"	

Client::Client(unsigned int codeClient)
    : Usager(),
      codeClient_(codeClient)
{
}

Client::Client(const string &nom, const string &prenom, int identifiant,
               const string &codePostal, unsigned int codeClient)
    : Usager(nom, prenom, identifiant, codePostal),
      codeClient_(codeClient)
{
}

unsigned int Client::obtenirCodeClient() const
{
    return codeClient_;
}

vector<Produit *> Client::obtenirPanier() const
{

    return panier_;
}

double Client::obtenirTotalAPayer() const
{
	double totalAPayer = 0.0;
    // TODO
	for (unsigned int i = 0; i < panier_.size(); i++)
		totalAPayer += panier_[i]->obtenirPrix();

	return totalAPayer;
}

void Client::afficherPanier() const
{
    cout << "PANIER (de " << obtenirNom() << ")"
         << "\n";
    for (unsigned int i = 0; i < panier_.size(); i++)
        panier_[i]->afficher();
    cout << endl;
}

void Client::afficherProfil() const
{
    // TODO
		Usager::afficherProfil();
		cout << "\t\t code client:	" << obtenirCodeClient() << endl
		<< "\t\t panier	 :	" << panier_.size() << "elements" << endl;
}

void Client::modifierCodeClient(unsigned int codeClient)
{
    codeClient_ = codeClient_;
}

void Client::enleverProduit(Produit *produit)
{
    for (unsigned int i = 0; i < panier_.size(); i++)
    {
        if (panier_[i] == produit)
        {
            panier_[i] = panier_[panier_.size() - 1];
            panier_.pop_back();
            return;
        }
    }
}

void Client::ajouterProduit(Produit *produit)
{
    for (unsigned int i = 0; i < panier_.size(); i++)
        if (panier_[i] == produit)
            return;
    panier_.push_back(produit);
}

void Client::reinitialiser()
{
    // TODO
	for (size_t i = 0; i < panier_.size(); i++) {
	
		ProduitAuxEncheres *prod = dynamic_cast<ProduitAuxEncheres *>(panier_[i]);
		
		if (prod == panier_[i]) {
			double nouveauPrix = prod->obtenirPrixInitial();
			prod->mettreAJourEnchere(nullptr, nouveauPrix);
			panier_[i] = prod;
		}
			

		 panier_[i]->modifierFournisseur(nullptr);
		 panier_[i]->modifierNom("outil");
		 panier_[i]->modifierPrix(0.0);
		 panier_[i]->modifierReference(0);
		 panier_.pop_back();

	}	

}
