#include <stdio.h>
#include <stdlib.h>
#include <string.h>


///////////// TYPY BAZOWE ///////////////

/**
* @brief - Struktura przechowywujaca znaki ktore wprowadzimy
*
* @param - char data - wprowadzony znak
* @param - int ilosc - ilosc wystapien znakow w calym tekscie
* @param - double prawdopodobienstwo - prawdopodobienstwo wystapienia znaku w calym tekscie
* @param - fifo_node *nastepny - wskaznik na kolejny element
*/
struct fifo_node {
    char data;
    int ilosc;
    double prawdopodobienstwo;
    struct fifo_node *nastepny;
};
/**
* @brief - Struktura przechowywuje wskazniki kolejki
*
* @param - *poczatek - wskaznik na pierwszy element
* @param - *koniec - wskaznik na ostatni element
*/
struct fifo_pointers {
    struct fifo_node *poczatek, *koniec;
} fifo;

/**
* @brief - Struktura opisuje element na liscie, gdzie nastepnie tworzone jest drzewo
*
* @param - char data - wprowadzony znak
* @param - double prawdopodobienstwo - prawdopodobienstwo wystapienia znaku w calym tekscie
* @param - int strona - sprawdza czy element jest w prawym czy lewym poddrzewie
* @param - list_node *nastepny - wskaznik na nastepny element
* @param - list_node *lewa_galaz, *prawa_galaz - wskaznik na prawe lub lewe poddrzewo
* @param - list_node *pien - wskaznik na pien
*/
struct list_node {
    char data;
    double prawdopodobienstwo;
    short int strona;
    struct list_node *nastepny;
    struct list_node *lewa_galaz, *prawa_galaz;
    struct list_node *pien;
} *list_pointer;

/**
* @brief - Struktura przechowywujaca elementy na stosie, służąca również do tworzenia znaków kodowania
*
* @param - int data - liczba odpowiada za poddrzewo lewe lub prawe
* @param - stack_node *next - wskaznik na nastepny element stosu
*/
struct stack_node {
    int data;
    struct stack_node *nastepny;
};
/**
* @brief - Struktura opisuje zakodowany element listy
*
* @param - char data - wprowadzony znak
* @param - short int code[8] - tablica przechowywujaca kod
* @param - short int code_size - okresla dlugosc kodu wyswietlanego
* @param - struct code_node *nastepny - wskaznik na nastepny element listy
*/
struct code_node {
    char data;
    short int code[8];
    short int code_size;
    struct code_node *nastepny;
} *coded_list_pointer;
/**
* @brief - Struktura opisuje element kolejki gdzie znajduje sie zdanie
*
* @param - char data - wprowadzony znak
* @param - sentence_node *nastepny - wskaznik na nastepny element kolejki
*/
struct sentence_node {
    char data;
    struct sentence_node *nastepny;
};
/**
* @brief - Struktura przechowuje wskazniki kolejki ze zdaniem
*
* @param - struct sentence_node *poczatek, *koniec - wskaznik na pierwszy i ostatni element kolejki przechowujacej zdanie
*/
struct sentence_pointers {
    struct sentence_node *poczatek, *koniec;
} zdanie;


////////// KOLEJKA //////////

/**
* @brief - Usuwa element w kolejce
*
* @param - fifo_pointers *fifo - wskaznik na strukture wskaznikowa kolejki
* @return - Wskaznik na strukture zwracajaca element
*/
struct fifo_pointers *w_kolejce_1(struct fifo_pointers *fifo);

/**
* @brief - Dodanie elementu w kolejke
*
* @param - fifo_pointers *fifo - wskaznik na strukture wskaznikowa kolejki
* @param - char data - wprowadzony znak
*/
void zakolejkowane_1(struct fifo_pointers *fifo, char data);

/**
* @brief - Wypisanie kolejki
*
* @param - fifo_pointers fifo - wskazniki kolejki
*/
void wypis_kolejka(struct fifo_pointers fifo);

/**
* @brief - Funkcja znajduje element kolejki i zlicza wystapienia
*
* @param - fifo_pointers fifo - wskazniki kolejki
* @param - char data - znak
* @return jesli liczba jest poprawna zwraca 0 jesli nie -1
*/
int znajdz_w_kolejce(struct fifo_pointers fifo, char data);

/**
* @brief - Funkcja wylicza wszystkie znaki
*
* @param - fifo_pointers fifo - wskazniki kolejki
* @return - funkcja zwroci ilosc znakow
*/
int liczba_znakow(struct fifo_pointers fifo);

/**
* @brief - Funkcja wylicza sume wszystkich elementow
*
* @param - fifo_pointers fifo - wskazniki kolejki
* @return - Funkcja zwroci sume elementow
*/
int suma_elementow(struct fifo_pointers fifo);

/**
* @brief - Funkcja oblicza prawdopodobienstwo wystapienia kazdego znaku w ciagu wyrazowym
*
* @param - fifo_pointers fifo - wskazniki kolejki
* @param - int sum - laczna ilosc znakow
*/
void prawdopodobienstwo_wystapienia(struct fifo_pointers fifo, int sum);

////////// LISTA //////////

/**
* @brief - Funkcja tworzy pierwszy element na liscie
*
* @param - fifo_pointers *fifo - wskazniki kolejki
* @return - wskaznik na liste
*/
struct list_node *stworz_liste(struct fifo_pointers *fifo);

/**
* @brief - Funkcja znajduje miejsce na liscie i wprowadza tam nowy element
*
* @param - list_node *list_pointer - wskaznik na liste
* @return - wskaznik na element przed wstawiany element
*/
struct list_node *znajdz_miejsce(struct list_node *list_pointer, double data);

/**
* @brief - Funkcja dodaje element do listy
*
* @param - list_node *list_pointer - wskaznik na liste
* @param - fifo_pointers *fifo - wskaznik na kolejke
* @return - wskaznik na liste
*/
struct list_node *dodaj_element_1(struct list_node *list_pointer, struct fifo_pointers *fifo);

/**
* @brief - Funkcja dodaje element na sam poczatek listy
*
* @param - list_node *list_pointer - wskaznik na liste
* @param - liste_node *nowy_wezel - wskaznik na nowy element listy
* @return - wskaznik na liste
*/
struct list_node *dodaj_na_poczatek(struct list_node *list_pointer, struct list_node *nowy_wezel);

/**
* @brief - Funkcja dodaje element na srodek listy
*
* @param - list_node *element - wskaznik na liste
* @param - list_node *nowy_wezel - wskaznik na nowy element
*/
void dodaj_na_srodek(struct list_node *element, struct list_node *nowy_wezel);

/**
* @brief - Funkcja dodaje element na koniec listy
*
* @param - list_node *element - wskaznik na liste
* @param - listy_node *nowy_wezel - wskaznik na nowy element
*/
void dodaj_na_koniec(struct list_node *element, struct list_node *nowy_wezel);

/**
* @brief - Funkcja znajduje element poprzedzajacy do usuwanego elementu
*
* @param - list_node *list_pointer - wskaznik na liste
* @param - int data - element ktory usuwamy
* @return - wskaznik na liste
*/
struct list_node *znajdz_poprzedni_do_usun(struct list_node *list_pointer, int data);

/**
* @brief - Funkcja usuwa element z poczatku listy
*
* @param - list_node *list_pointer - wskaznik na liste
* @return - wskaznik na liste
*/
struct list_node *usun_z_przodu(struct list_node *list_pointer);

/**
* @brief - Funkcja usuwa element ze srodka listy lub z jej konca
*
* @param - list_node *poprzedni - wskaznik na element wczesniejszy
*/
void usun_srodek_lub_koniec(struct list_node *poprzedni);

/**
* @brief - Funkcja usuwa element z listy
*
* @param - list_node *list_pointer - wskaznik na liste
* @param - int data - element ktory usuniemy
* @return - wskaznik na listre
*/
struct list_node *usun_element(struct list_node *list_pointer, int data);

/**
* @brief - Funkcja usuwa liste
*
* @param - list_node **list_pointer - wskaznik nadany podwojnie na liste
*/
void usun_liste(struct list_node **list_pointer);

/**
* @brief - Funkcja wyswietla liste
*
* @param - list_node *list_pointer - wskaznik na liste
*/
void pokaz_liste(struct list_node *list_pointer);


////////// DRZEWO //////////

/**
* @brief - Funkcja zerujaca wskazniki na lisciach
*
* @param - list_node *nowy_wezel - wskaznik na strukture
*/
void wyczysc_trzy(struct list_node *nowy_wezel);

/**
* @brief - Funkcja zerujaca wskazniki nastepny
*
* @param - list_node *nowy_wezel - wskaznik na strukture
*/
void wyczysc_jeden(struct list_node *nowy_wezel);

/**
* @brief - Funkcja tworzy drzewo usuwajac poczatkowe dwa elementy listy zarazem tworzac jeden z listy
*
* @param - list_node *list_pointer - wskaznik na liste
* @return - wskaznik na liste
*/
struct list_node *stworz_drzewo(struct list_node *list_pointer);

/**
* @brief - Funkcja wyswietla drzewo
*
* @param - list_node *korzen - wskaznik na poczatek drzewa
* @param - int level - poziom drzewa do wyswietlania
*/
void pokaz_drzewo(struct list_node *korzen, int level);

/**
* @brief - Funkcja wyswietla drzewo wedle poziomu
*
* @param - list_node *korzen - wskaznik na pien drzewa
*/
void pokaz_drzewo_2(struct list_node *korzen);

/**
* @brief - Funkcja znajduje wysokosc drzewa
*
* @param - list_node *korzen - wskaznik na pien drzewa
* @return - funkcja zwraca wysokosc drzewa
*/
int znajdz_gore(struct list_node *korzen);



////////// WPROWADZANE ZDANIE //////////

/**
* @brief - Funkcja dodajaca znak ze zdania do kolejki
*
* @param - struct sentence_pointers *zdanie - wskaznik na wskazniki kolejki przechowujacej zdanie
* @param - char data -  wprowadzony znak
*/
void zakolejkowane_zdanie(struct sentence_pointers *zdanie, char data);

/**
* @brief - Funkcja zwraca znak ze zdania
*
* @param - struct sentence_pointers *zdanie - wskaznik na wskazniki kolejki przechowujacej zdanie
* @return - wprowadzany znak
*/
char zwroc_znak_ze_zdania(struct sentence_pointers *zdanie);

/**
* @brief - Funkcja wyswietla zdanie wprowadzone przez uzytkownika do zakodowania
*
* @param - struct sentence_pointers zdanie - wskaznik kolejki przechowujacej zdanie
*/
void wypisz_zdanie(struct sentence_pointers zdanie);

/**
* @brief - Funkcja wyswietla zakodowane zdanie
*
* @param - struct code_node *wskaznik_zakodowanej_listy - wskaznik na liste z kodami i znakami
* @param - struct sentence_pointers *zdanie - wskaznik na wskazniki kolejki ze zdaniem
* @return - ilosc bitow zdania zakodowanego
*/
int wypisz_zakodowane_zdanie(struct code_node *wskaznik_zakodowanej_listy, struct sentence_pointers *zdanie);

/**
* @brief - Funkcja usuwa kolejke ze zdaniem
*
* @param - struct sentence_pointers *zdanie - wskaznik na strukture przechowywujaca wskazniki kolejki
*/
void wyczysc_zdanie(struct sentence_pointers *zdanie);


////////// PLIK DO OBLUGIWANIA //////////

/**
* @brief - Funkcja wedlug dzialan uzytkownika wczytuje podany plik
*
* @param - char *nazwa_folderu - nazwa danego pliku
* @param - char *tab - tablica
* @return - kod
*/
int odczytywany_plik(char *nazwa_folderu, char *tab);

/**
* @brief - Funkcja zajmuje sie odkodowywaniem tekstu z wczytanego pliku
*
* @param - struct code_node *wskaznik_zakodowanej_listy - wskaznik na liste z kodami
* @param - char *nazwa_folderu - nazwa danego pliku
* @param - struct list_node *korzen - wskaznik na korzen
* @return - kod
*/
int
odczyt_zakodowanego_pliku(struct code_node *wskaznik_zakodowanej_listy, char *nazwa_folderu, struct list_node *korzen);

/**
* @brief - Funkcja zapisuje plik o podanej nazwie
*
* @param - struct code_node *wskaznik_zakodowanej_listy - wskaznik na liste z kodami i znakami
* @param - struct sentence_pointers *zdanie - wskaznik na wskazniki kolejki przechowywujacej zdanie
* @param - char *nazwa_folderu - nazwa danego pliku
* @return - kod
*/
int zapis_pliku(struct code_node *wskaznik_zakodowanej_listy, struct sentence_pointers *zdanie, char *nazwa_folderu);


////////// STOS /////////

/**
* @brief - Funkcja wyswietla stos
*
* @param - struct stack_node *gora - wskaznik okreslajacy gore stosu
*/
void pokaz_stos(struct stack_node *gora);

/**
* @brief - Funkcja usuwa stos
*
* @param - struct stack_node **gora - podwojny wskaznik okreslajacy gore stosu
*/
void usun_stos(struct stack_node **gora);

/**
* @brief - Funkcja dodaje element na stos
*
* @param - struct stack_node *gora - wskaznik okreslajacy góre stosu
* @param - int  data - wprowadzona liczba
* @return - wskaznik okreslajacy nową góre stosu
*/
struct stack_node *dodaj_na_stos(struct stack_node *gora, int data);

/**
* @brief - Funkcja zdejmuje element ze stosu
*
* @param - struct stack_node **gora - podwojny wskaznik na gore stosu
* @return - liczba
*/
int pop(struct stack_node **gora);

/**
* @brief - Funkcja zlicza laczna ilosc elementow znajdujaca sie na stosie
* @param - struct stack_node *gora - wskaznik okreslajacy gore stosu
* @return - laczna ilosc elementow znajdujacych sie na stosie
*/
int liczebnosc_stosu(struct stack_node *gora);


////////// LISTA Z KODAMI //////////

/**
* @brief - Funkcja wyswietla liste kodow
*
* @param - struct code_node *wskaznik_zakodowanej_listy - wskaznik na liste z kodami
*/
void pokaz_zakodowana_liste(struct code_node *wskaznik_zakodowanej_listy);

/**
* @brief - Funkcja tworzy pierwszy element na liscie z kodami
*
* @return - wskaznik na liste z kodami
*/
struct code_node *stworz_zakodowana_liste();

/**
* @brief - Funkcja dodaje element na poczatek listy zakodowanej
*
* @param - struct code_node *wskaznik_zakodowanej_listy - wskaznik na liste z kodami
* @param - struct code_node *nowy_wezel - wskaznik na nowy element listy
* @return - wskaznik na liste z kodami
*/
struct code_node *dodaj_zakodowanie_1(struct code_node *wskaznik_zakodowanej_listy, struct code_node *nowy_wezel);

/**
* @brief - Funkcja usuwa liste z kodami
*
* @param - struct code_node **wskaznik_zakodowanej_listy - podwojny wskaznik na liste z kodami
*/
void usun_zakodowana_liste(struct code_node **wskaznik_zakodowanej_listy);

/**
* @brief - Funkcja wypelnia liste kodami
*
* @param - struct list_node *korzen - wskaznik na korzen
* @param - struct stack_node *gora - wskaznik na gore stosu
* @param - struct code_node *wskaznik_zakodowanej_listy - wskaznik na liste z kodami
* @param - char data - wprowadzony znak
*/
void lista_z_zakodowanymi_kodami(struct list_node *korzen, struct stack_node *gora,
                                 struct code_node *wskaznik_zakodowanej_listy, char data);

/**
* @brief - Funkcja przypisujaca kod do znaku
*
* @param - struct stack_node *gora - wskazik na gore stosu
* @param - struct code_node *wskaznik_zakodowanej_listy - wskaznik na liste z kodami
* @param - int rozmiar - dlugosc wypisanego kodu
*/
void dodaj_kod(struct stack_node *gora, struct code_node *wskaznik_listy_zakodowanej, int rozmiar);

/**
* @brief - Funkcja wypelnia liste znakami
*
* @param - struct list_node *korzen - wskaznik na poczatek drzewa
* @param - struct code_node *wskaznik_zakodowanej_listy - wskaznik na liste z kodami
* @return - wskaznik na liste zakodowana
*/
struct code_node *
wypelnij_zakodowana_liste_znakami(struct list_node *korzen, struct code_node *wskaznik_zakodowanej_listy);

/**
* @brief - Funkcja dodaje wezel kodu do znaku
*
* @param - struct code_node *wskaznik_zakodowanej_listy - wskaznik na liste z kodami
* @param - char data - wprowadzony znak
* @return - wskaznik na liste zakodowana
*/
struct code_node *dodaj_jeden_wezel(struct code_node *wskaznik_zakodowanej_listy, char data);

/**
* @brief - Funkcja zliczajaca znaki listy zakodowanej
*
* @param - struct code_node *wskazik_zakodowanej_listy - wskaznik na liste z kodami
* @return - laczna suma znakow listy zakodowanej
*/
int liczebnosc_zakodowanej_listy(struct code_node *wskaznik_listy_zakodowanej);


////////// MAIN //////////

enum Mode {
    MANUAL, ARGVFILE, ARGVTEXT
};

int main(int argc, char *argv[]) {

    enum Mode mode;
    mode = MANUAL;
    if (argc > 1) {
        for (int i = 0; i < argc; i++) {
            if (strcmp("-h", argv[i]) == 0) {
                printf("POMOC: \n");
                printf("\nAby uruchomic program z komunikatem wczytanym pliku dodaj flage -f oraz nazwe pliku w formacie nazwa.txt\nnp. -f wiadomosc.txt\n\n");
                printf("Aby uruchomic program z komunikatem wczytanym z wiersza polecen dodaj flage -c oraz wiadomosc zakonczona znakiem \"&\"\n");
                printf("\nAby uruchomic pomoc dodaj flage -h\n ");
                printf("\nAby uruchomic program w trybie manualnym nie dodawaj flagi w parametrach wywolania\n");
                return 0;
            }
            if (strcmp("-f", argv[i]) == 0) {
                printf("Wczytano program z komunikatem z pliku %s", argv[i + 1]);
                mode = ARGVFILE;
                break;
            }
            if (strcmp("-c", argv[i]) == 0) {
                printf("Wczytano program z komunikatem z linii komend %s", argv[i + 1]);
                mode = ARGVTEXT;
                break;
            }
        }
    }
    int zmienna_1;
    int zmienna_2;
    char znak;
    int result;

    if (mode == MANUAL) {
        puts("Wybierz co chcesz zrobic:");
        printf("Wcisnij \"1\" aby samodzielnie wprowadzic tekst.\n"
               "Wcisnij \"2\" aby pobrac tekst z wybranego pliku.\n");
        puts("\nDecyzja:");
        scanf("%d", &zmienna_1);
    } else if (mode == ARGVFILE) {
        zmienna_1 = 2;
    } else if (mode == ARGVTEXT) {
        zmienna_1 = 1;
    }
    switch (zmienna_1) {
        case 1: {
            if (mode == ARGVTEXT) {
                fflush(stdin);
                char komunikat[400];
                strcpy(komunikat,"");
                for(int i=2;i<argc;i++)
                {
                    strcat(komunikat,argv[i]);
                    strcat(komunikat," ");
                }
                for(int i=0; i<strlen(komunikat) ; i++)
                {
                    znak = komunikat[i];
                    if (znak != '&') {
                        zakolejkowane_zdanie(&zdanie, znak);
                        zmienna_2 = znajdz_w_kolejce(fifo, znak);
                        if (zmienna_2 != 0)
                            zakolejkowane_1(&fifo, znak);
                    }
                }

            } else {
                fflush(stdin);
                puts("Wprowadz tekst i zakoncz go znakiem: \"&\"");
                while (znak != '&') {
                    znak = getc(stdin);
                    if (znak != '&') {
                        zakolejkowane_zdanie(&zdanie, znak);
                        zmienna_2 = znajdz_w_kolejce(fifo, znak);
                        if (zmienna_2 != 0)
                            zakolejkowane_1(&fifo, znak);
                    }
                }
            }
            break;
        }
        case 2: {
            char tab[500];
            char plik[60];
            if (mode == ARGVFILE) {
                strcpy(plik, argv[argc - 1]);
            } else {
                fflush(stdin);
                puts("Pobierz tekst z pliku.");
                printf("Podaj nazwe pliku z ktorego chcesz pobrac tekst."
                       " W tym celu wpisz: \"nazwa.txt\"\n");
                scanf(" %s", plik);
            }
            result = odczytywany_plik(plik, tab);

            printf("\n%s\n", tab);
            if (result < 0) {
                return -1;
            }
            char zmienna_3;
            int dlugosc;
            dlugosc = strlen(tab) - 1;
            for (int i = 0; i < dlugosc; i++) {
                zmienna_3 = tab[i];
                zakolejkowane_zdanie(&zdanie, zmienna_3);
                if (znajdz_w_kolejce(fifo, zmienna_3) == 0)
                    continue;
                else if (zmienna_3 != '\n')
                    zakolejkowane_1(&fifo, zmienna_3);

            }
        }
        default:
            break;

    }

    int ilosc_znakow = liczba_znakow(fifo);
    if (ilosc_znakow == 0) {
        printf("\nPodano zly parametr ! ! !\n");
        return -1;
    }

    printf("\n------------------------");
    printf("\nKOLEJKA:\n");
    printf("------------------------");

    int suma_wszystkich_elementow = suma_elementow(fifo);
    printf("\nSuma elementow wynosi: %d\n", suma_wszystkich_elementow);
    printf("Wszystkich znakow jest: %d\n\n\n", liczba_znakow(fifo));

    prawdopodobienstwo_wystapienia(fifo, suma_elementow(fifo));
    printf("Ilosc znakow i prawdopodobienstwo ich wystapienia wynosi: \n");
    wypis_kolejka(fifo);

    list_pointer = stworz_liste(w_kolejce_1(&fifo));
    for (int i = 1; i < ilosc_znakow; ++i)
        list_pointer = dodaj_element_1(list_pointer, w_kolejce_1(&fifo));

    printf("-------------------------");
    printf("\nLISTA:\n");
    printf("-------------------------");
    printf("\nSortuje wedlug prawdopodobienstwa rosnacego ...\n");
    pokaz_liste(list_pointer);
    for (int i = 0; i < ilosc_znakow - 1; ++i)
        list_pointer = stworz_drzewo(list_pointer);

    printf("\n--------------------------");
    printf("\nDRZEWO:\n");
    printf("--------------------------\n");
    pokaz_drzewo_2(list_pointer);

    struct stack_node *gora = NULL;
    struct code_node *wskaznik_zakodowanej_listy = NULL;

    wskaznik_zakodowanej_listy = stworz_zakodowana_liste();
    wskaznik_zakodowanej_listy = wypelnij_zakodowana_liste_znakami(list_pointer, wskaznik_zakodowanej_listy);

    struct code_node *tmp = wskaznik_zakodowanej_listy;
    for (int i = 1; i < liczebnosc_zakodowanej_listy(wskaznik_zakodowanej_listy); ++i) {
        lista_z_zakodowanymi_kodami(list_pointer, gora, tmp, tmp->data);
        tmp = tmp->nastepny;
    }
    printf("\n\nKody dla znakow:\n\n");
    pokaz_zakodowana_liste(wskaznik_zakodowanej_listy);
    printf("\nLaczna suma wszystkich elementow listy zakodowanej: %d\n",
           liczebnosc_zakodowanej_listy(wskaznik_zakodowanej_listy));

    printf("\nZdanie do zaszyfrowania: \n");
    wypisz_zdanie(zdanie);

    printf("\nZdanie zakodowane: \n");
    int ilosc_zakodowanych_znakow = wypisz_zakodowane_zdanie(wskaznik_zakodowanej_listy, &zdanie);

    printf("\n\nLaczna liczba bitow zdania ktore nie jest zakodowane: %d\n", suma_wszystkich_elementow * 8);
    printf("\nLaczna liczba bitow zdania zakodowanego: %d\n", ilosc_zakodowanych_znakow);

    puts("\nWYBOR:");
    puts("Zapisac do pliku?\n");


    printf("TAK - \"1\"\n\n");
    printf("NIE - \"2\"\n\n");
    scanf("%d", &zmienna_1);
    if (zmienna_1 == 2) {
        puts("-----------------------------------------------------");
        printf("KONIEC PROGRAMU, KLINIJ DOWOLNY PRZYCISK.\n");
        puts("-----------------------------------------------------");
    }

    if (zmienna_1 == 1) {
        char nazwa_folderu[50];
        int wynik;
        printf("Podaj nazwe pliku:\n");
        scanf("%s", nazwa_folderu);
        wynik = zapis_pliku(wskaznik_zakodowanej_listy, &zdanie, nazwa_folderu);

        if (wynik > 0) {
            printf("\nZla nazwa pliku ! ! !\n");
            return -1;
        } else {
            printf("\nPlik zostal poprawnie zapisany.\n");
        }

        wynik = odczyt_zakodowanego_pliku(wskaznik_zakodowanej_listy, nazwa_folderu, list_pointer);
    }

    usun_zakodowana_liste(&wskaznik_zakodowanej_listy);
    usun_liste(&list_pointer);
    usun_stos(&gora);
    wyczysc_zdanie(&zdanie);

    return 0;
}


////////// KOLEJKA //////////


void zakolejkowane_1(struct fifo_pointers *fifo, char data) {
    struct fifo_node *nowy_wezel = (struct fifo_node *) malloc(sizeof(struct fifo_node));
    if (nowy_wezel) {
        nowy_wezel->data = data;
        nowy_wezel->ilosc = 1;
        nowy_wezel->nastepny = NULL;
        if (fifo->poczatek == NULL) {
            fifo->poczatek = fifo->koniec = nowy_wezel;
        } else {
            fifo->koniec->nastepny = nowy_wezel;
            fifo->koniec = nowy_wezel;
        }
    }
}

struct fifo_pointers *w_kolejce_1(struct fifo_pointers *fifo) {
    struct fifo_node *nowy_wezel = (struct fifo_node *) malloc(sizeof(struct fifo_node));
    if (nowy_wezel) {
        nowy_wezel->data = fifo->poczatek->data;
        nowy_wezel->prawdopodobienstwo = fifo->poczatek->prawdopodobienstwo;
    }
    struct fifo_pointers *wskaznik = (struct fifo_pointers *) malloc(sizeof(struct fifo_pointers));
    wskaznik->poczatek = nowy_wezel;
    if (fifo->poczatek) {
        struct fifo_node *tmp = fifo->poczatek->nastepny;
        free(fifo->poczatek);
        fifo->poczatek = tmp;
        if (tmp == NULL)
            fifo->koniec = NULL;
        return wskaznik;
    }
    return NULL;
}

int znajdz_w_kolejce(struct fifo_pointers fifo, char data) {
    while (fifo.poczatek) {
        if (fifo.poczatek->data == data) {
            ++fifo.poczatek->ilosc;
            return 0;
        }
        fifo.poczatek = fifo.poczatek->nastepny;
    }
    return -1;
}


int liczba_znakow(struct fifo_pointers fifo) {
    int suma = 0;
    for (; fifo.poczatek; fifo.poczatek = fifo.poczatek->nastepny)
        suma = suma + 1;
    return suma;
}

void wypis_kolejka(struct fifo_pointers fifo) {
    for (; fifo.poczatek; fifo.poczatek = fifo.poczatek->nastepny)
        printf("ZNAK: %c ILOSC WYSTAPIEN: %d PRAWDOPODBIENSTWO: %.6lf\n", fifo.poczatek->data, fifo.poczatek->ilosc,
               fifo.poczatek->prawdopodobienstwo);
}

void prawdopodobienstwo_wystapienia(struct fifo_pointers fifo, int suma) {
    for (; fifo.poczatek; fifo.poczatek = fifo.poczatek->nastepny)
        fifo.poczatek->prawdopodobienstwo = fifo.poczatek->ilosc / (double) suma;
}

int suma_elementow(struct fifo_pointers fifo) {
    int suma = 0;
    for (; fifo.poczatek; fifo.poczatek = fifo.poczatek->nastepny)
        suma = suma + fifo.poczatek->ilosc;
    return suma;
}



////////// LISTA //////////


struct list_node *dodaj_element_1(struct list_node *list_pointer, struct fifo_pointers *fifo) {
    if (fifo == NULL)
        return NULL;

    struct list_node *nowy_wezel = (struct list_node *) malloc(sizeof(struct list_node));
    if (list_pointer && nowy_wezel) {
        nowy_wezel->data = fifo->poczatek->data;
        nowy_wezel->prawdopodobienstwo = fifo->poczatek->prawdopodobienstwo;
        nowy_wezel->nastepny = NULL;
        nowy_wezel->pien = nowy_wezel->lewa_galaz = nowy_wezel->prawa_galaz = NULL;
        if (list_pointer->prawdopodobienstwo >= fifo->poczatek->prawdopodobienstwo) {
            return dodaj_na_poczatek(list_pointer, nowy_wezel);
        } else {
            struct list_node *element = znajdz_miejsce(list_pointer, fifo->poczatek->prawdopodobienstwo);
            if (element->nastepny)
                dodaj_na_srodek(element, nowy_wezel);
            else
                dodaj_na_koniec(element, nowy_wezel);
        }
    } else
        return NULL;

    return list_pointer;
}

struct list_node *stworz_liste(struct fifo_pointers *fifo) {
    struct list_node *pierwszy = (struct list_node *) malloc(sizeof(struct list_node));
    if (pierwszy) {
        pierwszy->data = fifo->poczatek->data;
        pierwszy->prawdopodobienstwo = fifo->poczatek->prawdopodobienstwo;
        pierwszy->nastepny = NULL;
    }
    return pierwszy;
}

struct list_node *znajdz_miejsce(struct list_node *list_pointer, double data) {
    struct list_node *wczesniejszy = NULL;
    while (list_pointer && list_pointer->prawdopodobienstwo < data) {
        wczesniejszy = list_pointer;
        list_pointer = list_pointer->nastepny;
    }
    return wczesniejszy;
}

void dodaj_na_koniec(struct list_node *element, struct list_node *nowy_wezel) {
    element->nastepny = nowy_wezel;
}

void dodaj_na_srodek(struct list_node *element, struct list_node *nowy_wezel) {
    nowy_wezel->nastepny = element->nastepny;
    element->nastepny = nowy_wezel;
}

struct list_node *dodaj_na_poczatek(struct list_node *list_pointer, struct list_node *nowy_wezel) {
    nowy_wezel->nastepny = list_pointer;
    return nowy_wezel;
}

void pokaz_liste(struct list_node *list_pointer) {

    while (list_pointer) {
        printf("ZNAK: %c PRAWDOPODBIENSTWO: %.6lf\n", list_pointer->data, list_pointer->prawdopodobienstwo);
        list_pointer = list_pointer->nastepny;
    }
}

struct list_node *znajdz_poprzedni_do_usun(struct list_node *list_pointer, int data) {
    struct list_node *wczesniejszy = NULL;
    while (list_pointer && list_pointer->data != data) {
        wczesniejszy = list_pointer;
        list_pointer = list_pointer->nastepny;
    }
    return wczesniejszy;
}

struct list_node *usun_element(struct list_node *list_pointer, int data) {
    if (list_pointer) {
        if (list_pointer->data == data) {
            list_pointer = usun_z_przodu(list_pointer);
            return list_pointer;
        } else {
            struct list_node *wczesniejszy = znajdz_poprzedni_do_usun(list_pointer, data);
            usun_srodek_lub_koniec(wczesniejszy);
        }
    }
    return list_pointer;
}


struct list_node *usun_z_przodu(struct list_node *list_pointer) {
    struct list_node *nastepny = list_pointer->nastepny;
    free(list_pointer);
    return nastepny;
}

void usun_srodek_lub_koniec(struct list_node *wczesniejszy) {
    struct list_node *element = wczesniejszy->nastepny;
    if (element) {
        wczesniejszy->nastepny = element->nastepny;
        free(element);
    }
}

void usun_liste(struct list_node **list_pointer) {
    while (*list_pointer) {
        struct list_node *nastepny = (*list_pointer)->nastepny;
        free(*list_pointer);
        *list_pointer = nastepny;
    }
}


////////// DRZEWO //////////


struct list_node *stworz_drzewo(struct list_node *list_pointer) {
    if (list_pointer->nastepny == NULL)
        return list_pointer;
    struct list_node *nowy_wezel = (struct list_node *) malloc(sizeof(struct list_node));

    if (nowy_wezel && list_pointer) {
        nowy_wezel->data = '&';
        nowy_wezel->prawdopodobienstwo = list_pointer->prawdopodobienstwo + list_pointer->nastepny->prawdopodobienstwo;
        nowy_wezel->nastepny = NULL;
        nowy_wezel->pien = NULL;
        nowy_wezel->lewa_galaz = list_pointer;

        list_pointer->pien = nowy_wezel;
        nowy_wezel->prawa_galaz = list_pointer->nastepny;
        nowy_wezel->prawa_galaz->pien = nowy_wezel;
        nowy_wezel->strona = -1;
        nowy_wezel->lewa_galaz->strona = 0;
        nowy_wezel->prawa_galaz->strona = 1;

        if (list_pointer->nastepny->nastepny != NULL) {
            list_pointer = list_pointer->nastepny->nastepny;
            wyczysc_jeden(nowy_wezel);
        } else {
            wyczysc_jeden(nowy_wezel);
            list_pointer = nowy_wezel;
            list_pointer->nastepny = NULL;
            return list_pointer;
        }

        if (list_pointer && list_pointer->prawdopodobienstwo >= nowy_wezel->prawdopodobienstwo) {
            return dodaj_na_poczatek(list_pointer, nowy_wezel);
        } else {
            struct list_node *node = znajdz_miejsce(list_pointer, nowy_wezel->prawdopodobienstwo);
            if (node->nastepny)
                dodaj_na_srodek(node, nowy_wezel);
            else
                dodaj_na_koniec(node, nowy_wezel);
        }
    } else {
        printf("BLAD!");
        return NULL;
    }

    return list_pointer;
}

void pokaz_drzewo(struct list_node *korzen, int level) {
    if (korzen) {
        if (level == 1)
            printf(" [%c : %d] ", korzen->data, korzen->strona);
        else {
            pokaz_drzewo(korzen->lewa_galaz, level - 1);
            pokaz_drzewo(korzen->prawa_galaz, level - 1);
        }
    }
}

void pokaz_drzewo_2(struct list_node *korzen) {
    int h = znajdz_gore(korzen) + 1;
    int i;
    for (i = 0; i <= h; i++) {
        pokaz_drzewo(korzen, i);
        printf("\n");
    }
}

int znajdz_gore(struct list_node *korzen) {
    if (korzen == NULL) {
        return -1;
    }

    int lewo = znajdz_gore(korzen->lewa_galaz);
    int prawo = znajdz_gore(korzen->prawa_galaz);

    if (lewo > prawo) {
        return lewo + 1;
    } else {
        return prawo + 1;
    }
}

void wyczysc_jeden(struct list_node *nowy_wezel) {
    nowy_wezel->lewa_galaz->nastepny = nowy_wezel->prawa_galaz->nastepny = NULL;
    wyczysc_trzy(&(*nowy_wezel));
}

void wyczysc_trzy(struct list_node *nowy_wezel) {
    if (nowy_wezel->data != '&') {
        nowy_wezel->lewa_galaz = nowy_wezel->prawa_galaz = NULL;

    } else {
        wyczysc_trzy(nowy_wezel->lewa_galaz);
        wyczysc_trzy(nowy_wezel->prawa_galaz);
    }
}


////////// PLIK DO OBSLUGIWANIA //////////

int odczytywany_plik(char *nazwa_folderu, char *tab) {

    int rozmiar = 0;
    FILE *file = fopen(nazwa_folderu, "r");
    if (file == NULL)
        return -1;
    while (!feof(file)) {
        char data_from_file = fgetc(file);
        if (data_from_file == '&')
            break;
        tab[rozmiar] = data_from_file;
        rozmiar++;
    }
    tab[++rozmiar] = '\0';
    if (fclose(file) != 0)
        return -1;
    return 0;
}

short char_1(char c) {
    if (c == '1')
        return 1;
    if (c == '0')
        return 0;


    else
        return -1;
}

int zapis_pliku(struct code_node *wskaznik_zakodowanej_listy, struct sentence_pointers *zdanie, char *nazwa_folderu) {

    FILE *file = fopen(nazwa_folderu, "wb");
    if (file == NULL)
        return -1;
    else {
        struct code_node *tmp = wskaznik_zakodowanej_listy;
        struct sentence_node *mem_head = zdanie->poczatek;
        int i;
        for (; zdanie->poczatek; zdanie->poczatek = zdanie->poczatek->nastepny) {
            for (tmp = wskaznik_zakodowanej_listy; tmp; tmp = tmp->nastepny) {

                if (zdanie->poczatek->data == tmp->data) {
                    for (i = 0; i < tmp->code_size; ++i) {
                        fwrite(&(tmp->code[i]), sizeof(unsigned char), 1, file);
                    }
                }
            }
        }
        if (fclose(file) != 0)
            return -3;
        zdanie->poczatek = mem_head;
    }

    return 0;
}

int
odczyt_zakodowanego_pliku(struct code_node *wskaznik_listy_zakodowanej, char *nazwa_folderu, struct list_node *korzen) {
    printf("\nZdanie odkodowane:\n");
    FILE *file = fopen(nazwa_folderu, "rb");
    struct list_node *tmp = korzen;
    if (file == NULL)
        return -1;
    else {
        while (!feof(file)) {
            unsigned char czytaj_kod;
            fread(&czytaj_kod, 1, 1, file);
            if (!feof(file)) {
                if (czytaj_kod == 0) {
                    tmp = tmp->lewa_galaz;
                } else if (czytaj_kod == 1) {
                    tmp = tmp->prawa_galaz;
                }
                if (tmp->data != '&') {
                    printf("%c", tmp->data);
                    tmp = korzen;
                }
            }
        }
        fclose(file);
    }
    printf("\n");

    return 0;
}


////////// WPROWADZANE ZDANIE //////////

void zakolejkowane_zdanie(struct sentence_pointers *zdanie, char data) {
    struct sentence_node *nowy_wezel = (struct sentence_node *) malloc(sizeof(struct sentence_node));
    if (nowy_wezel) {
        nowy_wezel->data = data;
        nowy_wezel->nastepny = NULL;
        if (zdanie->poczatek == NULL) {
            zdanie->poczatek = zdanie->koniec = nowy_wezel;
        } else {
            zdanie->koniec->nastepny = nowy_wezel;
            zdanie->koniec = nowy_wezel;
        }
    } else
        puts("BRAK ELEMENTU ! ! !");
}


void wyczysc_zdanie(struct sentence_pointers *zdanie) {
    while (zwroc_znak_ze_zdania(zdanie) != '\0');
}

char zwroc_znak_ze_zdania(struct sentence_pointers *zdanie) {
    if (zdanie->poczatek) {
        struct sentence_node *tmp = zdanie->poczatek->nastepny;
        char data = zdanie->poczatek->data;
        free(zdanie->poczatek);
        zdanie->poczatek = tmp;
        if (tmp == NULL)
            zdanie->koniec = NULL;
        return data;
    }
    return '\0';
}

void wypisz_zdanie(struct sentence_pointers zdanie) {
    for (; zdanie.poczatek; zdanie.poczatek = zdanie.poczatek->nastepny)
        printf(" %c", zdanie.poczatek->data);
}

////////// STOS //////////

struct stack_node *dodaj_na_stos(struct stack_node *gora, int data) {
    struct stack_node *nowy_wezel = (struct stack_node *) malloc(sizeof(struct stack_node));
    if (nowy_wezel != NULL) {
        nowy_wezel->data = data;
        nowy_wezel->nastepny = gora;
        gora = nowy_wezel;
    }
    return gora;
}

void usun_stos(struct stack_node **gora) {
    while (pop(gora) != -1);
}

void pokaz_stos(struct stack_node *gora) {
    while (gora) {
        printf("%d \n", gora->data);
        gora = gora->nastepny;
    }

}

int liczebnosc_stosu(struct stack_node *gora) {
    int liczba = 0;
    for (; gora; gora = gora->nastepny)
        liczba++;
    return liczba;
}

int pop(struct stack_node **gora) {
    int result = -1;
    if (*gora != NULL) {
        result = (*gora)->data;
        struct stack_node *tmp = (*gora)->nastepny;
        free(*gora);
        *gora = tmp;
    }
    return result;

}


////////// LISTA Z KODAMI //////////

struct code_node *stworz_zakodowana_liste() {
    struct code_node *pierwszy = (struct code_node *) malloc(sizeof(struct code_node));
    if (pierwszy) {
        pierwszy->data = '&';
        pierwszy->code_size = 0;
        pierwszy->nastepny = NULL;
    }
    return pierwszy;
}

struct code_node *dodaj_jeden_wezel(struct code_node *wskaznik_zakodowanej_listy, char data) {
    struct code_node *nowy_wezel = (struct code_node *) malloc(sizeof(struct code_node));
    if (nowy_wezel) {
        nowy_wezel->data = data;
        nowy_wezel->code_size = 0;
        nowy_wezel->nastepny = NULL;
        return dodaj_zakodowanie_1(wskaznik_zakodowanej_listy, nowy_wezel);
    }
    return 0;
}

struct code_node *
wypelnij_zakodowana_liste_znakami(struct list_node *korzen, struct code_node *wskaznik_zakodowanej_listy) {
    if (korzen) {
        wskaznik_zakodowanej_listy = wypelnij_zakodowana_liste_znakami(korzen->lewa_galaz, wskaznik_zakodowanej_listy);
        wskaznik_zakodowanej_listy = wypelnij_zakodowana_liste_znakami(korzen->prawa_galaz, wskaznik_zakodowanej_listy);
        if (korzen->data != '&') {
            wskaznik_zakodowanej_listy = dodaj_jeden_wezel(wskaznik_zakodowanej_listy, korzen->data);
        }
    }
    return wskaznik_zakodowanej_listy;
}

void lista_z_zakodowanymi_kodami(struct list_node *korzen, struct stack_node *gora,
                                 struct code_node *wskaznik_zakodowanej_listy, char data) {
    if (korzen) {
        if (korzen->data == data) {
            struct list_node *tmp = korzen;
            for (; tmp->pien; tmp = tmp->pien)
                gora = dodaj_na_stos(gora, tmp->strona);
            dodaj_kod(gora, wskaznik_zakodowanej_listy, liczebnosc_stosu(gora));
        }
        lista_z_zakodowanymi_kodami(korzen->lewa_galaz, gora, wskaznik_zakodowanej_listy, data);
        lista_z_zakodowanymi_kodami(korzen->prawa_galaz, gora, wskaznik_zakodowanej_listy, data);
    }
}


struct code_node *dodaj_zakodowanie_1(struct code_node *wskaznik_listy_zakodowanej, struct code_node *nowa_galaz) {
    nowa_galaz->nastepny = wskaznik_listy_zakodowanej;
    return nowa_galaz;
}

void dodaj_kod(struct stack_node *gora, struct code_node *wskaznik_listy_zakodowanej, int rozmiar) {
    int i;
    wskaznik_listy_zakodowanej->code_size = rozmiar;
    for (i = 0; i < rozmiar; i++)
        wskaznik_listy_zakodowanej->code[i] = pop(&gora);
}


int liczebnosc_zakodowanej_listy(struct code_node *wskaznik_listy_zakodowanej) {
    int result = 0;
    while (wskaznik_listy_zakodowanej) {
        result++;
        wskaznik_listy_zakodowanej = wskaznik_listy_zakodowanej->nastepny;
    }
    return result;
}

void pokaz_zakodowana_liste(struct code_node *wskaznik_listy_zakodowanej) {
    while (wskaznik_listy_zakodowanej) {
        printf("ZNAK: %c KOD: ", wskaznik_listy_zakodowanej->data);
        int i;
        for (i = 0; i < wskaznik_listy_zakodowanej->code_size; ++i)
            printf(" %d", wskaznik_listy_zakodowanej->code[i]);
        puts("");
        wskaznik_listy_zakodowanej = wskaznik_listy_zakodowanej->nastepny;
    }
}

void usun_zakodowana_liste(struct code_node **wskaznik_listy_zakodowanej) {
    while (*wskaznik_listy_zakodowanej) {
        struct code_node *nastepny = (*wskaznik_listy_zakodowanej)->nastepny;
        free(*wskaznik_listy_zakodowanej);
        *wskaznik_listy_zakodowanej = nastepny;
    }
}

int wypisz_zakodowane_zdanie(struct code_node *wskaznik_listy_zakodowanej, struct sentence_pointers *zdanie) {

    struct code_node *tmp = wskaznik_listy_zakodowanej;
    struct sentence_node *mem_head = zdanie->poczatek;
    int i;
    int ilosc_znakow = 0;
    for (; zdanie->poczatek; zdanie->poczatek = zdanie->poczatek->nastepny)
        for (tmp = wskaznik_listy_zakodowanej; tmp; tmp = tmp->nastepny)
            if (zdanie->poczatek->data == tmp->data) {
                ilosc_znakow += tmp->code_size;
                for (i = 0; i < tmp->code_size; ++i)
                    printf("%d", tmp->code[i]);
            }
    zdanie->poczatek = mem_head;
    return ilosc_znakow;
}
