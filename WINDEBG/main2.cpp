#include <windows.h>
#include<stdio.h>
void main()
{
	int i;
	//�����ڴ棬���Ϊ�ύ���ɶ���д 

	LPVOID lpvBase = VirtualAlloc(
		(LPVOID)0x5000000,                 // system selects address
		1024,     // size of allocation
		MEM_COMMIT,   // allocate reserved pages
		PAGE_READWRITE
	);       // protection = no access   
	lpvBase = VirtualAlloc(
		lpvBase,                 // system selects address
		1024,     // size of allocation
		MEM_COMMIT,   // allocate reserved pages
		PAGE_READWRITE
	);
	if (lpvBase == NULL)
		return;
	//����ڴ�����дЩ����
	unsigned char *ustr = (unsigned char *)lpvBase;
	for (i = 0; i < 5; i++)
	{
		ustr[i] = 'b';
	}
	for (i = 0; i < 5; i++)
	{
		printf("%c ��%x \n", ustr[i], &ustr[i]);
	}

}