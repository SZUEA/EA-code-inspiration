@echo off
g++ b.cpp -o b.exe
g++ c.cpp -o c.exe
g++ gen.cpp -o gen.exe

set /a i=0
set /a T=100

:loop
gen.exe > data.txt
c.exe < data.txt > c.txt
b.exe < data.txt > b.txt

fc c.txt b.txt

echo Running on test %i%

if %i% == %T% goto end

set /a i=i+1

if not errorlevel 1 goto loop

:end

pause