#ifndef CONSOLE_H
#define CONSOLE_H

#include "ADT/Array/Array.h"
#include "ADT/MesinKata/mesin_karakter.h"
#include "ADT/MesinKata/mesin_kata.h"
#include "ADT/Queue/Queue.h"

extern array ListGame;
extern Queue QueueGame;
extern int fitur, mode;

/* Fitur-fitur pada BNMO */

void MENU();
/* Tampilan awal mesin BNMO yang akan menampilkan pilihan START atau LOAD untuk playar */

void FITURE();
/* Perintah untuk menampilkan seluruh fitur BNMO yang dapat dipilih oleh user */

void CHOOSEMODE(int *mode);
/* Memilih mode awal apakah player memilih START atau LOAD */

void STARTBNMO();
/* Memulai mesin BNMO dengan mengakses file konfigurasi default */

void LOADBNMO();
/* Memulai mesin BNMO dengan mengakses file save player sebelumnya */

void CHOOSEFITURE(int *fitur);
/* Menerima perintah dari pengguna untuk menjalankan fitur yang diinginkan */

void SAVE();
/* Menyimpan state terkini mesin BNMO kedalam file inputan player */

void CREATEGAME(array *ListGame);
/* Membuat sebuah game baru inputan player */

void LISTGAME(array ListGame);
/* Menampilkan daftar game terkini yang dimiliki oleh player */

void DELETEGAME(array *ListGame);
/* Menghapus sebuah game yang dimiliki oleh player */

// void QUEUEGAME(IdxType X, array ListGame, Queue *QueueGame);
// /* Mendaftarkan sebuah game yang dimiliki oleh player kedalam Queue Game untuk dimainkan */

/*prosedur queuegame*/
void QUEUEGAME(Queue *q);
/*
Deskripsi: function akan dijalankan ketika menerima input dari user berupa "QUEUE GAME", 
           intinya setiap dipanggil, akan memilih game pada list game, dan akan dimasukkan
           kedalam queue. 
           Catatan: - Memungkinkan untuk ada lebih dari satu game yang sama pada queue.
                    - Disini hanya memasukkan game, masalah penanganan input valid/tidak 
                      bukan disini, di file main.
                    - Diasumsikan maksimum queue pada satu kali proses bermain adalah 10
I.S. input sudah valid, list game + queue game (jika sudah ada) di tampilkan
F.S. memasukkan game ke-n yang diminta user (jika input valid)
*/

// void PLAYGAME(IdxType X, array ListGame);
// /* Memainkan sebuah game yang dimiliki oleh player */

/*prosedur playgame*/
void PLAYGAME(Queue *q /*harusnya ada list juga*/);
/*
Deskripsi: function akan dijalankan ketika menerima input dari user berupa "PLAY GAME"
           ketika dipanggil, akan mengecek apakah queue game kosong atau tidak, jika kosong,
           maka akan menampilkan list game, lalu meminta input game yang akan dimainkan. Jika
           queue game tidak kosong, maka akan menjalankan game pertama yang ada di queue.
           Catatan - Dilakukan pengecekan valid/tidak nya input (jika queue kosong)
                   - 
I.S. list game ditampilkan (bisa berupa queue jika sudah ada, kalau queue kosong, tampilkan
list game awal). 
F.S. game dimainkan (memanggil game jika dia RNG/Dinner Dash)
*/

// void SKIPGAME(IdxType X, Queue *QueueGame);
// /* Melewatkan satu atau beberapa game dari Queue Game yang dimiliki player */

/*prosedur skipGame*/
void SKIPGAME(Queue *q);
/*
Deskripsi: function akan dilakukan ketika queue game sudah ada dan user memberika input
           berupa "SKIP GAME n". Jika n>length queue, maka muncul pesan error, jika n valid,
           maka akan mengeskip game sebanyak n kali(dequeue sebanyak n kali) lalu menjalankan 
           function playgame
           Catatan: -
I.S. list game ditampilkan (bisa berupa queue jika sudah ada, kalau queue kosong, tampilkan
list game awal). n sudah di dapat dari input command
F.S. game di skip, lalu dimainkan
*/

void QUIT();
/* Player keluar dari mesin BNMO */

void HELP();
/* Menampilkan menu fitur-fitur yang dimiliki oleh mesin BNMO serta penjelasannya */

void COMMANDLAIN();
/* Mengeluarkan pesan kesalahan serta meminta inputan ulang ketika player memberi perintah yang tidak valid */


#endif 