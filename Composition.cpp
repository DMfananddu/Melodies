#pragma once
#include "KLR.h"

vector <string> comp;

//setColor (YELLOW, BLACK);

Compos::Compos() {
	CompositionName = "";
}

void Compos::read () {
	Composition.RemoveAll();
	char line [500];// ��� ������ ���� ��������� �� ����� ������
	char* buf=line; // ��������� �� ��������� �����
	char* token; // ��������� ��� �������� ����� ������
	string fName = "..//"+CompositionName+"//Compositions.txt";
	ifstream fin(fName);
	if (!fin) {
		cout << "������ ������ ����� " << fName << endl;
		return;
	}
	fin.getline (buf, 500);
	while (token=strtok_s(buf,"|",&buf)) {
		comp.push_back(token);
		Composition.Add(new Melod(token));
	}
	cout << "���-�� �������: " << comp.size() << endl;
	fin.close();
}

ostream& operator<<(ostream& out, Compos& C) {
	out << "������ ���������� " << C.CompositionName << endl;
	for (int i=0; i<C.Composition.GetSize(); i++) {
		out << *(Melod*)C.Composition[i] << endl;
	}
	return out;
}

void Compos::write () {
	for (int i=0; i<Composition.GetSize(); i++) {
		setColor (YELLOW, BLACK);
		cout << "������ � ���� ..//Composition//" << comp[i] << ".txt ...\n";
		setColor (WHITE, BLACK);
		string fName = "..//" +CompositionName+ "//" + comp[i] + ".txt";
		ofstream fout(fName);
		if (!fout) {
			cout << "������ ������ ����� " << fName << endl;
			return;
		}
		fout << *(Melod*)Composition[i];
		cout << "������� " << comp[i] << " ��������.\n";
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