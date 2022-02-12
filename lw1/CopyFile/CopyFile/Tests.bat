﻿@echo off

REM Путь к тестируемой программе передается через первый аргумент командной строки
SET MyProgram="%~1"

REM Защита от запуска без аргументов
if %MyProgram%=="" (
	echo Please specify path to program
	exit /B 1
)

REM Copy empty file
%MyProgram% empty.txt "%TEMP%\output.txt" || goto err
fc empty.txt "%TEMP%\output.txt" > nul || goto err
echo Test 1 passed

REM Copy non-empty file
%MyProgram% NonEmptyFile.txt "%TEMP%\output.txt" || goto err
fc NonEmptyFile.txt "%TEMP%\output.txt" > nul || goto err
echo Test 2 passed

REM Copy missing file should fail
%MyProgram% MissingFile.txt "%TEMP%\output.txt" && goto err
echo Test 3 passed

REM If output file is not specified, program must fail
%MyProgram% MissingFile.txt && goto err
echo Test 4 passed

REM If input and output files are not specified, program must fail
%MyProgram% && goto err
echo Test 5 passed

REM Тесты прошли успешно
echo All tests passed succesfuly
exit /B 0

REM Сюда попадаем в случае ошибки
:err
echo Test fail
exit /B 1