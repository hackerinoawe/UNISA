//Si consideri una struttura rappresentante un punto e si rappresenti un triangolo come array di 3 punti (i vertici)
//Scrivere un programma che verifichi se due triangoli hanno lo stesso perimentro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAXNOME 20

typedef struct punto
        {
        int x, y;
        } punto;
        
        
void inserimento (punto tr[3]);

int perimetro (punto, punto, punto); //calcolo del perimetro

int main(void)
        {
        punto tr1[3], tr2[3]; //array di struct per i due triangoli
        double tr1_perimetro, tr2_perimetro;
        char nome[MAXNOME];
        
        printf("\nBenvenuto. Questo script ti permetterà di comparare il perimetro di due triangoli.\nCOME TI CHIAMI?\t");
        
        fgets(nome, MAXNOME, stdin); //prendo nome
        nome[strlen(nome)-1] = '\0'; //aggiusto solito bug
        
        printf("\nOttimo Prof. %s, procediamo.\n\n", nome);
        
        //FASE INSERIMENTO COORDINATE
        printf("\n=====TRIANGOLO 1:\n");
        inserimento(tr1);
        
        printf("\n=====TRIANGOLO 2:\n");
        inserimento(tr2);
        
        printf("\nOttimo, i dati sono stati acquisiti!\n");
        printf("TR1: A=%d;%d - B=%d;%d - C=%d;%d\n", tr1[0].x, tr1[0].y, tr1[1].x, tr1[1].y, tr1[2].x, tr1[2].y);
        printf("TR2: A=%d;%d - B=%d;%d - C=%d;%d\n", tr2[0].x, tr2[0].y, tr2[1].x, tr2[1].y, tr2[2].x, tr2[2].y);
        
        printf("\n=====CALCOLO I PERIMETRI:\n");
        tr1_perimetro = perimetro(tr1[0], tr1[1], tr1[2]);
        tr2_perimetro = perimetro(tr2[0], tr2[1], tr2[2]);
        printf("\nPERIMETRO TR1:\t%f e PERIMETRO TR2:\t%f", tr1_perimetro, tr2_perimetro);
        
        //CONFRONTO PERIMETRI
        if(tr1_perimetro==tr2_perimetro)
                {       printf("\nI DUE TRIANGOLI HANNO LO STESSO PERIMETRO.\n"); }
                else printf("\n\nI DUE TRIANGOLI HANNO PERIMETRI DIVERSI.\n");
         
        
        return 0;
        }
        
        
        
        
        
        
        
void inserimento (punto tr[3])
        {
        int i;
        char punti[3] = {'A', 'B', 'C'};
        for (i=0; i<3; i++)
                {
                printf("\nInserisci ascissa e ordinata del punto %c:\t", punti[i]);
                scanf("%d %d", &tr[i].x, &tr[i].y);
                }
        }

int perimetro (punto A, punto B, punto C)
        {
        int xA = A.x, xB = B.x, xC = C.x;
        int yA = A.y, yB = B.y, yC = C.y;
        double seg_AB, seg_BC, seg_CA;
        seg_AB = sqrt(pow(xB-xA, 2) + pow(yB-yA, 2));
        seg_BC = sqrt(pow(xC-xB, 2) + pow(yC-yB, 2));
        seg_CA = sqrt(pow(xA-xC, 2) + pow(yA-yC, 2));
        double perimetro;
        perimetro = seg_AB + seg_BC + seg_CA;
        return (perimetro);
        }
                
               
        
        
        
                 
        
