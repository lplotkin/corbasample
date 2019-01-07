#include <hello.hh>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    try
    {
        CORBA::ORB_var orb = CORBA::ORB_init(argc, argv);

        if (argc != 3)
        {
            cerr << "usage: " << argv[0] << " IORreference stringToReverse" << endl;
            return 2;
        }
        CORBA::Object_var obj = orb->string_to_object(argv[1]);

        hello_var instance = hello::_narrow(obj);
        if (CORBA::is_nil(instance))
        {
            cerr << "Can't get instance." << endl;
            return 1;
        }

        cout << "Remote said: " << instance->sayHello(argv[2]) << endl;

        orb->destroy();
        return 0;
    }
      catch(CORBA::COMM_FAILURE& ex) {
    cerr << "Caught system exception COMM_FAILURE -- unable to contact the "
         << "object." << endl;
  }
    catch (...)
    {
        cerr << "Caught an unknown exception." << endl;
    }
}