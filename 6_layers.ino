//#define bluetoothInput 0
//#define bluetoothOutput 1
int state = 0;
int layer[6] = {A0,A1,A2,A3,A4,A5};
int column[9] = {2,3,4,5,6,7,8,9,10};


void setup() {
  // Set up columns as OUTPUT pins
  for(int i = 0; i<9; i++)   
  {
    pinMode(column[i], OUTPUT);  //setting rows to ouput
  }
  // Set up layers as OUTPUT pins
  for(int i = 0; i<6; i++)
  {
    pinMode(layer[i], OUTPUT);  //setting layers to output
  }
  // Set up bluetooth pins
  //pinMode(bluetoothInput, INPUT);
  //pinMode(bluetoothOutput, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  //---STATIC---
  bluetoothOnOff();
  //everythingOn();
  //flickerOn();
  
  //---DYNAMIC---
  //testTriangles();
  //triangles();
  //flashAllOn();
  //layers();
}

void bluetoothOnOff() {
  if(Serial.available() > 0) { // Checks weather data is being transmitted (i think)
    state = Serial.read(); // Reads the data from the serial connection
    Serial.println(state);
  }
  if (state == 48) {
    everythingOff();
    Serial.println("LED: OFF");
    state = 0;
  }
  else if (state == 49) {
    everythingOn();
    Serial.println("LED: ON");
    state = 0;
  }
}

// Layers are positive and columns are negatives
// Therefore setting layers to 1 turns them on, setting them to 0 turns them off
// Therefore setting columns to 0 turns them on, setting them to 1 turns them off

void everythingOn()
{
  for(int i = 0; i<9; i++)
  {
    digitalWrite(column[i], 0);
  }
  //turning on layers
  for(int i = 0; i<6; i++)
  {
    digitalWrite(layer[i], 1);
  }  
}

void everythingOff ()
{
  for(int i = 0; i<9; i++)
  {
    digitalWrite(column[i], 1);
  }
}

void flickerOn()
{
  int i = 150;
  while(i != 0)
  {
    everythingOn();
    delay(i);
    everythingOff();
    delay(i);
    i-= 5;
  }
}


// ----- FLASH TEST STUFF, NOT STATIC LIGHTING ------

void flashAllOn()
{
  // LAYER 1
  digitalWrite(layer[0], 1);
  digitalWrite(layer[1], 0);
  digitalWrite(layer[2], 0);
  digitalWrite(layer[3], 0);
  digitalWrite(layer[4], 0);
  digitalWrite(layer[5], 0);
  digitalWrite(column[0], 0);
  digitalWrite(column[1], 0);
  digitalWrite(column[2], 0);
  digitalWrite(column[3], 0);
  digitalWrite(column[4], 0);
  digitalWrite(column[5], 0);
  digitalWrite(column[6], 0);
  digitalWrite(column[7], 0);
  digitalWrite(column[8], 0);
  delay(3);
  // LAYER 2
  digitalWrite(layer[0], 0);
  digitalWrite(layer[1], 1);
  digitalWrite(layer[2], 0);
  digitalWrite(layer[3], 0);
  digitalWrite(layer[4], 0);
  digitalWrite(layer[5], 0);
  digitalWrite(column[0], 0);
  digitalWrite(column[1], 0);
  digitalWrite(column[2], 0);
  digitalWrite(column[3], 0);
  digitalWrite(column[4], 0);
  digitalWrite(column[5], 0);
  digitalWrite(column[6], 0);
  digitalWrite(column[7], 0);
  digitalWrite(column[8], 0);
  delay(3);
  // LAYER 3
  digitalWrite(layer[0], 0);
  digitalWrite(layer[1], 0);
  digitalWrite(layer[2], 1);
  digitalWrite(layer[3], 0);
  digitalWrite(layer[4], 0);
  digitalWrite(layer[5], 0);
  digitalWrite(column[0], 0);
  digitalWrite(column[1], 0);
  digitalWrite(column[2], 0);
  digitalWrite(column[3], 0);
  digitalWrite(column[4], 0);
  digitalWrite(column[5], 0);
  digitalWrite(column[6], 0);
  digitalWrite(column[7], 0);
  digitalWrite(column[8], 0);
  delay(3);
  // LAYER 4
  digitalWrite(layer[0], 0);
  digitalWrite(layer[1], 0);
  digitalWrite(layer[2], 0);
  digitalWrite(layer[3], 1);
  digitalWrite(layer[4], 0);
  digitalWrite(layer[5], 0);
  digitalWrite(column[0], 0);
  digitalWrite(column[1], 0);
  digitalWrite(column[2], 0);
  digitalWrite(column[3], 0);
  digitalWrite(column[4], 0);
  digitalWrite(column[5], 0);
  digitalWrite(column[6], 0);
  digitalWrite(column[7], 0);
  digitalWrite(column[8], 0);
  delay(3);
  // LAYER 5
  digitalWrite(layer[0], 0);
  digitalWrite(layer[1], 0);
  digitalWrite(layer[2], 0);
  digitalWrite(layer[3], 0);
  digitalWrite(layer[4], 1);
  digitalWrite(layer[5], 0);
  digitalWrite(column[0], 0);
  digitalWrite(column[1], 0);
  digitalWrite(column[2], 0);
  digitalWrite(column[3], 0);
  digitalWrite(column[4], 0);
  digitalWrite(column[5], 0);
  digitalWrite(column[6], 0);
  digitalWrite(column[7], 0);
  digitalWrite(column[8], 0);
  delay(3);
  // LAYER 6
  digitalWrite(layer[0], 0);
  digitalWrite(layer[1], 0);
  digitalWrite(layer[2], 0);
  digitalWrite(layer[3], 0);
  digitalWrite(layer[4], 0);
  digitalWrite(layer[5], 1);
  digitalWrite(column[0], 0);
  digitalWrite(column[1], 0);
  digitalWrite(column[2], 0);
  digitalWrite(column[3], 0);
  digitalWrite(column[4], 0);
  digitalWrite(column[5], 0);
  digitalWrite(column[6], 0);
  digitalWrite(column[7], 0);
  digitalWrite(column[8], 0);
  delay(3);
}

void triangles()
{
  // LAYER 1
  digitalWrite(layer[0], 1);
  digitalWrite(layer[1], 0);
  digitalWrite(layer[2], 0);
  digitalWrite(layer[3], 0);
  digitalWrite(layer[4], 0);
  digitalWrite(layer[5], 0);
  digitalWrite(column[0], 0);
  digitalWrite(column[1], 0);
  digitalWrite(column[2], 0); 
  digitalWrite(column[3], 0);
  digitalWrite(column[4], 0);
  digitalWrite(column[5], 0);
  digitalWrite(column[6], 0);
  digitalWrite(column[7], 0);
  digitalWrite(column[8], 0);
  delay(30);
  // LAYER 2
  digitalWrite(layer[0], 0);
  digitalWrite(layer[1], 1);
  digitalWrite(layer[2], 0);
  digitalWrite(layer[3], 0);
  digitalWrite(layer[4], 0);
  digitalWrite(layer[5], 0);
  digitalWrite(column[0], 1);
  digitalWrite(column[1], 0);
  digitalWrite(column[2], 1); 
  digitalWrite(column[3], 1);
  digitalWrite(column[4], 0);
  digitalWrite(column[5], 1);
  digitalWrite(column[6], 1);
  digitalWrite(column[7], 0);
  digitalWrite(column[8], 1);
  delay(30);
  // LAYER 3
  digitalWrite(layer[0], 0);
  digitalWrite(layer[1], 0);
  digitalWrite(layer[2], 1);
  digitalWrite(layer[3], 0);
  digitalWrite(layer[4], 0);
  digitalWrite(layer[5], 0);
  digitalWrite(column[0], 0);
  digitalWrite(column[1], 0);
  digitalWrite(column[2], 0); 
  digitalWrite(column[3], 0);
  digitalWrite(column[4], 0);
  digitalWrite(column[5], 0);
  digitalWrite(column[6], 0);
  digitalWrite(column[7], 0);
  digitalWrite(column[8], 0);
  delay(30);
  // LAYER 4
  digitalWrite(layer[0], 0);
  digitalWrite(layer[1], 0);
  digitalWrite(layer[2], 0);
  digitalWrite(layer[3], 1);
  digitalWrite(layer[4], 0);
  digitalWrite(layer[5], 0);
  digitalWrite(column[0], 1);
  digitalWrite(column[1], 0);
  digitalWrite(column[2], 1); 
  digitalWrite(column[3], 1);
  digitalWrite(column[4], 0);
  digitalWrite(column[5], 1);
  digitalWrite(column[6], 1);
  digitalWrite(column[7], 0);
  digitalWrite(column[8], 1);
  delay(30);
  // LAYER 5
  digitalWrite(layer[0], 0);
  digitalWrite(layer[1], 0);
  digitalWrite(layer[2], 0);
  digitalWrite(layer[3], 0);
  digitalWrite(layer[4], 1);
  digitalWrite(layer[5], 0);
  digitalWrite(column[0], 0);
  digitalWrite(column[1], 0);
  digitalWrite(column[2], 0); 
  digitalWrite(column[3], 0);
  digitalWrite(column[4], 0);
  digitalWrite(column[5], 0);
  digitalWrite(column[6], 0);
  digitalWrite(column[7], 0);
  digitalWrite(column[8], 0);
  delay(30);
  // LAYER 6
  digitalWrite(layer[0], 0);
  digitalWrite(layer[1], 0);
  digitalWrite(layer[2], 0);
  digitalWrite(layer[3], 0);
  digitalWrite(layer[4], 0);
  digitalWrite(layer[5], 1);
  digitalWrite(column[0], 1);
  digitalWrite(column[1], 0);
  digitalWrite(column[2], 1); 
  digitalWrite(column[3], 1);
  digitalWrite(column[4], 0);
  digitalWrite(column[5], 1);
  digitalWrite(column[6], 1);
  digitalWrite(column[7], 0);
  digitalWrite(column[8], 1);
  delay(30);
}

void testTriangles()
{
    // LAYER 1
  digitalWrite(layer[0], 0);
  digitalWrite(layer[1], 0);
  digitalWrite(layer[2], 0);
  digitalWrite(layer[3], 0);
  digitalWrite(layer[4], 0);
  digitalWrite(layer[5], 0);
  digitalWrite(column[0], 0);
  digitalWrite(column[1], 0);
  digitalWrite(column[2], 0); 
  digitalWrite(column[3], 0);
  digitalWrite(column[4], 0);
  digitalWrite(column[5], 0);
  digitalWrite(column[6], 0);
  digitalWrite(column[7], 0);
  digitalWrite(column[8], 0);
  delay(3);
  // LAYER 2
  digitalWrite(layer[0], 0);
  digitalWrite(layer[1], 0);
  digitalWrite(layer[2], 0);
  digitalWrite(layer[3], 0);
  digitalWrite(layer[4], 0);
  digitalWrite(layer[5], 0);
  
  digitalWrite(column[0], 1);
  digitalWrite(column[1], 0);
  digitalWrite(column[2], 1); 
  digitalWrite(column[3], 1);
  digitalWrite(column[4], 0);
  digitalWrite(column[5], 1);
  digitalWrite(column[6], 1);
  digitalWrite(column[7], 0);
  digitalWrite(column[8], 1);/*
  digitalWrite(column[0], 0);
  digitalWrite(column[1], 0);
  digitalWrite(column[2], 0); 
  digitalWrite(column[3], 0);
  digitalWrite(column[4], 0);
  digitalWrite(column[5], 0);
  digitalWrite(column[6], 0);
  digitalWrite(column[7], 0);
  digitalWrite(column[8], 0);*/
  delay(3);
  // LAYER 3
  digitalWrite(layer[0], 0);
  digitalWrite(layer[1], 0);
  digitalWrite(layer[2], 0);
  digitalWrite(layer[3], 0);
  digitalWrite(layer[4], 0);
  digitalWrite(layer[5], 0);
  digitalWrite(column[0], 0);
  digitalWrite(column[1], 0);
  digitalWrite(column[2], 0); 
  digitalWrite(column[3], 0);
  digitalWrite(column[4], 0);
  digitalWrite(column[5], 0);
  digitalWrite(column[6], 0);
  digitalWrite(column[7], 0);
  digitalWrite(column[8], 0);
  delay(3);
  // LAYER 4
  digitalWrite(layer[0], 0);
  digitalWrite(layer[1], 0);
  digitalWrite(layer[2], 0);
  digitalWrite(layer[3], 0);
  digitalWrite(layer[4], 0);
  digitalWrite(layer[5], 0);
  digitalWrite(column[0], 0);
  digitalWrite(column[1], 0);
  digitalWrite(column[2], 0); 
  digitalWrite(column[3], 0);
  digitalWrite(column[4], 0);
  digitalWrite(column[5], 0);
  digitalWrite(column[6], 0);
  digitalWrite(column[7], 0);
  digitalWrite(column[8], 0);
  delay(3);
  // LAYER 5
  digitalWrite(layer[0], 0);
  digitalWrite(layer[1], 0);
  digitalWrite(layer[2], 0);
  digitalWrite(layer[3], 0);
  digitalWrite(layer[4], 0);
  digitalWrite(layer[5], 0);
  digitalWrite(column[0], 0);
  digitalWrite(column[1], 0);
  digitalWrite(column[2], 0); 
  digitalWrite(column[3], 0);
  digitalWrite(column[4], 0);
  digitalWrite(column[5], 0);
  digitalWrite(column[6], 0);
  digitalWrite(column[7], 0);
  digitalWrite(column[8], 0);
  delay(3);
  // LAYER 6
  digitalWrite(layer[0], 0);
  digitalWrite(layer[1], 0);
  digitalWrite(layer[2], 0);
  digitalWrite(layer[3], 0);
  digitalWrite(layer[4], 0);
  digitalWrite(layer[5], 0);
  digitalWrite(column[0], 0);
  digitalWrite(column[1], 0);
  digitalWrite(column[2], 0); 
  digitalWrite(column[3], 0);
  digitalWrite(column[4], 0);
  digitalWrite(column[5], 0);
  digitalWrite(column[6], 0);
  digitalWrite(column[7], 0);
  digitalWrite(column[8], 0);
  delay(3);
}

void layers()
{
    // LAYER 1
  digitalWrite(layer[0], 1);
  digitalWrite(layer[1], 1);
  digitalWrite(layer[2], 0);
  digitalWrite(layer[3], 0);
  digitalWrite(layer[4], 0);
  digitalWrite(layer[5], 0);
  digitalWrite(column[0], 0);
  digitalWrite(column[1], 0);
  digitalWrite(column[2], 0); 
  digitalWrite(column[3], 0);
  digitalWrite(column[4], 0);
  digitalWrite(column[5], 0);
  digitalWrite(column[6], 0);
  digitalWrite(column[7], 0);
  digitalWrite(column[8], 0);
}
