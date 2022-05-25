# v2.0

Sukurtas programos įdiegimo failas.

Įdiegimo instrukcija: paleidžiamas setup.msi failas, spaudžiama "next", sekančiame lange pasirenkama įdiegimo vieta, spaudžiama "next" ir instaliacija prasidės.

Sukurta programos dokumentacija naudojant Doxygen.

Realizuoti testavimo atvejai naudojant Google Test.

# v1.5

Pridėta klasė Žmogus, klasė Studentas padaryta kaip derivative iš Žmogus.

# v1.2

Įvykdyta rule of three ir perdengtas išvedimo << operatorius.

# v1.1

Pakeistas programos kodas taip, kad naudojama ne struktūra o klasė. 

Spartos matavimai atlikti su tais pačiais failais toje pačioje sistemoje.

Sistemos parametrai: CPU: AMD Ryzen 5 5500U 2.1 GHz 6 cores SSD: WDC PC SN530 256GB RAM: 8GB 3200Mhz

Spartos matavimai struktūra prieš klasę:
Struct:

1000000 įrašų:
Vector nuskaitymas: 1.315s, rūšiavimas į dvi grupes: 0.141s, rūšiavimas sort: 0.139s, išvedimas į failus: 4.959s

10000000 įrašų:
Vector nuskaitymas: 13.114s, rūšiavimas į dvi grupes: 2.074s, rūšiavimas sort: 1.413s, išvedimas į failus: 48.378s

Class:

1000000 įrašų:
Vector nuskaitymas: 1.449s, rūšiavimas į dvi grupes: 0.139s, rūšiavimas sort: 0.074s, išvedimas į failus: 4.232s

10000000 įrašų:
Vector nuskaitymas: 18.131s, rūšiavimas į dvi grupes: 2.922s, rūšiavimas sort: 0.666s, išvedimas į failus: 39.618s

Spartos matavimai su optimizacijų flag'ais:
Class:

1000000 įrašų:
Vector nuskaitymas: 1.449s, rūšiavimas į dvi grupes: 0.139s, rūšiavimas sort: 0.074s, išvedimas į failus: 4.232s

10000000 įrašų:
Vector nuskaitymas: 18.131s, rūšiavimas į dvi grupes: 2.922s, rūšiavimas sort: 0.666s, išvedimas į failus: 39.618s

Class su flag'ais:

Fast code flag'as: 

Vector nuskaitymas: 1,482s, rūšiavimas į dvi grupes: 0,131s, rūšiavimas sort: 0,082s, išvedimas į failus: 4,113s

10000000 įrašų:
Vector nuskaitymas: 15,954s, rūšiavimas į dvi grupes: 1,649s, rūšiavimas sort: 0,956s, išvedimas į failus: 40,033s

RAM gali pasiekti iki 3,8GB naudojimą

Small code flag'as:

1000000:
Vector nuskaitymas: 1,473s, rūšiavimas į dvi grupes: 0,122s, rūšiavimas sort: 0,077s, išvedimas į failus: 4,079s

10000000:
Vector nuskaitymas: 14,940s, rūšiavimas į dvi grupes: 1.920s, rūšiavimas sort: 0.664s, išvedimas į failus: 39.370s

RAM gali pasiekti iki 3,8GB naudojimą
# v1.0 

Sukurtas makefile, kurio pagalba lengvai įsidiegsite programą.

Pakeistas programos kodas taip, kad vietoje dviejų naujų studentų konteinerių yra sukuriamas tik vienas (studentų, kurių pažymių vidurkis virš 5), o pradiniame
konteineryje lieka tik studentai, kurių vidurkis mažiau už 5.  

Spartos matavimai atlikti su tais pačiais failais toje pačioje sistemoje.

Sistemos parametrai: CPU: AMD Ryzen 5 5500U 2.1 GHz 6 cores SSD: WDC PC SN530 256GB RAM: 8GB 3200Mhz

Spartos matavimas:
[v1.0_TEST.txt](https://github.com/Einartas/v0.1-vector/files/8602003/v1.0_TEST.txt)

# v0.5

Programa papildyta dviem naujais konteinerių tipais: deque ir list. Atlikti spartos matavimai, siekiant išsiaiškinti, kuris konteineris yra efektyviausias.

Spartos matavimai atlikti su tais pačiais failais toje pačioje sistemoje.

Sistemos parametrai: CPU: AMD Ryzen 5 5500U 2.1 GHz 6 cores SSD: WDC PC SN530 256GB RAM: 8GB 3200Mhz

Spartos matavimas: 
[TEST.txt](https://github.com/Einartas/v0.1-vector/files/8500068/TEST.txt)

# v0.4

Programoje pridėta galimybė generuoti įvairių dydžių failus. Generuojami atsitiktiniai vardai, pavardės ir pažymiai, viskas surašoma ir išsaugoma
tekstiniame faile Generavimas.txt. Po generavimo programa nuskaito šį failą ir atlikus apskaičiavimus yra sukuriami du nauji failai:
Gerieciai.txt (vidurkis daugiau už 5) ir Blogiečiai.txt (vidurkis mažiau už 5).

Atlikti skirtingų programos veikimo tarpų matavimai.

# v0.3

Atliktas programos kodo išskaidymas: programos kodas padalintas į naujus .cpp ir .h failus.

# v0.2

Programa papildyta galimybe nuskaityti duomenis iš duomenų failo kursiokai.txt.
Išvedami rezultatai yra surūšiuoti ir išlygiuoti.

# v0.1

Programa prašo įvesti studentų vardus, pavardes, pažymius bei egzamino balą. Galima įvesti įvairų kiekį studentų, tai pasirenkate patys. 
Vardus ir pavardes visada reikia įvesti ranka, tačiau pažymius galima įvesti ranka arba pasirinkti atsitiktinai sugeneruoti.
Baigus įvedimą programa apskaičiuoja kiekvieno studento galutinį vidurkį ir medianą. Ekrane išvedama gautų rezultatų lentelė.

Programa realizuota dviem būdais: naudojant masyvą ir vektorių.
