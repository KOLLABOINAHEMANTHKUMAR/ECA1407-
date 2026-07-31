#include <systemc.h>

//--------------------------------------------------
// Lubricant Controller Module
//--------------------------------------------------

SC_MODULE(LubricantController)
{
    sc_in<float> temperature;
    sc_out<bool> fan;
    sc_out<bool> alarm;

    void control()
    {
        while(true)
        {
            float temp = temperature.read();

            if(temp > 65.0)
            {
                fan.write(true);
                alarm.write(true);
            }
            else
            {
                fan.write(false);
                alarm.write(false);
            }

            wait(1, SC_SEC);
        }
    }

    SC_CTOR(LubricantController)
    {
        SC_THREAD(control);
    }
};