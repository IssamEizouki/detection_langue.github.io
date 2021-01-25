#ifndef __FCT_SUPP_H
#define __FCT_SUPP_H 



#include "trie.h"


/**
 * \brief il fait appel a parse_word(le mot) et apre il empile le mot dans la pile 
 * \param[in]: nombre de mot , une phrase
 * \param[out]: une pile 
 */
struct stack * getWords (int nb_mots , char* phrase[]);

/**
 * \brief detect la langue
 * \param[in] : une pile contenant tous les mots du paragraphe .
 * \param[in] : un trie representant le dictionaire francais .
 * \param[in] : un trie representant le dictionaire anglais 
 * \param[in] : un trie representant le dictionaire allemand .
 * \param[out] : 
 */
void detectTrie (struct stack * s, Trie * t_anglais , Trie * t_francais, Trie * t_allemand);

/**
 * \brief max de deux
 * \param[in] : deux entiers 
 * \param[out] : le max 
 */
int max1de2(int x, int y);
/**
 * \brief le max des trois 
 * \param[in] : trois entier 
 * \param[out] : le max 
 */

int max1de3(int x, int y , int z);
/**
 * \brief le plus grand prefixe commun entre deux mots 
 * \param[in] : deux mots 
 * \param[out] : int 
 */
int plusGrand_prefixe_commun(char*mot1, char*mot2);


#endif