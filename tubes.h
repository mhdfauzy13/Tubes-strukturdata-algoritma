#ifndef TUBES_STD_TUBES_H
#define TUBES_STD_TUBES_H
#define nextM(P) P->nextM
#define nextD(P) P->nextD
#define nextR(P) P->nextR
#define infoM(P) P->infoM
#define infoD(P) P->infoD
#define rel(P) P->rel
#define link(P) P->link
#define first_ormawa(L) L.first_ormawa
#define first_anggota(L) L.first_anggota
#define last_ormawa(L) L.last_ormawa
#define last_anggota(L) L.last_anggota
#define NIL NULL

#include <iostream>
#include <cstddef>
#include <string>
#include <stdlib.h>
#include <conio.h>
using namespace std;

typedef string infotype;
typedef struct ormawa *address_ormawa;
typedef struct relasi *address_relasi;
typedef struct anggota *address_anggota;

struct ormawa{
    infotype infoM;
    address_ormawa nextM;
    address_relasi rel;
};
struct relasi{
    address_relasi nextR;
    address_anggota link;
};
struct anggota{
    infotype infoD;
    address_anggota nextD;
};
struct multiList{
    address_ormawa first_ormawa;
    address_ormawa last_ormawa;
    address_anggota first_anggota;
    address_anggota last_anggota;
};

void createList(multiList &L);
address_ormawa allocatedOrmawa(infotype X);
address_anggota allocatedAnggota(infotype X);
address_relasi allocatedRel();
void insertOrmawa(address_ormawa P, multiList &L);
void insertAnggota(address_anggota P, multiList &L);
address_ormawa searchOrmawa(infotype X,multiList L);
address_anggota searchAnggota(infotype X,multiList L);
bool cekRelasi(address_ormawa M, address_anggota D);
void addRelasi(multiList &L);
void tambahAnggota(multiList &L);
void tambahOrmawa(multiList &L);
void HapusOrmawa(multiList &L);
void HapusRelasi(address_ormawa &M, address_anggota D);
void HapusAnggota(multiList &L);
void TampilOrmawaDanAnggotanya(multiList L);
//void tampilPengajarMatkulterbanyak(multiList L);
//void tampilPengajarMatkul(multiList L);
//int cek3matkul(address_matKul M, address_Dosen D);
//void tampilDosen3Matkul(multiList L);
void tampilSemuaOrmawa(multiList L);
void tampilSemuaAnggota(multiList L);
void menuHapusRelasi(multiList &L);
#endif //TUBES_STD_TUBES_H
