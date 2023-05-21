#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//C++ Code zur vereinfachten Simulation einer Dateiverschlüsselung, angelehnt an die Ryuk Ransomware

// Funktion zur Verschlüsselung des Datei Inhalts mit einer einfachen XOR Verschlüsselung
string encryptFile(const string& text, const string& key) {
    string encryptedText = text;
    for (size_t i = 0; i < text.length(); i++) {
        encryptedText[i] = text[i] ^ key[i % key.length()];
    }
    return encryptedText;
}

int main() {

    //Defintion der Eingabe und Ausgabedatei
    string inputFile = "test.txt";
    string outputFile = "encrypted.txt";
    string key = "snldcnirhnlcsdihcirnl<dhir"; //Verschlüsselungskey für diese XOR Verschlüsselung

    //Öffnen der Eingabedatei
    ifstream inputStream(inputFile);
    if (!inputStream) {
        cout << "Fehler beim Öffnen der Eingabedatei!" << endl;
        return 1;
    }

    //Öffnen der Ausgabedatei
    ofstream outputStream(outputFile);
    if (!outputStream) {
        cout << "Fehler beim Öffnen der Ausgabedatei!" << endl;
        return 1;
    }

    // Den gesamten Inhalt der Eingabedatei einlesen
    string fileContent((istreambuf_iterator<char>(inputStream)), (istreambuf_iterator<char>()));

    inputStream.close();

    // Verschlüsselung des Datei Inhalts
    string encryptedContent = encryptFile(fileContent, key);

    // Speichern des verschlüsselten Texts in der Ausgabedatei
    outputStream << encryptedContent;

    outputStream.close();

    cout << "Der Text wurde erfolgreich verschlüsselt und in die Datei gespeichert!" << endl;

    return 0;
}
