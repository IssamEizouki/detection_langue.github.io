#include <stdio.h>
#include <string.h>

#include "fct_supp.h"

int max1de2(int x, int y){ // renvoie le maximum entre les 2
    if (x>y){return x;}
    return y;
}
int max1de3(int x, int y , int z){ // renvoie le max entre les 3
    return max1de2(max1de2(x,y),z);
}
struct stack * getWords (int nb , char* phrase[]){ // il fait appel a parse_word(le mot) et apre il empile le mot dans la pile 

    int i;
    struct stack* s = new_stack(nb);
    for(i=nb-1; i>0; i--){
        parse_word(phrase[i]);
        stack_push(s,phrase[i]);
    }
return s;
}
void detectTrie (struct stack * s,  Trie * t_francais,Trie * t_anglais , Trie * t_allemand){ 
    char * mot;
    int french_corresp =0;
    int german_corresp =0;
    int english_corresp =0;
    while(!is_stack_empty(s)){
        mot =stack_peek(s);
        if(searchInDictionary(t_francais,mot))french_corresp++;
        if(searchInDictionary(t_anglais,mot))english_corresp++;
        if(searchInDictionary(t_allemand,mot))german_corresp++;
        stack_pop(s);
    }
    free(s);
    printf("FRENCH %d / ENGLISH %d / DEUTCH %d \n", french_corresp, english_corresp, german_corresp);
     if (max1de3(french_corresp,english_corresp,german_corresp)==0){
        printf("can not detect such a language , perhaps it's chinese xD \n");
    }
     if (max1de3(french_corresp,english_corresp,german_corresp)==french_corresp &&(french_corresp!=0)){
        printf("this text is a french one \n");
    }
    if (max1de3(french_corresp,english_corresp,german_corresp)==english_corresp&&(english_corresp!=0)){
        printf("this text is a english one \n");
    }
     if (max1de3(french_corresp,english_corresp,german_corresp)==german_corresp&&(german_corresp!=0)){
        printf("this text is an german one \n");
    }
  
}


int plusGrand_prefixe_commun(char*mot1, char*mot2){
    int i =0;
    int indice_de_plus_grand_pref =0; 
    while ((mot1[i]!='\0') && (mot2[i]!='\0') )
    {
        if((mot1[i]!=mot2[i])){
            return indice_de_plus_grand_pref;
        }
        indice_de_plus_grand_pref++;
        i++;
    }
    return indice_de_plus_grand_pref;//si 0 donc pas de prefix commun sinon la taille du plus grand prefix
}