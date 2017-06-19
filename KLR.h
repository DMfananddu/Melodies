#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#define _AFXDLL
#include <afx.h>
#include <atlcoll.h>
#include <windows.h>

#define WIDE 85

using namespace std;

enum color {BLACK = 0,BLUE_B,GREEN_B,Cyan,Red_B,Magenta,Brown,GRAY_A,GRAY_B,BLUE_A,GREEN_A,LightCyan,RED_A,LightMagenta,YELLOW,WHITE};
void setColor(color, color);

class Zvuk : public CObject{
public:
	//ДАННЫЕ
	char* degree; // Ступеньзвука (А, B, C, D, E, F, G)
	int octave; // октава звука (от 1 до 9)
	int timbre; // тембр звука: 1 - "звонкий", 2 - "глухой", 3 - "шумный"
	int duration; // длительность звука (настоящее знаение увеличенное в 2048 раз. от 8 до 30720)
	int pitch; // высота звука (от 0 до 3200 Мел)
	int volume; // громкость (от 0 до 200 дБ)
	int len; // длина строки звука
	//ПРИЗНАКИ
	bool opred;
	//ФУНКЦИИ
	friend ostream& operator<<(ostream&, Zvuk&);
	Zvuk ();
	Zvuk (const char*);
	Zvuk (Zvuk&);
//	~Zvuk () {};
	void print ();
	void setting ();
	void editing ();
	void deleting ();
};

class Melod : public CObject{
public:
	//ДАННЫЕ
	pair <bool, int> prakkol; // признак нахождения мелодии в акколаде, которая будет являться массивом мелодий в одном элементе мелодии
	int quantity; // кол-во строк в файле, в котором описана одна мелодия, которые она занимает
	string name; // название мелодии
	int nahoz; // нахождение в музыкаьном произведении
	int population[15]; // количество звуков в мелодии (акколаде)
	int volume; // громкость (от 0 до 100)
	//ПРИЗНАКИ
	bool opred; // признак определённости мелодии
	CObArray Melody; // сборище звуков
	//ФУНКЦИИ
	Melod ();
	Melod (const string&);
//	~Melod () {};
	friend ostream& operator<<(ostream&, Melod&);
	void operator=(Melod&);
	void setting ();
	void read ();
	void write();
	void editing_ch ();
	void print();
	void deleting (int);
};

class Compos {
public:
	string CompositionName; // название композиции/музыкального произведения
	CObArray Composition;
	Compos ();
	Compos (const string&);
	friend ostream& operator<<(ostream&, Compos&);
	void write ();
	void read ();
	void sequencing ();
};