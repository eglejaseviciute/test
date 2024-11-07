# Objektinis programavimas (1-oji užduotis)
## Programos versijų aprašymas
* ### v.pradinė
  * Nuskaito ***naudotojo įvestus*** duomenis: studentų vardus, pavardes, namų darbų bei egzamino rezultatus;
  * ***Atsitiktinai generuoja*** rezultatus, jei to pageidaujama;
  * Suskaičiuoja galutinį rezultatą pagal formulę: ***galutinis = 0,4 * namų darbų vidurkis arba mediana + 0,6 * egzaminas***.
* ### v0.1
  * Pridėta galimybė nuskaityti duomenis iš ***.txt failo***;
  * Pridėtas studentų ***rūšiavimas*** pagal ***vardus*** ir, jei reikia, pagal ***pavardes***;
  * Kur tikslinga, programoje panaudotos ***struct'ūros***;
  * Pridėta daugiau ***išimčių valdymo*** (angl. Exception Handling);
  * Programa išskirstyta į atskirus ****.cpp*** ir ****.h*** failus.
* ### v0.2
  * Pridėta galimybė ***generuoti penkis*** atsitiktinius studentų sąrašų ***failus***, sudarytus iš: 1 000, 10 000, 100 000, 1 000 000, 10 000 000 įrašų. Vardai ir Pavardės generuojami "šabloniniai", pvz.: Vardas1 Pavarde1, Vardas2 Pavarde2 ir t.t.;
  * Studentai rūšiuojami į dvi kategorijas:
    - studentai, kurių ***galutinis balas < 5.0***,
    - studentai, kurių ***galutinis balas >= 5.0***;
  * Surūšiuoti studentai išvedami į du naujus failus: ***"vargšiukai.txt"*** ir ***"galvočiai.txt"***;
  * Atlikta ***programos veikimo greičio analizė***: t.y., išmatuota programos sparta kiekvienam iš žemiau išvardintų žingsnių:
    - failo sukūrimo,
    - duomenų nuskaitymo iš failo,
    - studentų rūšiavimą į dvi grupes (iš prieš tai sukurto failo),
    - surūšiuotų studentų išvedimą į du naujus failus (iš prieš tai sukurto failo).

<img width="799" alt="Screenshot 2024-11-07 at 18 52 17" src="https://github.com/user-attachments/assets/d5d1d5cf-36de-4405-bab8-0fb92da06aff">

* ### v0.3
  * Sukurta alternatyvi programos versija, kur vietoj ***std::vector*** studentų duomenims saugoti naudojama ***std::list***;
  * * List ir Vector konteinerių atveju ***rankinio įvedimo metu ekrane*** be studento duomenų išvedamas ***objekto*** saugojimo ***atmintyje adresas***;
  * Atlikta ***programos veikimo greičio analizė*** priklausomai nuo naudojamo vieno iš ***dviejų konteinerių***:
    - std::vector,
    - std::list.

<img width="799" alt="Greicio analize (vector)" src="https://github.com/user-attachments/assets/0ecaa00c-35b2-430c-8069-30432c1fb672">

<img width="799" alt="Greicio analize (list) copy" src="https://github.com/user-attachments/assets/cecfe982-8746-47d6-9967-e69780f84e9f">

* ### v1.0
  * ***Optimizuotas studentų rūšiavimas į dvi kategorijas*** ("vargsiuku" ir "galvociu"): t.y., konteinerių tipams (vector ir list) ***atlikta strategijų analizė*** priklausomai nuo studentų dalijimo į dvi kategorijas:
    - ***1 strategija***: Bendro ***"studentai" konteinerio*** (vector arba list) ***skaidymas*** (rūšiavimas) ***į du naujus to paties tipo konteinerius***: "vargsiukai" ir "galvociai". Tokiu būdu tas pats studentas yra dviejuose konteineriuose: bendrame "studentai" ir viename iš suskaidytų ("vargsiukai" arba "galvociai");
    - ***2 strategija***: Bendro ***"studentai" konteinerio*** (vector arba list) ***skaidymas*** (rūšiavimas) panaudojant tik ***vieną naują konteinerį***: "vargsiukai". Tokiu būdu, jei studentas yra "vargšiukas", jį turime įkelti į naująjį "vargsiukai" konteinerį ir ištrinti iš bendro "studentai" konteinerio. Po šio žingsnio "studentai" konteineryje liks vien tik "galvociai";
    - ***3 strategija***: Bendro ***"studentai" konteinerio*** (vector arba list) ***skaidymas*** (rūšiavimas) ***panaudojant 2 strategiją*** ir įtraukiant į ją ***efektyvius*** darbo su konteineriais ***metodus*** (algoritmus):
      -  std::stable_partition;
      -  std::remove_if;
      -  std::iota;
      -  std::splice.
        
<img width="1030" alt="Screenshot 2024-11-07 at 19 42 26" src="https://github.com/user-attachments/assets/5985537a-2257-4c49-99ed-5d34308824a3">

#
## Programos įdiegimo instrukcija
  1. Pirmiausia reikia ***parsisiųsti "v1.0 (vector)" arba "v1.0 (list)" (arba abi) direktoriją (-as)***.
  2. Tuomet reikia savo kompiuteryje ***įsijungti "Terminal"*** ir pirmiausia ***įvesti kelią iki direktorijos***, kuri buvo parsiųsta: "cd "čia įrašyti kelią iki direktorijos"", tuomet paspausti "Enter" ir ***įvesti "./run.sh"*** (jei nesuveiktų "./run.sh", prieš "./run.sh" reiktų dar suvesti "chmod +x run.sh").
  3. Po "./run.sh" paleidomo - ***programa terminale pasileis***. 
  4. Pakartotiniam programos paleidimui terminale vėl reikės ***įvesti kelią iki direktorijos*** ir vietoj "./run.sh", gelėsite įvesti ***"/v1.0_vector"*** (std::vector atveju) arba ***"./v1.0_list"*** (std::list atveju).

# 
## Naudojimosi programa instrukcija
1. Paleidus šią programą, ekrane bus matomas ***pagrindinis meniu*** su keturiomis pateiktomis pasirinkimo galimybėmis:
    * ***generuoti failus (g)*** - ši parinktis leidžia sukurti naujus duomenų failus;
    * ***nuskaityti duomenis iš failo (f)*** - ši parinktis leidžia nuskaityti jau egzistuojančius duomenų failus;
    * ***įvesti duomenis patiems (i)*** - šis pasirinkimas suteikia galimybę tiesiogiai įvesti duomenis;
    * ***atlikti veikimo greičio analizę (a)*** - ši parinktis leidžia inicijuoti programos veikimo greičio analizę.
    
Norint pasirinkti vieną iš šių parinkčių, ekrane reikia įvesti atitinkamą raidę ('g', 'f', 'i' arba 'a') ir paspausti "Enter". Programa po to atliks pasirinktą veiksmą.

2. Jei pasirenkama ***'g'*** raidė - ***failų generavimas***:
    * programa paprašys ***įvesti***, kiek ***namų darbų rezultatų*** norima generuoti studentams;
    * po to programa paprašys ***įvesti***, ***kiek studentų*** norima generuoti (galima įvesti konkretų norima skaičių arba įvesti 'visi', jei norima sugeneruoti (1000, 10000, 100000, 1000000, 10000000) tokio dydžio failus).
      
Įvedus šiuos duomenis, programa sugeneruos pasirinktą kiekį studentų su atsitiktiniais namų darbų ir egzamino rezultatais. Visi sugeneruoti duomenys bus išsaugoti į atskirus failus, kurių pavadinimai bus suformuluoti taip: ***'studentai_X.txt', kur X yra studentų skaičius***.

Programa informuos, kada failai buvo sėkmingai sukurti ir taip pat bus prirašytas jų sukūrimo laikas.

Galiausiai programa paklaus, ar norima grįžti į pagrindinį meniu ir pasirinkti kitą funkciją. Jei pasirenkama "Taip" (ekrane įvedama raidė 't') grįžtama į pagrindinį meniu, jei pasirenkama "NE" (ekrane įvedama raidė 'n') - programa baigia darbą.

3. Jei  pasirenkama ***'f'*** raidė - ***duomenų nuskaitymas iš failo***:
    * programa paprašys ***įvesti failo pavadinimą***, iš kurio norima nuskaityti duomenis (pvz. 'studentai.txt') (jei toks failas jau buvo apdorotas anksčiau, programa informuos, kad šis failas jau buvo apdorotas, ir paprašys pasirinkti kitą);
    * kai vartotojas įves tinkamą failo pavadinimą, programa nuskaitys duomenis iš nurodyto failo;
    * po to programa paprašys pasirinkti, ar ***galutinį balą*** norima skaičiuoti pagal ***vidurkį***, ar ***pagal medianą*** (ekrane reikia įvesti atitinkamą raidę ('v' arba 'm') ir paspausti "Enter");
    * įvedus šį pasirinkimą, programa ***parodys visų studentų duomenis*** (didėjimo tvarka pagal vardą ir pavardę), ***įskaitant jų galutinį balą***.
      
Po rezultatų išvedimo bus paklausta, ar norima nuskaityti kitą failą, jei pasirenkama "Taip" (ekrane įvedama raidė 't') bus prašoma įvesti tinkamą failo pavadinimą ir visi likusieji žingsniai vėl kartosis, o jei pasirenkama "NE" (ekrane įvedama raidė 'n'), darbas baigiamas su pasirinkta funkcija.

Galiausiai programa paklaus, ar norima grįžti į pagrindinį meniu ir pasirinkti kitą funkciją. Jei pasirenkama "Taip" (ekrane įvedama raidė 't') grįžtama į pagrindinį meniu, jei pasirenkama "NE" (ekrane įvedama raidė 'n') - programa baigia darbą.

4. Jei pasirenkama ***'i'*** raidė - ***įvesti duomenis patiems***:
    * programa paprašys ***įvesti***, ***kiek studentų*** norima įvesti;
    * tuomet programa ***paklaus***, ar norima ***generuoti atsitiktinius*** rezultatus, ar juos ***įvesti rankiniu būdu*** (ekrane reikia įvesti 't' - TAIP, jei norima geruoti arba 'n' - NE, jei norima įvesti rankiniu būdu);
    * jei pasirenkama ***generuoti atsitiktinius*** rezultatus, programa automatiškai sugeneruos namų darbų ir egzamino rezultatus kiekvienam studentui;
    * jei pasirenkama ***įvesti rankiniu būdu***, programa paprašys įvesti kiekvieno studento vardą, pavardę, namų darbų rezultatus (bent vieną) ir egzamino rezultatą.
    * įvedus visus duomenis, programa paprašys ***pasirinkti***, ar ***galutinį balą*** norima skaičiuoti pagal ***vidurkį***, ar pagal ***medianą*** (ekrane reikia įvesti atitinkamą raidę ('v' arba 'm') ir paspausti "Enter").
      
Įvedus šiuos duomenis programa ***parodys*** visų ***įvestų studentų duomenis*** (didėjimo tvarka pagal vardą ir pavardę) su jų ***galutiniais balais***.

Galiausiai programa paklaus, ar norima grįžti į pagrindinį meniu ir pasirinkti kitą funkciją. Jei pasirenkama "Taip" (ekrane įvedama raidė 't') grįžtama į pagrindinį meniu, jei pasirenkama "NE" (ekrane įvedama raidė 'n') - programa baigia darbą.

5. Jei pasirenka ***'a'*** raidė - ***atlikti veikimo greičio analizę***:
    * programa paprašys ***įvesti failo pavadinimą***, kurį norima analizuoti (pvz., 'studentai.txt');
    * po to programa paprašys ***pasirinkti***, ar ***galutinį balą*** skaičiuoti pagal ***vidurkį***, ar pagal ***medianą*** (ekrane reikia įvesti atitinkamą raidę ('v' arba 'm') ir paspausti "Enter");
    * tada programa paprašys pasirinkti ***rūšiavimo strategiją***:
      - 1 Strategija (du nauji konteineriai),
      - 2 Strategija (vienas naujas konteineris),
      - 3 Strategija (optimizuota),
      - 4 (Palyginti visas strategijas);
    * pasirinkus vieną iš strategijų, programa paklaus, kaip norima ***surūšiuoti studentus***:
      - 1 - pagal galutinį balą didėjimo tvarka,
      - 2 - pagal galutinį balą mažėjimo tvarka,
      - 3 - pagal vardą,
      - 4 - pagal pavardę,
      - 5 - pagal vardą ir pavardę;
      ir galiausiai įrašys studentus į du atskirus failus - ***"vargsiukai_X.txt"*** ir ***"galvociai_X.txt"***, kur X yra failo pavadinimas. Tuomet bus paklausta, ar norima nuskaityti kitą failą, jei pasirenkama "Taip" (ekrane įvedama raidė 't') bus prašoma įvesti tinkamą failo pavadinimą ir visi likusieji žingsniai vėl kartosis, o jei pasirenkama "NE" (ekrane įvedama raidė 'n'), darbas baigiamas su pasirinkta funkcija ir parodoma atliktos ***programos veikimo greičio analizės*** rezultatai:
      - failo sukūrimo,
      - duomenų nuskaitymo iš failo,
      - studentų rūšiavimą į dvi grupes (iš prieš tai sukurto failo),
      - surūšiuotų studentų išvedimą į du naujus failus (iš prieš tai sukurto failo).
    * jei pasirenkama "Palyginti visas strategijas", programa parodys visų ***strategijų rūšiavimo rezultatus***, bei ***užimamos atminties dydį***.

Galiausiai programa paklaus, ar norima grįžti į pagrindinį meniu ir pasirinkti kitą funkciją. Jei pasirenkama "Taip" (ekrane įvedama raidė 't') grįžtama į pagrindinį meniu, jei pasirenkama "NE" (ekrane įvedama raidė 'n') - programa baigia darbą.

#
## Kompiuteris ***(testavimo sistemos parametrai)***:
  - CPU - APPLE M2
  - RAM - 8 GB
  - SSD - 512 GB
# 

