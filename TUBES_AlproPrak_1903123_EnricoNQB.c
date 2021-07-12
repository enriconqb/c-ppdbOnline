#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
Nama    : Enrico Nabil Qois B
NIM     : 1903123
Tanggal : 31 Maret 2020

*/

//==============================================
void cls(){system("cls");} //untuk clear screen
void pause(){system("pause");} //untuk system pause
//==============================================

//[Struct]
//alamat element 
typedef struct elmt *alamatelmt; // (Enrico Nabil Qois)

//Isi element 
typedef struct elmt{ //(Enrico Nabil Qois)
	//pendeklarasian Variabel dengan tipe data masing-masing 
    int no_murid;
    char nama[50];//varibel dengan menggunakan [Array] 
    char nisn[50];
    char jk[50];
    char ttl[50];
    char almt[50];
    char agama[50];
    char ortu[50];
    char asal[50];
    float mtk,ipa,ing,indo,un;
    char jurus[50];
    alamatelmt prev;
    alamatelmt next;
}node;

//Struct awal //(Enrico Nabil Qois)
typedef struct{
    node *first;
    node *tail;
}list;

//Buat list //(Enrico Nabil Qois)
void createList(list *L){
    (*L).first = NULL;
    (*L).tail = NULL;
}

//Buat nambah data diawal (Lisa)
void addFirst(int no_murid, char nama[],char nisn[],char jk[],char ttl[],char almt[],char agama[],char ortu[],char asal[],float mtk,float ipa,float ing, float indo, float un,char jurus[],list *L){ //(Lisa Amri M)
    node *new = (node*)malloc(sizeof(node)); //Mengalokasikan alamat untuk membuat elemen baru
    new->no_murid = no_murid; 
    strcpy(new->agama,agama);
    strcpy(new->asal,asal);
    strcpy(new->jk,jk);
    strcpy(new->nama,nama);
    strcpy(new->nisn,nisn);
    strcpy(new->ortu,ortu);
    strcpy(new->ttl,ttl);
    strcpy(new->almt,almt);
    new->indo = indo;
    new->ing = ing;
    new->ipa = ipa;
    new->mtk = mtk;
    new->un = un;
    strcpy(new->jurus,jurus);
    
    if ((*L).first == NULL){
        new->next = NULL;
        (*L).tail = new;
    }
    else{
        new->next = (*L).first;
    }
    new->prev = NULL;
    (*L).first = new;
    new = NULL;
}

//Buat nambah setelah data didepannya (Enrico)
void addAfter(node *before, int no_murid, char nama[],char nisn[],char jk[],char ttl[],char almt[],char agama[],char ortu[],char asal[],float mtk,float ipa,float ing, float indo, float un,char jurus[],list *L){//(Enrico Nabil Qois)
    if (before != NULL){ //Jika sudah ada data disebelumnya atau tidak sama dengan NULL
        node *new = (node*)malloc(sizeof(node));//mengalokasikan alamat untuk membuat elemen baru
        new->no_murid = no_murid;
        strcpy(new->agama,agama);
        strcpy(new->asal,asal);
        strcpy(new->jk,jk);
        strcpy(new->nama,nama);
        strcpy(new->nisn,nisn);
        strcpy(new->ortu,ortu);
        strcpy(new->ttl,ttl);
        strcpy(new->almt,almt);
        new->indo = indo;
        new->ing = ing;
        new->ipa = ipa;
        new->mtk = mtk;
        new->un = un;
        strcpy(new->jurus,jurus);

        if(before->next == NULL){
            new->next = NULL;
            (*L).tail = new;
        }
        else{
            new->next = before->next;
            new->next->prev = new;
        }
        new->prev = before;
        before->next = new;
        new = NULL;
    }
}

//Prosedur Buat head dari program
void judul(){// 
    printf("/=========================================\\ \n");
    printf("|       PPDB Online SMKN 1 BANDUNG        |\n");
    printf("\\=========================================/\n");
}

//Prosedur Buat mencetak data dari inputan cari [Searching]
void printcari(int no_murid, list L){//(Enrico Nabil Qois)
    node *help = L.first;
    while(help != NULL){//[Perulangan] 
        if (help->no_murid == no_murid){//percabangan jika no_murid yang dicari sama dengan no_murid yang sudah ada maka tercetak data detail seperti dibawah
            printf("Nama             : %s\n",help->nama);
            printf("NISN             : %s\n",help->nisn);
            printf("Jenis Kelamin    : %s\n",help->jk);
            printf("TTL              : %s\n",help->ttl);
            printf("Alamat           : %s\n",help->almt);
            printf("Agama            : %s\n",help->agama);
            printf("Nama Orang Tua   : %s\n",help->ortu);
            printf("Asal Sekolah     : %s\n",help->asal);
            printf("=========================================\n");
            printf("Matematika       : %.2f\n",help->mtk);
            printf("IPA              : %.2f\n",help->ipa);
            printf("Bahasa Inggris   : %.2f\n",help->ing);
            printf("Bahasa Indonesia : %.2f\n",help->indo);
            printf("Rata-Rata UN     : %.2f\n",help->un); 
            printf("=========================================\n");
            printf("Jurusan Pilihan  : %s\n",help->jurus);
        }
        help = help->next;
    }
}

//prosedur untuk mencetak data 
void print(list L){// 
    if (L.first != NULL){//percabangan jika list tidak kosong atau tidak NULL
        node *help = L.first;
        printf("| No - UN - Jurusan - Nama \n");
        while(help!=NULL){//perulangan untuk mencetak data
            printf("| %d | %.2f | %s | %s\n",help->no_murid,help->un,help->jurus,help->nama);
            help = help->next;
        }
    }
    else{//jika tidak terpenuhi(list kosong)
        printf("List Kosong\n");
    }
}

//prosedur [Sorting] quicksort descending
void deQuickSort (int arr[], int lo, int hi){//(Enrico Nabil Qois)
//  lo adalah index bawah, hi adalah index atas 
//  dari bagian array yang akan di urutkan 
    int i=lo, j=hi, h; 
    int pivot=arr[lo]; 
 
//  pembagian 
    do{ 
        while (arr[i]>pivot) i++; 
        while (arr[j]<pivot) j--; 
        if (i<=j) 
        { 
            h=arr[i];
            arr[i]=arr[j]; 
            arr[j]=h;//tukar 
            i++; j--; 
        } 
    } while (i<=j); 
 
//  pengurutan (dengan cara [Rekursif])
    if (lo<j) deQuickSort(arr, lo, j); 
    if (i<hi) deQuickSort(arr, i, hi); 
}

int main(){
	//(Enrico Nabil Qois)
    //Deklarasi Variabel
        int pil,i;
        //key password asli
            char pass[20], user[20];
        //key password input
            char in_pass[20], in_user[20], confirm[20];
        //format
            char nama[50], nisn[50], jk[50], ttl[50], almt[50], agama[50], ortu[50], asal[50],jurus[50];
            float mtk,ipa,ing,indo,un;
        //variabel bantu
            int no_murid = 1;
            int search_no;
        //variabel tampung
            float rank_un[40];
	//(Enrico Nabil Qois)
    //Deklarasi List
    list L;
    createList(&L);

    while(true){
        cls();//Tampilan Sebelum login
        judul();//pemanggilan prosedur judul
        printf("[1] Login\n");//isi menu dari tampilan awal program
        printf("[2] Buat akun\n");//
        printf("[0] Exit\n");//
        printf("Pilihan: ");scanf("%d",&pil);//inputan user untuk memilih menu
        //(Enrico Nabil Qois)
        if (pil==1){//percabangan jika memilih 1(LOGIN)
            while (true){//perulangan 
                cls();//Tampilan Pilihan 1 Sebelum Login
                printf("/=========================================\\ \n");
                printf("|             Login PPDB Online           |\n");
                printf("\\=========================================/\n");
                printf("Selamat datang di laman web PPDB online SMKN 1 BANDUNG\n");
                printf("Masukan Username: ");scanf("%s",&in_user);//input memasukan username 
                printf("Masukan Password: ");scanf("%s",&in_pass);//input memasukan password
                if (strcmp(in_user,user)==0 && strcmp(in_pass,pass)==0){//percabangan pencocokan username dan pasword yang diinput dengan yang ada di list(data)
                    printf("Login Berhasil\n");
                    pause();
                    //=====================================================
                    while(true){//perulangan
                        cls();
                        judul();//pemanggilan prosedur judul
                        printf("Selamat datang %s di laman web PPDB online SMKN 1 BANDUNG\n",user);//tampilan menu ketika berhasil LOGIN
                        printf("[1] Pendaftaran calon siswa baru\n");//
                        printf("[2] Lihat data calon siswa baru\n");//
                        printf("[3] Ranking Rerata Nilai UN\n");//
                        printf("[0] LogOut\n");//
                        printf("Pilihan: ");scanf("%d",&pil);//input user menu
                        if (pil==1){//percabangan jika user pilih 1(PENDAFTARAN)
                            while(true){//perulangan
                                cls();
                                judul();//prosedur judul
                                printf("Silahkan isi data dibawah ini:\n");//menu pilihan pendaftran
                                printf("[1] Data diri calon siswa baru\n");
                                printf("[0] Exit\n");
                                printf("Pilihan: ");scanf("%d",&pil);//input user menu
                                if (pil==1){//percabangan jika user pilih 1(MENGISI DATA DIRI)
                                    cls();//prosedur cls
                                    judul();//prosedur judul
                                    //input user tentang data diri seperti dibawah
                                    printf("Data Siswa ke-%d\n",no_murid);
                                    printf("Nama          : ");scanf("%s",&nama);
                                    printf("NISN          : ");scanf("%s",&nisn);
                                    printf("Jenis Kelamin : ");scanf("%s",&jk);
                                    printf("TTL           : ");scanf("%s",&ttl);
                                    printf("Alamat        : ");scanf("%s",&almt);
                                    printf("Agama         : ");scanf("%s",&agama);
                                    printf("Nama Orang Tua: ");scanf("%s",&ortu);
                                    printf("Asal Sekolah  : ");scanf("%s",&asal);

                                    cls();
                                    judul();
                                    //input user tentang nilai
                                    printf("Nilai Siswa ke-%d\n",no_murid);
                                    printf("Matematika       : ");scanf("%f",&mtk);
                                    printf("IPA              : ");scanf("%f",&ipa);
                                    printf("Bahasa Inggris   : ");scanf("%f",&ing);
                                    printf("Bahasa Indonesia : ");scanf("%f",&indo);
                                    un = (mtk+ipa+ing+indo)/4;//operasi aritmatika
                                    printf("Rata-Rata UN     : %.2f\n",un);//output dari operasi aritmatika
                                    printf("======================================\n");
                                    printf("Pilih Jurusan: \n");//pemilihan jurusan
                                    printf("[1] Tekhnik Komputer Jaringan(TKJ)\n");
                                    printf("[2] Rekayasa Perangakat Lunak(RPL)\n");
                                    printf("[3] Multimedia\n");
                                    printf("[4] Tekhnik Kendaraan Ringan(TKR)\n");
                                    printf("Pilihan: ");scanf("%d",&pil);//input user pilihan
                                    if (L.first == NULL){//jika list kosong
                                    //maka semua data baik pilihan jurusan apapun dimasukan dengan menggunakan prosedur addFirst
                                        if (pil==1){
                                            addFirst(no_murid,nama,nisn,jk,ttl,almt,agama,ortu,asal,mtk,ipa,ing,indo,un,"Tekhnik Komputer Jaringan(TKJ)",&L);
                                        }
                                        else if (pil==2){
                                            addFirst(no_murid,nama,nisn,jk,ttl,almt,agama,ortu,asal,mtk,ipa,ing,indo,un,"Rekayasa Perangakat Lunak(RPL)",&L);
                                        }
                                        else if (pil==3){
                                            addFirst(no_murid,nama,nisn,jk,ttl,almt,agama,ortu,asal,mtk,ipa,ing,indo,un,"Multimedia",&L);
                                        }
                                        else if (pil==4){
                                            addFirst(no_murid,nama,nisn,jk,ttl,almt,agama,ortu,asal,mtk,ipa,ing,indo,un,"Tekhnik Kendaraan Ringan(TKR)",&L);
                                        }
                                        else{
                                            printf("Pilihan tidak ada\n\n");
                                            pause();
                                            continue;
                                        }
                                    }
                                    else{//jika tidak memenuhi(LIST TIDAK KOSONG)
                                    //maka semua data dengan jurusan apapun dimasukan dengan menggunakan prosedur addAdfter
                                        if (pil==1){
                                            addAfter(L.tail,no_murid,nama,nisn,jk,ttl,almt,agama,ortu,asal,mtk,ipa,ing,indo,un,"Tekhnik Komputer Jaringan(TKJ)",&L);
                                        }
                                        else if (pil==2){
                                            addAfter(L.tail,no_murid,nama,nisn,jk,ttl,almt,agama,ortu,asal,mtk,ipa,ing,indo,un,"Rekayasa Perangakat Lunak(RPL)",&L);
                                        }
                                        else if (pil==3){
                                            addAfter(L.tail,no_murid,nama,nisn,jk,ttl,almt,agama,ortu,asal,mtk,ipa,ing,indo,un,"Multimedia",&L);
                                        }
                                        else if (pil==4){
                                            addAfter(L.tail,no_murid,nama,nisn,jk,ttl,almt,agama,ortu,asal,mtk,ipa,ing,indo,un,"Tekhnik Kendaraan Ringan(TKR)",&L);
                                        }
                                        else{//jika memilih jurusan selain yang ada di menu
                                            printf("Pilihan tidak ada");
                                            pause();
                                            continue;
                                        }
                                    }
                                    printf("Terima Kasih Telah mengisi formulir pendaftaran\n");
                                    no_murid+=1;//no_murid bertambah 1
                                    pause();
                                }
                                else if (pil==0){//jika pilihan 0
                                    break;//berhenti
                                }
                                else{//selain memilih yang ada di menu
                                    printf("Pilihan tidak ada!\n");
                                    pause();
                                }
                            }
                        }
                        else if (pil==2){//jika memilih 2 (LIHAT DATA SISWA)
                            cls();
                            judul();
                            print(L);//pemanggilan prosedur print dengan parameter L(Output data siswa yang sudah ada)
                            if(L.first == NULL){//percabangan jika list kosong(NULL)
                                pause();
                                continue;
                            }//jika list tidak kosong(NOT NULL)
                            printf("Mencari detail calon siswa?\n");//output apakah user ingin melihat data siswa lebih detail
                            printf("[1] Ya | [2] Tidak\n");
                            printf("Pilihan: ");scanf("%d",&pil);//input user
                            if (pil==1){//percabangan jika memilih 1 (IYA)
                                cls();
                                judul();
                                print(L);//pemanggilan prosedur printd dengan parameter L
                                printf("Masukan no calon siswa: ");scanf("%d",&search_no);//input user 
                                printcari(search_no, L);//pemanggilan prosedur printcari dengan parameter (search_no,L)
                                pause();
                            }   
                            else if (pil==2){//jika memilih 2(TIDAK)
                                continue;//continue
                            }   
                            else{//jika meilih selain 1 dan 2(YANG ADA DIMENU_)
                                printf("Pilihan tidak ada!\n");
                                pause();
                                continue;
                            }                 
                        }
                        else if (pil==3){//jika memilih 3(RANKING NEM SISWA)
                            cls();
                            judul();//pemanggilan prosedur judul
                            printf("=== Ranking Rerata Nilai UN ===\n");
                            if(L.first==NULL){//jika list kosong/NULL(data kosng)
                                printf("Belum ada yang mendaftar!\n");
                                pause();
                                continue;
                            }//jika list tidak kosong
                            int n = 0;//pendeklarasian variabel n dengan awal nilai 0
                            node *help=L.first;
                            while (help!=NULL){//perulangan jika data tidak kosong
                                rank_un[n] = help->un;
                                help = help->next;
                                n+=1;//n bertambah 1
                            }
                            deQuickSort(rank_un,0,n-1);//pemanggilan prosedur deQuickSort
                            printf("+----+-----------------+\n");
                            printf("| No | Nilai Rerata UN |\n");
                            for (i=0;i<n;i++){//perulangan untuk mencetak ranking UN siswa
                                printf("| %d  | %.2f \n",i+1,rank_un[i]);
                            }
                            printf("+----+-----------------+\n");
                            pause();
                        }
                        else if (pil==0){//jika pilihan 0
                            printf("Anda Logout!\n");
                            pause();
                            break;
                        }
                        else{//jika pilihan selain yang ada dimenu
                            printf("Pilihan tidak ada\n");
                            pause();
                        }
                    }
                }
                else{//jika username dan password tidak cocok dengan yang ada di list
                    printf("Maaf username atau password salah!\n");
                    printf("Ulangi? [1] YA  | [2] TIDAK\n");
                    printf("Pilihan: ");scanf("%d",&pil);///input user
                    if(pil==1) continue; //perbandingan jika pilihan 1 maka continue
                    else if(pil==2) break;//jika tidk makan break
                    else{//jika memilih selian 1 dan 2 yang ada dimenu
                        printf("Pilihan tidak ada!\n");
                        break;
                    }
                }
            }
        }
        // 
        else if (pil==2){//jika memilih 2(BUAT AKUN)
            cls();
            printf("/=========================================\\ \n");
            printf("|	      Daftar Akun PPDB Online		  |\n");
            printf("\\=========================================/\n");
            printf("Selamat datang di laman web PPDB online SMKN 1 BANDUNG\n");
            printf("Username        : ");scanf("%s",&user);//input username
            printf("Password        : ");scanf("%s",&pass);//inut pasword
            printf("Confirm Password: ");scanf("%s",&confirm);//input konfirmasi pasword
            if(strcmp(pass,confirm)!=0){//perbandingan jika pasword yang di input tidak sama dengan konfirmasi password yang diinout user
                printf("Password confirm salah. Mohon diulangi\n");
                strcpy(user," ");//mengkosongkan agar yang diinput user tdi tidak masuk list
                strcpy(pass," ");//mengkosongkan agar yang diinput user tdi tidak masuk list
                pause();
            }
            else {//jika password dengan konfirmasi password sama 
                printf("Akun berhasil dibuat!\n");
                pause();
            }
        }
        else if (pil==0){//jika pilihan 0
            printf("Terima Kasih!\n");
            pause();
            break;
        }
        else{//jika pilihan tidak ada yang dimenu
            printf("Pilihan tidak ada!\n");
            pause();
        }
    }
    return 0;//mengembalikan nilai 0
}
