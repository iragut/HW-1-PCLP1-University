#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Afisare(char *numar, int Lumgimea) //Afisare sirului de caractere
{
    int i;
    for (i = 0; i < Lumgimea - 1; i++)
    {
        printf("%c", *(numar + i));
    }
    printf("\n");
}
void Copiere(char *copy, char *nr, int inceput, int final) //Functia de copiere a unui numar
{
    int i, j = 0;
    for (i = inceput; i <= final; i++)
    {
        copy[j] = nr[i];
        j++;
    }
}
void CalculCuAcelasiSemn(char *rezultat, char *nr1, char *nr2, int terminarea_P, int inceperea_P){ //Calculare cu acelasi semn
    int i, Zecimal = 0, Nr_auxiliar;

    for (i = terminarea_P; i >= inceperea_P; i--)
    {
        Nr_auxiliar = (nr1[i] - 48) + (nr2[i] - 48) + Zecimal; //Adunare numarului 
        if (Nr_auxiliar / 10 != 0) // Daca e mai mare decat zece se adauga 1 la urmatorul numar
        {
            Zecimal = Nr_auxiliar / 10;
            rezultat[i] = (Nr_auxiliar % 10) + 48;
        }
        else //Daca e mai mic, egal ca 9 se adauga in sir
        {
            rezultat[i] = Nr_auxiliar + 48;
            Zecimal = 0;
        }
    }
}

void CalculCuSemnDiferit(char *rezultat, char *nr1, char *nr2, int terminarea_P, int inceperea_P, int SemnN){
    int i, j;
    for (i = terminarea_P; i >= inceperea_P; i--)
    {
        if ((nr2[i] > nr1[i]) && (i - 1 != SemnN)) //Daca numarul este mai mic decat cel pe care scazi se cauta o zecimala
        {
            for (j = i - 1; j >= inceperea_P; j--)
            {
                if (nr1[j] != '0')
                {
                    nr1[j] = (nr1[j] - 1); //Daca gaseste se ia una
                    break; 
                }
                else
                {
                    nr1[j] = '9'; // Daca gaseste 0 se va inlocui automat cu 9
                }
            }
            rezultat[i] = (nr1[i] - 48) + 10 - (nr2[i] - 48) + 48;
        }
        else //Scaderea si adaugarea la sir a numarului 
        {
            rezultat[i] = abs((nr1[i] - nr2[i])) + 48;
        }
    }
}

void Adunare(char *numarul1, char *numarul2, int DimensiuneaV){
    int Semnul_P_Imaginara, Semnul_P_Reale = 0; 
    int Terminare_P_Reale, Terminare_P_Imaginare;
    char rezultatul[1001], copiereNr1[501], copiereNr2[501];

    Semnul_P_Imaginara = (DimensiuneaV - 1) / 2; //Calcularea pozitiior a numarului imaginar si real
    Terminare_P_Imaginare = DimensiuneaV - 2;
    Terminare_P_Reale = Semnul_P_Imaginara - 1;
 
    if ((numarul1[Semnul_P_Reale] == '0') && (numarul2[Semnul_P_Reale] == '0')) // Adunarea numerelor reale cu semn pozitiv
    {
        rezultatul[Semnul_P_Reale] = '0';
        CalculCuAcelasiSemn(rezultatul, numarul1, numarul2, Terminare_P_Reale, 1);
    }
    else if ((numarul1[Semnul_P_Reale] == '1') && (numarul2[Semnul_P_Reale] == '1'))// Adunarea numerelor reale cu semn negativ
    {
        rezultatul[Semnul_P_Reale] = '1';
        CalculCuAcelasiSemn(rezultatul, numarul1, numarul2, Terminare_P_Reale, 1);
    }
    else if ((numarul1[Semnul_P_Reale] == '0') && (numarul2[Semnul_P_Reale] == '1')) // Scaderea numerelor reale daca al doilea numar este negativ
    {
        Copiere(copiereNr1, numarul1, 1, Terminare_P_Reale);
        Copiere(copiereNr2, numarul2, 1, Terminare_P_Reale);
        if (strcmp(copiereNr1, copiereNr2) >= 0)
        {
            rezultatul[Semnul_P_Reale] = '0';
            CalculCuSemnDiferit(rezultatul, numarul1, numarul2, Terminare_P_Reale, 1, 0);
        }
        else
        {
            rezultatul[Semnul_P_Reale] = '1';
            CalculCuSemnDiferit(rezultatul, numarul2, numarul1, Terminare_P_Reale, 1, 0);
        }
    }
    else // Scaderea numerelor reale daca primul numar este negativ
    {
        Copiere(copiereNr1, numarul1, 1, Terminare_P_Reale);
        Copiere(copiereNr2, numarul2, 1, Terminare_P_Reale);
        if (strcmp(copiereNr1, copiereNr2) > 0)
        {
            rezultatul[Semnul_P_Reale] = '1';
            CalculCuSemnDiferit(rezultatul, numarul1, numarul2, Terminare_P_Reale, 1, 0);
        }
        else
        {
            rezultatul[Semnul_P_Reale] = '0';
            CalculCuSemnDiferit(rezultatul, numarul2, numarul1, Terminare_P_Reale, 1, 0);
        }
    }
    // Calcularea numerelor imagianre=========================================================================
    if ((numarul1[Semnul_P_Imaginara] == '0') && (numarul2[Semnul_P_Imaginara] == '0')) // Adunarea numerelor imaginare cu semn pozitiv
    {
        rezultatul[Semnul_P_Imaginara] = '0';
        CalculCuAcelasiSemn(rezultatul, numarul1, numarul2, Terminare_P_Imaginare, Semnul_P_Imaginara + 1);
    }
    else if ((numarul1[Semnul_P_Imaginara] == '1') && (numarul2[Semnul_P_Imaginara] == '1')) // Adunarea numerelor imaginare cu semn negativ
    {
        rezultatul[Semnul_P_Imaginara] = '1';
        CalculCuAcelasiSemn(rezultatul, numarul1, numarul2, Terminare_P_Imaginare, Semnul_P_Imaginara + 1);
    }
    else if ((numarul1[Semnul_P_Imaginara] == '0') && (numarul2[Semnul_P_Imaginara] == '1')) // Scaderea numerelor imaginare daca al doilea numar  este negativ
    {
        Copiere(copiereNr1, numarul1, Semnul_P_Imaginara + 1, Terminare_P_Imaginare);
        Copiere(copiereNr2, numarul2, Semnul_P_Imaginara + 1, Terminare_P_Imaginare);
        if (strcmp(copiereNr1, copiereNr2) > 0)
        {
            rezultatul[Semnul_P_Imaginara] = '0';
            CalculCuSemnDiferit(rezultatul, numarul1, numarul2, Terminare_P_Imaginare, Semnul_P_Imaginara + 1, Semnul_P_Imaginara);
        }
        else if (strcmp(copiereNr1, copiereNr2) == 0)
        {
            rezultatul[Semnul_P_Imaginara] = '0';
            CalculCuSemnDiferit(rezultatul, numarul1, numarul2, Terminare_P_Imaginare, Semnul_P_Imaginara + 1, Semnul_P_Imaginara);
        }
        else
        {
            rezultatul[Semnul_P_Imaginara] = '1';
            CalculCuSemnDiferit(rezultatul, numarul2, numarul1, Terminare_P_Imaginare, Semnul_P_Imaginara + 1, Semnul_P_Imaginara);
        }
    }
    else // Scaderea numerelor imaginare daca primul numar este negativ
    {
        Copiere(copiereNr1, numarul1, Semnul_P_Imaginara + 1, Terminare_P_Imaginare);
        Copiere(copiereNr2, numarul2, Semnul_P_Imaginara + 1, Terminare_P_Imaginare);
        if (strcmp(copiereNr1, copiereNr2) > 0)
        {
            rezultatul[Semnul_P_Imaginara] = '1';
            CalculCuSemnDiferit(rezultatul, numarul1, numarul2, Terminare_P_Imaginare, Semnul_P_Imaginara + 1, Semnul_P_Imaginara);
        }
        else if (strcmp(copiereNr1, copiereNr2) == 0)
        {
            rezultatul[Semnul_P_Imaginara] = '0';
            CalculCuSemnDiferit(rezultatul, numarul1, numarul2, Terminare_P_Imaginare, Semnul_P_Imaginara + 1, Semnul_P_Imaginara);
        }
        else 
        {
            rezultatul[Semnul_P_Imaginara] = '0';
            CalculCuSemnDiferit(rezultatul, numarul2, numarul1, Terminare_P_Imaginare, Semnul_P_Imaginara + 1, Semnul_P_Imaginara);
        }
    }

    strcpy(numarul1, rezultatul); // Copierea rezultatului in numarul 1
}

void Scaderea(char *numarul1, char *numarul2, int DimensiuneaV)
{
    int Semnul_P_Imaginara, Semnul_P_Reale = 0;  //Calcularea pozitiior a numarului imaginar si real
    int Terminare_P_Reale, Terminare_P_Imaginare;
    char rezultatul[1001], copiereNr1[501], copiereNr2[501];

    Semnul_P_Imaginara = (DimensiuneaV - 1) / 2;
    Terminare_P_Imaginare = DimensiuneaV - 2;
    Terminare_P_Reale = Semnul_P_Imaginara - 1;

    if ((numarul1[Semnul_P_Reale] == '1') && (numarul2[Semnul_P_Reale] == '0')) // Adunarea numerelor reale cu semn negativ
    {
        rezultatul[Semnul_P_Reale] = '1';
        CalculCuAcelasiSemn(rezultatul, numarul1, numarul2, Terminare_P_Reale, 1);
    }
    else if ((numarul1[Semnul_P_Reale] == '0') && (numarul2[Semnul_P_Reale] == '1'))// Adunarea numerelor reale cu semn pozitiv
    {
        rezultatul[Semnul_P_Reale] = '0';
        CalculCuAcelasiSemn(rezultatul, numarul1, numarul2, Terminare_P_Reale, 1);
    }
    else if ((numarul1[Semnul_P_Reale] == '0') && (numarul2[Semnul_P_Reale] == '0')) // Scaderea numerelor reale daca al doilea numar devine negativ
    {
        Copiere(copiereNr1, numarul1, 1, Terminare_P_Reale);
        Copiere(copiereNr2, numarul2, 1, Terminare_P_Reale);
        if (strcmp(copiereNr1, copiereNr2) >= 0)
        {
            rezultatul[Semnul_P_Reale] = '0';
            CalculCuSemnDiferit(rezultatul, numarul1, numarul2, Terminare_P_Reale, 1, 0);
        }
        else
        {
            rezultatul[Semnul_P_Reale] = '1';
            CalculCuSemnDiferit(rezultatul, numarul2, numarul1, Terminare_P_Reale, 1, 0);
        }
    }
    else  // Scaderea numerelor reale daca al doilea numar devine pozitiv
    {
        Copiere(copiereNr1, numarul1, 1, Terminare_P_Reale);
        Copiere(copiereNr2, numarul2, 1, Terminare_P_Reale);
        if (strcmp(copiereNr1, copiereNr2) > 0)
        {
            rezultatul[Semnul_P_Reale] = '1';
            CalculCuSemnDiferit(rezultatul, numarul1, numarul2, Terminare_P_Reale, 1, 0);
        }
        else
        {
            rezultatul[Semnul_P_Reale] = '0';
            CalculCuSemnDiferit(rezultatul, numarul2, numarul1, Terminare_P_Reale, 1, 0);
        }
    }
    // Calcularea numerelor Imaginare===============================================================
    if ((numarul1[Semnul_P_Imaginara] == '1') && (numarul2[Semnul_P_Imaginara] == '0')) // Adunarea numerelor imaginare daca primul este negativ si al doilea devine negativ
    {
        rezultatul[Semnul_P_Imaginara] = '1';
        CalculCuAcelasiSemn(rezultatul, numarul1, numarul2, Terminare_P_Imaginare, Semnul_P_Imaginara + 1);
    }
    else if ((numarul1[Semnul_P_Imaginara] == '0') && (numarul2[Semnul_P_Imaginara] == '1'))// Adunarea numerelor imaginare daca primul este pozitiv si al doilea devine pozitiv
    {
        rezultatul[Semnul_P_Imaginara] = '0';
        CalculCuAcelasiSemn(rezultatul, numarul1, numarul2, Terminare_P_Imaginare, Semnul_P_Imaginara + 1);
    }
    else if ((numarul1[Semnul_P_Imaginara] == '0') && (numarul2[Semnul_P_Imaginara] == '0'))// Scaderea numerelor imaginare daca al doilea numar devine negativ
    {
        Copiere(copiereNr1, numarul1, Semnul_P_Imaginara + 1, Terminare_P_Imaginare);
        Copiere(copiereNr2, numarul2, Semnul_P_Imaginara + 1, Terminare_P_Imaginare);
        if (strcmp(copiereNr1, copiereNr2) >= 0)
        {
            rezultatul[Semnul_P_Imaginara] = '0';
            CalculCuSemnDiferit(rezultatul, numarul1, numarul2, Terminare_P_Imaginare, Semnul_P_Imaginara + 1, Semnul_P_Imaginara);
        }
        else
        {
            rezultatul[Semnul_P_Imaginara] = '1';
            CalculCuSemnDiferit(rezultatul, numarul2, numarul1, Terminare_P_Imaginare, Semnul_P_Imaginara + 1, Semnul_P_Imaginara);
        }
    }
    else// Scaderea numerelor imaginare daca al doilea numar devine pozitiv
    {
        Copiere(copiereNr1, numarul1, Semnul_P_Imaginara + 1, Terminare_P_Imaginare);
        Copiere(copiereNr2, numarul2, Semnul_P_Imaginara + 1, Terminare_P_Imaginare);
        if (strcmp(copiereNr1, copiereNr2) > 0)
        {
            rezultatul[Semnul_P_Imaginara] = '1';
            CalculCuSemnDiferit(rezultatul, numarul1, numarul2, Terminare_P_Imaginare, Semnul_P_Imaginara + 1, Semnul_P_Imaginara);
        }
        else if (strcmp(copiereNr1, copiereNr2) == 0)
        {
            rezultatul[Semnul_P_Imaginara] = '0';
            CalculCuSemnDiferit(rezultatul, numarul1, numarul2, Terminare_P_Imaginare, Semnul_P_Imaginara + 1, Semnul_P_Imaginara);
        }
        else
        {
            rezultatul[Semnul_P_Imaginara] = '0';
            CalculCuSemnDiferit(rezultatul, numarul2, numarul1, Terminare_P_Imaginare, Semnul_P_Imaginara + 1, Semnul_P_Imaginara);
        }
    }
    strcpy(numarul1, rezultatul); // Copiere rezultatului in 1;
}

int main(){
    char Sirul_de_numere1[1001], Sirul_de_numere2[1001], Semn;
    int Dimensiune_Sirului = 0;

    scanf("%d", &Dimensiune_Sirului);
    scanf("%s", Sirul_de_numere1);
    scanf("\n%c", &Semn);

    while (Semn != '0') //Rularea la infinit pana se tasteaza '0'
    {
        scanf("%s", Sirul_de_numere2);
        
        if (Semn == '+')
        {
            Adunare(Sirul_de_numere1, Sirul_de_numere2, Dimensiune_Sirului);
            Afisare(Sirul_de_numere1, Dimensiune_Sirului);
        }
        else
        {
            Scaderea(Sirul_de_numere1, Sirul_de_numere2, Dimensiune_Sirului);
            Afisare(Sirul_de_numere1, Dimensiune_Sirului);
        }
        scanf("\n%c", &Semn);
    }
}