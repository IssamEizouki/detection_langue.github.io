#include "dawg.h"
#include "trie.h"
void eval_de_perf_Trie (){
    FILE * t0 = fopen("trie.time","w");
    float moyenne =0.0;
    float tempst0;
    clock_t t1t0, t2t0;
        int n = 1;
    t1t0=clock();

        Trie* t1 = trieNouv();
        t1=constructTrie("english-wordlist.txt");
        
        t2t0 = clock();
    tempst0 = (float)(t2t0-t1t0)/CLOCKS_PER_SEC;
    if(moyenne==0){moyenne=tempst0;}
    else{moyenne= (moyenne +tempst0)/2;}
   // t1t0 = clock();
    fprintf(t0, "%d \t %f \n",n,tempst0);
    printf("temps  de creation de 1 trie pour dictionnaire english 1 fois = %f\n", tempst0);
    printf("temps moyen  = %f\n", moyenne);

        t1t0=clock();

    freeTrie(t1);


    t2t0 = clock();
    tempst0 = (float)(t2t0-t1t0)/CLOCKS_PER_SEC;
    if(moyenne==0){moyenne=tempst0;}
    else{moyenne= (moyenne +tempst0)/2;}
   // t1t0 = clock();
    fprintf(t0, "%d \t %f \n",n,tempst0);
    printf("temps  pour libere le trie = %f\n", tempst0);
    printf("temps moyen  = %f\n", moyenne);
    fclose(t0);    
return;
}


void eval_de_perf_DAWG (){
    FILE * t0 = fopen("DAWG.time","w");
    float moyenne =0.0;
    float tempst0;
    clock_t t1t0, t2t0;
        int n = 1;
    t1t0=clock();

        Sommet* t1 = DAWGNouv();
        t1=constructDAWG("german-wordlist.txt");
        
        t2t0 = clock();
    tempst0 = (float)(t2t0-t1t0)/CLOCKS_PER_SEC;
    if(moyenne==0){moyenne=tempst0;}
    else{moyenne= (moyenne +tempst0)/2;}
   // t1t0 = clock();
    fprintf(t0, "%d \t %f \n",n,tempst0);
    printf("temps  de creation de 1 dawg pour dictionnaire german 1 fois = %f\n", tempst0);
    printf("temps moyen  = %f\n", moyenne);

        t1t0=clock();

    freeDAWG(t1);


    t2t0 = clock();
    tempst0 = (float)(t2t0-t1t0)/CLOCKS_PER_SEC;
    if(moyenne==0){moyenne=tempst0;}
    else{moyenne= (moyenne +tempst0)/2;}
   // t1t0 = clock();
    fprintf(t0, "%d \t %f \n",n,tempst0);
    printf("temps  pour libere le dawg = %f\n", tempst0);
    printf("temps moyen  = %f\n", moyenne);
    fclose(t0);    
return;
}
