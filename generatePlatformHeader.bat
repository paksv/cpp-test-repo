SetLocal EnableDelayedExpansion
systeminfo | findstr /B /C:"OS Configuration" > osConfiguration.txt
FOR /F "tokens=4" %%F IN (osConfiguration.txt) DO (
SET var=%%F
)
ECHO %var%
if "%var%" == "Server" ( 
echo #define _WIN_SERVER_VAR_ TRUE > include2.h
) ELSE (
echo #define _WIN_DESKTOP_VAR_ TRUE > include2.h
)
del /q osConfiguration.txt