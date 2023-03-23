#include <iostream>

using namespace std;

class IKeyBoard{
    virtual void onKeyDown(int keycode) = 0;
    virtual void onKeyPress(int keycode) = 0;
    virtual void onKeyRelease(int keycode) = 0;
};

class EditBox : public IKeyBoard{
    void onKeyDown(int keycode){
        
    }
    void onKeyPress(int keycode){
        
    }
    void onKeyRelease(int keycode){
        
    }
};

class Button{
    void onKeyDown(int keycode){
        
    }
    void onKeyPress(int keycode){
        
    }
    void onKeyRelease(int keycode){
        
    }
};

int main(){
    EditBox edit;
    Button button;


    return 0;
}