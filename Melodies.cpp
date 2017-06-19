#pragma once
#include "KLR.h"

//setColor (YELLOW, BLACK);

bool otkr;

Melod::Melod() {
	prakkol.first = false; // признак и нахождение мелодии в акколаде, которая будет просто являться массивом мелодий в одном элементе мелодии
	prakkol.second = 1;
	name = ""; // название мелодии
	nahoz = -1; // нахождение в музыкаьном произведении
	//ПРИЗНАКИ
	opred = false; // признак определённости мелодии
	population[0] = -1; // длительность мелодии (неограничено)
	volume = -1; // громкость (от 0 до 100)
}

Melod::Melod(const string& Name) {
	name = Name; // запись имени  таблицы в объект класса
    setColor (YELLOW, BLACK);
    cout << "Создание мелодии " << name << endl;
    setColor (WHITE, BLACK);
    read();
  }

void Melod::read () {
	ifstream fin;
	string mname= name;
	string fname = "..//Composition//" + mname + ".txt";
	name = mname; // запись имени  таблицы в объект класса
	fin.open(fname); // Открытие файла для чтения
	while (!fin) {
		setColor (RED_A, BLACK);
		cout << "Не удается открыть файл с именем: " << fname << endl;
		setColor (WHITE, BLACK);
		otkr=false;
		}
	vector <string> header;
	otkr=true;
	char line [500];// тут храним саму считанную из файла строку
	char* buf; // указатель на следующее слово
	char* token; // указатель для хранения слова строки
	fin.getline(line,500);
	buf = line;
	opred = true; // задание признака определённости мелодии
	token = strtok_s(buf,"|",&buf);
	if (atoi(token)==1) {
		prakkol.first = false;
		prakkol.second = 1;
	}
	else { // если в этом файле идет описание акколады, то мы должны в качестве элемента мелодии выбрать мелодию
		prakkol.first = true;
		prakkol.second = atoi (token); // кол-во мелодий в акколаде
	}
	fin.close();
	fin.open(fname);
	for (int i=0; i<prakkol.second; i++) {
		fin.getline(line,500);
		buf = line;
		if (i==0) {
			token = strtok_s(buf,"|",&buf);
		}

		token = strtok_s(buf,"|",&buf);
		quantity = atoi(token); // кол-во строк в файле, в котором описана одна мелодия, которые она занимает
		
		token = strtok_s(buf,"|",&buf); //игнорируем поле имени мелодии, так как оно уже записано

		token = strtok_s(buf,"|",&buf);
		if (strlen(token)==0) {
			opred = false;
			nahoz = -1;
		}
		else nahoz = atoi(token); // октава звука (от 1 до 9)
		
		token = strtok_s(buf,"|",&buf);
		population[i] = atoi(token); // кол-во звуков в мелодии (обязательное к заполнению поле)
		
		token = strtok_s(buf,"|",&buf);
		if (strlen(token)==0) {
			opred = false;
			volume = -1;
		}
		else volume = atoi(token); // длительность звука (настоящее знаение увеличенное в 2048 раз. от 8 до 30720)
		// Считывание всех звуков
		for (int j=0; j<quantity; j++) {
			fin.getline(line,500);
			buf = line;
			while (token = strtok_s(buf,"|",&buf)) {
				Melody.Add(new Zvuk(token));
			}
		}
	}
	cout << name << " записана.\n";
	fin.close();
}

void Melod::setting() { //задание характеристик мелодии
	if (opred) {
		cout << "Звук полностью определён.";
	}
	else {
		if (quantity==-1) {
			cout << "\nНе определено количество строк звуков в мелодии. Введите его значение: ";
			cin >> quantity;
		}
		if (nahoz==-1) {
			cout << "\nНе определено положение мелодии в музыкальном произведении. Введите его значение: ";
			cin >> nahoz;
		}
		if (volume==-1) {
			cout << "\nНе определена громкость мелодии. Введите её значение (от 0 до 100): ";
			cin >> volume;
		}
	}
}

void Melod::operator=(Melod& M) {
	name = M.name;
	quantity = M.quantity;
	nahoz = M.nahoz;
	for (unsigned i=0; i<sizeof(population)/sizeof(int); i++) {
		population[i] = M.population[i];
	}
	volume = M.volume;
	opred = M.opred;
	prakkol.first = M.prakkol.first;
	prakkol.second = M.prakkol.second;
	Melody.Copy(M.Melody);
}

ostream& operator << (ostream& out, Melod& M) {
	int i=0;
	int k, w;
	for (int j=0; j<M.prakkol.second; j++) {
		k=0;
		w=0;
		if (j==0) {
			out << M.prakkol.second;
		}
		out << "|" << M.quantity << "|" << M.name << "|" << M.nahoz << "|" << M.population[j] << "|" << M.volume << endl;
		while (k!=M.population[j]) {
			while (w+(*(Zvuk*)M.Melody[i]).len <= WIDE) {
				if (w!=0) {
					out << "|"; }
				w+=(*(Zvuk*)M.Melody[i]).len;
				out << *(Zvuk*)M.Melody[i];
				i++;
				k++;
				if (k>=M.population[j]) {
					break;
				}
			}
			w=0;
			out << endl;
		}
	}
	return out;
}

void Melod::write() {
	setColor (YELLOW, BLACK);
	cout << "Запись в файл ..//Composition//" << name << ".txt ...\n";
	setColor (WHITE, BLACK);
	string fName = "..//Composition//" + name + ".txt";
	ofstream fout(fName);
	if (!fout) {
		cout << "Ошибка чтения файла " << fName << endl;
		return;
	}
	fout << *this;
	cout << "Мелодия " << name << " записана.\n";
}

void Melod::print() {
	setting();
	cout << "Характеристики выбранной мелодии следующие:\n";
	cout << "1) Номер в композиции: " << nahoz << endl;
	int sum = 0;
	for (int i = 0; i < prakkol.second; i += 2) {
		sum += population[i];
	}
	cout << "2) Кол-во звуков в мелодии: " << sum << endl;
	cout << "3) Громкость: " << volume << endl;
	if (prakkol.first) {
		cout << "Данная мелодия находится в акколаде.\nНазвание акколады и мелодий состоящих в ней совпадают.\n"
			<< "Перед вами вся акколада. По формату вывода видны отдельные мелодии.\n";
	}
	cout << *this;
}

void Melod::editing_ch() {
	print();
	string yn;
	int c;
	yn = "j";
	while (yn!="нет") {
		cout << "Хотите изменить какие-либо характеристики мелодии? (да/нет): ";
		cin >> yn;
		if (yn=="нет") {
			return;
		}
		cout << "\nВведите цифру соответстующую новой характеристике:\n";
		cout << "1) Номер мелодии в композиции;";
		cout << "2) Громкость мелодии;";
		cout << "3) Имя мелодии;";
		cin >> c;
		switch (c) {
		case 1:
			cout << "Введите новой номер мелодии в композиции: ";
			cin >> nahoz;
			break;
		case 2:
			cout << "Введите новую громкость мелодии: ";
			cin >> volume;
			cout << endl;
			break;
		case 3:
			cout << "Введите новое имя мелодии: ";
			cin >> name;
			cout << endl;
			break;
		default: return;
		}
	}
}

