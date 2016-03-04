int LED = 13;
String val;

void setup() {
 // put your setup code here, to run once:
 Serial.begin(11520);       // start serial communication at 9600bps
 pinMode(LED, OUTPUT);
}

void loop() {
 // put your main code here, to run repeatedly:
 while(!Serial.available());
 while(Serial.available()){
  val += Serial.read();
 }
  
 Serial.println(val);



 delay(100);                    // wait 100ms for next reading
}
