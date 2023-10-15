#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED



struct Noeud {
  char lettre;
  int  nboccurrence;
  struct Noeud* noeudGauche;
  struct Noeud* noeudDroit;
};

typedef struct Noeud* TArbre;


TArbre arbreConsVide(void);
int arbreEstVide(TArbre a);
TArbre arbreCons(char c, int n, TArbre fg, TArbre fd);
TArbre arbreFilsGauche(TArbre a);
TArbre arbreFilsDroit(TArbre a);
void arbreSuppr(TArbre a);
char arbreRacineLettre(TArbre a);
int arbreRacineNbOcc(TArbre a);



#endif
