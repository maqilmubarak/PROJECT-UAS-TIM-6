# PROJECT-UAS-TIM-6
<p align="center">
<img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge">
<img src="https://img.shields.io/badge/Platform-CLI%20Application-darkgoldenrod?style=for-the-badge">
<img src="https://img.shields.io/badge/Project-Academic-gold?style=for-the-badge">
<img src="https://img.shields.io/badge/Contributors-5-darkred?style=for-the-badge">
<img src="https://img.shields.io/badge/University-USK-darkgreen?style=for-the-badge">
<img src="https://img.shields.io/badge/Status-Completed-lightgreen?style=for-the-badge">
</p>

```
 __  __     ______     ______       
/\ \/\ \   /\  __ \   /\  ___\      
\ \ \_\ \  \ \  __ \  \ \___  \     
 \ \_____\  \ \_\ \_\  \/\_____\    
  \/_____/   \/_/\/_/   \/_____/    
 ______   ______     __    __     ______     ______     ______     ______     ______     __    __     ______     __   __       
/\  == \ /\  ___\   /\ "-./  \   /\  == \   /\  __ \   /\  ___\   /\  == \   /\  __ \   /\ "-./  \   /\  __ \   /\ "-.\ \      
\ \  _-/ \ \  __\   \ \ \-./\ \  \ \  __<   \ \ \/\ \  \ \ \__ \  \ \  __<   \ \  __ \  \ \ \-./\ \  \ \  __ \  \ \ \-.  \     
 \ \_\    \ \_____\  \ \_\ \ \_\  \ \_\ \_\  \ \_____\  \ \_____\  \ \_\ \_\  \ \_\ \_\  \ \_\ \ \_\  \ \_\ \_\  \ \_\\"\_\    
  \/_/     \/_____/   \/_/  \/_/   \/_/ /_/   \/_____/   \/_____/   \/_/ /_/   \/_/\/_/   \/_/  \/_/   \/_/\/_/   \/_/ \/_/    
 ______   __     __    __        __   __   __    
/\__  _\ /\ \   /\ "-./  \      /\ \ / /  /\ \   
\/_/\ \/ \ \ \  \ \ \-./\ \     \ \ \'/   \ \ \  
   \ \_\  \ \_\  \ \_\ \ \_\     \ \__|    \ \_\ 
    \/_/   \/_/   \/_/  \/_/      \/_/      \/_/ 
```                                                                                                                                                                                                             


# 🧪 **Deskripsi Proyek**

Proyek ini adalah implementasi **Sistem Peminjaman Alat Laboratorium** berbasis bahasa **C (ANSI C)** dengan antarmuka **Command Line (CLI)**.
Data disimpan dalam format `.txt` sesuai kebutuhan **Praktikum Pemrograman Kelas A – FMIPA USK**.

Program mencakup:

* 🔐 Login via Command Line Argument
* 🛠 Mode Admin (CRUD alat)
* 📦 Mode User (peminjaman & pengembalian)
* 📁 Database file-based
* 🎵 BONUS: Program pembuat kosakata unik dari lirik lagu

---
# 🎨 **Daftar Isi**

* [Anggota Kelompok](#-anggota-kelompok)
* [Struktur Direktori](#%EF%B8%8F-struktur-direktori)
* [Penjelasan Sistem](#-penjelasan-program)
* [Bonus Program Lirik](#-bonus-program--kosa-kata-lirik)
* [Format File TXT](#-format-file)
* [Cara Compile & Run](#️-cara-compile--run)
* [Cara Clone Repo](#-clone-repo)
* [Arsitektur Program](#-arsitektur-program)

---

# 👥 **Anggota Kelompok**

| No | Nama                        | NPM             |
| -- | --------------------------- | --------------- |
| 1  | **Siti Salwa Shafina**      | 250810701100055 |
| 2  | **Nayli Itqiyana**          | 250810701100025 |
| 3  | **Virzi Mayhand Syahputra** | 250810701100077 |
| 4  | **Muhammad Aqil Mubarak**   | 250810701100003 |
| 5  | **Muhammad Khishal Ardana** | 250810701100070 |

---
# 🗃️ Struktur Direktori

```
PROJECT-UAS-TIM-6
│
├── kosakatalirik
│   ├── lirik.txt
│   └── main.c
│
└── sistempinjamalat
    ├── admin
    │   ├── adminfunction.c
    │   └── adminfunction.h
    │
    ├── data
    │   ├── account.txt
    │   ├── items.txt
    │   └── loan.txt
    │
    ├── fileio
    │   ├── fileio.c
    │   └── fileio.h
    │
    ├── login
    │   ├── login.c
    │   └── login.h
    │
    ├── user
    │   ├── userfunction.c
    │   └── userfunction.h
    │
    ├── utils
    │   ├── utils.c
    │   └── utils.h
    │
    ├── main.c
    ├── makefile
    └── LICENSE
```

---

# 🧠 **Penjelasan Program**

## 🔑 1. Sistem Login

**Folder:** `sistempinjamalat/login/`

* `login.c`
* `login.h`

**Fungsi inti:**

* Validasi username & password
* Deteksi role (admin/user)
* Redirect ke menu yang sesuai

**Data user tersimpan di:**

```
sistempinjamalat/data/account.txt
```
## 🛠 2. Mode Admin – CRUD Alat

**Folder:** `sistempinjamalat/admin/`

* `adminfunction.c`
* `adminfunction.h`

**Operasi admin:**

* ➕ Tambah alat
* ✏️ Edit alat
* ❌ Hapus alat
* 📋 Tampilkan item

**Data item tersimpan di:**

```
sistempinjamalat/data/items.txt
```

---
## 📦 3. Mode User – Peminjaman Alat

**Folder:** `sistempinjamalat/user/`

* `userfunction.c`
* `userfunction.h`

**Operasi user:**

* 📦 Pinjam alat laboratorium
* ↩️ Kembalikan alat
* 📋 Lihat daftar peminjaman

**Data transaksi peminjaman tersimpan di:**

```
sistempinjamalat/data/loan.txt
```

---

## 📁 4. Sistem I/O File

**Folder:** `sistempinjamalat/fileio/`

* `fileio.c`
* `fileio.h`

**Tugas:**

* Membaca file account/item/loan
* Menulis ulang file
* Helper untuk menjaga konsistensi database

**Fungsi utama:**
- `loadAccounts()` → Baca `account.txt`
- `loadItems()` → Baca `items.txt`
- `loadLoans()` → Baca `loan.txt`
- `saveItems()` → Tulis ke `items.txt`
- `saveLoans()` → Tulis ke `loan.txt`

---

## 🔧 5. Utils

**Folder:** `sistempinjamalat/utils/`

* `utils.c`
* `utils.h`

**Berisi fungsi utilitas seperti:**

* Validasi input
* Konversi string
* Pengecekan kesalahan
* Text formatting pada CLI
* Terminal control (clear screen, colors, etc.)

---

# 🎵 **Bonus Program – Kosa Kata Lirik**

**Lokasi:** `kosakatalirik/`

Program terpisah yang membaca `lirik.txt` lalu menghasilkan:

```
kata=
kata=
kata=
```

**Aturan:**

* Kata unik (tidak ada duplikasi)
* Lowercase semua
* Tanpa tanda baca (kecuali apostrof)
* Urutan sesuai kemunculan pertama

**Cara menjalankan:**

```bash
cd kosakatalirik
gcc main.c -o kosakata
./kosakata
```

---

# 📄 **Format File**

### `account.txt`

```
admin admin123 admin
salwa 12345 user
virzi 9090 user
```

**Format:** `username password role`

---

### `items.txt`

```
1 Keyboard Rexux ModelA 2019 5
2 Mouse Logitech 5425 2020 3
```

**Format:** `id nama_alat merek model tahun jumlah`

---

### `loan.txt`

```
salwa 1 Keyboard
virzi 2 Mouse
```

**Format:** `username id_alat nama_alat`

---

# ▶️ **Cara Compile & Run**


## 📝 Makefile

```makefile
CC = gcc
CFLAGS = -Iadmin -Iuser -Ilogin -Ifileio -Iutils

SRC = main.c \
      admin/adminfunction.c \
      user/userfunction.c \
      login/login.c \
      fileio/fileio.c \
      utils/utils.c

all:
	$(CC) $(SRC) -o peminjaman $(CFLAGS)

clean:
	rm -f peminjaman
```

## 🔨 Compile Program

```bash
cd sistempinjamalat
make
```

---
## ▶️ **Jalankan sebagai Admin**

```bash
./peminjaman admin admin123
```

## ▶️ **Jalankan sebagai User**

```bash
./peminjaman salwa 12345
```

---

# 🚀 **Clone Repo**

```bash
git clone https://github.com/maqilmubarak/PROJECT-UAS-TIM-6
cd PROJECT-UAS-TIM-6
```

---

# 🧭 **Arsitektur Program**

## 📐 Struktur Modular

Program ini dibangun dengan arsitektur modular berbasis C, dengan pemisahan tanggung jawab yang jelas:

```
                              main.c
                                 │
                    ┌────────────┴─────────────┐
                    │                          │
                    ▼                          ▼
            ┌──────────────┐          ┌──────────────┐
            │   login/     │          │   utils/     │
            │  login.c/h   │          │  utils.c/h   │
            └──────┬───────┘          └──────────────┘
                   │                   (Helper Functions)
                   │ (Autentikasi)
                   │
        ┏━━━━━━━━━┻━━━━━━━━━┓
        ▼                    ▼
   ┌─────────┐          ┌─────────┐
   │  admin/ │          │  user/  │
   │ CRUD    │          │ Pinjam  │
   └────┬────┘          └────┬────┘
        │                    │
        └────────┬───────────┘
                 ▼
          ┌────────────┐
          │  fileio/   │
          │ fileio.c/h │
          └──────┬─────┘
                 │
        ┌────────┼────────┐
        ▼        ▼        ▼
    ┌────────────────────────┐
    │      data/             │
    ├────────────────────────┤
    │ • account.txt          │
    │ • items.txt            │
    │ • loan.txt             │
    └────────────────────────┘
```

---
## 🔄 Alur Kerja Program

### 1️⃣ **Entry Point: main.c**
- Menerima command line arguments (username & password)
- Memanggil modul `login/` untuk validasi

### 2️⃣ **Autentikasi: login/**
- Membaca `data/account.txt` via `fileio/`
- Validasi kredensial user
- Menentukan role: `admin` atau `user`
- Redirect ke menu yang sesuai

### 3️⃣ **Menu Admin: admin/**
**File:** `adminfunction.c` & `adminfunction.h`

---


Operasi CRUD untuk alat laboratorium:
- ➕ **Create**: Tambah alat baru
- 📖 **Read**: Tampilkan daftar alat
- ✏️ **Update**: Edit data alat
- ❌ **Delete**: Hapus alat

Data disimpan ke `data/items.txt` menggunakan `fileio/`

### 4️⃣ **Menu User: user/**
**File:** `userfunction.c` & `userfunction.h`

Operasi peminjaman:
- 📦 **Pinjam Alat**: Catat peminjaman ke `data/loan.txt`
- ↩️ **Kembalikan Alat**: Hapus record dari `loan.txt`
- 📋 **Lihat Peminjaman**: Tampilkan alat yang dipinjam

### 5️⃣ **File I/O Handler: fileio/**
**File:** `fileio.c` & `fileio.h`

Mengelola semua operasi baca/tulis file untuk menjaga konsistensi data.
