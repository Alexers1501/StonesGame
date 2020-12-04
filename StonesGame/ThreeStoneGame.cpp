/*
 * ThreeStonesGame.cpp
 *
 *  Created on: 28 сент. 2020 г.
 *      Author: Alexers
 *      https://github.com/Alexers1501/StonesGame.git
 */

#include <iostream>
#include <random>
#include <string>
#include <sstream>
#include <chrono>

//using clk = std::chrono::system_clock;
std:: random_device rd; //Датчик случайных чисел
std:: default_random_engine rnd {rd()};
//std::minstd_rand rnd {
//	unsigned(clk::now().time_since_epoch().count())
//};
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
			// проблема здесь она сюда перескакивает
		}
	}
	else if (!(input_ss.eof())){//если строка не до конца проитана
		std:: cout << "А что это такое???! (О.О)" << std:: endl;
		return read_int("Игрок, введите число от 1 до 3: ");
	}
	return result;				//выводим результат
}
// когда он сводит к 4n+1, у следующего игрока нет шансов
int Level1(int choice){
	while (n > 1){
		if (choice == 0){
			std:: cout << "Ход компьютера" << std:: endl;
			int k = distStones(rnd);
			n -= k;
			std:: cout << "Компьютер взял "<< k <<" камушек (@ - @)" << std:: endl;
			std:: cout << std:: endl;
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
			int k = distStones(rnd);
			n -= k;
			std:: cout << "Компьютер взял "<< k <<" камушек (@ - @)" << std:: endl;
			std:: cout << std:: endl;
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

	while(n >= 3){
		if (choice == 0){
			std:: cout << "Ход компьютера" << std:: endl;
					if (n % 4 == 2){
						std:: cout << "Компьютер взял 1 камушек (@ - @)" << std:: endl;
						std:: cout << std:: endl;
						n -= 1;
					}
					else if (n % 4 == 3){
						std:: cout << "Компьютер взял 3 камушка (@ - @)" << std:: endl;
						std:: cout << std:: endl;
						n -= 2;
					}
					else if (n % 4 == 1){
						int k = distStones(rnd);
						n -= k;
						std:: cout << "Компьютер взял "<< k <<" камушек (@ - @)" << std:: endl;
						std:: cout << std:: endl;
						std:: cout << "Осталось " << n << " камушков =(^o^)=" << std:: endl;
						std:: cout << std:: endl;
					}
					std:: cout << "Осталось " << n << " камушков =(^o^)=" << std:: endl;
					std:: cout << std:: endl;
					choice = 1;
		}
	}
	return choice;
}
int Level3(int choice){
	while(n >= 3){
		if (choice == 0){
			std:: cout << "Ход компьютера" << std:: endl;
			if (n % 4 == 2){
				std:: cout << "Компьютер взял 1 камушек (@ - @)" << std:: endl;
				std:: cout << std:: endl;
				n -= 1;
			}
			else if (n % 4 == 3){
				std:: cout << "Компьютер взял 2 камушка (@ - @)" << std:: endl;
				std:: cout << std:: endl;
				n -= 2;
			}
			else if (n % 4 == 0){
				std:: cout << "Компьютер взял 3 камушка (@ - @)" << std:: endl;
				std:: cout << std:: endl;
				n -= 3;
			}
			else if (n % 4 == 1){
				int k = distStones(rnd);
				n -= k;
				std:: cout << "Компьютер взял "<< k <<" камушек (@ - @)" << std:: endl;
				std:: cout << std:: endl;
				std:: cout << "Осталось " << n << " камушков =(^o^)=" << std:: endl;
				std:: cout << std:: endl;
			}
			std:: cout << "Осталось " << n << " камушков =(^o^)=" << std:: endl;
			std:: cout << std:: endl;
			choice = 1;
		}
		else{
			int p;
			//std::cin.clear();//попробовать на новом компиляторе
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
	choice = Level2(choice);
	return choice;
}

int main(){

	std:: cout << "____МЕНЮ____" << std:: endl;
	std:: cout << "1. Правила игры" << std:: endl;
	std:: cout << "2. Выбор уровня" << std:: endl;
	int r;
	r = read_int("Выберете нужный пункт");
	std:: cout << std:: endl;
	switch(r){
		case 1:{

		}
		case 2:{
			std:: cout << "____ВЫБОР УРОВНЯ____" << std:: endl;
			std:: cout << "1 уровень" << std:: endl;
			std:: cout << "2 уровень" << std:: endl;
			std:: cout << "3 уровень" << std:: endl;
			int level;
			level = read_int("Выберете нужный уровень");
			std:: cout << std:: endl;

			std:: uniform_int_distribution <> distChoice {0, 1};

				std:: cout << "На экране " << n << " камушков =(^.^)=" << std:: endl;
				std:: cout << std:: endl;

				int choice = distChoice(rnd);
				if (choice == 0)
					std:: cout << "Начинает компьютер" << std:: endl;
				else
					std:: cout << "Начинает пользователь" << std:: endl;
				int end;
				switch (level){
					case 1: end = Level1(choice); break;
					case 2: end = Level2(choice); break;
					case 3: end = Level3(choice); break;
				}

				if (end == 0)
					std:: cout << "Проиграл компьютер XDXDXDXD" << std:: endl;
				else
					std:: cout << "ВЫ ПРОИГРАЛИ ~('- _ -')~" << std:: endl;

		}
	}

	return 0;
}


