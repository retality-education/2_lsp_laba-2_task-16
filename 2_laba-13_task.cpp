// Кертанов Виталий 2 крус 91 группа
//11. Создать класс BitString для работы с 64-битовыми строками. Битовая строка должна
//быть представлена двумя полями типа unsigned long int.Должны быть реализованы
//традиционные операции для работы с битами(and, or , xor, not).Реализовать сдвиг
//влево shiftLeft и сдвиг вправо shiftRight на заданное количество битов.

#include"BitString.h"


void correct(int& x, int left, int right, std::string message) {
	do {
		std::cout << message;
		std::cin >> x;
	} while (x < left || x > right);
}
int input()
{
	std::cout << "Выберите способ ввода\n1. Из консоли\n2. Из файла\n";
	int x;
	correct(x, 1, 2, "->");
	return x;
}

int output()
{
	std::cout << "Выберите способ вывода\n1. В консоль\n2. В файл\n";
	int x;
	correct(x, 1, 2, "->");
	return x;
}

std::string check_file()
{
	std::cout << "Введите имя файла без расширения\n->";
	std::string file;
	std::cin >> file;
	file = file + ".txt";
	std::ifstream ifile(file);
	if (ifile)
	{
		if (ifile.eof())
		{
			file = "error";
			ifile.close();
		}
	}
	else file = "error";
	return file;
}

short menu1()
{
	std::cout << "Выберете задачу:\n";
	std::cout << "1.Вывести битовую строку A\n";
	std::cout << "2.Вывести битовую строку B\n";
	std::cout << "3.Изменить битовую строку A\n";
	std::cout << "4.Изменить битовую строку B\n";
	std::cout << "5.Сравнить битовую строку A и с битовой строкой B\n";
	std::cout << "6.Выполнить операцию '&' между битовыми строками A и B\n";
	std::cout << "7.Выполнить операцию '|' между битовыми строками A и B\n";
	std::cout << "8.Выполнить операцию '^' между битовыми строками A и B\n";
	std::cout << "9.Выполнить операцию 'not' над объектом A\n";
	std::cout << "10.Выполнить операцию 'not' над объектом B\n";
	std::cout << "11.Выполнить операцию '<<' над объектром A\n";
	std::cout << "12.Выполнить операцию '<<' над объектром B\n";
	std::cout << "13.Выполнить операцию '>>' над объектром A\n";
	std::cout << "14.Выполнить операцию '>>' над объектром B\n";
	int choice;
	correct(choice, 1, 14, "->");
	return choice;
}





void end(bool& exit)
{
	std::cout << "\n1. Продолжить\n2. Завершить работу\n";
	int end;
	correct(end, 1, 2, "->");
	if (end == 2)
		exit = true;

}

void input_object(BitString& obj) {
	bool is_input{};

	if (!is_input)
	{
		int way{};
		do {
			std::cout << "1. Прочитать как бинарное число.\n 2. Прочитать как обычное число.\n";
			std::cin >> way;
		} while (way < 1 || way > 2);


		int start = input();
		if (start == 1)
			obj.input(way);
		else
		{
			std::string file = check_file();
			if (file == "error")
			{
				std::cout << "Файл не существует или пуст\n";
				is_input = false;
			}
			else
			{
				std::ifstream ifile(file);
				obj.inputFromFile(ifile, way);
				ifile.close();
			}
		}
	}
}
std::string task(BitString& A, BitString& B, int choice) {
	int n;
	std::string message;

	switch (choice)
	{
	case 1:
		message = A.to_string();
		break;
	case 2:
		message = B.to_string();
		break;
	case 3:
		input_object(A);
		break;
	case 4:
		input_object(B);
		break;
	case 5:
		message = "A > B =" + (A > B);
		break;
	case 6:
		message = "A & B =" + (A & B).to_string() + '\n';
		break;
	case 7:
		message = "A | B =" + (A | B).to_string() + '\n';
		break;
	case 8:
		message = "A ^ B =" + (A & B).to_string() + '\n';
		break;
	case 9:
		message = "not A = " + (~A).to_string() + '\n';
		break;
	case 10:
		message = "not B = " + (~B).to_string() + '\n';
		break;
	case 11:
		std::cout << " На сколько бит будем двигать строку A?\n";
		std::cin >> n;
		if (n < 0)
			throw std::runtime_error("Сдвиг на отрицальное колличество бит невозможен!");
		message = "Результаты побитового сдвига: A << " + std::to_string(n) + " = " + (A << n).to_string();
		break;
	case 12:
		std::cout << " На сколько бит будем двигать строку B?\n";
		std::cin >> n;
		if (n < 0)
			throw std::runtime_error("Сдвиг на отрицальное колличество бит невозможен!");
		message = "Результаты побитового сдвига: B << " + std::to_string(n) + " = " + (B << n).to_string();
		break;
	case 13:
		std::cout << " На сколько будем двигать строку A?\n";
		std::cin >> n;
		if (n < 0)
			throw std::runtime_error("Сдвиг на отрицальное колличество бит невозможен!");
		message = "Результаты побитового сдвига: A >> " + std::to_string(n) + " = " + (A >> n).to_string();
		break;
	case 14:
		std::cout << " На сколько будем двигать строку B?\n";
		std::cin >> n;
		if (n < 0)
			throw std::runtime_error("Сдвиг на отрицальное колличество бит невозможен!");
		message = "Результаты побитового сдвига: B >> " + std::to_string(n) + " = " + (B >> n).to_string();
		break;
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	bool exit{};
	BitString A{}, B{};

	bool is_input{};
	std::cout << "Далее введите две битовые строки A и B, следуя инструкциям ниже:\n";
	input_object(A);
	input_object(B);

	do
	{
		int choice = menu1();
		
		std::string message = "";

		message = task(A, B, choice);

		if (message != "")
		{
			int is_output = output();
			if (is_output == 2)
			{
				std::string file = check_file();
				if (file == "error")
				{
					std::cout << "Файл не существует или пуст\n";
					is_input = false;
				}
				else
				{
					std::ofstream ofile(file);
					ofile << message;
					ofile.close();
				}
			}
			else std::cout << message;
		}
		end(exit);

	} while (exit != true);

	return 0;
}