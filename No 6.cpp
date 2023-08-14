#include <iostream>
#include <algorithm>
#include <limits>
#include <iomanip>
#include <locale>
#include <cstring>
#define MAX 5000 		// Define hard storage limit

using namespace std;

// --------------------------------------------------------------------------
// Utils
// --------------------------------------------------------------------------
class Utils : public numpunct<char>{			// using numpunct/locale_facets.h for custom format
	protected:
		virtual char do_thousands_sep() const{	// custom format
			return '.';
		};
		virtual string do_grouping() const{		// custom format
			return "\03";
		};
	private:

	public:
		int DigitCheck(int,int);
		string Uppercase(string);
		void clear();
		void pause();
};

// -----------------------------	Uppercase String
string Utils::Uppercase(string input){
    transform(input.begin(), input.end(), input.begin(), ::toupper);
    return input;
}

// -----------------------------	Digit Check, portable code thats why it use var limit
int Utils::DigitCheck(int input,int limit){
	while(!(cin >> input && (!(input > limit )))){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');		// flush buffer inside loop
		cerr<<endl<<"Input Salah."<<endl<<"Masukan Angka 1-"<<limit<<endl<<"Input : ";
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');			// flush buffer outside loop
	return input;
}

// -----------------------------	Clear
void Utils::clear(){	// use loop endl, more portable
	for (int i=0;i<50; i++){
		cout << endl;
	}
}

// -----------------------------	Pause
void Utils::pause(){
	string temp;
	cout << "Press enter to continue..";
	getline(cin, temp);
	cin.clear();
}
// --------------------------------------------------------------------------
// CODE START
// --------------------------------------------------------------------------
// -----------------------------	Base Class


class Data{			// base class to hold member
	protected:
		int BillNum=0;
		int InputFlag=0;
		int ImportFlas=0;
		struct POSsys {
			char sDMenu[8],sDSize[8],sDTemp[8];
			int sPrice,sBillSaved=0;
		}arr_bill[MAX];

		// static data for menu
		char Sptr[4][8] = {"KECIL","SEDANG","BESAR"};
		char Tptr[3][7] = {"BUBBLE","KEJU","AGAR"};
	private:
	public:
};

class Proccess : public virtual Data {			// class holding all function
	protected:
	private:
	public:
		// using namespase, only init placed here
		void debug();
		void InputKasir();
		void InputData();
		void MenuCheck();
		void PriceCalcal();
		void PrintTemp();
		void YNCheck();
		void ViewHistory();
		void DeleteHistory();
		void ExportList();
		void ImportList();
};


// -----------------------------	Export List
void Proccess::ExportList(){
	int TotalPenjualan = 0;
	FILE *file = fopen("dataminuman.txt", "w+");
	fprintf(file,"\n|*                         INVOICE\n\n");
	fprintf(file,"|~~~~~|~~~~~~~~~~~~|~~~~~~~~~~~~~|~~~~~~~~~~~~~|~~~~~~~~~~~~~|\n");
	fprintf(file,"| No. |  Minuman   |   Ukuran    |  Penyajian  |    Harga    |\n");
	fprintf(file,"|-----|------------|-------------|-------------|-------------|\n");
	for(int a = 0; a < MAX; a++ ){
	    if (arr_bill[a].sBillSaved != 0){
			fprintf(file,"|%3d. |  %-10s|   %-10s|   %-10s|    %-9d|\n",a+1,arr_bill[a].sDMenu,arr_bill[a].sDSize,arr_bill[a].sDTemp,arr_bill[a].sPrice);
			TotalPenjualan += arr_bill[a].sPrice;
//			if (arr_bill[a].sPriceF == 0){
//				TotalPenjualan += arr_bill[a].sPrice;
//				arr_bill[a].sPriceF = 1;
//			}
		}
	}
	fprintf(file,"|^    |            |             |             |             |\n");
	fprintf(file,"|-----|------------|-------------|-------------|-------------|\n");
	fprintf(file,"                                               |    TOTAL    |\n");
	fprintf(file,"                                               |    %-9d|\n",TotalPenjualan);
	fprintf(file,"                                               |_____________|");
	fclose(file);
}

// -----------------------------	Print Temp Input
void Proccess::PrintTemp(){
	if (arr_bill[BillNum].sBillSaved == 1){
		cout << "\n\n";
		cout << "-----------------------------------------\n";
		cout << "Bill No		: " << BillNum+1 << endl;
		cout << "Minuman		: " << arr_bill[BillNum].sDMenu << endl;
		cout << "Ukuran		: " << arr_bill[BillNum].sDSize << endl;
		cout << "Penyajian	: " << arr_bill[BillNum].sDTemp << endl;
		cout << "Harga		: " << arr_bill[BillNum].sPrice << endl;
		cout << "-----------------------------------------\n";
	}
}

// -----------------------------	YN Check
void Proccess::YNCheck(){
	Utils utl;

	char input[1];	//yn var
	cout << "\nMasukan Data Bill?\n\n Y/N\n\nINPUT	: ";
	cin >> input;

	if ((strcmp(input, "n" ) == 0) || (strcmp(input, "N" ) == 0))	{
		arr_bill[BillNum].sBillSaved = 0;
		utl.clear();
     	cout << "Bill di batalkan\n\n";
    }
    else if ((strcmp(input, "y" ) == 0) || (strcmp(input, "Y" ) == 0)){
		arr_bill[BillNum].sBillSaved = 1;
		utl.clear();
		cout << "-----------------------------------------\n";
		cout << "Input Bill no."<<BillNum+1<< " Berhasil !\n";
		cout << "-----------------------------------------\n";
		BillNum++;
	}
	else {
		utl.clear();
     	cout << "Input salah\n";
		PrintTemp();
		YNCheck();
	}
}


// -----------------------------	Input Kasir
void Proccess::InputKasir(){
	Utils utl;
	if (BillNum==MAX-1){		// cut input when data == hardlimit
		cout << "-----------------------------------------\n";
		cout << "! Storage Penuh !\n";
		cout << "-----------------------------------------\n";
		utl.pause();
		utl.clear();
	}
	else {
		if (arr_bill[BillNum].sBillSaved != 0)
		{
		}
		else {
			InputData();
			utl.clear();
			arr_bill[BillNum].sBillSaved = 1;
			PriceCalcal();
			PrintTemp();
			YNCheck();
//			BillNum++;		// increase N moved to YN Check
		}
	}

}

// -----------------------------	Price Calc
void Proccess::PriceCalcal(){
	if (arr_bill[BillNum].sBillSaved != 0){
		int tDName,tDSize,tDTemp;
		tDName = strlen(arr_bill[BillNum].sDMenu);
		tDSize = strlen(arr_bill[BillNum].sDSize);
		tDTemp = strlen(arr_bill[BillNum].sDTemp);
		arr_bill[BillNum].sPrice = (tDName*tDSize*tDTemp*100);
	}
}

// -----------------------------------------------------------------------------------
void Proccess::InputData(){
	Utils utl;
	cout << endl << "\n		Bill No." << BillNum+1 << endl;
	//-------------------------------------------------------------------
	cout << "\n--------------Nama Minuman---------------\n";
	cout << "\nDaftar Minuman: Kopi, Teh, Coklat, Soda\n\n";
	InputFlag=1;
	cout << "Input		: ";
	MenuCheck();
	utl.clear();
	cout << "Bill No		: " << BillNum+1 << endl;
	cout << "Minuman		: " << arr_bill[BillNum].sDMenu << endl;
	//-------------------------------------------------------------------
	cout << "\n-------------Ukuran Minuman--------------\n";
	cout << "\nUkuran: Small, Medium, Largest\n\n";
	InputFlag=2;
	cout << "Input		: ";
	MenuCheck();
	utl.clear();
	cout << "Bill No		: " << BillNum+1 << endl;
	cout << "Minuman		: " << arr_bill[BillNum].sDMenu << endl;
	cout << "Ukuran		: " << arr_bill[BillNum].sDSize << endl;
	//-------------------------------------------------------------------
	cout << "\n-----------Temperatur Minuman------------\n";
	cout << "\nPenyajian: Dingin, Panas, Hangat\n\n";
	InputFlag=3;
	cout << "Input		: ";
	MenuCheck();
	InputFlag=0;
	//-------------------------------------------------------------------
}

// -----------------------------	MENU Check
void Proccess::MenuCheck(){
	Utils utl;

	char temp[10];
	cin.getline(temp,10);
	// upercase to compare with menu array
	char i;
	for(i=0;temp[i];i++){
	if((temp[i]>=97) && (temp[i]<=122))
	temp[i]-=32;}

	if (InputFlag==1){
		if (strcmp(temp, Mptr[0])==0){
			strcpy(arr_bill[BillNum].sDMenu, "Kopi");}
		else if (strcmp(temp, Mptr[1])==0){
			strcpy(arr_bill[BillNum].sDMenu, "Teh");}
		else if (strcmp(temp, Mptr[2])==0){
			strcpy(arr_bill[BillNum].sDMenu, "Coklat");}
		else if (strcmp(temp, Mptr[3])==0){
			strcpy(arr_bill[BillNum].sDMenu, "Soda");}
		else {
			utl.clear();
			cout << "\n\n! Input Salah !\n";
			cout << "\nNama Minuman: Kopi, Teh, Coklat, Soda\n\nUppercase / Lowercase Valid\n\n";
			cout << "--------------Nama Minuman---------------\n\n";
			cout << "Input		: ";
			MenuCheck();
		}
	}
	else if (InputFlag==2){
		if (strcmp(temp, Sptr[0])==0){
			strcpy(arr_bill[BillNum].sDSize, "Small");}
		else if (strcmp(temp, Sptr[1])==0){
			strcpy(arr_bill[BillNum].sDSize, "Medium");}
		else if ((strcmp(temp, Sptr[2])==0)||(strcmp(temp, Sptr[3])==0)){
			strcpy(arr_bill[BillNum].sDSize, "Largest");}
		else {
			utl.clear();
			cout << "\n\n! Input Salah !\n";
			cout << "\nUkuran: Small, Medium, Largest / Large\n\nUppercase / Lowercase Valid\n\n";
			cout << "-------------Ukuran Minuman--------------\n\n";
			cout << "Input		: ";
			MenuCheck();
		}
	}
	else if (InputFlag==3){
		if (strcmp(temp, Tptr[0])==0){
			strcpy(arr_bill[BillNum].sDTemp, "Dingin");}
		else if (strcmp(temp, Tptr[1])==0){
			strcpy(arr_bill[BillNum].sDTemp, "Panas");}
		else if (strcmp(temp, Tptr[2])==0){
			strcpy(arr_bill[BillNum].sDTemp, "Hangat");}
		else {
			utl.clear();
			cout << "\n\n! Input Salah !\n";
			cout << "\n\n! Input Salah !\n";
			cout << "\nPenyajian: Dingin, Panas, Hangat\n\nUppercase / Lowercase Valid\n\n";
			cout << "-----------Temperatur Minuman------------\n\n";
			cout << "Input		: ";
			MenuCheck();
		}
	}
	else {
		cout << "!! Error !!\n\nInputFlag="<<InputFlag<<"\n\n";
		utl.pause();
	}
}

// -----------------------------
// MAIN
// -----------------------------
int main() {
	Utils utl;
	Proccess pcs;
//	if (ImportFlag == 0){
//		pcs.ImportList();
//		ImportFlag = 1;
//	}
	pcs.ImportList();
	int nChoice = 0;
	do{
		cout << "-----------------------------------------" << endl;
		cout << "PROGRAM POS" << endl << endl;
		cout << "1- Input Data\n2- View History\n3- Delete History\n4- Save & Quit\n";
//		cout << "5- Debug\n";
		cout << "-----------------------------------------" << endl;
		cout << "INPUT : ";
		nChoice = utl.DigitCheck(nChoice,5);	// check input isdigit
		switch (nChoice){
    		case 1:{
				utl.clear();
	    		pcs.InputKasir();
    		}break;
    		case 2:{
//				utl.pause();
				utl.clear();
	    		pcs.ViewHistory();
//				ViewHistory();
			}break;
			case 3:{
				utl.clear();
	         	pcs.DeleteHistory();
			}break;
			case 4:{
				pcs.ExportList();
				printf("\nData Saved to dataminuman.txt\n");
				exit(0);
			}break;
			case 5:{ // ! DEBUG !
				pcs.debug();
			}break;
		}
	}
	while (nChoice != 4);
	return 0;
}
