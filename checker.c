#include <stdio.h>
#include <assert.h>


void printToConsole( char *StringName){
printf("%s out of range!\n", StringName);
}

float checkTemp(float temp , void (*fpPrint)(char *)){
 char StringName[15] = "Temperature";
  float chargeRate;
 float temperature = temp;
 if(temperature < 0 || temperature > 45) {
    chargeRate = 0.8;
    fpPrint(StringName);
    return chargeRate;
  }
  return 0;
}

void checkChargeRate(float ChargeRate,void (*fpPrint)(char *)){
  char StringName[15] = "ChargeRate";
  float chargeRate = ChargeRate;
  if(chargeRate > 0.8) {
    fpPrint(StringName);
  }
}


int batteryIsOk(float temp,float soc, void (*fpPrint)(char *),float (*fpCheckTemp)(float , void (fpPrint)(char * )), void (fpCheckChargeRate)(float ChargeRate,void (fpPrint)(char * )) ) {
  char StringName[15] = "Soc";
 if(soc < 20 || soc > 80) {
  float temperature = temp;
  float ChargeRate = fpCheckTemp(temperature , fpPrint);
  fpCheckChargeRate(ChargeRate,fpPrint);
    fpPrint(StringName);
    return 0;
  }
  return 1; 
}


    int printCount = 0;

//stub
  char StringName[15] = "StubString";
void stubprintToConsole(char *StringName){
   printCount++;
}

float stubcheckTemp(float temp , void (*fpPrint)(char *)){
 if(temp < 0 || temp > 45) {
    fpPrint(StringName);
    return 1;
  }
  return 0;
}

void stubcheckChargeRate(float ChargeRate,void (*fpPrint)(char *)){
  if(ChargeRate > 0.8) {
    fpPrint(StringName);
  }
}

int main() {
 int result =batteryIsOk(50,85,printToConsole,checkTemp,checkChargeRate);
 printf("%d\n", result);
 result =batteryIsOk(25,85,printToConsole,checkTemp,checkChargeRate);
  printf("%d\n", result);
 // test
 assert(batteryIsOk(50,85,pstubrintToConsole,stubcheckTemp,stubcheckChargeRate));
  //assert(batteryIsOk(50,85,printToConsole,checkTemp));
//   assert(batteryIsOk(25, 70, 0.7));
//   assert(!batteryIsOk(50, 85, 0));
}
