#include<iostream>
#include<conio.h>
using namespace std;
//---------Xay dung class Time--------------
class Time{
	protected:
		int h,m,s;
	public:
		//Constructor
		Time(){}
		Time(int h, int m, int s){
			this->h=h;
			this->m=m;
			this->s=s;
		}
		//Kiem tra input
		bool checkInputTime(){
			if (h<0 || m<0 || s<0){
				cout<<"Thoi gian nhap khong hop le, vui long nhap lai";
				return false;
			}
			return true;
		}
		//Chuan hoa input
		void normalize(){
			while (this->s > 60){
				this->m ++;
				this->s -= 60;
			}
			while (this->m > 60){
				this->h ++;
				this->m -= 60;
			}
			while(this->h >= 24){
				this->h -= 24;
			}
		}
		//Hien ra man hinh
		void displayTime(){
			cout<<"Thoi gian hien tai la: "<<this->h<<":"<<this->m<<":"<<this->s<<endl;
		}
		//Nhap input
		void getInputTime(){
			cout<<"Nhap thoi gian (hh:mm:ss): ";
			char k;
			do {
				cin>>this->h>>k>>this->m>>k>>this->s;
				normalize();
			} while (!checkInputTime());
		}
		//Toan tu so sanh thoi gian
		friend bool operator > (Time t1, Time t2){
          	if (t1.h < t2.h) return false;
            	else if (t1.m < t2.m) return false;
            	else if (t1.s < t2.s) return false;
            	else return true;
     	}	
        	friend bool operator < (Time t1, Time t2){
            	if (t1.h > t2.h ) return false;
            	else if (t1.m > t2.m) return false;
            	else if (t1.s > t2.s) return false;
            	else return true;
        	}
};
//---------------Xay dung class Anh sang(Light)--------------
class Light{
	protected:
		int lux;
	public:
		//Constructor
		Light(){}
		Light(int lux){
			this->lux = lux;
		}
		//Cap nhat cuong do anh sang
		void setLux(int lux){
			this->lux = lux;
		}
		//Lay cuong do anh sang
		int getLux(){
			return lux;
		}
		//Kiem tra input
		bool checkInputLight(){
			if(lux<0) {
				cout<<"Cuong do anh sang nhap khong hop le. Vui long nhap lai."<<endl;
				return false;
			}
			else return true;
		}
		//Nhap cuong do anh sang
		void getInputLight(){
			do {	
				cout<<"Nhap cuong do sang hien tai cua phong: ";
				cin>>this->lux;
			} while (!checkInputLight());
		}
		//In ra man cuong do anh sang
		void displayLight(){
			cout<<"Cuong do hien tai trong phong la: "<<this->lux<<endl;
		}
};
//-----------Xay dung class Nhiet do (Temperature)-------
class Temperature{
	protected:
		float tempNowInside, tempNowOutside;
	public:
		//Constructor
		Temperature(){}
		Temperature(int tempNowInside, int tempNowOutside){
			this->tempNowInside=tempNowInside;
			this->tempNowOutside = tempNowOutside;
		}
		//Canh bao
		void warning(){
			if(tempNowOutside - tempNowInside >= 10 || tempNowInside - tempNowOutside >= 10) 
				cout<<"CANH BAO: Bien do nhiet qua 10 do. Chu y de tranh bi soc nhiet khi ra khoi phong!"<<endl;
		}
		//Cap nhat nhiet do trong phong
		void setTempNowInside(float tempNowInside){
			this->tempNowInside=tempNowInside;
		}
		void setTempNowOutside(float tempNowOutside){
			this->tempNowOutside=tempNowOutside;
		}
		//Lay nhiet do trong va ngoai phong
		float getTempNowInside(){
			return tempNowInside;
		}
		float getTempNowOutside(){
			return tempNowOutside;
		}
		//Nhap nhiet do trong phong va ngoai troi
		void getInputTemperature(){
			cout<<"Nhap nhiet do hien tai cua phong: ";
			cin>>this->tempNowInside;
			cout<<"Nhap nhiet do hien tai o ngoai phong: ";
			cin>>this->tempNowOutside;
		}
		//In ra man hinh nhiet do trong phong va ngoai troi
		void displayTemperature(){
			cout<<"Nhiet do trong phong la: "<<this->tempNowInside<<endl;
			cout<<"Nhiet do ngoai troi la: "<<this->tempNowOutside<<endl;
			warning();
		}
};
//----------------Xay dung class Do am (Moisture)-------------------------------:
class Moisture{
    	protected:
        	int moisture;
    	public:
        	Moisture(){}
        	Moisture(int moisture){
          	this->moisture= moisture;
        	}
        	bool checkInputMoisture(){
			if (moisture<0 || moisture>100){
				cout<<"Do an nhap khong hop le, vui long nhap lai: "<<endl;
				return false;
			}
			return true;
		}
        	// Ham hien thi do am:
        	void displayMoisture(){
          // cout << endl << "Do am hien tai la: ";
           cout <<"Do am la: "<<this->moisture;
        	}
        	// Ham nhap do am:
        	void getInputMoisture(){
			cout<<"Nhap do am: ";
			do {
				cin>>this->moisture;
			} while (!checkInputMoisture());
		}
        	// Ham tra ve gia tri do am
        	int getMoisture(){
          	return moisture;
        	}
};
//-------------He thong cam ung trong nha-----------
class Sensor: public Time, public Light, public Temperature, public Moisture{
	protected:
		Time tSang,tDem;
	public:
		void getInputSensor(){
			cout<<"Tien hành lay thong tin cua ngoi nha: \n\n"<<endl;
			getInputTime();
			getInputLight();
			getInputTemperature();
			getInputMoisture();
			system("cls");
		}
		void displaySensor(){
			cout<<"Thong bao thong tin: "<<endl;
			displayTime();
			displayLight();
			displayTemperature();
			displayMoisture();
		}
		void setLimitTime(){
			cout<<"Nhap thoi gian co dinh cho buoi sang: "<<endl;
			tSang.getInputTime();
			cout<<"Nhap thoi gian co dinh cho buoi toi: "<<endl;
			tDem.getInputTime();
		}
		Time getTime(){
			Time t(this->h, this->m, this->s);
			return t;
		}
};
// -----------------------------Cac thiet bi---------------------------------------
// -----------------------------Rem Cua--------------------------------
class CurtainSystem: virtual public Sensor{
	public:
		CurtainSystem(){};
		//Dua vao chi so do sang de dua ra che do
		int curtainLevel(){
			if(getLux()>1000) return 4;
			else if (getLux()>850) return 3;
			else if (getLux()>300) return 2;
			else if (getLux()>100) return 1;
			else return 0;
		}
		//Tu dong dieu chinh rem
		void curtainAutoControl(){
			switch(curtainLevel()){
				case 0:
					cout<<"Rem mo hoan toan "<<endl;
					break;
				case 1: 
					cout<<"Dong rem 25%"<<endl;
					break;
				case 2:
					cout<<"Dong rem 50%"<<endl;
					break;
				case 3:
					cout<<"Dong rem 75%"<<endl;
					break;
				case 4:
					cout<<"Dong rem 100%"<<endl;
					break;
			}
		}
};
// -----------------------------Lo suoi--------------------------------
class StoveSystem: virtual public Sensor{
    	public:
        	int stoveAutoControl(){
          	if (getTempNowInside()<=10 ){
                	if(getMoisture()<=85)
                    	cout<<"Da nhan thay nhiet do thap, do am cao: Bat lo suoi!!!"<<endl;
                	else
                    	cout<<"Da nhan thay nhiet do thap: Bat lo suoi!!!"<<endl;
            	} else if (getTempNowInside() <15){
               	cout<< "Da nhan thay nhiet do mat me: Bat lo suoi o che do suoi am"<<endl;
            	}   
            	else    
                	cout<< "Da nhan thay nhiet do vua phai: Tat lo suoi"<<endl;
        }
};
//-------------Quat--------------
class FanSystem: virtual public Sensor{
	public:
		FanSystem(){}
		//Dua vao nhiet do trong phong de dua ra muc do nhiet. Nhiet do khi bat quat se duoc giam
		int fanLevel(){
			if(getTempNowInside()>40) return 4;
			else if(getTempNowInside()>35) return 3;
			else if(getTempNowInside()>30) return 2;
			else if(getTempNowInside()>25) return 1;
			else return 0;
		}
		//Tu dong dieu khien quat
		void fanAutoControl(){
			switch(fanLevel()){
				case 4:
					cout<<"Quat dang o muc manh nhat (Muc 4) "<<endl;
					break;
				case 3:
					cout<<"Quat dang o muc manh (Muc 3) "<<endl;
					break;
				case 2:
					cout<<"Quat dang o muc binh thuong (Muc 2) "<<endl;
					break;
				case 1:
					cout<<"Quat dang o muc nhe (Muc 1) "<<endl;
					break;
				case 0:
					cout<<"Quat dang khong bat "<<endl;
					break;
			}
		}
};
//--------------Dieu hoa----------
class ConditionerSystem: virtual public Sensor{
	public:
		ConditionerSystem(){}
		//Tu dong dieu khien dieu hoa dua ve nhiet do co dinh la 20 do
		float conditionerAutoControl(){
			cout<<"Nhiet do da dua ve muc co dinh la 20 do. "<<endl;
		}
};
//--------------he thong den trong phong--------
class LightBulbSystem: virtual public Sensor{
	public:
		LightBulbSystem(){}
		int lightBulbLevel(){
			if(getLux()>850) return 0;
			else if (getLux()>600) return 1;
			else if (getLux()>300) return 4;
			else return -1;
		}
		void lightBulbAutoControl(){
			if(getTime()<tSang || getTime()>tDem) {
				cout<<"Tat ca cac den da duoc tu dong tat. ";
				displayTime();
			}
			else {
				switch(lightBulbLevel()){
					case 0:
						cout<<"Den khong bat. "<<endl;
						break;
					case 1:
						cout<<"Bat 1 trong cac den. "<<endl;
						break;
					case 4:
						cout<<"Bat 4 trong cac den. "<<endl;
						break;
					case -1:
						cout<<"Bat tat ca cac den. "<<endl;
						break;
				}
			}
		}
};
//---------------Dieu khien bat tat he thong------
class ControlStatus: public StoveSystem, public CurtainSystem, public FanSystem, public ConditionerSystem, public LightBulbSystem{
	public:
		ControlStatus(){};
		void displayStatus(){
             	int i;
 	          do {
	               cout << "\n________________BAT TAT TRANG THAI DIEU KHIEN TU DONG___________________\n\n\n" << endl;
	               cout << "1.Tu dong dieu khien he thong rem" << endl;
	               cout << "2.Tu dong dieu khien he thong quat" << endl;
	               cout << "3.Tu dong dieu khien he thong dieu hoa" << endl;
	               cout << "4.Tu dong dieu khien he thong den" << endl;
	               cout << "5.Tu dong dieu khien he thong lo suoi" << endl;
	               cout << "6.Tu dong dieu khien ca he thong" << endl;
	          	cout << "0.Tat tat ca chuc nang tu dong" << endl;
	               cin >> i;
	               switch(i){
	                    case 1:
	                    	system("cls");
	                         cout<<"Curtain System On"<<endl;
	                    	curtainAutoControl();
	                    	cout << endl << "---------Press Any Key To Continue---------";
                    		getch();
	                         break;
	                    case 2:
	                    	system("cls");
	                         cout<<"Fan System On"<<endl;
	                         fanAutoControl();
	                         cout << endl << "---------Press Any Key To Continue---------";
                    		getch();
	                         break;
	                    case 3:
	                    	system("cls");
	                         cout<<"Conditioner System On"<<endl;
	                         conditionerAutoControl();
	                         cout << endl << "---------Press Any Key To Continue---------";
                    		getch();
						break;
	                    case 4:
	                    	system("cls");
	                         cout<<"Light Bulb System"<<endl;
	                         lightBulbAutoControl();
	                         cout << endl << "---------Press Any Key To Continue---------";
                    		getch();
						break;
	                     case 5:
	                     	system("cls");
	                         cout<<"Light Bulb System"<<endl;
	                         stoveAutoControl();
	                         cout << endl << "---------Press Any Key To Continue---------";
                    		getch();
						break;    
	                    case 6:
	                    	system("cls");
	                     	cout<<"Bat tat ca he thong"<<endl;
	                        	curtainAutoControl();
	                     	fanAutoControl();
	                     	conditionerAutoControl();
	                     	lightBulbAutoControl();
	                     	stoveAutoControl();
	                     	cout << endl << "---------Press Any Key To Continue---------";
                    		getch();
	                       	break;
	               	case 0:
	               		system("cls");
	                    	cout<<"He thong da tat"<<endl;
	                    	break;
               	}
			} while (i!=0);
		}
};
//---------------Cac phong------------------
class Home: public ControlStatus{
	public:
		Hoom(){}
		void homeAutomation(){
			setLimitTime();
			getInputSensor();
			displaySensor();
			int i;
          	do {
	               cout << "\n----------------HE THONG NHA THONG MINH----------------\n";
	               cout << "1.Bat he thong cam bien trong nha" << endl;
	               cout << "0. Thoat" <<endl;
	               cout << "Nhap lua chon: ";
	               cin >> i;
	               switch (i){
	               	case 1: 
	                         system ("cls");
	                         cout<<"                  He thong da duoc bat"<<endl;
	                         displayStatus();
	                    	break;
	               }
	          } while (i!=0);
		}
};
int main(){
    cout << 	     "--------------------------------Loading...-----------------------------------" << endl;
    cout << endl << "-----------------------Press Any Key To Continue-----------------------------";
    getch();
    system("cls");
    Home A1;
    A1.homeAutomation();
    cout<<		"-------------------------Ket thuc chuong trinh--------------------------------";
    return 0;
}
