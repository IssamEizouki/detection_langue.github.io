#include <stdio.h>
#include <string.h>

#include "utils.h"
#include "trie.h"
#include "fct_supp.h"
#include "dawg.h"




void messageDeFin(){
        printf("Nous vous souhaitons des bonnes fêtes ! \nIssam EIZOUKI\n");
}


int main(int argc, char* argv[]) {
   if (argc <2) {
        fprintf(stderr, "Argument manquant\n");
        fprintf(stderr, "Usage: %s <paragrahe a detecter>\n", argv[0]);
        exit(1);
    }

    

   printf("Bienvenu :\n pour tester l'implementation d'un trie, merci d'entrer 1 \n pour tester l'implementation d'un dawg, merci d'entrer 2\n");
   int n ; 
   scanf("%d",&n);
   if (n==1){
 
   //Partie Tri
     //Init des Tries
     int choix;
    printf("TRIE :\n pour detecter la langue du paragraphe, merci d'entrer 1 \n pour tester les performances d'un trie merci d'entrer 2\n");
    scanf("%d",&choix);
    if(choix==1){
    Trie * t1 = trieNouv();
    Trie * t2 = trieNouv();
    Trie * t3 = trieNouv();
      //constructions des Tries
    t1=constructTrie("french-wordlist.txt");
    t2=constructTrie("english-wordlist.txt");
    t3=constructTrie("german-wordlist.txt");
        //Recuperation du text 
    struct stack * s=getWords(argc,argv);
        //detectTrie de la langue du text
    detectTrie(s,t1,t2,t3);


        //Free les Tries (liberation de la place en memoire)
    freeTrie(t1);   
    freeTrie(t2);    
    freeTrie(t3);
    messageDeFin();
      exit(0);

   }
   else{
    eval_de_perf_Trie();
    messageDeFin();         
    exit(0);

   }

   }
   else{
    int choix;
    printf("DAWG :\npour detecter la langue du paragraphe, merci d'entrer 1 \npour tester les performances d'un DAWG merci d'entrer 2\n");
    scanf("%d",&choix);
    if(choix==1){

    Sommet * s1 = DAWGNouv();
    
    s1=constructDAWG("french-wordlist.txt");

    printf("Nous sommes desolé , nous n'arrivons pas a detecter la langue :( \n mais nous avons quad-même construit un dawg du dictionnaire francais \n");

    freeDAWG(s1);
    messageDeFin();
    exit(0);
   }

    else{
    eval_de_perf_DAWG();
    messageDeFin();
    exit(0);
    }
   }

  
    exit (0);
}