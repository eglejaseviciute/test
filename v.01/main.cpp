#include <iostream>
#include <vector>
#include <string>
#include <limits> // Naudojama cin klaidų tvarkymui

using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::numeric_limits;
using std::streamsize;

struct Studentas {
    string vardas;
    string pavarde;
    vector<int> namuDarbai;
    int egzaminas;
};

void ivestiStudenta(Studentas &studentas) {
    // Įvedame studento vardą ir pavardę:
    cout << "Įveskite studento vardą: ";
    cin >> studentas.vardas;
    cout << "Įveskite studento pavardę: ";
    cin >> studentas.pavarde;

    // Įvedame namų darbų rezultatus ir tikriname klaidas:
    cout << "Įveskite namų darbų rezultatus (įveskite -1, kai norėsite baigti):" << endl;
    int rezultatas;
    while (true) {
        cin >> rezultatas;

        // Patikriname, ar įvesta reikšmė yra skaičius
        if (cin.fail()) {
            cin.clear(); // Išvalome klaidos būseną
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Praleidžiame neteisingą įvestį
            cout << "Klaida! Prašome įvesti skaičių: ";
        } else if (rezultatas == -1) {
            // Baigiame įvesti, kai įrašoma -1
            break;
        } else {
            studentas.namuDarbai.push_back(rezultatas); // Pridedame rezultatą į vektorių
        }
    }

    // Įvedame egzamino rezultatą:
    cout << "Įveskite egzamino rezultatą: ";
    while (!(cin >> studentas.egzaminas)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Klaida! Prašome įvesti skaičių: ";
    }
    cout << endl;
}

void spausdintiStudenta(const Studentas &studentas) {
    // Spausdiname įvestus studento duomenis:
    cout << "Studentas: " << studentas.vardas << " " << studentas.pavarde << endl;

    // Spausdiname namų darbų rezultatus:
    cout << "Namų darbų rezultatai: ";
    for (int nd : studentas.namuDarbai) {
        cout << nd << " ";
    }
    cout << endl;

    // Spausdiname egzamino rezultatą:
    cout << "Egzamino rezultatas: " << studentas.egzaminas << endl;
}

int main() {
    int studentuSkaicius;
    cout << "Kiek studentų norite įvesti? ";
    cin >> studentuSkaicius;

    vector<Studentas> studentai(studentuSkaicius);

    for (int i = 0; i < studentuSkaicius; ++i) {
        cout << "Įveskite " << i+1 << "-ojo studento duomenis:" << endl;
        ivestiStudenta(studentai[i]);
    }

    for (int i = 0; i < studentuSkaicius; ++i) {
        cout << i+1 << "-ojo studento duomenys:" << endl;
        spausdintiStudenta(studentai[i]);
    }

    return 0;
}
