//Creare una semplice struct alunno che contiene il nome, il cognome e il voto. Dopo inserire da 1 a 20 alunni al massimo e permettere di effettuare una ricerca per cognome dell’alunno. Se ci sono più alunni con lo stesso cognome visualizzarli entrambi.
#include <stdio.h>
#include <string.h>
#define MAX 20

typedef struct
        {       
        char cognome[30];
        char nome[20];
        int voto;
        } studente;

int main()
        {
        studente s[MAX];
        char nome_utente[20];
        int n, i, ricerca, close;
        int trovato = 0;
        int j = 0;
        char cognome_alunno[30];
        printf("\nBenvenuto! Questo programma ti permetterà di memorizzare l'elenco dei tuoi alunni e dei loro voti.\nPer cominciare, come ti chiami?\t");
        fgets(nome_utente, 20, stdin);
        
        do
        { printf("\nOttimo Prof. %sAdesso inserisci il numero di alunni (MAX 20):\t", nome_utente);
        scanf("%d", &n);
        } while (n<1 || n>MAX);
        
        for(i=1; i<=n; i++)
                {
                printf("\nInserisci COGNOME:\t");
                scanf("%s", s[i].cognome);
                printf("\nInserisci NOME:\t");
                scanf("%s", s[i].nome);
                printf("\nInserisci VOTO:\t");
                scanf("%d", &s[i].voto);
                printf("\n==============================SUCCESSIVO==============================\n");
                }
                
                printf("\n==============================RICERCA=================================\n");
        for (close=0; close!=1; )
                {
                printf("\nInserisci il cognome dell'alunno da cercare:\t");
                scanf("%s", cognome_alunno);
        for (j=0; j<=n; j++)
                {
                if (strcmp(s[j].cognome, cognome_alunno)==0)
                { printf("\nAlunno trovato in posizione %d.\n%s %s\nVoto: %d\n", j, s[j].cognome, s[j].nome, s[j].voto);
                trovato = 1;
                }
                }
                if (trovato!=1)
                printf("\nSpiacente. Alunno non trovato, premere 0 per riprovare.");
                printf("\nCercare ancora? (1 PER TERMINARE):\t");
                scanf("%d", &close);
                }
                
       return 0;
       }
        

                
