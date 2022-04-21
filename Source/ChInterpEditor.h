#ifndef __CHINTERPEDITOR_H_DEFINED__
#define __CHINTERPEDITOR_H_DEFINED__

#include <EditorHeaders.h>
#include "ChInterp.h"


class ChInterpEditor : public GenericEditor, public Label::Listener
{
public:

   ChInterpEditor(GenericProcessor* parentNode, bool useDefaultParameterEditors);
   ~ChInterpEditor();
   void labelTextChanged(Label* label);

private:
   ChInterpSpace::ChInterp * processor;
   ScopedPointer<Label> ogChannel_label;
   ScopedPointer<Label> ogChannel_0;
   ScopedPointer<Label> ogChannel_1;
   ScopedPointer<Label> ogChannel_2;
   ScopedPointer<Label> ogChannel_3;
   ScopedPointer<Label> ogChannel_4;
   ScopedPointer<Label> ogChannel_5;
   ScopedPointer<Label> ogChannel_6;
   ScopedPointer<Label> ogChannel_7;

   ScopedPointer<Label> toChannel_label;
   ScopedPointer<Label> toChannel_0;
   ScopedPointer<Label> toChannel_1;
   ScopedPointer<Label> toChannel_2;
   ScopedPointer<Label> toChannel_3;
   ScopedPointer<Label> toChannel_4;
   ScopedPointer<Label> toChannel_5;
   ScopedPointer<Label> toChannel_6;
   ScopedPointer<Label> toChannel_7;
   JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ChInterpEditor);

};

#endif 
