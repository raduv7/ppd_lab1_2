
$cFilePath = "cmake-build-debug\lab1_2.exe"

$inputFileNr = $args[0]
$threadsNr = $args[1]
$memoryAllocationStrategyCode = $args[2]
$convolutionStrategyCode = $args[3]

# Executare exe in cmd mode

$suma = 0

for ($i = 0; $i -lt 10; $i++){
    Write-Host "Rulare" ($i+1)
    $a = (cmd /c .\$cFilePath $inputFileNr $threadsNr $memoryAllocationStrategyCode $convolutionStrategyCode 2`>`&1)
    Write-Host $a
    $suma += $($a)
}
$media = $suma / $i
#Write-Host $suma
Write-Host "Timp de executie mediu:" $media

# Creare fisier .csv
if (!(Test-Path outC.csv)){
    New-Item outC.csv -ItemType File
    #Scrie date in csv
    Set-Content outC.csv 'Tip Matrice, Tip alocare(0 dyn, 1 static), Strategie de convolutie, Nr threads, Timp executie'
}

# Append
Add-Content outC.csv "$($inputFileNr),$($memoryAllocationStrategyCode),$($convolutionStrategyCode),$($threadsNr),$($media)"