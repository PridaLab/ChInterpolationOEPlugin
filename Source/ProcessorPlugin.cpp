#include "ChInterp.h"

using namespace ProcessorPluginSpace;

//Change all names for the relevant ones, including "Processor Name"
ChInterp::ChInterp() : GenericProcessor("Ch-interp")
{

}

ChInterp::~ChInterp()
{

}

void ChInterp::process(AudioSampleBuffer& buffer)
{
	/** 
	If the processor needs to handle events, this method must be called onyl once per process call
	If spike processing is also needing, set the argument to true
	*/
	//checkForEvents(false);
	int numChannels = getNumOutputs();

	for (int chan = 0; chan < numChannels; chan++)
	{
		int numSamples = getNumSamples(chan);
		int64 timestamp = getTimestamp(chan);

		//Do whatever processing needed
	}
	 
}

