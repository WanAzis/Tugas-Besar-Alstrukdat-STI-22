#include <stdio.h>
#include "queueDD.h"

/* *** Kreator *** */
void MakeQueue(QueueDD *q){
    IDX_HEAD(*q)=IDX_UNDEF;
    IDX_TAIL(*q)=IDX_UNDEF;
}
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean ISEmpty(QueueDD q){
    return IDX_HEAD(q)==IDX_UNDEF && IDX_TAIL(q)==IDX_UNDEF;
}
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean IsFull(QueueDD q){
    return IDX_TAIL(q)==CAPACITY-1;
}
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int Len(QueueDD q){
    return IDX_TAIL(q)+1;
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void Enqueue(QueueDD *q, Food val){
    if (ISEmpty(*q)){
        IDX_HEAD(*q)=0;
        IDX_TAIL(*q)=0;
        TAIL(*q)=val;
    } else {
        IDX_TAIL(*q)++;
        TAIL(*q)=val;
    }
}
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void DequeueAt(QueueDD *q, Food *val, int idx){
    *val = (*q).buffer[idx];
    if (IDX_HEAD(*q)==IDX_TAIL(*q)){
        IDX_HEAD(*q)=IDX_UNDEF;
        IDX_TAIL(*q)=IDX_UNDEF;
    } else {
        for (int i = idx; i<Len(*q)-1; i++){
            (*q).buffer[i]=(*q).buffer[i+1];
        } IDX_TAIL(*q)--;
    }
}
/* Proses: Menghapus val pada q dengan idx sesuai inputan */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen idx pd I.S., element setelah idx bergeser; 
        q mungkin kosong */

/* *** Display Queue *** */
void DisplayQueue(QueueDD q){
    if (ISEmpty(q)){
        printf("[]\n");
    } else {
        printf("[");
        for (int i = IDX_HEAD(q); i<Len(q)-1; i++){
            printf("%i %i %i %i,", q.buffer[i].id, q.buffer[i].durasi, q.buffer[i].ketahanan, q.buffer[i].harga);
        } printf("%i %i %i %i", TAIL(q).id, TAIL(q).durasi, TAIL(q).ketahanan, TAIL(q).harga); 
        printf("]\n");
    }
}
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
