@echo off

REM Путь к тестируемой программе передается через первый аргумент командной строки
SET MyProgram="%~1"

REM Защита от запуска без аргументов
if %MyProgram%=="" (
	echo Please specify path to program
	exit /B 1
)

REM If input and output files are not specified, program must fail
%MyProgram% && goto err
echo Test 1 passed

REM Если второй параметр не число, программа должна упасть
%MyProgram% "dsf" && goto err
echo Test 2 passed

REM Если второй параметр меньше 0, программа должна упасть
%MyProgram% "-1" && goto err
echo Test 3 passed

REM Если второй параметр больше 255, программа должна упасть
%MyProgram% "256" && goto err
echo Test 4 passed

REM Тесты прошли успешно
echo All tests passed succesfuly
exit /B 0

REM Сюда попадаем в случае ошибки
:err
echo Test fail
exit /B 1