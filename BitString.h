
#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>

class BitString {
private:
    unsigned long part1; // ������ 32 ����
    unsigned long part2; // ��������� 32 ����

public:
    BitString(); // ����������� �� ���������
    BitString(unsigned long p1, unsigned long p2); // ����������� � �����������

    BitString& operator =(const BitString& other); // �������� ������������
    BitString operator &(const BitString& t) const; // �������� AND
    BitString operator |(const BitString& t) const; // �������� OR
    BitString operator ^(const BitString& t) const; // �������� XOR
    BitString operator ~() const; // �������� NOT
    BitString operator <<(int n) const; // ����� �����
    BitString operator >>(int n) const; // ����� ������

    void print() const; // ����� �����

    void input(int way); // ���� ������� � ����������
    void inputFromFile(std::ifstream& file, int way); // ���� ������� �� �����
    void output(std::ostream& os) const; // ����� ������� � �����
    std::string to_string() const; // �������������� � ������

    bool operator ==(const BitString& other) const; // �������� ���������
    std::strong_ordering operator <=> (const BitString& other) const; // �������� �������� ���������
    bool operator !=(const BitString& other) const; // �������� �����������
};
