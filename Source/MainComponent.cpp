/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent() : mkc(state, MidiKeyboardComponent::Orientation::horizontalKeyboard)
{
    addAndMakeVisible(mkc);
    
    auto bounds = Desktop::getInstance().getDisplays().getMainDisplay().userArea;
    setSize(bounds.getWidth(), bounds.getHeight());
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setFont (Font (16.0f));
    g.setColour (Colours::white);
    g.drawText ("Hello World!", getLocalBounds(), Justification::centred, true);
    
    auto image = mkc.createComponentSnapshot(mkc.getLocalBounds());
    
    g.drawImageWithin(image, 0, getHeight() * 0.3f, getWidth(), 100, RectanglePlacement::stretchToFit);
    
    g.setColour(Colours::red);
    g.drawRect(0, int(getHeight() * 0.3f), getWidth(), 100);
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    mkc.setBounds(0, getHeight() - 100, getWidth(), 100);
}
