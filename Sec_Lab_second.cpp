#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Sec_Lab_header.h"

namespace for_menu {
menu::menu(std::string name) { //name = random = need.txt
    reverse(name.begin(), name.end());
    if (name.size() > 4) {
        if (name[0] == 't' && name[1] == 'x' && name.at(2) == 't' &&
            name.at(3) == '.') {
            std::cout << "Название файла корректно! Имя файла записано."
                      << std::endl;

        } else {
            std::cerr << "Ошибка формата файла!" << std::endl;
            exit(0);
        }
    } else {
        std::cout << "Название файла некорректно!" << std::endl;
        exit(0);
    }
};

void menu::print_menu() {
    std::cout << "Ввод      open - открытие Вашего файла" << std::endl;
    std::cout << "Ввод     close - закрытие Вашего файла" << std::endl;
    std::cout << "Ввод  get_name - получить имя файла" << std::endl;
    std::cout << "Ввод     check - проверка, открыт ли Ваш файл" << std::endl;
    std::cout << "Ввод check_end - проверка, закончился ли Ваш файл"
              << std::endl;
    std::cout << "Ввод  take_str - получить следующую строку из файла"
              << std::endl;
    std::cout << "Ввод take_word - получить следующее слово из файла"
              << std::endl;
    std::cout << "Ввод print_menu - вывести меню снова" << std::endl;
    std::cout << "Ввод       exit - выход из программы" << std::endl;
}

    void menu::neeed(std::string file_name) {
        int counter_words = 0;
        bool flag_word = 1;
        int counter_str = 0;
        bool flag_str = 1;
        bool isClosed = 0;

        //записываем имя файла во внутреннюю переменную
        func::functions need_2(file_name);
//        need_2(file_name);
//        need_2.writeFilename(file_name);

        //вызываем конструктор от string
        for_menu::menu need(file_name);

        //выводим меню
        need.print_menu();

        //переходим к функциям
        func::functions need_second(file_name);
        while(true) {
            std::string commands;
            std::cout << "Введите команду: ";
            std::cin >> commands;
            if (commands == "open") {
                need_second.open(file_name);
                isClosed = 0;
            }
            else if (commands == "close") {
                need_second.close();
                isClosed = 1;
            }
            else if (commands == "get_name") {
                std::cout << "Имя файла: " << need_second.getFilename(file_name) << std::endl;
            }
            else if (commands == "check") {
                if (need_second.isOpen() == 1) {
                    std::cout << "Проверка пройдена успешно! Файл открыт!" << std::endl;
                }
                else {
                    std::cout << "Файл не открыт!" << std::endl;
                }
            }
            else if (commands == "check_end") {
                if (need_second.CheckEndFile() == 0) {
                    std::cout << "Файл закончился либо Вы не работаете с файлом!" << std::endl;
                }
                else {
                    std::cout << "Файл не закончился! " << std::endl;
                }
//                need_second.CheckEndFile(file_name);
            }
            else if (commands == "take_word") {
//            int counter_words;
                std::cout << need_second.nextWord(file_name, counter_words, flag_word) << std::endl;
                counter_words++;
                flag_word = 0;
            }
            else if (commands == "take_str") {
                std::cout << need_second.nextStr(file_name, counter_str, flag_str) << std::endl;
                counter_str++;
                flag_str = 0;
            }
            else if (commands == "print_menu") {
                need.print_menu();
            }
            else if (commands == "exit") {
//            std::cout << "Выходим из программы...";
                if (isClosed == 0) {
                    std::cout << "Ваш файл еще не закрыт. Это нехорошо. Мы закроем его за Вас." << std::endl;
                    need_second.close();
                    std::cout << "Выходим из программы...";
                }
                else {
                    std::cout << "Выходим из программы...";
                }
                break;
            }
        }
    }
};  // namespace for_menu

namespace func {

functions::functions(std::string &name) {
    key = "/Users/user/CLionProjects/ITMO/" + name;
}

//Записываем пользовательское имя файла
//void functions::writeFilename(std::string name) {
//    key = "/Users/user/CLionProjects/ITMO/" + name;
//}
//Открываем файл
void functions::open(std::string &file_name) {
//    key = "/Users/user/CLionProjects/ITMO/" + name;
//    std::ifstream file(file_name);
    file.open(key);

    std::cout << "key = " << key << std::endl;

//
    //fite = std::ifstream(file_name);
//    file = std::ifstream(file_name);

    if (file.is_open()) {
        std::cout << "Файл открыт успешно!" << std::endl;
        isopen = true;
    } else {
        std::cerr << "Ошибка открытия файла! В данной директории не существует "
                     "такого файла!";
        exit(-1);
    }
}
//Закрываем файл
void functions::close() {
    if (isopen == 1) {
        file.close();
        std::cout << "Файл успешно закрыт!" << std::endl;
        isopen = 0;
    } else {
        std::cerr << "Ошибка закрытия файла!" << std::endl;
        exit(-1);
    }
}
//Выводим имя файла
std::string functions::getFilename(std::string name) const {
    if (isopen == 0) {
        return "Вы не работаете с файлом!
";
    }
    else {
        return name;
    }
}
//Проверка на открытость

bool functions::isOpen() const {
    if (isopen == 1) {
        return 1;
    }
    else {
        return 0;
    }
}
//Проверка на конец файла
bool functions::CheckEndFile() {
    if (isopen == 1) {
        if (file.eof() || ch_strings == 0 || ch_words == 0) {
            return 0;
        }
        else {
            return 1;
        }
    }
    else {
        return 0;
    }
}
//следующая строка из файла
std::string functions::nextStr(std::string &file_name, int counter, bool fl) {
    if (isopen == 1) {
//        std::ifstream myfile(file_name);
        std::string res_str;
        if (fl == 1) {
            do {
                std::getline(file, res_str);
                vect_strings.push_back(res_str);
            } while (!file.eof());
            vs_size = vect_strings.size();
        }
        if (counter < vs_size) {
            return vect_strings[counter];
        }
        else {
            ch_strings = 0;
            return "В файле больше нет строк!
";
        }
    }
    else {
        return "Вы не работаете с файлом!
";
    }
}
//Следующее слово из файла
std::string functions::nextWord(std::string &file_name, int count, bool fl) {
    if (isopen == 1) {
//        std::ifstream myfile(file_name);
        std::string res;

        if (fl == 1) {
            do {
                fite >> res;
                vect_words.push_back(res);
            } while (!fite.eof());
            vw_size = vect_words.size();
        }
        if (count < vw_size) {
            return vect_words[count];
        }
        else {
            ch_words = 0;
            return "В файле больше нет слов!
";
//            ch_words = 0;
        }
    }
    else {
        return "Вы не работаете с файлом!
";
    }
}
};  // namespace func
