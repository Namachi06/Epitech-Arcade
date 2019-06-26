/*
** EPITECH PROJECT, 2019
** Core.cpp
** File description:
** Core of the game
*/

#include "../../include/core/Core.hpp"

Core::Core()
{
}

Core::Core(const std::string &libName) : _libName(libName)
{
    _game = nullptr;
    _graphic = nullptr;
    _handleGame = nullptr;
    _handleLib = nullptr;
    _exit = false;
    getLibs("./lib/");
    getGames("./games/");
    openLib(_libName);
    _file.getNameSubStr(_currentGraph);
}

Core::~Core()
{
    if (_graphic) {
        _graphic->close();
        delete _graphic;
    }
    if (_game)
        delete _game;
    if (_handleGame)
        dlClose(_handleGame);
    if (_handleLib)
        dlClose(_handleLib);
}

void Core::getLibs(const std::string directory)
{
    File file(directory);
    _libsPath = file.getList();
    std::sort(_libsPath.begin(), _libsPath.end());
    _libsName = _libsPath;
    file.getName(_libsName);
}

void Core::getGames(const std::string directory)
{
    File file(directory);

    _gamesPath = file.getList();
    std::sort(_gamesPath.begin(), _gamesPath.end());
    _gamesName = _gamesPath;
    file.getName(_gamesName);
}

void Core::openLib(const std::string &libName)
{
    Arcade::ILibraryView *(*createLibrary)();

    _currentGraph = libName;
    _handleLib = dlOpen(libName.c_str(), RTLD_LAZY | RTLD_LOCAL);
    if (!_handleLib)
        throw ArcadeExceptions::SystemFunctionsError(dlerror());
    createLibrary = reinterpret_cast<Arcade::ILibraryView *(*)()>(dlSym(_handleLib, "createLibrary"));
    if (!createLibrary)
        throw ArcadeExceptions::SystemFunctionsError(dlerror());
    _file.getNameSubStr(_currentGraph);
    _graphic = createLibrary();
}

void Core::openGame(const std::string &gameName)
{
    Arcade::IGameModel *(*createGame)();

    _currentGame = gameName;
    _handleGame = dlOpen(gameName.c_str(), RTLD_LAZY | RTLD_LOCAL);
    if (!_handleGame)
        throw ArcadeExceptions::SystemFunctionsError(dlerror());
    createGame = reinterpret_cast<Arcade::IGameModel *(*)()>(dlSym(_handleGame, "createGame"));
    if (!createGame)
        throw ArcadeExceptions::SystemFunctionsError(dlerror());
    _file.getNameSubStr(_currentGame);
    _game = createGame();
}

Arcade::ILibraryView *Core::getLibrary() const
{
    return _graphic;
}

void Core::gameOver()
{
}

void Core::setScore(const std::string &score)
{
    (void)score;
}

void Core::switchGame(Arcade::Command cmd)
{
    std::vector<std::string>::iterator it;
    std::size_t counter = 0;

    delete _game;
    _game = nullptr;
    dlClose(_game);
    _handleGame = NULL;
    for (it = _gamesName.begin(); it != _gamesName.end(); ++it) {
        if (*it == _currentGame)
            break;
        counter++;
    }
    if (cmd == Arcade::PREV_GAME)
        counter--;
    else if (cmd == Arcade::NEXT_GAME)
        counter++;
    openGame(_gamesPath[counter % _gamesPath.size()]);
}

void Core::switchLib(Arcade::Command cmd)
{
    std::vector<std::string>::iterator it;
    std::size_t counter = 0;

    _graphic->close();
    delete _graphic;
    _graphic = nullptr;
    dlClose(_handleLib);
    _handleLib = NULL;
    for (it = _libsName.begin(); it != _libsName.end(); ++it) {
        if (*it == _currentGraph)
            break;
        counter++;
    }
    if (cmd == Arcade::PREV_LIB)
        counter--;
    else if (cmd == Arcade::NEXT_LIB)
        counter++;
    openLib(_libsPath[counter % _libsPath.size()]);
    _graphic->init(this);
}

void Core::getPlayerName()
{
    std::string input;

    if (_currentGraph == "ncurses") {
        _graphic->clear();
        _graphic->putText("ENTER YOUR NAME", Arcade::RED, WIDTH / 2, HEIGHT / 3.5, 32);
        _graphic->refresh();
    }
    while ((input = _graphic->getCharKeyboardEvent()) != "ENTER" || _playerName.empty()) {
        _graphic->clear();
        _graphic->putText("ENTER YOUR NAME", Arcade::RED, WIDTH / 2, HEIGHT / 3.5, 32);
        if (!input.empty()) {
            if (input == "BACKSPACE" && !_playerName.empty())
                _playerName.pop_back();
            else if (input != "BACKSPACE" && input != "ESCAPE" && input != "ENTER" && _playerName.size() < 16)
                _playerName += input;
            else if (input == "ESCAPE") {
                _exit = true;
                return;
            }
        }
        _graphic->putText(_playerName, Arcade::WHITE, WIDTH / 2, HEIGHT / 2, 28);
        _graphic->refresh();
    }
}

void Core::displayGames(std::size_t index)
{
    std::vector<std::string>::iterator it;
    std::size_t i = 0;

    _graphic->putText("ARCADE", Arcade::BLUE, WIDTH / 2, HEIGHT / 13, 80);
    _graphic->putText("WELCOME " + _playerName, Arcade::WHITE, WIDTH / 2, HEIGHT / 5, 58);
    _graphic->putText("->", Arcade::YELLOW, WIDTH / 2.5, (HEIGHT / 2) + 80 * index, 40);
    for (it = _gamesName.begin(); it != _gamesName.end(); ++it) {
        _graphic->putText((*it), Arcade::RED, WIDTH / 2, (HEIGHT / 2) + 80 * i, 40);
        i++;
    }
}

void Core::displayLibs()
{
    std::vector<std::string>::iterator it;
    std::size_t i = 0;

    for (it = _libsName.begin(); it != _libsName.end(); ++it) {
        if (*it == _currentGraph)
            _graphic->putText("->", Arcade::RED, WIDTH / 25, (HEIGHT / 1.1) + 50 * i, 25);
        _graphic->putText((*it), Arcade::GREEN, WIDTH / 10, (HEIGHT / 1.1) + 50 * i, 25);
        i++;
    }
}

void Core::displayControls()
{
    _graphic->putText("[ESCAPE] -> Quit the game", Arcade::CYAN, WIDTH / 7, (HEIGHT / 3), 20);
    _graphic->putText("[ARROWS] -> Move character", Arcade::CYAN, WIDTH / 7, (HEIGHT / 3) + 37 * 1, 20);
    _graphic->putText("[0] -> Get back to the menu", Arcade::CYAN, WIDTH / 7, (HEIGHT / 3) + 37 * 2, 20);
    _graphic->putText("[1] -> Restart game", Arcade::CYAN, WIDTH / 7, (HEIGHT / 3) + 37 * 3, 20);
    _graphic->putText("[2] -> Move to next library", Arcade::CYAN, WIDTH / 7, (HEIGHT / 3) + 37 * 4, 20);
    _graphic->putText("[3] -> Move to prev library", Arcade::CYAN, WIDTH / 7, (HEIGHT / 3) + 37 * 5, 20);
    _graphic->putText("[4] -> Move to next game", Arcade::CYAN, WIDTH / 7, (HEIGHT / 3) + 37 * 6, 20);
    _graphic->putText("[5] -> Move to prev game", Arcade::CYAN, WIDTH / 7, (HEIGHT / 3) + 37 * 7, 20);
}

void Core::startMenu()
{
    Arcade::Command cmd;
    std::size_t index = 0;

    if (_exit)
        return;
    _graphic->clear();
    displayGames(index);
    displayLibs();
    displayControls();
    _graphic->refresh();
    while ((cmd =_graphic->getCommand()) != Arcade::Command::PLAY) {
        _graphic->clear();
        if (cmd != Arcade::UNDEFINED) {
            if (cmd == Arcade::ESCAPE) {
                _exit = true;
                return;
            }
            if (cmd == Arcade::UP)
                index++;
            else if (cmd == Arcade::DOWN)
                index--;
            else if (cmd == Arcade::NEXT_LIB || cmd == Arcade::PREV_LIB)
                switchLib(cmd);
        }
        displayGames(index % _gamesPath.size());
        displayLibs();
        displayControls();
        if (_currentGraph != "ncurses") {
            while ((cmd = _graphic->getCommand()) == Arcade::DOWN);
            while ((cmd = _graphic->getCommand()) == Arcade::UP);
            while ((cmd = _graphic->getCommand()) == Arcade::NEXT_LIB);
            while ((cmd = _graphic->getCommand()) == Arcade::PREV_LIB);
        }
        _graphic->refresh();
    }
    _currentGame = _gamesPath[index % _gamesPath.size()];
}


void Core::start()
{
    _graphic->init(this);
    getPlayerName();
    startMenu();
    if (_exit)
        return;
    // game();
}

void Core::game()
{
    Arcade::Command gameCmd;

    openGame(_currentGame);
    while (_exit == false) {
        gameCmd = _game->playGame(*this);
        if (gameCmd == Arcade::ESCAPE)
            _exit = true;
        else if (gameCmd == Arcade::MENU)
            getBackToMenu();
        else if (gameCmd == Arcade::RESTART)
            restartGame();
        else if (gameCmd == Arcade::NEXT_LIB || gameCmd == Arcade::PREV_LIB)
            switchLib(gameCmd);
        else if (gameCmd == Arcade::NEXT_GAME || gameCmd == Arcade::PREV_GAME)
            switchGame(gameCmd);
    }
}

void Core::getBackToMenu()
{
    delete _game;
    _game = nullptr;
    dlClose(_handleGame);
    _currentGame.clear();
    startMenu();
}

void Core::restartGame()
{
    delete _game;
    _game = nullptr;
    dlClose(_handleGame);
    openGame(_currentGame);
}

void *Core::dlOpen(const char *file, int mode)
{
    return dlopen(file, mode);
}

void *Core::dlSym(void *handle, const char *function)
{
    return dlsym(handle, function);
}

int Core::dlClose(void *handle)
{
    return dlclose(handle);
}