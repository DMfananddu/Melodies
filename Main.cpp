#pragma once
#include "KLR.h"

//-----------------------������� ����
int menu(int &wod) {
	cout<<"============== ������� � ����� ==============\n";
	cout<<"   1. ������ ������������ ������������\n   2. ������ ������������ ������������\n";
	cout<<"   3. ������ ������������ ������������ � ����\n   4. ������ �������\n";
	cout<<"   5. ������ �������\n   6. �������� ������� � ����\n";
	cout<<"   7. ��������� ������������� �������, ��������� � ����������\n";
	cout<<"   8. �������� �����\n";
	cout<<"   9. ���������� ����� � �������, ��������� � ����������\n";
	cout<<"   10. �������� ����� �� �������, ��������� � ����������\n";
	cout<<"   11. �������� ������� �� ����������\n";
	cout<<"   12. �����\n";
	cout<<"=============================================\n\n\n";
	cin >> wod;
	cout<<"\n\n\n";
	if (wod >= 1 && wod <= 11) {
		return wod;
	}                           
	cout << "������������ ����. ";
	cout << "������������ ������� �������� �� �������� 1-11\n";
	return 0;
}

//-----------------------������� MAIN
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
		cout << "������� ����� ������������� ��� ������ ������ ���������: \n";
		switch (menu(n)) {
			case 1:
				cout << "������� �������� ����������: ";
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
				cout << "������� �������� �������: ";
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
				cout << "������� �������� ����������: ";
				cin >> C1.CompositionName;
				C1.read();
				cout << C1;
				cout << "������� ����� �������: ";
				cin >> m;
				m--;
				(*(Melod*)C1.Composition[m]).editing_ch();
				C1.sequencing();
				cout << C1 << endl;
				break;
			case 8:
				cout << "������ ����...\n";
				Z1.setting();
				cout << "���� ������";
				Z1.print();
				cout << endl;
				break;
			case 9:
				cout << "������� �������� ����������, � ������� ������ �������� ����: ";
				cin >> C1.CompositionName;
				C1.read();
				C1.sequencing();
				cout << C1 << endl;
				Z1.print();
				cout << "� ����� ������� �� ������ �������� �������� ����?\n";
				cout << "������� ����� �������: ";
				cin >> m;
				m--;
				(*(Melod*)C1.Composition[m]).print();
				cout << "\n������� ����� ����� (� ������� � �����): ";
				cin >> k;
				k--;
				(*(Melod*)C1.Composition[m]).Melody.InsertAt(k, new Zvuk(Z1));
				(*(Melod*)C1.Composition[m]).print();
				break;
			case 10:
				C1.sequencing();
				cout << C1;
				cout << "������� ����� �������: ";
				cin >> m;
				m--;
				(*(Melod*)C1.Composition[m]).print();
				cout << "\n������� ����� ����� (� ������� � �����): ";
				cin >> k;
				k--;
				(*(Melod*)C1.Composition[m]).Melody.RemoveAt(k);
				cout << "\n���� ������\n";
				(*(Melod*)C1.Composition[m]).print();
				cout << endl;
				break;
			case 11:
				C1.sequencing();
				cout << C1;
				cout << "������� ����� �������: ";
				cin >> m;
				m--;
				C1.Composition.RemoveAt(m);
				cout << "\n������� �������\n";
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
