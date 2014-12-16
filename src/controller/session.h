#include <Poco/URI.h>
#include <string>
#include <vector>
#include <iostream>

namespace app {
	class session {
	private:
		string token;
		URI uri;
	public:
		session();
		session(URI uri)
		
		int login();
		
		URI getUri();
		int setUri(URI uri);

		
		
	};
}