# Funkcjonalnosc programu
Program sluzy do symulacji mrowki langtona,<bl>
pozwala na zapisywanie stanow planszy do plikow
oraz wczytywanie stanow planszy z plikow wejsciowych

# Uruchamianie programu
Program nalezy skompilowac uzywajac komendy "make",
a nastepnie uruchomic wpisujac komende:
"./main [args]", gdzie args to argumenty opisane ponizej

# Argumenty programu
"-r [int]" - liczba wierszy planszy, 
"-c [int]" - liczba kolumn planszy, 
"-g [int]" - liczba generacji (iteracji),
"-o [string]" - przedrostek pliku wyjsciowego,
"-i [string]" - nazwa pliku wejsciowego,
"-a ["up", "down", "left", "right"] - pocz. kierunek mrowki,
"-p [int (0-100)]" - procent poczatkowych czarnych pol

# Uwagi
pliki wyjsciowe zapisywane sa w w folderze "output_files"
pliki wejsciowe nalezy umiescic w folderze "input_files"


