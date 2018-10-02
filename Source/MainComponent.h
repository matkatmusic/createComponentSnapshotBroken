/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

struct MemoryHog
{
    MemoryHog()
    {
        //allocate 1GB of Ram
        auto gigabyte = 1024 * 1024 * 1024;
        for( int i = 0; i < gigabyte; ++i )
        {
            array.add( 'a' );
        }
    }
private:
    Array<char> array;
};

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent   : public Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    MidiKeyboardState state;
    MidiKeyboardComponent mkc;
    
    //MemoryHog hog;
    //==============================================================================
    // Your private member variables go here...


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
