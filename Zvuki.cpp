#pragma once
#include "KLR.h"

//setColor (YELLOW, BLACK);

Zvuk::Zvuk() {
	degree= ""; // Ступеньзвука (А, B, C, D, E, F, G)
	octave = -1; // октава звука (от 1 до 9)
	timbre = -1; // тембр звука: 1 - "звонкий", 2 - "глухой", 3 - "шумный"
	duration = -1; // длительность звука (настоящее знаение увеличенное в 2048 раз. от 8 до 30720)
	pitch = -1; // высота звука (от 0 до 3200 Мел)
	volume = -1; // громкость (от 0 до 200 дБ)
	opred = false;
}

Zvuk::Zvuk(const char* z1) {
	opred = true; // задание признака определённости звука
	char* z = new char [100];
	strcpy_s(z, 100, z1);
	len = strlen(z);
	char* buf = z; // указатель для хранения слова строки
	buf = strtok_s(z,".",&z);
	if (strlen(buf)==0) {
		opred = false; 
		degree = "";
	}
	else degree = buf; // Ступень звука (А, B, C, D, E, F, G)
	
	buf = strtok_s(z,".",&z);
	if (strlen(buf)==0) {
		opred = false;
		octave = -1;
	}
	else octave = atoi(buf); // октава звука (от 1 до 9)
	
	buf = strtok_s(z,".",&z);
	if (strlen(buf)==0) {
		opred = false;
		timbre = -1;
	}
	else timbre = atoi(buf); // тембр звука: 1 - "звонкий", 2 - "глухой", 3 - "шумный"
	
	buf = strtok_s(z,".",&z);
	if (strlen(buf)==0) {
		opred = false;
		duration = -1;
	}
	else duration = atoi(buf); // длительность звука (настоящее знаение увеличенное в 2048 раз. от 8 до 30720)
	
	buf = strtok_s(z,".",&z);
	if (strlen(buf)==0) {
		opred = false;
		pitch = -1;
	}
	else pitch = atoi(buf); // высота звука (от 0 до 3200 Мел)
	
	buf = strtok_s(z,".",&z);
	if (strlen(buf)==0) {
		opred = false;
		volume = -1;
	}
	else volume = atoi(buf); // громкость (от 0 до 200 дБ)
};

Zvuk::Zvuk (Zvuk& Z1) {
	degree= Z1.degree; 
	octave = Z1.octave; 
	timbre = Z1.timbre; 
	duration = Z1.duration; 
	pitch = Z1.pitch; 
	volume = Z1.volume;
	opred = true;
}

void Zvuk::print() {
	setting();
	cout << "Характеристики выбранного звука следующие:\n";
	cout << "1) Cтупень: " << degree << endl;
	cout << "2) Октава: " << octave << endl;
	cout << "3) Тембр: " << timbre << endl;
	cout << "4) Длительность: " << duration << endl;
	cout << "5) Высота: " << pitch << endl;
	cout << "6) Громкость: " << volume << endl;
}

ostream& operator << (ostream& out, Zvuk& z) {
	out << z.degree << "." << z.octave << "." << z.timbre << "." << z.duration << "." << z.pitch << "." << z.volume;
	return out;
}

void Zvuk::setting() { //задание характеристик звука
	if (opred) {
		cout << "Звук полностью определён.";
	}
	else {
		char* deg = new char [2];
		int y = 0;
		if (degree=="") {
			cout << "\nНе определена ступень звука. Введите её значение (А, B, C, D, E, F, G): ";
			cin >> deg;
			degree = deg;
		}
		if (octave==-1) {
			cout << "\nНе определена октава звука. Введите её значение (от 1 до 9): ";
			cin >> y;
			octave = y;
		}
		if (timbre==-1) {
			cout << "\nНе определена тембр звука. Введите его значение (1 - звонкий, 2 - глухой, 3 - шумный): ";
			cin >> y;
			timbre = y;
		}
		if (duration==-1) {
			cout << "\nНе определена длительность звука. Введите её значение (8 до 30720): ";
			cin >> y;
			duration = y;
		}
		if (pitch==-1) {
			cout << "\nНе определена высота звука. Введите её значение (от 0 до 3200): ";
			cin >> y;
			pitch = y;
		}
		if (volume==-1) {
			cout << "\nНе определена громкость звука. Введите её значение (от 0 до 200): ";
			cin >> y;
			volume = y;
		}
	}
}

void Zvuk::editing () {
	print();
	string yn;
	int c;
	yn = "j";
	while (yn!="нет") {
		cout << "Хотите изменить какие-либо характеристики звука? (да/нет): ";
		cin >> yn;
		if (yn=="нет") {
			return;
		}
		cout << "\nВведите цифру соответстующую новой характеристике (см. список выше): ";
		cin >> c;
		switch (c) {
		case 1:
			cout << "Введите  новую ступень звука: ";
			cin >> degree;
			cout << endl;
			break;
		case 2:
			cout << "Введите  новую октаву звука: ";
			cin >> octave;
			cout << endl;
			break;
		case 3:
			cout << "Введите  новую тембр звука: ";
			cin >> timbre;
			cout << endl;
			break;
		case 4:
			cout << "Введите  новую длительность звука: ";
			cin >> duration;
			cout << endl;
			break;
		case 5:
			cout << "Введите  новую высоту звука: ";
			cin >> pitch;
			cout << endl;
			break;
		case 6:
			cout << "Введите  новую громкость звука: ";
			cin >> volume;
			cout << endl;
			break;
		}
	}
}

