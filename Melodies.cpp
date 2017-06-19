#pragma once
#include "KLR.h"

//setColor (YELLOW, BLACK);

bool otkr;

Melod::Melod() {
	prakkol.first = false; // ������� � ���������� ������� � ��������, ������� ����� ������ �������� �������� ������� � ����� �������� �������
	prakkol.second = 1;
	name = ""; // �������� �������
	nahoz = -1; // ���������� � ���������� ������������
	//��������
	opred = false; // ������� ������������� �������
	population[0] = -1; // ������������ ������� (������������)
	volume = -1; // ��������� (�� 0 �� 100)
}

Melod::Melod(const string& Name) {
	name = Name; // ������ �����  ������� � ������ ������
    setColor (YELLOW, BLACK);
    cout << "�������� ������� " << name << endl;
    setColor (WHITE, BLACK);
    read();
  }

void Melod::read () {
	ifstream fin;
	string mname= name;
	string fname = "..//Composition//" + mname + ".txt";
	name = mname; // ������ �����  ������� � ������ ������
	fin.open(fname); // �������� ����� ��� ������
	while (!fin) {
		setColor (RED_A, BLACK);
		cout << "�� ������� ������� ���� � ������: " << fname << endl;
		setColor (WHITE, BLACK);
		otkr=false;
		cout << "������� ������ �������� ����� �������: ";
		cin >> mname;
		cout << endl;
		name = mname;
		fname = "..//Composition//" + mname + ".txt";
		fin.open(fname);
	}
	vector <string> header;
	otkr=true;
	char line [500];// ��� ������ ���� ��������� �� ����� ������
	char* buf; // ��������� �� ��������� �����
	char* token; // ��������� ��� �������� ����� ������
	fin.getline(line,500);
	buf = line;
	opred = true; // ������� �������� ������������� �������
	token = strtok_s(buf,"|",&buf);
	if (atoi(token)==1) {
		prakkol.first = false;
		prakkol.second = 1;
	}
	else { // ���� � ���� ����� ���� �������� ��������, �� �� ������ � �������� �������� ������� ������� �������
		prakkol.first = true;
		prakkol.second = atoi (token); // ���-�� ������� � ��������
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
		quantity = atoi(token); // ���-�� ����� � �����, � ������� ������� ���� �������, ������� ��� ��������
		
		token = strtok_s(buf,"|",&buf); //���������� ���� ����� �������, ��� ��� ��� ��� ��������

		token = strtok_s(buf,"|",&buf);
		if (strlen(token)==0) {
			opred = false;
			nahoz = -1;
		}
		else nahoz = atoi(token); // ������ ����� (�� 1 �� 9)
		
		token = strtok_s(buf,"|",&buf);
		population[i] = atoi(token); // ���-�� ������ � ������� (������������ � ���������� ����)
		
		token = strtok_s(buf,"|",&buf);
		if (strlen(token)==0) {
			opred = false;
			volume = -1;
		}
		else volume = atoi(token); // ������������ ����� (��������� ������� ����������� � 2048 ���. �� 8 �� 30720)
		// ���������� ���� ������
		for (int j=0; j<quantity; j++) {
			fin.getline(line,500);
			buf = line;
			while (token = strtok_s(buf,"|",&buf)) {
				Melody.Add(new Zvuk(token));
			}
		}
	}
	cout << name << " ��������.\n";
	fin.close();
}

void Melod::setting() { //������� ������������� �������
	if (opred) {
		cout << "������� ��������� ����������.\n";
	}
	else {
		if (quantity==-1) {
			cout << "\n�� ���������� ���������� ����� ������ � �������. ������� ��� ��������: ";
			cin >> quantity;
		}
		if (nahoz==-1) {
			cout << "\n�� ���������� ��������� ������� � ����������� ������������. ������� ��� ��������: ";
			cin >> nahoz;
		}
		if (volume==-1) {
			cout << "\n�� ���������� ��������� �������. ������� � �������� (�� 0 �� 100): ";
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
	cout << "������ � ���� ..//Composition//" << name << ".txt ...\n";
	setColor (WHITE, BLACK);
	string fName = "..//Composition//" + name + ".txt";
	ofstream fout(fName);
	if (!fout) {
		cout << "������ ������ ����� " << fName << endl;
		return;
	}
	fout << *this;
	cout << "������� " << name << " ��������.\n";
}

void Melod::print() {
	setting();
	cout << "�������������� ��������� ������� ���������:\n";
	cout << "1) ����� � ����������: " << nahoz << endl;
	int sum = 0;
	for (int i = 0; i < prakkol.second; i += 2) {
		sum += population[i];
	}
	cout << "2) ���-�� ������ � �������: " << sum << endl;
	cout << "3) ���������: " << volume << endl;
	if (prakkol.first) {
		cout << "������ ������� ��������� � ��������.\n�������� �������� � ������� ��������� � ��� ���������.\n"
			<< "����� ���� ��� ��������. �� ������� ������ ����� ��������� �������.\n";
	}
	cout << *this;
}

void Melod::editing_ch() {
	print();
	string yn;
	int c;
	yn = "j";
	while (yn!="���") {
		cout << "������ �������� �����-���� �������������� �������? (��/���): ";
		cin >> yn;
		if (yn=="���") {
			return;
		}
		cout << "\n������� ����� �������������� ����� ��������������:\n";
		cout << "1) ����� ������� � ����������;";
		cout << "2) ��������� �������;";
		cout << "3) ��� �������;";
		cin >> c;
		switch (c) {
		case 1:
			cout << "������� ����� ����� ������� � ����������: ";
			cin >> nahoz;
			break;
		case 2:
			cout << "������� ����� ��������� �������: ";
			cin >> volume;
			cout << endl;
			break;
		case 3:
			cout << "������� ����� ��� �������: ";
			cin >> name;
			cout << endl;
			break;
		default: return;
		}
	}
}

