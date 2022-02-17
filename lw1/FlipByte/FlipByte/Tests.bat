@echo off

REM ���� � ����������� ��������� ���������� ����� ������ �������� ��������� ������
SET MyProgram="%~1"

REM ������ �� ������� ��� ����������
if %MyProgram%=="" (
	echo Please specify path to program
	exit /B 1
)

REM If input and output files are not specified, program must fail
%MyProgram% && goto err
echo Test 1 passed

REM ���� ������ �������� �� �����, ��������� ������ ������
%MyProgram% "dsf" && goto err
echo Test 2 passed

REM ���� ������ �������� ������ 0, ��������� ������ ������
%MyProgram% "-1" && goto err
echo Test 3 passed

REM ���� ������ �������� ������ 255, ��������� ������ ������
%MyProgram% "256" && goto err
echo Test 4 passed

REM ����� ������ �������
echo All tests passed succesfuly
exit /B 0

REM ���� �������� � ������ ������
:err
echo Test fail
exit /B 1