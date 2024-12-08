// Кертанов Виталий 2 крус 91 группа
//11. Создать класс BitString для работы с 64-битовыми строками. Битовая строка должна
//быть представлена двумя полями типа unsigned long int.Должны быть реализованы
//традиционные операции для работы с битами(and, or , xor, not).Реализовать сдвиг
//влево shiftLeft и сдвиг вправо shiftRight на заданное количество битов.

#include"BitString.h"

//Начало: Определение сигнатур методов
void correct(int& x, int left, int right, std::string message);

// Меню и действия с ним
short menu();
int how_much_should_the_value_be_shifted(const std::string& message);
std::string complete_chosen_action(BitString& A, BitString& B, int choice);
void end_menu(bool& exit);

//Ввод и его обработка
std::string check_file();
int input();
void input_object(BitString& obj);	
void input_start_value_of_objs(BitString& A, BitString& B);

//Вывод и его обработка
int choose_output_way();
void output_result(std::string& message);
//Конец: Определение сигнатур методов


//метод проверки на корректность вводимых значений
void correct(int& x, int left, int right, std::string message) {
	do {
		std::cout << message;
		std::cin >> x;
	} while (x < left || x > right);
}



// Начало: Меню и действия с ним
short menu()
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
int how_much_should_the_value_be_shifted(const std::string& message) {
	int n;
	std::cout << message << '\n';
	std::cin >> n;
	if (n < 0)
		throw std::runtime_error("Сдвиг на отрицальное колличество бит невозможен!");
	return n;
}
std::string complete_chosen_action(BitString& A, BitString& B, int choice) {
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
		message = "A > B = ";
		message += (A > B) ? "True" : "False";
		break;
	case 6: 
		message = "A & B = " + (A & B).to_string() + '\n';
		break;
	case 7:
		message = "A | B = " + (A | B).to_string() + '\n';
		break;
	case 8:
		message = "A ^ B = " + (A & B).to_string() + '\n';
		break;
	case 9:
		message = "not A = " + (~A).to_string() + '\n';
		break;
	case 10:
		message = "not B = " + (~B).to_string() + '\n';
		break;
	case 11:
		n = how_much_should_the_value_be_shifted("На сколько бит будем двигать строку: A << ");
		message = "Результаты побитового сдвига: A << " + std::to_string(n) + " = " + (A << n).to_string();
		break;
	case 12:
		n = how_much_should_the_value_be_shifted("На сколько бит будем двигать строку: B << ");
		message ="Результаты побитового сдвига: B << " + std::to_string(n) + " = " + (B << n).to_string();
		break;
	case 13:
		n = how_much_should_the_value_be_shifted("На сколько бит будем двигать строку: A >> ");
		message = "Результаты побитового сдвига: A >> " + std::to_string(n) + " = " + (A >> n).to_string();
		break;
	case 14:
		n = how_much_should_the_value_be_shifted("На сколько бит будем двигать строку: B >> ");
		message = "Результаты побитового сдвига: B >> " + std::to_string(n) + " = " + (B >> n).to_string();
		break;
	}
	return message;
}
void end_menu(bool& exit)
{
	std::cout << "\n1. Продолжить\n2. Завершить работу\n";
	int end;
	correct(end, 1, 2, "->");
	if (end == 2)
		exit = true;

}
// Конец: Меню и его обработка


// Начало: Ввод и его обработка
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
			throw std::runtime_error("Файл не существует или пуст");
			ifile.close();
		}
	}
	else
		throw std::runtime_error("Файл не существует или пуст");
	return file;
}
int input()
{
	std::cout << "Выберите способ ввода\n1. Из консоли\n2. Из файла\n";
	int x;
	correct(x, 1, 2, "->");
	return x;
}
void input_object(BitString& obj) {
	int way{};
	std::cout << "1. Прочитать как бинарное число.\n2. Прочитать как обычное число.\n";
	correct(way, 1, 2, "->");
	
	int start = input();
	if (start == 1)
		obj.input(std::cin, way);
	else{
		std::string file = check_file();
		std::ifstream ifile(file);
		obj.input(ifile, way);
		ifile.close();
	}
}

void input_start_value_of_objs(BitString& A, BitString& B) {
	int way{}, start{};
	std::cout << "Далее введите две битовые строки A и B, следуя инструкциям ниже:\n";
	std::cout << "Выберите способ обработки числа: \n1. Прочитать как бинарные числа.\n2. Прочитать как обычные числа.\n";
	correct(way, 1, 2, "->");

	std::cout << "Выберите способ ввода:\n1. Из консоли\n2. Из файла\n";
	correct(start, 1, 2, "->");

	if (start == 1) {
		std::cout << "Введите битовую строку, представленную через пробел двумя числами: \n";
		A.input(std::cin, way);
		std::cout << '\n';
		std::cout << "Введите битовую строку, представленную через пробел двумя числами: \n";
		B.input(std::cin, way);
		std::cout << '\n';
	}
	else {
		std::string file = check_file();
		std::ifstream ifile(file);
		A.input(ifile, way);
		B.input(ifile, way);
		ifile.close();
	}
}
// Конец: ввод и его обработка


// Начало: вывод и его обработка
int choose_output_way()
{
	std::cout << "Выберите способ вывода\n1. В консоль\n2. В файл\n";
	int x;
	correct(x, 1, 2, "->");
	return x;
}
void output_result(std::string& message) {

	int output_way = choose_output_way();
	if (output_way == 2)
	{
		std::string file = check_file();
		std::ofstream ofile(file);
		ofile << message;
		ofile.close();
	}else 
		std::cout << message;
}
// Конец: вывод и его обработка


// main
int main()
{
	setlocale(LC_ALL, "Russian");
	bool exit_flag{};
	int chosen_action{};
	std::string result_message{};
	BitString A{}, B{};

	input_start_value_of_objs(A, B);
	do
	{
		chosen_action = menu();

		result_message = complete_chosen_action(A, B, chosen_action);

		if (result_message != "") {
			output_result(result_message);
		}

		end_menu(exit_flag);

	} while (exit_flag != true);

	return 0;
}