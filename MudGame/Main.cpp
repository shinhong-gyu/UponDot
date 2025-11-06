#include <vector>
#include <locale>
#include <fcntl.h>
#include <tchar.h>
#include <io.h>
#include <Windows.h>
#include <cstdlib>
#include <crtdbg.h>

#include "Game/Game.h"
#include "Level/MenuLevel.h"
#include "Container/List.h"
#include "Level/MainLevel.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);

	std::wcout.imbue(std::locale("en_US.UTF-8"));

	Game* game = new Game();
	game->LoadLevel(new MenuLevel());
	game->Run();

	delete game;

	_CrtDumpMemoryLeaks();

}