#include <systemc.h>
#include "design.cpp"

//--------------------------------------------------
// Testbench
//--------------------------------------------------

int sc_main(int argc, char* argv[])
{
    sc_signal<float> temperature;
    sc_signal<bool> fan;
    sc_signal<bool> alarm;

    LubricantController controller("Controller");

    controller.temperature(temperature);
    controller.fan(fan);
    controller.alarm(alarm);

    cout << "----------------------------------------" << endl;
    cout << "Lubricant Monitoring System Simulation" << endl;
    cout << "----------------------------------------" << endl;

    temperature = 55;
    sc_start(1, SC_SEC);

    cout << "Time = " << sc_time_stamp()
         << "  Temp = " << temperature.read()
         << " C  Fan = " << fan.read()
         << "  Alarm = " << alarm.read() << endl;

    temperature = 62;
    sc_start(1, SC_SEC);

    cout << "Time = " << sc_time_stamp()
         << "  Temp = " << temperature.read()
         << " C  Fan = " << fan.read()
         << "  Alarm = " << alarm.read() << endl;

    temperature = 68;
    sc_start(1, SC_SEC);

    cout << "Time = " << sc_time_stamp()
         << "  Temp = " << temperature.read()
         << " C  Fan = " << fan.read()
         << "  Alarm = " << alarm.read() << endl;

    temperature = 72;
    sc_start(1, SC_SEC);

    cout << "Time = " << sc_time_stamp()
         << "  Temp = " << temperature.read()
         << " C  Fan = " << fan.read()
         << "  Alarm = " << alarm.read() << endl;

    temperature = 60;
    sc_start(1, SC_SEC);

    cout << "Time = " << sc_time_stamp()
         << "  Temp = " << temperature.read()
         << " C  Fan = " << fan.read()
         << "  Alarm = " << alarm.read() << endl;

    cout << "----------------------------------------" << endl;
    cout << "Simulation Completed" << endl;

    return 0;
}