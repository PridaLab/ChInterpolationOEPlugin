#include "ChInterp.h"
#include "ChInterpEditor.h"
using namespace ChInterpSpace;

//Change all names for the relevant ones, including "Processor Name"
ChInterp::ChInterp() : GenericProcessor("Ch-interp")
{
	int og_channelArray[8] = {0,-1,-1,3,-1,-1,-1,7};
	int to_channelArray[8] = {10,1,2,3,4,5,12,7};

}

ChInterp::~ChInterp()
{
}

void ChInterp::process(AudioSampleBuffer& buffer)
{
	/*
	If the processor needs to handle events, this method must be called onyl once per process call
	If spike processing is also needing, set the argument to true
	*/
	int og_channelArray[8] = {0,-1,-1,3,-1,-1,-1, 7};
	int to_channelArray[8] = {7, 1, 2,3, 4, 5, 9,12};
    const int nChannels = buffer.getNumChannels();

	//scale channels 
	for (int ch = 0; ch < 8 ; ++ch)
	{
		if (og_channelArray[ch]>-1)
		{
			const int nSamples = buffer.getNumSamples();
			float* bufPtr = buffer.getWritePointer (ch);
			for (int n = 0; n < nSamples; ++n)
			{
				*(bufPtr + n) = ch*(*(bufPtr +n));
			}
		}
	}

	//set -1 channels to 0 manually	
	for (int ch = 0; ch < 8 ; ++ch)
	{	
		if (og_channelArray[ch]==-1)
		{
			const int nSamples = buffer.getNumSamples();
			float* bufPtr = buffer.getWritePointer (ch);
			for (int n = 0; n < nSamples; ++n)
			{
				*(bufPtr + n) = 0*(*(bufPtr +n));
			}
		}

	}
	
	//Create copy of buffer first
    channelBuffer = buffer;
    
    //relocate provided channels on new positions [0-7]
    for (int ch = 0; ch< 8; ++ch)
    {
    	if (og_channelArray[ch]> -1)
    	{
			const int nSamples = buffer.getNumSamples();
			float* destPtr = buffer.getWritePointer (to_channelArray[ch]);
			float* ogPtr = channelBuffer.getWritePointer (og_channelArray[ch]);
			for (int n = 0; n < nSamples; ++n)
				{
					*(destPtr + n) = *(ogPtr +n);
				}

    	}
    	else
    	{
			const int nSamples = buffer.getNumSamples();
			float* destPtr = buffer.getWritePointer (to_channelArray[ch]);

			int left_chIdx = leftIndex(og_channelArray, ch);
			float* left_ogPtr = channelBuffer.getWritePointer (og_channelArray[left_chIdx]);

			int right_chIdx = rightIndex(og_channelArray, ch);
			float* right_ogPtr = channelBuffer.getWritePointer (og_channelArray[right_chIdx]);

			float dist_ch = right_chIdx - left_chIdx;
			for (int n = 0; n < nSamples; ++n)
			{
				//*(destPtr + n) = (*(left_ogPtr +n)) + ((ch - left_chIdx)/dist_ch)*((*(right_ogPtr +n))-(*(left_ogPtr +n)));
				//*(destPtr + n) = (*(left_ogPtr+n)) + ((*(right_ogPtr+n))-(*(left_ogPtr+n)))*pond;

				*(destPtr + n) = (*(left_ogPtr +n))*(right_chIdx - ch)/dist_ch + (*(right_ogPtr+n))*(ch-left_chIdx)/dist_ch;

			}

    	}

    }

}

int ChInterp::leftIndex(int inputChannel[], int currIndex){
	if(currIndex<0){
	    return -1;
	}

	if(inputChannel[currIndex] >-1){
	    return currIndex;
	}

	return leftIndex(inputChannel,currIndex-1);
		    
}

int ChInterp::rightIndex(int inputChannel[], int currIndex){
    if(currIndex==8){
        return -1;
    }

    if(inputChannel[currIndex] >-1){
        return currIndex;
    }

    return rightIndex(inputChannel,currIndex+1);
		    
}

AudioProcessorEditor* ChInterp::createEditor()
{
    editor = new ChInterpEditor (this, true);

    //std::cout << "Creating editor." << std::endl;

    return editor;
}