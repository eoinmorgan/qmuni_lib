#include <Poco/URI.h>
#include <string>
using namespace std;
using namespace Poco;
namespace BNet
{
	class HTTP
	{
    	public:
		
		
		string net_post( URI uri, string data);
        	string net_put(URI uri, string data);
			string net_get(URI uri);
			string net_delete(URI uri);
		private:

    
    
	};
}

