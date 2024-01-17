# Funkcjonalnosc programu
Program sluzy do symulacji mrowki langtona,<br>
pozwala na zapisywanie stanow planszy do plikow<br>
oraz wczytywanie stanow planszy z plikow wejsciowych<br>

# Uruchamianie programu
Program nalezy skompilowac uzywajac komendy "make",<br>
a nastepnie uruchomic wpisujac komende:<br>
"./main [args]", gdzie args to argumenty opisane ponizej<br>

# Argumenty programu
"-r [int]" - liczba wierszy planszy, <br>
"-c [int]" - liczba kolumn planszy, <br>
"-g [int]" - liczba generacji (iteracji),<br>
"-o [string]" - przedrostek pliku wyjsciowego,<br>
"-i [string]" - nazwa pliku wejsciowego,<br>
"-a ["up", "down", "left", "right"] - pocz. kierunek mrowki,<br>
"-p [int (0-100)]" - procent poczatkowych czarnych pol<br>

# Uwagi
pliki wyjsciowe zapisywane sa w w folderze "output_files"<br>
pliki wejsciowe nalezy umiescic w folderze "input_files"<br>


