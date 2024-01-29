/*/#include <iostream>
#include<string>
using namespace std;
void main() {
	string str;
	cin >> str;
	int size = str.length();
	int **asc = new *int[size];
	for (int i = 0; i < size; ++i)
		asc[i] = new int[8];

	for (int i = 0;i <= str.length();i++)
		asc[i][j] = int(str[i]);

	for (int i = 0;i <= str.length();i++)
		cout << asc[i] << endl;

}*/
#include <iostream>
#include <bitset>
#include <string>
using namespace std;

// Define the Feistel cipher function
string feistel(string text, bitset<4> key) {
    // Convert text to binary string
    string binary_text;
    for (char& c : text) {
        binary_text += bitset<8>(c).to_string();
    }

    // Split binary text into two halves
    string left_half = binary_text.substr(0, binary_text.length() / 2);
    string right_half = binary_text.substr(binary_text.length() / 2);

    // Run the Feistel cipher for the specified number of loops
    for (int i = 0; i < 16; i++) {
        // Generate the key for this round by taking the NOT operation on the key
        bitset<4> round_key = ~key;

        // XOR the right half with the round key
        bitset<32> round_result(right_half);
        for (int j = 0; j < 4; j++) {
            round_result ^= (round_key[j] << (j * 8 + 4));
        }

        // Swap the left and right halves
        string temp = left_half;
        left_half = right_half;
        right_half = round_result.to_string().substr(0, 32 - left_half.length());

        // Set the key for the next round to the original key
        key = round_key;
    }

    // Concatenate the left and right halves and convert back to text
    string binary_result = left_half + right_half;
    string result;
    for (int i = 0; i < binary_result.length(); i += 8) {
        result += static_cast<char>(bitset<8>(binary_result.substr(i, 8)).to_ulong());
    }

    return result;
}

int main() {
    // Read in the text and key from the user
    string text;
    cout << "Enter text: ";
    getline(cin, text);

    bitset<4> key;
    cout << "Enter key (4 bits): ";
    cin >> key;

    // Run the Feistel cipher with 16 loops and print the result
    string result = feistel(text, key);
    cout << "Result: " << result << endl;

    return 0;
}