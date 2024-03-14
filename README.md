<p align="center">
  <h2 align="center">
    SISTEM PELAYANAN RENTAL PS
  </h2>
</p>

<!-- Daftar Isi -->
<details open="open">
  <summary><h2 style="display: inline-block">Daftar Isi</h2></summary>
  <ol>
    <li><a href="#anggota-tim">Anggota Tim</a></li>
    <li><a href="#latar-belakang">Latar Belakang</a></li>
    <li><a href="#tujuan-dan-manfaat">Tujuan dan Manfaat</a></li>
    <li><a href="#penjelasan-aplikasi">Penjelasan Aplikasi</a></li>
    <li><a href="#gambar-rancangan-antarmuka">Gambar Rancangan Antarmuka</a></li>
    <li><a href="#rencana-pengerjaan-proyek">Rencana Pengerjaan Proyek</a></li>
    <li><a href="#lisensi">Lisensi</a></li>
  </ol>
</details>

<!-- Anggota Tim -->
## Anggota Tim
| NPM           | Name        |
| ------------- |-------------|
| 140810220035  | Umar        |
| 140810220055  | Athar       |
| 140810220059  | Ilham       |

<!-- Latar Belakang -->
## Latar Belakang
Di 2023 ini, banyaknya bisnis UMKM yang bergerak di bidang rental konsol gim tidaklah menurun. Hal ini tidak sejalan dengan perkiraan masyarakat umum yang mengarah pada menurunnya jumlah UMKM tersebut karena maraknya gim daring. Skala bisnis rental konsol gim sangatlah beragam, mulai dari yang besar dengan bangunan yang mewah, hingga yang kecil dengan stok konsol sedikit dengan bangunan rumah pada umumnya.
Tidak sedikit bisnis rental dengan skala kecil masih menggunakan pembukuan dan pencatatan standar seperti menggunakan Microsoft Excel atau bahkan manual dengan kertas dan pena. Sebenarnya, aplikasi pencatatan bagi para pebisnis skala kecil sudah tersebar di internet. Namun, hal itu tidak menjadi pertimbangan bagi mereka karena biasanya ada biaya perbulan yang cukup besar. Biaya yang cukup besar itu terjadi karena fitur yang ada dalam aplikasi pencatatan sangatlah banyak. Para pengembang aplikasi tersebut memang menyusun sedemikian rupa agar dapat mendapat pengguna dari segala jenis bisnis.

Maka dari itu kami membuat program ini yang bertujuan untuk membantu bisnis UMKM dibidang konsol gim untuk memudahkan dalam mengelola dan tidak perlu mengeluarkan biaya sepeserpun untuk menggunakannya. 

<!-- Tujuan dan Manfaat -->
## Tujuan dan Manfaat
* Tujuan
  <ol>
    <li>Mengatur antrean pemain secara otomatis </li>
    <li>Memproses pemakain ps berdasarkan urutan yang datang </li>
    <li>Memproses pembayaran </li>
    <li>Menampilkan laporan pendapatan harian </li>
  </ol>
  <br>
  Manfaat
  <ol>
    Manfaat pembuatan program ini adalah untuk melatih pemahaman dan kreativitas praktikan dalam mengimplementasikan materi struktur data yang sudah disampaikan selama satu semester menjadi suatu program yang dapat berjalan sesuai fungsinya. Selain itu, kami berharap program yang telah dibuat dapat berguna dan menjadi inspirasi bagi pelaku owner ps yang masih menggunakan metode tulis tangan dalam sistem pelayanannya.

<!-- Penjelasan Aplikasi -->
## Penjelasan Aplikasi
Aplikasi yang kami buat menggunakan tiga teknik dalam struktur data yaitu, queue, stack, dan circular linked list. Pada dasarnya aplikasi kita menuntun user dalam perjalanan memesan suatu konsol pada suatu waktu. Program kita memungkinkan user untuk melakukan pesanan secara berulang, melihat resi pesanan tertentu, jumlah pesanan dalam 1 hari, dan total pendapatan rental. Kita menggunakan CLI sebagai tampilan antarmuka aplikasi kita.

<!-- Gambar Rancangan Antarmuka -->
## Gambar Rancangan Antarmuka

---------------------------------------------------------------
			          Manajemen Rental Konsol
---------------------------------------------------------------

Silakan masukkan angka sesuai menu yang anda pilih!

1. Antrean Pelanggan
2. Stok Konsol
3. Keuangan Hari Ini

0. Keluar
---------------------------------------------------------------


(1)
---------------------------------------------------------------
		                Antrean Pelanggan
---------------------------------------------------------------

Silakan masukkan angka sesuai menu yang anda pilih!

1. Tambah pelanggan baru
2. Hapus pelanggan
3. Lihat detail antrean

---------------------------------------------------------------


(2)
---------------------------------------------------------------
		                    Stok Konsol
---------------------------------------------------------------

Silakan masukkan angka sesuai menu yang anda pilih!

1. Tambah stok baru
2. Hapus stok
3. Lihat detail stok

---------------------------------------------------------------


(3)
---------------------------------------------------------------
		                  Keuangan Hari Ini
---------------------------------------------------------------

TOTAL Pelanggan = 1
TOTAL Pendapatan = 30000

1.
-----------------------
	Bon Rental
-----------------------
1001 Rizky Putra

PS4

9.00 - 11.00 (2 jam)

30000
-----------------------


(1, 1)
---------------------------------------------------------------
		                Penambahan Pelanggan
---------------------------------------------------------------

ID Pelanggan:

Nama Pelanggan:

Konsol Pilihan:

Waktu Mulai: 

Durasi Rental: 

Lanjutkan atau tidak? (Y/N)

Pelanggan berhasil ditambahkan!...


(1, 2)
---------------------------------------------------------------
			              Penghapusan Pelanggan
---------------------------------------------------------------

ID Pelanggan: 1

Lanjutkan atau tidak? (Y/N)

Pelanggan berhasil dihapus!...


(1, 3)
--------------------------------------------------------------
			                  Detail Pelanggan

1.
-----------------------
    Antrean Rental
-----------------------
1001 Rizky Putra

PS4

9.00 - 11.00 (2 jam)
-----------------------


(2, 1)
---------------------------------------------------------------
			            Penambahan Stok Konsol
---------------------------------------------------------------

Kategori Konsol? (PS4/PS3/PS2)

Berapa Banyak?

Lanjutkan atau tidak? (Y/N)

Penambahan stok berhasil!...

---------------------------------------------------------------


(2, 2)
---------------------------------------------------------------
			          Penghapusan Stok Konsol
---------------------------------------------------------------

Kategori Konsol? (PS4/PS3/PS2)

Berapa Banyak?

Lanjutkan atau tidak? (Y/N)

Penghapusan stok berhasil!...

---------------------------------------------------------------


(2, 3)
---------------------------------------------------------------
			                  Stok Konsol
---------------------------------------------------------------

PS4 = 5 (Terdapat Antrean)

PS3 = 5 (Antrean kosong)

PS2 = 5 (Antrean Kosong)

---------------------------------------------------------------				


<!-- Rencana Pengerjaan Proyek -->
## Rencana Pengerjaan Proyek

Kami menggunakan beberapa tools seperti google docs, github, dan visual studio code untuk pengerjaan proyek. Selain itu, antar anggota kelompok berkoordinasi melalui google meet, dan whatsapp. Untuk pembagian tugas, kami saling membantu di setiap bagian program yang dikerjakan dan belum ada pembagian tugas yang spesifik kedepannya.

<!-- Lisensi -->
## Lisensi

MIT License 2022
