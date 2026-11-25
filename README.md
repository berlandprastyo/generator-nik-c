# NIK Generator (Just Kidding)

Program berbasis bahasa C untuk membuat simulasi Nomor Induk Kependudukan (NIK) berdasarkan data wilayah dan tanggal lahir.

Program ini membaca data wilayah dari file CSV, kemudian mencocokkan provinsi, kabupaten/kota, dan kecamatan yang dimasukkan pengguna untuk menghasilkan format NIK simulasi.

## Features

- Normalisasi huruf besar dan kecil untuk pencocokan nama wilayah.
- Penyesuaian tanggal lahir berdasarkan jenis kelamin.
- Pembuatan empat digit nomor urut secara acak.

## Requirements

- GCC Compiler
- Standard C Library
- Data wilayah dalam format CSV.

## Project Structure

```text
.
├── generate-nik.c
├── provinces.csv
├── regencies.csv
└── districts.csv
```

## How to Run

Compile program menggunakan GCC:

```bash
gcc generate-nik.c -o generate-nik
```

Jalankan program:

```bash
./generate-nik
```

Untuk Windows:

```powershell
gcc generate-nik.c -o generate-nik.exe
.\generate-nik.exe
```

## Special Input

Khusus wilayah Tangerang, pastikan memasukkan nama kabupaten/kota secara spesifik:

- `Kota Tangerang`
- `Kabupaten Tangerang`

Jangan hanya memasukkan `Tangerang`, karena keduanya merupakan wilayah administratif yang berbeda.

## Disclaimer

Program ini hanya dibuat untuk tujuan pembelajaran bahasa C, khususnya pengolahan string, pointer, array, file handling, dan pembacaan data CSV.

NIK yang dihasilkan merupakan simulasi dan bukan NIK resmi yang diterbitkan oleh Dukcapil. Kode wilayah dan nomor urut yang digunakan belum tentu sesuai dengan ketentuan administrasi kependudukan yang sebenarnya.

**NIK Generator — Just Kidding.**
## Dataset Attribution

Data wilayah yang digunakan dalam project ini berasal dari repository GitHub berikut:

- **Source:** dataset-wilayah-indonesia https://github.com/prodhokter/dataset-wilayah-indonesia
- **Directory:** `clean/`
- **Files used:** `provinces.csv`, `regencies.csv`, `districts.csv`

Dataset digunakan sebagai sumber referensi data wilayah untuk proses pencocokan nama provinsi, kabupaten/kota, dan kecamatan.

All credits belong to the original dataset author.

