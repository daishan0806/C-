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
	/*析构函数设置成虚函数*/
	virtual ~Animal(){
		cout<<"Animal 的析构函数被调用"<<endl;
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
	cout<<"Animal的构造函数被调用"<<endl;
}
class Horse:virtual public Animal{
	public:
		Horse(int height,COLOR color,int age);
		virtual ~Horse(){cout<<"Horse的析构函数"<<endl;}
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
	cout<<"Horse 的构造函数被调用"<<endl; 
}

class Bird:virtual public Animal{
	public:
		Bird(bool Migration,COLOR color,int age):Animal(age),isMigration(Migration),color(color){
			cout<<"Bird 的构造函数建立"<<endl;
		}
		virtual ~Bird(){
			cout<<"Bird 的析构函数"<<endl;
		};
		//鸟叫 
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
/*多继承*/ 
class flyHorse:public Horse,public Bird{
	public:
		//飞马的叫声,重写了鸟的叫声，换成马的叫声 
		void chirp()const{ 
			whinny();
		}
		flyHorse(int,bool,long,COLOR color,int age);
		~flyHorse(){
			cout<<"flyHorse 的析构函数"<<endl;
		}
		virtual long getNumber()const{return isNumber;} 
	private:
		long isNumber;
		
};
//由于flyHorse继承了Horse和Bird，所以初始化列表要调用Horse和Bird的构造函数，再初始化自己 
flyHorse::flyHorse(int height,bool Migration,long Number,COLOR color,int age):Animal(age),Horse(height,color,age),Bird(Migration,color,age),isNumber(Number){
	cout<<"flyHorse的构造函数"<<endl;
}
int main(){
	/*构造函数是先运行父类，再运行子类*/
	flyHorse *p_fh=new flyHorse(10,true,20,red,13);
	p_fh->fly();   //从鸟那里继承来的 
	p_fh->whinny(); //从马那里继承来的 
	p_fh->chirp();  //从马那里继承来的
	cout<<"flyHorse::Horse的颜色为："<<p_fh->Horse::getColor()<<endl;  //解决二义性问题 
	cout<<"flyHorse::Bird的颜色为 ："<<p_fh->Bird::getColor()<<endl;   //解决二义性问题 
    cout<<"飞马的年龄:"<<p_fh->getAge()<<endl; 
	cout<<"有"<<p_fh->getNumber()<<"个人相信飞马的存在"<<endl; 
	/*析构函数是先析构子类，再析构父类，和构造函数的次序正好相反*/ 
	delete p_fh; 
} 
