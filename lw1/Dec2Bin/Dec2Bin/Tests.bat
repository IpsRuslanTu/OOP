@echo off

REM Путь к тестируемой программе передается через первый аргумент командной строки
SET MyProgram="%~1"

REM Защита от запуска без аргументов
if %MyProgram%=="" (
	echo Please specify path to program
	exit /B 1
)

REM If no input number, program must fail
%MyProgram% && goto err
echo Test 1 passed

REM If extra parameters, program must fail
%MyProgram% "34" "234" && goto err
echo Test 2 passed

REM If parameter is not number, program must fail
%MyProgram% "hello" && goto err
echo Test 3 passed

REM If parameter is not number, program must fail
%MyProgram% "42hello" && goto err
echo Test 4 passed

REM If parameter is not bigger then type int, program must fail
%MyProgram% "2147483648" && goto err
echo Test 5 passed

REM If parameter is 0
%MyProgram% "0" > "%TEMP%\output.txt" || goto err
fc "%TEMP%\output.txt" "0.txt" || goto err
echo Test 6 passed

REM If parameter is (MAX_INT - 1)
%MyProgram% "2147483647" > "%TEMP%\output.txt" || goto err
fc "%TEMP%\output.txt" "2147483647.txt" || goto err
echo Test 7 passed

REM Тесты прошли успешно
echo All tests passed succesfuly
exit /B 0

REM Сюда попадаем в случае ошибки
:err
echo Test fail
exit /B 1