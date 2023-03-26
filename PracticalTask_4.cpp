#include <iostream>

int main()
{
    char message[100] = "Madam, I\'m Adam";
    int count = strlen(message);

    _asm
    {
        mov esi, 0
        mov ecx, count
        label1 :
            mov al, message[esi]
            push eax
            inc esi
        loop label1
        mov esi, 0
        mov ecx, count
        label2 :
            pop eax
            mov message[esi], al
            inc esi
        loop label2
    }

    std::cout << message;
}
