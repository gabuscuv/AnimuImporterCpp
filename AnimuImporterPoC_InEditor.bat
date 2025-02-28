call AnimuImporterPoC__CommonVariables

"%UEDIR%\Engine\Binaries\Win64\UnrealEditor-Cmd.exe" "%WORKDIR%AnimuImporter.uproject"  -ExecutePythonScript="%WORKDIR%AnimuImporterBootstrap.py -i %FILE%"