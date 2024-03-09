Seuraavassa esimerkissä funktio rivi(n,c) tulostaa rivin, jossa on n kertaa merkki c, ja funktio rivi(n) tulostaa rivin, jossa on n tähteä. Jälkimmäinen funktio on toteutettu ensimmäisen erikoistapauksena.

```c++
void rivi(int n, char c) {
    for (int i = 1; i <= n; i++) {
        cout << c;
    }
    cout << "\n";
}

void rivi(int n) {
    rivi(n,'*');
}

int main() {
    rivi(5); // *****
    rivi(5,'@'); // @@@@@
}
```

Goto-komento \
Vielä yksi tapa vaikuttaa ohjelman suoritukseen on komento goto, joka hyppää toisaalla koodissa olevaan nimiöön (label). Esimerkiksi seuraavassa koodissa komento goto hyppää nimiöön loppu.

```c++
goto loppu;
cout << "apina\n";
cout << "banaani\n";
loppu:
cout << "cembalo\n";

_______
cembalo
```

If shorthandejä
```c++
if (x == 4) {
    x = 2
} elsle {
    x = 1
}

if (x == 4=)
    x = 2
else
    x = 1

x = x == 4 ? 2 : 4
```

Bittioperaatiot

```c++
int a = 26, b = 19;
cout << (a&b) << "\n"; // 18
cout << (a|b) << "\n"; // 27
cout << (a^b) << "\n"; // 9
11111111 11111111 11111111 11011010 = ~37 = -38 //Not by bit
>> / << On bitshiftejä
```

| tyyppi    | tavallinen koko | tavallinen alaraja | tavallinen yläraja |
|-----------|-----------------|--------------------|--------------------|
| char      | 8 bittiä        | –27 = –128         | 27–1 = 127         |
| short     | 16 bittiä       | –215 = –32768      | 215–1 = 32767      |
| int       | 32 bittiä       | –231 ≈ –2 · 109    | 231–1 ≈ 2 · 109    |
| long      | 64 bittiä       | –263 ≈ –9 · 1018   | 263–1 ≈ 9 · 1018   |
| long_long | 64 bittiä       | –263 ≈ –9 · 1018   | 263–1 ≈ 9 · 1018   |

Osa 11 Jäin