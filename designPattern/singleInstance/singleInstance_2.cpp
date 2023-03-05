#include <stdio.h>
#include <stdlib.h>


// 饿汉模式就是在类加载的时候立刻进行实例化

class CModel
{
    public:
        static CModel *GetInstance()
        {
	         return g_pInstance;
        }
        void show();
     private:
        CModel();
        static CModel *g_pInstance;   //静态成员属于类，所有对象共享的数据，在内存中之占用一份空间
        int  id;
  };

//类的成员
 CModel * CModel::g_pInstance = new CModel();  //静态成员变量必须初始化，在类外初始化。  区分懒汉和恶汉模式的地方，恶汉在这里直接new一个对象

 //全局函数
 CModel * GetModelInstance();       //全局函数写在头文件，源文件实现


void CModel::show(){

  printf("饿汉 id 2:%d\n",id);

}

CModel * GetModelInstance()
{
   return CModel::GetInstance();
}


CModel::CModel(){

  id=rand()%1000;

}


int main()
{
   CModel *pMODEL = GetModelInstance();
   pMODEL->show();    
  CModel *pMODEL1 = GetModelInstance();
   pMODEL1->show();   //同一个实例



}