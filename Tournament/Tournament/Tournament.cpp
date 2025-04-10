#include<string>
#include<iostream>
#include<ctime>

using namespace std;

struct Student
{
	string name;
	int hp;
	int dmg;
	int luck;
	Student(string name, int hp = 100, int dmg = 5, int luck = 10) :
		name(name), hp(hp), dmg(dmg), luck(luck)
	{
	}

	Student(const Student& student) :
		name(student.name),
		hp(student.hp),
		dmg(student.dmg),
		luck(student.luck)
	{
	}

	~Student()
	{
	}

	bool luckWorks()
	{
		return (rand() % 100 < luck);
	}

	bool isDead()
	{
		return (hp < 1);
	}

	void getDmg(int dmg)
	{
		if (luckWorks())
		{
			cout << "\t" << name << " LUCK WORKS FOR GETTING DAMAGE\n";
			dmg /= 2;
		}
		hp -= dmg;
	}

	int makeDmg()
	{
		if (luckWorks())
		{
			cout << "\t" << name << " LUCK WORKS FOR MAKING DAMAGE\n";
			return dmg * 2;
		}
		else
		{
			return dmg;
		}
	}

	void print()
	{
		cout << name << " [" << hp << "] (";
		cout << "luck=" << luck << ";";
		cout << "damage=" << dmg << ")\n";;
	}
};
int battle(Student st1, Student st2)
{
	int c = 0;
	int round = 1;
	while (!(st1.isDead() || st2.isDead()))
	{
		cout << "\t\tROUND " << round++ << "\n";
		st1.print();
		cout << "versus\n";
		st2.print();
		st1.getDmg(st2.makeDmg());
		st2.getDmg(st1.makeDmg());
	
	}
	if (st1.isDead() && st2.isDead())
	{
		cout << "DRAW\n";
		c = 1;
	}
	else if(st1.isDead())
	{
		cout <<  st2.name << " wins\n";
		c = 2;
	}
	else 
	{
		cout << st1.name << " wins\n";
		c = 3;
	}
	return c;
}
int winner(Student st1, Student st2)
{
	int result;
	do {
		result = battle(st1, st2);
	} while (result == 1);
	return result;


}
int main()
{
	srand(time(0));
	Student st1("a", 130, 5, 5);     
	Student st2("b", 115, 6, 8);    
	Student st3("c", 95,9, 10);    
	Student st4("d", 105, 5, 15);    
	Student st5("e", 120, 7, 5); 
	Student st6("f", 100, 5, 18);  
	Student st7("g", 110, 6, 10);    
	Student st8("h", 80, 12, 8);
	int wins1 = 0, wins2 = 0;

	for (int i = 0; i < 1000; ++i) {
		Student temp1 = st1, temp2 = st2;
		int res = winner(temp1, temp2);
		if (res == 2) wins2++;
		else wins1++;
	}

	cout << "\n1 " << wins1 << " раз, 2 победил " << wins2 << " раз.\n";

	return 0;
}
