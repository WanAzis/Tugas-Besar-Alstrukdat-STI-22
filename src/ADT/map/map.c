#include <stdio.h>
#include "map.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptymap(Map *M){
    (*M).Count=0;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptymap(Map M){
    return M.Count==0;
}
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsFullmap(Map M){
    return M.Count==MaxEl;
}
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
valuetype Value(Map M, keytype k){
    boolean found = false;
    int i = 0;
    while(i<M.Count && !found){
        if(WordCompare(M.Elements[i].Key, k)){
            found = true;
        } else {
            i++;
        }
    }
    if (found){
        return M.Elements[i].Value;
    } else {return Undefined;}
}
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void Insertmap(Map *M, keytype k, valuetype v){
    if(!IsMembermap(*M, k)){
        int i = (*M).Count;
        while (i>0 && v > (*M).Elements[i-1].Value){
            (*M).Elements[i]=(*M).Elements[i-1];
            i--;
        } // i = 0 or v <= (*M).Elements[i-1].Value
        (*M).Elements[i].Key=k;
        (*M).Elements[i].Value=v;
        (*M).Count++;
    }
}
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void Deletemap(Map *M, keytype k){
    boolean found = false;
    int i = 0;
    while (i<(*M).Count && !found){
        if(WordCompare((*M).Elements[i].Key, k)){
            found = true;
        } else{
            i++;
        }
    }
    if (found){
        while (i<(*M).Count-1){
            (*M).Elements[i]=(*M).Elements[i+1];
            i++;
        } (*M).Count--;
    }
}
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMembermap(Map M, keytype k){
    boolean found = false;
    int i = 0;
    while (i<M.Count && !found){
        if(WordCompare(M.Elements[i].Key, k)){
            found= true;
        } else{
            i++;
        }
    } return found;
}
/* Mengembalikan true jika k adalah member dari M */

void CetakMap(Map M){
    if (IsEmptymap(M)){
        printf("{}\n");
    } else {
        printf("{");
        for (int i = 0; i<M.Count-1; i++){
            PrintKata(M.Elements[i].Key);printf(";");printf("%i , ",M.Elements[i].Value);
        } PrintKata(M.Elements[M.Count-1].Key);printf(";");printf("%i",M.Elements[M.Count-1].Value);
        printf("}\n");
    }
}
/* Mencetak Map M kelayar */