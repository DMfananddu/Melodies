#pragma once
#include "KLR.h"

//-----------------------Функция МЕНЮ
int menu(int &wod) {
	cout<<"============== Мелодии и Звуки ==============\n";
	cout<<"   1. Чтение музыкального произведения\n   2. Печать музыкального произведения\n";
	cout<<"   3. Запись музыкального произведения в файл\n   4. Чтение мелодии\n";
	cout<<"   5. Печать мелодии\n   6. Записать мелодию в файл\n";
	cout<<"   7. Изменение характеристик мелодии, состоящей в композиции\n";
	cout<<"   8. Создание звука\n";
	cout<<"   9. Добавление звука в мелодию, состоящую в композиции\n";
	cout<<"   10. Удаление звука из мелодии, состоящей в композиции\n";
	cout<<"   11. Удаление мелодии из композиции\n";
	cout<<"   12. Выход\n";
	cout<<"=============================================\n\n\n";
	cin >> wod;
	cout<<"\n\n\n";
	if (wod >= 1 && wod <= 11) {
		return wod;
	}                           
	cout << "Некорректный ввод. ";
	cout << "Постарайтесь попасть пальцами по клавишам 1-11\n";
	return 0;
}

//-----------------------Функция MAIN
int main(){
	system("chcp 1251 > nul");
	int n=0;
	int m=0;
	int k=0;
	Zvuk Z1;
	Zvuk Z2;
	Melod M1;
	Compos C1;
	char* meln = new char[100];
	while (true) {
		cout << "Введите цифру интересующего вас пункта работы программы: \n";
		switch (menu(n)) {
			case 1:
				cout << "Введите название композиции: ";
				cin >> C1.CompositionName;
				C1.read();
				break;
			case 2:
				cout << C1;
				break;
			case 3:
				C1.write();
				break;
			case 4:
				cout << "Введите название мелодии: ";
				cin.ignore();
				cin.getline(meln, 100, '\n');
				M1 = Melod(meln);
				break;
			case 5:
				M1.print();
				break;
			case 6:
				M1.write();
				break;
			case 7:
				cout << "Введите название композиции: ";
				cin >> C1.CompositionName;
				C1.read();
				cout << C1;
				cout << "Введите номер мелодии: ";
				cin >> m;
				m--;
				(*(Melod*)C1.Composition[m]).editing_ch();
				C1.sequencing();
				cout << C1 << endl;
				break;
			case 8:
				cout << "Создаём звук...\n";
				Z1.setting();
				cout << "Звук создан";
				Z1.print();
				cout << endl;
				break;
			case 9:
				cout << "Введите название композиции, в которую хотите добавить звук: ";
				cin >> C1.CompositionName;
				C1.read();
				C1.sequencing();
				cout << C1 << endl;
				Z1.print();
				cout << "В какую мелодию вы ходите добавить введённый звук?\n";
				cout << "Введите номер мелодии: ";
				cin >> m;
				m--;
				(*(Melod*)C1.Composition[m]).print();
				cout << "\nВведите номер звука (в мелодии в целом): ";
				cin >> k;
				k--;
				(*(Melod*)C1.Composition[m]).Melody.InsertAt(k, new Zvuk(Z1));
				(*(Melod*)C1.Composition[m]).print();
				break;
			case 10:
				C1.sequencing();
				cout << C1;
				cout << "Введите номер мелодии: ";
				cin >> m;
				m--;
				(*(Melod*)C1.Composition[m]).print();
				cout << "\nВведите номер звука (в мелодии в целом): ";
				cin >> k;
				k--;
				(*(Melod*)C1.Composition[m]).Melody.RemoveAt(k);
				cout << "\nЗвук удален\n";
				(*(Melod*)C1.Composition[m]).print();
				cout << endl;
				break;
			case 11:
				C1.sequencing();
				cout << C1;
				cout << "Введите номер мелодии: ";
				cin >> m;
				m--;
				C1.Composition.RemoveAt(m);
				cout << "\nМелодия удалена\n";
				cout << C1;
				cout << endl;
				break;
			default:
				return 0;
		}
	}
	return 0;
	system ("pause");
}
