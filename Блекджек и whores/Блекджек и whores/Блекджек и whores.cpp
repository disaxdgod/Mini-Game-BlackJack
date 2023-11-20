#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime> //Доработать визуал!!!

#include <vector>
#include <algorithm>
void map() {
	std::cout << "*******************************************" << std::endl;
	std::cout << "*                                         *" << std::endl;
	std::cout << "*         -----             -----         *" << std::endl;
	std::cout << "*        |9    |           |8    |        *" << std::endl;
	std::cout << "*        |V V V|   -----   |V V V|        *" << std::endl;
	std::cout << "*        |V V V|  |7    |  | V V |        *" << std::endl;
	std::cout << "*        |V V V|  | V V |  |V V V|        *" << std::endl;
	std::cout << "*        |____6|  |V V V|  |____8|        *" << std::endl;
	std::cout << "*		  | V V |                 *" << std::endl;
	std::cout << "*                 |____L|                 *" << std::endl;
	std::cout << "*                                         *" << std::endl;
	std::cout << "*******************************************" << std::endl;
	std::cout << "*           Добро пожаловать              *" << std::endl;
	std::cout << "*   Это упрощенная версия игры BlackJack  *" << std::endl;
	std::cout << "*   Правила просты тяни по одной карте    *" << std::endl;
	std::cout << "* и набери сумму достоинств карт равной 21*" << std::endl;
	std::cout << "*       Если не вышло попробуй снова      *" << std::endl;
	std::cout << "*******************************************" << std::endl;
} 
int main() {
	setlocale(LC_ALL, "Rus");
	std::srand(unsigned(std::time(0)));
	int choise, playcard;
	int count = 0;
	float bet = 0;
	int cash = 999999;
	std::vector<int> cards = { 11,11,11,11,2,2,2,2,3,3,3,3,
								4,4,4,4, 5,5,5,5,6,6,6,6,
								7,7,7,7,8,8,8,8,10,10,10,10,
								10,10,10,10,10,10,10,10,10,
								10,10,10,10,10,10,10 }; //номиналы кард
	std::cout << "*******************************************" << std::endl;
	std::cout << "*                                         *" << std::endl;
	std::cout << "*         -----             -----         *" << std::endl;
	std::cout << "*        |9    |           |8    |        *" << std::endl;
	std::cout << "*        |V V V|   -----   |V V V|        *" << std::endl;
	std::cout << "*        |V V V|  |7    |  | V V |        *" << std::endl;
	std::cout << "*        |V V V|  | V V |  |V V V|        *" << std::endl;
	std::cout << "*        |____6|  |V V V|  |____8|        *" << std::endl;
	std::cout << "*		  | V V |                 *" << std::endl;
	std::cout << "*                 |____L|                 *" << std::endl;
	std::cout << "*                                         *" << std::endl;
	std::cout << "*******************************************" << std::endl;
	std::cout << "*           Добро пожаловать              *" << std::endl;
	std::cout << "*   Это упрощенная версия игры BlackJack  *" << std::endl;
	std::cout << "*   Правила просты тяни по одной карте    *" << std::endl;
	std::cout << "* и набери сумму достоинств карт равной 20*" << std::endl;
	std::cout << "*       Если не вышло попробуй снова      *" << std::endl;
	std::cout << "*******************************************" << std::endl;
	std::cout << "Ваш баланс: " << cash << std::endl;
	std::cout << "Введите ставку: ";
	std::cin >> bet;
	if (cash < bet) {
		std::cout << "На вашем счету не достаточно средств" << std::endl;
		std::cout << "Ваш баланс: " << cash << std::endl;
		return 0;

	}
	else if (bet <= -1 || bet >= 999999) {
		std::cout << "Ставка не принята (20 < Ставка < 250)" << std::endl;
		return 0;
	}
	while (cash >= bet) {
		std::cout << "Тянуть карту?" << std::endl;
		std::cout << "2 - Забрать ставку досрочно" << std::endl;
		std::cout << "1 - да" << std::endl;
		std::cout << "0 - нет" << std::endl;
		std::cout << "Ваш выбор: ";
		std::cin >> choise;

		if (choise == 2) {
			if (count < 15) {
				std::cout << "Вы ничего не заработали " <<std::endl;
			}
			else if (count == 15) {
				std::cout << "Ваш баланс: " << (cash-bet)+bet/4 << std::endl;
				bet /= 4;
				std::cout << "Вы заработали: "<< bet << std::endl;
				break; 
			}
			else if (count == 16) {
				std::cout << "Ваш баланс: " << (cash - bet) + bet / 2 << std::endl;
				bet /= 2;
				std::cout << "Вы заработали: " << bet << std::endl;
				break;
			}
			else if (count == 17) {
				std::cout << "Ваш баланс: " << cash << std::endl;
				std::cout << "Вы заработали: " << bet << std::endl;
				break;
			}
			else if (count == 18) {
				std::cout << "Ваш баланс: " << (cash - bet) + bet *1.25 << std::endl;
				bet *= 1.25;
				std::cout << "Вы заработали: " << bet << std::endl;
				break;
			}
			else if (count == 19) {
				std::cout << "Ваш баланс: " << (cash - bet) + bet * 1.5 << std::endl;
				bet *= 1.5;
				std::cout << "Вы заработали: " << bet << std::endl;
				break;
			}
		}
		if (choise == 1) {
			std::random_shuffle(cards.begin(), cards.end());
			playcard = cards[cards.size() - 1];
			std::cout << "Вы вытянули: " << playcard << std::endl;
		    count += playcard;
		}
		else {
			break;
		}
		if (count > 20) {
			std::cout << "Ваш баланс: " << (cash - bet)<< std::endl;
			std::cout << "Вы заработали: -" << bet <<std::endl;
			break;
		}
		else if (count == 20) {
			std::cout << "*** Вы набрали 20 очков ***"<< std::endl;
			std::cout << "Ваш баланс: " << (cash - bet) + bet * 2 << std::endl;
			bet *= 2;
			std::cout << "Вы заработали: " << bet << std::endl;
			break;
		}
		else {
			std::cout <<"У вас " <<count <<" очков" << std::endl;
		}
	}
}


              


