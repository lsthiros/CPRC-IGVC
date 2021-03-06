/**
 * Skeleton of command recieve and response
 *
 * @author Louie Thiros
 */

#include "protocol.h"

//Ultrasonic group

//distance in cm stored as int in sensorResponse, returns success
char getCertainSensor(char sensor, int* sensorResponse) {
   //returns dummy value for now
   *sensorResponse = 0;
   //return success
   return 1;
}

//takes in 6 int array to store response, returns success
char getAllSensors(int* sensorResponse) {
   for(char i = 0; i < 6; i++) {
      getCertainSensor(i, &sensorResponse[i]);
   }
   //no error checking for now, return success
   return 1;
}

//stores cm values of a sensor group in sensorResponse
char getSensorGroup(char groupID, int *sensorResponse) {
   //different group ID's might mean different lengths. the dummy
   //implementation will place 3 0x0000's in the response
   for(int i = 0; i < 3; i++) {
      *sensorResponse=0;
   }
   //return success
   return 1;
}

//Speed Sensor group

//get the speed of the vehicle
char getSpeed(char* sensorResponse) {
   //store dummy speed value
   *sensorResponse = 0;
   //return success
   return 1;
}

//will set just the speed of the wheels of the car
char setSpeed(char speedTarget) {
   //nothing done down here
   //return success
   return 1;
}

//Steering group

//JUST SETS ANGLE TARGET. Actual angle changing is lower level
char setAngle(char angleTarget) {
   //dummy function, nothing will happen for now...
   //return success
   return 1;
}

//get the current angle of the steering system
char getAngle(char* sensorResponse) {
   //store fake angle reading
   *sensorResponse = 0;
   //return success
   return 1;
}

//get the angle target. argument name is sensorResponse for the sake of consistancy
char getDesiredAngle(char* sensorResponse) {
   //fake response
   *sensorResponse = 0;
   //return success
   return 1;
}

//change the PID controller
char changePID(char P, char I, char D) {
   //dummy function, nothing happens
   //return success
   return 1;
}

//not sure what this does. Also not sure why upper and lower are separated
//but its in the specs so...
char setLimits(char upper, char lower) {
   //dummy function, nothing happens
   //return success
   return 1;
}

//FNR controller functions

//set the FNR controller, inputs are either -1, 0, or 1.
char setFNR(char FNR) {
   //dummy function, nothing happens
   //return success
   return 1;
}

//get the current FNR state. Function follows same format for consistancy
char getFNR(char *sensorResponse) {
   //fake reading
   *sensorResponse = 0;
   //return success
   return 1;
}

//Brake controller functions. THERE IS CURRENTLY NO WAY TO GET THE DESIRED
//BRAKE TARGET IN THE SPECS

//set brake target
char setBrake(char gainTarget) {
   //dummy function, nothing happens
   //return success
   return 1;
}

//get what is assumed to be the current brake value?
char getBrake(char* sensorResponse) {
   //fake brake reading
   *sensorResponse = 0;
   //return success
   return 1;
}

//battery controller functions

//read battery strength in a char. Might need to be unsigned, specs don't say
//anything regarding that.
char getBatteryVoltage(char *sensorResponse) {
   //fake battery reading
   *sensorResponse = 0;
   //return success
   return 1;
}

//gets voltage from steering?
char getSteeringVoltage(char *sensorResponse) {
   //fake steering voltage reading
   *sensorResponse = 0;
   //return success
   return 1;
}

//light controller functions

//turn lights on and off
char setLight(char lightTarget) {
   //dummy function, nothing happens
   //return success
   return 1;
}

//specs make no mention of a getLight

//function to CRC the command structure
char commandIntegCheck(Command *command) {
   //CRC the command with 0x00 in place of the CRC
   //return success for now
   return 1;
}

char processUltrasonicCommand(char commandCode, void* commandData, void* responseData) {
   switch(commandCode) {
      case GET_ALL_SENSORS:
         getAllSensors((int*) responseData);
         break;
      case GET_CERTAIN_SENSORS:
         getCertainSensor(*((char*)commandData), (int*) responseData);
         break;
      case GET_SENSOR_GROUP:
         getSensorGroup(*((char*)commandData), (int*) responseData);
         break;
   }
   //return success for now...
   return 1;
}

char processSpeedCommand(char commandCode, void* commandData, void* responseData) {
   switch(commandCode) {
      case GET_SPEED:
         getSpeed((char*) responseData);
         break;
      case SET_SPEED:
         setSpeed(*((char*)commandData));
         break;
   }
   //return success for now
   return 1;
}

char processSteeringCommand(char commandCode, void* commandData, void* responseData) {
   switch(commandCode) {
      case SET_ANGLE:
         setAngle(*((char*)commandData));
         break;
      case GET_ANGLE:
         getAngle((char*) responseData);
         break;
      case GET_DESIRED_ANGLE:
         getDesiredAngle((char*) responseData);
         break;
      case CHANGE_PID:
         changePID(((char*)commandData)[0], ((char*)commandData)[1], ((char*)commandData)[2]);
         break;
      case SET_LIMITS:
         setLimits(((char*)commandData)[0], ((char*)commandData)[1]);
         break;
   }
   //return success for now
   return 1;
}

char processFNRCommand(char commandCode, void* commandData, void* responseData) {
   switch(commandCode) {
      case SET_FNR:
         setFNR(*((char*)commandData));
         break;
      case GET_FNR:
         getFNR((char*) responseData);
         break;
   }
}

char processBrakeCommand(char commandCode, void* commandData, void* responseData) {
   switch(commandCode) {
      case SET_BRAKE:
	 setBrake(*((char*)commandData));
	 break;
      case GET_BRAKE:
	 getBrake((char*) responseData);
	 break; 
   }
}

char processBatteryCommand(char commandCode, void* commandData, void* responseData) {
   switch(commandCode) {
      case GET_BATTERY_VOLTAGE:
         getBatteryVoltage((char*) responseData);
         break;
      case GET_STEERING_VOLTAGE:
         getSteeringVoltage((char*) responseData);
         break;
   }
}

char processLightCommand(char commandCode, void* commandData, void* responseDate) {
   switch(commandCode) {
      case SET_LIGHT:
	 setLight(*((char*)commandData));
         break;
   }
}



//Function that will take in a command (as char array) and process it into a
//correct response to be stored into response
char processCommand(Command *command, Response *response) {
   if(commandIntegCheck(command)) {
      switch(command->groupID) {
         case ULTRASONIC_GROUP:
            /*do ultrasonic things*/
            break;
         case SPEED_GROUP:
            /*do speed things*/
            break;
         case STEERING_GROUP:
            /*do steering things*/
            break;
         case FNR_GROUP:
            /*do FRN things*/
            break;
         case BRAKES_GROUP:
            /*do brakes things*/
            break;
         case BATTERY_GROUP:
            /*do battery things*/
            break;
         case LIGHTS_GROUP:
            /*do light things*/
            break;
         case ERROR_GROUP:
            /*do error things*/
            break;
      }
      //return a dummy success for now
      return 1;
   } else {
      return 0;
   }
}
