#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>
#include <vector>
#include "Sec_Lab_header.h"

int main() {

    std::string random;
    std::cout << "Введите название Вашего файла. Помните, что он должен быть в формате .txt: ";
    std::cin >> random;

    for_menu::menu::neeed(random);

}
