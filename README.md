# Arduino-Car-with-Remote-Control
Project details see:
https://www.instructables.com/Arduino-Car-With-L293D-and-Remote-Control/

# Arduino Remote Controlled Car with L293D and IR Receiver

A simple DIY project to build a remote-controlled car using an Arduino, L293D chip, and IR remote control & receiver. The project is built with minimal components and is designed using Tinkercad.

## Supplies

- Arduino four-wheel car chassis
- L293D chip
- IR remote control and receiver
- Two 18650 batteries

## Step 1: Assemble the Car Chassis

Start with soldering the motors and assemble the car chassis as per the instruction manual provided with the chassis kit.

## Step 2: Design the Circuit

- Utilizing the L293D chip, which has two distinct parts that can be controlled, connect the left motors to the left side of the L293D and the right motors to the right side.
  - For forward movement: Both the left and right parts spin.
  - For turns: Only the relevant side spins (either left or right).

- The power source for the Arduino and motors will be the two 18650 batteries.

- The entire circuit design is available on Tinkercad.

For an in-depth understanding of the L293D chip, please visit:
[Control DC Motors with L293D Motor Driver IC & Arduino](https://lastminuteengineers.com/l293d-dc-motor-ar...)

## Step 3: Code

Before you upload the code to the Arduino, ensure you've included the `IRremote.h` library in your Arduino IDE.

The code initializes the L293D chip pins and assigns functions to react to different buttons pressed on the IR remote control. Depending on the button pressed (forward, backward, left, or right), the corresponding motors will be activated.

**Download the code here**: [remote_controlled_car.ino](#)

## Step 4: About the Code

Once you've successfully uploaded the code to the Arduino and have all the components connected:

- Press the **forward button** (denoted by a red circle on the remote) and all four wheels will move the car forward.
- Press the **backward button** (denoted by a blue circle on the remote) and all four wheels will move the car backward.
- Press the **rewind button** (denoted by a yellow circle on the remote) and only the left wheels will spin, moving the car to the right.
- Press the **fast-forward button** (denoted by another red circle on the remote) and only the right wheels will spin, moving the car to the left.

Enjoy your remote-controlled car!

## Note

This project is a great way to learn and experiment with the fundamentals of motor control using Arduino and the L293D chip. Feel free to modify, enhance, and customize it further according to your requirements.
