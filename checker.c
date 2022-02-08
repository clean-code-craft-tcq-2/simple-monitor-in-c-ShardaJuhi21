#include <stdio.h>
#include <assert.h>


void printToConsole( char *StringeName){
printf("%s out of range!\n", StringeName);
}

float checkTemp(float temp , void (*fpPrint)(char *)){
 char StringeName[15] = "Temperature";
  float chargeRate=0.8;
 float temperature = temp;
 if(temperature < 0 || temperature > 45) {
    fpPrint(StringeName);
    return chargeRate;
  }
  return 1;
}

// int checkSoc(float Soc,float temp, fpTemp(temp, fprint)){
//   char StringeName[15] = "Soc";
//  if(soc < 20 || soc > 80) {
//     result = checkTemp(float , fpprint);
//     fpprint(StringeName);
//     return 0;
//   } 
//   return 1;
// }

// float checkChargeRate(float ChargeRate,float soc,void (*fpPrint)(char *)){
//   char StringeName[15] = "ChargeRate";
//   float Soc=soc;
//   float chargeRate = ChargeRate;
//   (chargeRate > 0.8) {
//     fpPrint(StringeName);
//     return 0;
//   }
//   return 1;
// }


int batteryIsOk(float temp,float soc, void (*fpPrint)(char *),float (*fpCheckTemp)(float , void (fpPrint)(char * )) ) {
  char StringeName[15] = "Soc";
 if(soc < 20 || soc > 80) {
      float temperature = temp;
  float ChargeRate = fpCheckTemp(temperature , fpPrint);
    fpPrint(StringeName);
    return 0;
  }

  return 1;
  
}



int main() {
  assert(batteryIsOk(50,70,printToConsole,checkTemp));
//   assert(batteryIsOk(25, 70, 0.7));
//   assert(!batteryIsOk(50, 85, 0));
}
