#include <stdio.h>  
#include <math.h>
#include <string.h>
#include <stdlib.h>

// O functie pentru aflarea lungimii unui sir
int str_length(char str[]) {
    int count; 
    for (count = 0; str[count] != '\0'; ++count);
    return count; 
}

char *CodificareA(char *text, char *cheia){
    char mat[50][100];
    int line = 1, lungimea_cheii = 0, lungimea_text = 0;
    int i, j, k;

    while (cheia[lungimea_cheii] != '\0')   // Introducem cheia in matrice pe primul rand
    {
        mat[0][lungimea_cheii] = cheia[lungimea_cheii];
        lungimea_cheii++;
    }

    while (text[lungimea_text] != '\0')   // Introducem textul in restul matricei depinzand de lungimea cheii
    {
        for (i = 0; i < lungimea_cheii; i++)
        {
            if (text[lungimea_text] != '\0') // Verificam daca nu am ajuns la finalul sirului
            {
                mat[line][i] = text[lungimea_text];
                lungimea_text++;
            } 
            else // Daca am ajuns la finalul punem spatii in continuare
            {
                mat[line][i] = ' ';
            }
        }
        line++; // Calculam numarul liniilor
    }

    for(i = 0; i < lungimea_cheii - 1; i++)  // Facem sequential sort in array pe baza cheii 
    {
        for(j = i + 1; j < lungimea_cheii; j++)
        {
            if (mat[0][j] < mat[0][i])
            {
                for(k = 0; k < line; k++)
                {
                    char swap = mat[k][i];
                    mat[k][i] = mat[k][j];
                    mat[k][j] = swap;
                }
            }
        }
    }

    for(i = 0, lungimea_text = 0; i < lungimea_cheii; i++)   // Dupa ce am sortat array-ul rescriem textul codificat
    {
        for(j = 1; j < line; j++)
        {
            if (lungimea_text < (line - 1) * lungimea_cheii)
            {
                text[lungimea_text++] = mat[j][i]; // Introducem caracterele de pe coloane
            }
        }
    }
    text[lungimea_text] = '\0';
    return text; // Returnam textul codificat
}

char *DecodificareA(char *text, char *cheia){
    char mat[50][100];
    int len = 0, mat_indx[50], lungimea_cheii = str_length(cheia), lungimea_text = str_length(text);
    int line = ceil((double)lungimea_text / lungimea_cheii);
    int i = 0, j = 0, k = 0, q = 0;

    for (i = 0; i < lungimea_cheii; i++)  // Introducem cheia in matrice pe primul rand 
    {
        mat[0][i] = cheia[i];
        mat_indx[i] = i;
    }

    for (j = 0; j < lungimea_cheii; j++)   // Introducem textul in restul matricei, dar inversand coloanele fata de codificare
    {
        for (i = 1; i <= line; i++)
        {
            if (text[k] != '\0') // Verificam daca nu am ajuns la finalul sirului
            {
                mat[i][j] = text[k++];
            } 
            else // Daca am ajuns la finalul punem spatii in continuare
            {
                mat[i][j] = ' ';
            }
        }
    }

    for(i = 0; i < lungimea_cheii - 1; i++)  // Facem sequential sort pentru cheie si index paralel
    {
        for(j = i + 1; j < lungimea_cheii; j++)
        {
            if (mat[0][j] < mat[0][i])
            {
                char swap = mat[0][i];
                int swap1 = mat_indx[i];
                mat[0][i] = mat[0][j];
                mat[0][j] = swap;
                mat_indx[i] = mat_indx[j];
                mat_indx[j] = swap1;
            }
        }
    }

    for(i = 1; i <= line; i++)  // Cautam caracterele in functie de index 
    {
        for(j = 0; j < lungimea_cheii; j++)
        {
            for(q = 0; q < lungimea_cheii; q++)
            {
                if (mat_indx[q] == j)
                {
                    text[len++] = mat[i][q]; // Introducem caracterele in text
                    break;
                }
            }
        }
    }
    text[len] = '\0';
    return text; // Returnam textul decodificat
}

char *CodificareB(char *text, char *cheia){
    int i = 0, j = 0;
    int nr_cheie = atoi(cheia);
    char ultimul_char;
    
    for(i = 0; i < nr_cheie; i++)
    {
        ultimul_char = text[str_length(text) - 1]; // Selectam ultimul caracter
        if (ultimul_char != ' ') // Verificam ca caracterul sa nu fie space
        {
            for (j = 0; j < nr_cheie; j++) // Adaugam caracterului numarului de permutari la codul ASCII
            {
                if (ultimul_char == 'Z') // Verificam daca este la ultima litera majuscula 
                {
                    ultimul_char += 6; // Sarim peste caracterele care nu sunt litere latine
                }
                if (ultimul_char == 'z') // Verificam daca este la ultima litera minuscula
                {
                    ultimul_char -= 58; // Ne intoarcem la primul caracter care este o litera latina
                }
                ultimul_char++; 
            } 
        }
        for(j = str_length(text) - 1; j > 0; j--)  // Permutam caracterele la dreapta
        {
            text[j] = text[j - 1];
        }
        text[0] = ultimul_char;   // Ultimul caracter il plasam la inceputul vectorului
    }
    return text; // Returnam textul codificat
}

char *DecodificareB(char *text, char *cheia){
    int i = 0, j = 0;
    int nr_cheie = atoi(cheia);
    char primul_char;

    for(i = 0; i < nr_cheie; i++)
    {
        primul_char = text[0]; // Selectam primul caracter
        if (primul_char != ' ') // Verificam ca caracterul sa nu fie space
        {
            for (j = 0; j < nr_cheie; j++) // Se inverseaza modelul de lucru de la CodificareaB
            {
                if (primul_char == 'a')
                {
                    primul_char -= 6; 
                }
                if (primul_char == 'A') 
                {
                    primul_char += 58; 
                }
                primul_char--;
            } 
        }
        for(j = 1; j < str_length(text); j++)  // Permutam caracterele la dreapta
        {
            text[j - 1] = text[j];
        }
        text[str_length(text) - 1] = primul_char; // Primul caracter il plasam la finalul vectorului
    }
    return text; // Returnam textul decodificat
}

int main(){
    char text[500], cheia[50], tip[50];

    scanf("%[^\n]", text); // Citirea textului cu tot cu spatii
    while (strcmp(tip, "STOP") != 0) // Citim pana ajugem ca tipul codificarii sa fie STOP
    {
        scanf("%s", tip); // Citim tipul Codificarii/Decodificarii
        if(strcmp(tip, "STOP") != 0) // Verificam sa nu fie STOP
        {
            scanf("\n");
            scanf("%[^\n]", cheia); // Citim cheia Codificarii/Decodificarii
            if (strcmp(tip, "CodificareA") == 0) // Verificam tipul codificarii/Decodifiicari si o executam
            {
                CodificareA(text, cheia);
            } 
            else if (strcmp(tip, "CodificareB") == 0)
            {
                CodificareB(text, cheia);
            } 
            else if (strcmp(tip, "DecodificareA") == 0)
            {
                DecodificareA(text, cheia);
            } 
            else if (strcmp(tip, "DecodificareB") == 0)
            {
                DecodificareB(text, cheia);
            }
            printf("%s\n", text); // Afisam textul dupa Codificare/Decodificare
        }
    }
}