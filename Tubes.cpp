#include "tubes.h"

void createList(multiList &L){
    first_ormawa(L) = NIL;
    last_ormawa(L) = NIL;
    first_anggota(L) = NIL;
    last_anggota(L) = NIL;
}
address_ormawa allocatedOrmawa(infotype X){
    address_ormawa P = new ormawa;
    infoM(P) = X;
    nextM(P) = NIL;
    rel(P) = NIL;
    return  P;
}
address_anggota allocatedAnggota(infotype X){
    address_anggota P = new anggota;
    infoD(P) = X;
    nextD(P) = NIL;
    return P;
}
address_relasi allocatedRel(){
    address_relasi P = new relasi;
    nextR(P) = NIL;
    link(P) = NIL;
    return P;
}
void insertOrmawa(address_ormawa P, multiList &L){
    if (first_ormawa(L)==NIL){
        first_ormawa(L) = P;
        last_ormawa(L) = P;
    } else {
        address_ormawa Q = last_ormawa(L);
        nextM(Q) = P;
        last_ormawa(L) = P;
    }
}
void insertAnggota(address_anggota P, multiList &L){
    if (first_anggota(L)==NIL){
        first_anggota(L) = P;
        last_anggota(L) = P;
    }else{
        address_anggota Q = last_anggota(L);
        nextD(Q) = P;
        last_anggota(L) = P;
    }
}
address_ormawa searchOrmawa(infotype X,multiList L){
    address_ormawa P = first_ormawa(L);
    while (P!=NIL && infoM(P)!=X )
        P = nextM(P);
    return P;
}
address_anggota searchAnggota(infotype X,multiList L){
    address_anggota P = first_anggota(L);
    while (P!=NIL && infoD(P)!=X )
        P = nextD(P);
    return P;
}
bool cekRelasi(address_ormawa M, address_anggota D){
    bool valid = false;
    address_relasi R = rel(M);
    while (R != NIL && !valid){
        if (link(R)==D){
            valid = true;
        }
        R = nextR(R);
    }
    return valid;
}
void tambahAnggota(multiList &L){
    infotype nama;
    address_anggota P = first_anggota(L);
    system("CLS");
    cout<<"+------------- TAMBAH ANGGOTA -------------+\n\n";
    tampilSemuaAnggota(L);
    cout<<"Masukkan nama Anggota : ";cin>>nama;
    while(P != NIL && infoD(P)!=nama){
        P = nextD(P);
    }
    if (P==NIL) {
        P = allocatedAnggota(nama);
        insertAnggota(P, L);
        cout<<"\n[+] Anggota atas nama "<<nama<<" berhasil di tambahkan";
    }else if (infoD(P)==nama){
        cout<<"\n[!] Anggota atas nama "<<nama<<" sudah terdaftar";
    }
    getch();
}
void tambahOrmawa(multiList &L){
    infotype nama;
    address_ormawa P = first_ormawa(L);
    system("CLS");
    cout<<"+------------- TAMBAH ORMAWA -------------+\n\n";
    tampilSemuaOrmawa(L);
    cout<<"Masukkan nama ORMAWA : ";cin>>nama;
    while(P != NIL && infoM(P)!=nama){
        P = nextM(P);
    }
    if (P==NIL) {
        P = allocatedOrmawa(nama);
        insertOrmawa(P, L);
        cout<<"\n[+] Ormawa "<<nama<<" berhasil di tambahkan";
    }else if (infoM(P)==nama){
        cout<<"\n[!] Ormawa "<<nama<<" sudah terdaftar";
    }
    getch();
}
void addRelasi(multiList &L){
    infotype input;
    string Title = "+------------- TAMBAH RELASI -------------+\n\n";
    address_ormawa P = first_ormawa(L);
    address_anggota Q = first_anggota(L);
    bool valid = false;
    if (P==NIL || Q==NIL){
        if (P!=NIL && Q==NIL){
            cout<<"\n[!] Tidak ada Anggota yang tersedia";
        }else if (P==NIL && Q!=NIL){
            cout<<"\n[!] Tidak ada Ormawa yang tersedia";
        }else{
            cout<<"\n[!] Anggota dan Ormawa tidak tersedia";
        }
        getch();
    }else{
        do {
            system("CLS");
            cout<<Title;
            tampilSemuaOrmawa(L);
            cout<<"Masukkan nama Ormawa ('cancel' untuk kembali): "; cin>>input;
            P = searchOrmawa(input,L);
            if (input == "cancel" || P != NIL){
                valid = true;
            }else {
                cout<<"[!] Ormawa tidak tersedia";
                getch();
            }
        }while (!valid);
        valid = false;
        while (!valid && input != "cancel"){
            system("CLS");
            cout<<Title;
            tampilSemuaAnggota(L);
            cout<<"Masukkan nama Anggota ('cancel' untuk kembali): "; cin>>input;
            Q = searchAnggota(input,L);
            if (input == "cancel" || Q != NIL){
                valid = true;
            }else{
                cout<<"[!] Anggota tidak tersedia";
                getch();
            }
        }
        if (input != "cancel"){
            if (!cekRelasi(P,Q)){
                address_relasi R = allocatedRel();
                if (rel(P)==NIL) {
                    rel(P) = R;
                }else{
                    address_relasi relation = rel(P);
                    while (nextR(relation)!=NIL){
                        relation = nextR(relation);
                    }
                    nextR(relation) = R;
                }
                link(R) = Q;
                cout<<"\n[+] Berhasil menghubungkan";
            }else{
                cout<<"\n[!] Anggota atas nama "<<infoD(Q)<<" sudah mengikuti Ormawa "<<infoM(P);
            }
            cout<<"\n\nEnter untuk kembali...";
            getch();
        }
    }
}
void HapusOrmawa(multiList &L) {
    infotype nama;
    address_ormawa P = first_ormawa(L);
    if (P!=NIL){
        system("CLS");
        cout<<"+------------- HAPUS ORMAWA -------------+\n\n";
        tampilSemuaOrmawa(L);
        cout<<"Masukkan nama Ormawa yang akan dihapus : ";
        cin>>nama;
        P = searchOrmawa(nama, L);
        if (P != NULL) {
            if (P == first_ormawa(L)) {
                first_ormawa(L) = nextM(P);
                nextM(P) = NIL;
            } else if (P == last_ormawa(L)) {
                address_ormawa Q = first_ormawa(L);
                while (nextM(Q) != P) {
                    Q = nextM(Q);
                }
                nextM(Q) = NIL;
                last_ormawa(L) = Q;
            } else {
                address_ormawa Q = first_ormawa(L);
                while (nextM(Q) != P) {
                    Q = nextM(Q);
                }
                nextM(Q) = nextM(P);
                nextM(P) = NIL;
            }
            delete P;
            cout<<"\n[!] Ormawa berhasil di hapus";
        } else {
            cout<<"\n[!] Ormawa tidak tersedia";
        }
    }else{
        cout<<"\n[!] Ormawa kosong";
    }
    getch();
}
void HapusRelasi(address_ormawa &M, address_anggota D){
    if (cekRelasi(M,D)){
        address_relasi R = rel(M);
        if (link(R)==D){
            rel(M)=nextR(R);
            link(R)=NIL;
            delete R;
        }else {
            address_relasi R2 = nextR(R);
            while (link(R2) != D) {
                R = nextR(R);
                R2 = nextR(R2);
            }
            link(R2) = NIL;
            nextR(R) = nextR(R2);
            delete R2;
        }
    }
}
void HapusAnggota(multiList &L) {
    infotype nama;
    address_anggota P = first_anggota(L);
    if (P!=NIL){
        system("CLS");
        cout<<"+------------- HAPUS ANGGOTA -------------+\n\n";
        tampilSemuaAnggota(L);
        cout<<"Masukkan nama Anggota yang akan dihapus : ";
        cin>>nama;
        P = searchAnggota(nama, L);
        address_ormawa Q = first_ormawa(L);
        while (Q!=NIL){
            HapusRelasi(Q,P);
            Q = nextM(Q);
        }
        if (P != NULL) {
            if (P == first_anggota(L)) {
                first_anggota(L) = nextD(P);
                nextD(P) = NIL;
            } else if (P == last_anggota(L)) {
                address_anggota Q = first_anggota(L);
                while (nextD(Q) != P) {
                    Q = nextD(Q);
                }
                nextD(Q) = NIL;
                last_anggota(L) = Q;
            } else {
                address_anggota Q = first_anggota(L);
                while (nextD(Q) != P) {
                    Q = nextD(Q);
                }
                nextD(Q) = nextD(P);
                nextD(P) = NIL;
            }
            cout<<"\n[-] Anggota berhasil di hapus";
            delete P;
        } else {
            cout<<"\n[!] Anggota tidak ditemukan";
        }
    }else{
        cout<<"\n[!] Anggota kosong";
    }
    getch();
}
void TampilOrmawaDanAnggotanya(multiList L){
    address_ormawa P = first_ormawa(L);
    if (P!=NIL) {
        cout<<endl;
        while (P != NIL) {
            cout << "Ormawa : " << infoM(P) << "\n";
            cout << "  [*] Anggota : ";
            address_relasi R = rel(P);
            if (R != NIL) {
                while (R != NIL) {
                    address_anggota D = link(R);
                    if (D != NIL) {
                        cout << infoD(D) << ", ";
                    }
                    R = nextR(R);
                }
            } else {
                cout << "Tidak ada.";
            }
            cout<<"\n--------------------------------------------------\n";
            P = nextM(P);
        }
    }else{
        cout<<"\n[!] Tidak ada Ormawa yang tersedia";
    }
}

void tampilSemuaOrmawa(multiList L){
    address_ormawa M = first_ormawa(L);
    int i = 0;
    if (M!=NIL){
        cout<<"\nOrmawa yang terdaftar :\n";
        do{
            i += 1;
            cout<<i<<". "<<infoM(M)<<endl;
            M = nextM(M);
        }while (M!=NIL);
        cout<<endl;
    }
}
void tampilSemuaAnggota(multiList L){
    address_anggota D = first_anggota(L);
    int i = 0;
    if (D!=NIL){
        cout<<"\nAnggota yang terdaftar :\n";
        do{
            i += 1;
            cout<<i<<". "<<infoD(D)<<endl;
            D = nextD(D);
        }while (D!=NIL);
        cout<<endl;
    }
}

void menuHapusRelasi(multiList &L){
    string Title = "+------------- HAPUS RELASI -------------+\n\n";
    address_ormawa P = first_ormawa(L);
    address_anggota Q = first_anggota(L);
    address_relasi R;
    bool valid;
    if (P==NIL || Q==NIL){
        if (P!=NIL && Q==NIL){
            cout<<"\n[!] Tidak ada Anggota yang tersedia";
        }else if (P==NIL && Q!=NIL){
            cout<<"\n[!] Tidak ada Ormawa yang tersedia";
        }else{
            cout<<"\n[!] Anggota dan Ormawa tidak tersedia";
        }
    }else{
        infotype input;
        do{
            do{
                system("CLS");
                cout<<Title;
                tampilSemuaOrmawa(L);
                cout<<"Masukkan nama Ormawa ('cancel' untuk kembali): "; cin>>input;
                P = searchOrmawa(input,L);
                if (input == "cancel" || P != NIL){
                    R = rel(P);
                    valid = true;
                    if (input!="cancel"&&R==NIL){
                        cout<<"\n\n[!] Ormawa ini tidak memiliki relasi dengan semua Anggota\n";
                        do{
                            cout<<"\nTambah relasi? (Y/N) : "; cin>>input;
                        }while (input!="Y"&&input!="y"&&input!="N"&&input!="n");
                        if (input=="Y"||input=="y"){
                            addRelasi(L);
                        }
                        valid = false;
                    }
                }else{
                    cout<<"[!] Ormawa tidak tersedia\n";
                }
            }while (!valid);
            if (input!="cancel"){
                valid = false;
                do{
                    system("CLS");
                    cout<<Title;
                    cout<<"Daftar Anggota beserta Ormawanya "<<infoM(P)<<" : \n";
                    int i = 1;
                    while (R!=NIL){
                        cout<<i<<". "<<infoD(link(R))<<"\n";
                        i++;
                        R = nextR(R);
                    }
                    cout<<"\nMasukkan nama Anggota ('cancel' untuk kembali): "; cin>>input;
                    Q  = searchAnggota(input,L);
                    if (input == "cancel" || Q != NIL){
                        valid = true;
                    }else{
                        cout<<"[!] Anggota tidak tersedia\n";
                    }
                }while (!valid);
                if (input!="cancel"){
                    if (cekRelasi(P,Q)){
                        HapusRelasi(P,Q);
                        cout<<"\n[-] Relasi berhasil di hapus";
                        cout<<"\n\nHapus lagi? (Y/N) : "; cin>>input;
                    }else{
                        cout<<"\n[!] Anggota tidak ditemukan\n";
                        cout<<"\nInput Ulang ? (Y/N) : "; cin>>input;
                    }
                }
            }
        }while (input=="Y" || input == "y");
    }
    cout<<"\n\nEnter untuk kembali...";
    getch();
}
