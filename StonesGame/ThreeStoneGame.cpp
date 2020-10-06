/*
 * ThreeStonesGame.cpp
 *
 *  Created on: 28 сент. 2020 г.
 *      Author: Alexers
 */

#include <iostream>
#include <random>
#include <string>
#include <sstream>
#include <chrono>

using clk = std::chrono::system_clock;
std:: random_device rd; //Датчик случайных чисел
//std:: default_random_engine rnd {rd()};
std::minstd_rand rnd {
	unsigned(clk::now().time_since_epoch().count())
};
std:: uniform_int_distribution <> distN {15, 25};
std:: uniform_int_distribution <> distStones {1, 3};

int n = distN(rnd);


int read_int(const char * prompt)	{
	int result;	//
	std::string input;			//хранилище для вводной строки
	std::cout << prompt;		//вывод запроса
	std::getline(std::cin, input);//ввод строки
	std::stringstream input_ss {input};//создание потока
	input_ss >> result;				//чтерние
	if (input_ss.fail()){//если не получилось
		if (std::cin.eof()){//возвращает истину если в файле все прочитано
			std::cerr<< "Ошибка ввода/вывода" << std::endl;
			exit(1);
		}
		else{
			std::cerr<< "Неверный формат числа!" << std::endl;//прописать цикл
			std::cerr.flush();//сброс буфера, то что есть в буфере он выведет прямо сейчас
			return read_int("Игрок, введите число от 1 до 3: ");

		}
	}
	else if (!(input_ss.eof())){//если строка не до конца проитана
		std:: cout << "А что это такое???! (О.О)" << std:: endl;
		return read_int("Игрок, введите число от 1 до 3: ");
	}
	return result;				//выводим результат
}
int Level1(int choice){
	while (n > 3){
		if (choice == 0){
			std:: cout << "Ход компьютера" << std:: endl;
			n -= distStones(rnd);
			std:: cout << "Осталось " << n << " камушков =(^o^)=" << std:: endl;
			std:: cout << std:: endl;
			choice = 1;
		}
		else{
			int p;
			p = read_int("Игрок, введите число от 1 до 3: ");
			while(p>3 or p<1){
				std:: cout << "Вы ввели неверное число" << std:: endl;
				p = read_int("Игрок, введите число от 1 до 3: ");

			};
			n -= p;
			std:: cout << "Осталось " << n << " камушков =(^~^)=" << std:: endl;
			std:: cout << std:: endl;
			choice = 0;
		}
	}
	return choice;
}
int Level2(int choice){// когда меньше 10 он начинает думать
	while (n > 10){
		if (choice == 0){
			std:: cout << "Ход компьютера" << std:: endl;
			n -= distStones(rnd);
			std:: cout << "Осталось " << n << " камушков =(^o^)=" << std:: endl;
			std:: cout << std:: endl;
			choice = 1;
		}
		else{
			int p;
			p = read_int("Игрок, введите число от 1 до 3: ");
			while(p>3 or p<1){
				std:: cout << "Вы ввели неверное число" << std:: endl;
				p = read_int("Игрок, введите число от 1 до 3: ");

			};
			n -= p;
			std:: cout << "Осталось " << n << " камушков =(^~^)=" << std:: endl;
			std:: cout << std:: endl;
			choice = 0;
		}
	}

	while(n > 3){
		if (choice ==0){

		}
		else{

		}
	}
	return choice;
}

int main(){

	std:: uniform_int_distribution <> distChoice {0, 1};

	std:: cout << "На экране " << n << " камушков =(^.^)=" << std:: endl;
	std:: cout << std:: endl;

	int choice = distChoice(rnd);
	if (choice == 0)
		std:: cout << "Начинает компьютер" << std:: endl;
	else
		std:: cout << "Начинает пользователь" << std:: endl;

	int end = Level1(choice);

	if (end == 0)
		std:: cout << "Проиграл компьютер XDXDXDXD" << std:: endl;
	else
		std:: cout << "ВЫ ПРОИГРАЛИ ~('- _ -')~" << std:: endl;

	return 0;
}


