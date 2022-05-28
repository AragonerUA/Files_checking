#pragma once

#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>
#include <vector>
namespace func {
    class functions {
    private:
        std::string file_name;
        std::string key;
        std::ifstream file;
        std::string result;
        std::string words;
        bool isopen = 0;
        std::vector<std::string> vect_words;
        int vw_size;
        std::vector<std::string> vect_strings;
        std::ifstream fite;
        int vs_size;
        bool ch_words = 1;
        bool ch_strings = 1;
    public:
        //конструкторы
        functions() = default;
        functions(std::string &name);
//        void writeFilename(std::string name);
        //функции соответствующие условию
        void open(std::string &name);
        void close();
        std::string getFilename(std::string name) const;
        bool isOpen() const;
        bool CheckEndFile();
        std::string nextStr(std::string &file_name, int counter, bool fl);
        std::string nextWord(std::string &file_name, int counter, bool fl);
};
}
//меню
namespace for_menu {
    class menu {
    public:
        menu() = default;
        menu (std::string name);
        static void print_menu();
        static void neeed(std::string file_name);
    };
}
