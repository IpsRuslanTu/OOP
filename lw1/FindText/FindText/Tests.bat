@echo off

REM Путь к тестируемой программе передается через первый аргумент командной строки
SET MyProgram="%~1"

REM Защита от запуска без аргументов
if %MyProgram%=="" (
	echo Please specify path to program
	exit /B 1
)

REM Open missing file should fail
%MyProgram% MissingFile.txt "hello world" && goto err
echo Test 1 passed

REM If text to search is not specified, program must fail
%MyProgram% onegin.txt && goto err
echo Test 2 passed

REM If input and output files are not specified, program must fail
%MyProgram% && goto err
echo Test 3 passed

REM Запуск программы с правильными параметрами, проверка поиска строк
%MyProgram% onegin.txt "Ideal" > "%TEMP%\output.txt" || goto err
fc "Ideal.txt" "%TEMP%\output.txt" || goto err
echo Test 4 passed

REM Запуск программы с правильными параметрами, проверка поиска строк
%MyProgram% onegin.txt "of" > "%TEMP%\output.txt" || goto err
fc "of.txt" "%TEMP%\output.txt" || goto err
echo Test 5 passed

REM Запуск программы с правильными параметрами, но искомого слова нет в тексте,
REM программа должна упасть
%MyProgram% onegin.txt "offf" && goto err
echo Test 6 passed

REM Тесты прошли успешно
echo All tests passed succesfuly
exit /B 0

REM Сюда попадаем в случае ошибки
:err
echo Test fail
exit /B 1