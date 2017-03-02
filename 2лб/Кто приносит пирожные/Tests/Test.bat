@echo off
@echo TEST %2
@echo TEST %2 >> result.txt
copy cookie.%2.in cookie.in > nul
Timer %1 2000 65536 >> result.txt
checker.exe cookie.%2.in >> result.txt
if exist cookie.in del cookie.in
if exist cookie.out del cookie.out