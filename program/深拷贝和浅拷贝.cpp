#include<iostream> 
#include<string.h>
using namespace std;

class CDemo{
	public: 
	CDemo(int a,char *cstr){
		this->a=a;
		this->str=new char[1024];;
		strcpy(this->str,cstr);
	}
	
	//ûд���ƹ��캯����C++���Զ���дһ�����ƹ��캯�� 
	//Ĭ�Ͽ������캯����ǳ���� 
	CDemo(const CDemo& obj){
		this->a=obj.a;
	//	this->str=obj.str;  //ǳ������ָ��ָ��ͬһ���ڴ� 
		this->str=new char[1024]; //��� 
		if(this->str)
			strcpy(this->str,obj.str);
	}
	~CDemo(){
		delete str;
	} 
	public:
		int a;
		char *str;
}; 
int main(){
	CDemo A(10,"hello");
	cout<<A.a<<","<<A.str<<endl;
	CDemo B=A;  //���ø��ƹ��캯��
	cout<<B.a<<","<<B.str<<endl; 
	B.a=8;
	B.str[0]='k';  //B��A��hello����ĳ� kello
	
	/*������仰���ᵼ��A��str�ı䣬��ΪA��str��ָ���������Ȼ��"hello"
	 *����B.strָ����ڴ�ռ䲻����"hello"������world��ַ�ռ� 
	 */
    //B.str="world"; 
					 
	cout<<"�޸��Ժ�"<<endl;
	cout<<A.a<<","<<A.str<<endl;
	cout<<B.a<<","<<B.str<<endl; 
	return 0;
}
