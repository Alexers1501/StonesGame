/*
 * ThreeStonesGame.cpp
 *
 *  Created on: 28 ����. 2020 �.
 *      Author: Alexers
 */

#include <iostream>
#include <random>

std:: random_device rd; //������ ��������� �����
std:: default_random_engine rnd {rd()};
std:: uniform_int_distribution <> distN {15, 25};
std:: uniform_int_distribution <> distStones {1, 3};

int n = distN(rnd);

void error(int p){
	while(p>3 or p<1){
		std:: cout << "�� ����� �������� �����" << std:: endl;
		std:: cout << "�����, ������� ����� �� 1 �� 3: ";
		std:: cin >> p;
	}
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
			std:: cout << "�����, ������� ����� �� 1 �� 3: ";
			std:: cin >> p;
			error(p);
			n -= p;
			std:: cout << "�������� " << n << " �������� =(^~^)=" << std:: endl;
			std:: cout << std:: endl;
			choice = 0;
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


