# Lorenz Attractor

An animated, interactive Lorenz attractor written in C with OpenGL.

This is an experiment I did a while back, figured I would open source it.

![Lorenz](http://i.imgur.com/21kWo.png)

## Building (OSX)

1. Run `make`
2. Run `./lorenz`

The `lorenz` binary has been prebuilt on OSX.

## Using

You can interact with the attractor using the following key bindings:

q: Rotate X axis +
a: Rotate X axis -
w: Rotate Y axis +
s: Rotate Y axis -
e: Rotate Z axis +
d: Rotate Z axis -
r: Restart animation
f: Finish animation
t: Animation speed +
g: Animation speed -
y: Zoom Z axis +
h: Zoom Z axis -
UP: Rotate X axis +
DOWN: Rotate X axis -
LEFT: Rotate Y axis +
RIGHT: Rotate Y axis -

## Background

This program follows a trace of the Lorenz attractor points calculated within the program using the following equations:
- dx/dt = (Prandtl)(y-x)
- dy/dt = x((Rayleigh)-z)-y
- dz/dt = xy - (beta)

By default, the program has the following values:

Prandtl = 10
Rayleigh = 2.6666 or 8/3
beta = 28
