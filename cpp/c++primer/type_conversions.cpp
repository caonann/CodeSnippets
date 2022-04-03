#include <iostream>
using namespace std;
class ConvertTo{};
class Convertable{
public:
    explicit operator ConvertTo() const{
        return c_;
    }
    explicit operator bool()const{
        return true;
    }
private:
    ConvertTo c_;
};

void func(ConvertTo ct){}
int main(){
    Convertable o;
    if(o){//隐式调用bool转换
        cout<<"oo"<<endl;
    }

    //o+1; 声明了显示类型转换，所以这种编译会报错 ，如果不声明explicit，则此行编译器会隐式类型转换
    /*
    · if、while及do语句的条件部分· for语句头的条件表达式· 逻辑非运算符（！）、逻辑或运算符（||）、逻辑与运算符（&&）的运算对象· 条件运算符（？ ：）的条件表达式。
    即使声明了显式，也会隐式类型转换
    */
   if(o&&1){
       cout<<"ooo"<<endl;
   }

   Convertable c;
   ConvertTo ct(c);
   //ConvertTo ct2=c; 拷贝构造初始化，编译失败
   ConvertTo ct3 = static_cast<ConvertTo>(c);
    return 0;
}