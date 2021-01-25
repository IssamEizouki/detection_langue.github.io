

#ifndef __DAWG_H
#define __DAWG_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "utils.h"
#include "hashmap.h"
#include "stack.h"
#include "fct_supp.h"


#define N 26

 struct Sommet;

typedef struct Sommet{
     char  id;     
    bool isWord;
    struct Sommet* tab[N]; 
 
}Sommet;

typedef struct Arete{
  const char * id;
  Sommet* SommetGauche;
  Sommet* SommetDroit;
}Arete;

/**
 * \brief  initialisation d'un dawg
 * \param[in] 
 * \param[out] Sommet *
 */
Sommet * DAWGNouv();

/**
 * \brief  initialisation d'un Sommet
 * \param[in] le char representant l'id du sommet  
 * \param[out] Sommet *
 */
Sommet * sommetNouv(char c);

/**
 * \brief  initialisation d'une arret
 * \param[in] 
 * \param[out]  arete
 */
struct Arete * areteNouv();

/**
 * \brief  construction  d'une arete
 * \param[in] arete , sommet gauche , sommet droite 
 * \param[out] Arete*
 *  */
Arete* construireArete(Arete * a ,Sommet * sG , Sommet * sD);


/**
 * \brief  inserer un mot dans un dawg
 * \param[in] le graphe  , le mot a inserer , une pile , et le profondeur a partir du quel l'insertion se fait
 * \param[out] 
 *  */
void insererMotDansDAWG(Sommet *g , char *word ,struct stack * s, int profondeur);

/**
 * \brief  minimisation d'un dawg jusqua un profondeur 
 * \param[in] une pile  , hashmap , et la profondeur 
 * \param[out] 
 *  */
void minimiserDAWG(struct stack *s ,struct hashmap_s *const hashmap,int profondeur);

/**
 * \brief  insertion  d'un mot dans le dawg
 * \param[in] le graphe , le mot , un pile , le hashmap 
 * \param[out] sommet * 
 *  */
Sommet * insererDansDAWG (Sommet *g , char *word ,struct stack * s,struct hashmap_s *const hashmap);


/**
 * \brief  liberation d'un  dawg
 * \param[in] le graphe
 * \param[out] 
 *  */
void freeDAWG(Sommet*s);

/**
 * \brief  rechercher un mot dans le dictionnaire(DAWG)
 * \param[in] le graphe , le mot , hashmap 
 * \param[out] Bool
 *  */
bool searchInDictionaryDAWG (Sommet * t,char* word,struct hashmap_s *const hashmap);


int count2, motMinimises, motAjoutesAuHshmap;

/**
 * \brief  convertir un index d'un char (0-25) et renvoie le char(a-z)
 * \param[in] int indice 
 * \param[out]  char
 *  */
char getId (int index);

/**
 * \brief  construction d'un  dawg
 * \param[in] le nom du fichier d'un dictionnaire a construire
 * \param[out] le graphe sommet *  
 *  */
Sommet * constructDAWG(char *dict);

/**
 * \brief  teste de performance sur  un  dawg
 * \param[in] le graphe
 * \param[out] 
 *  */
void eval_de_perf_DAWG();
#endif