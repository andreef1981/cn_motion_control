@ECHO OFF
ECHO
ECHO This script will delet the existing the master configuration file and create a new one.
ECHO
PAUSE

SET FileToDelete="master_configuration_file.txt"
IF EXIST %FileToDelete% del /F %FileToDelete%
IF EXIST %FileToDelete% exit 1

FOR /F "usebackq delims=" %%a IN (inclusion_list.txt) do TYPE %%a >> master_configuration_file.txt
FOR /F "usebackq delims=" %%a IN (inclusion_list.txt) do @echo %%a
PAUSE
CLS
EXIT