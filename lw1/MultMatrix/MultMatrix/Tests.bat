@echo off

REM Путь к тестируемой программе передается через первый аргумент командной строки
SET MyProgram="%~1"

REM Защита от запуска без аргументов
if %MyProgram%=="" (
	echo Please specify path to program
	exit /B 1
)

REM If no parameters, program must fail
%MyProgram% && goto err
echo Test 1 passed

REM If only 1 parameter, program must fail
%MyProgram% "MatrixFile1.txt" && goto err
echo Test 2 passed

REM if program get missing file, it must fail
%MyProgram% MissingFile.txt "MatrixFile2.txt" && goto err
echo Test 3 passed

REM If one matrix has incorrect dimensions in width, program must fail
%MyProgram% "wrongMatrixWidth.txt" "MatrixFile2.txt" && goto err
echo Test 4 passed

REM If one matrix has incorrect dimensions in height, program must fail
%MyProgram% "MatrixFile1.txt" "wrongMatrixHeight.txt" && goto err
echo Test 5 passed

REM If one file is empty, program must fail
%MyProgram% "MatrixFile1.txt" "empty.txt" && goto err
echo Test 6 passed

REM If one file dont have matrix, program must fail
%MyProgram% "MatrixFile1.txt" "hello.txt" && goto err
echo Test 7 passed

REM Check the correctness of matrix multiplication
%MyProgram% "MatrixFile1.txt" "MatrixFile2.txt" > "%TEMP%\output.txt" || goto err
fc "%TEMP%\output.txt" "resultMatrix.txt" || goto err
echo Test 8 passed

REM Тесты прошли успешно
echo All tests passed succesfuly
exit /B 0

REM Сюда попадаем в случае ошибки
:err
echo Test fail
exit /B 1