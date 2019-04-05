#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
  
Adafruit_BNO055 bno = Adafruit_BNO055(55);
 
void setup(void) 
{
  Serial.begin(9600);
  //Serial.println("Orientation Sensor Test"); Serial.println("");
  
  /* Initialise the sensor */
  if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    //Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }
  
  delay(1000);
  //displayCalStatus();
    
  bno.setExtCrystalUse(true);
}

/**************************************************************************/
/*
    Display sensor calibration status
*/
/**************************************************************************/
void displayCalStatus(void)
{
  /* Get the four calibration values (0..3) */
  /* Any sensor data reporting 0 should be ignored, */
  /* 3 means 'fully calibrated" */
  uint8_t system, gyro, accel, mag;
  system = gyro = accel = mag = 0;

  while(system == 0 || gyro == 0 || accel == 0 || mag == 0) {
  
    bno.getCalibration(&system, &gyro, &accel, &mag);
  
    /* The data should be ignored until the system calibration is > 0 */
    Serial.print("\t");
    if (!system) {
      Serial.print("! ");
    }
  
    /* Display the individual values */
    Serial.print("Sys:");
    Serial.print(system, DEC);
    Serial.print(" G:");
    Serial.print(gyro, DEC);
    Serial.print(" A:");
    Serial.print(accel, DEC);
    Serial.print(" M:");
    Serial.println(mag, DEC);
  
    delay(1000);
  }
}


 
void loop(void) 
{

   // Possible vector values can be:
  // - VECTOR_ACCELEROMETER - m/s^2
  // - VECTOR_MAGNETOMETER  - uT
  // - VECTOR_GYROSCOPE     - rad/s
  // - VECTOR_EULER         - degrees
  // - VECTOR_LINEARACCEL   - m/s^2
  // - VECTOR_GRAVITY       - m/s^2
  
  
  /* Get a new sensor event */ 
  sensors_event_t event; 
  bno.getEvent(&event);

  /* Magnetometer - uT, micro Teslas
   *  
   *  X = left/right ?
   *  Y = forward/backward ?
   *  Z = up/down ?
   *  
   */ 
  imu::Vector<3> mag = bno.getVector(Adafruit_BNO055::VECTOR_MAGNETOMETER);

  /* Gyroscope - rps, radians per second 
   *  
   *  Seems the "star" on the board signifies "top" of the board
   *  
  */
  imu::Vector<3> gyro = bno.getVector(Adafruit_BNO055::VECTOR_GYROSCOPE);

  /* Positional - degrees 0 to 359
   *  
   *  X = Heading
   *  Y = Roll
   *  Z = Pitch
   *  
  */
  imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);

  /* Acceleration - m/s^2 */
  imu::Vector<3> accel = bno.getVector(Adafruit_BNO055::VECTOR_ACCELEROMETER);

  /* Linear Accel - m/s^2 */
  imu::Vector<3> linaccel = bno.getVector(Adafruit_BNO055::VECTOR_LINEARACCEL);

  /* Gravity - m/s^2 */
  imu::Vector<3> grav = bno.getVector(Adafruit_BNO055::VECTOR_GRAVITY);

  /* Temperature - Celcius to Fahrenheit */
  int8_t tempC = bno.getTemp();
  int8_t tempF = (tempC * 1.8) + 32;

  /* MAG: X Y Z 
   * GYRO: X Y Z 
   * POS: X Y Z 
   * ACCEL: X Y Z 
   * LINEAR_ACCEL: X Y Z 
   * GRAV: X Y Z 
   * TEMP: tempF
   * 
   * MAG GYRO POS ACCEL LIN_ACCEL GRAV TEMP
   * 
  */

  /* Displaying values */

  String magVals = String(mag.x(), 4) + "," + String(mag.y(), 4) + "," + String(mag.z(), 4);
  String gyroVals = String(gyro.x(), 4) + "," + String(gyro.y(), 4) + "," + String(gyro.z(), 4);
  String eulerVals = String(euler.x(), 4) + "," + String(euler.y(), 4) + "," + String(euler.z(), 4);
  String accelVals = String(accel.x(), 4) + "," + String(accel.y(), 4) + "," + String(accel.z(), 4);
  String linAccelVals = String(linaccel.x(), 4) + "," + String(linaccel.y(), 4) + "," + String(linaccel.z(), 4);
  String gravVals = String(grav.x(), 4) + "," + String(grav.y(), 4) + "," + String(grav.z(), 4);
  String tempVal = String(tempF);

  String values = magVals + "|" + gyroVals + "|" + eulerVals + "|" + accelVals + "|" + linAccelVals + "|" + gravVals + "|" + tempVal;

  Serial.println(values);
  
  delay(400);
}
