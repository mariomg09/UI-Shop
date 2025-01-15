typedef struct Penjual{
    char nama[100];
    char userN[100];
    char pass[100];
}seller;

typedef struct Pembeli{
    char nama[100];
    char userN[100];
    char pass[100];
}buyer;

typedef struct Produk{
    char namaproduk[100];
    int hargaproduk;
    int stock;
    int dibeli;
}product;

typedef struct Node{
    product data;
    struct Node* next;
}Node;

void insert(Node** head, product data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    }
    else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void display(Node* head) {
    Node* current = head;
    int count = 1;

    if (current == NULL) {
        system("cls");
        printf("Tidak ada produk yang tersedia!");
        return;
    }   
    system("cls");
    printf("===============================================\n"
        "|                   UI SHOP                   |\n"
        "===============================================\n"
        "|                DAFTAR PRODUK                |\n"
        "===============================================\n"
        "No.\tNama Produk\t\tHarga\tStock\n"
    );
    
    while (current != NULL) {
        printf("%d.\t%s\t\t%d\t%d\n", count, current->data.namaproduk, current->data.hargaproduk, current->data.stock);
        current = current->next;
        count++;
    }
}

void deleteList(Node** head) {
    Node* current = *head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

void intro(){
    int i;
    system("cls");
    printf("===============================================\n"
        "|                   UI SHOP                   |\n"
        "===============================================");
    printf("\nTekan Enter untuk memulai program! ");
    getchar();
    system("cls");
	char a[]= { "===============================================\n"
			"|------------- Selamat Datang Di -------------|\n"
			"|------------------ UI SHOP ------------------|\n"
			"|----------- Pemrograman Lanjut 01 -----------|\n"
			"===============================================\n"
            "|    1. Irfan Yusuf Khaerullah (2206813290)   |\n"
            "|    2. Mario Matthews Gunawan (2206810452)   |\n"
            "===============================================\n"};
	for(i=0;a[i]!=a[385];i++){ 
		printf("%c",a[i]); 
		Sleep(5); 
	}
    Sleep(2000);
    system("cls");
    printf("\n\n\t\t  Loading . . .\n\n");
    Beep(659,500);
    Sleep(1000);
    char b=219;
    system("color 87");
    printf(" ");
	for(i=0;i<14;i++){ // looping untuk print array text
        printf("%c", b);
        Sleep(45); 
	}
	for(i=0;i<10;i++){ // looping untuk print array text
        printf("%c", b);
        Sleep(90); 
	}
	for(i=0;i<23;i++){ // looping untuk print array text
        printf("%c", b);
        Sleep(30); 
	}
}

void buatAkun(seller* sell, buyer* buy, int x, Node** head, int* ptri){
	FILE* fptr;
    if(x==1){
        system("cls");
        printf("===============================================\n"
            "|                   UI SHOP                   |\n"
            "===============================================\n"
            "|                  BUAT AKUN                  |\n"
            "===============================================\n");
        printf("Masukkan nama Anda : ");
        scanf(" %[^\n]s", sell->nama);
        printf("Masukkan username  : ");
        scanf("%s", sell->userN);
        printf("Masukkan password  : ");
        scanf("%s", sell->pass);
        
        fptr = fopen("penjual.txt", "w");
        if (fptr != NULL) {
            fprintf(fptr, "%s %s\n", sell->userN, sell->pass);
            fclose(fptr);
            system("cls");
            printf("Selamat datang %s!", sell->nama);
            Sleep(1500);
            menuPenjual(head,ptri);
        }
        else{
            printf("Account gagal dibuat");
        }
        fclose(fptr);
    }
    else if(x == 2){
        system("cls");
        printf("===============================================\n"
            "|                   UI SHOP                   |\n"
            "===============================================\n"
            "|                  BUAT AKUN                  |\n"
            "===============================================\n");
        printf("Masukkan nama Anda : ");
        scanf(" %[^\n]s", buy->nama);
        printf("Masukkan username  : ");
        scanf("%s", buy->userN);
        printf("Masukkan password  : ");
        scanf("%s", buy->pass);

        fptr = fopen("pembeli.txt", "w");
        if (fptr != NULL) {
            fprintf(fptr, "%s %s\n", buy->userN, buy->pass);
            fclose(fptr);
            system("cls");
            printf("Selamat datang %s!", buy->nama);
            Sleep(1500);
            menuPembeli(head,ptri);
        }
        else{
            printf("Account gagal dibuat");
        }
        fclose(fptr);
    }
}

void login(seller* sell, buyer* buy, int x, Node** head, int* ptri){
    FILE *fptr;
    system("cls");
    printf("===============================================\n"
        "|                   UI SHOP                   |\n"
        "===============================================\n"
        "|                   LOG IN                    |\n"
        "===============================================");
    if(x==1){
        printf("\nMasukkan username : ");
        scanf("%s", sell->userN);
        printf("Masukkan password : ");
        scanf("%s", sell->pass);

        fptr = fopen("penjual.txt", "r");
        char sellUser[100];
        char sellPass[100];
        if (fptr == NULL) {
            printf("Account tidak ada!\n");
            Sleep(1500);
        }
        else{
            fscanf(fptr, "%s %s", sellUser, sellPass);
            if(strcmp(sell->userN, sellUser) != 0){
                printf("\nUsername atau Password salah!");
                Sleep(1500);
            }
            if(strcmp(sell->userN, sellUser) == 0){
                if (strcmp(sell->pass, sellPass) == 0) {
                    system("cls");
                    printf("Selamat datang %s!", sell->nama);
                    Sleep(1500);
                    menuPenjual(head,ptri);
                } 
                else {
                    printf("\nUsername atau Password salah!\n");
                    Sleep(1500);
                }
            }
        }
        fclose(fptr);
    }
    else if(x==2){
        printf("\nMasukkan username : ");
        scanf("%s", buy->userN);
        printf("Masukkan password : ");
        scanf("%s", buy->pass);

        fptr = fopen("pembeli.txt", "r");
        char buyUser[100];
        char buyPass[100];
        if (fptr == NULL) {
            printf("Account tidak ada!\n");
            Sleep(1500);
        }
        else{
            fscanf(fptr, "%s %s", buyUser, buyPass);
            if(strcmp(buy->userN, buyUser) != 0){
                printf("\nUsername atau Password salah!");
                Sleep(1500);
            }
            if(strcmp(buy->userN, buyUser) == 0){
                if (strcmp(buy->pass, buyPass) == 0) {
                    system("cls");
                    printf("Selamat datang %s!", buy->nama);
                    Sleep(1500);
                    menuPembeli(head,ptri);
                }
                else {
                    printf("\nUsername atau Password salah!\n");
                    Sleep(1500);
                }
            }
        }
        fclose(fptr);
    }
}

void sorting(Node** head, int* ptri) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    int swapped;
    Node* curr;
    Node* tail = NULL;

    do{
        swapped = 0;
        curr = *head;
        #pragma omp parallel
        {
            #pragma omp single nowait
            while (curr->next != tail){
                if (curr->data.hargaproduk > curr->next->data.hargaproduk){
                    product temp = curr->data;
                    curr->data = curr->next->data;
                    curr->next->data = temp;
                    swapped = 1;
                }
                curr = curr->next;
            }
        }
        tail = curr;
    }while (swapped);
	
	system("cls");
    printf("Produk berhasil diurutkan berdasarkan harga.\n");
    display(*head);
}

void menuPenjual(Node** head,int* ptri){
    int menu;
    product data;
    
    do{
        system("cls");
        printf("===============================================\n"
            "|                   UI SHOP                   |\n"
            "===============================================\n"
            "|                 MENU PENJUAL                 |\n"
            "===============================================\n"
            "1. Tambah Produk\n"
            "2. Hapus Produk\n"
            "3. Produk Terjual\n"
            "4. Log out\n"
            "Pilih menu : ");
        scanf("%d", &menu);
        switch(menu){
            case 1:
                system("cls");
                tambahProduk(head);
                break;
                
            case 2:
                system("cls");
                hapusProduk(head,ptri);
                break;
                
            case 3:
                system("cls");
                produkTerjual(head,ptri);
                Sleep(4000);
                break;
            case 4:
                system("cls");
                printf("Anda berhasil logout!");
                Sleep(1000);
                break;			     
            default:
                printf("\nMasukkan angka 1 2 3 atau 4!\n");
                Sleep(1000);
                system("cls");
                break;
        }
    }while(menu != 4);
}

void tambahProduk(Node** head){
    product data;
    system("cls");
    printf("===============================================\n"
        "|                   UI SHOP                   |\n"
        "===============================================\n"
        "|                TAMBAH PRODUK                |\n"
        "===============================================\n");
    printf("Masukkan nama produk     : ");
    scanf(" %[^\n]s", data.namaproduk);
    printf("Masukkan harga produk    : ");
    scanf("%d", &data.hargaproduk);
    printf("Masukkan stock produk    : ");
    scanf("%d", &data.stock);
    data.dibeli = 0;
    insert(head, data);
    printf("Produk berhasil ditambahkan!\n");
    Sleep(1000);
    system("cls");
}

void hapusProduk(Node** head, int *ptri){
    char namaproduk[100];
    Node* current = *head;
    Node* prev = NULL;
    int found=0;
	
	system("cls");
    printf("===============================================\n"
        "|                   UI SHOP                   |\n"
        "===============================================\n"
        "|                 HAPUS PRODUK                |\n"
        "===============================================\n");
    sorting(head,ptri);
    display(*head);
    printf("Masukkan nama produk yang ingin dihapus : ");
    scanf(" %[^\n]s", namaproduk);
    if(current == NULL){
        printf("\nTidak ada produk yang tersedia!\n");
        Sleep(1000);
        system("cls");
        return;
    }
    if(strcmp(current->data.namaproduk, namaproduk) == 0){
        *head = current->next;
        free(current);
        printf("\nProduk berhasil dihapus!\n");
        Sleep(1000);
        system("cls");
        return;
    }
    while(current != NULL){
        if(strcmp(current->data.namaproduk, namaproduk) == 0){
            found = 1;
            break;
        }
        prev = current;
        current = current->next;
    }
    if(found == 1){
        prev->next = current->next;
        free(current);
        printf("\nProduk berhasil dihapus!\n");
        Sleep(1000);
        system("cls");
    }
    else{
        printf("\nProduk tidak ditemukan!\n");
        Sleep(1000);
        system("cls");
    }
}

void produkTerjual(Node** head, int *ptri){
    Node* current = *head;
    int count = 1;
    int totalTerjual = 0;

    if (current == NULL) {
        system("cls");
        printf("Tidak ada produk yang tersedia!\n");
        return;
    }

    system("cls");
    printf("===============================================\n"
        "|                   UI SHOP                   |\n"
        "===============================================\n"
        "|                PRODUK TERJUAL               |\n"
        "===============================================\n");
    printf("No.\tNama Produk\t\tHarga\tStock\tTerjual\n");

    while (current != NULL) {
        printf("%d.\t%s\t\t%d\t%d\t%d\n", count, current->data.namaproduk, current->data.hargaproduk, current->data.stock, current->data.dibeli);
        totalTerjual += current->data.dibeli;
        current = current->next;
        count++;
    }

    printf("\nTotal Produk Terjual: %d\n", totalTerjual);
}

void menuPembeli(Node** head, int* ptri){
    int menu;
    system("cls");
    do{
        printf("===============================================\n"
            "|                   UI SHOP                   |\n"
            "===============================================\n"
            "|                 MENU PEMBELI                |\n"
            "===============================================\n"
            "1. Lihat Daftar Produk\n"
            "2. Beli Produk\n"
            "3. Cari Produk\n"
            "4. Log out\n"
            "Pilih menu : ");
        scanf("%d", &menu);
        switch(menu){
            case 1:
                sorting(head, ptri);
                display(*head);
                Sleep(2000);
                system("cls");
                break;
            case 2:
                beliProduk(head, ptri);
                break;
            case 3:
                system("cls");
				search(head);
				Sleep(3000);
				system("cls");
				break;  
			case 4:
				system("cls");
                printf("Anda berhasil logout!");
                Sleep(1000);
                break;
            default:
                system("color 40");
                Beep(650,500);
                printf("Masukkan angka 1 2 atau 3!\n");
                Sleep(500);
                system("color 87");
                system("cls");
                break;
        }
        
    }while(menu != 4);
}

void beliProduk(Node** head, int* ptri){
    char namaproduk[100];
    int jumlah;
    Node* current = *head;
    Node* prev = NULL;
    int found = 0;
	
	system("cls");
    printf("===============================================\n"
        "|                   UI SHOP                   |\n"
        "===============================================\n"
        "|                 BELI PRODUK                 |\n"
        "===============================================");
    sorting(head,ptri);
    display(*head);
    printf("Masukkan nama produk yang ingin dibeli : ");
    scanf(" %[^\n]s", namaproduk);
    printf("Masukkan jumlah produk : ");
    scanf("%d", &jumlah);
    if(current == NULL){
        printf("Tidak ada produk yang tersedia!\n");
        Sleep(1000);
        system("cls");
        return;
    }
    if(strcmp(current->data.namaproduk, namaproduk) == 0){
        if(current->data.stock >= jumlah){
            current->data.stock -= jumlah;
            current->data.dibeli += jumlah;
            printf("Produk berhasil dibeli!\n");
            Sleep(1000);
            system("cls");
            return;
        }
        else{
            printf("Stock tidak cukup. Pembelian Gagal!\n");
            Sleep(1000);
            system("cls");
            return;
        }
    }
    while(current != NULL){
        if(strcmp(current->data.namaproduk, namaproduk) == 0){
            found = 1;
            break;
        }
        prev = current;
        current = current->next;
    }
    if(found == 1){
        if(current->data.stock > 0){
            current->data.stock -= jumlah;
            current->data.dibeli += jumlah;
            printf("Produk berhasil dibeli!\n");
            Sleep(1000);
            system("cls");
        }
        else{
            printf("Stock produk habis!\n");
            Sleep(1000);
            system("cls");
        }
    }
    else{
        printf("Produk tidak ditemukan!\n");
        Sleep(1000);
        system("cls");
    }
}

void search(Node** head){
    Node* current = *head;
    char cari[50];
    int count = 1;
    int found = 0;

    system("cls");
    printf("===============================================\n"
        "|                   UI SHOP                   |\n"
        "===============================================\n"
        "|                 CARI PRODUK                 |\n"
        "===============================================\n");
    printf("Nama Produk yang ingin dicari : ");
	scanf("%s", &cari);
    if(current == NULL){	
        printf("\nTidak ada produk yang tersedia!\n");
        return;
    }
    system("cls");
    printf("===============================================\n"
        "|                   UI SHOP                   |\n"
        "===============================================\n"
        "|                 CARI PRODUK                 |\n"
        "===============================================\n");
    searchLoop(current, cari, count, &found);
    if(found != 1){
        printf("Produk dengan nama '%s' tidak ditemukan.\n", cari);
    }
}

void searchLoop(Node* current, char* cari, int count, int* found){
    if(current != NULL){
        if(strcmp(current->data.namaproduk, cari) == 0) {
            printf("Nama Produk\t\tHarga\tStock\n");
            printf("%s\t\t%d\t%d\n", current->data.namaproduk, current->data.hargaproduk, current->data.stock);
            *found = 1;
        }
        searchLoop(current->next, cari, count + 1, found);
    }
}

void outro(){
	int i;
	char a[]= { "===============================================\n"
			"|---------------- Terima kasih ---------------|\n"
			"===============================================\n"};
	for(i=0;a[i]!=a[145];i++){ 
		printf("%c",a[i]); 
		Sleep(5); 
	}
    system("cls");
}
