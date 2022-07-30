#include <stdio.h>
#include <stdlib.h>



class CModel
{
    public:
        CModel();
        static CModel *GetInstance();
        void show();
     private:
         static CModel *g_pInstance;
         int  id;
  };
 CModel * CModel::g_pInstance=NULL;
 CModel *GetModelInstance();       //全局函数写在头文件，源文件实现


void CModel::show(){

 printf("id:%d\n",id);

}

CModel::CModel(){

  id=rand()%1000;

}

CModel * GetModelInstance()
{
	return CModel::GetInstance();
}

 CModel * CModel::GetInstance()
{
	if (g_pInstance == NULL) 
		g_pInstance = new CModel();
	
	return g_pInstance;
  
}


int main()
{
   CModel *pMODEL = GetModelInstance();
   pMODEL->show();    
    CModel *pMODEL1 = new CModel();
   pMODEL1->show();

}