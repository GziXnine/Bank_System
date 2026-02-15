@echo off
REM ===========================================================================
REM Build script for Bank System (Windows)
REM ===========================================================================

echo Compiling Bank System...
echo.

REM Compile all source files
g++ -std=c++11 -Wall -Wextra -o bank_system ^
    src/main.cpp ^
    src/models/Person.cpp ^
    src/models/Client.cpp ^
    src/models/Employee.cpp ^
    src/models/Admin.cpp ^
    src/utils/Validation.cpp ^
    src/core/Parser.cpp ^
    src/core/FilesHelper.cpp ^
    src/core/FileManager.cpp ^
    src/services/ClientManager.cpp ^
    src/services/EmployeeManager.cpp ^
    src/services/AdminManager.cpp ^
    src/services/Screens.cpp

if %ERRORLEVEL% EQU 0 (
    echo.
    echo ================================
    echo Compilation successful!
    echo Executable: bank_system.exe
    echo ================================
    echo.
    echo To run: bank_system.exe
) else (
    echo.
    echo ================================
    echo Compilation failed!
    echo ================================
)

pause
