#include "ChInterpEditor.h"
#include "ChInterp.h"

ChInterpEditor::ChInterpEditor(GenericProcessor* parentNode, bool useDefaultParameterEditors=true)
    : GenericEditor(parentNode, useDefaultParameterEditors)

{
   setDesiredWidth(250);

}

ChInterpEditor::~ChInterpEditor()
{

}

