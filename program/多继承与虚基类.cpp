#include<iostream>
using namespace std;
enum COLOR{
	red,
	blue,
	green,
	black,
	orange,
	yellow
};
class Animal{
	public:
	Animal(int);
	/*�����������ó��麯��*/
	virtual ~Animal(){
		cout<<"Animal ����������������"<<endl;
	}
	virtual int getAge(){
		return itsAge;
	}
	virtual void setAge(int age){
		this->itsAge=age;
	} 
	private:
		int itsAge;
};
Animal::Animal(int age):itsAge(age){
	cout<<"Animal�Ĺ��캯��������"<<endl;
}
class Horse:virtual public Animal{
	public:
		Horse(int height,COLOR color,int age);
		virtual ~Horse(){cout<<"Horse����������"<<endl;}
		virtual void whinny()const{cout<<"Whinny"<<endl;}
		virtual int getHeight(){return height;}
		virtual COLOR getColor()const {return color;}
	private:
		int height;
		 COLOR color;
};
Horse::Horse(int height,COLOR color,int age):Animal(age){
	this->height=height;
	this->color=color;
	cout<<"Horse �Ĺ��캯��������"<<endl; 
}

class Bird:virtual public Animal{
	public:
		Bird(bool Migration,COLOR color,int age):Animal(age),isMigration(Migration),color(color){
			cout<<"Bird �Ĺ��캯������"<<endl;
		}
		virtual ~Bird(){
			cout<<"Bird ����������"<<endl;
		};
		//��� 
		virtual void chirp() const{
			cout<<"l can chirp"<<endl;
		}
		virtual void fly() const{
			cout<<"l can fly"<<endl;
		}
		virtual bool getMigration() const{
			return isMigration;
		}
		virtual COLOR getColor()const{return color;}
	private:
		bool isMigration;
		COLOR color;
};
/*��̳�*/ 
class flyHorse:public Horse,public Bird{
	public:
		//����Ľ���,��д����Ľ�����������Ľ��� 
		void chirp()const{ 
			whinny();
		}
		flyHorse(int,bool,long,COLOR color,int age);
		~flyHorse(){
			cout<<"flyHorse ����������"<<endl;
		}
		virtual long getNumber()const{return isNumber;} 
	private:
		long isNumber;
		
};
//����flyHorse�̳���Horse��Bird�����Գ�ʼ���б�Ҫ����Horse��Bird�Ĺ��캯�����ٳ�ʼ���Լ� 
flyHorse::flyHorse(int height,bool Migration,long Number,COLOR color,int age):Animal(age),Horse(height,color,age),Bird(Migration,color,age),isNumber(Number){
	cout<<"flyHorse�Ĺ��캯��"<<endl;
}
int main(){
	/*���캯���������и��࣬����������*/
	flyHorse *p_fh=new flyHorse(10,true,20,red,13);
	p_fh->fly();   //��������̳����� 
	p_fh->whinny(); //��������̳����� 
	p_fh->chirp();  //��������̳�����
	cout<<"flyHorse::Horse����ɫΪ��"<<p_fh->Horse::getColor()<<endl;  //������������� 
	cout<<"flyHorse::Bird����ɫΪ ��"<<p_fh->Bird::getColor()<<endl;   //������������� 
    cout<<"���������:"<<p_fh->getAge()<<endl; 
	cout<<"��"<<p_fh->getNumber()<<"�������ŷ���Ĵ���"<<endl; 
	/*�������������������࣬���������࣬�͹��캯���Ĵ��������෴*/ 
	delete p_fh; 
} 
