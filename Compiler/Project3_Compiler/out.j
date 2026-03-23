
class example {
field static int a
method public static int add(int, int)
max_stack 15
max_locals 15
{
iadd
ireturn
}
method public static void main(java.lang.String[])
max_stack 15
max_locals 15
{
sipush 5
putstatic int example.a
sipush 10
invokestatic int example.add(int, int)
istore 0
sipush 10
isub
ifgt L0
iconst_0
goto L1
L0:
iconst_1
L1:
ineg
getstatic java.io.PrintStream java.lang.System.out
invokevirtual void java.io.PrintStream.print(int)
getstatic java.io.PrintStream java.lang.System.out
invokevirtual void java.io.PrintStream.print(int)
ifeq L2
goto L3
L2:
L3:
getstatic java.io.PrintStream java.lang.System.out
ldc "Hello World"
invokevirtual void java.io.PrintStream.print(java.lang.String)
return
}
}
