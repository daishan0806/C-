#include<iostream>
#include<memory>
using namespace std;
/*下面自己动手做一个简单的智能指针*/
template<typename T>
class smart_pointer{
	
	private:
		T *m_pRawPointer;
	public:
		smart_pointer(T *pdata):m_pRawPointer(pdata){
		};
		/*拷贝构造函数*/
		smart_pointer(const smart_pointer& obj);
		//赋值=
		smart_pointer& operator= (const smart_pointer& obj) ;
		//重载*操作符 
		T& operator* ()const{
			return *(m_pRawPointer);
		}
		//重载
		T& operator->() const{
			return m_pRawPointer;
		} 
}; 


class Dog{
	 
};
 void demo1(){
 	double d;
 	d=25.5;
 	double *pd=new double;  //堆里面的double变量 ,否则就会产生内存泄露 
 	*pd=25.5;
 	Dog *dog=new Dog();
 	cout<<d<<endl;
 	cout<<*pd<<endl;
 	delete dog;
 	delete pd;     //必须在函数结束之前delete指针 
 }
 
 void demo2(){
 	auto_ptr<double> pd(new double); //定义智能指针 
 	*pd=25.2;
 	auto_ptr<Dog> pDog(new Dog);    //定义Dog类型的auto_ptr智能指针
	 
	smart_pointer<double> m_pd(new double); 
	*m_pd=34.21;
	cout<<*m_pd<<endl;
 	cout<< *pd<<endl;
 }
 int main(){
 	//demo1();
 	demo2();
 	return 0; 
 }
