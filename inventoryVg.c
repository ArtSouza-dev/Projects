/******************************************************************************
Title: Final Project - Video Games Inventory
Author: Artur Souza
Studant nº: 2130631
Version: 0.1
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct video_game{
    long int sku;
    char name[25];
    char studio[25];
    char type[14];
    char esbRating[6];
    int metacriticRating;
    char platform[20]; 
    bool modes[2][3];  
    long int sellingPrice;
    bool isDigital;
}vg;

vg games[50];

void fillVg();

void printVg(int);

int k=0;

int main(){
    
    int menuOptions;
    
    do{
        printf("SELECT ONE OPTION:\n-Populate the inventory (enter 1)\n-Search for games (enter 2)\n-Edit an entry (enter 3)\n-Display all games (enter 4)\n-Exit (enter 5)\n");
        scanf("%d", &menuOptions); 
        printf("\n");
        
        //populating variables
        int vgInputs;
        char repInputs;
        
        //searching variables
        vg criteriasSearch;  
        int criteriasNum;  
        int criteria; 
        int output[k];
        int counter=0;
        int index;
        int modesCounter=0;
        
        //editing variables
        long int skuEdit;
        
        switch (menuOptions){
            case 1: // 1.Populate the inventory 
            do{
                do{
                    printf("How many games are going to be entered?\n");
                    scanf("%d", &vgInputs);
                    printf("\n");
                } while (vgInputs<=0);
                    
                for (int i=0; i<vgInputs; i++){
                    printf("----ENTER THE INFORMATION ABOUT THE GAME NUMBER %d:\n\n", i+1);
                    fillVg ();
                    k++;
                }
                fflush(stdin); 
                printf("Input more games?(y/n)\n");
                scanf("%c", &repInputs);
            }while (repInputs == 'Y' || 'y');
            break;
                    
            case 2: // 2.Search for games that match a single or a combination of criteria entered by the user 
            do{
                printf("How many search criterias will be applied?");
                scanf("%d", &criteriasNum);
            }while (criteriasNum<=0);
                    
            for (int i=0; i<criteriasNum; i++){
                printf("----INFORM THE CRITERIA NUMBER %d:\n-SKU (enter 1)\n-Name (enter 2)\n-Studio (enter 3)\n-Type (enter 4)\n-ESRB Rating (enter 5)\n-Metacritic Rating (enter 6)\n-Platform (enter 7)\n-Modes (enter 8)\n-Selling Price (enter 9)\n-Digital (enter 10)\n", i+1);
                scanf("%d", &criteria);
                        
                switch (criteria){
                    case 1:
                    printf("Enter the SKU to be searched:\n");
                    scanf("%ld", &criteriasSearch.sku);
                    for (int i=0; i<k; i++){
                        if (criteriasSearch.sku==games[i].sku){
                            counter=counter++;
                            index=i;
                        }
                    }
                    break;
                
                    case 2:
                    printf("Enter the Name to be searched:\n");
                    fgets(criteriasSearch.name,25,stdin);
                    getchar();
                    for (i=0; i<k; i++){
                        if (strcmp(criteriasSearch.name,games[i].name)==0){
                            counter=counter++;
                            index=i;
                        }
                    }
                    break;
                        
                    case 3:
                    printf("Enter the Studio to be searched:\n");
                    fgets(criteriasSearch.studio,25,stdin);
                    getchar();
                    for (i=0; i<k; i++){
                        if (strcmp(criteriasSearch.studio,games[i].studio)==0){
                            counter=counter++;
                            index=i; 
                        }
                    }
                    break;
                    
                    case 4:
                    printf("Enter the type to be searched:\n");
                    fgets(criteriasSearch.type,14,stdin);
                    getchar();
                    for (i=0; i<k; i++){
                        if (strcmp(criteriasSearch.type,games[i].type)==0){
                            counter=counter++;
                            index=i; 
                        }
                    }
                    break;
                        
                    case 5:
                    printf("Enter the ESRB Rating to be searched:\n");
                    fgets(criteriasSearch.esbRating,6,stdin);
                    getchar();
                    for (i=0; i<k; i++){
                        if (strcmp(criteriasSearch.esbRating,games[i].esbRating)==0){
                            counter=counter++;
                            index=i; 
                        }
                    }
                    break;
                    
                    case 6:
                    printf("Enter the Metacritic Rating to be searched:\n");
                    scanf("%d", &criteriasSearch.metacriticRating);
                    for (i=0; i<k; i++){
                        if (criteriasSearch.metacriticRating == games[i].sku){ 
                            counter=counter++;
                            index=i; 
                        }  
                    }
                    break;
                    
                    case 7:
                    printf("Enter the Platform to be searched:\n");
                    fgets(criteriasSearch.platform,20,stdin);
                    getchar();
                    for (i=0; i<k; i++){
                        if (strcmp(criteriasSearch.platform,games[i].platform)==0){
                            counter=counter++;
                            index=i; 
                        }
                    }
                    break;
                    
                    case 8:  
                    printf("Enter the Modes supported by the searched game:\n");
                    for (int o=0; o<k; o++){    
                        for (int i=0; i<2; i++){ 
                            switch(i){
                                case 0:
                                for (int j=0; j<3; j++){
                                    switch (j){
                                        case 0:
                                        printf("Is the game locally based and has single player option? (1=yes 0=no)\n");
                                        scanf("%d", &criteriasSearch.modes[i][j]);
                                        if (criteriasSearch.modes[i][j]==games[o].modes[i][j])
                                            modesCounter++;

                                        case 1:
                                        printf("Is the game locally based and has coop option? (1=yes 0=no)\n");
                                        scanf("%d", &criteriasSearch.modes[i][j]);
                                        if (criteriasSearch.modes[i][j]==games[o].modes[i][j])
                                            modesCounter++; 

                                        case 2:
                                        printf("Is the game locally based and has competition option? (1=yes 0=no)\n");
                                        scanf("%d", &criteriasSearch.modes[i][j]);
                                            if (criteriasSearch.modes[i][j]==games[o].modes[i][j])
                                                modesCounter++; 
                                    }
                                }
                                
                                case 1:
                                for (int j=0; j<3; j++){
                                    switch (j){
                                        case 0:
                                        printf("Is the game cloud based and has single player option? (1=yes 0=no)\n");
                                        scanf("%d", &criteriasSearch.modes[i][j]);
                                        if (criteriasSearch.modes[i][j]==games[o].modes[i][j])
                                            modesCounter++; 

                                        case 1:
                                        printf("Is the game cloud based and has coop option? (1=yes 0=no)\n");
                                        scanf("%d", &criteriasSearch.modes[i][j]);
                                        if (criteriasSearch.modes[i][j]==games[o].modes[i][j])
                                            modesCounter++; 

                                        case 2:
                                        printf("Is the game cloud based and has competition option? (1=yes 0=no)\n");
                                        scanf("%d", &criteriasSearch.modes[i][j]);
                                        if (criteriasSearch.modes[i][j]==games[o].modes[i][j])
                                            modesCounter++; 
                                    }            
                                }
                            }
                        }
                    }
                        
                    if (modesCounter==6)
                        counter=counter++;
                    break;
                        
                    case 9:
                    printf("Enter the Selling Price to be searched:\n");
                    scanf("%ld", &criteriasSearch.sellingPrice);
                    for (i=0; i<k; i++){
                        if (criteriasSearch.sellingPrice == games[i].sellingPrice){
                            counter=counter++;
                            index=i; 
                        }
                    }
                    break;
                    
                    case 10:
                    printf("Inform if the searched game is digital:\n");
                    scanf("%d", &criteriasSearch.isDigital);
                    for (i=0; i<k; i++){
                        if (criteriasSearch.isDigital == games[i].isDigital){
                            counter=counter++;
                            index=i; 
                        }
                    }
                    break;
                }              
            }
            
            if (counter==criteriasNum){
                printf("SEARCH RESULT:\n");
                printVg(index);
            }
            break;
            
            case 3: // 3.Edit an entry given its ID
            printf("----ENTER THE SKU TO EDIT THE DATA:\n");
            scanf("%ld", &skuEdit);
            for (int i=0; i<k; i++){
                if (skuEdit == games[i].sku)
                    fillVg(i);
            }
            break;
            
            case 4: // 4.Display all games in the inventory
            printf("----ALL GAMES:\n");
            for (int i=0; i<k; i++)
                printVg(i);
            break;
        }     
    }while (menuOptions != 5);
  
return 0;
    
} 
    
void fillVg(){
    
    printf("Enter the game unique ID\n");
    scanf("%ld", &games[k].sku);
    fflush(stdin);
    
    printf("Enter the name of the game\n");
    fgets(games[k].name,25,stdin);
    fflush(stdin);
    
    printf("Enter the game's studio\n");
    fgets(games[k].studio,25,stdin);
    fflush(stdin);
    
    printf("Enter the game type (action, idle, role-playing, simulation, sports, strategy, other)\n");
    fgets(games[k].type,14,stdin);
    fflush(stdin);
    
    printf("Enter the age restriction (E, E10+, T, M, A, RP):\n");
    fgets(games[k].esbRating,6,stdin);
    fflush(stdin);
    
    printf("Enter the metacritic rating (out of 100):\n");
    scanf("%d", &games[k].metacriticRating);
    fflush(stdin);
    
    printf("Enter the platform (PS, Xbox, Nintendo Switch, PC, Mobile, Streaming (Google Stadia/Amazon Luna)):\n");
    fgets(games[k].platform,20,stdin);
    fflush(stdin);
    
    for (int i=0; i<2; i++){ 
        switch(i){
            case 0:
            for (int j=0; j<3; j++){
                switch (j){
                    case 0: 
                    printf("Is the game locally based and has single player option? (1=yes 0=no)\n");
                    scanf("%d", &games[k].modes[i][j]);
                    break;

                    case 1: 
                    printf("Is the game locally based and has coop option? (1=yes 0=no)\n");
                    scanf("%d", &games[k].modes[i][j]);
                    break;

                    case 2:
                    printf("Is the game locally based and has competition option? (1=yes 0=no)\n");
                    scanf("%d", &games[k].modes[i][j]);
                    break;
                }
                break;
            }
            
            case 1:
            for (int j=0; j<3; j++){
                switch (j){
                    case 0: 
                    printf("Is the game cloud based and has single player option? (1=yes 0=no)\n");
                    scanf("%d", &games[k].modes[i][j]);
                    break;
                    
                    case 1: printf("Is the game cloud based and has coop option? (1=yes 0=no)\n");
                    scanf("%d", &games[k].modes[i][j]);
                    break;
                    
                    case 2: 
                    printf("Is the game cloud based and has competition option? (1=yes 0=no)\n");
                    scanf("%d", &games[k].modes[i][j]);
                    break;
                }
                break;
            }    
        }
    }
    
    printf("Enter the selling price of the game\n");
    scanf("%ld", &games[k].sellingPrice);
    
    printf("Is the game digital? (1 for yes, 0 for no)\n");
    scanf("%d", &games[k].isDigital);
}

void printVg(int k){

    printf("sku: %ld\n", games[k].sku);
    
    puts(games[k].name);
    
    puts(games[k].studio);
    
    puts(games[k].type);
    
    puts(games[k].esbRating);
    
    printf("%d", games[k].metacriticRating); 
    
    puts(games[k].platform);
    
    for (int i=0; i<2; i++){ 
        for (int j=0; j<3; j++){
            if (i==0) {
                switch (j){
                    case 0: 
                    if (games[k].modes[i][j]==1)
                    printf("The game is locally based and support single player mode");
                    break;
                                        
                    case 1: 
                    if (games[k].modes[i][j]==1)
                    printf("The game is locally based and support coop mode"); 
                    break;
                                    
                    case 2: 
                    if (games[k].modes[i][j]==1)
                    printf("The game is locally based and support competition mode");
                    break;
                }
                break;
            }
            if (i==1){
                switch (j){
                    case 0: 
                    if (games[k].modes[i][j]==1)
                    printf("The game is cloud based and support single player mode");
                    break;
                            
                    case 1: 
                    if (games[k].modes[i][j]==1)
                    printf("The game is cloud based and support coop mode");
                    break;
                    
                    case 2: 
                    if (games[k].modes[i][j]==1)
                    printf("The game is cloud based and support competition mode");
                    break;
                }
                break;
            }
        }
    }
    
    printf("%ld", games[k].sellingPrice);
    
    printf("%d", games[k].isDigital);
}
