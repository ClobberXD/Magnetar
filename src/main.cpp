#include "magnetar.h"

// TODO: This should really be done client-side at a later stage. But
// this should do for now, as we don't yet have the concept of a client
class MyApp : public Magnetar::Application
{
public:
	MyApp(int argc, char **argv)
		: Application(argc, argv)
	{
		LOG_TRACE("\tMyApp::MyApp");
	}

	~MyApp()
	{
		LOG_TRACE("\tMyApp::~MyApp");
	}

	int run() override
	{
		LOG_INFO("MyApp::run");

		return 0;
	}
};

Magnetar::Application *Magnetar::createApplication(int argc, char **argv)
{
	return new MyApp(argc, argv);
}
