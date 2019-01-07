#include <hello.hh>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class hello_I : public POA_hello, public PortableServer::RefCountServantBase {
	public:
		hello_I() {}
		virtual ~hello_I() {}
		virtual char *sayHello(const char * const msg);
};

char * hello_I::sayHello(const char * const msg) {
	std::string retval(msg);
	std::reverse(retval.begin(), retval.end());
	return CORBA::string_dup(retval.c_str());
}

int main(int argc, char *argv[]) {
    try {
        CORBA::ORB_var orb = CORBA::ORB_init(argc, argv);

        CORBA::Object_var obj = orb->resolve_initial_references("RootPOA");
        PortableServer::POA_var poa = PortableServer::POA::_narrow(obj);

        hello_I* instance = new hello_I();
      
        PortableServer::ObjectId_var id = poa->activate_object(instance);

        obj = instance->_this();
        CORBA::String_var sior(orb->object_to_string(obj));
        cerr << "'" << (char*)sior << "'" << endl;

        instance->_remove_ref();

        PortableServer::POAManager_var pman = poa->the_POAManager();
        pman->activate();

        orb->run();
  } catch(...) {
    cerr << "Caught unknown exception." << endl;
  }

  return 0;
}