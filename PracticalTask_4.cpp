#include <iostream>

int main()
{
    char message[100] = "Madam, I\'m Adam";
	int count;

	__asm
	{
		mov ecx,0 // счетчик с 0-го элемента
	begin_count:
		cmp message[ecx],0 // сравнение
		je end_count
		inc ecx
		jmp begin_count // безусловный переход
		mov cx,c // счетчик для цикла (кол-во итераций)

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

	// перевернуть строку
	//char szStr[100] = "ABC";
	//__asm
	//{
	//	mov al,szStr[0]
	//	push eax // в стек записываем eax (3 байта - мусор)
	//	mov al, szStr[1]
	//	push eax // в стек записываем eax (3 байта - мусор)
	//	mov al, szStr[2]
	//	push eax // в стек записываем eax (3 байта - мусор)

	//	pop ebx // из стека
	//	mov szStr[0],bl
	//	pop ebx // из стека
	//	mov szStr[1], bl
	//	pop ebx // из стека
	//	mov szStr[2], bl
	//}
	//printf("%s\n", szStr);
}
