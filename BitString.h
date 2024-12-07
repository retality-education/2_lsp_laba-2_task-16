
#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>

class BitString {
private:
    unsigned long part1; // Первые 32 бита
    unsigned long part2; // Остальные 32 бита

public:
    BitString(); // Конструктор по умолчанию
    BitString(unsigned long p1, unsigned long p2); // Конструктор с параметрами

    BitString& operator =(const BitString& other); // Оператор присваивания
    BitString operator &(const BitString& t) const; // Оператор AND
    BitString operator |(const BitString& t) const; // Оператор OR
    BitString operator ^(const BitString& t) const; // Оператор XOR
    BitString operator ~() const; // Оператор NOT
    BitString operator <<(int n) const; // Сдвиг влево
    BitString operator >>(int n) const; // Сдвиг вправо

    void print() const; // Вывод битов

    void input(int way); // Ввод объекта с клавиатуры
    void inputFromFile(std::ifstream& file, int way); // Ввод объекта из файла
    void output(std::ostream& os) const; // Вывод объекта в поток
    std::string to_string() const; // Преобразование в строку

    bool operator ==(const BitString& other) const; // Оператор равенства
    std::strong_ordering operator <=> (const BitString& other) const; // Оператор тройного сравнения
    bool operator !=(const BitString& other) const; // Оператор неравенства
};
