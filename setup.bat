@echo off
echo Copying files...

REM Set the source and target directories
set SOURCE_DIR=%USERPROFILE%\Desktop\Savarankiskas-1.0
set TARGET_DIR=C:\Program Files\VVK\Dagne_Sakalauskaite

REM Create the target directory if it doesn't exist
if not exist "%TARGET_DIR%" mkdir "%TARGET_DIR%"

REM Copy all files and subdirectories to the target directory
xcopy /E /Y "%SOURCE_DIR%\*" "%TARGET_DIR%\"

echo Files copied successfully.
pause
