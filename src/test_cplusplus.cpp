#include <iostream>
#include <stdio.h>
using namespace std;

typedef enum {UNKNOW,INITING,INITED,RESUMING,RESUMED,PAUSING,PAUSED,EXITING,EXITED,INVALID} _status;
class BaseApp
{
protected:
	_status status;
	int owner;	
public:
	BaseApp():status(UNKNOW),owner(2){printf("BaseApp construct, status %d , owner %d\n",status,owner );}
	virtual ~BaseApp(){printf("BaseApp destructed\n");};
	virtual void init(){ printf("BaseApp inited\n"); setStatus(INITED);}
	virtual void resume(){}
	virtual void pause(){}
	virtual void exit(){}
public:
	int setStatus(_status status){ this->status = status ; printf("set status %d\n",status); return 0;}
	_status getStatus(){ return status; }

};

class Playback : public BaseApp
{
public:
	Playback():playback_volum(50)
	          ,playback_type(1)
	          ,status(PAUSING)
	{
		cout << "playback app construct" << endl;
	}
	virtual ~Playback()
	{
		cout << "playback app destructed" << endl;
	}
	virtual void init(){ cout << "playback init" << endl;}
	void show()
	{
		cout << "playback_volum : " << playback_volum << " playback_type : " << playback_type << endl;
	}
    _status getStatus(){ return status; }
private:
	int playback_volum;
	int playback_type;
	_status status;

};
int main(int argc, char const *argv[])
{
	cout << "this is a test" << endl;
	BaseApp base_app;
	base_app.init();
	cout << "status is : " << base_app.getStatus() << endl;
	base_app.setStatus(PAUSED);
	cout << "status is : " << base_app.getStatus() << endl;

	Playback playback;
	playback.init();
	BaseApp& base_app_temp = playback;
	cout << "status is : " << playback.getStatus() << endl;
	cout << "status is : " << base_app_temp.getStatus() << endl;
	playback.setStatus(PAUSED);
	cout << "status is : " << playback.getStatus() << endl;
	playback.show();
	return 0;
}
