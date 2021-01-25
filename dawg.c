#include "dawg.h"

int count2 = 0; 
char *last_inserted =NULL;

Sommet * DAWGNouv(){
    Sommet * s = (Sommet*)malloc(sizeof(Sommet));
     s->isWord=false;// init a faux
    for (int i=0;i<N;i++){ 
        s->tab[i]=NULL; // init a null
    }

    return s;
}
Sommet * sommetNouv(char c){
    Sommet * s = (Sommet*)malloc(sizeof(Sommet));
    s->id = c; // init a la lettre donnée en param
     s->isWord=false;
    for (int i=0;i<N;i++){
        s->tab[i]=NULL;
    }

    return s;
}

 Arete * areteNouv(){
 Arete * a = (struct Arete *)malloc(sizeof(struct Arete)); 
a->SommetDroit =DAWGNouv();// init sommet droite 
a->SommetGauche=DAWGNouv();// init sommet gauche
return a;
}


Arete* construireArete(Arete * a ,Sommet * sG , Sommet * sD){
  char *x1 =&sG->id;
  char *x2=&sD->id;
  const char * c1 = x1 ;
  const char * c2 = x2 ;
a->id= concat(c1,c2);//Concatenation de deux id des deux sommet

a->SommetGauche=sG;
a->SommetDroit=sD;
return a;
}



//convertir un indice a un char 
  char getId (int index){
  switch(index)
  {
  case 0: return 'a';
  case 1: return 'b';
  case 2: return 'c';
  case 3: return 'd';
  case 4: return 'e';
  case 5: return 'f';
  case 6: return 'g';
  case 7: return 'h';
  case 8: return 'i';
  case 9: return 'j';
  case 10: return 'k';
  case 11: return 'l';
  case 12: return 'm';
  case 13: return 'n';
  case 14: return 'o';
  case 15: return 'p';
  case 16: return 'q';
  case 17: return 'r';
  case 18: return 's';
  case 19: return 't';
  case 20: return 'u';
  case 21: return 'v';
  case 22: return 'w';
  case 23: return 'x';
  case 24: return 'y';
  case 25: return 'z';
  
  }
  return 'A';
}





//Insertion:
void insererMotDansDAWG(Sommet *g , char *word ,struct stack * s, int profondeur){
Sommet * tmp= g;

int positionInArrete = (profondeur==0); //1 si depuis la racine 0 sinon

last_inserted=word; //sauvgarder le mot dans le variable global last inserted
int stop=0;

while (word[stop]!='\0')
    {
      if(word[stop+1]=='\0'){
        tmp->isWord=true;
      }
     int i = ascii_to_index(word[stop]); //convertir le char en indice 

      if(tmp->tab[i]==NULL){ 
        tmp->tab[i]=sommetNouv(word[0]);// creation de sommet a la position i 
   
        remove_char(word,0);

        if (positionInArrete){ //pour tester si la lettre qu'on es entrain d'inserer est la premier a inserer dans le graphe 
          positionInArrete=0;
        }
      
        else{
          Arete *a=areteNouv();      //initialisation de l'arrete 
          a=construireArete(a,tmp,tmp->tab[i]);
          stack_push(s,a);  //empiler l'arrete correspondante
        }
        
        tmp=tmp->tab[i];   // incrementation dans la position du dawg     
        }

      else {
           remove_char(word,0);
          //stop++;

         if (positionInArrete){
            positionInArrete=0;
        }
        else{
          Arete *a=areteNouv();      //initialisation de l'arrete 
          a=construireArete(a,tmp,tmp->tab[i]);
          stack_push(s,a);   //empiler l'arrete correspondante
        }
        
        tmp=tmp->tab[i];
        
      }

}
tmp->isWord=true; //dernier sommet ajouté est un etat final
count2++;
}


void minimiserDAWG(struct stack *s ,struct hashmap_s *const hashmap,int profondeur){
    Arete * a = areteNouv();//creation d'une arrete

  while(stack_size(s)>profondeur){//tant que la taille de la pile est superieur a la profondeur 
     a=stack_pop(s); //depiler 
    Sommet * sD = a->SommetDroit;
    size_t size = strlen(a->id); // la taille de mot
    Sommet* element = hashmap_get(hashmap, a->id, size);//cherche le sommet droite dans la hashmap
    if((element==NULL)||(!element->id)){ // si il est pas present 
      if((hashmap_put(hashmap,a->id,size,sD))!=0) exit(EXIT_FAILURE); //enrigistrer le sommet
   motAjoutesAuHshmap++;
    }
    else { // si non 
      
      char x = sD->id;
      int i = ascii_to_index(x);
      a->SommetGauche->tab[i]=sommetNouv(getId(i));
      a->SommetGauche->tab[i]=element;// relier le sommet gauche au sommet trouvé dans le hashmap
      element->isWord=sD->isWord;
      motMinimises++;
      }

  }
  free(a);
}

Sommet * insererDansDAWG (Sommet *g , char *word ,struct stack * s,struct hashmap_s *const hashmap){

int profondeur =0;

        if (last_inserted!=NULL){ //si c'est n'es pas le premier mot a inseré dans le graphe
        profondeur=(plusGrand_prefixe_commun(last_inserted,word)); // calcule le plus grand prefixe commun 
        //entre lui et le dernier qui a été inserer 
        minimiserDAWG(s,hashmap,profondeur);  ////minimiser jusqu'a la profondeur n 
 //(profondeur=plus grand prefixe commun entre le dernier mot insere et celui a inserer)
        }

        if(is_stack_empty(s)){  // Si la pile est vide //
        insererMotDansDAWG(g , word , s , 0);   ////-> inserer depuis la racine 
        }

        if(!is_stack_empty(s)){ //Si la pile est non vide 
        //->inserer depuis le sommet droit de la derniere arrete empilée
        Arete *a = stack_peek(s);
        insererMotDansDAWG(a->SommetDroit , word , s , profondeur);
        }

return g;
}

          
bool searchInDictionaryDAWG (Sommet * t,char* word,struct hashmap_s *const hashmap){
    

   if ((t==NULL)){ // si le dawg est vide 
    return false;
   }
    //si non 
     Sommet * tmp =t; 
     size_t bornMax =strlen(word);
    size_t succ =0;
    while ((word[succ]!='\0')&&(succ<bornMax))
    {
    int i = ascii_to_index(word[succ]);
    tmp = tmp->tab[i];
    if (tmp==NULL){
    return false;
    }
   
   succ++;
       
    }

  char *x1 =&word[succ-2];
  char *x2=&word[succ-1];
  

  const char * c1 = x1 ;
  const char * c2 = x2 ;
  const char * res= concat(c1,c2);
printf("res = %s\n",res);
    Sommet* element = hashmap_get(hashmap, res, strlen(res));

     if (element != NULL && element->isWord == true){
        printf("element = %d\n",element->isWord);

        return true;
     }
     if((tmp!=NULL)&&(tmp->isWord==true)){
       return true ;
     }
    
return false;
}

   

void freeDAWG(Sommet *s){

        for(int i=0; i<26;i++){ 
        free(s->tab[i]);
        }
    
        free(s);

}

Sommet * constructDAWG(char *dict) {
    
    Sommet * g = DAWGNouv();
    struct stack *s = new_stack(100); //init d'une pile 
    //creation de hashmap ******
    struct hashmap_s hashmap1;
         const unsigned initial_size = 8;

    if (0 != hashmap_create(initial_size, &hashmap1)) { // creation de hashmap
        perror("can not creat the hashmap");
    //creation de hashmap ******
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    FILE *fp;
    
    // open file 
    fp = fopen(dict, "r"); // read mode
    if (fp == NULL) {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }

    // read file
    while ((read = getline(&line, &len, fp)) != -1) {
        // remove newline
        size_t length = strlen(line);
        if((length > 0) && (line[length-1] == '\n'))
        {
            line[length-1] ='\0';
        }
   
        insererDansDAWG(g,line,s,&hashmap1);//insertion du mot 
    }

    minimiserDAWG(s,&hashmap1,0); //minimisation jusqu'a le profondeur 0
    printf("%d mots insereres\n",count2); 
    fclose(fp);
    free(line);
    //freeDAWG(g);
     return g;
}
