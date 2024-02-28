# Problema1 - Cutiile si Prizonierii =====================================================================================
-Informatii generale:
O inchisoare este pe cale sa se inchida ,directorul le ofera prizonierilor o sansa sa fie eliberati ,numai daca fiecare
prizonier isi gaseste numarul dintr-o cutie, fiindca numarul din cutie este aliatoriu si au un numar finit de incercari
un prizonier a venit cu o idee. Ideea consta in faptul ca fiecare prizonier isi deschide cutia repartizata si numarul din 
cutie va reprezenta numarul cutiei.
  
-Implementarea aleasa:
Primul pas se va verifica daca toti prizonierii isi gasesc numarul,pentru a afla daca vor fi eliberati sau nu ,al doilea
pas se vor afla toata ciclurile posibele prin care pot trece prizonierii.

-Pasii de executare:
1.Se introduce numarul de priznoieri.
2.Pe baza la numarul de prizonieri se va pune in cutie un numar egal sau mai mic decat cel a prizonierilor
 
# Problema2 - Numere Complexe Lungi ======================================================================================
-Informatii generale:
In acest program se va calcula adunare si scaderea ,pana la intalnirea caracterului '0', dintre numerele complexe extrem 
de lungi,pana la 1000 caracatere.

-Implementarea aleasa:
Se va extrage din fiecare sir partea reala si cea imaginara si se vor face calculele cerute pe baza semnul ales,si semnul 
numarului.

-Pasii de executare:
1.Se va introduce numarul de carcatere.
2.Se va introduce primul sir de numere.
3.Se va introduce semnul de adunare sau scaderea.
4.Se va introduce al doilea sir de numere.
5.Se va afisa rezultatul si se revine la pasul 3 pana la introducerea caracterului '0'.

# Problema3 - Transmisie Bruiata =========================================================================================
-Informatii generale:
In acet program se va putea codifica un sir de caractere prin doua metode si in acelas timp sa le poti decodifica. Prima
codificare are la baza algoritmul "Columnar Transposition Chipher" iar al doilea are la baza permutari in sir si in codul
ASCII.
 
-Implementarea aleasa:
CodificareaA a fost creata pe baza unei matrice unde prinind cheia se va face sortarea si se va afisa sirul primit,iar 
CodificareaB se va muta cu numarul de caractere cerut la dreapta,fiecare caracter mutat se va schimba in tabelul ASCII
pe baza numarului cerut.

-Pasii de executare:
1.Se va citi textul care trebuie codificat.
2.Se va citi ce fel de Codificare/Decodifcare(Daca e CodificareA: se va citi si cuvantul cheie,
daca e CodificareB se va citi numarul).

# Problema4 - Car Dealer =================================================================================================
-Informatii generale:
In acest progrma se vor introduce un numar de masini avand la ele anumite tipuri de informatii ,unde pe baza unei cerinte
se va afisa anumite informatii despre masinile date.

-Implementarea aleasa: 
Fiecare data a masinei va fi stocata intr-o structura aparte,unde la nevoie va fi apelata pentru a fi folosite 
informatiile din structura data,structurele si sirurile de caractere au fost alocate dinamic pentru a nu irosi memoria.

-Pasii de executare:
1.Se tasteza numarul de masini.
2.Se introduce fiecare data despre masina.
(ele sunt:<brandul>,<numarul de Inmatriculare>,<tipul motorului>,<consumul mediu><numarul de KM parcusi de masina>)
3.Se introduce cerinta aleasa:
   'a' - Calculeaza totalulul de moatoare de fiecare tip si il afiseaza.
   'b' - Se calculeaza consumul total de combustibil si suma totală cheltuita pentru fiecare brand de masina.
   'c' - Se verifica daca masinele introduse au Nr.de inmatriculare corect format;
   (Un număr de inmatriculare corect este format din 1 sau 2 litere, urmate de 2 sau 3 cifre, urmate de exact 3 litere).
