# OrbiterSteamController

## Intro

I love the Steam Controller, however it presents itself to the running process directly as an xinput controller. Unfortunately this means Orbiter can't detect it during launch.

This plugin detects the xinput controller presented by the Steam Controller and maps the analog inputs to the flight control surfaces.

## Install

Unzip the contents into your Orbiter install directory.

## Setup

1. Enable OrbiterSteamController in the Orbiter _Modules_ menu
2. Add Orbiter as a non-Steam game
3. Configure the controller in the Steam Overlay
    * Configure the analog stick as _Joystick Move_ with Output set to _Left Joystick_
    * For the left and right triggers, configure the Trigger Analog Output as _Left Trigger_ and _Right Trigger_ respectively and disable Full Pull and Soft Pull Actions

## Use

The analog stick will now control pitch and roll. The left and right triggers will control yaw.

## Additional Tips

* Outside of the analog functions, you can configure almost everything else directly in the Steam Overlay by mapping keys to the Steam Controller.
* You can configure one of the pads as a mouse with a _Touch Binding_ of "RIGHT MOUSE" - and a click action of the _HOME_ key. This will give you a nice touchpad for changing your view, looking around in the cockpit.
