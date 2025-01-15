/*
Irfan Yusuf Khaerullah (2206813290)
Mario Matthews Gunawan (2206810452)
Proyek Akhir Semester
Program = E-commerce Apps
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<omp.h>
#include"function.h"

int main(){
    seller sell;
    buyer buy;
    Node* head = NULL;
    int menu = 0, i, pil, accS = 0, accB = 0;
    int counter = 0;
    int *ptri = &counter;

    system("color 87");
    intro();
    system("cls");

    while(menu != 3){
        printf("===============================================\n"
            "|                   UI SHOP                   |\n"
            "===============================================\n"
            "|                 MENU UTAMA                  |\n"
            "==============================================="
            "\n1. Buat akun"
            "\n2. Log in akun"
            "\n3. Keluar Program"
        );
        do{
            printf("\nPilihan : ");
            scanf("%d", &menu);
            switch(menu){
                case 1:
                    do{
                        system("cls");
                        printf("===============================================\n"
                            "|                   UI SHOP                   |\n"
                            "===============================================\n"
                            "|                  BUAT AKUN                  |\n"
                            "===============================================\n"
                            "1. Akun Penjual\n"
                            "2. Akun Pembeli\n"
                            "3. Kembali Ke Menu\n"
                            "Note : Hanya dapat membuat 1 akun penjual & pembeli.\n\n"
                            "Pilihan : "
                        );
                        scanf("%d", &pil);
                        #pragma omp parallel num_threads(2)
                        {
                            #pragma omp sections
                            {
                                #pragma omp section
                                {
                                    if(pil == 1 && accS != 1){
                                        buatAkun(&sell, &buy, pil, &head, ptri);
                                        accS = 1;
                                    }
                                    else if((pil == 1 && accS == 1)){
                                        printf("\nAkun sudah dibuat sebelumnya!\n");
                                        Sleep(1000);
                                    }
                                }
                                #pragma omp section
                                {
                                    if(pil == 2 && accB != 1){
                                        buatAkun(&sell, &buy, pil, &head, ptri);
                                        accB = 1;
                                    }
                                    else if((pil == 2 && accB == 1)){
                                        printf("\nAkun sudah dibuat sebelumnya!\n");
                                        Sleep(1000);
                                    }
                                }
                            }
                        }
                        if(pil == 3){
                            break;
						}
                        else if(pil != 1 && pil != 2 && pil != 3){
                            system("color 40");
                            printf("Masukkan angka 1 2 atau 3!");
                            Beep(650,500);
                            Sleep(500);
                            system("color 87");
                            system("cls");
                        }
                    }while(pil != 1 && pil != 2);
                    system("cls");
                    break;
                case 2:
                    do{
                        system("cls");
                        printf("===============================================\n"
                            "|                   UI SHOP                   |\n"
                            "===============================================\n"
                            "|                 LOG IN AKUN                 |\n"
                            "===============================================\n"
                            "1. Akun Penjual\n"
                            "2. Akun Pembeli\n"
							"3. Kembali Ke menu\n"
                            "Pilihan : "
                        );
                        scanf("%d", &pil);
                        #pragma omp parallel num_threads(2)
                        {
                            #pragma omp sections
                            {
                                #pragma omp section
                                {
                                    if(pil == 1 && accS == 1){
                                        login(&sell, &buy, pil, &head, ptri);
                                    }
                                }
                                #pragma omp section
                                {
                                    if(pil == 2 && accB == 1){
                                        login(&sell, &buy, pil, &head, ptri);
                                    }
                                }
                            }
                        }
                        if(pil == 3){
                            break;
						}
                        else if(pil != 1 && pil != 2 && pil != 3){
                            system("color 40");
                            printf("Anda belum membuat akun atau anda salah memasukkan angka");
                            Beep(650,500);
                            Sleep(500);
                            system("color 87");
                            system("cls");
                        }
                    }while(pil != 1 && pil != 2);
                    system("cls");
                    break;
                case 3:
                    system("cls");
                    deleteList(&head);
                    outro();
                    break;
                default:
                    system("color 40");
                    printf("Masukkan angka 1, 2, atau 3!");
                    Beep(650,500);
                    Sleep(500);
                    system("color 87");
                    system("cls");
                    menu = 1;
                    break;
            }
        }while(menu != 1 && menu != 2 && menu != 3);
    }
    remove("penjual.txt");
    remove("pembeli.txt");
    return 0;
}
