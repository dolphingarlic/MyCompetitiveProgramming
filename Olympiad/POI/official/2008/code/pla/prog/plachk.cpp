/*************************************************************************
 *                                                                       *
 *                     XV  Olimpiada Informatyczna                       *
 *                                                                       *
 *   Zadanie:  Plakatowanie (PLA)                                        *
 *   Plik:     plachk.cpp                                                *
 *   Autor:    Michal Pilipczuk                                          *
 *   Opis:     Program weryfikujacy poprawnosc wyjscia wygenerowanego    *
 *             przez program zawodnika, format:                          *
 *               ./plachk.e in out_zawodnika out_wzorcowy                *
 *                                                                       *
 *************************************************************************/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <iterator>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <map>

using namespace std;

typedef long long LL;

#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define FORL(v,p,k) for(int v=p;v<k;++v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define PB push_back
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()

const int N = 200*1000;
FILE *sol, *out;
int wynik[N];
void WA(char *txt){
    printf("WRONG_ANSWER\n%s\n", txt);
    exit(0);
}

/*Wczytywanie poprawnego outa*/
int n,k;

void wczytaj(){
    fscanf(sol,"%d\n",&n);
}

int bylo[N];

char txt[1000];
int txtpoz;
int czytaj_znak(void){
    while(txt[txtpoz] == 0){
        if (!fgets(txt, 999, out)) return 1000;
        txtpoz = 0;
    }
    return txt[txtpoz++];
}

bool puste(int x){ return x==' ' || x=='\n' || x=='\r' || x == '\t'; }
bool byl_eof = false;
int czytaj_int(void){
    LL liczba = 0LL;
    int w;
    do{ w = czytaj_znak(); } while(puste(w));
    if (w == 1000) WA("Za krotki plik.");
    while(w >= '0' && w <= '9'){
        if (liczba > (1000LL * 1000LL * 1000LL))
            WA("Za duza liczba w pliku.");
        liczba = 10LL * liczba + (LL)(w-'0');
        w = czytaj_znak();
    }
    if (w != 1000 && !puste(w) && !(w >= '0' && w<= '9')) WA("Smieci w pliku.");
    if (w == 1000) byl_eof = true;
    return liczba;
}

bool czy_eof(void){
    if (byl_eof) return true;
    int w; do { w = czytaj_znak(); }while(puste(w));
    return w == 1000;
}

int main(int argc, char *argv[]){
    if ((sol = fopen(argv[3], "r")) == NULL || 
        (out = fopen(argv[2], "r")) == NULL)
        WA("Brak pliku.");
    wczytaj();
    k=czytaj_int();
    if (k != n) {printf("WRONG ANSWER\nZla liczba plakatow: wczytano %d, oczekiwano %d.\n",k,n); exit(0);}
    if (!czy_eof()) WA("Smieci na koncu pliku.");
    printf("OK\n");
    return 0;
}
