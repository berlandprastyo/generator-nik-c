#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>
char *trim(char *str) {
    while (*str == ' ' || *str == '\t') {
        str++;
    }
    return str;
}
void toLow (char* toLow ) {
    for (int i = 0; toLow[i] != '\0'; i++)
    {
        toLow[i] = tolower((unsigned char)toLow[i]);
    }
    
}
void toUp (char* toUp ) {
    for (int i = 0; toUp[i] != '\0'; i++)
    {
        toUp[i] = toupper((unsigned char)toUp[i]);
    }
    
}
int main(int argc, char const *argv[])
{   
    printf("============================================\n");
    printf("=          GENERATOR NIK (SIMULASI)        =\n");     
    printf("============================================\n");
    printf("CATATAN:\n");
    printf("- Gunakan nama provinsi, kabupaten, dan kecamatan sesuai dataset.\n");
    printf("- Untuk Tangerang, masukkan 'Kota Tangerang' atau\n");
    printf("  'Kabupaten Tangerang' sesuai wilayah yang dimaksud.\n");
    printf("- Program ini hanya untuk pembelajaran dan simulasi.\n");
    printf("- Bukan generator NIK resmi dan tidak menghasilkan\n");
    printf("  identitas kependudukan yang sah.\n");
    printf("============================================\n\n");
    while (1)
    {
        srand(time(NULL));
        int no_urut = rand() % 9 + 1;
        char isContinue[5];
        char nik[17] = "";
        char kode_provinsi[3] = "";
        char kode_kabupaten[5] = "";
        char nama[50];
        char jenis_kelamin[12];
        int tanggal_lahir;
        int bulan_lahir;
        char tahun_lahir[20];
        char kecamatan[40];
        char kabupaten[40];
        char provinsi[40];
        printf("Masukkan Nama Anda : ");
        fgets(nama,sizeof(nama),stdin);
        printf("Apa Jenis Kelamin Anda ? (laki-laki / perempuan) : ");
        fgets(jenis_kelamin,sizeof(jenis_kelamin),stdin);
        printf("Masukkan Tanggal Lahir (1-31) : ");
        scanf("%d",&tanggal_lahir);
        getchar();
        printf("Masukkan Bulan Lahir (1-12) : ");
        scanf("%d",&bulan_lahir);
        getchar();
        printf("Masukkan Tahun Lahir (YYYY) : ");
        fgets(tahun_lahir,sizeof(tahun_lahir),stdin);
        printf("Masukkan Kecamatan : ");
        fgets(kecamatan,sizeof(kecamatan),stdin);
        printf("Masukkan Kabupaten / Kota : ");
        fgets(kabupaten,sizeof(kabupaten),stdin);
        printf("Masukkan Provinsi: ");
        fgets(provinsi,sizeof(provinsi),stdin);
        nama[strcspn(nama,"\r\n")] = '\0';
        jenis_kelamin[strcspn(jenis_kelamin, "\r\n")] = '\0';
        tahun_lahir[strcspn(tahun_lahir, "\r\n")] = '\0';
        kecamatan[strcspn(kecamatan, "\r\n")] = '\0';
        kabupaten[strcspn(kabupaten, "\r\n")] = '\0';
        provinsi[strcspn(provinsi, "\r\n")] = '\0';
        toUp(kecamatan);
        toUp(kabupaten);
        toUp(provinsi);
        char *nama_panggilan = trim(nama);
        nama_panggilan = strtok(nama_panggilan," ");
        nama_panggilan[0] = toupper((unsigned char)nama_panggilan[0]);
        printf("\n===========================\n");
        printf("    HASIL GENERATE NIK\n");
        printf("===========================\n");
        printf("Halo %s, berikut data diri anda.\n",nama_panggilan);
        printf("Jenis Kelamin : %s\n",jenis_kelamin);
        printf("Tanggal Lahir : %02d-%02d-%s\n",tanggal_lahir,bulan_lahir,tahun_lahir);
        printf("Domisili : %s, %s, %s\n",kecamatan,kabupaten,provinsi);
        
        FILE *file = fopen("provinces.csv","r");
    if (file == NULL) {
        printf("File provinces.csv tidak ditemukan!\n");
        return 1;
    }
    char buffer[200];
    toLow(provinsi);
    char *provinsi_nama;
    provinsi_nama = trim(provinsi);
    fgets(buffer,sizeof(buffer),file);
    while (fgets(buffer,sizeof(buffer),file) != NULL)
    {
        char *id = strtok(buffer,",");
        char *provinsi_name = strtok(NULL,",\r\n");
        provinsi_name = trim(provinsi_name);
        toLow(provinsi_name);
        if (strcmp(provinsi_nama, provinsi_name) == 0)
        {
            strcpy(kode_provinsi,id);
            break;
        }
        
    }
    fclose(file);
    file = fopen("regencies.csv","r");
    if (file == NULL) {
        printf("File regencies.cv tidak ditemukan!\n");
        return 1;
    }
    fgets(buffer,sizeof(buffer),file);
    char *kabupaten_nama;
    toLow(kabupaten);
    kabupaten_nama = trim(kabupaten);
    while (fgets(buffer,sizeof(buffer),file) != NULL) {
        char *idKabupaten = strtok(buffer,",");
        char *province_id = strtok(NULL,",");
        char *kabupaten_name = strtok(NULL,",\r\n");
        kabupaten_name = trim(kabupaten_name);
        toLow(kabupaten_name);
        if (strcmp(kode_provinsi,province_id) == 0 && strcmp(kabupaten_nama,kabupaten_name) == 0)
        {
            strcpy(kode_kabupaten,idKabupaten);
            break;
        }
        
    }
    fclose(file);
    file = fopen("districts.csv","r");
    if (file == NULL) {
        printf("File districts.csv tidak ditemukan!\n");
        return 1;
    }
    fgets(buffer,sizeof(buffer),file);
    char *kecamatan_nama;
    toLow(kecamatan);
    kecamatan_nama = trim(kecamatan);
    while (fgets(buffer,sizeof(buffer),file) != NULL) {
        char *id_district = strtok(buffer,",");
        char *id_regency = strtok(NULL,",");
        char *district_name = strtok(NULL,",\r\n");
        district_name = trim(district_name);
        toLow(district_name);
        if (strcmp(kode_kabupaten,id_regency) == 0 && strcmp(kecamatan_nama,district_name) == 0)
        {
            strcat(nik,id_district);
            break;
        }
    }
    fclose(file);
    if (kode_provinsi[0] == '\0' ||
        kode_kabupaten[0] == '\0' ||
        nik[0] == '\0') {
            printf("Data wilayah tidak ditemukan!\n");
            return 1;
        }
        toLow(jenis_kelamin);
        if (strcmp(jenis_kelamin,"perempuan") == 0)
        {
        tanggal_lahir = tanggal_lahir + 40;
        char tanggal[3];
        snprintf(tanggal,sizeof(tanggal),"%02d",tanggal_lahir);
        strcat(nik,tanggal);
    } else {
        char tanggal[3];
        snprintf(tanggal,sizeof(tanggal),"%02d",tanggal_lahir);
        strcat(nik,tanggal);
    }
    char bulan[3];
    snprintf(bulan,sizeof(bulan),"%02d",bulan_lahir);
    strcat(nik,bulan);
    char tahun[3];
    strcpy(tahun,tahun_lahir + 2);
    strcat(nik,tahun);
    strcat(nik,"000");
    char no[2];
    snprintf(no,sizeof(no),"%d",no_urut);
    strcat(nik,no);
    printf("\n");
    printf("==========================================\n");
    printf("NIK hasil generate adalah %s\n",nik);
    printf("==========================================\n");
    while (1)
    {    
        printf("Masih Ingin Lanjut? (y/n) :");
        fgets(isContinue,sizeof(isContinue),stdin);
        if (toupper((unsigned char)isContinue[0]) == 'Y'){
            break;
        } else if (toupper((unsigned char)isContinue[0]) == 'N'){
            printf("Good Bye!\n");
            return 0;
        } else {
            printf("Karakter Tidak Dikenali, Silahkan Mulai Ulang!\n");
            continue;;
        }
    }

    
    
}

}
