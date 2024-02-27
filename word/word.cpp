// word.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <Windows.h>
#include <random>

using namespace std;


string reverseWord(string word) {
    reverse(word.begin(), word.end());
    return word;
}

bool isVowel(char c) {

    if (c == 'а' || c == 'е' || c == 'ё' || c == 'и' || c == 'о' || c == 'у' || c == 'ы' || c == 'э' || c == 'ю' || c == 'я') {
        return true;
    }
    else {
        return false;
    }
}

string removeVowels(string word) {
    string result;
    for (char c : word) {
        if (isVowel(c)) {
            continue;
        }
        else
        {
            result += c;
        }
    }
    return result;
}


string removeConsonants(string word) {
    string result;
    for (char c : word) {
        if (isVowel(c)) {
            result += c;
        }
    }
    return result;
}

string shuffleWord(string word) {
    random_device rd;
    mt19937 g(rd());
    shuffle(word.begin(), word.end(), g);
    return word;

}

int main()
{
    setlocale(LC_ALL, "RUS");

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    while (true) {
        string word;
        cout << "Введите слово: ";
        cin >> word;

        int choice;
        cout << "Выберите действие:\n1. reverse\n2. removeVowels\n3. removeConsonants\n4. shuffle\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Результат: " << reverseWord(word) << endl;
            break;
        case 2:
            cout << "Результат: " << removeVowels(word) << endl;
            break;
        case 3:
            cout << "Результат: " << removeConsonants(word) << endl;
            break;
        case 4:
            cout << "Результат: " << shuffleWord(word) << endl;
            break;
        default:
            cout << "Некорректный выбор действия.\n";
            break;
        }
    }

    return 0;



}