#include<stdio.h>
#include<malloc.h>
#include<string>
#include <windows.h>
using namespace std;
#include<iostream>
//int main()
//{
//	int i = 0,anum;
//	char *p;
//
//	p = (char *)malloc(100);
//	if (p)
//		printf("Memory Allocated at: %x/n", p);
//	else
//		printf("Not Enough Memory!/n");
//	for (i = 0; i<4096; i++)
//	{
//		p[i] = 'a';
//	}
//	anum = i;
//	//printf("��д��%d�ֽ�/n", anum);
//	//cout << "��д��" << anum << "�ֽ�" << endl;
//	for (i = 0; i<4096; i++)
//	{
//		if (p[i] != 'a')
//		{
//			anum--;
//		}
//	}
//	//printf("��%d�ֽڶ�ȡ��ȷ/n", anum);
//	
//	free(p);
//	return 0;
//}

void main()
{
	BOOL flag;
	//�����ڴ棬���Ϊ�ύ���ɶ���д 
	LPVOID lpvBase = VirtualAlloc(
		NULL,                 // system selects address
		4096,     // size of allocation
		MEM_COMMIT,   // allocate reserved pages
		PAGE_READWRITE
	);       // protection = no access   
	if (lpvBase == NULL )   
		return;
	//����ڴ�����дЩ����
	unsigned char *ustr = (unsigned char *)lpvBase;
	ustr[0] = 'a';
	//printf("д������ݣ�%d/n", ustr[0]);
	
	//�޸�Ϊ��ֻ�������ԣ���֤�Ƿ���д��
	DWORD dw;
	char c;
	VirtualProtect(lpvBase, 4096, PAGE_READONLY, &dw);
	c = ustr[0];  //���Զ�ȡ
	//ustr[0]=0x44; //ʧ��

	// virtualfree
	flag = VirtualFree(lpvBase,4096, MEM_DECOMMIT);
	if (flag == TRUE)
	{
		cout << "�ͷųɹ�"<<endl;
	}
	else
	{
		cout << "�ͷ�ʧ��" << endl;
	}
	//c = ustr[0];  //���ɶ�ȡ
	ustr[0] = 0x44; //ʧ��

}