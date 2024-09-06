#include <iostream> 
#include <fstream> 
#include <string> 
using namespace std;


bool isFileOpen{ false }, isFileEmpty{ true };

void decrypt(string textFileName) {
    float freqCountInText[26];
    string initialText, decryptedText, alphabet{ "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
    ifstream inTextFile(textFileName);
    getline(inTextFile, initialText);
    decryptedText = initialText;
    float freqCount;
    unsigned short shiftValue, temp{ 0 };
    if (inTextFile.is_open()) {
        isFileOpen = true;
        if ((inTextFile.peek() == std::ifstream::traits_type::eof()) == false || initialText.length() > 1) {
            isFileEmpty = false;
            for (unsigned short i = 0; i < 26; ++i) {
                freqCount = 0;
                for (unsigned short j = 0; j < decryptedText.length(); ++j) {
                    if (static_cast<int>(decryptedText[j]) >= 97 && static_cast<int>(decryptedText[j]) <= 122) {
                        decryptedText[j] = toupper(decryptedText[j]);
                    }
                    if (decryptedText[j] == alphabet[i]) {
                        freqCount = freqCount + 1;
                    }
                }
                freqCount = (freqCount * 100) / decryptedText.length();
                freqCountInText[i] = freqCount;
            }
            for (unsigned short i = 0; i < 26; ++i) {
                if (freqCountInText[i] > freqCountInText[0]) {
                    freqCountInText[0] = freqCountInText[i];
                    temp = i;
                }
            }
            shiftValue = abs(4 - temp);
            for (unsigned short i = 0; i < decryptedText.length(); ++i) {
                if (isalpha(decryptedText[i])) {
                    decryptedText[i] = ((decryptedText[i] - shiftValue - 'A' + 26) % 26) + 'A';
                    if (static_cast<int>(initialText[i]) >= 97 && static_cast<int>(initialText[i]) <= 122) {
                        decryptedText[i] = tolower(decryptedText[i]);
                    }
                }
            }
            inTextFile.close();
            ofstream outTextFile(textFileName);
            if (outTextFile.is_open()) {
                outTextFile << decryptedText;
                outTextFile.close();
            }
        }
    }
}

int main() {
    string textFileName;
    unsigned short operationSelection;
    cout << "Введите наименование текстового файла. ";
    cin >> textFileName;
    cout << "Выберите способ работы программы. 1 - шифрование, 2 - дешифрование. ";
    do {
        cin >> operationSelection;
        if (operationSelection < 1 ||
            operationSelection > 2) {
            cout << "\nОшибка ввода. Попробуйте еще раз: ";
        }
    } while (operationSelection < 1 || operationSelection > 2);
    if (operationSelection == 1) {
        unsigned short shiftValue;
        cout << "Введите сдвиг ";
        cin >> shiftValue;
        encrypt(textFileName, shiftValue);
        if (isFileOpen == false) {
            cout << "Ошибка - файл не открылся";
        }
        if (isFileOpen == true && isFileEmpty == true) {
            cout << "Ошибка - файл пустой";
        }
    }
    else {
        decrypt(textFileName);
        if (isFileOpen == false) {
            cout << "Ошибка - файл не открылся";
        }
        if (isFileOpen == true && isFileEmpty == true) {
            cout << "Ошибка - файл пустой";
        }
    }
}
