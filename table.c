#include<stdio.h>
#include<string.h>
typedef struct Date{
	int annee;
	int mois;
	int jour;
}Date;
 typedef struct Tache{
 	char titre[20];
 	char descrip[100];
 	char priorite[5];
 	Date date;
 }tache;
 tache A[50];
 int taille=0,jour,mois,annee,n;
 void AJOUTER_UNE_TACHE(){
 	printf("entrez le titre de la tache : ");
 	scanf("%s",A[taille].titre);
 	printf("entrez la description de la tache : ");
    scanf("%s",A[taille].descrip);
 	printf("********[Attention: la priorite prend deux valeurs <%s,%s>]********\n","high","low");
 	do{
 		printf("entrez la priorite de la tache : ");
 	    scanf("%s",A[taille].priorite);
	   }while(strcmp(A[taille].priorite,"high")!=0 && strcmp(A[taille].priorite,"low")!=0);
 	printf("Attention : vous devez planifier une tache pour une date future\n");
 	do{
 	printf("entrez la date : ");
 	scanf("%d/%d/%d",&A[taille].date.annee,&A[taille].date.mois,&A[taille].date.jour);
	  }while(A[taille].date.annee<annee || (A[taille].date.annee==annee && A[taille].date.mois<mois) || (A[taille].date.annee==annee && A[taille].date.mois==mois && A[taille].date.jour<jour));
	 taille++;
    }
 void  AFFICHER_LA_LISTE_DES_TACHES(){
  	int i;
  	if(taille==0) printf("pas de taches a executer\n");
  	else
  	    for(i=0;i<taille;i++){
  	    	printf("****LA TACHE D'INDICE %d****\n",i);
  	    	printf("%d/%d/%d\n",A[i].date.annee,A[i].date.mois,A[i].date.jour);
  	    	printf("%s\n",A[i].titre);
  	    	printf("%s\n",A[i].descrip);
  	    	printf("%s\n",A[i].priorite);
  	    	printf("----------------\n");
		  }    
  } 
 void MODIFIER_UNE_TACHE(){
  	    int indice,p;
  	    printf("\n----NUMEROTATION DES TACHES PAR INDICE----\n");
  	    AFFICHER_LA_LISTE_DES_TACHES();
  	    //choix de l'indice de la tache que tu veux modifier
  	    do{
  	    	printf("entrez l'indice de la tache que tu veux modifier\n");
  	        scanf("%d",&indice);
		  }while(indice>=taille || indice<0);
      if(taille!=0) {
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
  	    	        case 1:printf("entrez le nouveau titre de la tache\n");
 	                       scanf("%s",A[taille].titre);
				           break;
			        case 2:printf("entrez la nouvelle description de la tache\n");
			               scanf("%s",A[taille].descrip);
				           break;  
			    	case 3: printf("Attention: la priorite prend deux valeurs <%s,%s>\n","high","low");
 	                        do{
 		                    printf("entrez la priorite de la tache : ");
 	                        scanf("%s",A[indice].priorite);
	                        }while(strcmp(A[indice].priorite,"high")!=0 && strcmp(A[indice].priorite,"low")!=0);
	                        break;
				    case 4:	printf("Attention : il faut planifier une tache au futur si vous ne respectez pas la date le saise sera afficher une autre fois\n");
 	                        do{
 	                        printf("entrez la date\n");
 	                        scanf("%d %d %d",&A[indice].date.annee,&A[indice].date.mois,&A[indice].date.jour);
	                        }while(A[indice].date.annee<annee || (A[indice].date.annee==annee && A[indice].date.mois<mois) || (A[indice].date.annee==annee && A[indice].date.mois==mois && A[indice].date.jour<jour));
							break;
					case 5:break;
						break;
					}		
		   }while(p!=5);
		  }
		else printf("le tableau est vide\n");
	  }
  	   
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
	void  FILTRER_LES_TACHES(){
		char priorite[6];
		int i;
		printf("Attention: la priorite prend deux valeurs [%s,%s]\n","high","low");
     	do{
 	    	printf("entrez la priorite de la tache : ");
 	        scanf("%s",priorite);
	    }while(strcmp(priorite,"high")!=0 && strcmp(priorite,"low")!=0);
	    for(i=0;i<taille;i++){
	    	if(strcmp(priorite,A[i].priorite)==0) {
	    		printf("****LA TACHE D'INDICE %d****\n",i);
  	        	printf("%d/%d/%d\n",A[i].date.annee,A[i].date.mois,A[i].date.jour);
  	    	    printf("%s\n",A[i].titre);
  	    	    printf("%s\n",A[i].descrip);
  	    	    printf("%s\n",A[i].priorite);
  	    	    printf("----------------\n");
	    		
			}
		}
	} 
	void TRIER_LES_TACHES(){
		char ordre[20];
		int i,j;
		printf("entrez l'ordre\n");
		scanf("%s",ordre);
		if(strcmp(ordre,"croissant")==0)
		    for(i=0;i<taille;i++){
			        for(j=0;j<taille-i-1;j++){
				        if(A[j].date.annee>A[j+1].date.annee){
				            tache echang;
					        echang=A[j+1];
					        A[j+1]=A[j];
					        A[j]=echang;
							} 
				            else if(A[j].date.annee==A[j+1].date.annee){
				            	if(A[j].date.mois>A[j+1].date.mois){
				            	    tache echang;
					                echang=A[j+1];
					                A[j+1]=A[j];
					                A[j]=echang;
								    } 
								    else if(A[j].date.mois==A[j+1].date.mois){
								    	if(A[j].date.jour>A[j+1].date.jour){
				            	        tache echang;
					                    echang=A[j+1];
					                    A[j+1]=A[j];
					                    A[j]=echang;
								        } 
					
			                    	}
				
		                    	}
		                   }
                     	} 
        if(strcmp(ordre,"decroissant")==0)  
         for(i=0;i<taille;i++){
			        for(j=0;j<taille-i-1;j++){
				        if(A[j].date.annee<A[j+1].date.annee){
				            tache echang;
					        echang=A[j+1];
					        A[j+1]=A[j];
					        A[j]=echang;
							} 
				            else if(A[j].date.annee==A[j+1].date.annee){
				            	if(A[j].date.mois<A[j+1].date.mois){
				            	    tache echang;
					                echang=A[j+1];
					                A[j+1]=A[j];
					                A[j]=echang;
								    } 
								    else if(A[j].date.mois==A[j+1].date.mois){
								    	if(A[j].date.jour<A[j+1].date.jour){
				            	        tache echang;
					                    echang=A[j+1];
					                    A[j+1]=A[j];
					                    A[j]=echang;
								        } 
					
			                    	}
				
		                    	}
		                   }
                     	} 
                    }
		                
int main(){	
    int p;
	do{
        printf("\n       <Menu>     \n");
        printf("1-AJOUTER_UNE_TACHE\n");
        printf("2-AFFICHER_LA_LISTE_DES_TACHES\n");
        printf("3-MODIFIER_UNE_TACHE\n");
        printf("4-SUPPRIMER_UNE_TACHE\n");
        printf("5-FILTRER_LES_TACHE\n");
        printf("6-TRIER_LES_TACHE\n");
        printf("7-QUITTER\n");
        printf("Enter votre choix : ");
        scanf("%d",&p);
        switch(p){
            case 1:{
            	do{
            		printf("entrez la date d'aujourd'hui en respectant les conditions suivantes (1=<mois<=12) et (1=<jour<=31) : ");
			    	scanf("%d/%d/%d",&annee,&mois,&jour);
		        }while((mois>12 || mois<0) || (jour<1 || jour>31 ));
				AJOUTER_UNE_TACHE();
				break;
		     	}
		    case 2:AFFICHER_LA_LISTE_DES_TACHES(); break;
			case 3:MODIFIER_UNE_TACHE(); break;  
			case 4:SUPPRIMER_UNE_TACHE(); break; 
			case 5:FILTRER_LES_TACHES(); break; 
			case 6:TRIER_LES_TACHES(); break;
			case 7:break; 	
        }
    }while(p!=7);
	return 0;	
}





