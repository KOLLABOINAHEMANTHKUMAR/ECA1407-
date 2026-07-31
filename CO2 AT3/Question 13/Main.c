#include <stdio.h>
#include "pid_controller.h"

int main()
{
    float temperature;
    float setTemperature = 60.0;
    float fanSpeed;

    printf("=====================================\n");
    printf(" Lubricant Temperature Controller\n");
    printf("=====================================\n");

    while(1)
    {
        printf("\nEnter Lubricant Temperature : ");
        scanf("%f",&temperature);

        fanSpeed = calculatePID(setTemperature, temperature);

        printf("\nCurrent Temperature : %.2f C\n",temperature);
        printf("Desired Temperature : %.2f C\n",setTemperature);

        printf("Cooling Fan Speed : %.2f %%\n",fanSpeed);

        if(temperature > 65)
            printf("Status : HIGH TEMPERATURE\n");
        else
            printf("Status : NORMAL\n");
    }

    return 0;
}