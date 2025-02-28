call AnimuImporterPoC__CommonVariables

"%UEDIR%\Engine\Binaries\Win64\UnrealEditor-Cmd.exe" "%WORKDIR%AnimuImporter.uproject" -run=pythonscript -script="%WORKDIR%AnimuImporterBootstrap.py -i %FILE%"