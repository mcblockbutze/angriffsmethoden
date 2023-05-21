#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Funktion zur Verschlüsselung des Textinhalts mit XOR
string encryptText(const string& text, const string& key) {
    string encryptedText = text;
    for (size_t i = 0; i < text.length(); i++) {
        encryptedText[i] = text[i] ^ key[i % key.length()];
    }
    return encryptedText;
}

int main() {
    string inputFile = "test.txt";
    string outputFile = "encrypted.txt";
    string key = "encryptionkey";  // Schlüssel für die XOR-Verschlüsselung

    ifstream inputStream(inputFile);
    if (!inputStream) {
        cout << "Fehler beim Öffnen der Eingabedatei!" << endl;
        return 1;
    }

    ofstream outputStream(outputFile);
    if (!outputStream) {
        cout << "Fehler beim Öffnen der Ausgabedatei!" << endl;
        return 1;
    }

    // Den gesamten Inhalt der Eingabedatei einlesen
    string fileContent((istreambuf_iterator<char>(inputStream)), (istreambuf_iterator<char>()));

    inputStream.close();

    // Verschlüsselung des Textinhalts
    string encryptedContent = encryptText(fileContent, key);

    // Speichern des verschlüsselten Texts in der Ausgabedatei
    outputStream << encryptedContent;

    outputStream.close();

    cout << "Der Text wurde erfolgreich verschlüsselt und in die Datei gespeichert!" << endl;

    return 0;
}
