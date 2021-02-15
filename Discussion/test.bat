REM a script to stress test your solution
REM sol.cpp is your optimized solution, brute.cpp is slow and correct solution at least according to you  
REM gen.cpp is the generator to generate random testcases
REM Now compile all the three files gen, sol and brute
REM to compile any file , run in command prompt : g++ file.cpp -o file.exe
REM when this program will exit, you will have the counter testcase stored in "in", wrong answer given by
REM sol.cpp in "out" file and correct answer given by brute.cpp in "ok" file
@echo off
gen >in
sol <in >out
brute <in >ok
fc out ok
if errorlevel 1 exit
test