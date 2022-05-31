#include "ChInterpEditor.h"
#include "ChInterp.h"

ChInterpEditor::ChInterpEditor(GenericProcessor* parentNode, bool useDefaultParameterEditors=true)
    : GenericEditor(parentNode, useDefaultParameterEditors)

{
   setDesiredWidth(200);

   ogChannel_label = new Label("Source Channel Label", "Source Channels:");
   ogChannel_label->setBounds(5,25,200,20);
   ogChannel_label->setFont(Font("Small Text", 12, Font::plain));
   ogChannel_label->setColour(Label::textColourId, Colours::white);
   addAndMakeVisible(ogChannel_label);

   ogChannel_0 = new Label("Og Channel 1", "1");
   ogChannel_0->setBounds(10,45,20,15);
   ogChannel_0->setFont(Font("Default", 8, Font::plain));
   ogChannel_0->setColour(Label::textColourId, Colours::white);
   ogChannel_0->setColour(Label::backgroundColourId, Colours::orange);
   ogChannel_0->setEditable(true);
   ogChannel_0->addListener(this);
   ogChannel_0->setTooltip("Set the source channel 1 for interpolation");
   addAndMakeVisible(ogChannel_0);

   ogChannel_1 = new Label("Og Channel 2", "-1");
   ogChannel_1->setBounds(32,45,20,15);
   ogChannel_1->setFont(Font("Default", 8, Font::plain));
   ogChannel_1->setColour(Label::textColourId, Colours::black);
   ogChannel_1->setColour(Label::backgroundColourId, Colours::grey);
   ogChannel_1->setEditable(true);
   ogChannel_1->addListener(this);
   ogChannel_1->setTooltip("Set the source channel 2 for interpolation");
   addAndMakeVisible(ogChannel_1);

   ogChannel_2 = new Label("Og Channel 3", "-1");
   ogChannel_2->setBounds(54,45,20,15);
   ogChannel_2->setFont(Font("Default", 8, Font::plain));
   ogChannel_2->setColour(Label::textColourId, Colours::black);
   ogChannel_2->setColour(Label::backgroundColourId, Colours::grey);
   ogChannel_2->setEditable(true);
   ogChannel_2->addListener(this);
   ogChannel_2->setTooltip("Set the source channel 3 for interpolation");
   addAndMakeVisible(ogChannel_2);

   ogChannel_3 = new Label("Og Channel 4", "4");
   ogChannel_3->setBounds(76,45,20,15);
   ogChannel_3->setFont(Font("Default", 8, Font::plain));
   ogChannel_3->setColour(Label::textColourId, Colours::white);
   ogChannel_3->setColour(Label::backgroundColourId, Colours::orange);
   ogChannel_3->setEditable(true);
   ogChannel_3->addListener(this);
   ogChannel_3->setTooltip("Set the source channel 4 for interpolation");
   addAndMakeVisible(ogChannel_3);

   ogChannel_4 = new Label("Og Channel 5", "-1");
   ogChannel_4->setBounds(98,45,20,15);
   ogChannel_4->setFont(Font("Default", 8, Font::plain));
   ogChannel_4->setColour(Label::textColourId, Colours::black);
   ogChannel_4->setColour(Label::backgroundColourId, Colours::grey);
   ogChannel_4->setEditable(true);
   ogChannel_4->addListener(this);
   ogChannel_4->setTooltip("Set the source channel 5 for interpolation");
   addAndMakeVisible(ogChannel_4);

   ogChannel_5 = new Label("Og Channel 6", "-1");
   ogChannel_5->setBounds(120,45,20,15);
   ogChannel_5->setFont(Font("Default", 8, Font::plain));
   ogChannel_5->setColour(Label::textColourId, Colours::black);
   ogChannel_5->setColour(Label::backgroundColourId, Colours::grey);
   ogChannel_5->setEditable(true);
   ogChannel_5->addListener(this);
   ogChannel_5->setTooltip("Set the source channel 6 for interpolation");
   addAndMakeVisible(ogChannel_5);

   ogChannel_6 = new Label("Og Channel 7", "-1");
   ogChannel_6->setBounds(142,45,20,15);
   ogChannel_6->setFont(Font("Default", 8, Font::plain));
   ogChannel_6->setColour(Label::textColourId, Colours::black);
   ogChannel_6->setColour(Label::backgroundColourId, Colours::grey);
   ogChannel_6->setEditable(true);
   ogChannel_6->addListener(this);
   ogChannel_6->setTooltip("Set the source channel 7 for interpolation");
   addAndMakeVisible(ogChannel_6);

   ogChannel_7 = new Label("Og Channel 8", "8");
   ogChannel_7->setBounds(164,45,20,15);
   ogChannel_7->setFont(Font("Default", 8, Font::plain));
   ogChannel_7->setColour(Label::textColourId, Colours::white);
   ogChannel_7->setColour(Label::backgroundColourId, Colours::orange);
   ogChannel_7->setEditable(true);
   ogChannel_7->addListener(this);
   ogChannel_7->setTooltip("Set the source channel 8 for interpolation");
   addAndMakeVisible(ogChannel_7);


   toChannel_label = new Label("Recipient Channel Label", "Recipient Channels:");
   toChannel_label->setBounds(5,80,200,20);
   toChannel_label->setFont(Font("Small Text", 12, Font::plain));
   toChannel_label->setColour(Label::textColourId, Colours::white);
   addAndMakeVisible(toChannel_label);

   toChannel_0 = new Label("To Channel 1", "1");
   toChannel_0->setBounds(10,100,20,15);
   toChannel_0->setFont(Font("Default", 8, Font::plain));
   toChannel_0->setColour(Label::textColourId, Colours::white);
   toChannel_0->setColour(Label::backgroundColourId, Colours::orange);
   toChannel_0->setEditable(true);
   toChannel_0->addListener(this);
   toChannel_0->setTooltip("Set the recipient channel 1 for interpolation");
   addAndMakeVisible(toChannel_0);

   toChannel_1 = new Label("To Channel 2", "2");
   toChannel_1->setBounds(32,100,20,15);
   toChannel_1->setFont(Font("Default", 8, Font::plain));
   toChannel_1->setColour(Label::textColourId, Colours::white);
   toChannel_1->setColour(Label::backgroundColourId, Colours::orange);
   toChannel_1->setEditable(true);
   toChannel_1->addListener(this);
   toChannel_1->setTooltip("Set the recipient channel 2 for interpolation");
   addAndMakeVisible(toChannel_1);

   toChannel_2 = new Label("To Channel 3", "3");
   toChannel_2->setBounds(54,100,20,15);
   toChannel_2->setFont(Font("Default", 8, Font::plain));
   toChannel_2->setColour(Label::textColourId, Colours::white);
   toChannel_2->setColour(Label::backgroundColourId, Colours::orange);
   toChannel_2->setEditable(true);
   toChannel_2->addListener(this);
   toChannel_2->setTooltip("Set the recipient channel 3 for interpolation");
   addAndMakeVisible(toChannel_2);

   toChannel_3 = new Label("To Channel 4", "4");
   toChannel_3->setBounds(76,100,20,15);
   toChannel_3->setFont(Font("Default", 8, Font::plain));
   toChannel_3->setColour(Label::textColourId, Colours::white);
   toChannel_3->setColour(Label::backgroundColourId, Colours::orange);
   toChannel_3->setEditable(true);
   toChannel_3->addListener(this);
   toChannel_3->setTooltip("Set the recipient channel 4 for interpolation");
   addAndMakeVisible(toChannel_3);

   toChannel_4 = new Label("To Channel 5", "5");
   toChannel_4->setBounds(98,100,20,15);
   toChannel_4->setFont(Font("Default", 8, Font::plain));
   toChannel_4->setColour(Label::textColourId, Colours::white);
   toChannel_4->setColour(Label::backgroundColourId, Colours::orange);
   toChannel_4->setEditable(true);
   toChannel_4->addListener(this);
   toChannel_4->setTooltip("Set the recipient channel 5 for interpolation");
   addAndMakeVisible(toChannel_4);

   toChannel_5 = new Label("To Channel 6", "6");
   toChannel_5->setBounds(120,100,20,15);
   toChannel_5->setFont(Font("Default", 8, Font::plain));
   toChannel_5->setColour(Label::textColourId, Colours::white);
   toChannel_5->setColour(Label::backgroundColourId, Colours::orange);
   toChannel_5->setEditable(true);
   toChannel_5->addListener(this);
   toChannel_5->setTooltip("Set the recipient channel 6 for interpolation");
   addAndMakeVisible(toChannel_5);

   toChannel_6 = new Label("To Channel 7", "7");
   toChannel_6->setBounds(142,100,20,15);
   toChannel_6->setFont(Font("Default", 8, Font::plain));
   toChannel_6->setColour(Label::textColourId, Colours::white);
   toChannel_6->setColour(Label::backgroundColourId, Colours::orange);
   toChannel_6->setEditable(true);
   toChannel_6->addListener(this);
   toChannel_6->setTooltip("Set the recipient channel 7 for interpolation");
   addAndMakeVisible(toChannel_6);

   toChannel_7 = new Label("To Channel 8", "8");
   toChannel_7->setBounds(164,100,20,15);
   toChannel_7->setFont(Font("Default", 8, Font::plain));
   toChannel_7->setColour(Label::textColourId, Colours::white);
   toChannel_7->setColour(Label::backgroundColourId, Colours::orange);
   toChannel_7->setEditable(true);
   toChannel_7->addListener(this);
   toChannel_7->setTooltip("Set the recipient channel 8 for interpolation");
   addAndMakeVisible(toChannel_7);

}

void ChInterpEditor::labelTextChanged(Label* label)
{
   Value val = label->getTextValue();
   float requestedValue = float(val.getValue());

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

   //if change ogChannel
   if (label == ogChannel_0)
   {
      if (requestedValue<=0)
      {
         CoreServices::sendStatusMessage("Left most channel must be provided.");
         return;
      }
      getProcessor()->setParameter(0, requestedValue);
   }
   if (label == ogChannel_1)
   {
      getProcessor()->setParameter(1, requestedValue);
   }
   else if (label == ogChannel_2)
   {
      getProcessor()->setParameter(2, requestedValue);
   }
   else if (label == ogChannel_3)
   {
      getProcessor()->setParameter(3, requestedValue);
   }
   else if (label == ogChannel_4)
   {
      getProcessor()->setParameter(4, requestedValue);
   }
   else if (label == ogChannel_5)
   {
      getProcessor()->setParameter(5, requestedValue);
   }
   else if (label == ogChannel_6)
   {
      getProcessor()->setParameter(6, requestedValue);
   }
   else if (label == ogChannel_7)
   {      
      if (requestedValue<=0)
      {
         CoreServices::sendStatusMessage("Right most channel must be provided.");
         return;
      }
      getProcessor()->setParameter(7, requestedValue);
   }
   else
   {  
      Array<int> chans = getActiveChannels();
      if (requestedValue<=0)
      {
         CoreServices::sendStatusMessage("Recipient channel must be a valid number.");
         return;
      }
      //if change toChannel
      if (label == toChannel_0)
      {
         getProcessor()->setParameter(10, requestedValue);
      }
      if (label == toChannel_1)
      {
         getProcessor()->setParameter(11, requestedValue);
      }
      if (label == toChannel_2)
      {
         getProcessor()->setParameter(12, requestedValue);
      }
      if (label == toChannel_3)
      {
         getProcessor()->setParameter(13, requestedValue);
      }
      if (label == toChannel_4)
      {
         getProcessor()->setParameter(14, requestedValue);
      }
      if (label == toChannel_5)
      {
         getProcessor()->setParameter(15, requestedValue);
      }
      if (label == toChannel_6)
      {
         getProcessor()->setParameter(16, requestedValue);
      }
      if (label == toChannel_7)
      {
         getProcessor()->setParameter(17, requestedValue);
      }
   }
   

}

ChInterpEditor::~ChInterpEditor(){}

