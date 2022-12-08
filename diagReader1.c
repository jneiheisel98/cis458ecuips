#include <stdio.h>

#include <string.h>



#define MAX_LEN 256



int main(void)

{
    int carIsOn = 0;
    int oilLightOn = 0;
    int absLightOn = 0;
    int parkBrakeLightOn = 0;
    int checkEngineLightOn = 0;
    int oilIsLow = 0;
    int absIsBroke = 0;
    int parkBrakEngaged = 0;
    int turnCheckEngineLightOn = 0;
    int turnOilLightOn = 0;
    int turnAbsLightOn = 0;
    int oilLevelLow = 0;
    int carSpeed = 0;
    int rpm = 0;
    int absOn = 0;
    int brakesApplied = 0;
    int engineFault = 0;
    int absFault = 0;
    int parkingBrakeApplied = 0;
    int time = 0;
    FILE* fp;

    fp = fopen("test01.csv", "r");

    if (fp == NULL) {

      perror("Failed: ");

      return 1;

    }



    char buffer[MAX_LEN];
    int count = 0;
    while (fgets(buffer, MAX_LEN, fp))

    {
        int tempSpeed = carSpeed;
             int tempRPM = rpm;
             int tempEngineFault = engineFault;
             int tempAbsFault = absFault;
             int parkBrakeTemp = parkBrakEngaged;
             int oilLightOnTemp = oilLightOn;
             int absLightOnTemp = absLightOn;
             int tempParkBrakeLightOn = parkBrakeLightOn;
             int tempCheckEngineLightOn = checkEngineLightOn;
             int tempABSOn = absLightOn;
             int tempBrakesApplied = brakesApplied;
           int tempTime = time;

        // Remove trailing newline

        buffer[strcspn(buffer, "\n")] = 0;
         char *pt;
    printf("start: %s\n", buffer);
    pt = strtok (buffer,",");
   
    int counter = 0;
   
    while (pt != NULL) {

        int a = atoi(pt);
        if(count == 0){
            if(counter ==0){
                carIsOn = a;
                counter+=1;
            }
            else if(counter == 1){
                oilLightOn = a;
                counter+=1;
            }
            else if(counter == 2){
                absLightOn = a;
                counter+=1;
            }
            else if (counter == 3){
                parkBrakeLightOn = a;
                counter+=1;
            }
            else if (counter == 4){
                checkEngineLightOn = a;
                counter+=1;
            }
            else if (counter == 5){
                oilIsLow = a;
                counter+=1;
            }
            else if (counter == 6){
                absIsBroke = a;
                counter+=1;
            }
            else if (counter == 7){
                parkBrakEngaged = a;
                counter+=1;
            }
            else if (counter == 8){
                turnCheckEngineLightOn = a;
                counter+=1;
            }
            else if (counter == 9){
                oilLevelLow = a;
                counter+=1;
            }
            else if (counter == 10){
                carSpeed = a;
                counter+=1;
            }
            else if (counter == 11){
                rpm = a;
                counter+=1;
            }
            else if(counter == 12){
                absOn = a;
                counter+=1;
            }
            else if (counter == 13){
                brakesApplied = a;
                counter+=1;
            }
            
        }
        else {

            if(counter == 0){
           turnOilLightOn = a;
           counter+=1;
            }
            else if(counter == 1){
                turnAbsLightOn = a;
                counter+=1;
            }
            else if(counter == 2){
                parkBrakeLightOn = a;
                counter+=1;
            }
            else if(counter == 3){
                turnCheckEngineLightOn = a;
                counter+=1;
                }
            else if(counter == 4){
                carSpeed = a;
                counter+=1;
            }
            else if(counter == 5){
                rpm = a;
                counter+=1;
            }
            else if(counter == 6){
                absOn = a;
                counter+=1;
            }
            else if(counter == 7){

                brakesApplied = a;
                 counter+=1;
            }
            else if(counter == 8){
                time = a;
                
                 counter+=1;
            }
            else if(counter == 9){
                engineFault = a;
                counter+=1;
            }
            else if(counter == 10){
                absFault = a;
		counter+=1;
            }
            else if(counter == 11){
            
            parkBrakEngaged = a;
            }
            
            count+=1;
            }
        pt = strtok (NULL, ",");
    }
    
    


    count +=1;
    int error = 80;
    printf("start error check\n");

    if((turnAbsLightOn && absFault < 1)){
        error  = 1;
        turnAbsLightOn = absLightOnTemp;
    }
    if (turnCheckEngineLightOn && engineFault < 1){
    error = 2;
    checkEngineLightOn = turnCheckEngineLightOn;
    } 
    if(!parkBrakEngaged && parkBrakeLightOn){
        error = 3;
        parkBrakeLightOn = tempParkBrakeLightOn;
    } 
    if (turnOilLightOn && !oilLevelLow){
        error = 4;
        turnOilLightOn = oilLightOnTemp;
    }
    
     if (tempTime != 0 && time != 0) {
     
     
     if ((carSpeed - tempSpeed < -10 || carSpeed - tempSpeed > 10) && (time - tempTime < 200)){
     error = 7;
        carSpeed = tempSpeed; 
     }  
        }
    if ((tempTime !=0 && time != 0) && (carSpeed !=0 && time !=0) && absFault == tempAbsFault && tempSpeed == carSpeed && tempRPM == rpm && tempABSOn == absOn && tempEngineFault == engineFault && parkBrakeTemp == parkBrakEngaged && (((time - tempTime) < 100)) && parkingBrakeApplied == parkBrakeTemp && oilLightOnTemp == turnOilLightOn && absLightOnTemp == turnAbsLightOn && checkEngineLightOn == tempCheckEngineLightOn && tempBrakesApplied == brakesApplied){
        error = 6;
        brakesApplied = tempBrakesApplied;
        absOn = tempABSOn;
        carSpeed = tempSpeed;
                turnOilLightOn = oilLightOnTemp;
                absOn = tempABSOn;
                turnAbsLightOn = absLightOnTemp;
                parkBrakeLightOn = tempParkBrakeLightOn;
                checkEngineLightOn = turnCheckEngineLightOn;
                brakesApplied = tempBrakesApplied;
                time = tempTime;
                oilLightOn = oilLightOnTemp;
                rpm = tempRPM;
    } 
   
            if ((tempTime != 0 && time != 0) && ((tempTime-time > 0) || (time-tempTime > 0)) && (((carSpeed - tempSpeed)/(time - tempTime) <= -0.29) || ((carSpeed - tempSpeed)/(time - tempTime) >= 0.29))){
            error = 8;
               carSpeed = tempSpeed;
            }
            
            if ((tempTime != 0 && time != 0) && ((tempTime-time > 0) || (time-tempTime > 0))&& ((rpm-tempRPM)/(time - tempTime) > 12.14)){
            error = 9;
            rpm = tempRPM;
            } 
            
            if ((tempTime != 0 && time != 0) && ((tempTime-time > 0) || (time-tempTime > 0)) && (((rpm-tempRPM)/(time-tempTime) < -12.14) || ((rpm-tempRPM)/(time-tempTime) > 12.14))){
                error = 10;
                rpm = tempRPM;
            }
            
            printf("error %d, 80 is default\n", error);
        if(absIsBroke) {
            turnAbsLightOn = 1;
        }
        if(turnAbsLightOn == 1){
            absLightOn = 1;
        }
        if(turnOilLightOn == 1){
            oilLightOn = 1;
        }
        if(turnCheckEngineLightOn == 1){
            checkEngineLightOn = 1;
        }
        printf("carIsOn %d, oilLightOn %d, absLightOn %d, parkBrakeLightOn %d, checkEngineLightOn %d, oilIsLow %d, absIsBroke %d, parkBrakEngaged %d, turnCheckEngineLightOn %d, turnOilLightOn %d, turnAbsLightOn %d, oilLevelLow %d, carSpeed %d, rpm %d, absOn %d, brakesApplied %d, engineFault %d, absFault %d, parkingBrakeApplied %d, time %d\n", carIsOn, oilLightOn, absLightOn, parkBrakeLightOn, checkEngineLightOn, oilIsLow,  absIsBroke, parkBrakEngaged, turnCheckEngineLightOn, turnOilLightOn, turnAbsLightOn,  oilLevelLow, carSpeed, rpm, absOn, brakesApplied, engineFault, absFault, parkingBrakeApplied, time);


    }



    fclose(fp);

    return 0;

}
#include <stdio.h>
