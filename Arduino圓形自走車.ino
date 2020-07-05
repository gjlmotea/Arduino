#include <IRremote.h>
#define MotorA_I1 8
#define MotorA_I2 9
#define MotorB_I3 10
#define MotorB_I4 11
#define MotorA_PWMA 5
#define MotorB_PWMB 6
IRrecv irrecv(2);
decode_results results;
void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
  pinMode(MotorA_I1, OUTPUT);
  pinMode(MotorA_I2, OUTPUT);
  pinMode(MotorB_I3, OUTPUT);
  pinMode(MotorB_I4, OUTPUT);
  pinMode(MotorA_PWMA, OUTPUT);
  pinMode(MotorB_PWMB, OUTPUT);
  analogWrite(MotorA_PWMA, 200);
  analogWrite(MotorB_PWMB, 200);
  digitalWrite(MotorA_I1, LOW);
  digitalWrite(MotorA_I2, LOW);
  digitalWrite(MotorB_I3, LOW);
  digitalWrite(MotorB_I4, LOW);
}

int laststate = 0;
void loop() {
  if (irrecv.decode(&results)) {
    if (results.value == 4294967295 && laststate == 16736925) {
      digitalWrite(MotorA_I1, LOW);
      digitalWrite(MotorA_I2, HIGH);
      digitalWrite(MotorB_I3, HIGH);
      digitalWrite(MotorB_I4, LOW);
      irrecv.resume();
    }
    if (results.value == 4294967295 && laststate == 16754775) {
      digitalWrite(MotorA_I1, HIGH);
      digitalWrite(MotorA_I2, LOW);
      digitalWrite(MotorB_I3, LOW);
      digitalWrite(MotorB_I4, HIGH);
      irrecv.resume();
    }
    if (results.value == 4294967295 && laststate == 16720605) {
      digitalWrite(MotorA_I1, LOW);
      digitalWrite(MotorA_I2, HIGH);
      digitalWrite(MotorB_I3, LOW);
      digitalWrite(MotorB_I4, HIGH);
      irrecv.resume();
    }
    if (results.value == 4294967295 && laststate == 16761405) {
      digitalWrite(MotorA_I1, HIGH);
      digitalWrite(MotorA_I2, LOW);
      digitalWrite(MotorB_I3, HIGH);
      digitalWrite(MotorB_I4, LOW);
      irrecv.resume();
    }

    if (results.value == 16736925) {
      digitalWrite(MotorA_I1, LOW);
      digitalWrite(MotorA_I2, HIGH);
      digitalWrite(MotorB_I3, HIGH);
      digitalWrite(MotorB_I4, LOW);
      laststate = 16736925;
    }
    if (results.value == 16754775) {
      digitalWrite(MotorA_I1, HIGH);
      digitalWrite(MotorA_I2, LOW);
      digitalWrite(MotorB_I3, LOW);
      digitalWrite(MotorB_I4, HIGH);
      laststate = 16754775;
    }
    if (results.value == 16720605) {
      digitalWrite(MotorA_I1, LOW);
      digitalWrite(MotorA_I2, HIGH);
      digitalWrite(MotorB_I3, LOW);
      digitalWrite(MotorB_I4, HIGH);
      laststate = 16754775;
    }
    if (results.value == 16761405) {
      digitalWrite(MotorA_I1, HIGH);
      digitalWrite(MotorA_I2, LOW);
      digitalWrite(MotorB_I3, HIGH);
      digitalWrite(MotorB_I4, LOW);
      laststate = 16754775;
    }
    if (results.value == 16712445) { //OK
      digitalWrite(MotorA_I1, LOW);
      digitalWrite(MotorA_I2, LOW);
      digitalWrite(MotorB_I3, LOW);
      digitalWrite(MotorB_I4, LOW);
      laststate = 16712445;
    }
    irrecv.resume();

  } else {
    digitalWrite(MotorA_I1, LOW);
    digitalWrite(MotorA_I2, LOW);
    digitalWrite(MotorB_I3, LOW);
    digitalWrite(MotorB_I4, LOW);
  }
  delay(150);
}
