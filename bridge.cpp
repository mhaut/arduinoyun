#include <IceE/IceE.h>
#include "Learnbot.h"
#include <iostream>
#include <unistd.h>

using namespace std;
using namespace LearnBotComponent;

class LearnbotI : public LearnBot {
public:
   LearnbotI(){};
   virtual ~LearnbotI(){};
   virtual string getUltraSound(const Ice::Current&);
};

string 
LearnbotI::
getUltraSound(const Ice::Current&)
{
    string cmd = "curl -u root:arduino http://192.168.0.7/data/get/ultrasound";
    string data;
    FILE * stream;
    string buffer;
    cmd.append(" 2>&1");

    if (!(stream = popen(cmd.c_str(),"r"))){
        return 1;
    }
    while(fgets(buffer, sizeof(buffer), stream) != NULL)
        data.append(buffer);
    pclose(stream);

    return data;
}

int
main(int argc, char* argv[])
{
    int status = 0;
    Ice::CommunicatorPtr ic;
    try {
        ic = Ice::initialize(argc, argv);
        Ice::ObjectAdapterPtr adapter =
            ic->createObjectAdapterWithEndpoints("LearbotAdapter", "default -p 10000");
        Ice::ObjectPtr object = new LearnbotI;
        adapter->add(object, ic->stringToIdentity("Learnbot"));
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
