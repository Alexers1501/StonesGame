/*
 * ThreeStonesGame.cpp
 *
 *  Created on: 28 ����. 2020 �.
 *      Author: Alexers
 */

#include <iostream>
#include <random>
#include <string>
#include <sstream>
#include <chrono>

using clk = std::chrono::system_clock;
std:: random_device rd; //������ ��������� �����
//std:: default_random_engine rnd {rd()};
std::minstd_rand rnd {
	unsigned(clk::now().time_since_epoch().count())
};
std:: uniform_int_distribution <> distN {15, 25};
std:: uniform_int_distribution <> distStones {1, 3};

int n = distN(rnd);


int read_int(const char * prompt)	{
	int result;	//
	std::string input;			//��������� ��� ������� ������
	std::cout << prompt;		//����� �������
	std::getline(std::cin, input);//���� ������
	std::stringstream input_ss {input};//�������� ������
	input_ss >> result;				//�������
	if (input_ss.fail()){//���� �� ����������
		if (std::cin.eof()){//���������� ������ ���� � ����� ��� ���������
			std::cerr<< "������ �����/������" << std::endl;
			exit(1);
		}
		else{
			std::cerr<< "�������� ������ �����!" << std::endl;//��������� ����
			std::cerr.flush();//����� ������, �� ��� ���� � ������ �� ������� ����� ������
			return read_int("�����, ������� ����� �� 1 �� 3: ");

		}
	}
	else if (!(input_ss.eof())){//���� ������ �� �� ����� ��������
		std:: cout << "� ��� ��� �����???! (�.�)" << std:: endl;
		return read_int("�����, ������� ����� �� 1 �� 3: ");
	}
	return result;				//������� ���������
}
int Level1(int choice){
	while (n > 3){
		if (choice == 0){
			std:: cout << "��� ����������" << std:: endl;
			n -= distStones(rnd);
			std:: cout << "�������� " << n << " �������� =(^o^)=" << std:: endl;
			std:: cout << std:: endl;
			choice = 1;
		}
		else{
			int p;
			p = read_int("�����, ������� ����� �� 1 �� 3: ");
			while(p>3 or p<1){
				std:: cout << "�� ����� �������� �����" << std:: endl;
				p = read_int("�����, ������� ����� �� 1 �� 3: ");

			};
			n -= p;
			std:: cout << "�������� " << n << " �������� =(^~^)=" << std:: endl;
			std:: cout << std:: endl;
			choice = 0;
		}
	}
	return choice;
}
int Level2(int choice){// ����� ������ 10 �� �������� ������
	while (n > 10){
		if (choice == 0){
			std:: cout << "��� ����������" << std:: endl;
			n -= distStones(rnd);
			std:: cout << "�������� " << n << " �������� =(^o^)=" << std:: endl;
			std:: cout << std:: endl;
			choice = 1;
		}
		else{
			int p;
			p = read_int("�����, ������� ����� �� 1 �� 3: ");
			while(p>3 or p<1){
				std:: cout << "�� ����� �������� �����" << std:: endl;
				p = read_int("�����, ������� ����� �� 1 �� 3: ");

			};
			n -= p;
			std:: cout << "�������� " << n << " �������� =(^~^)=" << std:: endl;
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

	std:: cout << "�� ������ " << n << " �������� =(^.^)=" << std:: endl;
	std:: cout << std:: endl;

	int choice = distChoice(rnd);
	if (choice == 0)
		std:: cout << "�������� ���������" << std:: endl;
	else
		std:: cout << "�������� ������������" << std:: endl;

	int end = Level1(choice);

	if (end == 0)
		std:: cout << "�������� ��������� XDXDXDXD" << std:: endl;
	else
		std:: cout << "�� ��������� ~('- _ -')~" << std:: endl;

	return 0;
}


