#pragma once
#include "KLR.h"

//setColor (YELLOW, BLACK);

Zvuk::Zvuk() {
	degree= ""; // ������������ (�, B, C, D, E, F, G)
	octave = -1; // ������ ����� (�� 1 �� 9)
	timbre = -1; // ����� �����: 1 - "�������", 2 - "������", 3 - "������"
	duration = -1; // ������������ ����� (��������� ������� ����������� � 2048 ���. �� 8 �� 30720)
	pitch = -1; // ������ ����� (�� 0 �� 3200 ���)
	volume = -1; // ��������� (�� 0 �� 200 ��)
	opred = false;
}

Zvuk::Zvuk(const char* z1) {
	opred = true; // ������� �������� ������������� �����
	char* z = new char [100];
	strcpy_s(z, 100, z1);
	len = strlen(z);
	char* buf = z; // ��������� ��� �������� ����� ������
	buf = strtok_s(z,".",&z);
	if (strlen(buf)==0) {
		opred = false; 
		degree = "";
	}
	else degree = buf; // ������� ����� (�, B, C, D, E, F, G)
	
	buf = strtok_s(z,".",&z);
	if (strlen(buf)==0) {
		opred = false;
		octave = -1;
	}
	else octave = atoi(buf); // ������ ����� (�� 1 �� 9)
	
	buf = strtok_s(z,".",&z);
	if (strlen(buf)==0) {
		opred = false;
		timbre = -1;
	}
	else timbre = atoi(buf); // ����� �����: 1 - "�������", 2 - "������", 3 - "������"
	
	buf = strtok_s(z,".",&z);
	if (strlen(buf)==0) {
		opred = false;
		duration = -1;
	}
	else duration = atoi(buf); // ������������ ����� (��������� ������� ����������� � 2048 ���. �� 8 �� 30720)
	
	buf = strtok_s(z,".",&z);
	if (strlen(buf)==0) {
		opred = false;
		pitch = -1;
	}
	else pitch = atoi(buf); // ������ ����� (�� 0 �� 3200 ���)
	
	buf = strtok_s(z,".",&z);
	if (strlen(buf)==0) {
		opred = false;
		volume = -1;
	}
	else volume = atoi(buf); // ��������� (�� 0 �� 200 ��)
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
	cout << "�������������� ���������� ����� ���������:\n";
	cout << "1) C������: " << degree << endl;
	cout << "2) ������: " << octave << endl;
	cout << "3) �����: " << timbre << endl;
	cout << "4) ������������: " << duration << endl;
	cout << "5) ������: " << pitch << endl;
	cout << "6) ���������: " << volume << endl;
}

ostream& operator << (ostream& out, Zvuk& z) {
	out << z.degree << "." << z.octave << "." << z.timbre << "." << z.duration << "." << z.pitch << "." << z.volume;
	return out;
}

void Zvuk::setting() { //������� ������������� �����
	if (opred) {
		cout << "���� ��������� ��������.";
	}
	else {
		char* deg = new char [2];
		int y = 0;
		if (degree=="") {
			cout << "\n�� ���������� ������� �����. ������� � �������� (�, B, C, D, E, F, G): ";
			cin >> deg;
			degree = deg;
		}
		if (octave==-1) {
			cout << "\n�� ���������� ������ �����. ������� � �������� (�� 1 �� 9): ";
			cin >> y;
			octave = y;
		}
		if (timbre==-1) {
			cout << "\n�� ���������� ����� �����. ������� ��� �������� (1 - �������, 2 - ������, 3 - ������): ";
			cin >> y;
			timbre = y;
		}
		if (duration==-1) {
			cout << "\n�� ���������� ������������ �����. ������� � �������� (8 �� 30720): ";
			cin >> y;
			duration = y;
		}
		if (pitch==-1) {
			cout << "\n�� ���������� ������ �����. ������� � �������� (�� 0 �� 3200): ";
			cin >> y;
			pitch = y;
		}
		if (volume==-1) {
			cout << "\n�� ���������� ��������� �����. ������� � �������� (�� 0 �� 200): ";
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
	while (yn!="���") {
		cout << "������ �������� �����-���� �������������� �����? (��/���): ";
		cin >> yn;
		if (yn=="���") {
			return;
		}
		cout << "\n������� ����� �������������� ����� �������������� (��. ������ ����): ";
		cin >> c;
		switch (c) {
		case 1:
			cout << "�������  ����� ������� �����: ";
			cin >> degree;
			cout << endl;
			break;
		case 2:
			cout << "�������  ����� ������ �����: ";
			cin >> octave;
			cout << endl;
			break;
		case 3:
			cout << "�������  ����� ����� �����: ";
			cin >> timbre;
			cout << endl;
			break;
		case 4:
			cout << "�������  ����� ������������ �����: ";
			cin >> duration;
			cout << endl;
			break;
		case 5:
			cout << "�������  ����� ������ �����: ";
			cin >> pitch;
			cout << endl;
			break;
		case 6:
			cout << "�������  ����� ��������� �����: ";
			cin >> volume;
			cout << endl;
			break;
		}
	}
}

