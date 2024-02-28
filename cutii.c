#define MaximP 501
#define MinimP 2
#include <stdio.h>

int Eliberare(int nr_de_incercari, int nr_de_cutii[], int nr_necesar) 
{
    int indexul_cutii, nr_curent = 0;
    indexul_cutii = nr_necesar;

    while (nr_curent != nr_de_incercari) // Atat timp cat mai are incercari isi cauta numarul
    {
        if (nr_necesar != nr_de_cutii[indexul_cutii])
        {
            indexul_cutii = nr_de_cutii[indexul_cutii];
            nr_curent++;
        }
        else
        {
            return 1;
        } 
    // Daca isi gaseste numarul returneaza 1 daca nu returneaza 0
    }
    return 0;
}

int main()
{
    int Nr_de_prizonieri, Nr_de_incercari, Counter = 1;  //Declararea variabelor 
    int Nr_de_cutii[MaximP], Persoane_eliberate[MaximP], Cicluri[MaximP];
    int i, j;

    scanf("%d", &Nr_de_prizonieri);
    Nr_de_incercari = Nr_de_prizonieri / MinimP; // Aflarea numarului de incercari 
    if ((Nr_de_prizonieri <= MaximP) && (Nr_de_prizonieri >= MinimP))
    {
        for (i = 1; i <= Nr_de_prizonieri; i++)
        {
            scanf("%d", &Nr_de_cutii[i]); //Punerea cifrelor in cutie
        }
        for (i = 1; i <= Nr_de_prizonieri; i++)
        {
            Persoane_eliberate[i] = Eliberare(Nr_de_incercari, Nr_de_cutii, i); //Fiecare prizonier incepe sa isi caute numarul
        }
        for (i = 1; i <= Nr_de_prizonieri; i++)
        {
            if (Persoane_eliberate[i] == 0)
            {
                printf("Nu\n"); //Daca cel putin un prizonier nu o fost eliberat se returneaza nu
                break;
            }
        }
        if (i - 1 == Nr_de_prizonieri)
        {
            printf("Da\n");//Daca toti prizonierii au fost eliberati se returneaza da
        }
        int Locatia1 = 0, Locatia2 = 0;
        for (i = 1; i <= Nr_de_prizonieri; i++) // Incepem afisarea ciclurilor
        {
            Cicluri[i] = Counter;
            for (j = 1; j < i; j++) // Verificam daca am ajuns la un final de ciclu
            {
                if (Cicluri[j] == Counter)
                {
                    Locatia2++;
                    break; // Daca am gasit un final de ciclu iesim din loop
                }
            }
            if(Locatia2 == 0 && Locatia1 != 0) //Daca e scrisa prima cifra si nu e la final se pune space
            {
                printf(" ");
            } 
            else if (Locatia2 != 0)
            {
                Locatia2 = 0;
            }
            if (j == i) // Daca nu am ajuns la finalul ciclului afisam  nr.cutiei
            {
                printf("%d", Cicluri[i]);
                Locatia1++;
                int Counter2 = Counter;
                Counter = Nr_de_cutii[Counter];
                Nr_de_cutii[Counter2] = 0; // Inlocuiesti cutia deschisa cu 0
            }
            else // Daca am ajuns la finalul ciclului pregatim datele pentru urmatoarele cicluri existente
            {
                for (j = 1; j <= Nr_de_prizonieri; j++) // Cautam o cutie nedeschisa
                {
                    if (Nr_de_cutii[j] != 0)
                    {
                        Locatia1 = 0;
                        Counter = j;
                        i = j - 1;
                        printf("\n");
                        break; // Daca gaseste reincepem un alt ciclu
                    }
                }
            }
        }
        printf("\n");
    }
    else
    {
        printf("Numarul de prizonieri este prea mare sau prea mic!"); //Input gresit 
    }
    return 0;
}