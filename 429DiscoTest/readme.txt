Simple LED flasher program.

Modifications from base project:
*	Toolchain settings - ${PATH} vairable appended to environment PATH setting
*	JLink debug config - hardcoded gdb CL exe reference
*	Systick IRQ handler added at 1ms tick rate
*	ECHO not in path error - path to make tools added to PATH setting as well

Prerequisites:
arm-none-eabi toolchain installed
GNU ARM tools plugin for eclipse
Mylin not strictly necessary
GNU make install + echo required
JLink software including GDB server

Mostly it I think...
