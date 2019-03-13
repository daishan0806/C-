#include<iostream>
#include<memory>
using namespace std;
/*�����Լ�������һ���򵥵�����ָ��*/
template<typename T>
class smart_pointer{
	
	private:
		T *m_pRawPointer;
	public:
		smart_pointer(T *pdata):m_pRawPointer(pdata){
		};
		/*�������캯��*/
		smart_pointer(const smart_pointer& obj);
		//��ֵ=
		smart_pointer& operator= (const smart_pointer& obj) ;
		//����*������ 
		T& operator* ()const{
			return *(m_pRawPointer);
		}
		//����
		T& operator->() const{
			return m_pRawPointer;
		} 
}; 


class Dog{
	 
};
 void demo1(){
 	double d;
 	d=25.5;
 	double *pd=new double;  //�������double���� ,����ͻ�����ڴ�й¶ 
 	*pd=25.5;
 	Dog *dog=new Dog();
 	cout<<d<<endl;
 	cout<<*pd<<endl;
 	delete dog;
 	delete pd;     //�����ں�������֮ǰdeleteָ�� 
 }
 
 void demo2(){
 	auto_ptr<double> pd(new double); //��������ָ�� 
 	*pd=25.2;
 	auto_ptr<Dog> pDog(new Dog);    //����Dog���͵�auto_ptr����ָ��
	 
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
