#pragma once
#include "KLR.h"

vector <string> comp;

//setColor (YELLOW, BLACK);

Compos::Compos() {
	CompositionName = "";
}

void Compos::read () {
	Composition.RemoveAll();
	char line [500];// тут храним саму считанную из файла строку
	char* buf=line; // указатель на следующее слово
	char* token; // указатель для хранения слова строки
	string fName = "..//"+CompositionName+"//Compositions.txt";
	ifstream fin(fName);
	if (!fin) {
		cout << "Ошибка чтения файла " << fName << endl;
		return;
	}
	fin.getline (buf, 500);
	while (token=strtok_s(buf,"|",&buf)) {
		comp.push_back(token);
		Composition.Add(new Melod(token));
	}
	cout << "Кол-во мелодий: " << comp.size() << endl;
	fin.close();
}

ostream& operator<<(ostream& out, Compos& C) {
	out << "Печать композиции " << C.CompositionName << endl;
	for (int i=0; i<C.Composition.GetSize(); i++) {
		out << *(Melod*)C.Composition[i] << endl;
	}
	return out;
}

void Compos::write () {
	for (int i=0; i<Composition.GetSize(); i++) {
		setColor (YELLOW, BLACK);
		cout << "Запись в файл ..//Composition//" << comp[i] << ".txt ...\n";
		setColor (WHITE, BLACK);
		string fName = "..//" +CompositionName+ "//" + comp[i] + ".txt";
		ofstream fout(fName);
		if (!fout) {
			cout << "Ошибка чтения файла " << fName << endl;
			return;
		}
		fout << *(Melod*)Composition[i];
		cout << "Мелодия " << comp[i] << " записана.\n";
	}
}

void Compos::sequencing () {
	Melod M;
	for (int i=0; i<Composition.GetSize()-1; i++) {
		if ((*(Melod*)Composition[i]).nahoz > (*(Melod*)Composition[i+1]).nahoz){
			M = *(Melod*)Composition[i];
			*(Melod*)Composition[i] = *(Melod*)Composition[i+1];
			*(Melod*)Composition[i+1] = M;
		}
	}
}