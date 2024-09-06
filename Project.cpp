#include <iostream> 
#include <fstream> 
#include <string> 
using namespace std;

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
