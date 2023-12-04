# Personel Sistemi

Bu program, bir işyerindeki personelin bilgilerini yönetmek ve analiz etmek için kullanılır.

## Kullanım

1. **personel.txt Dosyasını Hazırlayın:** Programın çalışabilmesi için "personel.txt" adında bir dosya oluşturun ve her bir çalışanın bilgilerini aşağıdaki formatta girin:

    ```plaintext
    1 Ahmet  Yılmaz BilgiTek  10 3 5000
    2 Ayşe   Kaya   İK        15 6 6000
    3 Mehmet Demir  Pazarlama 20 2 4500
    4 Zeynep Yıldız İletişim   5 8 7000
    ...
    ```

    Her bir çalışanın bilgisi, sırasıyla çalışan ID, ad, soyad, departman, izin günleri, deneyim yılı ve maaş bilgilerini içermelidir.

2. **Programı Çalıştırın:** Derlenmiş programı çalıştırın. Program, belirli işlemleri yapmak için bir menü sunacaktır.

3. **Menüden İşlemleri Seçin:** Programın sunduğu menüden yapmak istediğiniz işlemi seçin. Örneğin, en yüksek maaş alan çalışanı görüntülemek, yönetici bilgilerini güncellemek, vb.

4. **Çıkış Yapın:** İşlemleri tamamladıktan sonra programdan çıkış yapmak için uygun seçeneği seçin.

## Fonksiyonlar

- **yonetici_secilen_calisanin_bilgileri:** Yönetici seçilen bir çalışanın bilgilerini görüntüler ve maaşını günceller.

- **en_yuksek_maas_alan_calisanin_bilgisi:** En yüksek maaş alan çalışanın adını ve maaşını görüntüler.

- **en_fazla_ek_maas_alan_calisanin_bilgisi:** En fazla ek maaş alan çalışanın adını ve departmanını görüntüler.

- **en_az_izin_kullanan_calisanin_bilgisi:** Deneyim yılı 1'den fazla olan ve en az izin kullanan çalışanın adını ve soyadını görüntüler.

- **en_fazla_calisan_departmani:** En fazla çalışana sahip departmanı görüntüler.



