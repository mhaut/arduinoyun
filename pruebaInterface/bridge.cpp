#include <IceE/IceE.h>
#include "Ultrasound.h"
#include <iostream>
#include <unistd.h>

using namespace std;
using namespace RoboCompUltrasound;

class UltrasoundI : public Ultrasound {
public:
   UltrasoundI(){};
   virtual ~UltrasoundI(){};

    virtual BusParams getBusParams(const Ice::Current&);
    virtual SensorParams getSensorParams(const string& sensor, const Ice::Current&);
    virtual SensorParamsList getAllSensorParams(const Ice::Current&);
    virtual string getSensorDistance(const string& sensor, const Ice::Current&);
    virtual SensorsState getAllSensorDistances(const Ice::Current&);
};

string
UltrasoundI::
getSensorDistance(const string& sensor, const Ice::Current&)
{
    string cmd = "curl -u root:arduino http://192.168.1.102/data/get/ultrasound";
    string data;
    FILE * stream;
    const int max_buffer = 256;
    char buffer[max_buffer];
    cmd.append(" 2>&1");

    stream = popen(cmd.c_str(), "r");
    if (stream) {
        while (!feof(stream))
            if (fgets(buffer, max_buffer, stream) != NULL)
                data.append(buffer);
        pclose(stream);
    }
    return data;
}


BusParams
UltrasoundI::
getBusParams(const Ice::Current&) {}


SensorParams
UltrasoundI::
getSensorParams(const string& sensor, const Ice::Current&) {}


SensorsState
UltrasoundI::
getAllSensorDistances(const Ice::Current&){} 


SensorParamsList
UltrasoundI::
getAllSensorParams(const Ice::Current&){}


int
main(int argc, char* argv[])
{
    int status = 0;
    Ice::CommunicatorPtr ic;
    try {
        ic = Ice::initialize(argc, argv);
        Ice::ObjectAdapterPtr adapter =
            ic->createObjectAdapterWithEndpoints("UltrasoundAdapter", "default -p 10000");
        Ice::ObjectPtr object = new UltrasoundI;
        adapter->add(object, ic->stringToIdentity("Ultrasound"));
        adapter->activate();
	cout << "Waiting for commands" << endl;
        ic->waitForShutdown();
    } catch (const Ice::Exception& e) {
        cerr << e << endl;
        status = 1;
    } catch (const char* msg) {
        cerr << msg << endl;
        status = 1;
    }
    if (ic) {
        try {
            ic->destroy();
        } catch (const Ice::Exception& e) {
            cerr << e << endl;
            status = 1;
        }
    }
    return status;
}
