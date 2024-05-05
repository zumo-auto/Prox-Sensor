#include <Wire.h>
#include <Zumo32U4.h>

// declaratie display
Zumo32U4OLED display;

// Declaratie van de lijnsensoren en de Proxsensoren
Zumo32U4LineSensors lineSensors;
Zumo32U4ProximitySensors proxSensors;

// Variabelen om de status van de Proxsensoren op te slaan
bool proxLeftActive;
bool proxFrontActive;
bool proxRightActive;

// Setup functie, wordt eenmaal uitgevoerd bij het opstarten
void setup()
{
  // Initialisatie van de lijnsensoren en de Proxssensoren
  lineSensors.initThreeSensors();
  proxSensors.initThreeSensors();

  // Laden van aangepaste karakters voor de display
  loadCustomCharacters();
}

// Weet nog niet geheel wat dit doet
void loadCustomCharacters()
{
  
  static const char levels[] PROGMEM = {
    0, 0, 0, 0, 0, 0, 0, 63, 63, 63, 63, 63, 63, 63
  };
  
  display.loadCustomCharacter(levels + 0, 0);  // 1 bar
  display.loadCustomCharacter(levels + 1, 1);  // 2 bars
  display.loadCustomCharacter(levels + 2, 2);  // 3 bars
  display.loadCustomCharacter(levels + 3, 3);  // 4 bars
  display.loadCustomCharacter(levels + 4, 4);  // 5 bars
  display.loadCustomCharacter(levels + 5, 5);  // 6 bars
  display.loadCustomCharacter(levels + 6, 6);  // 7 bars
}

// Functie voor het afdrukken van een balk op de display (begrijp dit stuk code nog niet helemaal want heb namelijk geen balk op de display gezien)
void printBar(uint8_t height)
{
  // Beperk de hoogte van de balk tot maximaal 8
  if (height > 8) { height = 8; }
  // Array met karakters voor het afdrukken van de balk
  const char barChars[] = {' ', 0, 1, 2, 3, 4, 5, 6, (char)255};
  // Afdrukken van de balk op het display
  display.print(barChars[height]);
}

// Functie voor het afdrukken van gegevens van de proxsensor op de display
void printReadingsToDisplay()
{
  // Afdrukken van de waarden van de proxsensoren op de display
  display.gotoXY(0, 0); 
  display.print(F("Left: "));
  display.println(proxSensors.countsLeft());
  display.print(F("Front: "));
  display.println(proxSensors.countsFront());
  display.print(F("Right: "));
  display.println(proxSensors.countsRight());
}

// Functie voor het afdrukken van gegevens van de sensoren naar de seriële monitor
void printReadingsToSerial()
{
  // Afdrukken van de waarden van de proxsensoren naar de seriële monitor
  Serial.print(F("Left: "));
  Serial.println(proxSensors.countsLeft());
  Serial.print(F("Front: "));
  Serial.println(proxSensors.countsFront());
  Serial.print(F("Right: "));
  Serial.println(proxSensors.countsRight());
}

// Hoofdprogramma, wordt continu herhaald
void loop()
{
  // Variabele om de tijd van de laatste meting bij te houden
  static uint16_t lastSampleTime = 0;

  // Controleren of het tijd is voor een nieuwe meting
  if ((uint16_t)(millis() - lastSampleTime) >= 100)
  {
    lastSampleTime = millis();

    // Uitvoeren van metingen met de proxsensoren
    proxSensors.read();


    // Afdrukken van gegevens naar het display en de seriële monitor
    printReadingsToDisplay();
    printReadingsToSerial();
  }
}
