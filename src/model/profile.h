namespace Col{
	class Profile{
	private:
		string userName;
		string emailAddress;
		Vector<conversation> conversations;
		Vector<contact> contacts;
		BOOL loggedIn;
	public:
		Profile();
		Profile(string userName, string emailAddress);
		
	};
}