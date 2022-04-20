#ifndef __CHINTERPEDITOR_H_DEFINED__
#define __CHINTERPEDITOR_H_DEFINED__

#include <EditorHeaders.h>
#include "ChInterp.h"


class ChInterpEditor : public GenericEditor //, public Label::Listener
{
public:

   ChInterpEditor(GenericProcessor* parentNode, bool useDefaultParameterEditors);
   ~ChInterpEditor();


private:
   ChInterpSpace::ChInterp * processor;

   JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ChInterpEditor);

};

#endif 
