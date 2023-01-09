#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
        {
        char *cognome;
        char *nome;
        int matricola;
        } studente;


void saveStud(studente **, char **, int); //copia le info sullo studente nel main nella struct studente tipo info1

void saveStudInput(studente **, studente **);

void cmpStud(studente **, studente **, studente **);

int freeRec(studente **, studente **, studente**);

int main(void)
        {
        char *infoStudente[] = {"Mickey", "Mouse"};
        int matr = 12345;
        
        studente *info1, *info2, *info3;
        saveStud(&info1, infoStudente, matr);
        saveStudInput(&info1, &info2);
        printf("\nINFO1\nNome:\t%s\nCognome:\t%s\nMatricola:\t%d\n", info1->nome, info1->cognome, info1->matricola);
        printf("\nINFO2\nNome:\t%s\nCognome:\t%s\nMatricola:\t%d\n", info2->nome, info2->cognome, info2->matricola);
        
        cmpStud(&info1, &info2, &info3);
        printf("\nINFO3\nNome:\t%s\nCognome:\t%s\nMatricola:\t%d\n", info3->nome, info3->cognome, info3->matricola);
        
        if (freeRec(&info1, &info2, &info3)== 0)
        printf("\nMemoria liberata correttamente.\n");
        else printf("\nMemoria NON LIBERATA.\n");
        
        
        return 0;
        }

void saveStud (studente **rec, char **data, int matrix)
        {
        
        (*rec) = malloc(sizeof(studente));
        (*rec)->cognome = calloc((strlen(data[0])) +1, sizeof(char));
        (*rec)->nome = calloc((strlen(data[1])) +1, sizeof(char));
        
        strcpy ((*rec)->cognome, data[0]);
        strcpy ((*rec)->nome, data[1]);
        (*rec)->matricola = matrix;
        }
        

void saveStudInput(studente **rec1, studente **rec2)
        {
        (*rec2) = malloc(sizeof(studente));
        (*rec2)->cognome = calloc(strlen((*rec1)->cognome) + 1, sizeof(char));
        (*rec2)->nome = calloc(strlen((*rec1)->nome) + 1, sizeof(char));
        
        
        strcpy ((*rec2)->cognome, (*rec1)->cognome);
        strcpy ((*rec2)->nome, (*rec1)->nome);
        (*rec2)->matricola = (*rec1)->matricola;
        }
        
void cmpStud(studente **rec1, studente **rec2, studente **rec3)
        {
        
        (*rec3) = malloc(sizeof(studente));
        (*rec3)->cognome = calloc(strlen((*rec1)->cognome) + 1, sizeof(char));
        (*rec3)->nome = calloc(strlen((*rec1)->nome) + 1, sizeof(char));
        
        
        int uguali = 0; //0=false
        if ((strcmp((*rec1)->cognome, (*rec2)->cognome)) && (strcmp((*rec1)->nome, (*rec2)->nome)) && ((*rec1)->matricola = (*rec2)->matricola))
        {
        uguali = 1;
        } else uguali = 0;
        
        if (uguali=1)
                {
                saveStudInput(rec2, rec3);
                } else printf("\nNon sono uguali");
        }
                
        
int freeRec(studente **rec1, studente **rec2, studente**rec3)
        {
        free(*rec1);
        free(*rec2);
        free(*rec3);
        
        return 0;
        }
