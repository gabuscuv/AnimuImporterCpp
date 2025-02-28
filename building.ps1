# Init Variable
$oldPWD=(Get-Location).Path
$uproject=(Get-ChildItem *.uproject).FullName

#Writable Variables
$UE4DIR="I:\Program Files\Epic Games\UE_*"
$PROFILE="Development"

cd $UE4DIR

Engine/Build/BatchFiles/RunUAT.bat `
BuildCookRun `
    -project="$uproject" -noP4 `
    -platform=Win64 -clientconfig="$PROFILE" -build
if (! $Args[0] -eq "--withoutpause") {PAUSE}
