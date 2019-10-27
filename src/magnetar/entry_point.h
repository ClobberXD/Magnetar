#pragma once

extern Magnetar::Application *Magnetar::createApplication(int argc, char **argv);

int main(int argc, char **argv)
{
	auto app = Magnetar::createApplication(argc, argv);
	int ret = app->run();

	delete app;
	return ret;
}
