#include "ChInterp.h"
#include "ChInterpEditor.h"

ChInterpEditor::ChInterpEditor(GenericProcessor* parentNode, bool useDefaultParameterEditors = true)
   : GenericEditor(parentNode, useDefaultParameterEditors)

{
   setDesiredWidth(250);

}

ChInterpEditor::~ChInterpEditor(){}


