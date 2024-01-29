#include "iostream"
#include "string"
#include"fstream"
using namespace std;
class seat {
	string seatNumber;
	int setValue;
	string passengerName;
	int amjad;
	amjad 3
public:
	void setpassengerName( string name) {
		passengerName = name;
	}
	string getPassengerName()const {
		return passengerName;
	}


	void setSeatNumber( string number) {
		seatNumber = number;
	}
	string getSeatNumber()const {
		return seatNumber;
	}

	bool IsEmpty() {
		if (passengerName=="")
			return 1;
		return 0;

	}
/*/	seat(const seat& obj) {
		cout << "copy is called\n";
		seatNumber = obj.seatNumber;
		IsEmpty = obj.IsEmpty;
	}*/
	seat() { //cout << "defualt seat is called\n"; 

		seatNumber = "",passengerName="";
	}
	seat(string number) {
		cout << "parameterizae is called\n";
		seatNumber = number;
		passengerName = "";

	}

	bool isValid(string seatNo) {
		
		if (seatNumber == seatNo)
			return true;
		
		return false;

	}
	string toString() {
		string out;
		out =  seatNumber+ "  "+passengerName;
	
		return out;
	}
	~seat() {}
};

class flight {
	seat s[42];


public:
	flight() {
		string seatName;
		int z = 0, y = 1, x = 1;
		for (int i = 0;i < 6;i++) {
			if (z % 2) {
				seatName = "C" + to_string(x++);
				s[i].setSeatNumber(seatName);
			}
			else
			{
				seatName = "A" + to_string(y++);
				s[i].setSeatNumber(seatName);
			}
			z++;
		}

	for (int i = 0;i < 6;i++) {
			cout << '\t' << s[i++].getSeatNumber() << '\t' << s[i].getSeatNumber() << endl;
		}

		int w = 4, c = 6;
		for (int i = 0;i < 9;i++)
			for (int j = 0;j < 4;j++) {

				if (j == 0) {
					seatName = "A" + to_string(x++);
					s[c++].setSeatNumber(seatName);
				}
				else if (j == 1)
				{
					seatName = "B" + to_string(w++);
					s[c++].setSeatNumber(seatName);
				}
				else if (j == 2)
				{
					seatName = "C" + to_string(y++);
					s[c++].setSeatNumber(seatName);
				}
				else
				{
					seatName = "D" + to_string(z - 2);
					s[c++].setSeatNumber(seatName);
					z++;
				}
			}
		int p = 6;
		for (int i = 0;i < 9;i++) {
			for (int j = 0;j < 4;j++)
				cout << s[p++].getSeatNumber() << '\t';
			cout << endl;
		}
	}


	void Val() {
		ifstream myFile;
		myFile.open("passengers.txt");
		if (!myFile.is_open()) { cout << "error in opening file\n";return; }
	
		string number, name;
	
		while (myFile >> number >> name) {
			int i;
			for (i = 0;i < 42;i++) {
				if (s[i].isValid(number) && s[i].getPassengerName()=="") {
					s[i].setpassengerName(name);
					
			}
			}

		}
		
		myFile.close();
	}
	bool reserveSeat(string number,string name) {
		int i;
		for (i = 0;i < 42;i++) {
			if (s[i].isValid(number) && s[i].getPassengerName() == "") {
				s[i].setpassengerName(name);
				cout << "this seat is reserved now\n";
				return true;
			}
			
		}
		for (i = 0;i < 42 && s[i].getPassengerName() != "";i++);
		if(i==42)
		{
			cout << "All seats are reserved\n";
			return true;
		}
		else {
			cout << "there is a problem,please check that you enter a correct empty seat\n ";
			cin >> number >> name;
			reserveSeat(number, name);
		}
		
	}
	bool deleteReserved(string number) {
		

		int i;
		for (i = 0;i < 42;i++) {
			if (s[i].isValid(number)) {
			
				s[i].setpassengerName("");
				
				return true;
			}

		}
		cout << "there is a problem,please check that you enter a correct seat number\n ";
		cin >> number;
		deleteReserved(number);
		


	}
	void deleteAll() {
		for (int i = 0;i < 42;i++)
			deleteReserved(s[i].getSeatNumber());
		cout << "you delete all reservation\n";

	}


	void update() {
		ofstream myFile;
		myFile.open("passengers.txt");
		if (!myFile.is_open()) {
			cout << "error in opening file";return;
		}

		for (int i = 0;i < 42;i++)
			myFile << s[i].toString()<<'\n';

		myFile.close();
		
	}



};

void main() {

	flight f;string name, number;
	char a = 's';
	while (a != 'f') {
		cout << "\nenter your choice\n\na. Read passengers' file.\nb. Reserve a newly empty seat\nc.Delete a reserved seat.\nd.Delete all reserved seats.\ne.Update passengers file.\nf Quit.\n";
		cin >> a;
		switch (a) {
		case 'a': {	f.Val();
			break;}
		case 'b': { cout << "\n enter seat number and name respectivly\n";
			cin >> number >> name;
			f.reserveSeat(number, name);
			break;
		case 'c': {
			cout << "\n enter seat number \n";
			cin >> number;
			f.deleteReserved(number);
			cout << "this seat is deleted now\n";
			break;

		}
		case'd': {

			f.deleteAll();
			break;

		}
		case'e': {
			f.update();
			break;
		}
		case'f': {cout << "bye\n";break;}

		default:cout << "please enter a correct choice\n";
		}

		}
	}
}