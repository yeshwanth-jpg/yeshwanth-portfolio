/*
 NEW EXAMPLE CODE — ESP32 + UART GPS module using TinyGPSPlus.
 Install TinyGPSPlus from Arduino Library Manager.
 Wiring example for many ESP32 boards: GPS TX -> GPIO16 (RX2), GPS RX -> GPIO17 (TX2).
 Check your board pinout and GPS logic voltage before wiring.
*/
#include <TinyGPSPlus.h>
TinyGPSPlus gps;
HardwareSerial GPSSerial(2);
void setup() {
  Serial.begin(115200);
  GPSSerial.begin(9600, SERIAL_8N1, 16, 17);
  Serial.println("ESP32 GPS tracker demo started");
}
void loop() {
  while (GPSSerial.available()) gps.encode(GPSSerial.read());
  if (gps.location.isUpdated()) {
    Serial.print("Latitude: "); Serial.println(gps.location.lat(), 6);
    Serial.print("Longitude: "); Serial.println(gps.location.lng(), 6);
    Serial.print("Satellites: "); Serial.println(gps.satellites.value());
    Serial.print("HDOP: "); Serial.println(gps.hdop.hdop());
    Serial.println("---");
  }
  delay(10);
}
