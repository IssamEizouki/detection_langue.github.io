
/**
 * \author 
 * \file 
 * \brief
 */

#ifndef __TRIE_H
#define __TRIE_H 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "utils.h"
#define N 26
#include "stack.h"



typedef struct Trie {
    bool isWord;
    struct Trie* tab[N] ;

}Trie;


// variable global pour compté le nombre de mots inséreés sert a testé 
int count; 
/**
 * \brief nouvelle trie 
 * \param[in] 
 * \param[out] trie 
 */
Trie *trieNouv ();

/**
 * \brief  inserée un mots dan sle trie 
 * \param[in] trie et un mot
 * \param[out]
 */
void insertInDictionary(Trie *t , char * word);


/**
 * \brief  liberation de trie
 * \param[in] trie
 * \param[out]
 */
void freeTrie(Trie *t); 


/**
 * \brief  recherche un mot dans le trie representant un dictionnaire
 * \param[in] trie et mot 
 * \param[out] bool
 */
bool searchInDictionary (Trie * t, char * word);


/**
 * \brief  constuction du dictionnaire en trie 
 * \param[in] nom de fichier representant le dictionaire 
 * \param[out] trie representant le dictionaire 
 */
Trie* constructTrie(char *dict) ;



/**
 * \brief  teste de performance d'un trie 
 * \param[in] 
 * \param[out]
 */
void  eval_de_perf_Trie();

#endif