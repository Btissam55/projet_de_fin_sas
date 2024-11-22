#include<stdio.h>
#include<string.h>
typedef struct Date{
	int mois;
	int jour;
	int heure;
}Date;
 typedef struct Tache{
 	char titre[20];
 	char descrip[100];
 	char priorite[5];
 	Date date;
 }tache;
 tache A[50];
 int taille=0,jour,n,heure,mois;
 void AJOUTER_UNE_TACHE(){
 	printf("entrez le titre de la tache : ");
 	scanf("%s",A[taille].titre);
 	printf("entrez la description de la tache : ");
    scanf("%s",A[taille].descrip);
 	printf("Attention: la priorite prend deux valeurs [%s,%s]\n","high","low");
 	do{
 		printf("\nentrez la priorite de la tache : ");
 	    scanf("%s",A[taille].priorite);
	   }while(strcmp(A[taille].priorite,"high")!=0 && strcmp(A[taille].priorite,"low")!=0);
 	printf("Attention : il faut planifier une tache au futur si vous ne respectez pas la date la saise sera afficher une autre fois\n");
 	do{
 	printf("entrez la date\n");
 	scanf("%d %d %d",&A[taille].date.mois,&A[taille].date.jour,&A[taille].date.heure);
	  }while(A[taille].date.mois<mois || (A[taille].date.mois==mois && A[taille].date.jour<jour) || (A[taille].date.mois==mois && A[taille].date.jour==jour && A[taille].date.heure<heure) || (A[taille].date.mois>12 || A[taille].date.mois<0) || (A[taille].date.jour<1 ||  A[taille].date.jour>31)  || (A[taille].date.heure>24 || A[taille].date.heure<0));
 	taille++;
    }
  void AFFICHER_LA_LISTE_DES_TACHES(){
  	int i;
  	if(taille==0) printf("pas de taches a executer\n");
  	else
  	    for(i=0;i<taille;i++){
  	    	printf("****LA TACHE D'INDICE %d****\n",i);
  	    	printf("%d/%d/%d\n",A[i].date.heure,A[i].date.jour,A[i].date.mois);
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
		  }while(indice>=taille);
  	    if(indice>=0 && indice<=taille){
  	        //siginifie le nombre de modification que l'utilisateur veut faire
  	        int nombre;
  	        printf("entrez le nombre de modification\n");
  	        scanf("%d",&nombre);
  	        if(nombre<4){
  	        while(nombre!=0){
  	    	    printf("\n******MENU DE MODIFICATION******\n");
  	            printf("1 : modifier le titre\n");
  	            printf("2 : modifier la description\n");
  	            printf("3 : modifier la priorite\n");
  	            printf("4 : modifier la date\n");
  	            printf("Enter votre choix : \n");
                scanf("%d",&p);
  	            switch(p){
  	    	        case 1:printf("entrez le titre de la tache\n");
 	                       scanf("%s",A[taille].titre);
				           break;
			        case 2:printf("entrez la description de la tache\n");
			               scanf("%s",A[taille].descrip);
				           break;  
			    	case 3: printf("Attention: la priorite prend deux valeurs [%s,%s] ","high","low");
 	                        do{
 		                    printf("\nentrez la priorite de la tache\n");
 	                        scanf("%s",A[indice].priorite);
	                        }while(strcmp(A[indice].priorite,"high")!=0 && strcmp(A[indice].priorite,"low")!=0);
	                        break;
				    case 4:	printf("Attention : il faut planifier une tache au futur si vous ne respectez pas la date le saise sera afficher une autre fois\n");
 	                        do{
 	                        printf("entrez la date\n");
 	                        scanf("%d %d %d",&A[indice].date.mois,&A[indice].date.jour,&A[indice].date.heure);
	                        }while(A[indice].date.mois<mois || (A[indice].date.mois==mois && A[indice].date.jour<jour) || (A[indice].date.mois==mois && A[indice].date.jour==jour && A[indice].date.heure<heure));
							break;  
		           }
		           nombre--;
		        }
		    }
	     	else if(nombre==4){
		        printf("entrez le titre de la tache\n");
 	            scanf("%s",A[taille].titre);
 	            printf("entrez la description de la tache\n");
 	            scanf("%s",A[taille].descrip);
 	            printf("Attention: la priorite prend deux valeurs [%s,%s] ","high","low");
 	            do{
 		            printf("\nentrez la priorite de la tache\n");
 	                scanf("%s",A[indice].priorite);
	            }while(strcmp(A[indice].priorite,"high")!=0 && strcmp(A[indice].priorite,"low")!=0);
 	            printf("Attention : il faut planifier une tache au futur si vous ne respectez pas la date le saise sera afficher une autre fois\n");
 	            do{
 	                printf("entrez la date\n");
 	                scanf("%d %d %d",&A[indice].date.mois,&A[indice].date.jour,&A[indice].date.heure);
	            }while(A[indice].date.mois<mois || (A[indice].date.mois==mois && A[indice].date.jour<jour) || (A[indice].date.mois==mois && A[indice].date.jour==jour && A[indice].date.heure<heure) || (A[taille].date.mois>12 || A[taille].date.mois<0) || (A[taille].date.jour<1 ||  A[taille].date.jour>31) || (A[taille].date.heure>24 || A[taille].date.heure<0));	
	       	}
		         else printf("vous avez depasser le nombre de champ ");
		}
		else printf("ERROR : VERFIER LA VALEUR DE L'INDICE\n");
    }
	void SUPPRIMER_UNE_TACHE(){
		if(taille==0){
			printf("pas d'element a supprimer\n");
		}
		else{
				int indice,i;
		printf("ENTREZ LA POSITION DE L'INDICE");
		scanf("%d",&indice);
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
 	    	printf("\nentrez la priorite de la tache : ");
 	        scanf("%s",priorite);
	    }while(strcmp(priorite,"high")!=0 && strcmp(priorite,"low")!=0);
	    
	    for(i=0;i<taille;i++){
	    	if(strcmp(priorite,A[i].priorite)==0) {
	    		printf("****LA TACHE D'INDICE %d****\n",i);
  	        	printf("%d/%d/%d\n",A[i].date.heure,A[i].date.jour,A[i].date.mois);
  	    	    printf("%s\n",A[i].titre);
  	    	    printf("%s\n",A[i].descrip);
  	    	    printf("%s\n",A[i].priorite);
  	    	    printf("----------------\n");
	    		
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
        printf("==Enter votre choix== ");
        scanf("%d",&p);
        switch(p){
            case 1:{
            	do{
            		printf("entrez la date d'aujourd'hui en respectant les conditions suivante: \n*1=<mois<=12*\t*1=<jour<=31*\tt*0=<heure<=23*\n");
			    	scanf("%d%d%d",&mois,&jour,&heure);
		        }while((mois>12 || mois<0) || (jour<1 ||  jour>31 ) || (heure>24 || heure<0));
				AJOUTER_UNE_TACHE();
				break;
		     	}
		    case 2:AFFICHER_LA_LISTE_DES_TACHES(); break;
			case 3:MODIFIER_UNE_TACHE(); break;  
			case 4:SUPPRIMER_UNE_TACHE(); break; 
			case 5:FILTRER_LES_TACHES(); break;   	
        }
    }while(p!=6);	
}





