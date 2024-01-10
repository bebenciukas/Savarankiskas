## 1 savarankiškas darbas | v1.0
## Naudojimosi instrukcija:

## Failų "diegimo" (nukopijavimo) į reikiamą folderį žingsniai:

1. Atsisiųskite v1.0 zip.
2. Išsiarchyvuokite ant Desktop'o.
3. Paleiskite Setup.bat naudodami administratoriaus teises.
4.  C:\Program Files\VVK rasite visus sukurtus/(vos ne vos) įgyvendintus pirmojo savarankiško darbo failus.

## v0.1 Naudojimosi instrukcija:

1. Sukompiliuokite main.cpp
2. Norint įvesti studento duomenis, įrašykite 1.
3. Norint nuskaityti duomenis iš tekstinio failo (šiuo atveju - kursiokai.txt), įrašykite 2.
4. Norint sugeneruoti studento įvertinimus atsitiktinai, įrašykite 3.
5. Prieš atsitiktinį skaičių generavimą įveskite studento vardą ir pavardę.
6. Rezultatai bus parodomi dėstytojo nurodyta forma.

## v0.2 Naudojimosi instrukcija:

1. Sukompiliuokite v0.2 esantį main.cpp.
2. Irašykite vieno iš .txt failų pavadinimą, kurį norėtumėte sutvarkyti (pvz. studentai10000.txt).
3. Programa parodys laikus, kurie buvo išmatuoti vykdant:
   > visą procesą (BendraTrukmė) |
   > duomenų skaitymą iš duoto .txt failo |
   > duomenų išskirstymą |
   > naujų failų įrašymą;
4. v1.0 versijoje yra įkeltas 'gener.cpp" kuris buvo naudojamas dideliems studentų failams generuoti (1 000 - 10 000 000) 
____________________________________________________________
## v1.0 - ištestuota strategija
Ištestuota 2 strategija, parinktas partition metodas optimizavimui.
____________________________________________________________
## v0.1 - studento įvedimas
Sukurta programa, kuri :
- leidžia ranka įvesti studento vardą, pavardę, n namų darbų ir egzamino įvertinimus;
- leidžia pasirinkti nuskaitymą iš failo;
- leidžia pasirinkti atsitiktinių pažymių sugeneravimą;
- apskaičiuoja galutinį vidurkį ir medianą;
- rezultatus išveda dėstytojo nurodyta forma.

_____________________________________________________________
## v0.2 - spartos testavimas
Ištestuoti 5 atsitiktinai sugeneruoti skirtingų dydžių tekstiniai duomenų failai, sudaryti iš:
- 1 000 irašų;
- 10 000 irašų;
- 100 000 irašų;
- 1 000 000 irašų;
- 10 000 000 irašų.
  
Sparčiausias konteinerių tipas mano atveju - list.
> Nežinau dėl ko, bet viskas truko gerokai per ilgai. 10mil. studentų failą sutvarkyti užtruko >10min.
> Techniniai parametrai:
> i9-9900k | 3600mhz 32Gb | Samsung 970 Evo 1TB NVMe M.2
______________________________________________________________



