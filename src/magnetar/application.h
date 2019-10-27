#pragma once

namespace Magnetar
{

	// To be sub-classed by client
	class Application
	{
	public:
		Application(int argc, char **argv);
		virtual ~Application();

		// To be overrided by client
		virtual int run();
	};

	// To be implemented by client
	Application *createApplication(int argc, char **argv);

}
