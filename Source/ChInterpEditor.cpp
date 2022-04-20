#include "ChInterpEditor.h"
#include "ChInterp.h"

ChInterpEditor::ChInterpEditor(GenericProcessor* parentNode, bool useDefaultParameterEditors=true)
    : GenericEditor(parentNode, useDefaultParameterEditors)

{
   setDesiredWidth(250);

   ogChannel_label = new Label("Source Channel Label", "Source Channels:");
   ogChannel_label->setBounds(5,25,200,20);
   ogChannel_label->setFont(Font("Small Text", 12, Font::plain));
   ogChannel_label->setColour(Label::textColourId, Colours::white);
   addAndMakeVisible(ogChannel_label);

   ogChannel_0 = new Label("Og Channel 0", "0");
   ogChannel_0->setBounds(10,45,20,15);
   ogChannel_0->setFont(Font("Default", 8, Font::plain));
   ogChannel_0->setColour(Label::textColourId, Colours::white);
   ogChannel_0->setColour(Label::backgroundColourId, Colours::orange);
   ogChannel_0->setEditable(true);
   ogChannel_0->addListener(this);
   ogChannel_0->setTooltip("Set the source channel 0 for interpolation");
   addAndMakeVisible(ogChannel_0);

   ogChannel_1 = new Label("Og Channel 0", "-1");
   ogChannel_1->setBounds(32,45,20,15);
   ogChannel_1->setFont(Font("Default", 8, Font::plain));
   ogChannel_1->setColour(Label::textColourId, Colours::black);
   ogChannel_1->setColour(Label::backgroundColourId, Colours::grey);
   ogChannel_1->setEditable(true);
   ogChannel_1->addListener(this);
   ogChannel_1->setTooltip("Set the source channel 1 for interpolation");
   addAndMakeVisible(ogChannel_1);

}

void ChInterpEditor::labelTextChanged(Label* label)
{
   Value val = label->getTextValue();
   double requestedValue = double(val.getValue());

   if (requestedValue>-1)
   {
      label->setColour(Label::textColourId, Colours::white);
      label->setColour(Label::backgroundColourId, Colours::orange);
   }
   else
   {
      label->setColour(Label::textColourId, Colours::black);
      label->setColour(Label::backgroundColourId, Colours::grey);
   }
   if (label == ogChannel_0)
   {
      //do something
   }

}


ChInterpEditor::~ChInterpEditor(){}

