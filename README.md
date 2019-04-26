# SoalShift_modul4_E12
by:<br/> 
I Dewa Putu Wiprah A      (05111740000152)<br/>
Reza Adipatria Maranatha  (05111740000186)
# 1
Untuk mengerjakan nomor 1, kita harus membuat 2 fungsi, yaitu fungsi decrypt dan fungsi encrypt, dengan format  [qE1~ YMUR2\"`hNIdPzi%^t@(Ao:=CQ,nx4S[7mHFye#aT6+v)DfKL$r?bkOGB>}!9_wV']jcp5JZ&Xl|\\8s;g<{3.u*W-0]`. Lalu menggunakan fungsi getattr dan readdir untuk mengambil filename pada path dirpath. Sebelum di mount, filename akan ter encrypt, dan saat di mount, filename akan ter decrypt.
# 2
Untuk nomor 2 kita diminta untuk menggabungkan/join file-file video yang terpisah-pisah. Saat file system di mount akan otomatis terbuat folder Videos untuk menampung file video yang sudah tergabung. Kemudian jangan tampilkan file pecahan video di direktori manapun. Saat akan di un-mount, folder Videos dan isinya akan terhapus, tetapi tidak menghapus file-file pecahan video yang ada di root file system.
# 3
Untuk mengerjakan nomor 3, kita harus mengecek apakah suatu file memiliki group name "rusak" dan memiliki owner name "chipset" atau "ic_controller" dan juga mengecek apakah file tersebut bisa dibaca atau tidak. Maka kita perlu menyimpan gid dan uid dalam struct stat, lalu mencari group name dan owner name dari gid dan uid suatu file yang bersangkutan dengan struct group dan struct passwd. Jika memenuhi syarat, maka file akan di remove.

# 4
Untuk mengerjakan nomor 4, kita perlu mengecek apakah suatu direktori merupakan subdirektori dari folder YOUTUBE. Jika iya, maka setiap folder akan memiliki permission 750 dan file akan memiliki permission 640 dan pada file akan ditambah ekstensi "iz1" File berekstensi “.iz1” tidak bisa diubah permissionnya dan memunculkan error bertuliskan “File ekstensi iz1 tidak boleh diubah permissionnya.”

# 5
Untuk nomor 5, kita diminta untuk membuat backup suatu file ketika kita sedang meng-edit kemudian melakukan save terhadap file tersebut. File tersebut akan dibuat backupnya dengan format `namafile_[timestamp].ekstensi`. Kemudian pada saat file di hapus, akan terbuat folder RecycleBin untuk menampung file yang di hapus setelah di zip terlebih dahulu. Setelah dipindah ke RecycleBin, hapus file asli.
  
