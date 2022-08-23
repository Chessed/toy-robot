# Toy Robot Challenge
C++ Technical Challenge
## Table of Contents  
* [Description and requirements](#description)  
* [Constraints](#constraints) 
* [Prerequisite and Instructions](#prerequisite)   
* [Example](#example)  


<a name="description"/>

## Description and Requirements
* The application is a simulation of a toy robot moving on a square table top, of dimensions 5 units x 5 units.
* There are no other obstructions on the table surface.
* The robot is free to roam around the surface of the table, but must be prevented from falling to destruction.
* Any movement that would result in the robot falling from the table must be prevented, however further valid movement commands must still be allowed.

## Commands

### `PLACE X,Y,F`
PLACE will put the toy robot on the table in position X,Y and facing NORTH, SOUTH, EAST or WEST.The origin (0,0)
can be considered to be the SOUTH WEST most corner.
corner. It is required that the first command to the robot is a PLACE
command, after that, any sequence of commands may be issued, in any order, including another PLACE command. The
application should discard all commands in the sequence until a valid PLACE command has been executed.
### `MOVE`
MOVE will move the toy robot one unit forward in the direction it is currently facing.
### `LEFT`
LEFT will rotate the robot 90 degrees to the right without changing the position of the robot.
### `RIGHT`
RIGHT will rotate the robot 90 degrees to the left without changing the position of the robot.
### `REPORT`
REPORT will announce the X,Y and F of the robot. This can be in any form, but standard output is sufficient.


## Constraints
* The toy robot must not fall off the table during movement. This also includes the initial placement of the toy robot.
* Any move that would cause the robot to fall must be ignored.

<a name="prerequisite"/>

## Prerequisite
* Create and test using Visual Studio 2022
* Google Test Adapter (installed via Visual Studio 2022)
[_link on how_](https://docs.microsoft.com/en-us/visualstudio/test/how-to-use-google-test-for-cpp?view=vs-2022) 

## Instructions

### Unit Test
1. Clone this repository.
2. Open `ToyRobot.sln` via Visual Studio _(preferrably Visual Studio 2017 or newer)_
3. Rebuild the solution.
4. Open the "Test Explorer"
5. Press Run button

### Application
1. Follow same steps as _Unit Test_.
2. Run it via "Local Windows Debugger".

<a name="example"/>

## Example Input and Output
### Example #1
Input
<pre>
PLACE 0,0,NORTH 
MOVE 
REPORT 
</pre>
Output
<pre>
Output: 0,1,NORTH 
</pre>
### Example #2
Input
<pre>
PLACE 0,0,NORTH 
LEFT 
REPORT 
</pre>
Output
<pre>
Output: 0,0,WEST 
</pre>
### Example #3
Input
<pre>
PLACE 1,2,EAST 
MOVE 
MOVE 
LEFT 
MOVE 
REPORT 
</pre>
Output 
<pre>
Output: 3,3,NORTH
