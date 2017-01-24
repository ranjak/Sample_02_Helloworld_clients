// Helloworld_client_cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	//Configure the sample to use the test server on api.stormancer.com
	auto config = Stormancer::Configuration::create("https://api.stormancer.com/", "ranjak", "helloworld-2");
	//config->addServerEndpoint("https://api.stormancer.com/");


	auto client = Stormancer::Client::createClient(config);

	auto sceneResult = client->getPublicScene("helloworld").get();

	auto scene = sceneResult->get();

	scene->connect().wait();



	auto rpcService = scene->dependencyResolver()->resolve<Stormancer::IRpcService>();

	auto response = rpcService->rpc<std::string>("hello").get();

	std::cout << response->get();
	scene->disconnect().wait();
	
	Stormancer::destroy(client);

}

