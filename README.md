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
3. Go to the `Build` directory (<ch_interp_path>/Build/) and execute to create the CMake project:

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

## How to install Visual Studio 2019 and Open Ephys from source
1. Clone [Open Ephys GUI repository](https://github.com/open-ephys/plugin-GUI).

2. Download and install Visual Studio 2019.

3. Run `Resources/DLLs/FrontPanelUSB-DriverOnly-4.4.0.exe` to install DAQ drivers if needed.

4. Install C++ compiling tools for Visual Studio 2019 and create a new project so everything gets [properly configured](https://stackoverflow.com/questions/31619296/cmake-does-not-find-visual-c-compiler).

5. Download and install CMake. Select "Add CMake to the system PATH".

6. Add the line `add_definitions(-DWIN32)` into line 107 of CMakeLists.txt.

7. Open PowerShell, go to folder plugin-GUI/Build and run CMake. 

```
cmake -G "Visual Studio 16 2019" -A x64 -DCMAKE_CXX_FLAGS="/EHsc /utf-8" ..
```

`-A` indicates the target architecture, which must be specified accordingly.

8. Open `open-ephys-GUI.sln`, which can be found in the `Build` directory, with Visual Studio 2019.

9. Compile the solution.
