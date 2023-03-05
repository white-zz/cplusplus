#include <stdio.h>
#include <stdlib.h>


// 懒汉模式是在类加载的时候不去创建这个唯一的实例，而是在需要使用的时候再进行实例化。 （存在线程安全问题、需要双重检查锁定，这里没有锁的检查）
class CModel
{
    public:
        static CModel *GetInstance();
        void show();
     private:
        CModel();
        static CModel *g_pInstance;   //静态成员属于类，所有对象共享的数据，在内存中之占用一份空间
        int  id;
  };

//类的成员
 CModel * CModel::g_pInstance=NULL;  //静态成员变量必须初始化，在类外初始化

 //全局函数
 CModel * GetModelInstance();       //全局函数写在头文件，源文件实现

void CModel::show(){

 printf(" 懒汉 id:%d\n",id);

}

CModel::CModel()
{
  id = rand()%1000;
}

 CModel * CModel::GetInstance()
{

	if (g_pInstance == NULL) 
		g_pInstance = new CModel();
      
	
	return g_pInstance;
  
}

CModel * GetModelInstance()
{
   return CModel::GetInstance();
}


int main()
{
   CModel *pMODEL = GetModelInstance();
   pMODEL->show();    
  CModel *pMODEL1 = GetModelInstance();
   pMODEL1->show();   //同一个实例

   // CModel test = *pMODEL;  //构造函数拷贝构造了一个对象，多了一个对象，不符合单例
   // test.show();
   // printf("model1 %p、model2 %p、model3 %p",pMODEL,pMODEL1,&test);
}