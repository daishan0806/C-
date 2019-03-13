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
	
	//没写复制构造函数，C++会自动帮写一个复制构造函数 
	//默认拷贝构造函数是浅拷贝 
	CDemo(const CDemo& obj){
		this->a=obj.a;
	//	this->str=obj.str;  //浅拷贝，指针指向同一个内存 
		this->str=new char[1024]; //深拷贝 
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
	CDemo B=A;  //调用复制构造函数
	cout<<B.a<<","<<B.str<<endl; 
	B.a=8;
	B.str[0]='k';  //B和A的hello都会改成 kello
	
	/*下面这句话不会导致A的str改变，因为A的str所指向的内容依然是"hello"
	 *但是B.str指向的内存空间不再是"hello"，而是world地址空间 
	 */
    //B.str="world"; 
					 
	cout<<"修改以后"<<endl;
	cout<<A.a<<","<<A.str<<endl;
	cout<<B.a<<","<<B.str<<endl; 
	return 0;
}
