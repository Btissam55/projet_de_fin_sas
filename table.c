#include<stdio.h>
#include<string.h>
//declaration de la structure date
typedef struct Date{
	int annee;
	int mois;
	int jour;
}Date;
//declaration de la structure tache
 typedef struct Tache{
 	char titre[20];
 	char descrip[100];
 	char priorite[5];
 	Date date;
 }tache;
 tache A[50];
/*Les variables 'jour', 'mois' et 'année' sont utilisées pour vérifier que la date limite de la tache saisie est bien une date future. Cette vérification se fait en comparant la date saisie avec la date actuelle*/
 int jour,mois,annee,n;
//declartion de la taille du tableau 
 int taille=0;
 //Cette fonction ajoute une tâche lorsque l'utilisateur sélectionne le choix 1
void AJOUTER_UNE_TACHE(){
	// Vérifier que la liste de tâches n'est pas pleine avant d'ajouter une nouvelle tâche
	if(taille>=50) printf("la liste des atches est pleine\n");
	else{
 	    printf("entrez le titre de la tache : ");
 	    scanf("%s",A[taille].titre);
 	    printf("entrez la description de la tache : ");
        scanf("%s",A[taille].descrip);
 	    printf("Attention: la priorite prend deux valeurs <%s,%s>\n","high","low");
 	    // Vérification que la priorité est soit 'high' soit 'low', sinon redemander la saisie
 	    do{
 		    printf("entrez la priorite de la tache : ");
 	        scanf("%s",A[taille].priorite);
	    }while(strcmp(A[taille].priorite,"high")!=0 && strcmp(A[taille].priorite,"low")!=0);
      	printf("Attention : vous devez planifier une tache pour une date future\n");
 	    // Vérification que la date saisie est dans le futur par rapport à la date actuelle
 	    do{
 	         printf("entrez la date : ");
 	         scanf("%d/%d/%d",&A[taille].date.annee,&A[taille].date.mois,&A[taille].date.jour);
	    }while(A[taille].date.annee<annee || (A[taille].date.annee==annee && A[taille].date.mois<mois) || (A[taille].date.annee==annee && A[taille].date.mois==mois && A[taille].date.jour<jour) || (A[taille].date.mois>12 || A[taille].date.mois<0) || (A[taille].date.jour<1 || A[taille].date.jour>31) || A[taille].date.annee<2024);
	    taille++;// Incrémenter la taille après avoir ajouté la tâche
       }
   }
// Cette fonction affiche les tâches stockes dans la table A(le choix 2).
void  AFFICHER_LA_LISTE_DES_TACHES(){
  	int i;
  	if(taille==0) printf("pas de taches a executer\n");
  	else
  	    for(i=0;i<taille;i++){
  	    	printf("______________________\n");
  	    	printf("      LA TACHE D'INDICE %d      \n",i);
  	    	printf("%d/%d/%d\n",A[i].date.annee,A[i].date.mois,A[i].date.jour);
  	    	printf("%s\n",A[i].titre);
  	    	printf("%s\n",A[i].descrip);
  	    	printf("%s\n",A[i].priorite);
  	    	printf("______________________\n");
		  }    
  } 
// Cette fonction modifie une tache d'indice i saisie par l'utilsateur(le choix 3). 
void MODIFIER_UNE_TACHE(){
  	    int indice,p;
  	    printf("\n----NUMEROTATION DES TACHES PAR INDICE----\n");
  	    AFFICHER_LA_LISTE_DES_TACHES();
  	    //choix de l'indice de la tache que tu veux modifier
  	    do{
  	    	printf("\nentrez l'indice de la tache que tu veux modifier : ");
  	        scanf("%d",&indice);
		  }while(indice>=taille || indice<0);
      if(taille!=0) {
      	// Menu pour modifier différents attributs de la tâche d'indice donné
      	do{
      	 printf("\n    <MENU DE MODIFICATION>   \n");
  	        printf("1 : modifier le titre\n");
  	        printf("2 : modifier la description\n");
  	        printf("3 : modifier la priorite\n");
  	        printf("4 : modifier la date\n");
  	        printf("5 : quitter\n");
  	        printf("Enter votre choix : ");
            scanf("%d",&p);
  	        switch(p){
  	    	        case 1:// Modifier le titre de la tâche
					        printf("entrez le nouveau titre de la tache\n");
 	                       scanf("%s",A[indice].titre);
				           break;
			        case 2:// Modifier la description de la tâche
					       printf("entrez la nouvelle description de la tache\n");
			               scanf("%s",A[indice].descrip);
				           break;  
			    	case 3: // Modifier la priorité en vérifiant qu'elle est correcte
					        printf("Attention: la priorite prend deux valeurs <%s,%s>\n","high","low");
 	                        do{
 		                    printf("entrez la priorite de la tache : ");
 	                        scanf("%s",A[indice].priorite);
	                        }while(strcmp(A[indice].priorite,"high")!=0 && strcmp(A[indice].priorite,"low")!=0);
	                        break;
				    case 4:	// Modifier la date en s'assurant qu'elle est future
					        printf("Attention : il faut planifier une tache au futur si vous ne respectez pas la date le saise sera afficher une autre fois\n");
 	                        do{
 	                        printf("entrez la date\n");
 	                        scanf("%d %d %d",&A[indice].date.annee,&A[indice].date.mois,&A[indice].date.jour);
	                        }while(A[indice].date.annee<annee || (A[indice].date.annee==annee && A[indice].date.mois<mois) || (A[indice].date.annee==annee && A[indice].date.mois==mois && A[indice].date.jour<jour) || (A[indice].date.mois>12 || A[indice].date.mois<0) || (A[indice].date.jour<1 || A[indice].date.jour>31) || A[indice].date.annee < 2024 );
							break;
					case 5: // Quitter le menu de modification
					        break;
					}		
		   }while(p!=5);
		  }
		else printf("le tableau est vide\n");
	  }
//Cette fonction supprime une tache d'indice i saisie par l'utilsateur(le choix 4).   
void SUPPRIMER_UNE_TACHE(){
		int indice,i;
		if(taille==0){
			printf("pas d'element a supprimer\n");
		}
		else{
	    	printf("ENTREZ L'INDICE DE LA TACHE : ");
		    scanf("%d",&indice);
	    	if(indice>=0 && indice<taille)
	    	for(i=indice;i<taille;i++){
			   A[i]=A[i+1];
		}
	    taille--;
		}	
	}
//Cette fonction filtre le tableau A en fonction du choix 5.	
void  FILTRER_LES_TACHES(){
		char priorite[6];
		int i;
		printf("Attention: la priorite prend deux valeurs [%s,%s]\n","high","low");
		//L'utilisateur doit choisir entre les deux priorités disponibles ('high' ou 'low')
     	do{
 	    	printf("entrez la priorite de la tache : ");
 	        scanf("%s",priorite);
	    }while(strcmp(priorite,"high")!=0 && strcmp(priorite,"low")!=0);
	    //Affichage des tâches qui correspondent à la priorité saisie par l'utilisateur
	    for(i=0;i<taille;i++){
	    	if(strcmp(priorite,A[i].priorite)==0) {
	    		printf("______________________\n");
	    		printf("****LA TACHE D'INDICE %d****\n",i);
  	        	printf("%d/%d/%d\n",A[i].date.annee,A[i].date.mois,A[i].date.jour);
  	    	    printf("%s\n",A[i].titre);
  	    	    printf("%s\n",A[i].descrip);
  	    	    printf("%s\n",A[i].priorite);
  	    	    printf("______________________\n");
	    		
			}
		}
	} 
   
int main(){	
//la variable p indique le choix de l'utilisateur
    int p;
	do{
        printf("\n       <Menu>     \n");
        printf("1-AJOUTER_UNE_TACHE\n");
        printf("2-AFFICHER_LA_LISTE_DES_TACHES\n");
        printf("3-MODIFIER_UNE_TACHE\n");
        printf("4-SUPPRIMER_UNE_TACHE\n");
        printf("5-FILTRER_LES_TACHE\n");
        printf("6-QUITTER\n");
        printf("Enter votre choix : ");
        scanf("%d",&p);
        switch(p){
            case 1:do{
            		
            		printf("entrez la date d'aujourd'hui en respectant les conditions suivantes (1=<mois<=12) et (1=<jour<=31) : ");
			    	scanf("%d/%d/%d",&annee,&mois,&jour);
			    	
		            } while((mois>12 || mois<0) || (jour<1 || jour>31 ) || annee<2024); AJOUTER_UNE_TACHE(); break;
		    
		    case 2:AFFICHER_LA_LISTE_DES_TACHES(); break;
			case 3:MODIFIER_UNE_TACHE(); break;  
			case 4:SUPPRIMER_UNE_TACHE(); break; 
			case 5:FILTRER_LES_TACHES(); break; 
			case 6:break; 	
        }
    }while(p!=6);
	return 0;	
}





