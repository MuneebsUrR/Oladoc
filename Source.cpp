#include<iostream>
#include<string>
#include <cstdio>
#include<windows.h>
#include<fstream>
#include"P:\OOP\Oladoc\Oladoc\Header.h"
#define ADMINUSER "Admin"/*Predefine user name of admin*/
#define ADMINPASS "Admin123"/*Predefine password of admin*/
using namespace std;
/******************************************Muneeb Ur Rehman**************************************
*                                                                                          I210392                                                                       *
*																					         G                                                                                  *
 *******************************************Final Project OOP***************************************/





void  BankTransfer::getbank() { /*A setter for the information of a bank account*/
	cout << "Enter the bank name = "; cin >> BankName; cout << endl;
	cout << "Enter the Account number = "; cin >> AccountNO; cout << endl;
	cout << "Enter the Pin = "; cin >> Pin; cout << endl;
}



void Etrans::getEtrans() {/*A setter for the information of the E transaction */
	cout << "Enter the Phone number = "; cin >> phoneNo; cout << endl;
	cout << "Enter the E wallet(Jazzcash/Easypaisa) = "; cin >> Etype; cout << endl;
	cout << "Enter the Pin = "; cin >> pin; cout << endl;
}


void payment::settype() { /*Setter for select the type of a payment */
	cout << "Enter the type (Bank transfer or E transaction)" << endl; cin >> paytype; cout << endl;
}


void payment::setamount() {/*setter for the amount of transaction*/
	cout << "Enter the amount you want = "; cin >> amount; cout << endl;
}


long payment::getamount() {
	return amount;
}



void Feedback::giveFeedback() {/*Setter for feedback for patient*/
	cout << "****************************************" << endl;
	cout << "\t\tFeedback" << endl;
	cout << "Rate stars out of five = "; cin >> stars; cout << endl;
	cout << "****************************************" << endl;
	cin.ignore();
	cout << "Write a short review about the appointment : "; getline(cin, review);

}


void Feedback::viewFeedback() {/*A getter to see the feedback*/
	cout << "****************************************" << endl;
	cout << "\t\tFeedback" << endl;
	cout << "\t\t" << stars << endl;
	cout << "****************************************" << endl;
	cout << "\t\tReview:" << endl << review;
}




void Time::settime() {/*Set time for appointments*/

	cout << "Enter the day = "; cin >> day;
	cout << "Enter thestart  hours = "; cin >> hours;
	cout << "Enter the Ending hours = "; cin >> Ehour;

}


void Time::showtime() {/*To display the set time for appointments*/
	cout << "Day = " << day << endl;
	cout << " Start Hours =  " << hours << endl;
	cout << "Ending hours = " << Ehour << endl;
}


	void appointment::setstatus() {
		cout << "Enter the status(approved or reject) = "; cin >> status; cout << endl;
	}


	string appointment::getmode() {
		return appointmentMode;
	}


	string appointment::getstatus() {
		return status;
	}


	void appointment::setapptime() {
		timing.settime();
	}


	void appointment::getapptime() {
		timing.showtime();
	}
	

void appointment::Payment() {
	system("cls");
	cout << "***********************************************************************************************************************" << endl;
	cout << "\t\t\t\t\tOLADOC\n\t\t\tFind and book the best doctor near you" << endl;
	cout << "***********************************************************************************************************************" << endl;
	setamount();
	settype();
	if (paytype == "banktransfer") {
		getbank();
		cout << "Payment successful";
		for (int i = 0; i < 5; i++)

		{

			cout << ".";

			Sleep(500);

		}
		system("cls");
	}
	if (paytype == "Etransaction") {
		getEtrans();
		cout << "Payment successful";
		for (int i = 0; i < 5; i++)

		{

			cout << ".";

			Sleep(500);

		}
		system("cls");
	}
}

/*A function to check the stronger pass*/
bool checkPass(string p) {
	for (int i = 0; i < p.size(); i++) {
		if (isupper(p[i]))
			return true;
		else
			return false;
	}
}

void patient::setpat() {/*A setter for patient info*/

	cout << "Enter your Name = "; cin >> Name; cout << endl;
backCNIC:

	if (CNIC.size() != 13) {  
		cout << "Enter user CNIC(13-digit) = "; cin >> CNIC; cout << endl;
		goto backCNIC;
	}

	cout << "Enter your password = "; cin >> pass; cout << endl;
backPass:
	bool check;
	check = checkPass(pass);
	
	if (pass.size() < 8 and check==false) {
		cout << "Enter again strong password = "; cin >> pass; cout << endl;
		goto backPass;
	}
	balance = 3500;/*Inital balance is 3500 for every patient*/
}


void patient::getpat() {
	cout << " Name = " << Name << endl;
	cout << " CNIC = " << CNIC << endl;

	if (appointmentMode != "") {  /*Only show appointment if it is booked*/
		cout << "Appointment mode = " << appointmentMode << endl;
	}
}


string patient::getName() {
	return Name;
}


string patient::getPass() {
	return pass;
}


void doctor::setdoc() {/*A setter for doctor info*/
	cout << "Enter your Name = "; cin >> Name; cout << endl;
	cout << "Enter your CNIC = "; cin >> CNIC; cout << endl;
CNIC:
	if (CNIC.size() != 13) {
		cout << "Enter user CNIC(13-digit) = "; cin >> CNIC; cout << endl;
		goto CNIC;
	}
	cout << "Enter your password = "; cin >> pass; cout << endl;
Pass:
	bool check;
	check = checkPass(pass);
	if (pass.size() < 8 and check==false) {

		cout << "Enter again strong password = "; cin >> pass; cout << endl;
		goto Pass;

	}
	cout << "Enter your Email = "; cin >> Email; cout << endl;
	cout << "your degree type = "; cin >> type; cout << endl;
	cout << "Enter your Hospital = "; cin >> hospital; cout << endl;
	timing.settime(); /*Composing timing information from the timing class*/
	cout << "Enter your charges for appointment = "; cin >> charges; cout << endl;
}


void doctor::getdoc() {/*A getter for doctor info*/
	cout << " Name = " << Name << endl;
	cout << " CNIC = " << CNIC << endl;
	cout << " Email = " << Email << endl;
	cout << " degree type = " << type << endl;
	cout << " Hospital = " << hospital << endl;
	timing.showtime();
	cout << "Charges for in person appointment = " << charges << endl;
	long vcharges = charges * 70 / 100;/*Calculating the video appointment charges*/
	cout << "Charges for video conultation appointment  = " << vcharges << endl;
}



/*Static data member */
int user::ptotal = 0;
int user::dtotal = 0;
/**********************/

/*File operation */
void writeP(patient obj,string fileName) {
	ofstream of;
	of.open(fileName, ios::app);
	of << obj.CNIC << "\t\t" << obj.Name<<" \t\t"<<obj.pass << endl;
	of.close();
}

void writeD(doctor obj, string fileName) {
	ofstream of;
	of.open(fileName, ios::app);
	of << obj.CNIC << "\t\t" << obj.Name << " \t\t" << obj.pass << " \t\t" << obj.Email << " \t\t" << obj.type << " \t\t" << obj.Email << " \t\t" << obj.charges << " \t\t"; obj.timing.showtime();cout << endl;
	of.close();
}

void writeF(patient obj, string fileName) {
	
}
/****************************/


void user::Reg() {/*Registration module*/
	system("cls");
	cout << "***********************************************************************************************************************" << endl;
	cout << "\t\t\t\t\tOLADOC\n\t\t\tFind and book the best doctor near you" << endl;
	cout << "***********************************************************************************************************************" << endl;
	int input = 0;
	//ofstream of("Patient.bin", ios::app);
	while (input != 3) {
	start:
		cout << "Register\n1.Patient\n2.Doctor\n3.Log In" << endl;
		cin >> input;

		switch (input) {

		case 1:
			system("cls");
			cout << "***********************************************************************************************************************" << endl;
			cout << "\t\t\t\t\tOLADOC\n\t\t\tFind and book the best doctor near you" << endl;
			cout << "***********************************************************************************************************************" << endl;

			obj[ptotal].setpat();
			for (int i = 0; i < ptotal; i++) {

				if (obj[i].CNIC == obj[ptotal].CNIC) {

					cout << "Enter Different CNIC again = "; cin >> obj[ptotal].CNIC;/*checking for not having same CNIC */

				}
			}
		 
			writeP(obj[ptotal],"Patient.txt"); /*Writing */

			ptotal++;/*total index*/


			cout << "Your new id is creating please wait";

			for (int i = 0; i < 5; i++)

			{

				cout << ".";

				Sleep(500);

			}

			cout << "\n\t\t\tYour account is created successfully" << endl;
			for (int i = 0; i < 5; i++)

			{

				Sleep(500);

			}

			system("cls");
			cout << "\t\t\t\t\tOLADOC\n\t\t\tFind and book the best doctor near you" << endl;
			break;


		case 2:
			system("cls");
			cout << "\t\t\t\t\tOLADOC\n\t\t\tFind and book the best doctor near you" << endl;

			obj2[dtotal].setdoc();
			for (int i = 0; i < dtotal; i++) {

				if (obj2[i].CNIC == obj2[dtotal].CNIC) {

					cout << "Enter Different CNIC again = "; cin >> obj2[dtotal].CNIC;/*checking for not having same CNIC */

				}
			}


			for (int i = 0; i < dtotal; i++) {
				if (obj2[i].hospital == obj2[dtotal].hospital) {

					cout << "Enter Different Hospital again = "; cin >> obj2[dtotal].hospital;
				}
			}

			writeD(obj2[dtotal], "Doctor.txt");
			dtotal++;

			cout << "Your new id is creating please wait";

			for (int i = 0; i < 5; i++)

			{

				cout << ".";

				Sleep(500);

			}
			cout << "\n\t\t\tYour account is created successfully" << endl;
			for (int i = 0; i < 5; i++)

			{

				Sleep(500);

			}
			system("cls");
			cout << "\t\t\t\t\tOLADOC\n\t\t\tFind and book the best doctor near you" << endl;

			break;
		case 3:
			break;
		}

	}
}


bool user::searchdoc() {/*Search doctor module for appointment */
	system("cls");
	int choose; string type; string hos;
	cout << "\t\t\t\t\tOLADOC\n\t\t\tFind and book the best doctor near you" << endl;
	cout << "select the option to find doctor\n1.Doctor Type\n2.Doctor Hospital" << endl; cin >> choose;
	switch (choose) {

	case 1:

		system("cls");
		cout << "\t\t\t\t\tOLADOC\n\t\t\tFind and book the best doctor near you" << endl;
		cout << "Enter the Type of doctor = "; cin >> type;
		for (int i = 0; i < dtotal; i++) {

			if (type == obj2[i].type) { /*Oppoint by the type of the doctor */

				obj2[i].getdoc(); char select;

				cout << "Do you want appointment with this doctor(y/n)"; cin >> select;
				if (select == 'y') {

					if (obj[pindex].balance < obj2[i].charges) { /*Checking account balance */

						obj[pindex].Payment();

						obj[pindex].balance += obj[pindex].amount;
					}

					obj[pindex].need = type;

					obj2[i].ID = i;

					return true;
				}
				else if (select == 'n')
					return false;
			}
			else if (type != obj2[i].type)

				cout << "No such record found sorry" << endl;
		}
		break;

	case 2:

		system("cls");
		cout << "\t\t\t\t\tOLADOC\n\t\t\tFind and book the best doctor near you" << endl;
		cout << "Enter the Hospital of doctor = "; cin >> hos;

		for (int i = 0; i < dtotal; i++) {

			if (hos == obj2[i].hospital) {/*Appoint bye the hsopital of the doctor */

				obj2[i].getdoc(); char select;

				cout << "Do you want appointment with this doctor(y/n)"; cin >> select;

				if (select == 'y') {

					if (obj[pindex].balance < obj2[i].charges) {

						obj[pindex].Payment();

						obj[pindex].balance += obj[pindex].amount;

					}

					obj[pindex].need = hos;

					obj2[i].ID = i;
					return true;
				}
				else if (select == 'n')
					return false;
			}

			else if (hos != obj2[i].hospital)

				cout << "No such record found sorry" << endl;
		}
		break;
	}
}


void user::cancelapp() {/*cancellation of appointment module*/
	system("cls");
	char choose;

	cout << "\t\t\t\t\tOLADOC\n\t\t\tFind and book the best doctor near you" << endl;

	for (int i = 0; i < dtotal; i++) {

		if (obj2[i].type == obj[pindex].need || obj2[i].hospital == obj[pindex].need) {

			obj2[i].getdoc();

			cout << "Do you want to cancel appointment  (y/n)" << endl; cin >> choose;

			if (choose == 'y') {

				obj[pindex].need = "";

				cout << "We are cancelling your appointment";
				for (int i = 0; i < 5; i++)

				{

					cout << ".";

					Sleep(400);

				}
				cout << endl;
			}

			if (choose == 'n')
				break;
		}

		else
			cout << "No appointment is booked yet" << endl;
	}
}


void user::login() {/*Login module */
	system("cls");
	cout << "***********************************************************************************************************************" << endl;
	cout << "\t\t\t\t\tOLADOC\n\t\t\tFind and book the best doctor near you" << endl;
	cout << "***********************************************************************************************************************" << endl;
	string namecheck, passcheck;
	int input;
	//ifstream ifs("Patient.bin", ios::app);
	
	cout << "Login as :\n1.patient\n2.Doctor\n3.Admin" << endl; cin >> input;
	switch (input) {

	case 1:
		userType = "Patient";
	checkpat:
		system("cls");
		cout << "\t\t\t\t\tOLADOC\n\t\t\tFind and book the best doctor near you" << endl;
	
		cout << "Enter your Name = "; cin >> namecheck;
		cout << "Enter your password = "; cin >> passcheck;
		for (int i = 0; i < ptotal; i++) {

			if (namecheck != obj[i].Name && passcheck != obj[i].pass) {
				/*checking for wrong info*/
				cout << "Try again\n"; i--;
				for (int i = 0; i < 5; i++)

				{

					cout << ".";

					Sleep(400);

				}
				goto checkpat;
			}

			else if (namecheck == obj[i].getName() and passcheck == obj[i].getPass()) {

				pindex = i;
				cout << "Login in please wait";
				for (int i = 0; i < 5; i++)

				{

					cout << ".";

					Sleep(500);

				}
			}
			
		}

		break;
	case 2:

		userType = "Doctor";
		system("cls"); int dchoice;
		cout << "\t\t\t\t\tOLADOC\n\t\t\tFind and book the best doctor near you" << endl;
	checkdoc:

		cout << "Enter your name = "; cin >> namecheck;
		cout << "Enter your password = "; cin >> passcheck;
		for (int i = 0; i < dtotal; i++) {

			if (namecheck == obj2[i].Name && passcheck == obj2[i].pass) {
				dindex = i; 
				cout << "Login in please wait";
				for (int i = 0; i < 5; i++)

				{

					cout << ".";

					Sleep(500);

				}
			}
			else if (namecheck != obj2[i].Name && passcheck != obj2[i].pass) {

				cout << "Try again\n"; i--;
				for (int i = 0; i < 5; i++)

				{

					cout << ".";

					Sleep(400);

				}
				goto checkdoc;
			}

		}
		break;
	case 3:
		userType = "Admin";
	checkAd:
		system("cls");
		cout << "\t\t\t\t\tOLADOC\n\t\t\tFind and book the best doctor near you" << endl;
		cout << "Enter your User Name = "; cin >> namecheck;
		cout << "Enter your password = "; cin >> passcheck;

		if (namecheck != ADMINUSER and passcheck != ADMINPASS) {
			cout << "Try Again";
			for (int i = 0; i < 5; i++)

			{

				cout << ".";

				Sleep(400);

			}
			goto checkAd;
		}

		else if (namecheck == ADMINUSER and passcheck == ADMINPASS) {
			cout << "Login in please wait";
			for (int i = 0; i < 5; i++)

			{

				cout << ".";

				Sleep(500);

			}
		}
	}
}


void Admin::displayAdmin() {
	cout << "User Name  = " << ADMINUSER << endl;
	cout << "Password  = " << ADMINPASS << endl;
}



void oladoc::menu() { /*Main menu */
start:
	obj.Reg();

	obj.login();

	if (obj.userType == "Patient") {/*checking the user*/
		int choice;
		ofstream ofeed;
		ofeed.open("Feedback.txt", ios::app);/*Writng feedback */

		system("cls");
		if (obj.obj[obj.pindex].getstatus() == "Approved" || obj.obj[obj.pindex].getstatus() == "approved") {

			obj.obj[obj.pindex].giveFeedback();

			cout << endl;
			ofeed<<obj.obj[obj.pindex].review<<endl;

			ofeed.close();
			
			obj.obj[obj.pindex].status = "";
			cout << "//////////////////////////////////////////////////////" << endl;
			cout << "\t\t\t\tManagement ! \n\t\tThanks for your feedback" << endl;/*Mesage by the management*/
			for (int i = 0; i < 5; i++)

			{

				cout << ".";

				Sleep(400);

			}
			cout << "//////////////////////////////////////////////////////" << endl;
			cin.ignore();
			char c;
			c=getchar();
			//getchar();
			system("cls");
		}

		while (1) {
			cout << "***********************************************************************************************************************" << endl;
			cout << "\t\t\t\t\tOLADOC\n\t\t\tFind and book the best doctor near you" << endl;
			cout << "***********************************************************************************************************************" << endl;
			cout << "Welcome Mr/Ms " << obj.obj[obj.pindex].getName()<<endl;

			cout << "1.Book appointment\n2.logout\n3.view information\n4.Edit information\n5.View balance\n6.Recharge Account\n7.Cancel Appointment" << endl;

			cin >> choice;
			switch (choice) {
			case 1:
				system("cls");
				cout << "\t\t\t\t\tOLADOC\n\t\t\tFind and book the best doctor near you" << endl;

				obj.searchdoc();
				cout << "Select the appointment mode(video / In-person) = "; cin >> obj.obj[obj.pindex].appointmentMode;
				cout << "Your appointment is booking . Please wait";
				for (int i = 0; i < 5; i++)

				{

					cout << ".";

					Sleep(400);

				}
				cout << endl;
				break;

			case 2:
				goto start;
				break;

			case 3:
				obj.obj[obj.pindex].getpat();

				break;
			case 4:

				obj.obj[obj.pindex].setpat();

				break;

			case 5:
				system("cls");
				cout << "\t\t\t\t\tOLADOC\n\t\t\tFind and book the best doctor near you" << endl;
				cout << "*****************************************************************************************" << endl;
				cout << "\n\t\t\t\t\tBalance = " << obj.obj[obj.pindex].balance << endl;
				cout << "*****************************************************************************************" << endl;
				break;

			case 7:
				system("cls");
				cout << "\t\t\t\t\tOLADOC\n\t\t\tFind and book the best doctor near you" << endl;
				obj.cancelapp();
				break;

			case 6:
				obj.obj[obj.pindex].Payment();
				obj.obj[obj.pindex].balance += obj.obj[obj.pindex].amount;
				break;

			}
		}
	}


	if (obj.userType == "Doctor") {
		system("cls");

		while (1) {
			cout << "***********************************************************************************************************************" << endl;
			cout << "\t\t\t\t\tOLADOC\n\t\t\tFind and book the best doctor near you" << endl;
			cout << "***********************************************************************************************************************" << endl;
			cout << "Welcome Mr/Ms " << obj.obj2[obj.dindex].Name<<endl;
			cout << "1.Show appointments\n2.logout\n3.view details\n4.Edit details\n5.View Feedbacks" << endl; int dchoice = 0;
			cin >> dchoice;
			int count = 0;
			switch (dchoice) {

			case 1:
				system("cls");
				cout << "\t\t\t\t\tOLADOC\n\t\t\tFind and book the best doctor near you" << endl;

				for (int i = 0; i < obj.ptotal; i++) {
					if (obj.obj[i].need == obj.obj2[obj.dindex].type || obj.obj[i].need == obj.obj2[obj.dindex].hospital) {
						obj.obj[i].getpat();
						count = 1;
					}
				}

				if (count != 1) {
					cout << "No record for you " << endl;
				}

				else if (count == 1) {
					string CN;
					cout << "Enter the CNIC of a patient = "; cin >> CN; cout << endl;

					for (int i = 0; i < obj.ptotal; i++) {
						if (obj.obj[i].CNIC == CN) {
							obj.obj[i].getpat();

							obj.obj[i].setstatus();

							if (obj.obj[i].getstatus() == "approved" || obj.obj[i].getstatus() == "Approved") {

								obj.obj[i].need = "";

								if (obj.obj[obj.pindex].getmode() == "video" || obj.obj[obj.pindex].getmode() == "Video") {

									obj.obj[i].balance -= obj.obj2[obj.dindex].charges * (70 / 100);
								}

								else
									obj.obj[i].balance -= obj.obj2[obj.dindex].charges;
							}

							else if (obj.obj[i].getstatus() == "Reject" || obj.obj[i].getstatus() == "reject") {
								obj.obj[i].need = "";
							}
						}
					}
				}

				break;

			case 2:
				goto start;
				break;

			case 3:
				obj.obj2[obj.dindex].getdoc();
				break;

			case 4:
				obj.obj2[obj.dindex].setdoc();
				break;
			case 5:
				system("cls");
				cout << "\t\t\t\t\tOLADOC\n\t\t\tFind and book the best doctor near you" << endl;
				cout << "**********************************Your Rating*************************************" << endl;
				srand(time(NULL));
				double r = rand()%5;
				cout << "\t\t\tRating = " << r << endl;
				cout << "**********************************Your Rating*************************************" << endl;
				break;
			}
		}
	}
	if (obj.userType == "Admin") {

		system("cls");
		string CNIC; int count = 0;
		while (1) {

			cout << "***********************************************************************************************************************" << endl;
			cout << "\t\t\t\t\tOLADOC\n\t\t\tFind and book the best doctor near you" << endl;
			cout << "***********************************************************************************************************************" << endl;
			cout << "1.Add Doctor/Patient\n2.logout\n3.view doctor\n4.Edit doctor\n5.View all Patient\n6.View appointment" << endl; int achoice = 0;
			cin >> achoice;
			switch (achoice) {

			case 1:
				obj.Reg();
				break;

			case 2:
				goto start;
				break;

			case 3:
				cout << "\t\t\t\t\tOLADOC\n\t\t\tFind and book the best doctor near you" << endl;
				cout << "Enter the CNIC of the doctor you want to search : "; cin >> CNIC;cout << endl;
				for (int i = 0; i < obj.dtotal; i++) {

					if (CNIC == obj.obj2[i].CNIC) {
						obj.obj2[i].getdoc();
					}

					else
						cout << "No record find !" << endl;
				}

				break;

			case 4:
				cout << "Enter the CNIC of the doctor you want to Edit : "; cin >> CNIC; cout << endl;
				for (int i = 0; i < obj.dtotal; i++) {

					if (CNIC == obj.obj2[i].CNIC) {
						obj.obj2[i].setdoc();
					}

					else
						cout << "No record find !" << endl;
				}

				break;

			case 5:
				system("clear");
				cout << "\t\t\t\t\tOLADOC\n\t\t\tFind and book the best doctor near you" << endl;
				for (int i = 0; i < obj.ptotal; i++) {

					obj.obj[i].getpat();
				}

				break;

			case 6:
				system("clear");

				cout << "\t\t\t\t\tOLADOC\n\t\t\tFind and book the best doctor near you" << endl;
				cout << "Enter the CNIC of a doctor to check the appointments = "; cin >> CNIC; cout << endl;

				for (int i = 0; i < obj.dtotal; i++) {

					if (obj.obj2[i].CNIC == CNIC) {

						obj.obj2[i].getdoc();

						cout << "Appointments of this doctor : " << endl;

						for (int i = 0; i < obj.ptotal; i++) {

							if (obj.obj[i].need == obj.obj2[obj.dindex].type || obj.obj[i].need == obj.obj2[obj.dindex].hospital) {
								obj.obj[i].getpat();
								count = 1;
							}
						}
						if (count != 1) {
							cout << "No record for you " << endl;
						}
					}
					else
						cout << "Wrong info sorry" << endl;
				}
				break;
			}

		}
	}

}

int main() {
	oladoc obj;
	obj.menu();
	return 0;
}