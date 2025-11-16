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
