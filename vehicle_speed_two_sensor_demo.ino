/*
 NEW DEMONSTRATION CODE — not original project code.
 Two ultrasonic modules are placed a known distance apart along the travel direction.
 This estimates speed from the time difference between detected object arrivals.
 Ultrasonic reflections can be noisy; this is a learning prototype, not a certified speed meter.
*/
const int TRIG1=2, ECHO1=3, TRIG2=4, ECHO2=7;
const float SENSOR_SPACING_M=0.20; // measure actual spacing and update
const unsigned long TIMEOUT_US=25000;
unsigned long t1=0, t2=0;
bool seen1=false, seen2=false;

float distanceCm(int trig,int echo) {
  digitalWrite(trig,LOW); delayMicroseconds(3);
  digitalWrite(trig,HIGH); delayMicroseconds(10); digitalWrite(trig,LOW);
  unsigned long duration=pulseIn(echo,HIGH,TIMEOUT_US);
  if(duration==0) return -1;
  return duration*0.0343f/2.0f;
}
bool objectPresent(int trig,int echo) {
  float d=distanceCm(trig,echo);
  return d>0 && d<80; // tune threshold for your test setup
}
void resetIfDone() {
  if(seen1 && seen2) {
    unsigned long dt=t2-t1;
    if(dt>0) {
      float speed_ms=SENSOR_SPACING_M/(dt/1000000.0f);
      Serial.print("Estimated speed: "); Serial.print(speed_ms,2);
      Serial.print(" m/s | "); Serial.print(speed_ms*3.6f,2); Serial.println(" km/h");
    }
    seen1=false; seen2=false; t1=0; t2=0;
    delay(500);
  }
}
void setup() {
  pinMode(TRIG1,OUTPUT); pinMode(ECHO1,INPUT);
  pinMode(TRIG2,OUTPUT); pinMode(ECHO2,INPUT);
  Serial.begin(9600);
  Serial.println("Two-sensor speed demo ready; verify spacing and sensor geometry.");
}
void loop() {
  if(!seen1 && objectPresent(TRIG1,ECHO1)) { t1=micros(); seen1=true; Serial.println("Sensor 1 detected"); }
  if(seen1 && !seen2 && objectPresent(TRIG2,ECHO2)) { t2=micros(); seen2=true; Serial.println("Sensor 2 detected"); }
  resetIfDone();
}
