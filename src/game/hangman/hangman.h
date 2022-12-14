#ifndef HANGMAN_H
#define HANGMAN_H

#include "time.h"
#include "../../boolean.h"
#include "../../ADT/Array/array.h"
#include "../../ADT/MesinKata/mesin_kata.h"
#include "../../ADT/set/set.h"

extern int MODE;
extern array Answers;

/* Fungsi utama game */
void Hangman(int* Score);

/* Prosedure memilih mode */
void PilihMode(int* mode);

/* Menyimpan dictionary kedalam file */
void saveDictionary(array arr);

/* Menyiapkan Word Tebakan */
void MakeTebakan(Word Jawaban, Word *Tebakan);

/* Mengecek apakah input terdapat dalam Jawaban */
boolean CheckJawab(Word Jawaban, Word* Tebakan, Word input);

/* Men-generate kata baru dari array */
void generateKata(array* arr, Word* Jawaban);

#endif