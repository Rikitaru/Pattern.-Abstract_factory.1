#include "Army.h"
#include "Cold_war.h"
#include "Russian_ArmyFactory.h"
#include "USA_ArmyFactory.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	Cold_war cold_war;
	Russian_ArmyFactory RU_factory;
	USA_ArmyFactory US_factory;

	const char * filename_RU = "Russian_army.dat";
	const char * filename_US = "USA_army.dat";

	Army * RU = nullptr;
	Army * US = nullptr;

	/////////////////////////
	/*���������������� ����*/
	/////////////////////////

	int swtch1 = 1;

	while (swtch1 != 0) {
		cout << endl << endl << "�������� ��������:" << endl <<
			"|1| <-> ���������� ������� ����" << endl <<
			"|2| <-> ������������ ������� ����" << endl <<
			"|3| <-> �������� ���� ���������� � ������������ ������� ���" << endl <<
			"|0| <-> �����" << endl;
		cin >> swtch1;
		switch (swtch1)
		{
		case 1:
			cout << "�������� ��������: " << endl <<
				"|1| <-> ������� ����� ����������" << endl <<
				"|2| <-> ��������� ��������� ����������" << endl <<
				"|0| <-> �����" << endl;
			cin >> swtch1;
			switch (swtch1)
			{
			case 1:
				SetColor(15, 1);
				cout << endl << endl << "�������� ���������� ������� ����:" << endl;
				RU = cold_war.createArmy(RU_factory);
				RU->set();
				RU->Who_is_more_powerful();
				RU->info();
				RU->save_to_file(filename_RU);
				break;
			case 2:
				SetColor(15, 1);
				RU = new Army;
				RU->read_from_file(filename_RU, RU_factory);
				RU->info();
				break;
			default:
				break;
			}
			break;
		case 2:
			cout << "�������� ��������: " << endl <<
				"|1| <-> ������� ����� ����������" << endl <<
				"|2| <-> ��������� ��������� ����������" << endl <<
				"|0| <-> �����" << endl;
			cin >> swtch1;
			switch (swtch1)
			{
			case 1:
				SetColor(15, 1);
				cout << endl << endl << "�������� ������������ ������� ����:" << endl;
				US = cold_war.createArmy(US_factory);
				US->set();
				US->Who_is_more_powerful();
				US->info();
				US->save_to_file(filename_US);
				break;
			case 2:
				SetColor(15, 1);
				US = new Army;
				US->read_from_file(filename_US, US_factory);
				US->info();
				break;
			default:
				break;
			}
			break;
		case 3:
			if (RU == nullptr)
			{
				SetColor(15, 1);
				RU = new Army;
				RU->read_from_file(filename_RU, RU_factory);
			}
			if (US == nullptr)
			{
				SetColor(15, 1);
				US = new Army;
				US->read_from_file(filename_US, US_factory);
			}

			cout << "\t������� ����" << endl;
			cout << "���������� ������� ����    --> " << setw(5) << RU->get_requirement_power() << endl;
			cout << "������������ ������� ����  --> " << setw(5) << US->get_requirement_power() << endl;

			break;
		default:
			break;
		}
	}

	if (RU != nullptr) delete RU;
	if (US != nullptr) delete US;

	system("pause");
	return 0;


}