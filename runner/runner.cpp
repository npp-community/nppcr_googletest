#define WIN32_LEAN_AND_MEAN
#include <windows.h>

typedef int (__stdcall *runnerFunc)(int, TCHAR**);
int main(int argc, TCHAR* argv[])
{
	if (argc >= 2) {
		if (HMODULE module = LoadLibrary(argv[1])) {
			if (runnerFunc runner = (runnerFunc)::GetProcAddress (module, "_RunTests@8")) {
				runner(argc, argv);
			}
		}
	}
	return 1;
}

