#pragma once
#include<string>
#include<iostream>
using namespace std;

/*All classes declerations(start)*/
class BankTransfer {
public:
	string BankName;
	string AccountNO;
	string Pin;
	void getbank();
};

class Etrans {
public:
	string phoneNo;
	string Etype;
	string pin;
	void getEtrans();
};

class payment :public BankTransfer, public Etrans {
public:
	long amount;
	string paytype;
	void setamount();
	void settype();
	long getamount();
};

class Feedback {
public:
	string stars;
	string review;
	void giveFeedback();
	void viewFeedback();
};


class Time {
public:
	string day;
	int hours;
	int Ehour;
	void settime();
	void showtime();
};



class appointment :public payment {
public:
	string status;
	Time timing;
	string appointmentMode;
	void setstatus();
	string getmode();
	string getstatus();
	void setapptime();
	void  getapptime();
	void Payment();
};

class patient : public appointment, public Feedback {
public:
	string Name, CNIC, pass;
	long balance;
	Time timing;
	string need;
	void setpat();
	void getpat();
	string getName();
	string getPass();

};

class doctor : public appointment, public Feedback {
public:
	string Name, CNIC, pass, Email, type, hospital;
	long charges;
	Time timing;
	int ID;
	void setdoc();
	void getdoc();

};


class user :public patient, public doctor {
public:
	patient obj[4];
	doctor obj2[4];
	string userType;
	int pindex;
	int dindex;
	static int ptotal, dtotal;
	void Reg();
	bool searchdoc();
	void cancelapp();
	void login();

};

class Admin :public user {
public:
	string pass, username;
	void displayAdmin();
};

class oladoc {
public:
	user obj;
	void menu();
};

/*End decleration*/