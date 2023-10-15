#include "arbre.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>


char end='\0';


int dicoNbOcc(char mot[], TArbre a){
int i=0;

// parcourir l'arbre et le mots caractére par caractére jusqu'a atteindre  /0 qui contient le nombre d'occurence du mots sinon retourner 0
if(mot[i]!=arbreRacineLettre(a)){
    while(!arbreEstVide(a) && mot[i]!=arbreRacineLettre(a)){
        a=arbreFilsDroit(a);
        if(arbreEstVide(a)){
        return 0;
    }
    }
}



while(mot[i] != end && !arbreEstVide(a)){
        if(mot[i]==arbreRacineLettre(a)){
            a=arbreFilsGauche(a);
            i++;
        }else{
        a=arbreFilsDroit(a);
        }
}

// si en termine les mots et en arréte au noeud /0 alors en retourne le nombre d'occurence de cette noeud
if(mot[i] == end){
    return arbreRacineNbOcc(a);
}
return 0;
}
/* -------------------------------------------------------*/
int dicoNbMotsDifferents(TArbre a){

// le nombre des mots différent est le nombre du /0 présente dans la la dictionnaire
// si en trouve /0 en incremente le resultat et lancer un apple recursive a droit et a gauche
    if(!arbreEstVide(a)){
        if(arbreRacineLettre(a)==end){
            return 1+dicoNbMotsDifferents(arbreFilsGauche(a))+dicoNbMotsDifferents(arbreFilsDroit(a));
        }

        return dicoNbMotsDifferents(arbreFilsGauche(a))+dicoNbMotsDifferents(arbreFilsDroit(a));
    }else{
        return 0;
    }
}
/*-------------------------------------------------------*/
int dicoNbMotsTotal(TArbre a){

    // le nombre des mots total est le nombre d'occurence du noeud /0 dans la la dictionnaire
    // si en trouve /0 en incremente le resultat par le nombre d'occurence de cette noeud et lancer un apple recursive a droit et a gauche

    if(!arbreEstVide(a)){
            if(arbreRacineLettre(a)==end){

                return arbreRacineNbOcc(a)+dicoNbMotsTotal(arbreFilsGauche(a))+dicoNbMotsTotal(arbreFilsDroit(a));
            }

        return dicoNbMotsTotal(arbreFilsGauche(a))+dicoNbMotsTotal(arbreFilsDroit(a));
    }else{
    return 0;
    }
}
/*-------------------------------------------------------*/
void dicoInsererMot(char mot[], TArbre *pa)
{
    if (*pa != NULL)
    {
        if (mot[0] != end)
        {if ((*pa)->lettre == mot[0])
            {
                // si la lettre est deja existe en increment le pointer suivie par un appel recursive au noeud gauche
                mot++;
                dicoInsererMot(mot, &((*pa)->noeudGauche));
            }
            else
            {
                // deplacement a gauche si la lettre current est diffirent au lettre du mots
                if ((*pa)->noeudDroit != NULL){dicoInsererMot(mot, &((*pa)->noeudDroit));}
                else
                {
                    (*pa)->noeudDroit = arbreCons(mot[0], 0, NULL, NULL);
                    dicoInsererMot(mot, &(*pa));
                }
            }
        }
        else if ((*pa)->lettre != end && mot[0] == end)
        {
            // creation d'un noeud intermédiaire si le nouvel noeud est une partie d'autre
                    TArbre a = arbreCons(end, 1, NULL, *pa);
                    *pa = a;
        }
        // si le mots est deja existe en increment le nombre d'occurence par 1
        else if ((*pa)->lettre == end && mot[0] == end){(*pa)->nboccurrence=(*pa)->nboccurrence+1;}
    }
    else
    {

        if (mot[0] != end)
        {
            // l'insertion du nouvel lettre et incrementation du pointer sur le mots suivie par un appel recursive avec le noeud gauche
            *pa = arbreCons(mot[0], 0, NULL, NULL);
            mot++;dicoInsererMot(mot, &((*pa)->noeudGauche));
        }
        else{
                // insertion du /0 avec le nombre d'occurence =1
                *pa = arbreCons(end, 1, NULL, NULL);
        }
    }
}
/*-------------------------------------------------------*/
void afficherElements(char mot[], TArbre a)
{

    if (a !=NULL)
    {
        if (arbreRacineLettre(a) != end)
        {
            // appel recursive a noeud droit sans l'insertion du caractére current
            if (a->noeudDroit !=NULL)
            {
                afficherElements(mot, a->noeudDroit);
            }
            // appel recursive a noeud droit sans l'insertion du caractére current
            if (a->noeudGauche !=NULL)
            {
                strcat(mot, (char[2]){arbreRacineLettre(a), end});
                afficherElements(mot, arbreFilsGauche(a));
            }
            // l'insertion du /0 au fin du chaine
            mot[strlen(mot)-1] = end;
        }
        else
        {
            //afficher le mots si le noeud current est /0 qui présent le caractére du fin de chaine
            printf("%s\n", mot);
            //continue s'il ya une autre mots qui commence par le meme sequence
            if (a->noeudDroit!=NULL)
                afficherElements(mot, arbreFilsDroit(a));
        }
    }
}

void dicoAfficher(TArbre a)
{
    printf("\n\tDictionnaire:\t\n");
    char mot[100] = "";
    afficherElements(mot, a);
}


// creation du nombre aleatoire
int nombreAleatoire(int nombreMax)
{
srand(time(NULL));
 return (rand() % nombreMax);
}

// recupération d'un mot et inserer dans motPioche
int piocherMot(char *motPioche)
{



    FILE* dico = NULL;
    dico = fopen("dico.txt", "r");

    int nombreMots = 0, numMotChoisi = 0, i = 0;

    int caractereLu = 0;

    if (dico == NULL)

    {

        printf("\nImpossible de charger le dictionnaire de mots");

        return 0;
    }


    do{

        caractereLu = fgetc(dico);

        if (caractereLu == '\n')

            nombreMots++;

    } while(caractereLu != EOF);


    numMotChoisi = nombreAleatoire(nombreMots);

    rewind(dico);

    while (numMotChoisi > 0)

    {

        caractereLu = fgetc(dico);

        if (caractereLu == '\n')

            numMotChoisi--;

    }


    fgets(motPioche, 100, dico);


    motPioche[strlen(motPioche) - 1] = '\0';

    fclose(dico);



    return 1;

}


