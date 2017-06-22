# nodeMcu-iot
NodeMCU je nizkocenovni odprtokodni mikrokrmilnik za razvoj naprav IoT. Mikrokmilnik je interaktivna, programabilna, enostavna in pametna naprava z vgrajenim brezžičnim modulom, ki omogoča enostavno povezovanje naprave z internetom. V projektu “internet stvari” smo ga uporabili v kombinaciji s temperaturnim senzorjem DHT-11, ki omogoča merjenje temperature in zračne vlažnosti.
 
Ideja naprave je zbiranje podatkov in pošiljanje le-teh na vozlišče IoT. Za vozlišče uporabimo platformo Ubidots, kjer določimo novo napravo in ji dodamo spremenljivke. Spremenljivke predstavljajo vrednosti za temperaturo in vlago. Drugi korak implementacije je povezovanje senzorja z mirkormilnikom, nato pa programiranje. Napravo povežemo na znano brezžično omrežje. Sledi branje senzorja in obdelava prebranih podatkov. Podatke zapakiramo v objekt JSON in jih preko HTTP metode POST pošljemo na vozlišče IoT.

Razvojno ploščico programiramo z razvojnim okolje Arduino. Pri tem potrebujemo vključene dodatne knjižnice, ki so definirane v datoteki main.ino (esp8266).


# Reference
https://ubidots.com/
https://www.arduino.cc/
http://nodemcu.com/index_en.html
http://www.instructables.com/id/Quick-Start-to-Nodemcu-ESP8266-on-Arduino-IDE/
http://www.iotlearning.net/code/esp8266-code/nodemcu-web-server-showing-dht11-data.php#codesyntax_1
