#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <math.h>
using namespace std;
bool isPrime(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

// Returns greatest common divisor of two integers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

string encoded(string text,int e,int d,int n) {
    string cipher;
    for (int i = 0; i < text.length(); i++) {
        int c = text[i];
        double p = pow(c, e);
        int encoded = (int)p % n;
        cipher += to_string(encoded) + " ";
    }
    return cipher;
}
string decoded(string cipher, int d, int n) {
    string decodedmsg;
    int j = 0;
    while (j < cipher.length()) {
        string num;
        while (isdigit(cipher[j])) {
            num += cipher[j];
            j++;
        }
        if (num != "") {
            int c = stoi(num);
            double p = pow(c, d);
            int decoded_char = (int)p % n;
            decodedmsg += (char)decoded_char;
        }
        j++;
    }
    return decodedmsg;

}

int main() {
    
    srand(time(NULL));

    int p = rand() % 100 + 1; 
    while (!isPrime(p)) 
        p = rand() % 100 + 1;



    int q = rand() % 100 + 1;
    while (!isPrime(q))
        q = rand() % 100 + 1;


    cout << "p = " << p << endl;
    cout << "q = " << q << endl;

    int n = p * q;
    int phi_n = (p - 1) * (q - 1);
    cout << "n = " << n << endl;
    cout << "phi(n) = " << phi_n << endl;

    int e = 2;
    while (gcd(e, phi_n) != 1) 
        e++;
    int d = 1;
    while ((d * e) % phi_n != 1) 
        d++;
    cout << "e = " << e << endl;
    cout << "d = " << d << endl;

   
    string text;
    cout << "Enter a text message: ";
    getline(cin, text);
    string cipher=encoded(text,e,d,n);
    cout << "Encoded message: " << cipher << endl;

   
    string decodedmsg = decoded(cipher, d, n);
    
    cout << "Decoded message: " << decodedmsg << endl;

    return 0;
    //ayat dardouk
    //kinanah abueideh
    //nehaya 
}