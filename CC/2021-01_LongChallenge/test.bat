@echo off
gen >in
Watching_CPL <in >out
brute <in >ok
fc out ok
if errorlevel 1 exit
test