#include "trie.h"



Trie* trieNouv (){ 

    Trie *n = (Trie *)malloc(sizeof(Trie));
    n->isWord=false; //init a faux
    for (int i=0;i<N;i++){
        n->tab[i]=NULL;//init a Null
    }
    return n;
}

    int count =0;

void insertInDictionary( Trie *t , char * word){
    
    Trie * tmp= t; // declar une nouv trie 
    
    while (word[0]!='\0')
    {
        int i = ascii_to_index(word[0]);
        if (tmp->tab[i]==NULL){
        tmp->tab[i]=trieNouv();
        remove_char(word,0);
        tmp=tmp->tab[i];
        }
        else{        
            tmp=tmp->tab[i];
            remove_char(word,0);
        }
    }
     tmp->isWord=true;
        count++;   

}

void freeTrie(Trie *t){ // liberer le trie 

        for(int i=0; i<26;i++){
        free(t->tab[i]);
        }
    
        free(t);

}


 

bool searchInDictionary (Trie * t,char* word){
   if ((t==NULL)){ //si le trie est vide
    return false;
   }
   //si non 
     Trie * tmp =t;
    int succ =0;
    while ((word[succ]!='\0'))
    {
    int i = ascii_to_index(word[succ]);
    tmp = tmp->tab[i];
    if (tmp==NULL){
    return false;
    }
   
   succ++;
       
    }
     if (tmp != NULL && tmp->isWord == true)
        return true;
   
    
return false;
}

Trie* constructTrie(char *dict) {
    // Instantiate either a Trie 
    // ...
    Trie * t = trieNouv();
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    FILE *fp;
    
    // ouvertire de fichier
    fp = fopen(dict, "r"); // read mode
    if (fp == NULL) {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }

    // lire le fichier 
    while ((read = getline(&line, &len, fp)) != -1) {
        size_t length = strlen(line);
        if((length > 0) && (line[length-1] == '\n'))
        {
            line[length-1] ='\0';
        }
        insertInDictionary(t,line);
    }

    fclose(fp);
    free(line);

     return t;
}