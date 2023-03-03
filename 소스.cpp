//A클래스가 B클래스를 대상으로 friend 선언을 하면, B클래스는 A클래스의 private 멤버에 직접 접근이 가능하다.

#include<iostream>
#include<cstring>
using namespace std;

class Girl;	//Boy에 friend로 접근하기 위해선 먼저 선언할 필요가 있다.

class Boy
{
	int height;
	friend class Girl;	//friend 선언은 private 공간에 해도 좋고, public 공간에 해도 좋다.
public:
	Boy(int len):height(len){}
	void ShowYourFriendInfo(Girl& frn);
};

class Girl
{
	char phNum[20];
public:
	Girl(const char* num) { strcpy(phNum, num); }
	void ShowYourFriendInfo(Boy& frn);
	friend class Boy;
};

void Boy::ShowYourFriendInfo(Girl& frn) { cout << "Her phone number: " << frn.phNum << endl; }
void Girl::ShowYourFriendInfo(Boy& frn) { cout << "His height: " << frn.height << endl; }

int main()
{
	Boy boy(170);
	Girl girl("010-1234-5678");
	boy.ShowYourFriendInfo(girl);
	girl.ShowYourFriendInfo(boy);
	return 0;
}