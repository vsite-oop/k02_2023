# VSITE OOP 2. kolokvij

### 1. zadatak (15 bodova)

Napišite template klasu `point2d` (ima privatne članove za `x` i `y`).  
Napišite funkciju `hypot` koja prima dvije točke i vraća udaljenost između točaka.  
U slučaju da je udaljenost manja od 10<sup>-4</sup> (koristite `const` varijablu), funkcija baca iznimku `hypot_err` 
(izvedite je iz `std::exception`, prima tekst greške u konstruktoru).  
U programu unesite dvije točke (sa cjelobrojnim koordinatama) i ispišite njihovu udaljenost (zaokruženu na dvije decimale).
U slučaju greške ispišite poruku greške.

### 2. zadatak (15 bodova)

Napravite program za statistiku postizanja golova u rukometnoj utakmici.  
Podaci se nalaze u datoteci `goals.txt` (u repozitoriju) u formatu: vrijeme strijelac.  
Ispišite u kojem intervalu (po 10 minuta) je palo koliko golova i koliko je koji igrač dao golova:

```
0 - 10: 9
10 - 20: 7
20 - 30: 12
30 - 40: 5
40 - 50: 11
50 - 60: 10

Damgaard: 1
Descat: 2
Fabregas: 7
Gidsel: 7
Hansen: 8
Jakobsen: 2
Kirkelokke: 2
Landin: 1
Lenne: 3
Mahe: 3
Nahi: 4
Prandi: 3
Pytlick: 4
Remili: 4
Saugstrup: 2
Tournat: 1
```

Uputstva: koristite `std::map`.

### 3. zadatak (20 bodova)

Napravite program za analizu rezultata kolokvija.  
Datoteka `oop.txt` je u repozitoriju, format je: ime prezime bodovi (po zadatku).  
Naziv datoteke se prosljeđuje u komandnoj liniji. 
Program unosi sve podatke iz datoteke, izbacuje invalidne (negativni bodovi) 
sortira (ako je isti broj bodova, onda po prezimenu) i ispisuje rezultate u formatu:

```
B. Gjenero 50 (5)
P. Huljek 48 (5)
S. Perkovic 48 (5)
M. Pavic 47 (5)
D. Rukavina 45 (5)
A. Maletic 44 (5)
M. Krpes 41 (4)
L. Blagojevic 31 (3)
T. Basic 20 (2)
```
U zagradi je ocjena, računa se po sljedećoj skali:
```
0-19	1
20-26	2
27-34	3
35-42	4
43-50	5
```
Uputstva: 
- koristite `std::vector` i samo standardne algoritme: `copy`, `copy_n`, `remove_if`, `sort`, `accumulate`
- struktura za studenta neka sadrži `std::array`za bodove po zadatku
