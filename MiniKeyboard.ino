#include "HID-Project.h"

byte rows[] = {2, 3, 4};
const int rowCount = sizeof(rows)/sizeof(rows[0]);

// JP2 and JP3 are outputs
byte cols[] = {7, 8,9, 10};
const int colCount = sizeof(cols)/sizeof(cols[0]);

byte keys[colCount][rowCount];

void setup() {
  //Consumer.begin();
  Serial.begin(115200);
  while (!Serial) ; // wait for serial to start up
  
  for(int x=0; x<rowCount; x++) {
    Serial.print(rows[x]); Serial.println(" as input");
    pinMode(rows[x], INPUT);
  }

  for (int x=0; x<colCount; x++) {
    Serial.print(cols[x]); Serial.println(" as input-pullup");
    pinMode(cols[x], INPUT_PULLUP);
  }
    
}

void readMatrix() {
  // iterate the columns
  for (int colIndex=0; colIndex < colCount; colIndex++) {
    // col: set to output to low
    byte curCol = cols[colIndex];
    //Serial.println(curCol);
    pinMode(curCol, OUTPUT);
    digitalWrite(curCol, LOW);

    // row: interate through the rows
    for (int rowIndex=0; rowIndex < rowCount; rowIndex++) {
      //Serial.printf("row: %d\n", rowIndex);
      byte rowCol = rows[rowIndex];
      pinMode(rowCol, INPUT_PULLUP);
      keys[colIndex][rowIndex] = digitalRead(rowCol);
      pinMode(rowCol, INPUT);
    }
    // disable the column
    pinMode(curCol, INPUT);
  }
}

void printMatrix() {
  for (int rowIndex=0; rowIndex < rowCount; rowIndex++) {
    if (rowIndex < 10)
      Serial.print(F("0"));
    Serial.print(rowIndex); Serial.print(F(": "));

    for (int colIndex=0; colIndex < colCount; colIndex++) { 
      Serial.print(keys[colIndex][rowIndex]);
      if (colIndex < colCount)
        Serial.print(F(", "));
    } 
    Serial.println("");
  }
  Serial.println("");
}

void loop() {
  readMatrix();
  if (Serial.read()=='!')
    printMatrix();
}
