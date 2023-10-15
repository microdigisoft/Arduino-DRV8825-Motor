int M0Pin   = A0;                  // Stepstick M0 to Arduino Analog pin A0
int M1Pin   = A1;                  // Stepstock M1 to Arduino Analog pin A1
int M2Pin   = A2;                  // Stepstick M2 to Arduino Analog pin A2
int StepPin  = A3;                 // Stepstick STEP pin to Arduino Analog pin A3
int DirPin   = A4;                 // Stepstick DIR pin to Arduino Analog pin A4
int NumofSteps = 708;                 //720/5.625 degree = 128/2 = 64 
int rotations = 3;                  // Number of rotations of the rotor for each
int delay1  =   2;                  // Delay between coil activations (ms)
int delay2  =   2000;               // Delay between subsequent rotations
int i;                              // int to use in for loop

//------------------------------
void setup() {

  pinMode(M0Pin, OUTPUT); // M0/MS1 set to receive Arduino signals
  pinMode(M1Pin, OUTPUT); // M1/MS2 set to receive Arduino signals
  pinMode(M2Pin, OUTPUT); // M2/MS3 set to receive Arduino signals
  pinMode(StepPin, OUTPUT); // stepPin set to receive Arduino signals
  pinMode(DirPin, OUTPUT); // DIR set to receive Arduino signals
}

//------------------------------

void loop() {

  delay(delay2);
  digitalWrite(DirPin, LOW);
  // Rotate stepper rotatations revolutions, using full step method
  digitalWrite(M0Pin, LOW);
  digitalWrite(M1Pin, LOW);
  digitalWrite(M2Pin, LOW);

  for (i = 1; i <= (numofSteps * 1 * rotations); ++i) {
    digitalWrite(StepPin, LOW);    // Prepare to take a step
    digitalWrite(StepPin, HIGH) ;  // Take a step
    delay(delay1);                 // Allow some delay between energizing
    // the coils to allow stepper rotor time to respond.
  }
  delay(delay2);

  digitalWrite(DirPin, HIGH);
  // Rotate stepper rotatations revolutions, using half step method
  digitalWrite(M0Pin, HIGH);
  digitalWrite(M1Pin, LOW);
  digitalWrite(M2Pin, LOW);
  for (i = 1; i <= (numofSteps * 2 * rotations); ++i) {
    digitalWrite(StepPin, LOW);     // Prepare to take a step
    digitalWrite(StepPin, HIGH) ;   // Take a step
    delay(delay1);                  // Allow some delay between energizing
    // the coils to allow stepper rotor time to respond.
  }
  delay(delay2);
  digitalWrite(DirPin, LOW);

  // Rotate stepper a rotatations revolutions, using quarter stepping
  digitalWrite(M0Pin, LOW);
  digitalWrite(M1Pin, HIGH);
  digitalWrite(M2Pin, LOW);
  for (i = 1; i <= (numofSteps * 4 * rotations); ++i) {
    digitalWrite(StepPin, LOW);     // Prepare to take a step
    digitalWrite(StepPin, HIGH) ;   // Take a step
    delay(delay1);                  // Allow some delay between energizing
    // the coils to allow stepper rotor time to respond.
  }

  // Rotate stepper rotations revolution, using microstepping
  //  8 steps/step

  delay(delay2);
  digitalWrite(DirPin, HIGH);
  digitalWrite(M0Pin, HIGH);
  digitalWrite(M1Pin, HIGH);
  digitalWrite(M2Pin, LOW);
  for (i = 1; i <= (numofSteps * 8 * rotations); ++i) {
    digitalWrite(StepPin, LOW);       // Prepare to take a step
    digitalWrite(StepPin, HIGH) ;     // Take a step
    delay(delay1);                    // Allow some delay between energizing
    // the coils to allow stepper rotor time to respond.
  }

  // Rotate stepper rotations revolution, using microstepping
  //  16 steps/step

  delay(delay2);
  digitalWrite(DirPin, LOW);
  digitalWrite(M0Pin, LOW);
  digitalWrite(M1Pin, LOW);
  digitalWrite(M2Pin, HIGH);
  for (i = 1; i <= numofSteps * 16 * rotations; ++i) {
    digitalWrite(StepPin, LOW);         // Prepare to take a step
    digitalWrite(StepPin, HIGH) ;       // Take a step
    delay(delay1);                      // Allow some delay between energizing
    // the coils to allow stepper rotor time to respond.
  }
  // Rotate stepper rotations revolution, using microstepping
  //  32 steps/step

  delay(delay2);
  digitalWrite(DirPin, HIGH);
  digitalWrite(M0Pin, HIGH);
  digitalWrite(M1Pin, HIGH);
  digitalWrite(m2Pin, HIGH);
  for (i = 1; i <= numofSteps * 32 * rotations; ++i) {
    digitalWrite(StepPin, LOW);         // Prepare to take a step
    digitalWrite(StepPin, HIGH) ;       // Take a step
    delay(delay1);                      // Allow some delay between energizing
    // the coils to allow stepper rotor time to respond.
  }
}
