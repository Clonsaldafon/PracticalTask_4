#include <iostream>

int main()
{
    char message[100] = "Madam, I\'m Adam";
	int count;

	__asm
	{
		mov ecx,0 // ������� � 0-�� ��������
	begin_count:
		cmp message[ecx],0 // ���������
		je end_count
		inc ecx
		jmp begin_count // ����������� �������
		mov cx,c // ������� ��� ����� (���-�� ��������)

		// TODO: loop
		mov al,message[cx]
		push eax
		
		// TODO: loop
		// mov cx,c - ?
		pop ebx
		mov message[cx],bl
	end_count:
		mov c,ecx
	}

	printf("%s", message);

	// ����������� ������
	//char szStr[100] = "ABC";
	//__asm
	//{
	//	mov al,szStr[0]
	//	push eax // � ���� ���������� eax (3 ����� - �����)
	//	mov al, szStr[1]
	//	push eax // � ���� ���������� eax (3 ����� - �����)
	//	mov al, szStr[2]
	//	push eax // � ���� ���������� eax (3 ����� - �����)

	//	pop ebx // �� �����
	//	mov szStr[0],bl
	//	pop ebx // �� �����
	//	mov szStr[1], bl
	//	pop ebx // �� �����
	//	mov szStr[2], bl
	//}
	//printf("%s\n", szStr);
}
