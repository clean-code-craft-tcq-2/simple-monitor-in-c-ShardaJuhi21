#include <stdio.h>
#include <assert.h>


void printToConsole( char *StringeName){
printf("%s out of range!\n", StringeName);
}

float checkTemp(float temp , void (*fpPrint)(char *)){
 char StringeName[15] = "Temperature";
  float chargeRate;
 float temperature = temp;
 if(temperature < 0 || temperature > 45) {
    chargeRate = 0.8;
    fpPrint(StringeName);
    return chargeRate;
  }
  return 1;
}

void checkChargeRate(float ChargeRate,void (*fpPrint)(char *)){
  char StringeName[15] = "ChargeRate";
  float chargeRate = ChargeRate;
  if(chargeRate > 0.8) {
    fpPrint(StringeName);
  }
}


int batteryIsOk(float temp,float soc, void (*fpPrint)(char *),float (*fpCheckTemp)(float , void (fpPrint)(char * )), void (fpCheckChargeRate)(float ChargeRate,void (fpPrint)(char * )) ) {
  char StringeName[15] = "Soc";
 if(soc < 20 || soc > 80) {
  float temperature = temp;
  float ChargeRate = fpCheckTemp(temperature , fpPrint);
  fpCheckChargeRate(ChargeRate,fpPrint);
    fpPrint(StringeName);
    return 0;
  }

  return 1;
  
}



int main() {
 int result =batteryIsOk(50,85,printToConsole,checkTemp,checkChargeRate);
 printf("%d", result);
 result =batteryIsOk(25,85,printToConsole,checkTemp,checkChargeRate);
  printf("%d", result);
  //assert(batteryIsOk(50,85,printToConsole,checkTemp));
//   assert(batteryIsOk(25, 70, 0.7));
//   assert(!batteryIsOk(50, 85, 0));
}
