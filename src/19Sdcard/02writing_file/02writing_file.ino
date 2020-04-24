#include <SPI.h>
#include <SD.h>

File myFile;

// change this to match your SD shield or module;
const int chipSelect = 10;

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }


  Serial.print("Initializing SD card...");

  if (!SD.begin()) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open("arduino.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) {
    Serial.println("Writing to arduino.txt...");
    for(int i = 0; i < 10; i++){
        myFile.print("Testing: ");
        myFile.println(i);
    }
    // close the file:
    myFile.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening arduino.txt");
  }
}

void loop()
{
  // nothing happens after setup
}
