#include <iostream>
#include <iomanip>
#include "Produit.h"
#include "ProduitAuxEncheres.h"
#include "ProduitSolde.h"
#include "Client.h"
#include "ClientPremium.h"
#include "Fournisseur.h"
#include "Gestionnaire.h"

using namespace std;

int main()
{
	Gestionnaire poly;
	Client ratus;
	Client gaspard("Donada--Vidal", "Gaspard", 5215487, "P4R 1I5", 1997);
	Client rick("S", "Rick", 8435174, "HF1 8H3", 20012003);
	ClientPremium marou;
	ClientPremium julie("Cash", "Julie", 1126250, "HZ9 1J4", 19141918, 50);
	Fournisseur mina;
	Fournisseur martine("Bellaiche", "Martine", 6845123, "H4C 8D4");
	Fournisseur samuel("Kadoury", "Samuel", 1687421, "H1G 2G4");
	Produit sel;
	Produit chaussures(&martine, "chaussures", 1, 40.0);
	Produit stylo(&samuel, "stylo", 2, 3.0);
	ProduitAuxEncheres sculpture;
	ProduitAuxEncheres violoncelle(&martine, "violoncelle", 3, 5000.0);
	ProduitSolde saladier;
	ProduitSolde montre(&mina, "montre", 4, 100.0, 30);
	ProduitSolde nem(&samuel, "nem crevettes", 5, 2.0);
	poly.ajouterUsager(&gaspard);
	poly.ajouterUsager(&rick);
	poly.ajouterUsager(&martine);
	poly.ajouterUsager(&samuel);
	poly.ajouterUsager(&ratus);
	poly.ajouterUsager(&marou);
	poly.ajouterUsager(&mina);
	poly.ajouterUsager(&julie);

	vector<bool> tests;

	// le constructeur par d�faut de client doit fonctionner
	tests.push_back(ratus.obtenirNom() == "Doe" &&
		ratus.obtenirPrenom() == "John" &&
		ratus.obtenirIdentifiant() == 0 &&
		ratus.obtenirCodePostal() == "A1A A1A" &&
		ratus.obtenirCodeClient() == 0);
	// le constructeur par param�tres de client doit fonctionner
	tests.push_back(gaspard.obtenirNom() == "Donada--Vidal" &&
		gaspard.obtenirPrenom() == "Gaspard" &&
		gaspard.obtenirIdentifiant() == 5215487 &&
		gaspard.obtenirCodePostal() == "P4R 1I5" &&
		gaspard.obtenirCodeClient() == 1997);
	// le constructeur par d�faut de client premium doit fonctionner
	tests.push_back(marou.obtenirNom() == "Doe" &&
		marou.obtenirPrenom() == "John" &&
		marou.obtenirIdentifiant() == 0 &&
		marou.obtenirCodePostal() == "A1A A1A" &&
		marou.obtenirCodeClient() == 0 &&
		marou.obtenirJoursRestants() == 0);
	// le constructeur par param�tres de client premium doit fonctionner
	tests.push_back(julie.obtenirNom() == "Cash" &&
		julie.obtenirPrenom() == "Julie" &&
		julie.obtenirIdentifiant() == 1126250 &&
		julie.obtenirCodePostal() == "HZ9 1J4" &&
		julie.obtenirCodeClient() == 19141918 &&
		julie.obtenirJoursRestants() == 50);
	// le constructeur par d�faut de fournisseur doit fonctionner
	tests.push_back(mina.obtenirNom() == "Doe" &&
		mina.obtenirPrenom() == "John" &&
		mina.obtenirIdentifiant() == 0 &&
		mina.obtenirCodePostal() == "A1A A1A");
	// le constructeur par param�tres de fournisseur doit fonctionner
	tests.push_back(martine.obtenirNom() == "Bellaiche" &&
		martine.obtenirPrenom() == "Martine" &&
		martine.obtenirIdentifiant() == 6845123 &&
		martine.obtenirCodePostal() == "H4C 8D4");
	// le constructeur par d�faut de produit doit fonctionner
	tests.push_back(sel.obtenirNom() == "outil" &&
		sel.obtenirReference() == 0 &&
		sel.obtenirFournisseur() == nullptr &&
		sel.obtenirPrix() == 0.0);
	// le constructeur par param�tres de produit doit fonctionner
	tests.push_back(stylo.obtenirNom() == "stylo" &&
		stylo.obtenirReference() == 2 &&
		stylo.obtenirFournisseur() == &samuel &&
		stylo.obtenirPrix() == 3.0);
	// le constructeur par d�faut de produit aux ench�res doit fonctionner
	tests.push_back(sculpture.obtenirNom() == "outil" &&
		sculpture.obtenirReference() == 0 &&
		sculpture.obtenirFournisseur() == nullptr &&
		sculpture.obtenirPrix() == 0.0 &&
		sculpture.obtenirPrixInitial() == 0.0);
	// le constructeur par param�tres de produit aux ench�res doit fonctionner
	tests.push_back(violoncelle.obtenirNom() == "violoncelle" &&
		violoncelle.obtenirReference() == 3 &&
		violoncelle.obtenirFournisseur() == &martine &&
		violoncelle.obtenirPrix() == 5000.0 &&
		violoncelle.obtenirPrixInitial() == 5000.0);
	// le constructeur par d�faut de produit sold� doit fonctionner
	tests.push_back(saladier.obtenirNom() == "outil" &&
		saladier.obtenirReference() == 0 &&
		saladier.obtenirFournisseur() == nullptr &&
		saladier.obtenirPrix() == 0.0 &&
		saladier.obtenirPourcentageRabais() == 0);
	// le constructeur par param�tres de produit sold� doit fonctionner
	tests.push_back(nem.obtenirNom() == "nem crevettes" &&
		nem.obtenirReference() == 5 &&
		nem.obtenirFournisseur() == &samuel &&
		nem.obtenirPrix() == 2 &&
		nem.obtenirPourcentageRabais() == 0);

	// une surench�re doit �tre strictement sup�rieure � l'offre pr�c�dente
	poly.encherir(&julie, &violoncelle, 5000.0);
	tests.push_back(julie.obtenirPanier().size() == 0);
	poly.encherir(&gaspard, &violoncelle, 6000.0);
	poly.encherir(&julie, &violoncelle, 6000.0);
	tests.push_back(julie.obtenirPanier().size() == 0);
	poly.encherir(&julie, &violoncelle, 7000.0);
	tests.push_back(julie.obtenirPanier().size() == 1);
	// on ne peut pas surencherir sur sa propre ench�re
	poly.encherir(&julie, &violoncelle, 8000.0);
	tests.push_back(violoncelle.obtenirPrix() == 7000.0);
	// surench�rir doit enlever le produit du panier de l'ancien encherisseur
	poly.encherir(&gaspard, &violoncelle, 8000.0);
	tests.push_back(julie.obtenirPanier().size() == 0);
	// surench�rir doit ajouter le produit au panier du nouvel ench�risseur
	poly.encherir(&julie, &violoncelle, 9000.0);
	tests.push_back(julie.obtenirPanier().size() == 1 &&
		julie.obtenirPanier()[0]->obtenirNom() == "violoncelle");
	// surench�rir doit mettre � jour l'attribut encherisseur_
	tests.push_back(violoncelle.obtenirEncherisseur() != nullptr &&
		violoncelle.obtenirEncherisseur()->obtenirPrenom() == "Julie");
	// surench�rir doit mettre � jour le prix du produit
	tests.push_back(violoncelle.obtenirPrix() == 9000.0);
	// le prix initial ne doit pas varier
	tests.push_back(violoncelle.obtenirPrixInitial() == 5000.0);

	// ajouter le produit au client doit l'ajouter au panier
	gaspard.ajouterProduit(&stylo); // produit normal
	gaspard.ajouterProduit(&nem);   // produit sold�
	tests.push_back(gaspard.obtenirPanier().size() == 2 &&
		gaspard.obtenirPanier()[0]->obtenirNom() == "stylo" &&
		gaspard.obtenirPanier()[1]->obtenirNom() == "nem crevettes");
	// idem pour client premium
	julie.ajouterProduit(&stylo); // produit normal
	julie.ajouterProduit(&nem);   // produit sold�
	tests.push_back(julie.obtenirPanier().size() == 3 &&
		julie.obtenirPanier()[1]->obtenirNom() == "stylo" &&
		julie.obtenirPanier()[2]->obtenirNom() == "nem crevettes");
	// on ne peut pas ajouter le m�me produit deux fois dans le panier
	gaspard.ajouterProduit(&stylo); // produit normal
	gaspard.ajouterProduit(&nem);   // produit sold�
	tests.push_back(gaspard.obtenirPanier().size() == 2);
	// idem pour client premium
	julie.ajouterProduit(&stylo); // produit normal
	julie.ajouterProduit(&nem);   // produit sold�
	tests.push_back(julie.obtenirPanier().size() == 3);

	// ajouter le produit au fournisseur doit l'ajouter au catalogue
	tests.push_back(martine.obtenirCatalogue().size() == 2 &&
		martine.obtenirCatalogue()[0]->obtenirNom() == "chaussures" && // normal
		martine.obtenirCatalogue()[1]->obtenirNom() == "violoncelle"); // ench�res
	tests.push_back(mina.obtenirCatalogue().size() == 1 &&
		mina.obtenirCatalogue()[0]->obtenirNom() == "montre"); // sold�
															   // modifier le fournisseur d'un produit doit ajouter le produit au nouveau fournisseur
	martine.ajouterProduit(&montre);
	tests.push_back(martine.obtenirCatalogue().size() == 3 &&
		martine.obtenirCatalogue()[0]->obtenirNom() == "chaussures" &&
		martine.obtenirCatalogue()[1]->obtenirNom() == "violoncelle" &&
		martine.obtenirCatalogue()[2]->obtenirNom() == "montre");
	// modifier le fournisseur d'un produit doit retirer le produit du catalogue pr�c�dent
	tests.push_back(mina.obtenirCatalogue().size() == 0);
	// enlever un produit doit mettre l'attribut fournisseur � jour
	martine.enleverProduit(&montre);
	tests.push_back(montre.obtenirFournisseur() == nullptr);
	// enlever un produit doit le retirer du catalogue du fournisseur
	tests.push_back(martine.obtenirCatalogue().size() == 2 &&
		martine.obtenirCatalogue()[0]->obtenirNom() == "chaussures" &&
		martine.obtenirCatalogue()[1]->obtenirNom() == "violoncelle");
	// enlever un produit une deuxi�me fois ne doit rien faire
	martine.enleverProduit(&montre);
	tests.push_back(martine.obtenirCatalogue().size() == 2 &&
		martine.obtenirCatalogue()[0]->obtenirNom() == "chaussures" &&
		martine.obtenirCatalogue()[1]->obtenirNom() == "violoncelle");

	// r�initialiser doit vider le panier de tous les clients
	poly.reinitialiser();
	tests.push_back(gaspard.obtenirPanier().size() == 0 &&
		ratus.obtenirPanier().size() == 0 &&
		julie.obtenirPanier().size() == 0 &&
		marou.obtenirPanier().size() == 0 &&
		rick.obtenirPanier().size() == 0);
	// r�initialiser doit mettre � jour l'attribut encherisseur_ quand n�cessaire
	tests.push_back(violoncelle.obtenirEncherisseur() == nullptr);
	// r�initialiser doit remettre les produits aux ench�res � leur prix intial
	tests.push_back(violoncelle.obtenirPrix() == violoncelle.obtenirPrixInitial());
	// r�initialiser doit vider le catalogue de tous les fournisseurs
	tests.push_back(martine.obtenirCatalogue().size() == 0 &&
		samuel.obtenirCatalogue().size() == 0 &&
		mina.obtenirCatalogue().size() == 0);
	// r�initialiser doit mettre � jour l'attribut fournisseur_ quand n�cessaire
	tests.push_back(stylo.obtenirFournisseur() == nullptr &&
		sculpture.obtenirFournisseur() == nullptr &&
		nem.obtenirFournisseur() == nullptr);

	// le chiffre d'affaires devrait �tre nul apr�s une r�initialisation
	tests.push_back(poly.obtenirChiffreAffaires() == 0.0);
	// le total � payer des clients normaux doit sommer les prix dans le panier
	gaspard.ajouterProduit(&chaussures);       // 40
	gaspard.ajouterProduit(&montre);           // 100 - 30
	poly.encherir(&gaspard, &violoncelle, 20000); // 20000
	tests.push_back(gaspard.obtenirTotalAPayer() == 20110.0);
	// le total � payer des clients premiums doit prendre ne compte la r�duction
	julie.ajouterProduit(&chaussures);       // 35
	julie.ajouterProduit(&montre);           // 100 - 30 - 5
	poly.encherir(&julie, &violoncelle, 21000); // 21000 - 5
	tests.push_back(julie.obtenirTotalAPayer() == 21095.0);
	// la r�duction ne doit pas induire des prix n�gatifs
	julie.ajouterProduit(&nem); // 0
	tests.push_back(julie.obtenirTotalAPayer() == 21095.0);
	// la surench�re doit actualiser le prix � payer pour l'ancien encherisseur
	tests.push_back(gaspard.obtenirTotalAPayer() == 110.0);
	// le total � payer des fournisseurs doit �tre nul
	samuel.ajouterProduit(&chaussures);
	samuel.ajouterProduit(&montre);
	tests.push_back(samuel.obtenirTotalAPayer() == 0.0);
	// le chiffre d'affaires doit additionner les totaux � payer
	tests.push_back(poly.obtenirChiffreAffaires() == 110.0 + 21095.0);

	// un usager ne peut pas �tre ajout� deux fois au gestionnaire
	tests.push_back(poly.obtenirUsagers().size() == 8);
	poly.ajouterUsager(&martine);
	tests.push_back(poly.obtenirUsagers().size() == 8);

	// fonctions d'affichage
	gaspard.afficherPanier();
	julie.afficherPanier();
	ratus.afficherPanier();
	martine.afficherCatalogue();
	samuel.afficherCatalogue();
	mina.afficherCatalogue();
	poly.afficherLesProfils();

	cout << "TESTS" << endl;
	for (unsigned int i = 0; i < tests.size(); i++)
	{
		cout << "\tTest " << setfill('0') << setw(2) << i + 1 << "... ";
		if (tests[i])
			cout << "OK!" << endl;
		else
			cout << "ECHEC" << endl;
	}
	return 0;
}
