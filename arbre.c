#include "arbre.h" // pour pouvoir utiliser les structures y compris
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//  creation et initialisation des noeud vide
TArbre arbreConsVide()
{
  return NULL;
}

// retourner 1 si la noeud est vide sinon 0 // sur tete de l'arbre 1er noeud
int arbreEstVide(TArbre a)
{
  return a==NULL?1:0;
}


// creation d'un noeud par les paramétres passent lors d'appel
TArbre arbreCons(char c, int n, TArbre fg, TArbre fd)
{
  TArbre newElement = (TArbre)malloc(sizeof(struct Noeud));
  newElement->lettre = c;
  newElement->nboccurrence = n;
  newElement->noeudDroit = fd;
  newElement->noeudGauche = fg;
  return newElement;
}

// retourner le nombre d'occurence du noeud passent en paramétre
int arbreRacineNbOcc(TArbre a)
{
  int nombreOccurence = a->nboccurrence;
  return nombreOccurence;
}

// retourner la lettre du noeud passent en paramétre
char arbreRacineLettre(TArbre a)
{
    char lettre = a->lettre;
    return lettre;
}


// retourner la fils droit du noeud passent en paramétre
TArbre arbreFilsDroit(TArbre a)
{
    TArbre noeudDroit =a->noeudDroit;
    return noeudDroit;
}

// retourner la fils gauche du noeud passent en paramétre
TArbre arbreFilsGauche(TArbre a)
{
    TArbre noeudGauche =a->noeudGauche;
    return noeudGauche;
}


// suppression de tous les noeud a partir du noeud passent en paramétre
void arbreSuppr(TArbre a) // appel recursif
{
  if (a != NULL)
    {
        arbreSuppr(a->noeudDroit);
        arbreSuppr(a->noeudGauche);
        free(a);
    }
}



