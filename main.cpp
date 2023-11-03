#include "tubes.h"
#include "Tubes.cpp"


int main() {
    multiList L;
    createList(L);
    int Pil;
    do{
        system("CLS");
        cout<<"+-------------------------------------------------------------------+\n";
        cout<<"|                   *  ORGANISASI MAHASISWA  *                      |\n";
        cout<<"+-------------------------------------------------------------------+\n";
        cout<<"| 1.  Tambahkan Ormawa                                              |\n";
        cout<<"| 2.  Tambahkan Anggota                                             |\n";
        cout<<"| 3.  Hubungkan Anggota dengan Ormawa                               |\n";
        cout<<"| 4.  Hapus Ormawa                                                  |\n";
        cout<<"| 5.  Hapus Anggota                                                 |\n";
        cout<<"| 6.  Menampilkan semua Ormawa beserta Anggotanya                   |\n";
        cout<<"| 7.  Hapus relasi                                                  |\n";
        cout<<"| 99. Keluar                                                        |\n";
        cout<<"+___________________________________________________________________+\n";
        cout<<"\nMasukkan Pilihan : ";cin>>Pil;
        switch (Pil){
            case 1:
                tambahOrmawa(L);
                break;
            case 2:
                tambahAnggota(L);
                break;
            case 3:
                addRelasi(L);
                break;
            case 4:
                HapusOrmawa(L);
                break;
            case 5:
                HapusAnggota(L);
                break;
            case 6:
                system("CLS");
                cout<<"+------------- DAFTAR ORMAWA BESERTA ANGGOTANYAs -------------+\n\n";
                TampilOrmawaDanAnggotanya(L);
                cout<<"\n\nEnter untuk kembali...";
                getch();
                break;
            case 7:
                menuHapusRelasi(L);
                break;
            case 99:
                break;
            default:
                cout<<"Pilihan tidak ada...\n";
                getch();
        }
    }while (Pil!=99);
    return 0;
}
