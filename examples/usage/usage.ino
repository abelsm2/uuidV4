// Example usage for uuidV4 library by Micah L Abelson.

// Be sure to include the library from the IDE

void setup() {

	// start serial
    Serial.begin();
    
}

void loop() {
    
	// create large enough string to hold UUID
    char uuid[37];
    
	// store a new UUID in the string
	// note that you need uuid:: to get the correct namespace
    uuid::generateUuidV4(uuid);
    
	// print the UUID to serial
    Serial.println(uuid);
    
	// wait 5 seconds to create another UUID
    delay(5000);
}