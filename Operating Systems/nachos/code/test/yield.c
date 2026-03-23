#include "syscall.h"

int main()
{
	PrintInt(88);
	ThreadYield();
	PrintInt(99);
}
