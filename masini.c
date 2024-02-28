#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {  //Creaerea structruii de date
    char *brand;
    char *numarul;
    char *combustibil;
    double consum;
    int km;
} InformtiileMasinei;

void CerinatA(InformtiileMasinei *Date, int *benz, int *motori, int *hib, int *elect, int Num){
    int i;
    for ( i = 0; i < Num; i++) // Cauta prin toata structuctura tipul masinei 
    {
        if (strcmp(Date[i].combustibil, "benzina") == 0)
        {
            (*benz) += 1;
        }
        else if (strcmp(Date[i].combustibil, "motorina") == 0)
        {
            (*motori) += 1;
        }
        else if (strcmp(Date[i].combustibil, "hibrid") == 0)
        {
            (*hib) += 1;
        }
        else
        {
            (*elect) += 1;
        }
    }
}

void CerintaB(InformtiileMasinei *Date, char *Modelul, int Maxim, double *out_Consum, double *rezult){
    int i;
    double Consum_Total;
    const double Consum_benzina = 8.02;
    const double Consum_Motorina = 9.29;

    for (i = 0; i < Maxim; i++) // Cauta prin structura aceiasi marca de masina 
    {
        if (strcmp(Modelul, Date[i].brand) == 0)
        {
            Consum_Total = (double)((Date[i].consum * Date[i].km) / 100); // Daca gaseste calculeaza consumul total
            *(out_Consum) += Consum_Total;
            if (strcmp(Date[i].combustibil, "benzina") == 0) //Calculeaza pretul total pe baza tipului de masina 
            {
                *(rezult) += Consum_benzina * Consum_Total;
            }
            else if (strcmp(Date[i].combustibil, "motorina") == 0)
            {
                *(rezult) += Consum_Motorina * Consum_Total;
            }
            else if (strcmp(Date[i].combustibil, "hibrid") == 0)
            {
                *(rezult) += Consum_benzina * Consum_Total;
            }
            memset(Date[i].brand ,0 ,strlen(Date[i].brand));     // Marca masinei folosita este inlocuita cu 0
        }
    }
}

void CerintaC(InformtiileMasinei *Date, int Numarul_Masinei, int *Incorect){
    char Numarul_de_Inmatriculare[21];
    int Lungime;
    int i;

    strcpy(Numarul_de_Inmatriculare, Date[Numarul_Masinei].numarul); //Copierea Nr.de inmatriculare si aflarea lungimei lui
    Lungime = strlen(Date[Numarul_Masinei].numarul);

    if ((Numarul_de_Inmatriculare[0] < 64) || (Numarul_de_Inmatriculare[0]  > 91)) // Daca la inceput nu e litera rezulta ca e gresit nr.
    {
        *(Incorect) += 1;
    }
    for (i = Lungime - 1; i > Lungime - 4; i--) // Daca ultimele 3 caractere nu sunt litere rezulta ca e gresit nr.
    {
        if ((Numarul_de_Inmatriculare[i] < 64) || (Numarul_de_Inmatriculare[i]  > 91))
        {
            *(Incorect) += 1;
        }
    }
    for (i = Lungime - 4; i > Lungime - 6; i--) // Daca urmatorele 2 caractere nu sunt numere rezulta ca e gresit nr.
    {
        if ((Numarul_de_Inmatriculare[i] < 48) || (Numarul_de_Inmatriculare[i]  > 58))
        {
            *(Incorect) += 1;
        }
    }
    if (Lungime == 8) // Daca lungimea nr. este 8 se afla daca al doilea caracter este cifra si al 3 este litera
    {
        if ((Numarul_de_Inmatriculare[2] < 48) || (Numarul_de_Inmatriculare[2]  > 58))
        {
            *(Incorect) += 1;
        }
        else if ((Numarul_de_Inmatriculare[1] < 64) || (Numarul_de_Inmatriculare[1]  > 91))
        {
            *(Incorect) += 1;
        }
    }
}

int main() {
    int i, Numarul_de_Caractere, Numarul_de_Masini; 
    char Cerinta, auxiliar[21];
    scanf("%d", &Numarul_de_Masini);

    InformtiileMasinei *IMasina = (InformtiileMasinei *) malloc(Numarul_de_Masini * sizeof (InformtiileMasinei)); // Alocare dinamica a memoriei la structura de date
    for ( i = 0; i < Numarul_de_Masini; i++)
    {
        scanf("%s", auxiliar);        // Alocare dinamica a memoriei la fiecare sir de carcatere aparte 
        Numarul_de_Caractere = strlen(auxiliar) + 1;
        IMasina[i].brand = (char *)malloc(Numarul_de_Caractere * sizeof(char));
        strcpy(IMasina[i].brand, auxiliar); //Citirea datelor si atribuirea lor la structura

        scanf("%s", auxiliar);
        Numarul_de_Caractere = strlen(auxiliar) + 1;
        IMasina[i].numarul = (char *)malloc(Numarul_de_Caractere * sizeof(char));
        strcpy(IMasina[i].numarul, auxiliar);

        scanf("%s", auxiliar);
        Numarul_de_Caractere = strlen(auxiliar) + 1;
        IMasina[i].combustibil = (char *)malloc(Numarul_de_Caractere * sizeof(char));
        strcpy(IMasina[i].combustibil, auxiliar);

        scanf("%lf", &IMasina[i].consum); // Citirea datelor care nu sunt de tip string
        scanf("%d", &IMasina[i].km);
    }
    scanf("\n%c", &Cerinta); // Cerinta aleasa
    // Cerinta A
    if (Cerinta == 'a')
    {
        int benzina = 0, motorina = 0, hibrid = 0, electric = 0;
        CerinatA(IMasina, &benzina, &motorina, &hibrid, &electric, Numarul_de_Masini);
        printf("benzina - %d\n", benzina);
        printf("motorina - %d\n", motorina);
        printf("hibrid - %d\n", hibrid);
        printf("electric - %d\n", electric);
    }
    // Cerinta B
    else if (Cerinta == 'b')
    {
        int i, j;
        double Output_Consum, rezultat;

        for (i = 0; i < 21; i++)
        {
            auxiliar[i] = '0'; //Atribuirea sirului auxiliar cu 0
        }
        for (i = 0; i < Numarul_de_Masini; i++) // Cauta un marca de masina care nu o fost folosita
        {
            if (strcmp(IMasina[i].brand, auxiliar) > 0)
            {
                Output_Consum = 0;
                rezultat = 0;

                strcpy(auxiliar, IMasina[i].brand); // Este copiata marca in auxilar pentru a fi trimisa in functie
                CerintaB(IMasina, auxiliar, Numarul_de_Masini, &Output_Consum, &rezultat);
                printf("%s a consumat %.2lf - %.2lf lei\n", auxiliar, Output_Consum, rezultat);
                for (j = 0; j < 21; j++)
                {
                    auxiliar[j] = '0';  //Reatribuirea sirului auxiliar cu 0
                }
            }
        }
    }
    // Cerinta C
    else
    {
        int Incorecte = 0, Counter;
        int i;
        for (i = 0; i < Numarul_de_Masini; i++)
        {
            Counter = 0;
            CerintaC(IMasina, i, &Counter);
            if (Counter != 0) // Daca este o gresala in numarul de inmatriculare el afiseaza marca si numarul gresit
            {
                printf("%s cu numarul %s: numar invalid\n", IMasina[i].brand, IMasina[i].numarul);
                Incorecte ++;
            }
        }
        if (Incorecte == 0) // Daca sunt toate corecte se executa
        {
            printf("Numere corecte!\n");
        } 
    }

    for (i = 0; i < Numarul_de_Masini; i++)
    {
        free(IMasina[i].brand);
        free(IMasina[i].numarul);
        free(IMasina[i].combustibil);
    }
    
    free(IMasina); // Elibereaza spatiul folosit
    return 0;
}