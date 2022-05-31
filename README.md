# Open Ephys channel interpolation plugin

This repository contains a plugin for the [Open Ephys GUI](https://github.com/open-ephys/plugin-GUI) to interpolate channels.

## Installing the plugin

Download the latest release for your operating system from https://github.com/PridaLab/Ch_interp_OEplugin/releases.

For Linux:
1. Copy the `CNNRippleDetectorOEPlugin.so` file to Open Ephys `plugins` folder.

For Windows:
1. Copy the `CNNRippleDetectorOEPlugin.dll` file to Open Ephys `plugins` folder.

## Plugin configuration
The plugin receives N channels as input (2<=N<=7), and interpolate the missing ones with a weighted linear approximation.

![CNN-ripple](ch-interp-plugin.png)
- **Source Channels:** indicates the channels used as a source (>=1) and the desired interpolated ones (-1). Source channels (>=1) will be indicated in orange, whereas the ones that need to be interpolated must be indicated with a -1 (the box will turn grey). Note that channel numbering starts at 1. 
- **Recipient Channels:** indicates the channels where the source channels will be saved (one to one mapping). 

For instance, in the image provided, the plugin takes channels (1,5,12) and uses them to interpolate the missing 5 channels (2 interpolations between 1&5, 3 interpolations between 5&12). The resulting 8 channels (3 provided, 5 interpolated) are saved in the 1-8 channels. 

Note that channels index refers to the practical order. If a Channel Map plugin is used to rearrange the channels, the new order is passed down to this plugin. That is, if a channel map is used to place channel 18 into the first (1) position, then if we want to access that channel for interpolation, we must refer to it in the source channels with index 1. 

## Compiling the plugin from source

1. Clone this repository inside a folder `OEPlugins` in the same directory where [`plugin-GUI`](https://github.com/open-ephys/plugin-GUI) is located.

e.g.:
```
/code
    /plugin-GUI
    /OEPlugins
        /Ch_interp_OEplugin
            /Source
            /Build
```

3. From inside the `Build` directory (<ch_interp_path>/Build/) execute to create the CMake project:

For Linux:
```
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release  ..
make
make install
```

For Windows:
```
cmake -G "Visual Studio 16 2019" -A x64 ..
```
Open Visual Studio 16 2019 and compile and install the solution (see notes below on how to install Visual Studio).

