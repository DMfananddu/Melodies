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
	//������
	char* degree; // ������������ (�, B, C, D, E, F, G)
	int octave; // ������ ����� (�� 1 �� 9)
	int timbre; // ����� �����: 1 - "�������", 2 - "������", 3 - "������"
	int duration; // ������������ ����� (��������� ������� ����������� � 2048 ���. �� 8 �� 30720)
	int pitch; // ������ ����� (�� 0 �� 3200 ���)
	int volume; // ��������� (�� 0 �� 200 ��)
	int len; // ����� ������ �����
	//��������
	bool opred;
	//�������
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
	//������
	pair <bool, int> prakkol; // ������� ���������� ������� � ��������, ������� ����� �������� �������� ������� � ����� �������� �������
	int quantity; // ���-�� ����� � �����, � ������� ������� ���� �������, ������� ��� ��������
	string name; // �������� �������
	int nahoz; // ���������� � ���������� ������������
	int population[15]; // ���������� ������ � ������� (��������)
	int volume; // ��������� (�� 0 �� 100)
	//��������
	bool opred; // ������� ������������� �������
	CObArray Melody; // ������� ������
	//�������
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
	string CompositionName; // �������� ����������/������������ ������������
	CObArray Composition;
	Compos ();
	Compos (const string&);
	friend ostream& operator<<(ostream&, Compos&);
	void write ();
	void read ();
	void sequencing ();
};