@echo off
if exist result.txt del result.txt
for %%i in (1,2,3,4,5,6,7,8,9,10) do call Test.bat %1 %%i