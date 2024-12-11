#include <iostream>
using namespace std;

bool groeßerAlsX(double numberArray[], int length, double x);
int groeßerAlsXAnzahl(double numberArray[], int length, double x);
bool twoArraysSameNumbers(int numberArray1[], int numberArray2[], int length1, int length2);
int wieOftTeilInVoll(string voll, string teil);
int wieOftStringInArray(string stringArray[], int length, string wort);
int zahlenGroesserAlsImAnderenArray(int numberArray1[], int numberArray2[], int length1, int length2);

int main() {
    double x = 4.0;
    const int length = 5;
    double numberArray[length] = { 1.5, 2.3, 0.7, 4.1, 4.2 };
    const int length1 = 5;
    const int length2 = 5;
    int numberArray1[length1] = { 1, 2, 3, 4, 5 };
    int numberArray2[length2] = { 1, 2, 2, 100, 50 };
    int numberArray3[length2] = { 3, 4, 6, 8, 9 };
    string voll = "vollvollvol";
    string teil = "vol";
    string stringArray[length] = {"voll","vol","vollvollvol","volllovol","ende"};
    string wort = "vol";
    cout << "Funktion a): Ist x im Array: " << groeßerAlsX(numberArray, length, x) << endl;
    cout << "Funktion b): Anzahl der Zahlen groesser als " << x << ": " << groeßerAlsXAnzahl(numberArray, length, x) << endl;
    cout << "Funktion c): Sind die ersten drei Zahlen in beiden Arrays gleich: " << twoArraysSameNumbers(numberArray1, numberArray2, length1, length2) << endl;
    cout << "Funktion d): Wie oft ist der Teil string im Voll string: " << wieOftTeilInVoll(voll, teil) << endl;
    cout << "Funktion e): Wie oft kommt string vollstaendig oder teilweise im array vor: " << wieOftStringInArray(stringArray, length, wort) << endl;
    cout << "Funktion f): Wie oft gibt es eine groessere zahl in array2 als in array1: " << zahlenGroesserAlsImAnderenArray(numberArray1, numberArray2, length1, length2) << endl;
    return 0;
}

bool groeßerAlsX(double numberArray[], int length, double x) { //Aufgabe a
    for (int i = 0; i < length; i++) {
        if (numberArray[i] > x) {
            return true;
        }
    }
    return false;
}

int groeßerAlsXAnzahl(double numberArray[], int length, double x) { //Aufgabe b
    int counter = 0;
    for (int i = 0; i < length; i++) {
        if (numberArray[i] > x) {
            counter++;
        }
    }
    return counter;
}

bool twoArraysSameNumbers(int numberArray1[], int numberArray2[], int length1, int length2) { //Aufgabe c
    if (length1 < 3 || length2 < 3) {
        return false;
    }

    for (int i = 0; i < 3; i++) {
        if (numberArray1[i] != numberArray2[i]) {
            return false;
        }
    }
    return true;
}

int wieOftTeilInVoll(string voll, string teil) {//Aufgabe d
    int summe = 0;
    if (teil.size() > voll.size()) {
        cout << "Der teil string darf nicht groesser als der Voll string sein" << endl;
    }

    else {
        for (int i = 0; i <= voll.size(); i++) {
            if (voll.substr(i, teil.size()) == teil) {

                summe++;
            }
        }
    }
    return summe;
}

int wieOftStringInArray(string stringArray[], int length, string wort) {//Aufgabe e
    int summe = 0;
    for (int i = 0; i < length; i++) {
        summe += wieOftTeilInVoll(stringArray[i], wort);
    }
    return summe;
}

int zahlenGroesserAlsImAnderenArray(int numberArray1[], int numberArray2[], int length1, int length2) {//Aufgabe f
    //zahlen im array 2 die größer als alle zahlen im array
    int counterAußen = 0;
    for (int i = 0; i < length2; i++) {
        int counterInnen = 0;

        for (int j = 0; j < length1; j++) {
            if (numberArray1[j] < numberArray2[i]) {
                counterInnen++;
            }
        }
        if (counterInnen == length2) {
            counterAußen++;
        }
    }
    return counterAußen;
}