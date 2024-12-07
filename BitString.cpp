#include "BitString.h"

// ����������� �� ���������
BitString::BitString() : part1(0), part2(0) {}

// ����������� � �����������
BitString::BitString(unsigned long p1, unsigned long p2) : part1(p1), part2(p2) {}

// �������� ������������
BitString& BitString::operator =(const BitString& other) {
    if (this != &other) { // �������� �� ����������������
        part1 = other.part1;
        part2 = other.part2;
    }
    return *this;
}

// �������� AND
BitString BitString::operator &(const BitString& t) const {
    return BitString(part1 & t.part1, part2 & t.part2);
}

// �������� OR
BitString BitString::operator |(const BitString& t) const {
    return BitString(part1 | t.part1, part2 | t.part2);
}

// �������� XOR
BitString BitString::operator ^(const BitString& t) const {
    return BitString(part1 ^ t.part1, part2 ^ t.part2);
}

// �������� NOT
BitString BitString::operator ~() const {
    return BitString(~part1, ~part2);
}

// �������� ������ �����
BitString BitString::operator <<(int n) const {
    if (n < 32) {
        return BitString((part1 << n) | (part2 >> (32 - n)), part2 << n);
    }
    else if (n < 64) {
        return BitString(0, part1 << (n - 32));
    }
    else {
        return BitString(0, 0);
    }
}

// �������� ������ ������
BitString BitString::operator >>(int n) const {
    if (n < 32) {
        return BitString(part1 >> n, (part2 >> n) | (part1 << (32 - n)));
    }
    else if (n < 64) {
        return BitString(part1 >> (n - 32), 0);
    }
    else {
        return BitString(0, 0);
    }
}


// ����� ����� �� �����
void BitString::print() const {
    for (int i = 31; i >= 0; --i) { // ������� ����� 1
        std::cout << ((part1 >> i) & 1);
    }
    for (int i = 31; i >= 0; --i) { // ������� ����� 2
        std::cout << ((part2 >> i) & 1);
    }
    std::cout << std::endl;
}

// ���� ������� � ����������
void BitString::input(int way) {

    std::string s1, s2;
    if (way == 1)
    {
        std::cout << "������� ��� �������� ������ ����� enter: ";
        std::cin >> s1 >> s2;
        part1 = stoi(s1, 0, 2);
        part2 = stoi(s2, 0, 2);
    }
    else
        std::cin >> part1 >> part2;
}

// ���� ������� �� �����
void BitString::inputFromFile(std::ifstream& file, int way) {
    std::string s1, s2;
    if (way == 1)
    {
        file >> s1 >> s2;
        part1 = stoi(s1, 0, 2);
        part2 = stoi(s2, 0, 2);
    }
    else
        file >> part1 >> part2;
}

// ����� ������� � �����
void BitString::output(std::ostream& os) const {
    os << "Part1: " << part1 << ", Part2: " << part2;
}

// �������������� � ������
std::string BitString::to_string() const {
    std::string result;

    // ���������� ����� �� part1
    for (int i = 31; i >= 0; --i) {
        result += ((part1 >> i) & 1) ? '1' : '0';
    }

    // ���������� ����� �� part2
    for (int i = 31; i >= 0; --i) {
        result += ((part2 >> i) & 1) ? '1' : '0';
    }

    return result;
}

// �������� ���������
bool BitString::operator ==(const BitString& other) const {
    return part1 == other.part1 && part2 == other.part2;
}

// �������� �������� ��������� (<=>)
std::strong_ordering BitString::operator<=>(const BitString& other) const
{
    if (part1 != other.part1)
        return part1 <=> other.part1;

    return part2 <=> other.part2;
}



// �������� �����������
bool BitString::operator !=(const BitString& other) const {
    return !(*this == other);
}